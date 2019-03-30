//
// Created by MOmac on 23.03.2019.
//

#ifndef PROJECTELF_ELFSECTIONHEADERIMPL_H
#define PROJECTELF_ELFSECTIONHEADERIMPL_H

#include "ELFSectionHeader.h"
#include "ELF.h"

namespace elf {

template <typename T>
class ELFSectionHeaderImpl : public ELFSectionHeader {
public:
    explicit ELFSectionHeaderImpl(ELF &elf) : ELFSectionHeader(elf) {}

    size_t get_size() const override {
        return sizeof(header);
    }

    char *get_bytes() override {
        return reinterpret_cast<char *>(&header);
    }

    ELFIssuesBySeverity find_issues() const override {
        return ELFIssuesBySeverity();  // TODO
    }

    ELFIO_GET_SET_ACCESS(Elf_Word, sh_name, header.sh_name);
    ELFIO_GET_SET_ACCESS(Elf_Word, sh_type, header.sh_type);
    ELFIO_GET_SET_ACCESS(Elf_Xword, sh_flags, header.sh_flags);
    ELFIO_GET_SET_ACCESS(Elf64_Addr, sh_addr, header.sh_addr);
    ELFIO_GET_SET_ACCESS(Elf64_Off, sh_offset, header.sh_offset);
    ELFIO_GET_SET_ACCESS(Elf_Xword, sh_size, header.sh_size);
    ELFIO_GET_SET_ACCESS(Elf_Word, sh_link, header.sh_link);
    ELFIO_GET_SET_ACCESS(Elf_Word, sh_info, header.sh_info);
    ELFIO_GET_SET_ACCESS(Elf_Xword, sh_addralign, header.sh_addralign);
    ELFIO_GET_SET_ACCESS(Elf_Xword, sh_entsize, header.sh_entsize);

protected:
    T header;
};

}

#endif //PROJECTELF_ELFSECTIONHEADERIMPL_H
