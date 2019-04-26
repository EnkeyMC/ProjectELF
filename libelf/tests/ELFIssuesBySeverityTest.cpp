#include <ELFIssuesBySeverity.h>
#include "gtest/gtest.h"

using namespace elf;

class ELFIssuesBySeverityTest : public ::testing::Test {
protected:
    void SetUp() override {
        issues = new ELFIssuesBySeverity();
    }

    void TearDown() override {
        delete issues;
        issues = nullptr;
    }

    ELFIssuesBySeverity *issues = nullptr;
};

TEST_F(ELFIssuesBySeverityTest, empty) {
    EXPECT_TRUE(issues->empty());
}

TEST_F(ELFIssuesBySeverityTest, add_issue) {
    *issues += ELFIssue(ISEV_CRITICAL, ISRC_E_EHSIZE, ITYPE_INVALID);

    ASSERT_EQ(issues->size(), 1);
    ASSERT_EQ((*issues)[ISEV_CRITICAL].size(), 1);

    auto issue = (*issues)[ISEV_CRITICAL][0];
    ASSERT_EQ(issue.get_severity(), ISEV_CRITICAL);
    ASSERT_EQ(issue.get_type(), ITYPE_INVALID);
    ASSERT_EQ(issue.get_source(), ISRC_E_EHSIZE);
}

TEST_F(ELFIssuesBySeverityTest, add_multiple_issues) {
    auto issue1 = ELFIssue(ISEV_CRITICAL, ISRC_E_EHSIZE, ITYPE_INVALID);
    auto issue2 = ELFIssue(ISEV_CRITICAL, ISRC_SH_SIZE, ITYPE_UNEXPECTED_EOF);
    auto issue3 = ELFIssue(ISEV_CRITICAL, ISRC_HEADER, ITYPE_INVALID);
    *issues += issue1;
    *issues += issue2;
    *issues += issue3;

    ASSERT_EQ(issues->size(), 1);
    ASSERT_EQ(issues->at(ISEV_CRITICAL).size(), 3);

    auto &crit_issues = issues->at(ISEV_CRITICAL);
    ASSERT_NE(std::find(crit_issues.begin(), crit_issues.end(), issue1), crit_issues.end());
    ASSERT_NE(std::find(crit_issues.begin(), crit_issues.end(), issue2), crit_issues.end());
    ASSERT_NE(std::find(crit_issues.begin(), crit_issues.end(), issue3), crit_issues.end());
}

TEST_F(ELFIssuesBySeverityTest, add_multiple_severities) {
    auto issue1 = ELFIssue(ISEV_CRITICAL, ISRC_E_EHSIZE, ITYPE_INVALID);
    auto issue2 = ELFIssue(ISEV_WARNING, ISRC_SH_SIZE, ITYPE_UNEXPECTED_EOF);
    auto issue3 = ELFIssue(ISEV_ERROR, ISRC_HEADER, ITYPE_INVALID);
    *issues += issue1;
    *issues += issue2;
    *issues += issue3;

    ASSERT_EQ(issues->size(), 3);
    ASSERT_EQ(issues->at(ISEV_CRITICAL).size(), 1);
    ASSERT_EQ(issues->at(ISEV_ERROR).size(), 1);
    ASSERT_EQ(issues->at(ISEV_WARNING).size(), 1);

    ASSERT_EQ(issues->at(ISEV_CRITICAL)[0], issue1);
    ASSERT_EQ(issues->at(ISEV_WARNING)[0], issue2);
    ASSERT_EQ(issues->at(ISEV_ERROR)[0], issue3);
}

TEST_F(ELFIssuesBySeverityTest, has_critical_issue_true) {
    *issues += ELFIssue(ISEV_CRITICAL, ISRC_HEADER, ITYPE_INVALID);
    ASSERT_TRUE(issues->has_critical_issue());
}

TEST_F(ELFIssuesBySeverityTest, has_critical_issue_false) {
    *issues += ELFIssue(ISEV_ERROR, ISRC_HEADER, ITYPE_INVALID);
    ASSERT_FALSE(issues->has_critical_issue());
}