//
// Created by MOmac on 02.03.2019.
//

#ifndef PROJECTELF_ELFREADER_H
#define PROJECTELF_ELFREADER_H

#include <istream>
#include "ELF.h"
#include "ELFIssue.h"
#include "ELFHeader.h"
#include "ELFSectionHeader.h"


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
    ELFIssuesBySeverity parse_raw(IRawParsable &parsable, ELFIssueSource issueSource);

    ELFHeader* create_header(unsigned char ei_class) const;

    ELFSectionHeader* create_section_header() const;

    std::istream &istream;
    ELF &elf;
};

}  // namespace elf

#endif //PROJECTELF_ELFREADER_H
