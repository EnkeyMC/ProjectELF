//
// Created by MOmac on 23.03.2019.
//

#ifndef PROJECTELF_ELFSECTIONHEADER_H
#define PROJECTELF_ELFSECTIONHEADER_H

#include "ELFUtils.h"
#include "ELFIssuesBySeverity.h"
#include "IRawParsable.h"
#include "ELFStructureBase.h"

namespace elf {

class ELF;

class ELFSectionHeader : public IRawParsable, public ELFStructureBase {
public:
    explicit ELFSectionHeader(ELF &elf);

    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Word, sh_name);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Word, sh_type);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Xword, sh_flags);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf64_Addr, sh_addr);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf64_Off, sh_offset);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Xword, sh_size);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Word, sh_link);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Word, sh_info);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Xword, sh_addralign);
    ELFIO_GET_SET_SIZE_ACCESS_DECL(Elf_Xword, sh_entsize);

    char *get_section_data() const;

    void set_copy_of_section_data(const char *raw_data, Elf_Word size);

    unsigned int get_index() const;

    void set_index(unsigned int index);

    bool is_header_valid() const;

    void set_header_valid(bool valid);

    bool is_section_valid() const;

    void set_section_valid(bool valid);

protected:
    char *section_data;

    unsigned index;
    bool header_valid;
    bool section_valid;
};

}

#endif //PROJECTELF_ELFSECTIONHEADER_H
