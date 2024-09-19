#include <algorithm>
#include <cctype>
#include <random>
#include <stdexcept>
#include <string>
#include <utility>

#include "gtest/gtest.h"

#include "faker-cxx/random_generator.h"
#include "faker-cxx/string.h"
#include "faker-cxx/types/hex.h"
#include "string_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::string;

class StringTest : public Test
{
public:
    const int runCount{100};
};

TEST_F(StringTest, shouldUseCustomRandomGeneratorForUuid4)
{
    RandomGenerator<std::mt19937> gen1{};
    const auto generatedUuid1 = uuid(gen1);

    ASSERT_EQ(generatedUuid1[8], '-');
    ASSERT_EQ(generatedUuid1[13], '-');
    ASSERT_EQ(generatedUuid1[14], '4');
    ASSERT_EQ(generatedUuid1[18], '-');
    ASSERT_EQ(generatedUuid1[23], '-');

    RandomGenerator<std::mt19937_64> gen2{};
    const auto generatedUuid2 = uuid(gen2);

    ASSERT_EQ(generatedUuid2[8], '-');
    ASSERT_EQ(generatedUuid2[13], '-');
    ASSERT_EQ(generatedUuid2[14], '4');
    ASSERT_EQ(generatedUuid2[18], '-');
    ASSERT_EQ(generatedUuid2[23], '-');

    RandomGenerator<std::minstd_rand0> gen3{};
    const auto generatedUuid3 = uuid(gen3);

    ASSERT_EQ(generatedUuid3[8], '-');
    ASSERT_EQ(generatedUuid3[13], '-');
    ASSERT_EQ(generatedUuid3[14], '4');
    ASSERT_EQ(generatedUuid3[18], '-');
    ASSERT_EQ(generatedUuid3[23], '-');

    RandomGenerator<std::minstd_rand> gen4{};
    const auto generatedUuid4 = uuid(gen4);

    ASSERT_EQ(generatedUuid4[8], '-');
    ASSERT_EQ(generatedUuid4[13], '-');
    ASSERT_EQ(generatedUuid4[14], '4');
    ASSERT_EQ(generatedUuid4[18], '-');
    ASSERT_EQ(generatedUuid4[23], '-');

    RandomGenerator<std::ranlux24_base> gen5{};
    const auto generatedUuid5 = uuid(gen5);

    ASSERT_EQ(generatedUuid5[8], '-');
    ASSERT_EQ(generatedUuid5[13], '-');
    ASSERT_EQ(generatedUuid5[14], '4');
    ASSERT_EQ(generatedUuid5[18], '-');
    ASSERT_EQ(generatedUuid5[23], '-');

    RandomGenerator<std::ranlux24> gen6{};
    const auto generatedUuid6 = uuid(gen6);

    ASSERT_EQ(generatedUuid6[8], '-');
    ASSERT_EQ(generatedUuid6[13], '-');
    ASSERT_EQ(generatedUuid6[14], '4');
    ASSERT_EQ(generatedUuid6[18], '-');
    ASSERT_EQ(generatedUuid6[23], '-');

    RandomGenerator<std::ranlux48_base> gen7{};
    const auto generatedUuid7 = uuid(gen7);

    ASSERT_EQ(generatedUuid7[8], '-');
    ASSERT_EQ(generatedUuid7[13], '-');
    ASSERT_EQ(generatedUuid7[14], '4');
    ASSERT_EQ(generatedUuid7[18], '-');
    ASSERT_EQ(generatedUuid7[23], '-');

    RandomGenerator<std::ranlux48> gen8{};
    const auto generatedUuid8 = uuid(gen8);

    ASSERT_EQ(generatedUuid8[8], '-');
    ASSERT_EQ(generatedUuid8[13], '-');
    ASSERT_EQ(generatedUuid8[14], '4');
    ASSERT_EQ(generatedUuid8[18], '-');
    ASSERT_EQ(generatedUuid8[23], '-');

    RandomGenerator<std::knuth_b> gen9{};
    const auto generatedUuid9 = uuid(gen9);

    ASSERT_EQ(generatedUuid9[8], '-');
    ASSERT_EQ(generatedUuid9[13], '-');
    ASSERT_EQ(generatedUuid9[14], '4');
    ASSERT_EQ(generatedUuid9[18], '-');
    ASSERT_EQ(generatedUuid9[23], '-');

    RandomGenerator<std::default_random_engine> gen10{};
    const auto generatedUuid10 = uuid(gen10);

    ASSERT_EQ(generatedUuid10[8], '-');
    ASSERT_EQ(generatedUuid10[13], '-');
    ASSERT_EQ(generatedUuid10[14], '4');
    ASSERT_EQ(generatedUuid10[18], '-');
    ASSERT_EQ(generatedUuid10[23], '-');
}

TEST_F(StringTest, shouldGenerateUuid4)
{
    const auto generatedUuid = uuid();

    ASSERT_EQ(generatedUuid[8], '-');
    ASSERT_EQ(generatedUuid[13], '-');
    ASSERT_EQ(generatedUuid[14], '4');
    ASSERT_EQ(generatedUuid[18], '-');
    ASSERT_EQ(generatedUuid[23], '-');
}

TEST_F(StringTest, shouldGenerateDefaultSampleString)
{
    const auto generatedSample = sample();

    ASSERT_EQ(generatedSample.size(), 10);
    ASSERT_TRUE(std::ranges::all_of(
        generatedSample, [](char sampleCharacter)
        { return static_cast<int>(sampleCharacter) >= 33 && static_cast<int>(sampleCharacter) <= 125; }));
}

