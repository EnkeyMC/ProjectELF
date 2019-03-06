//
// Created by MOmac on 02.03.2019.
//

#ifndef PROJECTELF_ELFREADER_H
#define PROJECTELF_ELFREADER_H

#include <istream>
#include <vector>
#include "ELF.h"
#include "ELFIssue.h"
#include "ELFHeader.h"

using std::vector;

namespace elf {

class ELFReader {
public:
    explicit ELFReader(std::istream &istream, ELF &output);

    ELFIssuesBySeverity parse_header();

    ELFIssuesBySeverity parse_section_headers();

    ELFIssuesBySeverity parse_program_headers();

    ELFIssuesBySeverity parse_sections();

    ELFIssuesBySeverity parse_segments();

private:
    ELFHeader* create_header(unsigned char ei_class) const;

    std::istream &istream;
    ELF &elf;
};

}  // namespace elf

#endif //PROJECTELF_ELFREADER_H
