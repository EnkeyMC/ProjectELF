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

    static QString severityToReadable(elf::ELFIssueSeverity severity);

    static QString sourceToReadable(elf::ELFIssueSource source, unsigned index = 0);

    static QString typeToReadable(elf::ELFIssueType type);

private:
    static QString tr(const char *s);
};


#endif //PROJECTELF_ELFISSUECONVERTER_H
