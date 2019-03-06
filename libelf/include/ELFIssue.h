//
// Created by MOmac on 03.03.2019.
//

#ifndef PROJECTELF_ELFISSUE_H
#define PROJECTELF_ELFISSUE_H

#include <string>

namespace elf {

enum ELFIssueSeverity {
    ISEV_CRITICAL,
    ISEV_ERROR,
    ISEV_WARNING
};

enum ELFIssueSource {
    ISRC_HEADER,
    ISRC_EI_MAGN,
    ISRC_EI_CLASS,
    ISRC_EI_DATA,
    ISRC_E_VERSION,
    ISRC_E_ENTRY,
    ISRC_E_PHOFF,
    ISRC_E_PHENTSIZE,
    ISRC_E_PHNUM,
    ISRC_E_SHOFF,
    ISRC_E_SHENTSIZE,
    ISRC_E_SHNUM,
    ISRC_E_EHSIZE,
    ISRC_E_SHSTRNDX,

    ISRC_SECTIONS_HEADER,
    ISRC_SH_NAME,
    ISRC_SH_OFFSET,
    ISRC_SH_SIZE,
    ISRC_SH_ENTSIZE,

    ISRC_PROGRAM_HEADER,
    ISRC_P_OFFSET,
    ISRC_P_FILESZ
};

enum ELFIssueType {
    ITYPE_UNEXPECTED_EOF
};

class ELFIssue {
public:
    ELFIssue(enum ELFIssueSeverity severity, enum ELFIssueSource source, enum ELFIssueType type);

    ELFIssueSource get_source() const;

    ELFIssueSeverity getSeverity() const;

    ELFIssueType getType() const;

private:
    enum ELFIssueSeverity severity;
    enum ELFIssueSource source;
    enum ELFIssueType type;
};

}  // namespace elf

#endif //PROJECTELF_ELFISSUE_H
