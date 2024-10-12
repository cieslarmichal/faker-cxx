#include <algorithm>
#include <regex>
#include <string>
#include <vector>

#include "gtest/gtest.h"

#include "common/string_helper.h"
#include "faker-cxx/git.h"
#include "faker-cxx/number.h"
#include "word_data.h"

using namespace ::testing;
using namespace faker;
using namespace git;

class GitTest : public Test
{
public:
    inline static const std::string DATE_REGEX =
        "[0-9]{4}-((0[13578]|1[02])-(0[1-9]|[12][0-9]|3[01])|(0[469]|11)-(0[1-9]|[12][0-9]|30)|(02)-(0[1-9]|[12][0-9]))"
        "T(0[0-9]|1[0-9]|2[0-3]):(0[0-9]|[1-5][0-9]):(0[0-9]|[1-5][0-9])Z";

    inline static const std::string MESSAGE_REGEX =
        R"([a-zA-Z]+(\-[a-zA-Z]+)* ([a-zA-Z\-]+(\-[a-zA-Z]+)*\s)*[a-zA-Z\-]+(\-[a-zA-Z]+)*)";
    inline static const std::string EMAIL_REGEX = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    inline static const std::string NAME_REGEX = "^[A-Z][a-zA-Z]+\\s[A-Z][a-zA-Z]+$";

    static std::string generateShaRegex(unsigned length);
    static std::string generateShaRegex();
};

std::string GitTest::generateShaRegex(unsigned length)
{
    return "[0-9a-fA-F]{" + std::to_string(length) + "}";
}

std::string GitTest::generateShaRegex()
{
    return "[0-9a-fA-F]+";
}

TEST_F(GitTest, shouldGenerateBranch)
{
    const auto generatedBranch = branch();
    const auto branchSplit = common::split(generatedBranch, "-").size();

    ASSERT_TRUE(2 <= branchSplit && branchSplit <= 7);
}

TEST_F(GitTest, branchWithIssueNumTest)
{
    const auto testValue = unsigned(number::integer(2, 100));

    const auto randomBranch = branch(BranchIssueType::WithIssueNumber, testValue);

    const auto branchElements = common::split(randomBranch, "-");

    const auto issueNumber = std::stoi(branchElements[0]);

    ASSERT_TRUE(1 <= issueNumber && issueNumber <= int(testValue));
}

TEST_F(GitTest, branchWithoutIssueNumTest)
{
    const std::integral auto testValue = number::integer(2u, 100u);

    std::vector<std::string> branchElements;

    branchElements = common::split(branch(BranchIssueType::WithoutIssueNumber, testValue), "-");

    const auto& generatedVerb = branchElements[0];
    const auto& generatedNoun = branchElements[1];

    ASSERT_TRUE(std::ranges::any_of(word::verbs,
                                    [generatedVerb](const std::string_view& word) { return word == generatedVerb; }));

    ASSERT_TRUE(std::ranges::any_of(word::nouns,
                                    [generatedNoun](const std::string_view& word) { return word == generatedNoun; }));
}

TEST_F(GitTest, shouldGenerateCommitDate)
{
    const std::regex dateRegex("^" + GitTest::DATE_REGEX + "$");

    ASSERT_TRUE(std::regex_match(commitDate(), dateRegex));
}

TEST_F(GitTest, shouldGenerateCommitEntry)
{
    const std::regex entryRegex("^commit " + GitTest::generateShaRegex() +
                                "\nAuthor: [A-Z][a-zA-Z]+ [A-Z][a-zA-Z]+ .+@[0-9a-zA-Z]+\\.[0-9a-zA-Z]+\nDate: " +
                                GitTest::DATE_REGEX + "\n\n\t" + GitTest::MESSAGE_REGEX + "$");

    ASSERT_TRUE(std::regex_match(commitEntry(), entryRegex));
}

TEST_F(GitTest, shouldGenerateCommitEntryWithGivenArguments)
{
    const unsigned years = 20;

    const unsigned length = 50;

    const std::regex entryRegex("^commit " + GitTest::generateShaRegex(length) +
                                "\nAuthor: [A-Z][a-zA-Z]+ [A-Z][a-zA-Z]+ .+@[0-9a-zA-Z]+\\.[0-9a-zA-Z]+\nDate: " +
                                GitTest::DATE_REGEX + "\n\n\t" + GitTest::MESSAGE_REGEX + "$");

    ASSERT_TRUE(std::regex_match(commitEntry(years, length), entryRegex));
}

TEST_F(GitTest, shouldGenerateCommitMessage)
{
    const std::regex messageRegex("^" + GitTest::MESSAGE_REGEX + "$");

    const auto temp = commitMessage();

    ASSERT_TRUE(std::regex_match(temp, messageRegex));
}

TEST_F(GitTest, shouldGenerateCommitSha)
{
    const unsigned length = 40;

    const std::regex shaRegex("^" + GitTest::generateShaRegex(length) + "$");

    ASSERT_TRUE(std::regex_match(commitSha(length), shaRegex));
}
