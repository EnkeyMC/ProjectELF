//
// Created by MOmac on 24.03.2019.
//

#include <fstream>

#include "gtest/gtest.h"
#include "ELFReader.h"
#include "Memstream.h"

class ELFReaderTest : public ::testing::Test {
protected:
    void SetUp() override {
        elf = new elf::ELF();
        reader = new elf::ELFReader(istream, *elf);
    }

    void TearDown() override {
        delete reader;
        delete elf;
    }

    void setInput(const char * bytes, size_t len) {
        istream.set_data(bytes, len);
    }

    elf::ELF *elf;
    elf::ELFReader *reader;
    memstream istream;
};

TEST_F(ELFReaderTest, parse_header_valid_32bit_msb) {
    const char input[] = "\x7f\x45LF" // ei_mag
            "\x01" // ei_class
            "\x02" // ei_data
            "\x01" // ei_version
            "\x00" // ei_osabi
            "\x00" // ei_abiversion
            "\0\0\0\0\0\0\0" // padding bytes
            "\x00\x02" // e_type (EXEC)
            "\x00\x07" // e_machine
            "\x00\x00\x00\x01" // e_version
            "\x00\x00\xff\xff" // e_entry
            "\x00\x00\x00\x00" // e_phoff
            "\x00\x00\x00\x00" // e_shoff
            "\x00\x00\x00\x00" // e_flags
            "\x00\x34" // e_ehsize
            "\x00\x00" // e_phentsize
            "\x00\x00" // e_phnum
            "\x00\x00" // e_shentsize
            "\x00\x00" // e_shnum
            "\x00\x00"; // e_shstrndx

    setInput(input, sizeof(input));

    auto issues = reader->parse_header();

    EXPECT_TRUE(issues.empty()) << "Header parsing shouldn't return any issues";

    EXPECT_EQ(elf->get_ei_mag0(), ELFMAG0);
    EXPECT_EQ(elf->get_ei_mag1(), ELFMAG1);
    EXPECT_EQ(elf->get_ei_mag2(), ELFMAG2);
    EXPECT_EQ(elf->get_ei_mag3(), ELFMAG3);
    EXPECT_EQ(elf->get_ei_class(), ELFCLASS32);
    EXPECT_EQ(elf->get_ei_data(), ELFDATA2MSB);

    EXPECT_EQ(elf->get_header().get_e_type(), ET_EXEC);
    EXPECT_EQ(elf->get_header().get_e_machine(), EM_860);
    EXPECT_EQ(elf->get_header().get_e_version(), EV_CURRENT);
    EXPECT_EQ(elf->get_header().get_e_entry(), 0xFFFF);
    EXPECT_EQ(elf->get_header().get_e_phoff(), 0);
    EXPECT_EQ(elf->get_header().get_e_shoff(), 0);
    EXPECT_EQ(elf->get_header().get_e_flags(), 0);
    EXPECT_EQ(elf->get_header().get_e_ehsize(), 0x34);
    EXPECT_EQ(elf->get_header().get_e_phentsize(), 0);
    EXPECT_EQ(elf->get_header().get_e_phnum(), 0);
    EXPECT_EQ(elf->get_header().get_e_shentsize(), 0);
    EXPECT_EQ(elf->get_header().get_e_shnum(), 0);
    EXPECT_EQ(elf->get_header().get_e_shstrndx(), 0);
}

