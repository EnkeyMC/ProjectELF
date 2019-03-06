#ifndef PROJECTELF_ELF_H
#define PROJECTELF_ELF_H

#include <vector>

#include "ELFIssue.h"
#include "ELFTypes.h"
#include "ELFUtils.h"
#include "ELFIssuesBySeverity.h"
#include "ELFHeader.h"

namespace elf {

class ELF {
public:
    ~ELF();

    void clear();

    ELFIssuesBySeverity set_e_ident(const unsigned char e_ident[EI_NIDENT]);

    endianess_converter get_converter() const;

    const unsigned char *get_e_ident() const;
    ELFHeader& get_header();

    unsigned char get_ei_mag0() const;
    unsigned char get_ei_mag1() const;
    unsigned char get_ei_mag2() const;
    unsigned char get_ei_mag3() const;
    unsigned char get_ei_class() const;
    unsigned char get_ei_data() const;

    friend class ELFReader;

protected:
    endianess_converter converter;

    unsigned char e_ident[EI_NIDENT]{};
    ELFHeader *header{};

};

} // namespace elf


#endif //PROJECTELF_ELF_H
