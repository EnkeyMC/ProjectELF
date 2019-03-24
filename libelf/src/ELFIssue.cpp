//
// Created by MOmac on 03.03.2019.
//

#include <ELFIssue.h>

#include "ELFIssue.h"

namespace elf {

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

unsigned int ELFIssue::getIndex() const {
    return index;
}

}  // namespace elf