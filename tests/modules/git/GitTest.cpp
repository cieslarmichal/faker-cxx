#include "faker-cxx/Git.h"

#include <regex>
#include <string>
#include <vector>

#include "gtest/gtest.h"

#include "common/StringHelper.h"
#include "faker-cxx/Number.h"

using namespace ::testing;
using namespace faker;

class GitTest : public Test
{
public:
    inline static const std::string DATE_REGEX =
        "[A-Z][a-z]{2} [A-Z][a-z]{2,3} (([0-2][0-9])|(3[0-1])) (([0-1][0-9])|(2[0-4])):[0-5][0-9]:[0-5][0-9] "
        "[1-2][0-9]{3} (-|\\+)((0[0-9])|(1[0-2]))00";
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
    const auto branch = Git::branch();
    const auto branchSplit = faker::StringHelper::split(branch, "-").size();

    ASSERT_TRUE(2 <= branchSplit && branchSplit <= 7);
}

TEST_F(GitTest, branchIssueNumTest)
{
    auto testValue = unsigned(faker::Number::integer(2, 100));

    std::vector<std::string> branch = faker::StringHelper::split(Git::branch(testValue), "-");

    bool numberAtFront = false;

    int number;

    while (!numberAtFront)
    {
        branch = faker::StringHelper::split(Git::branch(testValue), "-");
        try
        {
            number = std::stoi(branch[0]);
            numberAtFront = true;
        }
        catch (...)
        {
            continue;
        }
    }

    ASSERT_TRUE(1 <= number && number <= int(testValue));
}

TEST_F(GitTest, shouldGenerateCommitDate)
{
    const std::regex dateRegex("^" + GitTest::DATE_REGEX + "$");

    ASSERT_TRUE(std::regex_match(Git::commitDate(), dateRegex));
}

TEST_F(GitTest, shouldGenerateCommitEntry)
{
    const std::regex entryRegex("^commit " + GitTest::generateShaRegex() +
                                "\nAuthor: [A-Z][a-zA-Z]+ [A-Z][a-zA-Z]+ .+@[0-9a-zA-Z]+\\.[0-9a-zA-Z]+\nDate: " +
                                GitTest::DATE_REGEX + "\n\n\t" + GitTest::MESSAGE_REGEX + "$");

    ASSERT_TRUE(std::regex_match(Git::commitEntry(), entryRegex));
}

TEST_F(GitTest, shouldGenerateCommitMessage)
{
    const std::regex messageRegex("^" + GitTest::MESSAGE_REGEX + "$");

    const auto temp = Git::commitMessage();

    ASSERT_TRUE(std::regex_match(temp, messageRegex));
}

TEST_F(GitTest, shouldGenerateCommitSha)
{
    const unsigned length = 40;

    const std::regex shaRegex("^" + GitTest::generateShaRegex(length) + "$");

    ASSERT_TRUE(std::regex_match(Git::commitSha(length), shaRegex));
}

TEST_F(GitTest, shouldGenerateAuthor)
{
    const auto generatedAuthor = Git::author();

    const std::regex nameRegex(NAME_REGEX);

    const std::regex emailRegex(EMAIL_REGEX);

    ASSERT_TRUE(std::regex_match(generatedAuthor.name, nameRegex));
    ASSERT_TRUE(std::regex_match(generatedAuthor.email, emailRegex));
}
