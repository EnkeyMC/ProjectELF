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

    void parse();

    void parse_header();

    void parse_section_headers();

    void parse_program_headers();

    void parse_sections();

    void parse_segments();

private:
    ELFIssue parse_raw(IRawParsable &parsable, ELFIssueSource issue_source, unsigned issue_index = 0);

    ELFHeader* create_header(unsigned char ei_class) const;

    ELFSectionHeader* create_section_header() const;

    ELFProgramHeader* create_program_header() const;

    std::istream &istream;
    ELF &elf;
};

}  // namespace elf

#endif //PROJECTELF_ELFREADER_H
