#include <ELF.h>
#include "gtest/gtest.h"

class ELFTest : public ::testing::Test {
protected:
    void SetUp() override {
        elf = new elf::ELF();
    }

    void TearDown() override {
        delete elf;
        elf = nullptr;
    }

    elf::ELF *elf;
};

TEST_F(ELFTest, set_e_ident_no_issues1) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = ELFMAG1;
    e_ident[EI_MAG2] = ELFMAG2;
    e_ident[EI_MAG3] = ELFMAG3;
    e_ident[EI_CLASS] = ELFCLASS32;
    e_ident[EI_DATA] = ELFDATA2MSB;

    auto issues = elf->set_e_ident(e_ident);

    EXPECT_EQ(issues.size(), 0) << "set_e_ident should return no issues";

    auto e_ident_result = elf->get_e_ident();
    for (int i = 0; i < EI_NIDENT; ++i) {
        EXPECT_EQ(e_ident_result[i], e_ident[i]) << "get_e_ident should return same values";
    }

    EXPECT_EQ(elf->get_ei_mag0(), e_ident[EI_MAG0]);
    EXPECT_EQ(elf->get_ei_mag1(), e_ident[EI_MAG1]);
    EXPECT_EQ(elf->get_ei_mag2(), e_ident[EI_MAG2]);
    EXPECT_EQ(elf->get_ei_mag3(), e_ident[EI_MAG3]);
    EXPECT_EQ(elf->get_ei_class(), e_ident[EI_CLASS]);
    EXPECT_EQ(elf->get_ei_data(), e_ident[EI_DATA]);
}

TEST_F(ELFTest, set_e_ident_no_issues2) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = ELFMAG1;
    e_ident[EI_MAG2] = ELFMAG2;
    e_ident[EI_MAG3] = ELFMAG3;
    e_ident[EI_CLASS] = ELFCLASS64;
    e_ident[EI_DATA] = ELFDATA2LSB;

    auto issues = elf->set_e_ident(e_ident);

    EXPECT_EQ(issues.size(), 0) << "set_e_ident should return no issues";

    auto e_ident_result = elf->get_e_ident();
    for (int i = 0; i < EI_NIDENT; ++i) {
        EXPECT_EQ(e_ident_result[i], e_ident[i]) << "get_e_ident should return same values";
    }

    EXPECT_EQ(elf->get_ei_mag0(), e_ident[EI_MAG0]);
    EXPECT_EQ(elf->get_ei_mag1(), e_ident[EI_MAG1]);
    EXPECT_EQ(elf->get_ei_mag2(), e_ident[EI_MAG2]);
    EXPECT_EQ(elf->get_ei_mag3(), e_ident[EI_MAG3]);
    EXPECT_EQ(elf->get_ei_class(), e_ident[EI_CLASS]);
    EXPECT_EQ(elf->get_ei_data(), e_ident[EI_DATA]);
}

TEST_F(ELFTest, set_e_ident_mag0_issue) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = 134;  // the issue
    e_ident[EI_MAG1] = ELFMAG1;
    e_ident[EI_MAG2] = ELFMAG2;
    e_ident[EI_MAG3] = ELFMAG3;
    e_ident[EI_CLASS] = ELFCLASS32;
    e_ident[EI_DATA] = ELFDATA2MSB;

    auto issues = elf->set_e_ident(e_ident).get_issues();

    ASSERT_EQ(issues.size(), 1) << "set_e_ident should return only 1 issue";
    EXPECT_EQ(issues[0].get_severity(), elf::ISEV_CRITICAL) << "issues should be critical";
    EXPECT_EQ(issues[0].get_source(), elf::ISRC_EI_MAGN) << "source of issue should be EI_MAGN";
    EXPECT_EQ(issues[0].get_type(), elf::ITYPE_INVALID) << "type of issue should be invalid";
    EXPECT_EQ(elf->get_ei_mag0(), e_ident[EI_MAG0]) << "get_ei_mag0 should return the wrong value";
}

TEST_F(ELFTest, set_e_ident_mag1_issue) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = 134;  // the issue
    e_ident[EI_MAG2] = ELFMAG2;
    e_ident[EI_MAG3] = ELFMAG3;
    e_ident[EI_CLASS] = ELFCLASS32;
    e_ident[EI_DATA] = ELFDATA2MSB;

    auto issues = elf->set_e_ident(e_ident).get_issues();

    ASSERT_EQ(issues.size(), 1) << "set_e_ident should return only 1 issue";
    EXPECT_EQ(issues[0].get_severity(), elf::ISEV_CRITICAL) << "issues should be critical";
    EXPECT_EQ(issues[0].get_source(), elf::ISRC_EI_MAGN) << "source of issue should be EI_MAGN";
    EXPECT_EQ(issues[0].get_type(), elf::ITYPE_INVALID) << "type of issue should be invalid";
    EXPECT_EQ(elf->get_ei_mag1(), e_ident[EI_MAG1]) << "get_ei_mag1 should return the wrong value";
}

