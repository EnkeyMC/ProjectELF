#include <ELF.h>
#include <ELFIssueException.h>
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

    elf->set_e_ident(e_ident);

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

    elf->set_e_ident(e_ident);

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

    try {
        elf->set_e_ident(e_ident);
        ASSERT_FALSE(true) << "set_e_ident should throw exception";
    } catch (const elf::ELFIssueException &ex) {
        auto issue = ex.getIssue();
        EXPECT_EQ(issue.get_severity(), elf::ISEV_CRITICAL) << "issues should be critical";
        EXPECT_EQ(issue.get_source(), elf::ISRC_EI_MAGN) << "source of issue should be EI_MAGN";
        EXPECT_EQ(issue.get_type(), elf::ITYPE_INVALID_VALUE) << "type of issue should be invalid";
    }
}

TEST_F(ELFTest, set_e_ident_mag1_issue) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = 134;  // the issue
    e_ident[EI_MAG2] = ELFMAG2;
    e_ident[EI_MAG3] = ELFMAG3;
    e_ident[EI_CLASS] = ELFCLASS32;
    e_ident[EI_DATA] = ELFDATA2MSB;

    try {
        elf->set_e_ident(e_ident);
        ASSERT_FALSE(true) << "set_e_ident should throw exception";
    } catch (const elf::ELFIssueException &ex) {
        auto issue = ex.getIssue();
        EXPECT_EQ(issue.get_severity(), elf::ISEV_CRITICAL) << "issues should be critical";
        EXPECT_EQ(issue.get_source(), elf::ISRC_EI_MAGN) << "source of issue should be EI_MAGN";
        EXPECT_EQ(issue.get_type(), elf::ITYPE_INVALID_VALUE) << "type of issue should be invalid";
    }
}

TEST_F(ELFTest, set_e_ident_mag2_issue) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = ELFMAG1;
    e_ident[EI_MAG2] = 134;  // the issue
    e_ident[EI_MAG3] = ELFMAG3;
    e_ident[EI_CLASS] = ELFCLASS32;
    e_ident[EI_DATA] = ELFDATA2MSB;

    try {
        elf->set_e_ident(e_ident);
        ASSERT_FALSE(true) << "set_e_ident should throw exception";
    } catch (const elf::ELFIssueException &ex) {
        auto issue = ex.getIssue();
        EXPECT_EQ(issue.get_severity(), elf::ISEV_CRITICAL) << "issues should be critical";
        EXPECT_EQ(issue.get_source(), elf::ISRC_EI_MAGN) << "source of issue should be EI_MAGN";
        EXPECT_EQ(issue.get_type(), elf::ITYPE_INVALID_VALUE) << "type of issue should be invalid";
    }
}

TEST_F(ELFTest, set_e_ident_mag3_issue) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = ELFMAG1;
    e_ident[EI_MAG2] = ELFMAG2;
    e_ident[EI_MAG3] = 134;  // the issue
    e_ident[EI_CLASS] = ELFCLASS32;
    e_ident[EI_DATA] = ELFDATA2MSB;

    try {
        elf->set_e_ident(e_ident);
        ASSERT_FALSE(true) << "set_e_ident should throw exception";
    } catch (const elf::ELFIssueException &ex) {
        auto issue = ex.getIssue();
        EXPECT_EQ(issue.get_severity(), elf::ISEV_CRITICAL) << "issues should be critical";
        EXPECT_EQ(issue.get_source(), elf::ISRC_EI_MAGN) << "source of issue should be EI_MAGN";
        EXPECT_EQ(issue.get_type(), elf::ITYPE_INVALID_VALUE) << "type of issue should be invalid";
    }
}

TEST_F(ELFTest, set_e_ident_class_issue) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = ELFMAG1;
    e_ident[EI_MAG2] = ELFMAG2;
    e_ident[EI_MAG3] = ELFMAG3;
    e_ident[EI_CLASS] = 98;  // the issue
    e_ident[EI_DATA] = ELFDATA2MSB;

    try {
        elf->set_e_ident(e_ident);
        ASSERT_FALSE(true) << "set_e_ident should throw exception";
    } catch (const elf::ELFIssueException &ex) {
        auto issue = ex.getIssue();
        EXPECT_EQ(issue.get_severity(), elf::ISEV_CRITICAL) << "issues should be critical";
        EXPECT_EQ(issue.get_source(), elf::ISRC_EI_CLASS) << "source of issue should be EI_CLASS";
        EXPECT_EQ(issue.get_type(), elf::ITYPE_INVALID_VALUE) << "type of issue should be invalid";
    }
}

TEST_F(ELFTest, set_e_ident_data_issue) {
    unsigned char e_ident[EI_NIDENT];
    e_ident[EI_MAG0] = ELFMAG0;
    e_ident[EI_MAG1] = ELFMAG1;
    e_ident[EI_MAG2] = ELFMAG2;
    e_ident[EI_MAG3] = ELFMAG3;
    e_ident[EI_CLASS] = ELFCLASS32;
    e_ident[EI_DATA] = 5; // the issue

    try {
        elf->set_e_ident(e_ident);
        ASSERT_FALSE(true) << "set_e_ident should throw exception";
    } catch (const elf::ELFIssueException &ex) {
        auto issue = ex.getIssue();
        EXPECT_EQ(issue.get_severity(), elf::ISEV_CRITICAL) << "issues should be critical";
        EXPECT_EQ(issue.get_source(), elf::ISRC_EI_DATA) << "source of issue should be EI_DATA";
        EXPECT_EQ(issue.get_type(), elf::ITYPE_INVALID_VALUE) << "type of issue should be invalid";
    }
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