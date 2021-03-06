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

    void load(std::istream &istream);

    void load_structure();

    bool save(std::ostream &ostream);

    const endianess_converter & get_converter() const;

    size_t get_file_size() const;

    ELFIssuesBySeverity find_issues() const;

    const unsigned char *get_e_ident() const;
    ELFHeader *get_header();

    const vector<ELFSectionHeader *> &get_section_headers() const;

    const vector<ELFProgramHeader *> &get_program_headers() const;

    std::string get_name(unsigned index) const;

    unsigned char get_ei_mag0() const;
    unsigned char get_ei_mag1() const;
    unsigned char get_ei_mag2() const;
    unsigned char get_ei_mag3() const;
    unsigned char get_ei_class() const;
    unsigned char get_ei_data() const;
    unsigned char get_ei_version() const;
    unsigned char get_ei_osabi() const;
    unsigned char get_ei_abiversion() const;

    size_t get_sizeof_ei_mag0() const;
    size_t get_sizeof_ei_mag1() const;
    size_t get_sizeof_ei_mag2() const;
    size_t get_sizeof_ei_mag3() const;
    size_t get_sizeof_ei_class() const;
    size_t get_sizeof_ei_data() const;
    size_t get_sizeof_ei_version() const;
    size_t get_sizeof_ei_osabi() const;
    size_t get_sizeof_ei_abiversion() const;

    void set_ei_mag0(unsigned char value);
    void set_ei_mag1(unsigned char value);
    void set_ei_mag2(unsigned char value);
    void set_ei_mag3(unsigned char value);
    void set_ei_class(unsigned char value);
    void set_ei_data(unsigned char value);
    void set_ei_version(unsigned char value);
    void set_ei_osabi(unsigned char value);
    void set_ei_abiversion(unsigned char value);

    static unsigned int MAX_STRUCTURES;

private:
    void read_file_bytes(std::istream &istream);

    void load_identification();

    void clear_structure();

    void clear_data();

    void load_header();

    void load_section_headers();

    void load_program_headers();

    void load_sections();

    void load_segments();

    ELFHeader* create_header(unsigned char ei_class);

    ELFSectionHeader* create_section_header();

    ELFProgramHeader* create_program_header();

    void add_section_header(ELFSectionHeader *section_header);

    void add_program_header(ELFProgramHeader *program_header);

    void set_file_bytes(char *bytes, size_t size);

    void set_e_ident_ptr(char *ptr);

    ELFIssuesBySeverity find_e_ident_issues() const;
    ELFIssuesBySeverity find_overlapping_sections() const;
    ELFIssuesBySeverity find_string_section_issues() const;

    endianess_converter converter;

    size_t file_size;

    char *file_bytes;

    unsigned char *e_ident_ptr;
    ELFHeader *header;
    vector<ELFSectionHeader *> section_headers;
    vector<ELFProgramHeader *> program_headers;
};

} // namespace elf


#endif //PROJECTELF_ELF_H
