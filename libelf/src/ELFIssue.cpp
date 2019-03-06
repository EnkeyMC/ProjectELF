//
// Created by MOmac on 03.03.2019.
//

#include <ELFIssue.h>

#include "ELFIssue.h"

namespace elf {

ELFIssue::ELFIssue(
        enum ELFIssueSeverity severity,
                enum ELFIssueSource source,
                        enum ELFIssueType type)
                                : severity(severity),
                                source(source),
                                type(type) {

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

}  // namespace elf