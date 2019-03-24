#ifndef PROJECTELF_ELF_H
#define PROJECTELF_ELF_H

#include <vector>

#include "ELFIssue.h"
#include "ELFTypes.h"
#include "ELFUtils.h"
#include "ELFIssuesBySeverity.h"
#include "ELFHeader.h"
#include "ELFSectionHeader.h"

using std::vector;

namespace elf {

class ELF {
public:
    ELF();

    ~ELF();

    void clear();

    ELFIssuesBySeverity set_e_ident(const unsigned char e_ident[EI_NIDENT]);

    const endianess_converter & get_converter() const;

    size_t getFile_size() const;

    void set_file_size(size_t file_size);

    const unsigned char *get_e_ident() const;
    ELFHeader& get_header();

    void add_section_header(ELFSectionHeader *section_header);
    vector<ELFSectionHeader *> get_section_headers() const;

    unsigned char get_ei_mag0() const;
    unsigned char get_ei_mag1() const;
    unsigned char get_ei_mag2() const;
    unsigned char get_ei_mag3() const;
    unsigned char get_ei_class() const;
    unsigned char get_ei_data() const;

    friend class ELFReader;

protected:
    endianess_converter converter;

    size_t file_size;

    unsigned char e_ident[EI_NIDENT]{};
    ELFHeader *header;
    vector<ELFSectionHeader *> section_headers;
};

} // namespace elf


#endif //PROJECTELF_ELF_H
