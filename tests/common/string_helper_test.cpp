#include "../test_helpers.h"
#include <common/string_helper.h>

using namespace faker;

TEST(StringHelperTest, splitStringBySpace)
{
    const auto result = utils::split("faker cxx open source");

    ASSERT_EQ(result.size(), 4);
    ASSERT_EQ(result[0], "faker");
    ASSERT_EQ(result[1], "cxx");
    ASSERT_EQ(result[2], "open");
    ASSERT_EQ(result[3], "source");
}

TEST(StringHelperTest, splitStringByNewLine)
{
    const auto result = utils::split("faker\ncxx\nopen\nsource", "\n");

    ASSERT_EQ(result.size(), 4);
    ASSERT_EQ(result[0], "faker");
    ASSERT_EQ(result[1], "cxx");
    ASSERT_EQ(result[2], "open");
    ASSERT_EQ(result[3], "source");
}

TEST(StringHelperTest, joinStringsIntoVectorBySpace)
{
    const std::vector<std::string> input { "Join", "faker", "development!" };

    const auto result = utils::join(input);

    ASSERT_EQ(result, "Join faker development!");
}

TEST(StringHelperTest, joinStringsIntoVectorByNewLine)
{
    const std::vector<std::string> input { "Join", "faker", "development!" };

    const auto result = utils::join(input, "\n");

    ASSERT_EQ(result, "Join\nfaker\ndevelopment!");
}

TEST(StringHelperTest, repeatString)
{
    const std::string data = "hello ";
    const int repetition = 3;

    const std::string result = utils::repeat(data, repetition);

    ASSERT_EQ(result, "hello hello hello ");
}

TEST(StringHelperTest, to_lower)
{
    const std::string data = "HeLlo!";

    const std::string result = utils::to_lower(data);

    ASSERT_EQ(result, "hello!");
}

TEST(StringHelperTest, IsPunctuation)
{
    std::string punctuation = ".,;:!?";
    for (char c : punctuation) {
        EXPECT_TRUE(utils::is_punctuation(c));
    }

    std::string notPunctuation = "abc123";
    for (char c : notPunctuation) {
        EXPECT_FALSE(utils::is_punctuation(c));
    }
}

TEST(StringHelperTest, RemovePunctuation)
{
    std::string input = "Hello, World!";
    std::string result = utils::remove_punctuation(input);
    EXPECT_EQ(result, "Hello World");
}
