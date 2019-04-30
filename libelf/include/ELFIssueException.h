//
// Created by MOmac on 29.04.2019.
//

#ifndef PROJECTELF_ELFISSUEEXCEPTION_H
#define PROJECTELF_ELFISSUEEXCEPTION_H

#include <exception>

namespace elf {

class ELFIssueException : public std::exception {
public:
    explicit ELFIssueException(const ELFIssue &issue) : issue(issue) {}

    const ELFIssue &getIssue() const {
        return issue;
    }

private:
    ELFIssue issue;
};

}


#endif //PROJECTELF_ELFISSUEEXCEPTION_H