TEST_F(ELFReaderTest, parse_header_valid_64bit_msb) {
    const char input[] = "\x7f\x45LF" // ei_mag
            "\x02" // ei_class
            "\x02" // ei_data
            "\x01" // ei_version
            "\x00" // ei_osabi
            "\x00" // ei_abiversion
            "\0\0\0\0\0\0\0" // padding bytes
            "\x00\x02" // e_type (EXEC)
            "\x00\x07" // e_machine
            "\x00\x00\x00\x01" // e_version
            "\x00\x00\x00\x00\x00\x00\xff\xff" // e_entry
            "\x00\x00\x00\x00\x00\x00\x00\x00" // e_phoff
            "\x00\x00\x00\x00\x00\x00\x00\x00" // e_shoff
            "\x00\x00\x00\x00" // e_flags
            "\x00\x40" // e_ehsize
            "\x00\x00" // e_phentsize
            "\x00\x00" // e_phnum
            "\x00\x00" // e_shentsize
            "\x00\x00" // e_shnum
            "\x00\x00"; // e_shstrndx

    setInput(input, sizeof(input));

    auto issues = reader->parse_header();

    EXPECT_TRUE(issues.empty()) << "Header parsing shouldn't return any issues";

    EXPECT_EQ(elf->get_ei_mag0(), ELFMAG0);
    EXPECT_EQ(elf->get_ei_mag1(), ELFMAG1);
    EXPECT_EQ(elf->get_ei_mag2(), ELFMAG2);
    EXPECT_EQ(elf->get_ei_mag3(), ELFMAG3);
    EXPECT_EQ(elf->get_ei_class(), ELFCLASS64);
    EXPECT_EQ(elf->get_ei_data(), ELFDATA2MSB);

    EXPECT_EQ(elf->get_header().get_e_type(), ET_EXEC);
    EXPECT_EQ(elf->get_header().get_e_machine(), EM_860);
    EXPECT_EQ(elf->get_header().get_e_version(), EV_CURRENT);
    EXPECT_EQ(elf->get_header().get_e_entry(), 0xFFFF);
    EXPECT_EQ(elf->get_header().get_e_phoff(), 0);
    EXPECT_EQ(elf->get_header().get_e_shoff(), 0);
    EXPECT_EQ(elf->get_header().get_e_flags(), 0);
    EXPECT_EQ(elf->get_header().get_e_ehsize(), 0x40);
    EXPECT_EQ(elf->get_header().get_e_phentsize(), 0);
    EXPECT_EQ(elf->get_header().get_e_phnum(), 0);
    EXPECT_EQ(elf->get_header().get_e_shentsize(), 0);
    EXPECT_EQ(elf->get_header().get_e_shnum(), 0);
    EXPECT_EQ(elf->get_header().get_e_shstrndx(), 0);
}

TEST_F(ELFReaderTest, parse_header_valid_64bit_lsb) {
    const char input[] = "\x7f\x45LF" // ei_mag
            "\x02" // ei_class
            "\x01" // ei_data
            "\x01" // ei_version
            "\x00" // ei_osabi
            "\x00" // ei_abiversion
            "\0\0\0\0\0\0\0" // padding bytes
            "\x02\x00" // e_type (EXEC)
            "\x07\x00" // e_machine
            "\x01\x00\x00\x00" // e_version
            "\xff\xff\x00\x00\x00\x00\x00\x00" // e_entry
            "\x00\x00\x00\x00\x00\x00\x00\x00" // e_phoff
            "\x00\x00\x00\x00\x00\x00\x00\x00" // e_shoff
            "\x00\x00\x00\x00" // e_flags
            "\x40\x00" // e_ehsize
            "\x00\x00" // e_phentsize
            "\x00\x00" // e_phnum
            "\x00\x00" // e_shentsize
            "\x00\x00" // e_shnum
            "\x00\x00"; // e_shstrndx

    setInput(input, sizeof(input));

    auto issues = reader->parse_header();

    EXPECT_TRUE(issues.empty()) << "Header parsing shouldn't return any issues";

    EXPECT_EQ(elf->get_ei_mag0(), ELFMAG0);
    EXPECT_EQ(elf->get_ei_mag1(), ELFMAG1);
    EXPECT_EQ(elf->get_ei_mag2(), ELFMAG2);
    EXPECT_EQ(elf->get_ei_mag3(), ELFMAG3);
    EXPECT_EQ(elf->get_ei_class(), ELFCLASS64);
    EXPECT_EQ(elf->get_ei_data(), ELFDATA2LSB);

    EXPECT_EQ(elf->get_header().get_e_type(), ET_EXEC);
    EXPECT_EQ(elf->get_header().get_e_machine(), EM_860);
    EXPECT_EQ(elf->get_header().get_e_version(), EV_CURRENT);
    EXPECT_EQ(elf->get_header().get_e_entry(), 0xFFFF);
    EXPECT_EQ(elf->get_header().get_e_phoff(), 0);
    EXPECT_EQ(elf->get_header().get_e_shoff(), 0);
    EXPECT_EQ(elf->get_header().get_e_flags(), 0);
    EXPECT_EQ(elf->get_header().get_e_ehsize(), 0x40);
    EXPECT_EQ(elf->get_header().get_e_phentsize(), 0);
    EXPECT_EQ(elf->get_header().get_e_phnum(), 0);
    EXPECT_EQ(elf->get_header().get_e_shentsize(), 0);
    EXPECT_EQ(elf->get_header().get_e_shnum(), 0);
    EXPECT_EQ(elf->get_header().get_e_shstrndx(), 0);
}

