//
// Created by MOmac on 02.03.2019.
//

#ifndef PROJECTELF_ELFWRITER_H
#define PROJECTELF_ELFWRITER_H

#include "ELF.h"

namespace elf {

class ElfWriter {
public:
    static void save(const ELF &elf, std::ostream &ostream);
};

}

#endif //PROJECTELF_ELFWRITER_H
