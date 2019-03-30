//
// Created by MOmac on 23.03.2019.
//

#ifndef PROJECTELF_IRAWPARSABLE_H
#define PROJECTELF_IRAWPARSABLE_H

#include <cstddef>

namespace elf {

class IRawParsable {

public:
    virtual size_t get_size() const = 0;

    virtual char * get_bytes() = 0;
};

}


#endif //PROJECTELF_IRAWPARSABLE_H