TEST_F(ELFReaderTest, parse_header_valid_32bit_lsb) {
    const char input[] = "\x7f\x45LF" // ei_mag
            "\x01" // ei_class
            "\x01" // ei_data
            "\x01" // ei_version
            "\x00" // ei_osabi
            "\x00" // ei_abiversion
            "\0\0\0\0\0\0\0" // padding bytes
            "\x02\x00" // e_type (EXEC)
            "\x07\x00" // e_machine
            "\x01\x00\x00\x00" // e_version
            "\xff\xff\x00\x00" // e_entry
            "\x00\x00\x00\x00" // e_phoff
            "\x00\x00\x00\x00" // e_shoff
            "\x00\x00\x00\x00" // e_flags
            "\x34\x00" // e_ehsize
            "\x00\x00" // e_phentsize
            "\x00\x00" // e_phnum
            "\x00\x00" // e_shentsize
            "\x00\x00" // e_shnum
            "\x00\x00"; // e_shstrndx

    setInput(input, sizeof(input));

    auto issues = reader->parse_header();

    EXPECT_TRUE(issues.empty()) << "Header parsing shouldn't return any issues";

    EXPECT_EQ(elf->get_ei_mag0(), ELFMAG0);
    EXPECT_EQ(elf->get_ei_mag1(), ELFMAG1);
    EXPECT_EQ(elf->get_ei_mag2(), ELFMAG2);
    EXPECT_EQ(elf->get_ei_mag3(), ELFMAG3);
    EXPECT_EQ(elf->get_ei_class(), ELFCLASS32);
    EXPECT_EQ(elf->get_ei_data(), ELFDATA2LSB);

    EXPECT_EQ(elf->get_header().get_e_type(), ET_EXEC);
    EXPECT_EQ(elf->get_header().get_e_machine(), EM_860);
    EXPECT_EQ(elf->get_header().get_e_version(), EV_CURRENT);
    EXPECT_EQ(elf->get_header().get_e_entry(), 0xFFFF);
    EXPECT_EQ(elf->get_header().get_e_phoff(), 0);
    EXPECT_EQ(elf->get_header().get_e_shoff(), 0);
    EXPECT_EQ(elf->get_header().get_e_flags(), 0);
    EXPECT_EQ(elf->get_header().get_e_ehsize(), 0x34);
    EXPECT_EQ(elf->get_header().get_e_phentsize(), 0);
    EXPECT_EQ(elf->get_header().get_e_phnum(), 0);
    EXPECT_EQ(elf->get_header().get_e_shentsize(), 0);
    EXPECT_EQ(elf->get_header().get_e_shnum(), 0);
    EXPECT_EQ(elf->get_header().get_e_shstrndx(), 0);
}