TEST_F(ELFTest, set_e_ident_mag2_issue) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = ELFMAG1;
    e_ident[EI_MAG2] = 134;  // the issue
    e_ident[EI_MAG3] = ELFMAG3;
    e_ident[EI_CLASS] = ELFCLASS32;
    e_ident[EI_DATA] = ELFDATA2MSB;

    auto issues = elf->set_e_ident(e_ident).get_issues();

    ASSERT_EQ(issues.size(), 1) << "set_e_ident should return only 1 issue";
    EXPECT_EQ(issues[0].get_severity(), elf::ISEV_CRITICAL) << "issues should be critical";
    EXPECT_EQ(issues[0].get_source(), elf::ISRC_EI_MAGN) << "source of issue should be EI_MAGN";
    EXPECT_EQ(issues[0].get_type(), elf::ITYPE_INVALID) << "type of issue should be invalid";
    EXPECT_EQ(elf->get_ei_mag2(), e_ident[EI_MAG2]) << "get_ei_mag2 should return the wrong value";
}

TEST_F(ELFTest, set_e_ident_mag3_issue) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = ELFMAG1;
    e_ident[EI_MAG2] = ELFMAG2;
    e_ident[EI_MAG3] = 134;  // the issue
    e_ident[EI_CLASS] = ELFCLASS32;
    e_ident[EI_DATA] = ELFDATA2MSB;

    auto issues = elf->set_e_ident(e_ident).get_issues();

    ASSERT_EQ(issues.size(), 1) << "set_e_ident should return only 1 issue";
    EXPECT_EQ(issues[0].get_severity(), elf::ISEV_CRITICAL) << "issues should be critical";
    EXPECT_EQ(issues[0].get_source(), elf::ISRC_EI_MAGN) << "source of issue should be EI_MAGN";
    EXPECT_EQ(issues[0].get_type(), elf::ITYPE_INVALID) << "type of issue should be invalid";
    EXPECT_EQ(elf->get_ei_mag3(), e_ident[EI_MAG3]) << "get_ei_mag3 should return the wrong value";
}

TEST_F(ELFTest, set_e_ident_class_issue) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = ELFMAG1;
    e_ident[EI_MAG2] = ELFMAG2;
    e_ident[EI_MAG3] = ELFMAG3;
    e_ident[EI_CLASS] = 98;  // the issue
    e_ident[EI_DATA] = ELFDATA2MSB;

    auto issues = elf->set_e_ident(e_ident).get_issues();

    ASSERT_EQ(issues.size(), 1) << "set_e_ident should return only 1 issue";
    EXPECT_EQ(issues[0].get_severity(), elf::ISEV_CRITICAL) << "issues should be critical";
    EXPECT_EQ(issues[0].get_source(), elf::ISRC_EI_CLASS) << "source of issue should be EI_CLASS";
    EXPECT_EQ(issues[0].get_type(), elf::ITYPE_INVALID) << "type of issue should be invalid";
    EXPECT_EQ(elf->get_ei_class(), e_ident[EI_CLASS]) << "get_ei_class should return the wrong value";
}

TEST_F(ELFTest, set_e_ident_data_issue) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = ELFMAG1;
    e_ident[EI_MAG2] = ELFMAG2;
    e_ident[EI_MAG3] = ELFMAG3;
    e_ident[EI_CLASS] = ELFCLASS32;
    e_ident[EI_DATA] = 5; // the issue

    auto issues = elf->set_e_ident(e_ident).get_issues();

    ASSERT_EQ(issues.size(), 1) << "set_e_ident should return only 1 issue";
    EXPECT_EQ(issues[0].get_severity(), elf::ISEV_CRITICAL) << "issues should be critical";
    EXPECT_EQ(issues[0].get_source(), elf::ISRC_EI_DATA) << "source of issue should be EI_DATA";
    EXPECT_EQ(issues[0].get_type(), elf::ITYPE_INVALID) << "type of issue should be invalid";
    EXPECT_EQ(elf->get_ei_data(), e_ident[EI_DATA]) << "get_ei_data should return the wrong value";
}

TEST_F(ELFTest, e_ident_clear) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = ELFMAG1;
    e_ident[EI_MAG2] = ELFMAG2;
    e_ident[EI_MAG3] = ELFMAG3;
    e_ident[EI_CLASS] = ELFCLASS32;
    e_ident[EI_DATA] = ELFDATA2MSB;

    elf->set_e_ident(e_ident);
    elf->clear();

    auto e_ident_result = elf->get_e_ident();
    for (int i = 0; i < EI_NIDENT; ++i) {
        EXPECT_EQ(e_ident_result[i], 0) << "get_e_ident should return zeros";
    }
}