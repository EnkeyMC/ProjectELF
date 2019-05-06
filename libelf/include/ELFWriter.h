//
// Created by MOmac on 02.03.2019.
//

#ifndef PROJECTELF_ELFWRITER_H
#define PROJECTELF_ELFWRITER_H

#include <ostream>
#include "ELF.h"

namespace elf {

class ELFWriter {
public:
    static bool save(const ELF &elf, std::ostream &ostream);

private:
    static bool save_header(const ELF &elf, std::ostream &ostream);

    static bool save_sections(const ELF &elf, std::ostream &ostream);
    static bool save_section_header(ELFSectionHeader *section_header, std::streampos offset, std::ostream &ostream);
    static bool save_section(ELFSectionHeader *section_header, std::ostream &ostream);

    static bool save_segments(const ELF &elf, std::ostream &ostream);
    static bool save_program_header(ELFProgramHeader *program_header, std::streampos offset, std::ostream &ostream);
    static bool save_segment(ELFProgramHeader *program_header, std::ostream &ostream);
};

}

#endif //PROJECTELF_ELFWRITER_H
