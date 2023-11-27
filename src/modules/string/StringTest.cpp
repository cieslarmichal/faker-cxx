#include "faker-cxx/String.h"

#include <algorithm>
#include <random>
#include <stdexcept>

#include "gtest/gtest.h"

#include "data/Characters.h"
#include "faker-cxx/types/RandomGenerator.h"

using namespace ::testing;
using namespace faker;

class StringTest : public Test
{
public:
    const int runCount{100};
};

TEST_F(StringTest, shouldUseCustomRandomGeneratorForUuid4)
{
    RandomGenerator<std::mt19937> gen1{};
    const auto uuid1 = String::uuid(gen1);

    ASSERT_EQ(uuid1[8], '-');
    ASSERT_EQ(uuid1[13], '-');
    ASSERT_EQ(uuid1[14], '4');
    ASSERT_EQ(uuid1[18], '-');
    ASSERT_EQ(uuid1[23], '-');

    RandomGenerator<std::mt19937_64> gen2{};
    const auto uuid2 = String::uuid(gen2);

    ASSERT_EQ(uuid2[8], '-');
    ASSERT_EQ(uuid2[13], '-');
    ASSERT_EQ(uuid2[14], '4');
    ASSERT_EQ(uuid2[18], '-');
    ASSERT_EQ(uuid2[23], '-');

    RandomGenerator<std::minstd_rand0> gen3{};
    const auto uuid3 = String::uuid(gen3);

    ASSERT_EQ(uuid3[8], '-');
    ASSERT_EQ(uuid3[13], '-');
    ASSERT_EQ(uuid3[14], '4');
    ASSERT_EQ(uuid3[18], '-');
    ASSERT_EQ(uuid3[23], '-');

    RandomGenerator<std::minstd_rand> gen4{};
    const auto uuid4 = String::uuid(gen4);

    ASSERT_EQ(uuid4[8], '-');
    ASSERT_EQ(uuid4[13], '-');
    ASSERT_EQ(uuid4[14], '4');
    ASSERT_EQ(uuid4[18], '-');
    ASSERT_EQ(uuid4[23], '-');

    RandomGenerator<std::ranlux24_base> gen5{};
    const auto uuid5 = String::uuid(gen5);

    ASSERT_EQ(uuid5[8], '-');
    ASSERT_EQ(uuid5[13], '-');
    ASSERT_EQ(uuid5[14], '4');
    ASSERT_EQ(uuid5[18], '-');
    ASSERT_EQ(uuid5[23], '-');

    RandomGenerator<std::ranlux24> gen6{};
    const auto uuid6 = String::uuid(gen6);

    ASSERT_EQ(uuid6[8], '-');
    ASSERT_EQ(uuid6[13], '-');
    ASSERT_EQ(uuid6[14], '4');
    ASSERT_EQ(uuid6[18], '-');
    ASSERT_EQ(uuid6[23], '-');

    RandomGenerator<std::ranlux48_base> gen7{};
    const auto uuid7 = String::uuid(gen7);

    ASSERT_EQ(uuid7[8], '-');
    ASSERT_EQ(uuid7[13], '-');
    ASSERT_EQ(uuid7[14], '4');
    ASSERT_EQ(uuid7[18], '-');
    ASSERT_EQ(uuid7[23], '-');

    RandomGenerator<std::ranlux48> gen8{};
    const auto uuid8 = String::uuid(gen8);

    ASSERT_EQ(uuid8[8], '-');
    ASSERT_EQ(uuid8[13], '-');
    ASSERT_EQ(uuid8[14], '4');
    ASSERT_EQ(uuid8[18], '-');
    ASSERT_EQ(uuid8[23], '-');

    RandomGenerator<std::knuth_b> gen9{};
    const auto uuid9 = String::uuid(gen9);

    ASSERT_EQ(uuid9[8], '-');
    ASSERT_EQ(uuid9[13], '-');
    ASSERT_EQ(uuid9[14], '4');
    ASSERT_EQ(uuid9[18], '-');
    ASSERT_EQ(uuid9[23], '-');

    RandomGenerator<std::default_random_engine> gen10{};
    const auto uuid10 = String::uuid(gen10);

    ASSERT_EQ(uuid10[8], '-');
    ASSERT_EQ(uuid10[13], '-');
    ASSERT_EQ(uuid10[14], '4');
    ASSERT_EQ(uuid10[18], '-');
    ASSERT_EQ(uuid10[23], '-');
}

TEST_F(StringTest, shouldGenerateUuid4)
{
    const auto uuid = String::uuid();

    ASSERT_EQ(uuid[8], '-');
    ASSERT_EQ(uuid[13], '-');
    ASSERT_EQ(uuid[14], '4');
    ASSERT_EQ(uuid[18], '-');
    ASSERT_EQ(uuid[23], '-');
}

TEST_F(StringTest, shouldGenerateDefaultSampleString)
{
    const auto sample = String::sample();

    ASSERT_EQ(sample.size(), 10);
    ASSERT_TRUE(std::ranges::all_of(
        sample, [](char sampleCharacter)
        { return static_cast<int>(sampleCharacter) >= 33 && static_cast<int>(sampleCharacter) <= 125; }));
}

TEST_F(StringTest, shouldGenerateSampleString)
{
    const auto sample = String::sample(5);

    ASSERT_EQ(sample.size(), 5);
    ASSERT_TRUE(std::ranges::all_of(
        sample, [](char sampleCharacter)
        { return static_cast<int>(sampleCharacter) >= 33 && static_cast<int>(sampleCharacter) <= 125; }));
}