TEST_F(StringTest, shouldGenerateSampleString)
{
    const auto generatedSample = sample(5);

    ASSERT_EQ(generatedSample.size(), 5);
    ASSERT_TRUE(std::ranges::all_of(
        generatedSample, [](char sampleCharacter)
        { return static_cast<int>(sampleCharacter) >= 33 && static_cast<int>(sampleCharacter) <= 125; }));
}

TEST_F(StringTest, shouldGenerateSampleStringWithGuarantee1)
{
    const auto sampleLength{20};
    const GuaranteeMap guarantee = {{';', {1, 3}}, {',', {3, 4}}, {'a', {2, 10}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedSample = sample(std::move(copyGuarantee), sampleLength);

        ASSERT_EQ(generatedSample.size(), sampleLength);
        ASSERT_TRUE(std::ranges::all_of(
            generatedSample, [](char sampleCharacter)
            { return static_cast<int>(sampleCharacter) >= 33 && static_cast<int>(sampleCharacter) <= 125; }));

        auto count_semicolon = std::ranges::count(generatedSample, ';');
        auto count_comma = std::ranges::count(generatedSample, ',');
        auto count_a = std::ranges::count(generatedSample, 'a');

        ASSERT_TRUE(count_semicolon >= 1 && count_semicolon <= 3);
        ASSERT_TRUE(count_comma >= 3 && count_comma <= 4);
        ASSERT_TRUE(count_a >= 2 && count_a <= 10);
    }
}

TEST_F(StringTest, shouldGenerateSampleStringWithGuarantee2)
{
    const auto sampleLength{20};
    const GuaranteeMap guarantee = {{'4', {0, 1}}, {'5', {0, 2}}, {'a', {0, 3}}, {'@', {2, 2}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedSample = sample(std::move(copyGuarantee), sampleLength);

        ASSERT_EQ(generatedSample.size(), sampleLength);
        ASSERT_TRUE(std::ranges::all_of(
            generatedSample, [](char sampleCharacter)
            { return static_cast<int>(sampleCharacter) >= 33 && static_cast<int>(sampleCharacter) <= 125; }));

        auto count_4 = std::ranges::count(generatedSample, '4');
        auto count_5 = std::ranges::count(generatedSample, '5');
        auto count_a = std::ranges::count(generatedSample, 'a');
        auto count_at = std::ranges::count(generatedSample, '@');

        ASSERT_TRUE(count_4 <= 1);
        ASSERT_TRUE(count_5 <= 2);
        ASSERT_TRUE(count_a <= 3);
        ASSERT_TRUE(count_at == 2);
    }
}

TEST_F(StringTest, shouldGenerateSampleStringWithGuarantee3)
{
    const auto sampleLength{20};
    const GuaranteeMap guarantee = {{'(', {0, 4}}, {'{', {0, 2}}, {'\\', {0, 1}}, {'/', {0, 5}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedSample = sample(std::move(copyGuarantee), sampleLength);

        ASSERT_EQ(generatedSample.size(), sampleLength);
        ASSERT_TRUE(std::ranges::all_of(
            generatedSample, [](char sampleCharacter)
            { return static_cast<int>(sampleCharacter) >= 33 && static_cast<int>(sampleCharacter) <= 125; }));

        auto count_leftBracket = std::ranges::count(generatedSample, '(');
        auto count_leftBrace = std::ranges::count(generatedSample, '{');
        auto count_backSlash = std::ranges::count(generatedSample, '\\');
        auto count_forwardSlash = std::ranges::count(generatedSample, '/');

        ASSERT_TRUE(count_leftBracket <= 4);
        ASSERT_TRUE(count_leftBrace <= 2);
        ASSERT_TRUE(count_backSlash <= 1);
        ASSERT_TRUE(count_forwardSlash <= 5);
    }
}

TEST_F(StringTest, invalidGuaranteeForSample1)
{
    const auto sampleLength{20};
    GuaranteeMap guarantee = {{'3', {5, 6}}, {':', {6}}, {'A', {10}}};
    ASSERT_THROW(sample(std::move(guarantee), sampleLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForSample2)
{
    const auto sampleLength{20};
    GuaranteeMap guarantee = {{'a', {3}}, {'A', {10}}, {'~', {2, 2}}};
    ASSERT_THROW(sample(std::move(guarantee), sampleLength), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateDefaultStringFromCharaters)
{
    const std::string characters{"abc"};

    const auto generatedFromCharacters = fromCharacters(characters);

    ASSERT_EQ(generatedFromCharacters.size(), 1);
    ASSERT_TRUE(std::ranges::all_of(generatedFromCharacters, [&characters](char sampleCharacter)
                                    { return characters.find(sampleCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateStringFromCharaters)
{
    const std::string characters{"iosjdaijqw"};

    const auto generatedFromCharacters = fromCharacters(characters, 6);

    ASSERT_EQ(generatedFromCharacters.size(), 6);
    ASSERT_TRUE(std::ranges::all_of(generatedFromCharacters, [&characters](char sampleCharacter)
                                    { return characters.find(sampleCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateStringFromCharatersWithGuarantee1)
{
    const std::string characters{"iosjdaijqw"};
    const GuaranteeMap guarantee{{'s', {1, 1}}, {'w', {2}}, {'a', {0, 1}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedFromCharacters = fromCharacters(std::move(copyGuarantee), characters, 6);

        ASSERT_EQ(generatedFromCharacters.size(), 6);
        ASSERT_TRUE(std::ranges::all_of(generatedFromCharacters, [&characters](char sampleCharacter)
                                        { return characters.find(sampleCharacter) != std::string::npos; }));

        auto count_s = std::ranges::count(generatedFromCharacters, 's');
        auto count_w = std::ranges::count(generatedFromCharacters, 'w');
        auto count_a = std::ranges::count(generatedFromCharacters, 'a');

        ASSERT_TRUE(count_s == 1);
        ASSERT_TRUE(count_w >= 2);
        ASSERT_TRUE(count_a <= 1);
    }
}

TEST_F(StringTest, shouldGenerateStringFromCharatersWithGuarantee2)
{
    const auto fromCharactersLength = 20;
    const std::string characters{"_abcd6=89#"};
    const GuaranteeMap guarantee{{'_', {3}}, {'#', {5, 5}}, {'8', {0, 1}}, {'=', {0, 2}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedFromCharacters = fromCharacters(std::move(copyGuarantee), characters, fromCharactersLength);

        ASSERT_EQ(generatedFromCharacters.size(), fromCharactersLength);
        ASSERT_TRUE(std::ranges::all_of(generatedFromCharacters, [&characters](char sampleCharacter)
                                        { return characters.find(sampleCharacter) != std::string::npos; }));

        auto count_underscore = std::ranges::count(generatedFromCharacters, '_');
        auto count_hash = std::ranges::count(generatedFromCharacters, '#');
        auto count_8 = std::ranges::count(generatedFromCharacters, '8');
        auto count_equal = std::ranges::count(generatedFromCharacters, '=');

        ASSERT_TRUE(count_underscore >= 3);
        ASSERT_TRUE(count_hash == 5);
        ASSERT_TRUE(count_8 <= 1);
        ASSERT_TRUE(count_equal <= 2);
    }
}

TEST_F(StringTest, shouldGenerateStringFromCharatersWithGuarantee3)
{
    const auto fromCharactersLength = 20;
    const std::string characters{"!@#$%^&*()_+-=BA"};
    const GuaranteeMap guarantee{{'B', {10, 10}}, {'*', {1, 1}}, {'-', {0, 2}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedFromCharacters = fromCharacters(std::move(copyGuarantee), characters, fromCharactersLength);

        ASSERT_EQ(generatedFromCharacters.size(), fromCharactersLength);
        ASSERT_TRUE(std::ranges::all_of(generatedFromCharacters, [&characters](char sampleCharacter)
                                        { return characters.find(sampleCharacter) != std::string::npos; }));

        auto count_B = std::ranges::count(generatedFromCharacters, 'B');
        auto count_asterisk = std::ranges::count(generatedFromCharacters, '*');
        auto count_minus = std::ranges::count(generatedFromCharacters, '-');

        ASSERT_TRUE(count_B == 10);
        ASSERT_TRUE(count_asterisk == 1);
        ASSERT_TRUE(count_minus <= 2);
    }
}

TEST_F(StringTest, invalidGuaranteeForFromCharacters1)
{
    const auto fromCharactersLength = 20;
    const std::string characters{"bnmv*&"};
    GuaranteeMap guarantee{{'&', {10}}, {'*', {5}}, {'m', {5}}, {'b', {1, 10}}};
    ASSERT_THROW(fromCharacters(std::move(guarantee), characters, fromCharactersLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForFromCharacters2)
{
    const auto fromCharactersLength = 20;
    const std::string characters{"ab1"};
    GuaranteeMap guarantee{{'a', {0, 3}}, {'b', {0, 5}}, {'1', {6, 8}}};
    ASSERT_THROW(fromCharacters(std::move(guarantee), characters, fromCharactersLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForFromCharacters3)
{
    const auto fromCharactersLength = 20;
    const std::string characters{"67bnmM"};
    GuaranteeMap guarantee{{'1', {2, 2}}, {'M', {2, 2}}, {'m', {2, 2}}};
    ASSERT_THROW(fromCharacters(std::move(guarantee), characters, fromCharactersLength), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateDefaultApha)
{
    const auto generatedAlpha = alpha();

    ASSERT_EQ(generatedAlpha.size(), 1);
    ASSERT_TRUE(std::ranges::any_of(mixedAlphaCharacters, [generatedAlpha](char mixedCharacter)
                                    { return generatedAlpha[0] == mixedCharacter; }));
}

TEST_F(StringTest, shouldGenerateMixedAlpha)
{
    const auto alphaLength = 10;

    const auto generatedAlpha = alpha(alphaLength);

    ASSERT_EQ(generatedAlpha.size(), alphaLength);
    ASSERT_TRUE(std::ranges::all_of(generatedAlpha,
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

    const auto generatedAlpha = alpha(alphaLength, StringCasing::Upper);

    ASSERT_EQ(generatedAlpha.size(), alphaLength);
    ASSERT_TRUE(std::ranges::all_of(generatedAlpha,
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

    const auto generatedAlpha = alpha(alphaLength, StringCasing::Lower);

    ASSERT_EQ(generatedAlpha.size(), alphaLength);
    ASSERT_TRUE(std::ranges::all_of(generatedAlpha,
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
    const GuaranteeMap guarantee{{'A', {5, 20}}, {'B', {3, 20}}, {'a', {5, 5}}, {'z', {3, 6}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedAlpha = alpha(std::move(copyGuarantee), alphaLength);

        ASSERT_EQ(generatedAlpha.size(), alphaLength);
        ASSERT_TRUE(std::ranges::all_of(generatedAlpha,
                                        [](char alphaCharacter)
                                        {
                                            return std::ranges::any_of(mixedAlphaCharacters,
                                                                       [alphaCharacter](char mixedCharacter)
                                                                       { return mixedCharacter == alphaCharacter; });
                                        }));
        auto count_A = std::ranges::count(generatedAlpha, 'A');
        auto count_B = std::ranges::count(generatedAlpha, 'B');
        auto count_a = std::ranges::count(generatedAlpha, 'a');
        auto count_z = std::ranges::count(generatedAlpha, 'z');

        ASSERT_TRUE(count_A >= 5 && count_A <= 20);
        ASSERT_TRUE(count_B >= 3 && count_B <= 20);
        ASSERT_TRUE(count_a == 5);
        ASSERT_TRUE(count_z >= 3 && count_z <= 6);
    }
}

TEST_F(StringTest, shouldGenerateLowerAlphaWithGuarantee)
{
    const auto alphaLength = 20;
    const GuaranteeMap guarantee{{'k', {5, 20}}, {'o', {3, 20}}, {'a', {5, 5}}, {'z', {3, 6}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedAlpha = alpha(std::move(copyGuarantee), alphaLength, StringCasing::Lower);

        ASSERT_EQ(generatedAlpha.size(), alphaLength);
        ASSERT_TRUE(std::ranges::all_of(generatedAlpha,
                                        [](char alphaCharacter)
                                        {
                                            return std::ranges::any_of(lowerCharSet,
                                                                       [alphaCharacter](char lowerCharacter)
                                                                       { return lowerCharacter == alphaCharacter; });
                                        }));
        auto count_k = std::ranges::count(generatedAlpha, 'k');
        auto count_o = std::ranges::count(generatedAlpha, 'o');
        auto count_a = std::ranges::count(generatedAlpha, 'a');
        auto count_z = std::ranges::count(generatedAlpha, 'z');

        ASSERT_TRUE(count_k >= 5 && count_k <= 20);
        ASSERT_TRUE(count_o >= 3 && count_o <= 20);
        ASSERT_TRUE(count_a == 5);
        ASSERT_TRUE(count_z >= 3 && count_z <= 6);
    }
}

TEST_F(StringTest, shouldGenerateUpperAlphaWithGuarantee)
{
    const auto alphaLength = 20;
    const GuaranteeMap guarantee{{'K', {5, 20}}, {'O', {3, 20}}, {'A', {5, 5}}, {'Z', {3, 6}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedAlpha = alpha(std::move(copyGuarantee), alphaLength, StringCasing::Upper);

        ASSERT_EQ(generatedAlpha.size(), alphaLength);
        ASSERT_TRUE(std::ranges::all_of(generatedAlpha,
                                        [](char alphaCharacter)
                                        {
                                            return std::ranges::any_of(upperCharSet,
                                                                       [alphaCharacter](char lowerCharacter)
                                                                       { return lowerCharacter == alphaCharacter; });
                                        }));
        auto count_K = std::ranges::count(generatedAlpha, 'K');
        auto count_O = std::ranges::count(generatedAlpha, 'O');
        auto count_A = std::ranges::count(generatedAlpha, 'A');
        auto count_Z = std::ranges::count(generatedAlpha, 'Z');

        ASSERT_TRUE(count_K >= 5 && count_K <= 20);
        ASSERT_TRUE(count_O >= 3 && count_O <= 20);
        ASSERT_TRUE(count_A == 5);
        ASSERT_TRUE(count_Z >= 3 && count_Z <= 6);
    }
}

TEST_F(StringTest, invalidGuaranteeForAlpha1)
{
    const auto alphaLength = 20;
    GuaranteeMap guarantee = {{'A', {8, 10}}, {'B', {10, 15}}, {'Y', {1, 10}}, {'Z', {3, 3}}};
    ASSERT_THROW(alpha(std::move(guarantee), alphaLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlpha2)
{
    const auto alphaLength = 30;
    GuaranteeMap guarantee = {
        {'A', {0, 1}}, {'B', {0, 1}}, {'C', {0, 1}}, {'D', {0, 1}}, {'E', {0, 1}}, {'F', {0, 1}}, {'G', {0, 1}},
        {'H', {0, 1}}, {'I', {0, 1}}, {'J', {0, 1}}, {'K', {0, 1}}, {'L', {0, 1}}, {'M', {0, 1}}, {'N', {0, 1}},
        {'O', {0, 1}}, {'P', {0, 1}}, {'Q', {0, 1}}, {'R', {0, 1}}, {'S', {0, 1}}, {'T', {0, 1}}, {'U', {0, 1}},
        {'V', {0, 1}}, {'W', {0, 1}}, {'X', {0, 1}}, {'Y', {0, 1}}, {'Z', {0, 1}},
    };
    ASSERT_THROW(alpha(std::move(guarantee), alphaLength, StringCasing::Upper), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlpha3)
{
    const auto alphaLength = 20;
    GuaranteeMap guarantee = {{'a', {4, 10}}, {'B', {4, 10}}, {'5', {4, 6}}};
    ASSERT_THROW(alpha(std::move(guarantee), alphaLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlpha4)
{
    const auto alphaLength = 20;
    GuaranteeMap guarantee = {{'a', {4, 10}}, {'B', {4, 10}}};
    ASSERT_THROW(alpha(std::move(guarantee), alphaLength, StringCasing::Upper), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlpha5)
{
    const auto alphaLength = 20;
    GuaranteeMap guarantee = {{'a', {4, 10}}, {'B', {4, 10}}};
    ASSERT_THROW(alpha(std::move(guarantee), alphaLength, StringCasing::Lower), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateDefaultAphanumeric)
{
    const auto generatedAlphanumeric = alphanumeric();

    ASSERT_EQ(generatedAlphanumeric.size(), 1);
    ASSERT_TRUE(std::ranges::any_of(mixedAlphanumericCharacters, [generatedAlphanumeric](char mixedCharacter)
                                    { return generatedAlphanumeric[0] == mixedCharacter; }));
}

TEST_F(StringTest, shouldGenerateMixedAlphanumeric)
{
    const auto alphanumericLength = 10;

    const auto generatedAlphanumeric = alphanumeric(alphanumericLength);

    ASSERT_EQ(generatedAlphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(std::ranges::all_of(generatedAlphanumeric,
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

    const auto generatedAlphanumeric = alphanumeric(alphanumericLength, StringCasing::Upper);

    ASSERT_EQ(generatedAlphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(std::ranges::all_of(generatedAlphanumeric,
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

    const auto generatedAlphanumeric = alphanumeric(alphanumericLength, StringCasing::Lower);

    ASSERT_EQ(generatedAlphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(std::ranges::all_of(generatedAlphanumeric,
                                    [](char alphanumericCharacter)
                                    {
                                        return std::ranges::any_of(
                                            lowerAlphanumericCharacters,
                                            [alphanumericCharacter](char lowerAlphanumericCharacter)
                                            { return lowerAlphanumericCharacter == alphanumericCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateMixedAlphanumericWithGuarantee)
{
    const auto alphanumericLength = 20;
    const GuaranteeMap guarantee{{'1', {5, 20}}, {'B', {3, 20}}, {'a', {5, 5}}, {'z', {3, 6}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedAlphanumeric = alphanumeric(std::move(copyGuarantee), alphanumericLength);

        ASSERT_EQ(generatedAlphanumeric.size(), alphanumericLength);
        ASSERT_TRUE(std::ranges::all_of(
            generatedAlphanumeric,
            [](char alphanumericCharacter)
            {
                return std::ranges::any_of(mixedAlphanumericCharacters, [alphanumericCharacter](char mixedCharacter)
                                           { return mixedCharacter == alphanumericCharacter; });
            }));
        auto count_1 = std::ranges::count(generatedAlphanumeric, '1');
        auto count_B = std::ranges::count(generatedAlphanumeric, 'B');
        auto count_a = std::ranges::count(generatedAlphanumeric, 'a');
        auto count_z = std::ranges::count(generatedAlphanumeric, 'z');

        ASSERT_TRUE(count_1 >= 5 && count_1 <= 20);
        ASSERT_TRUE(count_B >= 3 && count_B <= 20);
        ASSERT_TRUE(count_a == 5);
        ASSERT_TRUE(count_z >= 3 && count_z <= 6);
    }
}

TEST_F(StringTest, shouldGenerateLowerAlphanumericWithGuarantee)
{
    const auto alphanumericLength = 20;
    const GuaranteeMap guarantee{{'k', {5, 20}}, {'o', {3, 20}}, {'a', {5, 5}}, {'0', {3, 6}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedAlphanumeric =
            alphanumeric(std::move(copyGuarantee), alphanumericLength, StringCasing::Lower);

        ASSERT_EQ(generatedAlphanumeric.size(), alphanumericLength);
        ASSERT_TRUE(std::ranges::all_of(
            generatedAlphanumeric,
            [](char alphanumericCharacter)
            {
                return std::ranges::any_of(lowerAlphanumericCharacters, [alphanumericCharacter](char lowerCharacter)
                                           { return lowerCharacter == alphanumericCharacter; });
            }));
        auto count_k = std::ranges::count(generatedAlphanumeric, 'k');
        auto count_o = std::ranges::count(generatedAlphanumeric, 'o');
        auto count_a = std::ranges::count(generatedAlphanumeric, 'a');
        auto count_0 = std::ranges::count(generatedAlphanumeric, '0');

        ASSERT_TRUE(count_k >= 5 && count_k <= 20);
        ASSERT_TRUE(count_o >= 3 && count_o <= 20);
        ASSERT_TRUE(count_a == 5);
        ASSERT_TRUE(count_0 >= 3 && count_0 <= 6);
    }
}

TEST_F(StringTest, shouldGenerateUpperAlphanumericWithGuarantee)
{
    const auto alphanumericLength = 20;
    const GuaranteeMap guarantee{{'7', {5, 20}}, {'O', {3, 20}}, {'A', {5, 5}}, {'Z', {3, 6}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedAlphanumeric =
            alphanumeric(std::move(copyGuarantee), alphanumericLength, StringCasing::Upper);

        ASSERT_EQ(generatedAlphanumeric.size(), alphanumericLength);
        ASSERT_TRUE(std::ranges::all_of(
            generatedAlphanumeric,
            [](char alphanumericCharacter)
            {
                return std::ranges::any_of(upperAlphanumericCharacters, [alphanumericCharacter](char lowerCharacter)
                                           { return lowerCharacter == alphanumericCharacter; });
            }));
        auto count_7 = std::ranges::count(generatedAlphanumeric, '7');
        auto count_O = std::ranges::count(generatedAlphanumeric, 'O');
        auto count_A = std::ranges::count(generatedAlphanumeric, 'A');
        auto count_Z = std::ranges::count(generatedAlphanumeric, 'Z');

        ASSERT_TRUE(count_7 >= 5 && count_7 <= 20);
        ASSERT_TRUE(count_O >= 3 && count_O <= 20);
        ASSERT_TRUE(count_A == 5);
        ASSERT_TRUE(count_Z >= 3 && count_Z <= 6);
    }
}

TEST_F(StringTest, invalidGuaranteeForAlphanumeric1)
{
    const auto alphanumericLength = 20;
    GuaranteeMap guarantee = {{'A', {8, 10}}, {'b', {10, 15}}, {'Y', {1, 10}}, {'8', {3, 3}}};
    ASSERT_THROW(alphanumeric(std::move(guarantee), alphanumericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlphanumeric2)
{
    const auto alphanumericLength = 40;
    GuaranteeMap guarantee = {
        {'A', {0, 1}}, {'B', {0, 1}}, {'C', {0, 1}}, {'D', {0, 1}}, {'E', {0, 1}}, {'F', {0, 1}},
        {'G', {0, 1}}, {'H', {0, 1}}, {'I', {0, 1}}, {'J', {0, 1}}, {'K', {0, 1}}, {'L', {0, 1}},
        {'M', {0, 1}}, {'N', {0, 1}}, {'O', {0, 1}}, {'P', {0, 1}}, {'Q', {0, 1}}, {'R', {0, 1}},
        {'S', {0, 1}}, {'T', {0, 1}}, {'U', {0, 1}}, {'V', {0, 1}}, {'W', {0, 1}}, {'X', {0, 1}},
        {'Y', {0, 1}}, {'Z', {0, 1}}, {'0', {0, 1}}, {'1', {0, 1}}, {'2', {0, 1}}, {'3', {0, 1}},
        {'4', {0, 1}}, {'5', {0, 1}}, {'6', {0, 1}}, {'7', {0, 1}}, {'8', {0, 1}}, {'9', {0, 1}},
    };
    ASSERT_THROW(alphanumeric(std::move(guarantee), alphanumericLength, StringCasing::Upper), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlphanumeric3)
{
    const auto alphanumericLength = 20;
    GuaranteeMap guarantee = {{'a', {4, 10}}, {'B', {4, 10}}, {'5', {4, 6}}, {'#', {4}}};
    ASSERT_THROW(alphanumeric(std::move(guarantee), alphanumericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlphanumeric4)
{
    const auto alphanumericLength = 20;
    GuaranteeMap guarantee = {{'a', {4, 10}}, {'B', {4, 10}}, {'2', {1}}};
    ASSERT_THROW(alphanumeric(std::move(guarantee), alphanumericLength, StringCasing::Upper), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlphanumeric5)
{
    const auto alphanumericLength = 20;
    GuaranteeMap guarantee = {{'a', {4, 10}}, {'B', {4, 10}}, {'8', {8, 10}}};
    ASSERT_THROW(alphanumeric(std::move(guarantee), alphanumericLength, StringCasing::Lower), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateNumeric)
{
    const auto generatedNumeric = numeric();

    ASSERT_EQ(generatedNumeric.size(), 1);
    ASSERT_TRUE(std::ranges::any_of(generatedNumeric, [generatedNumeric](char numericCharacter)
                                    { return generatedNumeric[0] == numericCharacter; }));
}

TEST_F(StringTest, shouldGenerateNumericWithoutLeadingZeros)
{
    const auto numericLength = 13;

    const auto generatedNumeric = numeric(numericLength, false);

    const auto nonZeroCharacter = generatedNumeric[0];
    const auto numericWithPossibleZeroCharacters = generatedNumeric.substr(1);

    ASSERT_EQ(generatedNumeric.size(), numericLength);
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
    const GuaranteeMap guarantee = {{'0', {10, 15}}, {'9', {5, 10}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedNumeric = numeric(std::move(copyGuarantee), numericLength);

        ASSERT_EQ(generatedNumeric.size(), numericLength);
        ASSERT_TRUE(std::ranges::any_of(generatedNumeric, [generatedNumeric](char numericCharacter)
                                        { return generatedNumeric[0] == numericCharacter; }));

        auto count_0 = std::ranges::count(generatedNumeric, '0');
        auto count_9 = std::ranges::count(generatedNumeric, '9');

        ASSERT_TRUE(count_0 >= 10 && count_0 <= 15);
        ASSERT_TRUE(count_9 >= 5 && count_9 <= 10);
    }
}

TEST_F(StringTest, shouldGenerateNumericWithGuarantee2)
{
    const auto numericLength = 20;
    const GuaranteeMap guarantee = {{'1', {0, 0}}, {'2', {5, 20}}, {'8', {0, 1}}, {'9', {5, 5}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedNumeric = numeric(std::move(copyGuarantee), numericLength);

        ASSERT_EQ(generatedNumeric.size(), numericLength);
        ASSERT_TRUE(std::ranges::any_of(generatedNumeric, [generatedNumeric](char numericCharacter)
                                        { return generatedNumeric[0] == numericCharacter; }));

        auto count_1 = std::ranges::count(generatedNumeric, '1');
        auto count_2 = std::ranges::count(generatedNumeric, '2');
        auto count_8 = std::ranges::count(generatedNumeric, '8');
        auto count_9 = std::ranges::count(generatedNumeric, '9');

        ASSERT_TRUE(count_1 == 0);
        ASSERT_TRUE(count_2 >= 5 && count_2 <= 20);
        ASSERT_TRUE(count_8 <= 1);
        ASSERT_TRUE(count_9 == 5);
    }
}

TEST_F(StringTest, shouldGenerateNumericWithoutLeadingZerosWithGuarantee1)
{
    const auto numericLength = 20;
    const GuaranteeMap guarantee = {{'0', {19}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedNumeric = numeric(std::move(copyGuarantee), numericLength, false);

        const auto nonZeroCharacter = generatedNumeric[0];
        const auto numericWithPossibleZeroCharacters = generatedNumeric.substr(1);

        ASSERT_EQ(generatedNumeric.size(), numericLength);
        ASSERT_TRUE(std::ranges::any_of(numericCharactersWithoutZero, [nonZeroCharacter](char numericCharacter)
                                        { return nonZeroCharacter == numericCharacter; }));
        ASSERT_TRUE(std::ranges::all_of(
            numericWithPossibleZeroCharacters,
            [](char numericCharacterWithPossibleZero)
            {
                return std::ranges::any_of(numericCharacters, [numericCharacterWithPossibleZero](char numericCharacter)
                                           { return numericCharacterWithPossibleZero == numericCharacter; });
            }));
        auto count_0 = std::ranges::count(generatedNumeric, '0');

        ASSERT_TRUE(count_0 >= 19);
    }
}

TEST_F(StringTest, shouldGenerateNumericWithoutLeadingZerosWithGuarantee2)
{
    const auto numericLength = 20;
    const GuaranteeMap guarantee = {{'0', {10}}, {'1', {3, 4}}, {'3', {2, 4}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedNumeric = numeric(std::move(copyGuarantee), numericLength, false);

        const auto nonZeroCharacter = generatedNumeric[0];
        const auto numericWithPossibleZeroCharacters = generatedNumeric.substr(1);

        ASSERT_EQ(generatedNumeric.size(), numericLength);
        ASSERT_TRUE(std::ranges::any_of(numericCharactersWithoutZero, [nonZeroCharacter](char numericCharacter)
                                        { return nonZeroCharacter == numericCharacter; }));
        ASSERT_TRUE(std::ranges::all_of(
            numericWithPossibleZeroCharacters,
            [](char numericCharacterWithPossibleZero)
            {
                return std::ranges::any_of(numericCharacters, [numericCharacterWithPossibleZero](char numericCharacter)
                                           { return numericCharacterWithPossibleZero == numericCharacter; });
            }));
        auto count_0 = std::ranges::count(generatedNumeric, '0');
        auto count_1 = std::ranges::count(generatedNumeric, '1');
        auto count_3 = std::ranges::count(generatedNumeric, '3');

        ASSERT_TRUE(count_0 >= 10);
        ASSERT_TRUE(count_1 >= 3 && count_1 <= 4);
        ASSERT_TRUE(count_3 >= 2 && count_3 <= 4);
    }
}

TEST_F(StringTest, invalidGuaranteeForNumeric1)
{
    const auto numericLength = 20;
    GuaranteeMap guarantee = {{'0', {10}}, {'1', {3, 4}}, {'3', {8, 10}}};
    ASSERT_THROW(numeric(std::move(guarantee), numericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForNumeric2)
{
    const auto numericLength = 20;
    GuaranteeMap guarantee = {
        {'1', {0, 1}}, {'2', {0, 1}}, {'3', {0, 1}}, {'4', {0, 1}}, {'5', {0, 1}},
        {'6', {0, 1}}, {'7', {0, 1}}, {'8', {0, 1}}, {'9', {0, 1}}, {'0', {0, 1}},
    };
    ASSERT_THROW(numeric(std::move(guarantee), numericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForNumeric3)
{
    const auto numericLength = 20;
    GuaranteeMap guarantee = {{'0', {10}}, {'1', {3, 4}}, {'3', {2, 4}}, {'a', {5, 5}}};
    ASSERT_THROW(numeric(std::move(guarantee), numericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForNumeric4)
{
    const auto numericLength = 5;
    GuaranteeMap guarantee = {{'0', {5}}};
    ASSERT_THROW(numeric(std::move(guarantee), numericLength, false), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateHexadecimal)
{
    const auto hexadecimalLength = 8;

    const auto generatedHexadecimal = hexadecimal(hexadecimalLength);

    const auto prefix = generatedHexadecimal.substr(0, 2);
    const auto hexNumber = generatedHexadecimal.substr(2);

    ASSERT_EQ(generatedHexadecimal.size(), hexadecimalLength + 2);
    ASSERT_EQ(prefix, "0x");
    ASSERT_TRUE(std::ranges::any_of(hexNumber, [hexNumber](char hexNumberCharacter)
                                    { return hexLowerCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateHexadecimalWithHashPrefix)
{
    const auto hexadecimalLength = 8;

    const auto generatedHexadecimal = hexadecimal(hexadecimalLength, HexCasing::Upper, HexPrefix::Hash);

    const auto prefix = generatedHexadecimal.substr(0, 1);
    const auto hexNumber = generatedHexadecimal.substr(1);

    ASSERT_EQ(generatedHexadecimal.size(), hexadecimalLength + 1);
    ASSERT_EQ(prefix, "#");
    ASSERT_TRUE(std::ranges::any_of(hexNumber, [](char hexNumberCharacter)
                                    { return hexUpperCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateHexadecimalWithoutPrefix)
{
    const auto hexadecimalLength = 8;

    const auto generatedHexadecimal = hexadecimal(hexadecimalLength, HexCasing::Upper, HexPrefix::None);

    ASSERT_EQ(generatedHexadecimal.size(), hexadecimalLength);
    ASSERT_TRUE(std::ranges::any_of(generatedHexadecimal, [](char hexNumberCharacter)
                                    { return hexUpperCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateHexadecimalWithGuarantee1)
{
    const auto hexadecimalLength = 20;
    GuaranteeMap guarantee{{'a', {4, 4}}, {'f', {3, 10}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedHexadecimal = hexadecimal(std::move(copyGuarantee), hexadecimalLength);
        const auto prefix = generatedHexadecimal.substr(0, 2);
        const auto hexNumber = generatedHexadecimal.substr(2);

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
    GuaranteeMap guarantee{{'A', {0, 0}}, {'F', {10, 10}}, {'0', {5}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedHexadecimal = hexadecimal(std::move(copyGuarantee), hexadecimalLength, HexCasing::Upper);
        const auto prefix = generatedHexadecimal.substr(0, 2);
        const auto hexNumber = generatedHexadecimal.substr(2);

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
    GuaranteeMap guarantee{
        {'0', {0, 0}}, {'1', {0, 0}}, {'2', {0, 0}}, {'3', {0, 0}},
        {'4', {0, 0}}, {'5', {0, 0}}, {'6', {0, 0}}, {'7', {0, 0}},
    };
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedHexadecimal = hexadecimal(std::move(copyGuarantee), hexadecimalLength, HexCasing::Upper);
        const auto prefix = generatedHexadecimal.substr(0, 2);
        const auto hexNumber = generatedHexadecimal.substr(2);

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
    GuaranteeMap guarantee{{'A', {0, 0}}, {'F', {10, 10}}, {'G', {5}}};
    ASSERT_THROW(hexadecimal(std::move(guarantee), hexadecimalLength, HexCasing::Upper), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal2)
{
    const auto hexadecimalLength = 20;
    GuaranteeMap guarantee{{'a', {0, 0}}, {'F', {10, 10}}, {'1', {5}}};
    ASSERT_THROW(hexadecimal(std::move(guarantee), hexadecimalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal3)
{
    const auto hexadecimalLength = 20;
    GuaranteeMap guarantee{{'a', {0, 0}}, {'F', {10, 10}}, {'1', {5}}};
    ASSERT_THROW(hexadecimal(std::move(guarantee), hexadecimalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal4)
{
    const auto hexadecimalLength = 10;
    GuaranteeMap guarantee{{'a', {5}}, {'b', {8, 10}}, {'1', {0, 3}}};
    ASSERT_THROW(hexadecimal(std::move(guarantee), hexadecimalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal5)
{
    const auto hexadecimalLength = 20;
    GuaranteeMap guarantee{
        {'0', {0, 1}}, {'1', {0, 1}}, {'2', {0, 1}}, {'3', {0, 1}}, {'4', {0, 1}}, {'5', {0, 1}},
        {'6', {0, 1}}, {'7', {0, 1}}, {'8', {0, 1}}, {'9', {0, 1}}, {'a', {0, 1}}, {'b', {0, 1}},
        {'c', {0, 1}}, {'d', {0, 1}}, {'e', {0, 1}}, {'f', {0, 1}},
    };
    ASSERT_THROW(hexadecimal(std::move(guarantee), hexadecimalLength), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateHexNumber)
{
    auto result = hexadecimal(100, 255);
    ASSERT_EQ(result.size(), 2);
    ASSERT_TRUE(std::isxdigit(result[0]));
    ASSERT_TRUE(std::isxdigit(result[1]));

    result = hexadecimal(10, 15);
    ASSERT_EQ(result.size(), 1);
    ASSERT_TRUE(std::isxdigit(result[0]));

    result = hexadecimal(30, 40);
    ASSERT_EQ(result.size(), 2);
    ASSERT_TRUE(std::isxdigit(result[0]));
    ASSERT_TRUE(std::isxdigit(result[1]));
}


TEST_F(StringTest, shouldGenerateOctalWithPrefix)
{
    const auto octalLength = 8;

    const auto generatedOctal = octal(octalLength);

    const auto prefix = generatedOctal.substr(0, 2);
    const auto octalNumber = generatedOctal.substr(2);

    ASSERT_EQ(generatedOctal.size(), octalLength + 2);
    ASSERT_EQ(prefix, "0o");
    ASSERT_TRUE(
        std::ranges::any_of(generatedOctal, [](char octalNumberCharacter)
                            { return std::string("01234567").find(octalNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateOctalWithGuarantee1)
{
    const auto octalLength = 10;
    GuaranteeMap guarantee{{'0', {2}}, {'3', {2, 2}}, {'5', {0, 0}}, {'6', {3, 10}}, {'7', {1, 10}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedOctal = octal(std::move(copyGuarantee), octalLength);

        const auto prefix = generatedOctal.substr(0, 2);
        const auto octalNumber = generatedOctal.substr(2);

        ASSERT_EQ(octalNumber.size(), octalLength);
        ASSERT_EQ(prefix, "0o");
        ASSERT_TRUE(
            std::ranges::any_of(generatedOctal, [](char octalNumberCharacter)
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
    GuaranteeMap guarantee{{'0', {18}},   {'2', {0, 0}}, {'3', {0, 0}}, {'4', {0, 0}},
                           {'5', {0, 0}}, {'6', {0, 0}}, {'7', {0, 0}}};
    for (int i = 0; i < runCount; ++i)
    {
        auto copyGuarantee = guarantee;
        const auto generatedOctal = octal(std::move(copyGuarantee), octalLength);

        const auto prefix = generatedOctal.substr(0, 2);
        const auto octalNumber = generatedOctal.substr(2);

        ASSERT_EQ(octalNumber.size(), octalLength);
        ASSERT_EQ(prefix, "0o");
        ASSERT_TRUE(
            std::ranges::any_of(generatedOctal, [](char octalNumberCharacter)
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
    GuaranteeMap guarantee{{'0', {8}}, {'2', {9}}, {'3', {9}}, {'4', {0, 0}}};
    ASSERT_THROW(octal(std::move(guarantee), octalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForOctal2)
{
    const auto octalLength = 20;
    GuaranteeMap guarantee{{'0', {0, 2}}, {'1', {0, 2}}, {'2', {0, 2}}, {'3', {0, 2}},
                           {'4', {0, 2}}, {'5', {0, 2}}, {'6', {0, 2}}, {'7', {0, 2}}};
    ASSERT_THROW(octal(std::move(guarantee), octalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForOctal3)
{
    const auto octalLength = 20;

    GuaranteeMap guarantee{{'0', {0, 2}}, {'1', {0, 2}}, {'8', {2, 3}}, {'2', {0, 2}}, {'3', {0, 2}}};
    ASSERT_THROW(octal(std::move(guarantee), octalLength), std::invalid_argument);
}
