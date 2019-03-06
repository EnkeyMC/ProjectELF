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

#include <istream>

#include "ELFUtils.h"
#include "ELFIssue.h"
#include "ELFIssuesBySeverity.h"

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

class ELF;

class ELFHeader {
public:
    explicit ELFHeader(const ELF &elf, const endianess_converter &convertor);

    virtual ELFIssuesBySeverity load_from_stream(std::istream &stream) = 0;

    virtual ELFIssuesBySeverity find_issues() = 0;

    ELFIO_GET_SET_ACCESS_DECL(Elf_Half, e_type);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Half, e_machine);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Word, e_version);
    ELFIO_GET_SET_ACCESS_DECL(Elf64_Addr, e_entry);
    ELFIO_GET_SET_ACCESS_DECL(Elf64_Off, e_phoff);
    ELFIO_GET_SET_ACCESS_DECL(Elf64_Off, e_shoff);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Word, e_flags);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Half, e_ehsize);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Half, e_phentsize);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Half, e_phnum);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Half, e_shentsize);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Half, e_shnum);
    ELFIO_GET_SET_ACCESS_DECL(Elf_Half, e_shstrndx);

protected:
    const endianess_converter &converter;
    const ELF &elf;
};

}


#endif //PROJECTELF_ELFHEADER_H
