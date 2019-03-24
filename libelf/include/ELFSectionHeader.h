//
// Created by MOmac on 23.03.2019.
//

#ifndef PROJECTELF_ELFSECTIONHEADER_H
#define PROJECTELF_ELFSECTIONHEADER_H

#include "ELFUtils.h"
#include "ELFIssuesBySeverity.h"
#include "IRawParsable.h"

namespace elf {

class ELF;

class ELFSectionHeader : public IRawParsable {
public:
    explicit ELFSectionHeader(ELF &elf);

    virtual ~ELFSectionHeader();

    virtual ELFIssuesBySeverity find_issues() const = 0;

    ELFIO_GET_SET_ACCESS_DECL(Elf_Word, sh_name);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Word, sh_type);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Xword, sh_flags);
    ELFIO_GET_SET_ACCESS_DECL(Elf64_Addr, sh_addr);
    ELFIO_GET_SET_ACCESS_DECL(Elf64_Off, sh_offset);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Xword, sh_size);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Word, sh_link);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Word, sh_info);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Xword, sh_addralign);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Xword, sh_entsize);

protected:
    ELF &elf;
};

}

#endif //PROJECTELF_ELFSECTIONHEADER_H
