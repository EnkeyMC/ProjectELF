#ifndef PROJECTELF_ELF_H
#define PROJECTELF_ELF_H

#include <vector>

#include "ELFIssue.h"
#include "ELFTypes.h"

using std::vector;

namespace elf {

class ELF {
public:

    void clear();

    vector<ELFIssue> set_ei_mag(const char * ei_mag);

protected:

    char e_ident[EI_NIDENT];
};

} // namespace elf


#endif //PROJECTELF_ELF_H
