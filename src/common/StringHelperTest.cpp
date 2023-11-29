#include "StringHelper.h"

#include <algorithm>

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

class StringHelperTest : public Test
{
public:
};

TEST_F(StringHelperTest, splitStringBySpace)
{
    const auto result = StringHelper::split("faker cxx open source");

    ASSERT_EQ(result.size(), 4);
    ASSERT_EQ(result[0], "faker");
    ASSERT_EQ(result[1], "cxx");
    ASSERT_EQ(result[2], "open");
    ASSERT_EQ(result[3], "source");
}

TEST_F(StringHelperTest, splitStringByNewLine)
{
    const auto result = StringHelper::split("faker\ncxx\nopen\nsource", "\n");

    ASSERT_EQ(result.size(), 4);
    ASSERT_EQ(result[0], "faker");
    ASSERT_EQ(result[1], "cxx");
    ASSERT_EQ(result[2], "open");
    ASSERT_EQ(result[3], "source");
}

TEST_F(StringHelperTest, joinStringsIntoVectorBySpace)
{
    const std::vector<std::string> input{"Join", "faker", "development!"};

    const auto result = StringHelper::join(input);

    ASSERT_EQ(result, "Join faker development!");
}

TEST_F(StringHelperTest, joinStringsIntoVectorByNewLine)
{
    const std::vector<std::string> input{"Join", "faker", "development!"};

    const auto result = StringHelper::join(input, "\n");

    ASSERT_EQ(result, "Join\nfaker\ndevelopment!");
}

TEST_F(StringHelperTest, repeatString)
{
    const std::string data = "hello ";
    const int repetition = 3;

    const std::string result = StringHelper::repeat(data, repetition);

    ASSERT_EQ(result, "hello hello hello ");
}

TEST_F(StringHelperTest, toLower)
{
    const std::string data = "HeLlo!";

    const std::string result = StringHelper::toLower(data);

    ASSERT_EQ(result, "hello!");
}

TEST_F(StringHelperTest, IsPunctuation)
{
    std::string punctuation = ".,;:!?";
    for (char c : punctuation)
    {
        EXPECT_TRUE(StringHelper::isPunctuation(c));
    }

    std::string notPunctuation = "abc123";
    for (char c : notPunctuation)
    {
        EXPECT_FALSE(StringHelper::isPunctuation(c));
    }
}

TEST_F(StringHelperTest, RemovePunctuation)
{
    std::string input = "Hello, World!";
    std::string result = StringHelper::removePunctuation(input);
    EXPECT_EQ(result, "Hello World");
}

