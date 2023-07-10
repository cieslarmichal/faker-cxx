#include "String.h"

#include "gtest/gtest.h"

#include "data/AlphanumericCharacters.h"

using namespace ::testing;
using namespace faker;

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
    ASSERT_TRUE(std::any_of(mixedAlphaCharacters.begin(), mixedAlphaCharacters.end(),
                            [alpha](char mixedCharacter) { return alpha[0] == mixedCharacter; }));
}

TEST_F(StringTest, shouldGenerateMixedAlpha)
{
    const auto alphaLength = 10;

    const auto alpha = String::alpha(alphaLength);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(std::all_of(alpha.begin(), alpha.end(),
                            [](char alphaCharacter)
                            {
                                return std::any_of(mixedAlphaCharacters.begin(), mixedAlphaCharacters.end(),
                                                   [alphaCharacter](char mixedCharacter)
                                                   { return mixedCharacter == alphaCharacter; });
                            }));
}

TEST_F(StringTest, shouldGenerateUpperAlpha)
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

TEST_F(StringTest, shouldGenerateLowerAlpha)
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

TEST_F(StringTest, shouldGenerateDefaultAphanumeric)
{
    const auto alphanumeric = String::alphanumeric();

    ASSERT_EQ(alphanumeric.size(), 1);
    ASSERT_TRUE(std::any_of(mixedAlphanumericCharacters.begin(), mixedAlphanumericCharacters.end(),
                            [alphanumeric](char mixedCharacter) { return alphanumeric[0] == mixedCharacter; }));
}

TEST_F(StringTest, shouldGenerateMixedAlphanumeric)
{
    const auto alphanumericLength = 10;

    const auto alphanumeric = String::alphanumeric(alphanumericLength);

    ASSERT_EQ(alphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(std::all_of(alphanumeric.begin(), alphanumeric.end(),
                            [](char alphanumericCharacter)
                            {
                                return std::any_of(mixedAlphanumericCharacters.begin(),
                                                   mixedAlphanumericCharacters.end(),
                                                   [alphanumericCharacter](char mixedAlphanumericCharacter)
                                                   { return alphanumericCharacter == mixedAlphanumericCharacter; });
                            }));
}

TEST_F(StringTest, shouldGenerateUpperAlphanumeric)
{
    const auto alphanumericLength = 15;

    const auto alphanumeric = String::alphanumeric(alphanumericLength, StringCasing::Upper);

    ASSERT_EQ(alphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(std::all_of(alphanumeric.begin(), alphanumeric.end(),
                            [](char alphanumericCharacter)
                            {
                                return std::any_of(upperAlphanumericCharacters.begin(),
                                                   upperAlphanumericCharacters.end(),
                                                   [alphanumericCharacter](char upperAlphanumericCharacter)
                                                   { return upperAlphanumericCharacter == alphanumericCharacter; });
                            }));
}

TEST_F(StringTest, shouldGenerateLowerAlphanumeric)
{
    const auto alphanumericLength = 7;

    const auto alphanumeric = String::alphanumeric(alphanumericLength, StringCasing::Lower);

    ASSERT_EQ(alphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(std::all_of(alphanumeric.begin(), alphanumeric.end(),
                            [](char alphanumericCharacter)
                            {
                                return std::any_of(lowerAlphanumericCharacters.begin(),
                                                   lowerAlphanumericCharacters.end(),
                                                   [alphanumericCharacter](char lowerAlphanumericCharacter)
                                                   { return lowerAlphanumericCharacter == alphanumericCharacter; });
                            }));
}

TEST_F(StringTest, shouldGenerateNumeric)
{
    const auto numeric = String::numeric();

    ASSERT_EQ(numeric.size(), 1);
    ASSERT_TRUE(std::any_of(numeric.begin(), numeric.end(),
                            [numeric](char numericCharacter) { return numeric[0] == numericCharacter; }));
}

TEST_F(StringTest, shouldGenerateNumericWithoutLeadingZeros)
{
    const auto numericLength = 13;

    const auto numeric = String::numeric(numericLength, true);

    const auto nonZeroCharacter = numeric[0];
    const auto numericWithPossibleZeroCharacters = numeric.substr(1);

    ASSERT_EQ(numeric.size(), numericLength);
    ASSERT_TRUE(std::any_of(numericCharactersWithoutZero.begin(), numericCharactersWithoutZero.end(),
                            [nonZeroCharacter](char numericCharacter)
                            { return nonZeroCharacter == numericCharacter; }));
    ASSERT_TRUE(std::all_of(numericWithPossibleZeroCharacters.begin(), numericWithPossibleZeroCharacters.end(),
                            [](char numericCharacterWithPossibleZero)
                            {
                                return std::any_of(numericCharacters.begin(), numericCharacters.end(),
                                                   [numericCharacterWithPossibleZero](char numericCharacter)
                                                   { return numericCharacterWithPossibleZero == numericCharacter; });
                            }));
}
