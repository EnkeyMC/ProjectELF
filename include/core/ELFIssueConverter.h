//
// Created by MOmac on 29.04.2019.
//

#ifndef PROJECTELF_ELFISSUECONVERTER_H
#define PROJECTELF_ELFISSUECONVERTER_H

#include <QString>
#include <ELFIssue.h>

class ELFIssueConverter {
public:
    static QString toReadable(const elf::ELFIssue &issue);
};


#endif //PROJECTELF_ELFISSUECONVERTER_H
