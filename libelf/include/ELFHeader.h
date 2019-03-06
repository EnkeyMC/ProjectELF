/*
Copyright (C) 2001-2015 by Serge Lamikhov-Center

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef PROJECTELF_ELFHEADER_H
#define PROJECTELF_ELFHEADER_H

#include <vector>

#include "ELFUtils.h"
#include "ELFIssue.h"
#include "ELFIssuesBySeverity.h"
#include "ELF.h"

using std::vector;

namespace elf {

template< class T > struct ELFHeaderImplTypes;
template<> struct ELFHeaderImplTypes<Elf32_Ehdr> {
    typedef Elf32_Phdr Phdr_type;
    typedef Elf32_Shdr Shdr_type;
    static const unsigned char file_class = ELFCLASS32;
};
template<> struct ELFHeaderImplTypes<Elf64_Ehdr> {
    typedef Elf64_Phdr Phdr_type;
    typedef Elf64_Shdr Shdr_type;
    static const unsigned char file_class = ELFCLASS64;
};

class ELFHeader {
public:
    explicit ELFHeader(const ELF &elf, const endianess_converter &convertor);

    virtual void load_from_stream(std::istream &stream) = 0;

    virtual ELFIssuesBySeverity find_issues() = 0;

    virtual Elf_Half get_e_type() const = 0;
    virtual Elf_Half get_e_machine() const = 0;
    virtual Elf_Word get_e_version() const = 0;
    virtual Elf64_Addr get_e_entry() const = 0;
    virtual Elf64_Off get_e_phoff() const = 0;
    virtual Elf64_Off get_e_shoff() const = 0;
    virtual Elf_Word get_e_flags() const = 0;
    virtual Elf_Half get_e_ehsize() const = 0;
    virtual Elf_Half get_e_phentsize() const = 0;
    virtual Elf_Half get_e_phnum() const = 0;
    virtual Elf_Half get_e_shentsize() const = 0;
    virtual Elf_Half get_e_shnum() const = 0;
    virtual Elf_Half get_e_shstrndx() const = 0;

    virtual void set_e_type(Elf_Half value) = 0;
    virtual void set_e_machine(Elf_Half value) = 0;
    virtual void set_e_version(Elf_Word value) = 0;
    virtual void set_e_entry(Elf64_Addr value) = 0;
    virtual void set_e_phoff(Elf64_Off value) = 0;
    virtual void set_e_shoff(Elf64_Off value) = 0;
    virtual void set_e_flags(Elf_Half value) = 0;
    virtual void set_e_ehsize(Elf_Half value) = 0;
    virtual void set_e_phentsize(Elf_Half value) = 0;
    virtual void set_e_phnum(Elf_Half value) = 0;
    virtual void set_e_shentsize(Elf_Half value) = 0;
    virtual void set_e_shnum(Elf_Half value) = 0;
    virtual void set_e_shstrndx(Elf_Half value) = 0;

protected:
    const endianess_converter &converter;
    const ELF &elf;
};

}


#endif //PROJECTELF_ELFHEADER_H
