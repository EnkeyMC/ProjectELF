//
// Created by MOmac on 07.05.2019.
//

#ifndef PROJECTELF_ELFPARSEEXCEPTION_H
#define PROJECTELF_ELFPARSEEXCEPTION_H

#include <stdexcept>


namespace elf {

class ELFParseException : public std::runtime_error {
public:
    explicit ELFParseException(const char *string) : runtime_error(string) {}
};

}


#endif //PROJECTELF_ELFPARSEEXCEPTION_H
