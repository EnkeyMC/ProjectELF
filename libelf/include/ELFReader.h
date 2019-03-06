//
// Created by MOmac on 02.03.2019.
//

#ifndef PROJECTELF_ELFREADER_H
#define PROJECTELF_ELFREADER_H

#include <istream>
#include <vector>
#include "ELF.h"
#include "ELFIssue.h"

using std::vector;

namespace elf {

class ELFReader {
public:
    explicit ELFReader(std::istream &istream, ELF &output);

    vector<ELFIssue> parse_header();

    vector<ELFIssue> parse_section_headers();

    vector<ELFIssue> parse_program_headers();

    vector<ELFIssue> parse_sections();

    vector<ELFIssue> parse_segments();

private:
    std::istream &istream;
    ELF &elf;
};

}

#endif //PROJECTELF_ELFREADER_H
