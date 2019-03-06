//
// Created by MOmac on 06.03.2019.
//

#ifndef PROJECTELF_ELFHEADERIMPL_H
#define PROJECTELF_ELFHEADERIMPL_H

#include <algorithm>
#include "ELFHeader.h"

namespace elf {

template <typename T>
class ELFHeaderImpl : public ELFHeader {
public:
    explicit ELFHeaderImpl(const ELF &elf, const endianess_converter &converter) : ELFHeader(elf, converter) {
    }

    ELFIO_GET_SET_ACCESS(Elf_Half, e_type, header.e_type);
    ELFIO_GET_SET_ACCESS(Elf_Half, e_machine, header.e_machine);
    ELFIO_GET_SET_ACCESS(Elf_Word, e_version, header.e_version);
    ELFIO_GET_SET_ACCESS(Elf64_Addr, e_entry, header.e_entry);
    ELFIO_GET_SET_ACCESS(Elf64_Off, e_phoff, header.e_phoff);
    ELFIO_GET_SET_ACCESS(Elf64_Off, e_shoff, header.e_shoff);
    ELFIO_GET_SET_ACCESS(Elf_Word, e_flags, header.e_flags);
    ELFIO_GET_SET_ACCESS(Elf_Half, e_ehsize, header.e_ehsize);
    ELFIO_GET_SET_ACCESS(Elf_Half, e_phentsize, header.e_phentsize);
    ELFIO_GET_SET_ACCESS(Elf_Half, e_phnum, header.e_phnum);
    ELFIO_GET_SET_ACCESS(Elf_Half, e_shentsize, header.e_shentsize);
    ELFIO_GET_SET_ACCESS(Elf_Half, e_shnum, header.e_shnum);
    ELFIO_GET_SET_ACCESS(Elf_Half, e_shstrndx, header.e_shstrndx);

    void load_from_stream(std::istream &stream) override {

    }

    ELFIssuesBySeverity find_issues() override {
        return nullptr;
    }

protected:
    T header;
};

}  // namespace elf


#endif //PROJECTELF_ELFHEADERIMPL_H
