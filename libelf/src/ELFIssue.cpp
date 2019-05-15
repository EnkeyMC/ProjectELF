//
// Created by MOmac on 03.03.2019.
//

#include <ELFIssue.h>

#include "ELFIssue.h"

namespace elf {

const ELFIssue ELFIssue::NO_ISSUE = ELFIssue();

ELFIssue::ELFIssue(enum ELFIssueSeverity severity, enum ELFIssueSource source, enum ELFIssueType type, unsigned index)
                                : severity(severity),
                                source(source),
                                type(type),
                                index(index) {

}

ELFIssueSource ELFIssue::get_source() const {
    return source;
}

ELFIssueSeverity ELFIssue::get_severity() const {
    return severity;
}

ELFIssueType ELFIssue::get_type() const {
    return type;
}

bool ELFIssue::operator==(const ELFIssue &rhs) const {
    return severity == rhs.severity && source == rhs.source && type == rhs.type && index == rhs.index;
}

bool ELFIssue::operator!=(const ELFIssue &rhs) const {
    return !(*this == rhs);
}

unsigned int ELFIssue::get_index() const {
    return index;
}

ELFIssue::ELFIssue() : severity(ISEV_NONE), source(ISRC_NONE), type(ITYPE_NONE), index(0) {}

}  // namespace elf