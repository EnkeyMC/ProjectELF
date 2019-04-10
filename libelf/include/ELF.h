#ifndef PROJECTELF_ELF_H
#define PROJECTELF_ELF_H

#include <vector>

#include "ELFIssue.h"
#include "ELFTypes.h"
#include "ELFUtils.h"
#include "ELFIssuesBySeverity.h"
#include "ELFHeader.h"
#include "ELFSectionHeader.h"
#include "ELFProgramHeader.h"

using std::vector;

namespace elf {

class ELF {
public:
    ELF();

    ~ELF();

    void clear();

    ELFIssuesBySeverity set_e_ident(const unsigned char e_ident[EI_NIDENT]);

    const endianess_converter & get_converter() const;

    size_t get_file_size() const;

    void set_file_size(size_t file_size);

    const unsigned char *get_e_ident() const;
    ELFHeader *get_header();

    void add_section_header(ELFSectionHeader *section_header);
    vector<ELFSectionHeader *> get_section_headers() const;

    void add_program_header(ELFProgramHeader *program_header);
    const vector<ELFProgramHeader *> &get_program_headers() const;

    unsigned char get_ei_mag0() const;
    unsigned char get_ei_mag1() const;
    unsigned char get_ei_mag2() const;
    unsigned char get_ei_mag3() const;
    unsigned char get_ei_class() const;
    unsigned char get_ei_data() const;
    unsigned char get_ei_version() const;
    unsigned char get_ei_osabi() const;
    unsigned char get_ei_abiversion() const;

    void set_ei_mag0(unsigned char value);
    void set_ei_mag1(unsigned char value);
    void set_ei_mag2(unsigned char value);
    void set_ei_mag3(unsigned char value);
    void set_ei_class(unsigned char value);
    void set_ei_data(unsigned char value);
    void set_ei_version(unsigned char value);
    void set_ei_osabi(unsigned char value);
    void set_ei_abiversion(unsigned char value);

    friend class ELFReader;

protected:
    endianess_converter converter;

    size_t file_size;

    unsigned char e_ident[EI_NIDENT]{};
    ELFHeader *header;
    vector<ELFSectionHeader *> section_headers;
    vector<ELFProgramHeader *> program_headers;
};

} // namespace elf


#endif //PROJECTELF_ELF_H
