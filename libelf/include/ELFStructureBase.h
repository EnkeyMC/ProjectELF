//
// Created by MOmac on 30.03.2019.
//

#ifndef PROJECTELF_ELFSTRUCTUREBASE_H
#define PROJECTELF_ELFSTRUCTUREBASE_H

#include "ELFUtils.h"
#include "ELFIssuesBySeverity.h"

namespace elf {

class ELF;

class ELFStructureBase {

public:
    explicit ELFStructureBase(ELF &elf);

    virtual ~ELFStructureBase();

    virtual ELFIssuesBySeverity find_issues() const = 0;

    virtual size_t get_size() const = 0;

    virtual char * get_bytes() = 0;

protected:
    ELF &elf;
};

}


#endif //PROJECTELF_ELFSTRUCTUREBASE_H
