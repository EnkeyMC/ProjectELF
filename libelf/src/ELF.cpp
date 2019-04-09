//
// Created by MOmac on 02.03.2019.
//

#include <ELF.h>

#include "ELF.h"

namespace elf {

ELF::ELF() : header(nullptr) {}

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

ELFIssuesBySeverity ELF::set_e_ident(const unsigned char *e_ident) {
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
    } else {
        converter.setup(e_ident[EI_DATA]);
    }

    for (int i = 0; i < sizeof(this->e_ident); ++i) {
        this->e_ident[i] = e_ident[i];
    }

    return issues;
}

const endianess_converter & ELF::get_converter() const {
    return converter;
}

size_t ELF::get_file_size() const {
    return file_size;
}

void ELF::set_file_size(size_t file_size) {
    ELF::file_size = file_size;
}

void ELF::add_section_header(ELFSectionHeader *section_header) {
    section_headers.push_back(section_header);
}

vector<ELFSectionHeader *> ELF::get_section_headers() const {
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

const unsigned char *ELF::get_e_ident() const {
    return e_ident;
}

ELFHeader &ELF::get_header() {
    return *header;
}

const vector<ELFProgramHeader *> &ELF::get_program_headers() const {
    return program_headers;
}

void ELF::add_program_header(ELFProgramHeader *program_header) {
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

}