TEST(ELFReaderTestFromFile, parse_header_valid_32bit_msb) {
    elf::ELF elf{};
    std::ifstream in("resources/elf_header.bin", std::ios::binary);
    elf::ELFReader reader{in, elf};

    auto issues = reader.parse_header();

    EXPECT_TRUE(issues.empty()) << "Header parsing shouldn't return any issues";

    EXPECT_EQ(elf.get_ei_mag0(), ELFMAG0);
    EXPECT_EQ(elf.get_ei_mag1(), ELFMAG1);
    EXPECT_EQ(elf.get_ei_mag2(), ELFMAG2);
    EXPECT_EQ(elf.get_ei_mag3(), ELFMAG3);
    EXPECT_EQ(elf.get_ei_class(), ELFCLASS32);
    EXPECT_EQ(elf.get_ei_data(), ELFDATA2MSB);

    EXPECT_EQ(elf.get_header().get_e_type(), ET_EXEC);
    EXPECT_EQ(elf.get_header().get_e_machine(), EM_860);
    EXPECT_EQ(elf.get_header().get_e_version(), EV_CURRENT);
    EXPECT_EQ(elf.get_header().get_e_entry(), 0xFFFF);
    EXPECT_EQ(elf.get_header().get_e_phoff(), 0);
    EXPECT_EQ(elf.get_header().get_e_shoff(), 0);
    EXPECT_EQ(elf.get_header().get_e_flags(), 0);
    EXPECT_EQ(elf.get_header().get_e_ehsize(), 0x34);
    EXPECT_EQ(elf.get_header().get_e_phentsize(), 0);
    EXPECT_EQ(elf.get_header().get_e_phnum(), 0);
    EXPECT_EQ(elf.get_header().get_e_shentsize(), 0);
    EXPECT_EQ(elf.get_header().get_e_shnum(), 0);
    EXPECT_EQ(elf.get_header().get_e_shstrndx(), 0);
}

