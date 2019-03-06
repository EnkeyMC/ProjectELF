//
// Created by MOmac on 06.03.2019.
//

#include "ELFIssuesBySeverity.h"

namespace elf {

ELFIssuesBySeverity &ELFIssuesBySeverity::operator+=(const ELFIssue &rhs) {
    (*this)[rhs.get_severity()].push_back(rhs);
    return *this;
}

ELFIssuesBySeverity &ELFIssuesBySeverity::operator+=(const ELFIssuesBySeverity &rhs) {
    for (auto &severity_issues : rhs) {
        this->at(severity_issues.first).insert(
                this->at(severity_issues.first).end(),
                severity_issues.second.begin(),
                severity_issues.second.end()
        );
    }

    return *this;
}

bool ELFIssuesBySeverity::has_critical_issue() const {
    if (this->count(ISEV_CRITICAL))
        return !this->at(ISEV_CRITICAL).empty();
    return false;
}

std::vector<ELFIssue> ELFIssuesBySeverity::get_issues() const {
    std::vector<ELFIssue> issues;
    for (auto &severity_issues : *this) {
        issues.insert(issues.end(), severity_issues.second.begin(), severity_issues.second.end());
    }

    return issues;
}

}  // namespace elf
