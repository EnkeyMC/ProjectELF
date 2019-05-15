//
// Created by MOmac on 30.03.2019.
//

#ifndef PROJECTELF_ELFPROGRAMHEADER_H
#define PROJECTELF_ELFPROGRAMHEADER_H

#include "ELFUtils.h"
#include "ELFIssuesBySeverity.h"
#include "ELFStructureBase.h"

namespace elf {

class ELF;

class ELFProgramHeader : public ELFStructureBase {
public:
    explicit ELFProgramHeader(ELF &elf);

    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Word, p_type);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Word, p_flags);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf64_Off, p_offset);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf64_Addr, p_vaddr);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf64_Addr, p_paddr);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Xword, p_filesz);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Xword, p_memsz);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Xword, p_align);

    virtual void set_header_ptr(char *ptr) = 0;

    void set_segment_ptr(char *ptr);

    char *get_segment_data() const;

    unsigned int get_index() const;

    void set_index(unsigned int index);

    bool is_header_valid() const;

    bool is_segment_valid() const;

    void set_header_valid(bool valid);

    void set_segment_valid(bool valid);

protected:
    char *segment_data;

    unsigned index;
    bool header_valid;
    bool segment_valid;
};

} // namespace elf


#endif //PROJECTELF_ELFPROGRAMHEADER_H