TEST_F(StringTest, shouldGenerateDefaultStringFromCharaters)
{
    const std::string characters{"abc"};

    const auto fromCharacters = String::fromCharacters(characters);

    ASSERT_EQ(fromCharacters.size(), 1);
    ASSERT_TRUE(std::ranges::all_of(fromCharacters, [&characters](char sampleCharacter)
                                    { return characters.find(sampleCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateStringFromCharaters)
{
    const std::string characters{"iosjdaijqw"};

    const auto fromCharacters = String::fromCharacters(characters, 6);

    ASSERT_EQ(fromCharacters.size(), 6);
    ASSERT_TRUE(std::ranges::all_of(fromCharacters, [&characters](char sampleCharacter)
                                    { return characters.find(sampleCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateDefaultApha)
{
    const auto alpha = String::alpha();

    ASSERT_EQ(alpha.size(), 1);
    ASSERT_TRUE(
        std::ranges::any_of(mixedAlphaCharacters, [alpha](char mixedCharacter) { return alpha[0] == mixedCharacter; }));
}

TEST_F(StringTest, shouldGenerateMixedAlpha)
{
    const auto alphaLength = 10;

    const auto alpha = String::alpha(alphaLength);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(std::ranges::all_of(alpha,
                                    [](char alphaCharacter)
                                    {
                                        return std::ranges::any_of(mixedAlphaCharacters,
                                                                   [alphaCharacter](char mixedCharacter)
                                                                   { return mixedCharacter == alphaCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateUpperAlpha)
{
    const auto alphaLength = 15;

    const auto alpha = String::alpha(alphaLength, StringCasing::Upper);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(std::ranges::all_of(alpha,
                                    [](char alphaCharacter)
                                    {
                                        return std::ranges::any_of(upperCharacters,
                                                                   [alphaCharacter](char upperCharacter)
                                                                   { return upperCharacter == alphaCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateLowerAlpha)
{
    const auto alphaLength = 7;

    const auto alpha = String::alpha(alphaLength, StringCasing::Lower);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(std::ranges::all_of(alpha,
                                    [](char alphaCharacter)
                                    {
                                        return std::ranges::any_of(lowerCharacters,
                                                                   [alphaCharacter](char lowerCharacter)
                                                                   { return lowerCharacter == alphaCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateMixedAlphaWithGuarantee)
{
    const auto alphaLength = 20;
    // exactly 5 'a'
    // atleast 5 'A' - 3 'B' - 3 'z'
    // atmost 20 'A' - 20 'B' - 6 'z'
    const GuaranteeMap&& guarantee{{'A', {5, 20}}, {'B', {3, 20}}, {'a', {5, 5}}, {'z', {3, 6}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto alpha = String::alpha(std::move(copyGuarantee), alphaLength);

        ASSERT_EQ(alpha.size(), alphaLength);
        ASSERT_TRUE(std::ranges::all_of(alpha,
                                        [](char alphaCharacter)
                                        {
                                            return std::ranges::any_of(mixedAlphaCharacters,
                                                                       [alphaCharacter](char mixedCharacter)
                                                                       { return mixedCharacter == alphaCharacter; });
                                        }));
        auto count_A = std::ranges::count(alpha, 'A');
        auto count_B = std::ranges::count(alpha, 'B');
        auto count_a = std::ranges::count(alpha, 'a');
        auto count_z = std::ranges::count(alpha, 'z');

        ASSERT_TRUE(count_A >= 5 && count_A <= 20);
        ASSERT_TRUE(count_B >= 3 && count_B <= 20);
        ASSERT_TRUE(count_a == 5);
        ASSERT_TRUE(count_z >= 3 && count_z <= 6);
    }
}

TEST_F(StringTest, shouldGenerateLowerAlphaWithGuarantee)
{
    const auto alphaLength = 20;
    // exactly 5 'a'
    // atleast 5 'k' - 3 'o' - 3 'z'
    // atmost 20 'k' - 20 'o' - 6 'z'
    const GuaranteeMap&& guarantee{{'k', {5, 20}}, {'o', {3, 20}}, {'a', {5, 5}}, {'z', {3, 6}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto alpha = String::alpha(std::move(copyGuarantee), alphaLength, StringCasing::Lower);

        ASSERT_EQ(alpha.size(), alphaLength);
        ASSERT_TRUE(std::ranges::all_of(alpha,
                                        [](char alphaCharacter)
                                        {
                                            return std::ranges::any_of(lowerCharSet,
                                                                       [alphaCharacter](char lowerCharacter)
                                                                       { return lowerCharacter == alphaCharacter; });
                                        }));
        auto count_k = std::ranges::count(alpha, 'k');
        auto count_o = std::ranges::count(alpha, 'o');
        auto count_a = std::ranges::count(alpha, 'a');
        auto count_z = std::ranges::count(alpha, 'z');

        ASSERT_TRUE(count_k >= 5 && count_k <= 20);
        ASSERT_TRUE(count_o >= 3 && count_o <= 20);
        ASSERT_TRUE(count_a == 5);
        ASSERT_TRUE(count_z >= 3 && count_z <= 6);
    }
}

TEST_F(StringTest, shouldGenerateUpperAlphaWithGuarantee)
{
    const auto alphaLength = 20;
    // exactly 5 'A'
    // atleast 5 'K' - 3 'O' - 3 'Z'
    // atmost 20 'K' - 20 'O' - 6 'Z'
    const GuaranteeMap&& guarantee{{'K', {5, 20}}, {'O', {3, 20}}, {'A', {5, 5}}, {'Z', {3, 6}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto alpha = String::alpha(std::move(copyGuarantee), alphaLength, StringCasing::Upper);

        ASSERT_EQ(alpha.size(), alphaLength);
        ASSERT_TRUE(std::ranges::all_of(alpha,
                                        [](char alphaCharacter)
                                        {
                                            return std::ranges::any_of(upperCharSet,
                                                                       [alphaCharacter](char lowerCharacter)
                                                                       { return lowerCharacter == alphaCharacter; });
                                        }));
        auto count_K = std::ranges::count(alpha, 'K');
        auto count_O = std::ranges::count(alpha, 'O');
        auto count_A = std::ranges::count(alpha, 'A');
        auto count_Z = std::ranges::count(alpha, 'Z');

        ASSERT_TRUE(count_K >= 5 && count_K <= 20);
        ASSERT_TRUE(count_O >= 3 && count_O <= 20);
        ASSERT_TRUE(count_A == 5);
        ASSERT_TRUE(count_Z >= 3 && count_Z <= 6);
    }
}

TEST_F(StringTest, invalidGuaranteeForAlpha1)
{
    const auto alphaLength = 20;
    // exactly 3 'Z'
    // atleast 8 'A' - 10 'B' 1 'Y' // invalid // string size will be atleast 22 which is invalid
    // atmost 10 'A','Y' - 15 'B'
    GuaranteeMap guarantee = {{'A', {8, 10}}, {'B', {10, 15}}, {'Y', {1, 10}}, {'Z', {3, 3}}};
    ASSERT_THROW(String::alpha(std::move(guarantee), alphaLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlpha2)
{
    const auto alphaLength = 30;
    // atmost 1 'A','B','C',D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    // invalid // string size won't exceed 26 which is invalid
    GuaranteeMap guarantee = {
        {'A', {0, 1}}, {'B', {0, 1}}, {'C', {0, 1}}, {'D', {0, 1}}, {'E', {0, 1}}, {'F', {0, 1}}, {'G', {0, 1}},
        {'H', {0, 1}}, {'I', {0, 1}}, {'J', {0, 1}}, {'K', {0, 1}}, {'L', {0, 1}}, {'M', {0, 1}}, {'N', {0, 1}},
        {'O', {0, 1}}, {'P', {0, 1}}, {'Q', {0, 1}}, {'R', {0, 1}}, {'S', {0, 1}}, {'T', {0, 1}}, {'U', {0, 1}},
        {'V', {0, 1}}, {'W', {0, 1}}, {'X', {0, 1}}, {'Y', {0, 1}}, {'Z', {0, 1}},
    };
    ASSERT_THROW(String::alpha(std::move(guarantee), alphaLength, StringCasing::Upper), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlpha3)
{
    const auto alphaLength = 20;
    // atleast 4 '5' // invalid // alpha can't have digits
    GuaranteeMap guarantee = {{'a', {4, 10}}, {'B', {4, 10}}, {'5', {4, 6}}};
    ASSERT_THROW(String::alpha(std::move(guarantee), alphaLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlpha4)
{
    const auto alphaLength = 20;
    // atleast 4 'a' // invalid // Can't have lower case characters when string casing is set to StringCasing::Upper
    GuaranteeMap guarantee = {{'a', {4, 10}}, {'B', {4, 10}}};
    ASSERT_THROW(String::alpha(std::move(guarantee), alphaLength, StringCasing::Upper), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlpha5)
{
    const auto alphaLength = 20;
    // atleast 4 'B' // invalid // Can't have upper case characters when string casing is set to StringCasing::Lower
    GuaranteeMap guarantee = {{'a', {4, 10}}, {'B', {4, 10}}};
    ASSERT_THROW(String::alpha(std::move(guarantee), alphaLength, StringCasing::Lower), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateDefaultAphanumeric)
{
    const auto alphanumeric = String::alphanumeric();

    ASSERT_EQ(alphanumeric.size(), 1);
    ASSERT_TRUE(std::ranges::any_of(mixedAlphanumericCharacters,
                                    [alphanumeric](char mixedCharacter) { return alphanumeric[0] == mixedCharacter; }));
}

TEST_F(StringTest, shouldGenerateMixedAlphanumeric)
{
    const auto alphanumericLength = 10;

    const auto alphanumeric = String::alphanumeric(alphanumericLength);

    ASSERT_EQ(alphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(std::ranges::all_of(alphanumeric,
                                    [](char alphanumericCharacter)
                                    {
                                        return std::ranges::any_of(
                                            mixedAlphanumericCharacters,
                                            [alphanumericCharacter](char mixedAlphanumericCharacter)
                                            { return alphanumericCharacter == mixedAlphanumericCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateUpperAlphanumeric)
{
    const auto alphanumericLength = 15;

    const auto alphanumeric = String::alphanumeric(alphanumericLength, StringCasing::Upper);

    ASSERT_EQ(alphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(std::ranges::all_of(alphanumeric,
                                    [](char alphanumericCharacter)
                                    {
                                        return std::ranges::any_of(
                                            upperAlphanumericCharacters,
                                            [alphanumericCharacter](char upperAlphanumericCharacter)
                                            { return upperAlphanumericCharacter == alphanumericCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateLowerAlphanumeric)
{
    const auto alphanumericLength = 7;

    const auto alphanumeric = String::alphanumeric(alphanumericLength, StringCasing::Lower);

    ASSERT_EQ(alphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(std::ranges::all_of(alphanumeric,
                                    [](char alphanumericCharacter)
                                    {
                                        return std::ranges::any_of(
                                            lowerAlphanumericCharacters,
                                            [alphanumericCharacter](char lowerAlphanumericCharacter)
                                            { return lowerAlphanumericCharacter == alphanumericCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateNumeric)
{
    const auto numeric = String::numeric();

    ASSERT_EQ(numeric.size(), 1);
    ASSERT_TRUE(
        std::ranges::any_of(numeric, [numeric](char numericCharacter) { return numeric[0] == numericCharacter; }));
}

TEST_F(StringTest, shouldGenerateNumericWithoutLeadingZeros)
{
    const auto numericLength = 13;

    const auto numeric = String::numeric(numericLength, false);

    const auto nonZeroCharacter = numeric[0];
    const auto numericWithPossibleZeroCharacters = numeric.substr(1);

    ASSERT_EQ(numeric.size(), numericLength);
    ASSERT_TRUE(std::ranges::any_of(numericCharactersWithoutZero, [nonZeroCharacter](char numericCharacter)
                                    { return nonZeroCharacter == numericCharacter; }));
    ASSERT_TRUE(std::ranges::all_of(numericWithPossibleZeroCharacters,
                                    [](char numericCharacterWithPossibleZero)
                                    {
                                        return std::ranges::any_of(
                                            numericCharacters, [numericCharacterWithPossibleZero](char numericCharacter)
                                            { return numericCharacterWithPossibleZero == numericCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateNumericWithGuarantee1)
{
    const auto numericLength = 20;
    // atleast 10 '0' - 5 '9'
    // atmost 15 '0' - 10 '9'
    const GuaranteeMap guarantee = {{'0', {10, 15}}, {'9', {5, 10}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto numeric = String::numeric(std::move(copyGuarantee), numericLength);

        ASSERT_EQ(numeric.size(), numericLength);
        ASSERT_TRUE(
            std::ranges::any_of(numeric, [numeric](char numericCharacter) { return numeric[0] == numericCharacter; }));

        auto count_0 = std::ranges::count(numeric, '0');
        auto count_9 = std::ranges::count(numeric, '9');

        ASSERT_TRUE(count_0 >= 10 && count_0 <= 15);
        ASSERT_TRUE(count_9 >= 5 && count_9 <= 10);
    }
}

TEST_F(StringTest, shouldGenerateNumericWithGuarantee2)
{
    const auto numericLength = 20;
    // exactly 0 '1' - 5 '9'
    // atleast 5 '2'
    // atmost 20 '2' - 1 '8'
    const GuaranteeMap guarantee = {{'1', {0, 0}}, {'2', {5, 20}}, {'8', {0, 1}}, {'9', {5, 5}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto numeric = String::numeric(std::move(copyGuarantee), numericLength);

        ASSERT_EQ(numeric.size(), numericLength);
        ASSERT_TRUE(
            std::ranges::any_of(numeric, [numeric](char numericCharacter) { return numeric[0] == numericCharacter; }));

        auto count_1 = std::ranges::count(numeric, '1');
        auto count_2 = std::ranges::count(numeric, '2');
        auto count_8 = std::ranges::count(numeric, '8');
        auto count_9 = std::ranges::count(numeric, '9');

        ASSERT_TRUE(count_1 == 0);
        ASSERT_TRUE(count_2 >= 5 && count_2 <= 20);
        ASSERT_TRUE(count_8 <= 1);
        ASSERT_TRUE(count_9 == 5);
    }
}

TEST_F(StringTest, shouldGenerateNumericWithoutLeadingZerosWithGuarantee1)
{
    const auto numericLength = 20;
    // atleast 19 '0'
    const GuaranteeMap guarantee = {{'0', {19}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto numeric = String::numeric(std::move(copyGuarantee), numericLength, false);

        const auto nonZeroCharacter = numeric[0];
        const auto numericWithPossibleZeroCharacters = numeric.substr(1);

        ASSERT_EQ(numeric.size(), numericLength);
        ASSERT_TRUE(std::ranges::any_of(numericCharactersWithoutZero, [nonZeroCharacter](char numericCharacter)
                                        { return nonZeroCharacter == numericCharacter; }));
        ASSERT_TRUE(std::ranges::all_of(
            numericWithPossibleZeroCharacters,
            [](char numericCharacterWithPossibleZero)
            {
                return std::ranges::any_of(numericCharacters, [numericCharacterWithPossibleZero](char numericCharacter)
                                           { return numericCharacterWithPossibleZero == numericCharacter; });
            }));
        auto count_0 = std::ranges::count(numeric, '0');

        ASSERT_TRUE(count_0 >= 19);
    }
}

TEST_F(StringTest, shouldGenerateNumericWithoutLeadingZerosWithGuarantee2)
{
    const auto numericLength = 20;
    // atleast 10 '0' - 3 '1' - 3 '3'
    // atmost 4 '1' - 4 '3'
    const GuaranteeMap guarantee = {{'0', {10}}, {'1', {3, 4}}, {'3', {2, 4}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto numeric = String::numeric(std::move(copyGuarantee), numericLength, false);

        const auto nonZeroCharacter = numeric[0];
        const auto numericWithPossibleZeroCharacters = numeric.substr(1);

        ASSERT_EQ(numeric.size(), numericLength);
        ASSERT_TRUE(std::ranges::any_of(numericCharactersWithoutZero, [nonZeroCharacter](char numericCharacter)
                                        { return nonZeroCharacter == numericCharacter; }));
        ASSERT_TRUE(std::ranges::all_of(
            numericWithPossibleZeroCharacters,
            [](char numericCharacterWithPossibleZero)
            {
                return std::ranges::any_of(numericCharacters, [numericCharacterWithPossibleZero](char numericCharacter)
                                           { return numericCharacterWithPossibleZero == numericCharacter; });
            }));
        auto count_0 = std::ranges::count(numeric, '0');
        auto count_1 = std::ranges::count(numeric, '1');
        auto count_3 = std::ranges::count(numeric, '3');

        ASSERT_TRUE(count_0 >= 10);
        ASSERT_TRUE(count_1 >= 3 && count_1 <= 4);
        ASSERT_TRUE(count_3 >= 2 && count_3 <= 4);
    }
}

TEST_F(StringTest, invalidGuaranteeForNumeric1)
{
    const auto numericLength = 20;
    // atleast 10 '0' - 3 '1' - 8 '3' // invalid // string size will be atleast 21 which is wrong
    // atmost 4 '1' - 10 '3'
    GuaranteeMap guarantee = {{'0', {10}}, {'1', {3, 4}}, {'3', {8, 10}}};
    ASSERT_THROW(String::numeric(std::move(guarantee), numericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForNumeric2)
{
    const auto numericLength = 20;
    // atmost 1 '0','1','2','3','4','5','6','7','8','9' // invalid // string size wont exceed 10 which is wrong
    GuaranteeMap guarantee = {
        {'1', {0, 1}}, {'2', {0, 1}}, {'3', {0, 1}}, {'4', {0, 1}}, {'5', {0, 1}},
        {'6', {0, 1}}, {'7', {0, 1}}, {'8', {0, 1}}, {'9', {0, 1}}, {'0', {0, 1}},
    };
    ASSERT_THROW(String::numeric(std::move(guarantee), numericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForNumeric3)
{
    const auto numericLength = 20;
    // exactly 5 'a' // invalid // numeric string can't have alphabets
    GuaranteeMap guarantee = {{'0', {10}}, {'1', {3, 4}}, {'3', {2, 4}}, {'a', {5, 5}}};
    ASSERT_THROW(String::numeric(std::move(guarantee), numericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForNumeric4)
{
    const auto numericLength = 5;
    // atleast 5 '0' // invalid // leading zeros not allowed so '0' count should be less than numericLength i.e 5
    GuaranteeMap guarantee = {{'0', {5}}};
    ASSERT_THROW(String::numeric(std::move(guarantee), numericLength, false), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateHexadecimal)
{
    const auto hexadecimalLength = 8;

    const auto hexadecimal = String::hexadecimal(hexadecimalLength);

    const auto prefix = hexadecimal.substr(0, 2);
    const auto hexNumber = hexadecimal.substr(2);

    ASSERT_EQ(hexadecimal.size(), hexadecimalLength + 2);
    ASSERT_EQ(prefix, "0x");
    ASSERT_TRUE(std::ranges::any_of(hexNumber, [hexNumber](char hexNumberCharacter)
                                    { return hexLowerCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateHexadecimalWithHashPrefix)
{
    const auto hexadecimalLength = 8;

    const auto hexadecimal = String::hexadecimal(hexadecimalLength, HexCasing::Upper, HexPrefix::Hash);

    const auto prefix = hexadecimal.substr(0, 1);
    const auto hexNumber = hexadecimal.substr(1);

    ASSERT_EQ(hexadecimal.size(), hexadecimalLength + 1);
    ASSERT_EQ(prefix, "#");
    ASSERT_TRUE(std::ranges::any_of(hexNumber, [](char hexNumberCharacter)
                                    { return hexUpperCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateHexadecimalWithoutPrefix)
{
    const auto hexadecimalLength = 8;

    const auto hexadecimal = String::hexadecimal(hexadecimalLength, HexCasing::Upper, HexPrefix::None);

    ASSERT_EQ(hexadecimal.size(), hexadecimalLength);
    ASSERT_TRUE(std::ranges::any_of(hexadecimal, [](char hexNumberCharacter)
                                    { return hexUpperCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateHexadecimalWithGuarantee1)
{
    const auto hexadecimalLength = 20;
    // exactly 4 'a'
    // atleast 3 'f'
    // atmost 10 'f'
    faker::GuaranteeMap guarantee{{'a', {4, 4}}, {'f', {3, 10}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto hexadecimal = String::hexadecimal(std::move(copyGuarantee), hexadecimalLength);
        const auto prefix = hexadecimal.substr(0, 2);
        const auto hexNumber = hexadecimal.substr(2);

        ASSERT_EQ(hexNumber.size(), hexadecimalLength);
        ASSERT_EQ(prefix, "0x");
        ASSERT_TRUE(std::ranges::any_of(hexNumber, [hexNumber](char hexNumberCharacter)
                                        { return hexLowerCharacters.find(hexNumberCharacter) != std::string::npos; }));

        auto count_a = std::ranges::count(hexNumber, 'a');
        auto count_f = std::ranges::count(hexNumber, 'f');
        ASSERT_TRUE(count_a == 4);
        ASSERT_TRUE(count_f >= 3 && count_f <= 10);
    }
}

TEST_F(StringTest, shouldGenerateHexadecimalWithGuarantee2)
{
    const auto hexadecimalLength = 20;
    // exactly 10 'F' - 0 'A'
    // atleast 5 '0'
    faker::GuaranteeMap guarantee{{'A', {0, 0}}, {'F', {10, 10}}, {'0', {5}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto hexadecimal = String::hexadecimal(std::move(copyGuarantee), hexadecimalLength, HexCasing::Upper);
        const auto prefix = hexadecimal.substr(0, 2);
        const auto hexNumber = hexadecimal.substr(2);

        ASSERT_EQ(hexNumber.size(), hexadecimalLength);
        ASSERT_EQ(prefix, "0x");
        ASSERT_TRUE(std::ranges::any_of(hexNumber, [hexNumber](char hexNumberCharacter)
                                        { return hexUpperCharacters.find(hexNumberCharacter) != std::string::npos; }));

        auto count_A = std::ranges::count(hexNumber, 'A');
        auto count_F = std::ranges::count(hexNumber, 'F');
        auto count_0 = std::ranges::count(hexNumber, '0');
        ASSERT_TRUE(count_A == 0);
        ASSERT_TRUE(count_F == 10);
        ASSERT_TRUE(count_0 >= 5);
    }
}

TEST_F(StringTest, shouldGenerateHexadecimalWithGuarantee3)
{
    const auto hexadecimalLength = 20;
    // exactly 0 '0' '1' '2' '3' '4' '5' '6' '7'
    faker::GuaranteeMap guarantee{
        {'0', {0, 0}}, {'1', {0, 0}}, {'2', {0, 0}}, {'3', {0, 0}},
        {'4', {0, 0}}, {'5', {0, 0}}, {'6', {0, 0}}, {'7', {0, 0}},
    };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto hexadecimal = String::hexadecimal(std::move(copyGuarantee), hexadecimalLength, HexCasing::Upper);
        const auto prefix = hexadecimal.substr(0, 2);
        const auto hexNumber = hexadecimal.substr(2);

        ASSERT_EQ(hexNumber.size(), hexadecimalLength);
        ASSERT_EQ(prefix, "0x");
        ASSERT_TRUE(std::ranges::any_of(hexNumber, [hexNumber](char hexNumberCharacter)
                                        { return hexUpperCharacters.find(hexNumberCharacter) != std::string::npos; }));

        auto count_0 = std::ranges::count(hexNumber, '0');
        auto count_1 = std::ranges::count(hexNumber, '1');
        auto count_2 = std::ranges::count(hexNumber, '2');
        auto count_3 = std::ranges::count(hexNumber, '3');
        auto count_4 = std::ranges::count(hexNumber, '4');
        auto count_5 = std::ranges::count(hexNumber, '5');
        auto count_6 = std::ranges::count(hexNumber, '6');
        auto count_7 = std::ranges::count(hexNumber, '7');
        ASSERT_TRUE(count_0 == 0);
        ASSERT_TRUE(count_1 == 0);
        ASSERT_TRUE(count_2 == 0);
        ASSERT_TRUE(count_3 == 0);
        ASSERT_TRUE(count_4 == 0);
        ASSERT_TRUE(count_5 == 0);
        ASSERT_TRUE(count_6 == 0);
        ASSERT_TRUE(count_7 == 0);
    }
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal1)
{
    const auto hexadecimalLength = 20;
    // atleast 5 'G' // invalid // 'G' is not a valid char for hexadecimal numbers
    faker::GuaranteeMap guarantee{{'A', {0, 0}}, {'F', {10, 10}}, {'G', {5}}};
    ASSERT_THROW(String::hexadecimal(std::move(guarantee), hexadecimalLength, HexCasing::Upper), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal2)
{
    const auto hexadecimalLength = 20;
    // atleast 5 'F' // invalid // 'F' is not a valid char for hexadecimal numbers with HexCasing::Lower
    faker::GuaranteeMap guarantee{{'a', {0, 0}}, {'F', {10, 10}}, {'1', {5}}};
    ASSERT_THROW(String::hexadecimal(std::move(guarantee), hexadecimalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal3)
{
    const auto hexadecimalLength = 20;
    // atleast 5 'F' // invalid // 'F' is not a valid char for hexadecimal numbers with HexCasing::Lower
    faker::GuaranteeMap guarantee{{'a', {0, 0}}, {'F', {10, 10}}, {'1', {5}}};
    ASSERT_THROW(String::hexadecimal(std::move(guarantee), hexadecimalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal4)
{
    const auto hexadecimalLength = 10;
    // atleast 5 'a' - 8 'b' // invalid // string size will be atleast 13 which is wrong
    // atmost 10 'b' - 3 '1'
    faker::GuaranteeMap guarantee{{'a', {5}}, {'b', {8, 10}}, {'1', {0, 3}}};
    ASSERT_THROW(String::hexadecimal(std::move(guarantee), hexadecimalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal5)
{
    const auto hexadecimalLength = 20;
    // atmost 1 '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' // invalid // string size wont exceed 16
    // which is wrong
    faker::GuaranteeMap guarantee{
        {'0', {0, 1}}, {'1', {0, 1}}, {'2', {0, 1}}, {'3', {0, 1}}, {'4', {0, 1}}, {'5', {0, 1}},
        {'6', {0, 1}}, {'7', {0, 1}}, {'8', {0, 1}}, {'9', {0, 1}}, {'a', {0, 1}}, {'b', {0, 1}},
        {'c', {0, 1}}, {'d', {0, 1}}, {'e', {0, 1}}, {'f', {0, 1}},
    };
    ASSERT_THROW(String::hexadecimal(std::move(guarantee), hexadecimalLength), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateBinary)
{
    const auto binaryLength = 8;

    const auto binary = String::binary(binaryLength);

    const auto prefix = binary.substr(0, 2);
    const auto binaryNumber = binary.substr(2);

    ASSERT_EQ(binary.size(), binaryLength + 2);
    ASSERT_EQ(prefix, "0b");
    ASSERT_TRUE(std::ranges::any_of(binary, [](char binaryNumberCharacter)
                                    { return std::string("01").find(binaryNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateBinaryWithGuarantee1)
{
    const auto binaryLength = 9;

    // atleast 3 '0' and 2 '1'
    // atmost 7 '0' and 7 '1'
    faker::GuaranteeMap guarantee{{'0', {3, 7}}, {'1', {2, 7}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto binary = String::binary(std::move(copyGuarantee), binaryLength);

        const auto prefix = binary.substr(0, 2);
        const auto binaryNumber = binary.substr(2);

        ASSERT_EQ(binaryNumber.size(), binaryLength);
        ASSERT_EQ(prefix, "0b");
        ASSERT_TRUE(
            std::ranges::any_of(binaryNumber, [](char binaryNumberCharacter)
                                { return std::string("01").find(binaryNumberCharacter) != std::string::npos; }));
        auto count_0 = std::count(binaryNumber.begin(), binaryNumber.end(), '0');
        auto count_1 = std::count(binaryNumber.begin(), binaryNumber.end(), '1');
        ASSERT_TRUE(count_0 >= 3 && count_0 <= 7);
        ASSERT_TRUE(count_1 >= 2 && count_1 <= 7);
    }
}
TEST_F(StringTest, shouldGenerateBinaryWithGuarantee2)
{
    const auto binaryLength = 10;

    // exactly 8 '0' and 2 '1'
    faker::GuaranteeMap guarantee{{'0', {8, 8}}, {'1', {2, 2}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto binary = String::binary(std::move(copyGuarantee), binaryLength);

        const auto prefix = binary.substr(0, 2);
        const auto binaryNumber = binary.substr(2);

        ASSERT_EQ(binaryNumber.size(), binaryLength);
        ASSERT_EQ(prefix, "0b");
        ASSERT_TRUE(
            std::ranges::any_of(binaryNumber, [](char binaryNumberCharacter)
                                { return std::string("01").find(binaryNumberCharacter) != std::string::npos; }));
        auto count_0 = std::count(binaryNumber.begin(), binaryNumber.end(), '0');
        auto count_1 = std::count(binaryNumber.begin(), binaryNumber.end(), '1');
        ASSERT_TRUE(count_0 == 8);
        ASSERT_TRUE(count_1 == 2);
    }
}
TEST_F(StringTest, shouldGenerateBinaryWithGuarantee3)
{
    const auto binaryLength = 10;

    // atleast 10 '0'
    faker::GuaranteeMap guarantee{{'0', {10}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto binary = String::binary(std::move(copyGuarantee), binaryLength);

        const auto prefix = binary.substr(0, 2);
        const auto binaryNumber = binary.substr(2);

        ASSERT_EQ(binaryNumber.size(), binaryLength);
        ASSERT_EQ(prefix, "0b");
        ASSERT_TRUE(
            std::ranges::any_of(binaryNumber, [](char binaryNumberCharacter)
                                { return std::string("01").find(binaryNumberCharacter) != std::string::npos; }));
        auto count_0 = std::count(binaryNumber.begin(), binaryNumber.end(), '0');
        ASSERT_TRUE(count_0 == 10);
    }
}

TEST_F(StringTest, shouldGenerateBinaryWithGuarantee4)
{
    const auto binaryLength = 10;

    // atmost 0 '0'
    faker::GuaranteeMap guarantee{{'0', {0, 0}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto binary = String::binary(std::move(copyGuarantee), binaryLength);

        const auto prefix = binary.substr(0, 2);
        const auto binaryNumber = binary.substr(2);

        ASSERT_EQ(binaryNumber.size(), binaryLength);
        ASSERT_EQ(prefix, "0b");
        ASSERT_TRUE(
            std::ranges::any_of(binaryNumber, [](char binaryNumberCharacter)
                                { return std::string("01").find(binaryNumberCharacter) != std::string::npos; }));
        auto count_0 = std::count(binaryNumber.begin(), binaryNumber.end(), '0');
        ASSERT_TRUE(count_0 == 0);
    }
}

TEST_F(StringTest, invalidGuaranteeForBinary1)
{
    const auto binaryLength = 10;

    // atleast 6 '0' and 6 '1'  // invalid // total string size will be 12 which is wrong
    // atleast 10 '0' and 10 '1'
    faker::GuaranteeMap guarantee{{'0', {6, 10}}, {'1', {6, 10}}};
    EXPECT_THROW(String::binary(std::move(guarantee), binaryLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForBinary2)
{
    const auto binaryLength = 20;

    // atleast 6 '0' and 6 '1'
    // atleast 10 '0' and 8 '1' // invalid // total string size won't exceed 18 which is wrong
    faker::GuaranteeMap guarantee{{'0', {6, 10}}, {'1', {6, 8}}};
    EXPECT_THROW(String::binary(std::move(guarantee), binaryLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForBinary3)
{
    const auto binaryLength = 10;
    //  atleast 4 '0' and 3 'a' // invalid // binary string should consist of only '0' and '1'
    faker::GuaranteeMap guarantee{{'0', {4}}, {'a', {3}}};
    EXPECT_THROW(String::binary(std::move(guarantee), binaryLength), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateOctalWithPrefix)
{
    const auto octalLength = 8;

    const auto octal = String::octal(octalLength);

    const auto prefix = octal.substr(0, 2);
    const auto octalNumber = octal.substr(2);

    ASSERT_EQ(octal.size(), octalLength + 2);
    ASSERT_EQ(prefix, "0o");
    ASSERT_TRUE(
        std::ranges::any_of(octal, [](char octalNumberCharacter)
                            { return std::string("01234567").find(octalNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateOctalWithGuarantee1)
{
    const auto octalLength = 10;
    // exactly 2 '3' - 0 '5'
    // atleast 2 '0' - 3 '6' - 1 '7'
    // atmost 10 '6' - 10 '7'
    GuaranteeMap guarantee{{'0', {2}}, {'3', {2, 2}}, {'5', {0, 0}}, {'6', {3, 10}}, {'7', {1, 10}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto octal = String::octal(std::move(copyGuarantee), octalLength);

        const auto prefix = octal.substr(0, 2);
        const auto octalNumber = octal.substr(2);

        ASSERT_EQ(octalNumber.size(), octalLength);
        ASSERT_EQ(prefix, "0o");
        ASSERT_TRUE(
            std::ranges::any_of(octal, [](char octalNumberCharacter)
                                { return std::string("01234567").find(octalNumberCharacter) != std::string::npos; }));
        auto count_0 = std::ranges::count(octalNumber, '0');
        auto count_3 = std::ranges::count(octalNumber, '3');
        auto count_5 = std::ranges::count(octalNumber, '5');
        auto count_6 = std::ranges::count(octalNumber, '6');
        auto count_7 = std::ranges::count(octalNumber, '7');
        ASSERT_TRUE(count_0 >= 2);
        ASSERT_TRUE(count_3 == 2);
        ASSERT_TRUE(count_5 == 0);
        ASSERT_TRUE(count_6 >= 3 && count_6 <= 10);
        ASSERT_TRUE(count_7 >= 1 && count_7 <= 10);
    }
}

TEST_F(StringTest, shouldGenerateOctalWithGuarantee2)
{
    const auto octalLength = 20;
    // exactly 0 '2' '3' '4' '5' '6' '7'
    // atleast 18 '0'
    GuaranteeMap guarantee{{'0', {18}},   {'2', {0, 0}}, {'3', {0, 0}}, {'4', {0, 0}},
                           {'5', {0, 0}}, {'6', {0, 0}}, {'7', {0, 0}}};
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto octal = String::octal(std::move(copyGuarantee), octalLength);

        const auto prefix = octal.substr(0, 2);
        const auto octalNumber = octal.substr(2);

        ASSERT_EQ(octalNumber.size(), octalLength);
        ASSERT_EQ(prefix, "0o");
        ASSERT_TRUE(
            std::ranges::any_of(octal, [](char octalNumberCharacter)
                                { return std::string("01234567").find(octalNumberCharacter) != std::string::npos; }));
        auto count_0 = std::ranges::count(octalNumber, '0');
        auto count_2 = std::ranges::count(octalNumber, '2');
        auto count_3 = std::ranges::count(octalNumber, '3');
        auto count_4 = std::ranges::count(octalNumber, '4');
        auto count_5 = std::ranges::count(octalNumber, '5');
        auto count_6 = std::ranges::count(octalNumber, '6');
        auto count_7 = std::ranges::count(octalNumber, '7');

        ASSERT_TRUE(count_0 >= 18);
        ASSERT_TRUE(count_2 == 0);
        ASSERT_TRUE(count_3 == 0);
        ASSERT_TRUE(count_4 == 0);
        ASSERT_TRUE(count_5 == 0);
        ASSERT_TRUE(count_6 == 0);
        ASSERT_TRUE(count_7 == 0);
    }
}

TEST_F(StringTest, invalidGuaranteeForOctal1)
{
    const auto octalLength = 10;
    // exactly 0 '4'
    // atleast 8 '0' - 9 '2' 9 '3'  // invalid // total string size will be atleast 26 which is wrong
    // atmost
    GuaranteeMap guarantee{{'0', {8}}, {'2', {9}}, {'3', {9}}, {'4', {0, 0}}};
    ASSERT_THROW(String::octal(std::move(guarantee), octalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForOctal2)
{
    const auto octalLength = 20;
    // atmost 2 '0' '1' '2' '3' '4' '5' '6' '7' // invalid // octal string won't exceed 16 which is wrong
    GuaranteeMap guarantee{{'0', {0, 2}}, {'1', {0, 2}}, {'2', {0, 2}}, {'3', {0, 2}},
                           {'4', {0, 2}}, {'5', {0, 2}}, {'6', {0, 2}}, {'7', {0, 2}}};
    ASSERT_THROW(String::octal(std::move(guarantee), octalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForOctal3)
{
    const auto octalLength = 20;

    // atleast 2 '8' // invalid // octal numbers cannot have '8'
    // atmost 3 '8'
    GuaranteeMap guarantee{{'0', {0, 2}}, {'1', {0, 2}}, {'8', {2, 3}}, {'2', {0, 2}}, {'3', {0, 2}}};
    ASSERT_THROW(String::octal(std::move(guarantee), octalLength), std::invalid_argument);
}
