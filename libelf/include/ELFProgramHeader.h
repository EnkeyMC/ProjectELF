//
// Created by MOmac on 30.03.2019.
//

#ifndef PROJECTELF_ELFPROGRAMHEADER_H
#define PROJECTELF_ELFPROGRAMHEADER_H

#include "IRawParsable.h"
#include "ELFUtils.h"
#include "ELFIssuesBySeverity.h"
#include "ELFStructureBase.h"

namespace elf {

class ELF;

class ELFProgramHeader : public IRawParsable, public ELFStructureBase {
public:
    explicit ELFProgramHeader(ELF &elf);

    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Word, p_type);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Word, p_flags);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf64_Off , p_offset);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf64_Addr , p_vaddr);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf64_Addr , p_paddr);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Xword , p_filesz);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Xword , p_memsz);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Xword , p_align);

    char *get_segment_data() const;

    void set_copy_of_segment_data(const char *raw_data, Elf_Word size);

    void set_segment_data(char *raw_data, Elf_Word size);

    unsigned int get_index() const;

    void set_index(unsigned int index);

protected:
    char *segment_data;

    unsigned index;
};

} // namespace elf


#endif //PROJECTELF_ELFPROGRAMHEADER_H
