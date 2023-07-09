#include "String.h"

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

namespace
{
const std::string upperCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string lowerCharacters = "abcdefghijklmnopqrstuvwxyz";
const std::string mixedCharacters = upperCharacters + lowerCharacters;
}

class StringTest : public Test
{
public:
};

TEST_F(StringTest, shouldGenerateUuid4)
{
    const auto uuid = String::uuid();

    ASSERT_EQ(uuid[8], '-');
    ASSERT_EQ(uuid[13], '-');
    ASSERT_EQ(uuid[14], '4');
    ASSERT_EQ(uuid[18], '-');
    ASSERT_EQ(uuid[23], '-');
}

TEST_F(StringTest, shouldGenerateDefaultApha)
{
    const auto alpha = String::alpha();

    ASSERT_EQ(alpha.size(), 1);
    ASSERT_TRUE(std::any_of(mixedCharacters.begin(), mixedCharacters.end(),
                            [alpha](char mixedCharacter) { return alpha[0] == mixedCharacter; }));
}

TEST_F(StringTest, shouldGenerateMixedString)
{
    const auto alphaLength = 10;

    const auto alpha = String::alpha(alphaLength);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(std::all_of(alpha.begin(), alpha.end(),
                            [](char alphaCharacter)
                            {
                                return std::any_of(mixedCharacters.begin(), mixedCharacters.end(),
                                                   [alphaCharacter](char mixedCharacter)
                                                   { return mixedCharacter == alphaCharacter; });
                            }));
}

TEST_F(StringTest, shouldGenerateUpperString)
{
    const auto alphaLength = 15;

    const auto alpha = String::alpha(alphaLength, StringCasing::Upper);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(std::all_of(alpha.begin(), alpha.end(),
                            [](char alphaCharacter)
                            {
                                return std::any_of(upperCharacters.begin(), upperCharacters.end(),
                                                   [alphaCharacter](char upperCharacter)
                                                   { return upperCharacter == alphaCharacter; });
                            }));
}

TEST_F(StringTest, shouldGenerateLowerString)
{
    const auto alphaLength = 7;

    const auto alpha = String::alpha(alphaLength, StringCasing::Lower);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(std::all_of(alpha.begin(), alpha.end(),
                            [](char alphaCharacter)
                            {
                                return std::any_of(lowerCharacters.begin(), lowerCharacters.end(),
                                                   [alphaCharacter](char lowerCharacter)
                                                   { return lowerCharacter == alphaCharacter; });
                            }));
}
