//
// Created by MOmac on 02.03.2019.
//

#include "ELF.h"

namespace elf {

void ELF::clear() {
    for (unsigned char &field : e_ident) {
        field = 0;
    }
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
        convertor.setup(e_ident[EI_CLASS]);
    }

    for (int i = 0; i < sizeof(this->e_ident); ++i) {
        this->e_ident[i] = e_ident[i];
    }

    return issues;
}

endianess_converter ELF::get_convertor() const {
    return convertor;
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

}
