//
// Created by MOmac on 02.03.2019.
//

#ifndef PROJECTELF_ELFREADER_H
#define PROJECTELF_ELFREADER_H

#include <istream>
#include "ELF.h"

namespace elf {

class ELFReader {
public:
    explicit ELFReader(std::istream &istream, ELF &output);

    void parse_header();

    void parse_section_headers();

    void parse_program_headers();

    void parse_sections();

    void parse_segments();

private:
    std::istream &istream;
    ELF &elf;
};

}

#endif //PROJECTELF_ELFREADER_H