TEST(ELFReaderTestFromFile, parse_helloworld_file) {
    // ARRANGE
    elf::ELF elf{};
    std::ifstream in("resources/helloworld", std::ios::binary);
    elf::ELFReader reader(in, elf);

    // ACT
    auto issues = reader.parse_header();
    issues += reader.parse_section_headers();
    issues += reader.parse_program_headers();
    issues += reader.parse_sections();
    issues += reader.parse_segments();

    // ASSERT
    EXPECT_TRUE(issues.empty());

    EXPECT_EQ(elf.get_ei_mag0(), ELFMAG0);
    EXPECT_EQ(elf.get_ei_mag1(), ELFMAG1);
    EXPECT_EQ(elf.get_ei_mag2(), ELFMAG2);
    EXPECT_EQ(elf.get_ei_mag3(), ELFMAG3);
    EXPECT_EQ(elf.get_ei_class(), ELFCLASS64);
    EXPECT_EQ(elf.get_ei_data(), ELFDATA2LSB);

    EXPECT_EQ(elf.get_header().get_e_type(), ET_EXEC);
    EXPECT_EQ(elf.get_header().get_e_machine(), EM_X86_64);
    EXPECT_EQ(elf.get_header().get_e_version(), EV_CURRENT);
    EXPECT_EQ(elf.get_header().get_e_entry(), 0x400430);
    EXPECT_EQ(elf.get_header().get_e_phoff(), 64);
    EXPECT_EQ(elf.get_header().get_e_shoff(), 6624);
    EXPECT_EQ(elf.get_header().get_e_flags(), 0);
    EXPECT_EQ(elf.get_header().get_e_ehsize(), 64);
    EXPECT_EQ(elf.get_header().get_e_phentsize(), 56);
    EXPECT_EQ(elf.get_header().get_e_phnum(), 9);
    EXPECT_EQ(elf.get_header().get_e_shentsize(), 64);
    EXPECT_EQ(elf.get_header().get_e_shnum(), 31);
    EXPECT_EQ(elf.get_header().get_e_shstrndx(), 28);

    auto sections = elf.get_section_headers();

    ASSERT_EQ(sections.size(), elf.get_header().get_e_shnum());

    EXPECT_EQ(sections[0]->get_sh_name(), 0);
    EXPECT_EQ(sections[0]->get_sh_type(), SHT_NULL);
    EXPECT_EQ(sections[0]->get_sh_addr(), 0);
    EXPECT_EQ(sections[0]->get_sh_offset(), 0);
    EXPECT_EQ(sections[0]->get_sh_size(), 0);
    EXPECT_EQ(sections[0]->get_sh_entsize(), 0);
    EXPECT_EQ(sections[0]->get_sh_flags(), 0);
    EXPECT_EQ(sections[0]->get_sh_link(), 0);
    EXPECT_EQ(sections[0]->get_sh_info(), 0);
    EXPECT_EQ(sections[0]->get_sh_addralign(), 0);

    EXPECT_EQ(sections[1]->get_sh_name(), 0x1B);
    EXPECT_EQ(sections[1]->get_sh_type(), SHT_PROGBITS);
    EXPECT_EQ(sections[1]->get_sh_addr(), 0x400238);
    EXPECT_EQ(sections[1]->get_sh_offset(), 0x238);
    EXPECT_EQ(sections[1]->get_sh_size(), 0x1C);
    EXPECT_EQ(sections[1]->get_sh_entsize(), 0);
    EXPECT_TRUE(sections[1]->get_sh_flags() & SHF_ALLOC);
    EXPECT_EQ(sections[1]->get_sh_link(), 0);
    EXPECT_EQ(sections[1]->get_sh_info(), 0);
    EXPECT_EQ(sections[1]->get_sh_addralign(), 1);

    EXPECT_EQ(sections[2]->get_sh_name(), 0x23);
    EXPECT_EQ(sections[2]->get_sh_type(), SHT_NOTE);
    EXPECT_EQ(sections[2]->get_sh_addr(), 0x400254);
    EXPECT_EQ(sections[2]->get_sh_offset(), 0x254);
    EXPECT_EQ(sections[2]->get_sh_size(), 0x20);
    EXPECT_EQ(sections[2]->get_sh_entsize(), 0);
    EXPECT_TRUE(sections[2]->get_sh_flags() & SHF_ALLOC);
    EXPECT_EQ(sections[2]->get_sh_link(), 0);
    EXPECT_EQ(sections[2]->get_sh_info(), 0);
    EXPECT_EQ(sections[2]->get_sh_addralign(), 4);

    // ... not gonna do all section headers

    ASSERT_LT(elf.get_header().get_e_shstrndx(), sections.size());
    auto string_section = sections[elf.get_header().get_e_shstrndx()];
    const char * section_data = string_section->get_section_data();

    EXPECT_EQ(section_data[0], 0);
    EXPECT_STREQ(section_data + 1, ".symtab");
    EXPECT_STREQ(section_data + 9, ".strtab");
    EXPECT_STREQ(section_data + 0x103, ".comment");

    auto segments = elf.get_program_headers();

    ASSERT_EQ(segments.size(), elf.get_header().get_e_phnum());

    EXPECT_EQ(segments[0]->get_p_type(), PT_PHDR);
    EXPECT_EQ(segments[0]->get_p_offset(), 0x40);
    EXPECT_EQ(segments[0]->get_p_vaddr(), 0x400040);
    EXPECT_EQ(segments[0]->get_p_paddr(), 0x400040);
    EXPECT_EQ(segments[0]->get_p_filesz(), 0x1F8);
    EXPECT_EQ(segments[0]->get_p_memsz(), 0x1F8);
    EXPECT_TRUE(segments[0]->get_p_flags() & (PF_R | PF_X));
    EXPECT_EQ(segments[0]->get_p_align(), 8);

    // test if segment contains the first program header
    const char * segment_data = segments[0]->get_segment_data();
    const char * raw_program_header = segments[0]->get_bytes();

    for (int i = 0; i < segments[0]->get_size(); ++i) {
        EXPECT_EQ(segment_data[i], raw_program_header[i]);
    }
}
