//
// Created by MOmac on 02.03.2019.
//

#include "ELF.h"
#include "ELFIssueException.h"

#define SIZEOF_EI_FIELD(field) size_t ELF::get_sizeof_##field() const {return sizeof(unsigned char);}

namespace elf {

SIZEOF_EI_FIELD(ei_mag0)
SIZEOF_EI_FIELD(ei_mag1)
SIZEOF_EI_FIELD(ei_mag2)
SIZEOF_EI_FIELD(ei_mag3)
SIZEOF_EI_FIELD(ei_class)
SIZEOF_EI_FIELD(ei_data)
SIZEOF_EI_FIELD(ei_version)
SIZEOF_EI_FIELD(ei_osabi)
SIZEOF_EI_FIELD(ei_abiversion)

ELF::ELF() : file_size(0), header(nullptr) {}

ELF::~ELF() {
    clear();
}

void ELF::clear() {
    for (unsigned char &field : e_ident) {
        field = 0;
    }

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

void ELF::set_e_ident(const unsigned char *e_ident) {
    auto issues = find_e_ident_issues(e_ident);
    if (issues.has_critical_issue())
        throw ELFIssueException(*issues[ISEV_CRITICAL].begin());

    converter.setup(e_ident[EI_DATA]);

    for (unsigned i = 0; i < sizeof(this->e_ident); ++i) {
        this->e_ident[i] = e_ident[i];
    }
}

const endianess_converter & ELF::get_converter() const {
    return converter;
}

size_t ELF::get_file_size() const {
    return file_size;
}

void ELF::set_file_size(size_t file_size) {
    this->file_size = file_size;
}

ELFIssuesBySeverity ELF::find_issues() const
{
    ELFIssuesBySeverity issues;

    issues += find_e_ident_issues(this->e_ident);
    issues += find_overlapping_sections();
    issues += find_string_section_issues();
    issues += header->find_issues();

    for (auto section_header : section_headers)
        issues += section_header->find_issues();

    for (auto program_header : program_headers)
        issues += program_header->find_issues();

    return issues;
}

void ELF::add_section_header(ELFSectionHeader *section_header) {
    section_header->set_index(section_headers.size());
    section_headers.push_back(section_header);
}

const vector<ELFSectionHeader *> &ELF::get_section_headers() const {
    return section_headers;
}

unsigned char ELF::get_ei_mag0() const {
    return e_ident[EI_MAG0];
}

unsigned char ELF::get_ei_mag1() const {
    return e_ident[EI_MAG1];
}

unsigned char ELF::get_ei_mag2() const {
    return e_ident[EI_MAG2];
}

unsigned char ELF::get_ei_mag3() const {
    return e_ident[EI_MAG3];
}

unsigned char ELF::get_ei_class() const {
    return e_ident[EI_CLASS];
}

unsigned char ELF::get_ei_data() const {
    return e_ident[EI_DATA];
}

unsigned char ELF::get_ei_version() const
{
    return e_ident[EI_VERSION];
}

unsigned char ELF::get_ei_osabi() const
{
    return e_ident[EI_OSABI];
}

unsigned char ELF::get_ei_abiversion() const
{
    return e_ident[EI_ABIVERSION];
}

const unsigned char *ELF::get_e_ident() const {
    return e_ident;
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

void ELF::set_ei_mag0(unsigned char value) {
    e_ident[EI_MAG0] = value;
}

void ELF::set_ei_mag1(unsigned char value) {
    e_ident[EI_MAG1] = value;
}

void ELF::set_ei_mag2(unsigned char value) {
    e_ident[EI_MAG2] = value;
}

void ELF::set_ei_mag3(unsigned char value) {
    e_ident[EI_MAG3] = value;
}

void ELF::set_ei_class(unsigned char value) {
    e_ident[EI_CLASS] = value;
}

void ELF::set_ei_data(unsigned char value) {
    e_ident[EI_DATA] = value;
}

void ELF::set_ei_version(unsigned char value)
{
    e_ident[EI_VERSION] = value;
}

void ELF::set_ei_osabi(unsigned char value)
{
    e_ident[EI_OSABI] = value;
}

void ELF::set_ei_abiversion(unsigned char value)
{
    e_ident[EI_ABIVERSION] = value;
}

ELFIssuesBySeverity ELF::find_e_ident_issues(const unsigned char *e_ident)
{
    ELFIssuesBySeverity issues;

    if (e_ident[EI_MAG0] != ELFMAG0
        || e_ident[EI_MAG1] != ELFMAG1
        || e_ident[EI_MAG2] != ELFMAG2
        || e_ident[EI_MAG3] != ELFMAG3) {
        issues += ELFIssue(ISEV_CRITICAL, ISRC_EI_MAGN, ITYPE_INVALID);
    }

    if (e_ident[EI_CLASS] != ELFCLASS32 && e_ident[EI_CLASS] != ELFCLASS64) {
        issues += ELFIssue(ISEV_CRITICAL, ISRC_EI_CLASS, ITYPE_INVALID);
    }

    if (e_ident[EI_DATA] != ELFDATA2LSB && e_ident[EI_DATA] != ELFDATA2MSB) {
        issues += ELFIssue(ISEV_CRITICAL, ISRC_EI_DATA, ITYPE_INVALID);
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
                && shoff > oshoff
                && shoff < oshoff + oshsize
                && shoff + shsize > oshoff
                && shoff + shsize < oshoff + oshsize)
            {
                issues += ELFIssue(ISEV_ERROR, ISRC_SECTION, ITYPE_OVERLAPS_SECTION, section_header->get_index());
            }
        }
    }

    return issues;
}

const char *ELF::get_name(unsigned index) const {
    if (header == nullptr) return nullptr;
    if (header->get_e_shstrndx() >= section_headers.size()) return nullptr;

    auto string_section_header = section_headers[header->get_e_shstrndx()];
    if (index >= string_section_header->get_sh_size()) return nullptr;

    if (string_section_header->get_sh_size() == 0) {
        if (index == 0)
            return "";
        else
            return nullptr;
    }

    return &string_section_header->get_section_data()[index];
}

ELFIssuesBySeverity ELF::find_string_section_issues() const {
    ELFIssuesBySeverity issues;

    if (header == nullptr) return issues;
    if (header->get_e_shstrndx() >= section_headers.size()) return issues;

    auto string_section_header = section_headers[header->get_e_shstrndx()];
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

}
