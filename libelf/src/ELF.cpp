//
// Created by MOmac on 02.03.2019.
//

#include "ELF.h"
#include "ELFIssueException.h"
#include "ELFHeaderImpl.h"
#include "ELFProgramHeaderImpl.h"
#include "ELFSectionHeaderImpl.h"

#define SIZEOF_EI_FIELD(field) size_t ELF::get_sizeof_##field() const {return sizeof(unsigned char);}
#define INVALID_NAME "<<INVALID_NAME>>"

namespace elf {

unsigned int ELF::MAX_STRUCTURES = 100;

SIZEOF_EI_FIELD(ei_mag0)
SIZEOF_EI_FIELD(ei_mag1)
SIZEOF_EI_FIELD(ei_mag2)
SIZEOF_EI_FIELD(ei_mag3)
SIZEOF_EI_FIELD(ei_class)
SIZEOF_EI_FIELD(ei_data)
SIZEOF_EI_FIELD(ei_version)
SIZEOF_EI_FIELD(ei_osabi)
SIZEOF_EI_FIELD(ei_abiversion)

ELF::ELF() : file_bytes(nullptr), file_size(0), header(nullptr), e_ident_ptr(nullptr) {}

ELF::~ELF() {
    clear();
}

void ELF::clear() {
    clear_structure();
    clear_data();
    e_ident_ptr = nullptr;
}

void ELF::load(std::istream &istream) {
    this->clear_data();
    this->read_file_bytes(istream);
    this->load_structure();
}

void ELF::load_structure() {
    this->load_identification();
    this->clear_structure();
    this->load_header();
    this->load_section_headers();
    this->load_program_headers();
    this->load_sections();
    this->load_segments();
}

bool ELF::save(std::ostream &ostream) {
    ostream.seekp(0);
    ostream.write(file_bytes, file_size);
    return ostream.good();
}

const endianess_converter & ELF::get_converter() const {
    return converter;
}

size_t ELF::get_file_size() const {
    return file_size;
}

ELFIssuesBySeverity ELF::find_issues() const
{
    ELFIssuesBySeverity issues;

    issues += find_e_ident_issues();
    issues += find_overlapping_sections();
    issues += find_string_section_issues();
    issues += header->find_issues();

    for (auto section_header : section_headers)
        issues += section_header->find_issues();

    for (auto program_header : program_headers)
        issues += program_header->find_issues();

    if (header->get_e_shnum() > MAX_STRUCTURES)
        issues += ELFIssue(ISEV_ERROR, ISRC_SECTION_HEADERS, ITYPE_TOO_MANY);
    if (header->get_e_phnum() > MAX_STRUCTURES)
        issues += ELFIssue(ISEV_ERROR, ISRC_PROGRAM_HEADERS, ITYPE_TOO_MANY);

    return issues;
}

void ELF::add_section_header(ELFSectionHeader *section_header) {
    section_header->set_index(section_headers.size());
    section_headers.push_back(section_header);
}

const vector<ELFSectionHeader *> &ELF::get_section_headers() const {
    return section_headers;
}

unsigned char ELF::get_ei_mag0() const          {return e_ident_ptr[EI_MAG0];}
unsigned char ELF::get_ei_mag1() const          {return e_ident_ptr[EI_MAG1];}
unsigned char ELF::get_ei_mag2() const          {return e_ident_ptr[EI_MAG2];}
unsigned char ELF::get_ei_mag3() const          {return e_ident_ptr[EI_MAG3];}
unsigned char ELF::get_ei_class() const         {return e_ident_ptr[EI_CLASS];}
unsigned char ELF::get_ei_data() const          {return e_ident_ptr[EI_DATA];}
unsigned char ELF::get_ei_version() const       {return e_ident_ptr[EI_VERSION];}
unsigned char ELF::get_ei_osabi() const         {return e_ident_ptr[EI_OSABI];}
unsigned char ELF::get_ei_abiversion() const    {return e_ident_ptr[EI_ABIVERSION];}

void ELF::set_ei_mag0(unsigned char value)          {e_ident_ptr[EI_MAG0] = value;}
void ELF::set_ei_mag1(unsigned char value)          {e_ident_ptr[EI_MAG1] = value;}
void ELF::set_ei_mag2(unsigned char value)          {e_ident_ptr[EI_MAG2] = value;}
void ELF::set_ei_mag3(unsigned char value)          {e_ident_ptr[EI_MAG3] = value;}
void ELF::set_ei_class(unsigned char value)         {e_ident_ptr[EI_CLASS] = value;}
void ELF::set_ei_data(unsigned char value)          {e_ident_ptr[EI_DATA] = value;}
void ELF::set_ei_version(unsigned char value)       {e_ident_ptr[EI_VERSION] = value;}
void ELF::set_ei_osabi(unsigned char value)         {e_ident_ptr[EI_OSABI] = value;}
void ELF::set_ei_abiversion(unsigned char value)    {e_ident_ptr[EI_ABIVERSION] = value;}

const unsigned char *ELF::get_e_ident() const {
    return e_ident_ptr;
}

ELFHeader *ELF::get_header() {
    return header;
}

const vector<ELFProgramHeader *> &ELF::get_program_headers() const {
    return program_headers;
}

void ELF::add_program_header(ELFProgramHeader *program_header) {
    program_header->set_index(program_headers.size());
    this->program_headers.push_back(program_header);
}

ELFIssuesBySeverity ELF::find_e_ident_issues() const
{
    ELFIssuesBySeverity issues;

    if (e_ident_ptr[EI_MAG0] != ELFMAG0
        || e_ident_ptr[EI_MAG1] != ELFMAG1
        || e_ident_ptr[EI_MAG2] != ELFMAG2
        || e_ident_ptr[EI_MAG3] != ELFMAG3) {
        issues += ELFIssue(ISEV_ERROR, ISRC_EI_MAGN, ITYPE_INVALID_VALUE);
    }

    if (e_ident_ptr[EI_CLASS] != ELFCLASS32 && e_ident_ptr[EI_CLASS] != ELFCLASS64) {
        issues += ELFIssue(ISEV_CRITICAL, ISRC_EI_CLASS, ITYPE_INVALID_VALUE);
    }

    if (e_ident_ptr[EI_DATA] != ELFDATA2LSB && e_ident_ptr[EI_DATA] != ELFDATA2MSB) {
        issues += ELFIssue(ISEV_CRITICAL, ISRC_EI_DATA, ITYPE_INVALID_VALUE);
    }

    if (e_ident_ptr[EI_VERSION] == EV_NONE) {
        issues += ELFIssue(ISEV_WARNING, ISRC_EI_VERSION, ITYPE_INVALID_VALUE);
    }

    return issues;
}

ELFIssuesBySeverity ELF::find_overlapping_sections() const {
    ELFIssuesBySeverity issues;

    for (auto section_header : section_headers) {
        for (auto other_section_header : section_headers) {
            auto shoff = section_header->get_sh_offset();
            auto oshoff = other_section_header->get_sh_offset();
            auto shsize = section_header->get_sh_size();
            auto oshsize = other_section_header->get_sh_size();

            if (section_header->get_sh_type() != SHT_NOBITS
                && other_section_header->get_sh_type() != SHT_NOBITS
                && section_header->get_sh_size() > 0
                && other_section_header->get_sh_size() > 0
                && (
                        (shoff > oshoff && shoff < oshoff + oshsize)
                        || (shoff + shsize > oshoff && shoff + shsize < oshoff + oshsize)
                        || (oshoff > shoff && oshoff < shoff + shsize)
                        || (oshoff + oshsize > shoff && oshoff + oshsize < shoff + shsize)
                   )
                )
            {
                issues += ELFIssue(ISEV_ERROR, ISRC_SECTION, ITYPE_OVERLAPS_SECTION, section_header->get_index());
            }
        }
    }

    return issues;
}

std::string ELF::get_name(unsigned index) const {
    if (header == nullptr) return INVALID_NAME;
    if (header->get_e_shstrndx() >= section_headers.size()) return INVALID_NAME;

    auto string_section_header = section_headers[header->get_e_shstrndx()];
    if (!string_section_header->is_section_valid()) return INVALID_NAME;
    if (index >= string_section_header->get_sh_size()) return INVALID_NAME;

    if (string_section_header->get_sh_size() == 0) {
        if (index == 0)
            return "";
        else
            return INVALID_NAME;
    }

    const char *buffer = &string_section_header->get_section_data()[index];
    const char *string_end = std::find(buffer, buffer + string_section_header->get_sh_size() - index, 0);
    return std::string(buffer, string_end);
}

ELFIssuesBySeverity ELF::find_string_section_issues() const {
    ELFIssuesBySeverity issues;

    if (header == nullptr) return issues;
    if (header->get_e_shstrndx() == SHN_UNDEF) return issues;
    if (header->get_e_shstrndx() >= section_headers.size()) return issues;

    auto string_section_header = section_headers[header->get_e_shstrndx()];
    if (!string_section_header->is_section_valid()) {
        issues += ELFIssue(ISEV_ERROR, ISRC_STRING_SECTION, ITYPE_IS_INVALID);
        return issues;
    }

    auto size = string_section_header->get_sh_size();
    auto data = string_section_header->get_section_data();

    if (size > 0) {
        if (data[0] != '\0')
            issues += ELFIssue(ISEV_WARNING, ISRC_STRING_SECTION, ITYPE_SHOULD_START_WITH_ZERO, header->get_e_shstrndx());
        if (data[size - 1] != '\0')
            issues += ELFIssue(ISEV_ERROR, ISRC_STRING_SECTION, ITYPE_HAS_TO_END_WITH_ZERO, header->get_e_shstrndx());
    }

    return issues;
}

void ELF::set_file_bytes(char *bytes, size_t size) {
    this->file_bytes = bytes;
    this->file_size = size;
}

void ELF::set_e_ident_ptr(char *ptr) {
    this->e_ident_ptr = reinterpret_cast<unsigned char *>(ptr);
    auto issues = find_e_ident_issues();
    if (issues.has_critical_issue())
        throw ELFIssueException(*issues[ISEV_CRITICAL].begin());

    converter.setup(e_ident_ptr[EI_DATA]);
}

void ELF::read_file_bytes(std::istream &istream) {
    istream.seekg(0, std::istream::end);
    auto size = istream.tellg();
    istream.seekg(0);

    char *bytes = new char[size];
    istream.read(bytes, size);
    this->set_file_bytes(bytes, size);
}

void ELF::load_identification()
{
    if (this->file_size < EI_NIDENT)
        throw ELFIssueException(ELFIssue(ISEV_CRITICAL, ISRC_HEADER, ITYPE_UNEXPECTED_EOF));

    this->set_e_ident_ptr(this->file_bytes);
}

void ELF::clear_structure() {
    delete header;
    header = nullptr;

    for (auto pheader : program_headers) {
        delete pheader;
    }

    program_headers.clear();

    for (auto sheader : section_headers) {
        delete sheader;
    }

    section_headers.clear();
}

void ELF::clear_data()
{
    delete[] file_bytes;
    file_bytes = nullptr;
    file_size = 0;
}

void ELF::load_header() {
    this->header = create_header(this->get_ei_class());

    if (this->header->get_size() + EI_NIDENT > this->file_size)
        throw ELFIssueException(ELFIssue(ISEV_CRITICAL, ISRC_HEADER, ITYPE_UNEXPECTED_EOF));

    this->header->set_header_ptr(this->file_bytes + EI_NIDENT);
    this->header->set_header_valid(true);
}

void ELF::load_section_headers() {

    Elf64_Off shoff = this->header->get_e_shoff();
    Elf_Half shentsize = this->header->get_e_shentsize();
    Elf_Half shnum = this->header->get_e_shnum();
    ELFSectionHeader *section_header;

    for (unsigned int i = 0; i < shnum && i < MAX_STRUCTURES; ++i) {
        section_header = create_section_header();
        if (shoff + shentsize*i + shentsize <= this->file_size) {
            section_header->set_header_valid(true);
            section_header->set_header_ptr(this->file_bytes + shoff + shentsize*i);
        }

        this->add_section_header(section_header);
    }
}

void ELF::load_program_headers() {

    Elf64_Off phoff = this->header->get_e_phoff();
    Elf_Half phentsize = this->header->get_e_phentsize();
    Elf_Half phnum = this->header->get_e_phnum();
    ELFProgramHeader *program_header;

    for (unsigned int i = 0; i < phnum && i < MAX_STRUCTURES; ++i) {
        program_header = create_program_header();
        if (phoff + phentsize*i + phentsize <= this->file_size) {
            program_header->set_header_valid(true);
            program_header->set_header_ptr(this->file_bytes + phoff + phentsize*i);
        }

        this->add_program_header(program_header);
    }
}

void ELF::load_sections() {

    for (auto section_header : this->section_headers) {
        if (section_header->is_header_valid()
            && section_header->get_sh_offset() + section_header->get_sh_size() <= this->file_size)
        {
            section_header->set_section_valid(true);
            section_header->set_section_ptr(this->file_bytes + section_header->get_sh_offset());
        }
    }
}

void ELF::load_segments() {

    for (auto program_header : this->program_headers) {
        if (program_header->is_header_valid()
            && program_header->get_p_offset() + program_header->get_p_filesz() <= this->file_size)
        {
            program_header->set_segment_valid(true);
            program_header->set_segment_ptr(this->file_bytes + program_header->get_p_offset());
        }
    }
}

ELFHeader* ELF::create_header(unsigned char ei_class) {
    if (ei_class == ELFCLASS32)
        return new ELFHeaderImpl<Elf32_Ehdr>(*this);
    else
        return new ELFHeaderImpl<Elf64_Ehdr>(*this);
}

ELFSectionHeader* ELF::create_section_header() {
    if (this->get_ei_class() == ELFCLASS32)
        return new ELFSectionHeaderImpl<Elf32_Shdr>(*this);
    else
        return new ELFSectionHeaderImpl<Elf64_Shdr>(*this);
}

ELFProgramHeader* ELF::create_program_header() {
    if (this->get_ei_class() == ELFCLASS32)
        return new ELFProgramHeaderImpl<Elf32_Phdr>(*this);
    else
        return new ELFProgramHeaderImpl<Elf64_Phdr>(*this);
}

}
