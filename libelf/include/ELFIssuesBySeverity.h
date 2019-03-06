//
// Created by MOmac on 06.03.2019.
//

#ifndef PROJECTELF_ELFISSUESBYSEVERITY_H
#define PROJECTELF_ELFISSUESBYSEVERITY_H

#include <map>
#include <vector>

#include "ELFIssue.h"

namespace elf {

class ELFIssuesBySeverity : public std::map<enum ELFIssueSeverity,std::vector<ELFIssue>> {
public:
    ELFIssuesBySeverity& operator+=(const ELFIssue &rhs);
    ELFIssuesBySeverity& operator+=(const ELFIssuesBySeverity &rhs);

    bool has_critical_issue() const;

    std::vector<ELFIssue> get_issues() const;
};

}  // namespace elf


#endif //PROJECTELF_ELFISSUESBYSEVERITY_H
