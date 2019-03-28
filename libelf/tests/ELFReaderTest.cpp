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



TEST(ELFReaderTestNoFixture, parse_header_valid_32bit_msb_from_file) {
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
