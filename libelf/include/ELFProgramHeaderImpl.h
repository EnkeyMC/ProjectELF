//
// Created by MOmac on 30.03.2019.
//

#ifndef PROJECTELF_ELFPROGRAMHEADERIMPL_H
#define PROJECTELF_ELFPROGRAMHEADERIMPL_H

#include "ELFProgramHeader.h"
#include "ELF.h"
#include "ELFStructureBase.h"

namespace elf {

template <typename T>
class ELFProgramHeaderImpl : public ELFProgramHeader {
public:
    explicit ELFProgramHeaderImpl(ELF &elf) : ELFProgramHeader(elf) {}

    ELFIssuesBySeverity find_issues() const override {
        ELFIssuesBySeverity issues{};

        if (get_p_offset() + get_p_filesz() > elf.get_file_size())
            issues += ELFIssue(ISEV_ERROR, ISRC_SEGMENT, ITYPE_OUT_OF_BOUNDS, get_index());

        return issues;
    }

    size_t get_size() const override {
        return sizeof(header);
    }

    char *get_bytes() override {
        return reinterpret_cast<char *>(&header);
    }

    ELFIO_GET_SET_SIZE_ACCESS(Elf_Word, p_type, header.p_type);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Word, p_flags, header.p_flags);
    ELFIO_GET_SET_SIZE_ACCESS(Elf64_Off , p_offset, header.p_offset);
    ELFIO_GET_SET_SIZE_ACCESS(Elf64_Addr , p_vaddr, header.p_vaddr);
    ELFIO_GET_SET_SIZE_ACCESS(Elf64_Addr , p_paddr, header.p_paddr);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Xword , p_filesz, header.p_filesz);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Xword , p_memsz, header.p_memsz);
    ELFIO_GET_SET_SIZE_ACCESS(Elf_Xword , p_align, header.p_align);

protected:
    T header;
};

}

#endif //PROJECTELF_ELFPROGRAMHEADERIMPL_H
