//
// Created by MOmac on 30.03.2019.
//

#ifndef PROJECTELF_ELFPROGRAMHEADER_H
#define PROJECTELF_ELFPROGRAMHEADER_H

#include "IRawParsable.h"
#include "ELFUtils.h"
#include "ELFIssuesBySeverity.h"

namespace elf {

class ELF;

class ELFProgramHeader : public IRawParsable {
public:
    explicit ELFProgramHeader(ELF &elf);

    virtual ~ELFProgramHeader();

    virtual ELFIssuesBySeverity find_issues() const = 0;

    ELFIO_GET_SET_ACCESS_DECL(Elf_Word, p_type);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Word, p_flags);
    ELFIO_GET_SET_ACCESS_DECL(Elf64_Off , p_offset);
    ELFIO_GET_SET_ACCESS_DECL(Elf64_Addr , p_vaddr);
    ELFIO_GET_SET_ACCESS_DECL(Elf64_Addr , p_paddr);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Xword , p_filesz);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Xword , p_memsz);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Xword , p_align);
protected:
    ELF &elf;
};

} // namespace elf


#endif //PROJECTELF_ELFPROGRAMHEADER_H
