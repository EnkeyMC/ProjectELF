#ifndef PROJECTELF_ELFHEADER_H
#define PROJECTELF_ELFHEADER_H

#include <istream>

#include "ELFUtils.h"
#include "ELFIssue.h"
#include "ELFIssuesBySeverity.h"
#include "ELFStructureBase.h"

namespace elf {

class ELF;

class ELFHeader : public ELFStructureBase {
public:
    explicit ELFHeader(ELF &elf);

    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Half, e_type);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Half, e_machine);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Word, e_version);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf64_Addr, e_entry);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf64_Off, e_phoff);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf64_Off, e_shoff);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Word, e_flags);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Half, e_ehsize);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Half, e_phentsize);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Half, e_phnum);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Half, e_shentsize);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Half, e_shnum);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Half, e_shstrndx);

    virtual void set_header_ptr(char *ptr) = 0;

    bool is_header_valid() const;

    void set_header_valid(bool valid);

protected:
    bool header_valid;
};

}


#endif //PROJECTELF_ELFHEADER_H
