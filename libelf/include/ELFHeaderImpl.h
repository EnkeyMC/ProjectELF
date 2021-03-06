//
// Created by MOmac on 06.03.2019.
//

#ifndef PROJECTELF_ELFHEADERIMPL_H
#define PROJECTELF_ELFHEADERIMPL_H

#include <algorithm>
#include <istream>

#include "ELFHeader.h"
#include "ELF.h"

namespace elf {

template <typename T>
class ELFHeaderImpl : public ELFHeader {
public:
    explicit ELFHeaderImpl(ELF &elf) : ELFHeader(elf) {
    }

    ELFIO_GET_SET_SIZE_ACCESS(Elf_Half, e_type, header->e_type);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Half, e_machine, header->e_machine);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Word, e_version, header->e_version);
    ELFIO_GET_SET_SIZE_ACCESS(Elf64_Addr, e_entry, header->e_entry);
    ELFIO_GET_SET_SIZE_ACCESS(Elf64_Off, e_phoff, header->e_phoff);
    ELFIO_GET_SET_SIZE_ACCESS(Elf64_Off, e_shoff, header->e_shoff);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Word, e_flags, header->e_flags);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Half, e_ehsize, header->e_ehsize);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Half, e_phentsize, header->e_phentsize);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Half, e_phnum, header->e_phnum);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Half, e_shentsize, header->e_shentsize);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Half, e_shnum, header->e_shnum);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Half, e_shstrndx, header->e_shstrndx);

    size_t get_size() const override {
        return sizeof(T);
    }

    char *get_bytes() override {
        return reinterpret_cast<char *>(header);
    }

    void set_header_ptr(char *ptr) override {
        this->header = reinterpret_cast<T*>(ptr);
    }

    ELFIssuesBySeverity find_issues() const override {
        ELFIssuesBySeverity issues;

        if (get_e_version() == 0)
            issues += ELFIssue(ISEV_WARNING, ISRC_E_VERSION, ITYPE_INVALID_VALUE);
        if (get_e_ehsize() != get_size() + EI_NIDENT)
            issues += ELFIssue(ISEV_WARNING, ISRC_E_EHSIZE, ITYPE_INVALID_VALUE);
        if (get_e_shnum() > 0) {
            if (get_e_shoff() + get_e_shentsize() * get_e_shnum() > elf.get_file_size())
                issues += ELFIssue(ISEV_ERROR, ISRC_SECTION_HEADERS, ITYPE_OUT_OF_BOUNDS);
            if (get_e_shoff() < get_size() + EI_NIDENT)
                issues += ELFIssue(ISEV_ERROR, ISRC_SECTION_HEADERS, ITYPE_OVERLAPS_HEADER);
            if (get_e_shstrndx() != SHN_UNDEF && get_e_shstrndx() >= get_e_shnum())
                issues += ELFIssue(ISEV_ERROR, ISRC_E_SHSTRNDX, ITYPE_INDEX_OUT_OF_BOUNDS);
        }

        if (get_e_phnum() > 0) {
            if (get_e_phoff() + get_e_phentsize() * get_e_phnum() > elf.get_file_size())
                issues += ELFIssue(ISEV_ERROR, ISRC_PROGRAM_HEADERS, ITYPE_OUT_OF_BOUNDS);
            if (get_e_phoff() < get_size() + EI_NIDENT)
                issues += ELFIssue(ISEV_ERROR, ISRC_PROGRAM_HEADERS, ITYPE_OVERLAPS_HEADER);
        }

        return issues;
    }

protected:
    T *header;
};

}  // namespace elf


#endif //PROJECTELF_ELFHEADERIMPL_H
