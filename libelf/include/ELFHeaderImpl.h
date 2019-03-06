//
// Created by MOmac on 06.03.2019.
//

#ifndef PROJECTELF_ELFHEADERIMPL_H
#define PROJECTELF_ELFHEADERIMPL_H

#include <algorithm>
#include "ELFHeader.h"

namespace elf {

template <typename T>
class ELFHeaderImpl : public ELFHeader {
public:
    explicit ELFHeaderImpl(const ELF &elf, const endianess_converter &converter) : ELFHeader(elf, converter) {
    }

    Elf_Half get_e_type() const override {
        return converter(header.e_type);
    }

    Elf_Half get_e_machine() const override {
        return converter(header.e_machine);
    }

    Elf_Word get_e_version() const override {
        return converter(header.e_version);
    }

    Elf64_Addr get_e_entry() const override {
        return converter(header.e_phoff);
    }

    Elf64_Off get_e_phoff() const override {
        return converter(header.e_phoff);
    }

    Elf64_Off get_e_shoff() const override {
        return converter(header.e_shoff);
    }

    Elf_Word get_e_flags() const override {
        return converter(header.e_flags);
    }

    Elf_Half get_e_ehsize() const override {
        return converter(header.e_ehsize);
    }

    Elf_Half get_e_phentsize() const override {
        return converter(header.e_phentsize);
    }

    Elf_Half get_e_phnum() const override {
        return converter(header.e_phnum);
    }

    Elf_Half get_e_shentsize() const override {
        return converter(header.e_shentsize);
    }

    Elf_Half get_e_shnum() const override {
        return converter(header.e_shnum);
    }

    Elf_Half get_e_shstrndx() const override {
        return converter(header.e_shstrndx);
    }

    void set_e_type(Elf_Half value) override {
        header.e_type = value;
        header.e_type = converter(header.e_type);
    }

    void set_e_machine(Elf_Half value) override {
        header.e_machine = value;
        header.e_machine = converter(header.e_machine);
    }

    void set_e_version(Elf_Word value) override {
        header.e_version = value;
        header.e_version = converter(header.e_version);
    }

    void set_e_entry(Elf64_Addr value) override {
        header.e_entry = value;
        header.e_entry = converter(header.e_entry);
    }

    void set_e_phoff(Elf64_Off value) override {
        header.e_phoff = value;
        header.e_entry = converter(header.e_phoff);
    }

    void set_e_shoff(Elf64_Off value) override;
    void set_e_flags(Elf_Half value) override;
    void set_e_ehsize(Elf_Half value) override;
    void set_e_phentsize(Elf_Half value) override;
    void set_e_phnum(Elf_Half value) override;
    void set_e_shentsize(Elf_Half value) override;
    void set_e_shnum(Elf_Half value) override;
    void set_e_shstrndx(Elf_Half value) override;

protected:
    T header;
};

}  // namespace elf


#endif //PROJECTELF_ELFHEADERIMPL_H
