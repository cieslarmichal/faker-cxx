#include "../test_helpers.h"
#include <algorithm>
#include <faker/string.h>
#include <modules/string_data.h>
#include <random>
#include <stdexcept>
#include <unordered_set>
#include <vector>

using namespace ::testing;
using namespace faker;

namespace {

const std::unordered_set<char> lowerCharSet {
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z',
};
const std::unordered_set<char> upperCharSet {
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z',
};

}

class StringTest : public Test {
public:
    const int runCount { 100 };
};

TEST_F(StringTest, shouldUseCustomRandomGeneratorForUuid4)
{
    const auto uuid1 = string::uuid();

    ASSERT_EQ(uuid1[8], '-');
    ASSERT_EQ(uuid1[13], '-');
    ASSERT_EQ(uuid1[14], '4');
    ASSERT_EQ(uuid1[18], '-');
    ASSERT_EQ(uuid1[23], '-');
}

TEST_F(StringTest, shouldGenerateUuid4)
{
    const auto uuid = string::uuid();

    ASSERT_EQ(uuid[8], '-');
    ASSERT_EQ(uuid[13], '-');
    ASSERT_EQ(uuid[14], '4');
    ASSERT_EQ(uuid[18], '-');
    ASSERT_EQ(uuid[23], '-');
}

TEST_F(StringTest, shouldGenerateDefaultSampleString)
{
    const auto sample = string::sample();

    ASSERT_EQ(sample.size(), 10);
    ASSERT_TRUE(faker::testing::all_of(sample, [](char sampleCharacter) {
        return static_cast<int>(sampleCharacter) >= 33 && static_cast<int>(sampleCharacter) <= 125;
    }));
}

TEST_F(StringTest, shouldGenerateSampleString)
{
    const auto sample = string::sample(5);

    ASSERT_EQ(sample.size(), 5);
    ASSERT_TRUE(faker::testing::all_of(sample, [](char sampleCharacter) {
        return static_cast<int>(sampleCharacter) >= 33 && static_cast<int>(sampleCharacter) <= 125;
    }));
}

TEST_F(StringTest, shouldGenerateSampleStringWithGuarantee1)
{
    const auto sampleLength { 20 };

    // atleast 1 ';' - 3 ',' - 2 'a'
    // atmost 3 ';' - 4 ',' - 10 'a'
    const std::vector<string::Spec> guarantee { { ';', 1, 3 }, { ',', 3, 4 }, { 'a', 2, 10 } };

    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto sample = string::sample((copyGuarantee), sampleLength);

        ASSERT_EQ(sample.size(), sampleLength);
        ASSERT_TRUE(faker::testing::all_of(sample, [](char sampleCharacter) {
            return static_cast<int>(sampleCharacter) >= 33
                && static_cast<int>(sampleCharacter) <= 125;
        }));

        auto count_semicolon = faker::testing::count(sample, ';');
        auto count_comma = faker::testing::count(sample, ',');
        auto count_a = faker::testing::count(sample, 'a');

        ASSERT_TRUE(count_semicolon >= 1 && count_semicolon <= 3);
        ASSERT_TRUE(count_comma >= 3 && count_comma <= 4);
        ASSERT_TRUE(count_a >= 2 && count_a <= 10);
    }
}

TEST_F(StringTest, shouldGenerateSampleStringWithGuarantee2)
{
    const auto sampleLength { 20 };
    // exactly 2 '@'
    // atmost 1 '4' - 2 '5' - 3 'a'
    const std::vector<string::Spec> guarantee { { '4', 0, 1 }, { '5', 0, 2 }, { 'a', 0, 3 },
        { '@', 2, 2 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        const auto sample = string::sample(guarantee, sampleLength);

        ASSERT_EQ(sample.size(), sampleLength);
        ASSERT_TRUE(faker::testing::all_of(sample, [](char sampleCharacter) {
            return static_cast<int>(sampleCharacter) >= 33
                && static_cast<int>(sampleCharacter) <= 125;
        }));

        auto count_4 = faker::testing::count(sample, '4');
        auto count_5 = faker::testing::count(sample, '5');
        auto count_a = faker::testing::count(sample, 'a');
        auto count_at = faker::testing::count(sample, '@');

        ASSERT_TRUE(count_4 <= 1);
        ASSERT_TRUE(count_5 <= 2);
        ASSERT_TRUE(count_a <= 3);
        ASSERT_TRUE(count_at == 2);
    }
}

TEST_F(StringTest, shouldGenerateSampleStringWithGuarantee3)
{
    const auto sampleLength { 20 };
    // atmost 4 '(' - 2 '{' - 1 '\' - 5 '/'
    const std::vector<string::Spec> guarantee { { '(', 0, 4 }, { '{', 0, 2 }, { '\\', 0, 1 },
        { '/', 0, 5 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto sample = string::sample(copyGuarantee, sampleLength);

        ASSERT_EQ(sample.size(), sampleLength);
        ASSERT_TRUE(faker::testing::all_of(sample, [](char sampleCharacter) {
            return static_cast<int>(sampleCharacter) >= 33
                && static_cast<int>(sampleCharacter) <= 125;
        }));

        auto count_leftBracket = faker::testing::count(sample, '(');
        auto count_leftBrace = faker::testing::count(sample, '{');
        auto count_backSlash = faker::testing::count(sample, '\\');
        auto count_forwardSlash = faker::testing::count(sample, '/');

        ASSERT_TRUE(count_leftBracket <= 4);
        ASSERT_TRUE(count_leftBrace <= 2);
        ASSERT_TRUE(count_backSlash <= 1);
        ASSERT_TRUE(count_forwardSlash <= 5);
    }
}

TEST_F(StringTest, invalidGuaranteeForSample1)
{
    const auto sampleLength { 20 };
    // atleast 5 '3' - 6 ':' - 10 'A' // invalid // string will be atleast 21 which is wrong
    // atmost 6 '3'
    const std::vector<string::Spec> guarantee = { { '3', 5, 6 }, { ':', 6, 0 }, { 'A', 10, 0 } };
    ASSERT_THROW(string::sample(guarantee, sampleLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForSample2)
{
    const auto sampleLength { 20 };
    // exactly 2 '~' // invalid // not in char set
    const std::vector<string::Spec> guarantee = { { 'a', 3 }, { 'A', 10 }, { '~', 2, 2 } };
    ASSERT_THROW(string::sample(guarantee, sampleLength), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateDefaultStringFromCharaters)
{
    const std::string characters { "abc" };

    const auto fromCharacters = string::from_chars(characters);

    ASSERT_EQ(fromCharacters.size(), 1);
    ASSERT_TRUE(faker::testing::all_of(fromCharacters, [&characters](char sampleCharacter) {
        return characters.find(sampleCharacter) != std::string::npos;
    }));
}

TEST_F(StringTest, shouldGenerateStringFromCharaters)
{
    const std::string characters { "iosjdaijqw" };

    const auto fromCharacters = string::from_chars(characters, 6);

    ASSERT_EQ(fromCharacters.size(), 6);
    ASSERT_TRUE(faker::testing::all_of(fromCharacters, [&characters](char sampleCharacter) {
        return characters.find(sampleCharacter) != std::string::npos;
    }));
}

TEST_F(StringTest, shouldGenerateStringFromCharatersWithGuarantee1)
{
    const std::string characters { "iosjdaijqw" };
    // exactly 1 's'
    // atleast 2 'w'
    // atmost 1 'a'
    const std::vector<string::Spec> guarantee { { 's', 1, 1 }, { 'w', 2 }, { 'a', 0, 1 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        const auto fromCharacters = string::from_chars(guarantee, characters, 6);

        ASSERT_EQ(fromCharacters.size(), 6);
        ASSERT_TRUE(faker::testing::all_of(fromCharacters, [&characters](char sampleCharacter) {
            return characters.find(sampleCharacter) != std::string::npos;
        }));

        auto count_s = faker::testing::count(fromCharacters, 's');
        auto count_w = faker::testing::count(fromCharacters, 'w');
        auto count_a = faker::testing::count(fromCharacters, 'a');

        ASSERT_TRUE(count_s == 1);
        ASSERT_TRUE(count_w >= 2);
        ASSERT_TRUE(count_a <= 1);
    }
}

TEST_F(StringTest, shouldGenerateStringFromCharatersWithGuarantee2)
{
    const auto fromCharactersLength = 20;
    const std::string characters { "_abcd6=89#" };
    // exactly 5 '#'
    // atleast 3 '_' -
    // atmost 1 '8' - 2 '='
    const std::vector<string::Spec> guarantee { { '_', 3 }, { '#', 5, 5 }, { '8', 0, 1 },
        { '=', 0, 2 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto fromCharacters
            = string::from_chars((copyGuarantee), characters, fromCharactersLength);

        ASSERT_EQ(fromCharacters.size(), fromCharactersLength);
        ASSERT_TRUE(faker::testing::all_of(fromCharacters, [&characters](char sampleCharacter) {
            return characters.find(sampleCharacter) != std::string::npos;
        }));

        auto count_underscore = faker::testing::count(fromCharacters, '_');
        auto count_hash = faker::testing::count(fromCharacters, '#');
        auto count_8 = faker::testing::count(fromCharacters, '8');
        auto count_equal = faker::testing::count(fromCharacters, '=');

        ASSERT_TRUE(count_underscore >= 3);
        ASSERT_TRUE(count_hash == 5);
        ASSERT_TRUE(count_8 <= 1);
        ASSERT_TRUE(count_equal <= 2);
    }
}

TEST_F(StringTest, shouldGenerateStringFromCharatersWithGuarantee3)
{
    const auto fromCharactersLength = 20;
    const std::string characters { "!@#$%^&*()_+-=BA" };
    // exactly 10 'B' 1 '*'
    // atmost 2 '-'
    const std::vector<string::Spec> guarantee { { 'B', 10, 10 }, { '*', 1, 1 }, { '-', 0, 2 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto fromCharacters
            = string::from_chars((copyGuarantee), characters, fromCharactersLength);

        ASSERT_EQ(fromCharacters.size(), fromCharactersLength);
        ASSERT_TRUE(faker::testing::all_of(fromCharacters, [&characters](char sampleCharacter) {
            return characters.find(sampleCharacter) != std::string::npos;
        }));

        auto count_B = faker::testing::count(fromCharacters, 'B');
        auto count_asterisk = faker::testing::count(fromCharacters, '*');
        auto count_minus = faker::testing::count(fromCharacters, '-');

        ASSERT_TRUE(count_B == 10);
        ASSERT_TRUE(count_asterisk == 1);
        ASSERT_TRUE(count_minus <= 2);
    }
}

TEST_F(StringTest, invalidGuaranteeForFromCharacters1)
{
    const auto fromCharactersLength = 20;
    const std::string characters { "bnmv*&" };
    // atleast 10 '&' - 5 '*' - 5 'm' - 1 'b' // invalid // string size will be atleast 21 which
    // is invalid atmost 10 'b'
    std::vector<string::Spec> guarantee { { '&', 10 }, { '*', 5 }, { 'm', 5 }, { 'b', 1, 10 } };
    ASSERT_THROW(
        string::from_chars((guarantee), characters, fromCharactersLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForFromCharacters2)
{
    const auto fromCharactersLength = 20;
    const std::string characters { "ab1" };
    // atleast 6 '1'
    // atmost 3 'a' - 5 'b' - 8 '1' // invalid // string size wont exceed 16 which is invalid
    std::vector<string::Spec> guarantee { { 'a', 0, 3 }, { 'b', 0, 5 }, { '1', 6, 8 } };
    ASSERT_THROW(
        string::from_chars((guarantee), characters, fromCharactersLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForFromCharacters3)
{
    const auto fromCharactersLength = 20;
    const std::string characters { "67bnmM" };
    // exactly 2 '1' // invalid // '1' not in `characters`
    std::vector<string::Spec> guarantee { { '1', 2, 2 }, { 'M', 2, 2 }, { 'm', 2, 2 } };
    ASSERT_THROW(
        string::from_chars((guarantee), characters, fromCharactersLength), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateDefaultApha)
{
    const auto alpha = string::alpha();

    ASSERT_EQ(alpha.size(), 1);
    ASSERT_TRUE(faker::testing::any_of(string::data::ascii_letters,
        [alpha](char mixedCharacter) { return alpha[0] == mixedCharacter; }));
}

TEST_F(StringTest, shouldGenerateMixedAlpha)
{
    const auto alphaLength = 10;

    const auto alpha = string::alpha(alphaLength);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(faker::testing::all_of(alpha, [](char alphaCharacter) {
        return faker::testing::any_of(string::data::ascii_letters,
            [alphaCharacter](char mixedCharacter) { return mixedCharacter == alphaCharacter; });
    }));
}

TEST_F(StringTest, shouldGenerateUpperAlpha)
{
    const auto alphaLength = 15;

    const auto alpha = string::alpha(alphaLength, string::string_case::upper);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(faker::testing::all_of(alpha, [](char alphaCharacter) {
        return faker::testing::any_of(string::data::ascii_upper_letters,
            [alphaCharacter](char upperCharacter) { return upperCharacter == alphaCharacter; });
    }));
}

TEST_F(StringTest, shouldGenerateLowerAlpha)
{
    const auto alphaLength = 7;

    const auto alpha = string::alpha(alphaLength, string::string_case::lower);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(faker::testing::all_of(alpha, [](char ch1) {
        return faker::testing::any_of(
            string::data::ascii_lower_letters, [ch1](char ch2) { return ch2 == ch1; });
    }));
}

TEST_F(StringTest, shouldGenerateMixedAlphaWithGuarantee)
{
    const auto alphaLength = 20;
    // exactly 5 'a'
    // atleast 5 'A' - 3 'B' - 3 'z'
    // atmost 20 'A' - 20 'B' - 6 'z'
    const std::vector<string::Spec> guarantee { { 'A', 5, 20 }, { 'B', 3, 20 }, { 'a', 5, 5 },
        { 'z', 3, 6 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto alpha = string::alpha((copyGuarantee), alphaLength);

        ASSERT_EQ(alpha.size(), alphaLength);
        ASSERT_TRUE(faker::testing::all_of(alpha, [](char alphaCharacter) {
            return faker::testing::any_of(string::data::ascii_letters,
                [alphaCharacter](char mixedCharacter) { return mixedCharacter == alphaCharacter; });
        }));
        auto count_A = faker::testing::count(alpha, 'A');
        auto count_B = faker::testing::count(alpha, 'B');
        auto count_a = faker::testing::count(alpha, 'a');
        auto count_z = faker::testing::count(alpha, 'z');

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
    const std::vector<string::Spec> guarantee { { 'k', 5, 20 }, { 'o', 3, 20 }, { 'a', 5, 5 },
        { 'z', 3, 6 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto alpha = string::alpha((copyGuarantee), alphaLength, string::string_case::lower);

        ASSERT_EQ(alpha.size(), alphaLength);
        ASSERT_TRUE(faker::testing::all_of(alpha, [](char alphaCharacter) {
            return faker::testing::any_of(lowerCharSet,
                [alphaCharacter](char lowerCharacter) { return lowerCharacter == alphaCharacter; });
        }));
        auto count_k = faker::testing::count(alpha, 'k');
        auto count_o = faker::testing::count(alpha, 'o');
        auto count_a = faker::testing::count(alpha, 'a');
        auto count_z = faker::testing::count(alpha, 'z');

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
    const std::vector<string::Spec> guarantee { { 'K', 5, 20 }, { 'O', 3, 20 }, { 'A', 5, 5 },
        { 'Z', 3, 6 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto alpha = string::alpha((copyGuarantee), alphaLength, string::string_case::upper);

        ASSERT_EQ(alpha.size(), alphaLength);
        ASSERT_TRUE(faker::testing::all_of(alpha, [](char alphaCharacter) {
            return faker::testing::any_of(upperCharSet,
                [alphaCharacter](char lowerCharacter) { return lowerCharacter == alphaCharacter; });
        }));
        auto count_K = faker::testing::count(alpha, 'K');
        auto count_O = faker::testing::count(alpha, 'O');
        auto count_A = faker::testing::count(alpha, 'A');
        auto count_Z = faker::testing::count(alpha, 'Z');

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
    std::vector<string::Spec> guarantee { { 'A', 8, 10 }, { 'B', 10, 15 }, { 'Y', 1, 10 },
        { 'Z', 3, 3 } };
    ASSERT_THROW(string::alpha((guarantee), alphaLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlpha2)
{
    const auto alphaLength = 30;
    // atmost 1
    // 'A','B','C',D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    // invalid // string size won't exceed 26 which is invalid
    std::vector<string::Spec> guarantee = {
        { 'A', 0, 1 },
        { 'B', 0, 1 },
        { 'C', 0, 1 },
        { 'D', 0, 1 },
        { 'E', 0, 1 },
        { 'F', 0, 1 },
        { 'G', 0, 1 },
        { 'H', 0, 1 },
        { 'I', 0, 1 },
        { 'J', 0, 1 },
        { 'K', 0, 1 },
        { 'L', 0, 1 },
        { 'M', 0, 1 },
        { 'N', 0, 1 },
        { 'O', 0, 1 },
        { 'P', 0, 1 },
        { 'Q', 0, 1 },
        { 'R', 0, 1 },
        { 'S', 0, 1 },
        { 'T', 0, 1 },
        { 'U', 0, 1 },
        { 'V', 0, 1 },
        { 'W', 0, 1 },
        { 'X', 0, 1 },
        { 'Y', 0, 1 },
        { 'Z', 0, 1 },
    };
    ASSERT_THROW(
        string::alpha((guarantee), alphaLength, string::string_case::upper), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlpha3)
{
    const auto alphaLength = 20;
    // atleast 4 '5' // invalid // alpha can't have digits
    std::vector<string::Spec> guarantee { { 'a', 4, 10 }, { 'B', 4, 10 }, { '5', 4, 6 } };
    ASSERT_THROW(string::alpha((guarantee), alphaLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlpha4)
{
    const auto alphaLength = 20;
    // atleast 4 'a' // invalid // Can't have lower case characters when string casing is set to
    // string::string_case::upper
    std::vector<string::Spec> guarantee { { 'a', 4, 10 }, { 'B', 4, 10 } };
    ASSERT_THROW(
        string::alpha((guarantee), alphaLength, string::string_case::upper), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlpha5)
{
    const auto alphaLength = 20;
    // atleast 4 'B' // invalid // Can't have upper case characters when string casing is set to
    // string::string_case::lower
    std::vector<string::Spec> guarantee { { 'a', 4, 10 }, { 'B', 4, 10 } };
    ASSERT_THROW(
        string::alpha((guarantee), alphaLength, string::string_case::lower), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateDefaultAphanumeric)
{
    const auto alphanumeric = string::alphanumeric();

    ASSERT_EQ(alphanumeric.size(), 1);
    ASSERT_TRUE(faker::testing::any_of(string::data::ascii_alphanum,
        [alphanumeric](char mixedCharacter) { return alphanumeric[0] == mixedCharacter; }));
}

TEST_F(StringTest, shouldGenerateMixedAlphanumeric)
{
    const auto alphanumericLength = 10;

    const auto alphanumeric = string::alphanumeric(alphanumericLength);

    ASSERT_EQ(alphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(faker::testing::all_of(alphanumeric, [](char alphanumericCharacter) {
        return faker::testing::any_of(
            string::data::ascii_alphanum, [alphanumericCharacter](char mixedAlphanumericCharacter) {
                return alphanumericCharacter == mixedAlphanumericCharacter;
            });
    }));
}

TEST_F(StringTest, shouldGenerateUpperAlphanumeric)
{
    const auto alphanumericLength = 15;

    const auto alphanumeric = string::alphanumeric(alphanumericLength, string::string_case::upper);

    ASSERT_EQ(alphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(faker::testing::all_of(alphanumeric, [](char alphanumericCharacter) {
        return faker::testing::any_of(string::data::ascii_upper_alphanum,
            [alphanumericCharacter](char upperAlphanumericCharacter) {
                return upperAlphanumericCharacter == alphanumericCharacter;
            });
    }));
}

TEST_F(StringTest, shouldGenerateLowerAlphanumeric)
{
    const auto alphanumericLength = 7;

    const auto alphanumeric = string::alphanumeric(alphanumericLength, string::string_case::lower);

    ASSERT_EQ(alphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(faker::testing::all_of(alphanumeric, [](char alphanumericCharacter) {
        return faker::testing::any_of(string::data::ascii_lower_alphanum,
            [alphanumericCharacter](char lowerAlphanumericCharacter) {
                return lowerAlphanumericCharacter == alphanumericCharacter;
            });
    }));
}

TEST_F(StringTest, shouldGenerateMixedAlphanumericWithGuarantee)
{
    const auto alphanumericLength = 20;
    // exactly 1 'a'
    // atleast 5 'A' - 3 'B' - 3 'z'
    // atmost 20 'A' - 20 'B' - 6 'z'
    const std::vector<string::Spec> guarantee { { '1', 5, 20 }, { 'B', 3, 20 }, { 'a', 5, 5 },
        { 'z', 3, 6 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto alphanumeric = string::alphanumeric((copyGuarantee), alphanumericLength);

        ASSERT_EQ(alphanumeric.size(), alphanumericLength);
        ASSERT_TRUE(faker::testing::all_of(alphanumeric, [](char alphanumericCharacter) {
            return faker::testing::any_of(
                string::data::ascii_alphanum, [alphanumericCharacter](char mixedCharacter) {
                    return mixedCharacter == alphanumericCharacter;
                });
        }));
        auto count_1 = faker::testing::count(alphanumeric, '1');
        auto count_B = faker::testing::count(alphanumeric, 'B');
        auto count_a = faker::testing::count(alphanumeric, 'a');
        auto count_z = faker::testing::count(alphanumeric, 'z');

        ASSERT_TRUE(count_1 >= 5 && count_1 <= 20);
        ASSERT_TRUE(count_B >= 3 && count_B <= 20);
        ASSERT_TRUE(count_a == 5);
        ASSERT_TRUE(count_z >= 3 && count_z <= 6);
    }
}

TEST_F(StringTest, shouldGenerateLowerAlphanumericWithGuarantee)
{
    const auto alphanumericLength = 20;
    // exactly 5 'a'
    // atleast 5 'k' - 3 'o' - 3 '0'
    // atmost 20 'k' - 20 'o' - 6 '0'
    const std::vector<string::Spec> guarantee { { 'k', 5, 20 }, { 'o', 3, 20 }, { 'a', 5, 5 },
        { '0', 3, 6 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto alphanumeric
            = string::alphanumeric((copyGuarantee), alphanumericLength, string::string_case::lower);

        ASSERT_EQ(alphanumeric.size(), alphanumericLength);
        ASSERT_TRUE(faker::testing::all_of(alphanumeric, [](char alphanumericCharacter) {
            return faker::testing::any_of(
                string::data::ascii_lower_alphanum, [alphanumericCharacter](char lowerCharacter) {
                    return lowerCharacter == alphanumericCharacter;
                });
        }));
        auto count_k = faker::testing::count(alphanumeric, 'k');
        auto count_o = faker::testing::count(alphanumeric, 'o');
        auto count_a = faker::testing::count(alphanumeric, 'a');
        auto count_0 = faker::testing::count(alphanumeric, '0');

        ASSERT_TRUE(count_k >= 5 && count_k <= 20);
        ASSERT_TRUE(count_o >= 3 && count_o <= 20);
        ASSERT_TRUE(count_a == 5);
        ASSERT_TRUE(count_0 >= 3 && count_0 <= 6);
    }
}

TEST_F(StringTest, shouldGenerateUpperAlphanumericWithGuarantee)
{
    const auto alphanumericLength = 20;
    // exactly 5 'A'
    // atleast 5 '7' - 3 'O' - 3 'Z'
    // atmost 20 '7' - 20 'O' - 6 'Z'
    const std::vector<string::Spec> guarantee { { '7', 5, 20 }, { 'O', 3, 20 }, { 'A', 5, 5 },
        { 'Z', 3, 6 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto alphanumeric
            = string::alphanumeric((copyGuarantee), alphanumericLength, string::string_case::upper);

        ASSERT_EQ(alphanumeric.size(), alphanumericLength);
        ASSERT_TRUE(faker::testing::all_of(alphanumeric, [](char alphanumericCharacter) {
            return faker::testing::any_of(
                string::data::ascii_upper_alphanum, [alphanumericCharacter](char lowerCharacter) {
                    return lowerCharacter == alphanumericCharacter;
                });
        }));
        auto count_7 = faker::testing::count(alphanumeric, '7');
        auto count_O = faker::testing::count(alphanumeric, 'O');
        auto count_A = faker::testing::count(alphanumeric, 'A');
        auto count_Z = faker::testing::count(alphanumeric, 'Z');

        ASSERT_TRUE(count_7 >= 5 && count_7 <= 20);
        ASSERT_TRUE(count_O >= 3 && count_O <= 20);
        ASSERT_TRUE(count_A == 5);
        ASSERT_TRUE(count_Z >= 3 && count_Z <= 6);
    }
}

TEST_F(StringTest, invalidGuaranteeForAlphanumeric1)
{
    const auto alphanumericLength = 20;
    // exactly 3 '8'
    // atleast 8 'A' - 10 'b' 1 'Y' // invalid // string size will be atleast 22 which is invalid
    // atmost 10 'A','Y' - 15 'b'
    std::vector<string::Spec> guarantee
        = { { 'A', 8, 10 }, { 'b', 10, 15 }, { 'Y', 1, 10 }, { '8', 3, 3 } };
    ASSERT_THROW(string::alphanumeric((guarantee), alphanumericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlphanumeric2)
{
    const auto alphanumericLength = 40;
    // atmost 1
    // 'A','B','C',D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
    // 'S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'
    // invalid // string size won't exceed 36 which is invalid
    std::vector<string::Spec> guarantee = {
        { 'A', 0, 1 },
        { 'B', 0, 1 },
        { 'C', 0, 1 },
        { 'D', 0, 1 },
        { 'E', 0, 1 },
        { 'F', 0, 1 },
        { 'G', 0, 1 },
        { 'H', 0, 1 },
        { 'I', 0, 1 },
        { 'J', 0, 1 },
        { 'K', 0, 1 },
        { 'L', 0, 1 },
        { 'M', 0, 1 },
        { 'N', 0, 1 },
        { 'O', 0, 1 },
        { 'P', 0, 1 },
        { 'Q', 0, 1 },
        { 'R', 0, 1 },
        { 'S', 0, 1 },
        { 'T', 0, 1 },
        { 'U', 0, 1 },
        { 'V', 0, 1 },
        { 'W', 0, 1 },
        { 'X', 0, 1 },
        { 'Y', 0, 1 },
        { 'Z', 0, 1 },
        { '0', 0, 1 },
        { '1', 0, 1 },
        { '2', 0, 1 },
        { '3', 0, 1 },
        { '4', 0, 1 },
        { '5', 0, 1 },
        { '6', 0, 1 },
        { '7', 0, 1 },
        { '8', 0, 1 },
        { '9', 0, 1 },
    };
    ASSERT_THROW(string::alphanumeric((guarantee), alphanumericLength, string::string_case::upper),
        std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlphanumeric3)
{
    const auto alphanumericLength = 20;
    // atleast 4 '#' // invalid // alphanumeric can't have symbols
    std::vector<string::Spec> guarantee
        = { { 'a', 4, 10 }, { 'B', 4, 10 }, { '5', 4, 6 }, { '#', 4 } };
    ASSERT_THROW(string::alphanumeric(guarantee, alphanumericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlphanumeric4)
{
    const auto alphanumericLength = 20;
    // atleast 4 'a' // invalid // Can't have lower case characters when string casing is set to
    // string::string_case::upper
    std::vector<string::Spec> guarantee = { { 'a', 4, 10 }, { 'B', 4, 10 }, { '2', 1 } };
    ASSERT_THROW(string::alphanumeric(guarantee, alphanumericLength, string::string_case::upper),
        std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForAlphanumeric5)
{
    const auto alphanumericLength = 20;
    // atleast 4 'B' // invalid // Can't have upper case characters when string casing is set to
    // string::string_case::lower
    std::vector<string::Spec> guarantee = { { 'a', 4, 10 }, { 'B', 4, 10 }, { '8', 8, 10 } };
    ASSERT_THROW(string::alphanumeric((guarantee), alphanumericLength, string::string_case::lower),
        std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateNumeric)
{
    const auto numeric = string::numeric();

    ASSERT_EQ(numeric.size(), 1);
    ASSERT_TRUE(faker::testing::any_of(
        numeric, [numeric](char numericCharacter) { return numeric[0] == numericCharacter; }));
}

TEST_F(StringTest, shouldGenerateNumericWithoutLeadingZeros)
{
    const auto numericLength = 13;

    const auto numeric = string::numeric(numericLength, false);

    const auto nonZeroCharacter = numeric[0];
    const auto numericWithPossibleZeroCharacters = numeric.substr(1);

    ASSERT_EQ(numeric.size(), numericLength);
    ASSERT_TRUE(faker::testing::any_of(
        string::data::non_zero_digits, [nonZeroCharacter](char numericCharacter) {
            return nonZeroCharacter == numericCharacter;
        }));
    ASSERT_TRUE(faker::testing::all_of(
        numericWithPossibleZeroCharacters, [](char numericCharacterWithPossibleZero) {
            return faker::testing::any_of(
                string::data::digits, [numericCharacterWithPossibleZero](char numericCharacter) {
                    return numericCharacterWithPossibleZero == numericCharacter;
                });
        }));
}

TEST_F(StringTest, shouldGenerateNumericWithGuarantee1)
{
    const auto numericLength = 20;
    // atleast 10 '0' - 5 '9'
    // atmost 15 '0' - 10 '9'
    const std::vector<string::Spec> guarantee = { { '0', 10, 15 }, { '9', 5, 10 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto numeric = string::numeric((copyGuarantee), numericLength);

        ASSERT_EQ(numeric.size(), numericLength);
        ASSERT_TRUE(faker::testing::any_of(
            numeric, [numeric](char numericCharacter) { return numeric[0] == numericCharacter; }));

        auto count_0 = faker::testing::count(numeric, '0');
        auto count_9 = faker::testing::count(numeric, '9');

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
    const std::vector<string::Spec> guarantee { { '1', 0, 0 }, { '2', 5, 20 }, { '8', 0, 1 },
        { '9', 5, 5 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto numeric = string::numeric((copyGuarantee), numericLength);

        ASSERT_EQ(numeric.size(), numericLength);
        ASSERT_TRUE(faker::testing::any_of(
            numeric, [numeric](char numericCharacter) { return numeric[0] == numericCharacter; }));

        auto count_1 = faker::testing::count(numeric, '1');
        auto count_2 = faker::testing::count(numeric, '2');
        auto count_8 = faker::testing::count(numeric, '8');
        auto count_9 = faker::testing::count(numeric, '9');

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
    const std::vector<string::Spec> guarantee = { { '0', 19 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto numeric = string::numeric((copyGuarantee), numericLength, false);

        const auto nonZeroCharacter = numeric[0];
        const auto numericWithPossibleZeroCharacters = numeric.substr(1);

        ASSERT_EQ(numeric.size(), numericLength);
        ASSERT_TRUE(faker::testing::any_of(
            string::data::non_zero_digits, [nonZeroCharacter](char numericCharacter) {
                return nonZeroCharacter == numericCharacter;
            }));
        ASSERT_TRUE(faker::testing::all_of(
            numericWithPossibleZeroCharacters, [](char numericCharacterWithPossibleZero) {
                return faker::testing::any_of(string::data::digits,
                    [numericCharacterWithPossibleZero](char numericCharacter) {
                        return numericCharacterWithPossibleZero == numericCharacter;
                    });
            }));
        auto count_0 = faker::testing::count(numeric, '0');

        ASSERT_TRUE(count_0 >= 19);
    }
}

TEST_F(StringTest, shouldGenerateNumericWithoutLeadingZerosWithGuarantee2)
{
    const auto numericLength = 20;
    // atleast 10 '0' - 3 '1' - 3 '3'
    // atmost 4 '1' - 4 '3'
    const std::vector<string::Spec> guarantee = { { '0', 10 }, { '1', 3, 4 }, { '3', 2, 4 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto numeric = string::numeric((copyGuarantee), numericLength, false);

        const auto nonZeroCharacter = numeric[0];
        const auto numericWithPossibleZeroCharacters = numeric.substr(1);

        ASSERT_EQ(numeric.size(), numericLength);
        ASSERT_TRUE(faker::testing::any_of(
            string::data::non_zero_digits, [nonZeroCharacter](char numericCharacter) {
                return nonZeroCharacter == numericCharacter;
            }));
        ASSERT_TRUE(faker::testing::all_of(
            numericWithPossibleZeroCharacters, [](char numericCharacterWithPossibleZero) {
                return faker::testing::any_of(string::data::digits,
                    [numericCharacterWithPossibleZero](char numericCharacter) {
                        return numericCharacterWithPossibleZero == numericCharacter;
                    });
            }));
        auto count_0 = faker::testing::count(numeric, '0');
        auto count_1 = faker::testing::count(numeric, '1');
        auto count_3 = faker::testing::count(numeric, '3');

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
    std::vector<string::Spec> guarantee = { { '0', 10 }, { '1', 3, 4 }, { '3', 8, 10 } };
    ASSERT_THROW(string::numeric((guarantee), numericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForNumeric2)
{
    const auto numericLength = 20;
    // atmost 1 '0','1','2','3','4','5','6','7','8','9' // invalid // string size wont exceed 10
    // which is wrong
    std::vector<string::Spec> guarantee = {
        { '1', 0, 1 },
        { '2', 0, 1 },
        { '3', 0, 1 },
        { '4', 0, 1 },
        { '5', 0, 1 },
        { '6', 0, 1 },
        { '7', 0, 1 },
        { '8', 0, 1 },
        { '9', 0, 1 },
        { '0', 0, 1 },
    };
    ASSERT_THROW(string::numeric((guarantee), numericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForNumeric3)
{
    const auto numericLength = 20;
    // exactly 5 'a' // invalid // numeric string can't have alphabets
    std::vector<string::Spec> guarantee
        = { { '0', 10 }, { '1', 3, 4 }, { '3', 2, 4 }, { 'a', 5, 5 } };
    ASSERT_THROW(string::numeric((guarantee), numericLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForNumeric4)
{
    const auto numericLength = 5;
    // atleast 5 '0' // invalid // leading zeros not allowed so '0' count should be less than
    // numericLength i.e 5
    std::vector<string::Spec> guarantee = { { '0', 5 } };
    ASSERT_THROW(string::numeric((guarantee), numericLength, false), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateHexadecimal)
{
    const auto hexadecimalLength = 8;

    const auto hexadecimal = string::hexadecimal(hexadecimalLength);

    const auto prefix = hexadecimal.substr(0, 2);
    const auto hexNumber = hexadecimal.substr(2);

    ASSERT_EQ(hexadecimal.size(), hexadecimalLength + 2);
    ASSERT_EQ(prefix, "0x");
    ASSERT_TRUE(faker::testing::any_of(hexNumber, [hexNumber](char hexNumberCharacter) {
        return string::data::hex_lower_digits.find(hexNumberCharacter) != std::string::npos;
    }));
}

TEST_F(StringTest, shouldGenerateHexadecimalWithHashPrefix)
{
    const auto hexadecimalLength = 8;

    const auto hexadecimal
        = string::hexadecimal(hexadecimalLength, hex_case_t::upper, hex_prefix_t::hash);

    const auto prefix = hexadecimal.substr(0, 1);
    const auto hexNumber = hexadecimal.substr(1);

    ASSERT_EQ(hexadecimal.size(), hexadecimalLength + 1);
    ASSERT_EQ(prefix, "#");
    ASSERT_TRUE(faker::testing::any_of(hexNumber, [](char hexNumberCharacter) {
        return string::data::hex_upper_digits.find(hexNumberCharacter) != std::string::npos;
    }));
}

TEST_F(StringTest, shouldGenerateHexadecimalWithoutPrefix)
{
    const auto hexadecimalLength = 8;

    const auto hexadecimal
        = string::hexadecimal(hexadecimalLength, hex_case_t::upper, hex_prefix_t::none);

    ASSERT_EQ(hexadecimal.size(), hexadecimalLength);
    ASSERT_TRUE(faker::testing::any_of(hexadecimal, [](char hexNumberCharacter) {
        return string::data::hex_upper_digits.find(hexNumberCharacter) != std::string::npos;
    }));
}

TEST_F(StringTest, shouldGenerateHexadecimalWithGuarantee1)
{
    const auto hexadecimalLength = 20;
    // exactly 4 'a'
    // atleast 3 'f'
    // atmost 10 'f'
    std::vector<string::Spec> guarantee { { 'a', 4, 4 }, { 'f', 3, 10 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        const auto hexadecimal = string::hexadecimal(guarantee, hexadecimalLength);
        const auto prefix = hexadecimal.substr(0, 2);
        const auto hexNumber = hexadecimal.substr(2);

        ASSERT_EQ(hexNumber.size(), hexadecimalLength);
        ASSERT_EQ(prefix, "0x");
        ASSERT_TRUE(faker::testing::any_of(hexNumber, [hexNumber](char hexNumberCharacter) {
            return string::data::hex_lower_digits.find(hexNumberCharacter) != std::string::npos;
        }));

        auto count_a = faker::testing::count(hexNumber, 'a');
        auto count_f = faker::testing::count(hexNumber, 'f');
        ASSERT_TRUE(count_a == 4);
        ASSERT_TRUE(count_f >= 3 && count_f <= 10);
    }
}

TEST_F(StringTest, shouldGenerateHexadecimalWithGuarantee2)
{
    const auto hexadecimalLength = 20;
    // exactly 10 'F' - 0 'A'
    // atleast 5 '0'
    std::vector<string::Spec> guarantee { { 'A', 0, 0 }, { 'F', 10, 10 }, { '0', 5 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        const auto hexadecimal
            = string::hexadecimal(guarantee, hexadecimalLength, hex_case_t::upper);
        const auto prefix = hexadecimal.substr(0, 2);
        const auto hexNumber = hexadecimal.substr(2);

        ASSERT_EQ(hexNumber.size(), hexadecimalLength);
        ASSERT_EQ(prefix, "0x");
        ASSERT_TRUE(faker::testing::any_of(hexNumber, [hexNumber](char hexNumberCharacter) {
            return string::data::hex_upper_digits.find(hexNumberCharacter) != std::string::npos;
        }));

        auto count_A = faker::testing::count(hexNumber, 'A');
        auto count_F = faker::testing::count(hexNumber, 'F');
        auto count_0 = faker::testing::count(hexNumber, '0');
        ASSERT_TRUE(count_A == 0);
        ASSERT_TRUE(count_F == 10);
        ASSERT_TRUE(count_0 >= 5);
    }
}

TEST_F(StringTest, shouldGenerateHexadecimalWithGuarantee3)
{
    const auto hexadecimalLength = 20;
    // exactly 0 '0' '1' '2' '3' '4' '5' '6' '7'
    std::vector<string::Spec> guarantee {
        { '0', 0, 0 },
        { '1', 0, 0 },
        { '2', 0, 0 },
        { '3', 0, 0 },
        { '4', 0, 0 },
        { '5', 0, 0 },
        { '6', 0, 0 },
        { '7', 0, 0 },
    };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto hexadecimal
            = string::hexadecimal((copyGuarantee), hexadecimalLength, hex_case_t::upper);
        const auto prefix = hexadecimal.substr(0, 2);
        const auto hexNumber = hexadecimal.substr(2);

        ASSERT_EQ(hexNumber.size(), hexadecimalLength);
        ASSERT_EQ(prefix, "0x");
        ASSERT_TRUE(faker::testing::any_of(hexNumber, [hexNumber](char hexNumberCharacter) {
            return string::data::hex_upper_digits.find(hexNumberCharacter) != std::string::npos;
        }));

        auto count_0 = faker::testing::count(hexNumber, '0');
        auto count_1 = faker::testing::count(hexNumber, '1');
        auto count_2 = faker::testing::count(hexNumber, '2');
        auto count_3 = faker::testing::count(hexNumber, '3');
        auto count_4 = faker::testing::count(hexNumber, '4');
        auto count_5 = faker::testing::count(hexNumber, '5');
        auto count_6 = faker::testing::count(hexNumber, '6');
        auto count_7 = faker::testing::count(hexNumber, '7');
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
    std::vector<string::Spec> guarantee { { 'A', 0, 0 }, { 'F', 10, 10 }, { 'G', 5 } };
    ASSERT_THROW(string::hexadecimal((guarantee), hexadecimalLength, hex_case_t::upper),
        std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal2)
{
    const auto hexadecimalLength = 20;
    // atleast 5 'F' // invalid // 'F' is not a valid char for hexadecimal numbers with
    // hex_case::lower
    std::vector<string::Spec> guarantee { { 'a', 0, 0 }, { 'F', 10, 10 }, { '1', 5 } };
    ASSERT_THROW(string::hexadecimal((guarantee), hexadecimalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal3)
{
    const auto hexadecimalLength = 20;
    // atleast 5 'F' // invalid // 'F' is not a valid char for hexadecimal numbers with
    // hex_case::lower
    std::vector<string::Spec> guarantee { { 'a', 0, 0 }, { 'F', 10, 10 }, { '1', 5 } };
    ASSERT_THROW(string::hexadecimal((guarantee), hexadecimalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal4)
{
    const auto hexadecimalLength = 10;
    // atleast 5 'a' - 8 'b' // invalid // string size will be atleast 13 which is wrong
    // atmost 10 'b' - 3 '1'
    std::vector<string::Spec> guarantee { { 'a', 5 }, { 'b', 8, 10 }, { '1', 0, 3 } };
    ASSERT_THROW(string::hexadecimal((guarantee), hexadecimalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForHexadecimal5)
{
    const auto hexadecimalLength = 20;
    // atmost 1 '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' // invalid // string
    // size wont exceed 16 which is wrong
    std::vector<string::Spec> guarantee {
        { '0', 0, 1 },
        { '1', 0, 1 },
        { '2', 0, 1 },
        { '3', 0, 1 },
        { '4', 0, 1 },
        { '5', 0, 1 },
        { '6', 0, 1 },
        { '7', 0, 1 },
        { '8', 0, 1 },
        { '9', 0, 1 },
        { 'a', 0, 1 },
        { 'b', 0, 1 },
        { 'c', 0, 1 },
        { 'd', 0, 1 },
        { 'e', 0, 1 },
        { 'f', 0, 1 },
    };
    ASSERT_THROW(string::hexadecimal((guarantee), hexadecimalLength), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateBinary)
{
    const auto binaryLength = 8;

    const auto binary = string::binary(binaryLength);

    const auto prefix = binary.substr(0, 2);
    const auto binaryNumber = binary.substr(2);

    ASSERT_EQ(binary.size(), binaryLength + 2);
    ASSERT_EQ(prefix, "0b");
    ASSERT_TRUE(faker::testing::any_of(binary, [](char binaryNumberCharacter) {
        return std::string("01").find(binaryNumberCharacter) != std::string::npos;
    }));
}

TEST_F(StringTest, shouldGenerateBinaryWithGuarantee1)
{
    const auto binaryLength = 9;

    // atleast 3 '0' and 2 '1'
    // atmost 7 '0' and 7 '1'
    std::vector<string::Spec> guarantee { { '0', 3, 7 }, { '1', 2, 7 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto binary = string::binary((copyGuarantee), binaryLength);

        const auto prefix = binary.substr(0, 2);
        const auto binaryNumber = binary.substr(2);

        ASSERT_EQ(binaryNumber.size(), binaryLength);
        ASSERT_EQ(prefix, "0b");
        ASSERT_TRUE(faker::testing::any_of(binaryNumber, [](char binaryNumberCharacter) {
            return std::string("01").find(binaryNumberCharacter) != std::string::npos;
        }));
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
    std::vector<string::Spec> guarantee { { '0', 8, 8 }, { '1', 2, 2 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        const auto binary = string::binary(guarantee, binaryLength);

        const auto prefix = binary.substr(0, 2);
        const auto binaryNumber = binary.substr(2);

        EXPECT_EQ(binaryNumber.size(), binaryLength);
        EXPECT_EQ(prefix, "0b");
        EXPECT_TRUE(faker::testing::any_of(binaryNumber, [](char binaryNumberCharacter) {
            return std::string("01").find(binaryNumberCharacter) != std::string::npos;
        }));
        auto count_0 = std::count(binaryNumber.begin(), binaryNumber.end(), '0');
        auto count_1 = std::count(binaryNumber.begin(), binaryNumber.end(), '1');
        EXPECT_EQ(count_0, 8);
        EXPECT_EQ(count_1, 2);
    }
}

TEST_F(StringTest, shouldGenerateBinaryWithGuarantee3)
{
    const auto binaryLength = 10;

    // atleast 10 '0'
    std::vector<string::Spec> guarantee { { '0', 0, 10 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        const auto binary = string::binary(guarantee, binaryLength);

        const auto prefix = binary.substr(0, 2);
        const auto binaryNumber = binary.substr(2);

        ASSERT_EQ(binaryNumber.size(), binaryLength);
        ASSERT_EQ(prefix, "0b");
        ASSERT_TRUE(faker::testing::any_of(binaryNumber, [](char binaryNumberCharacter) {
            return std::string("01").find(binaryNumberCharacter) != std::string::npos;
        }));
        auto count_0 = std::count(binaryNumber.begin(), binaryNumber.end(), '0');
        ASSERT_LE(count_0, 10);
    }
}

TEST_F(StringTest, shouldGenerateBinaryWithGuarantee4)
{
    const auto binaryLength = 10;

    // atmost 0 '0'
    std::vector<string::Spec> guarantee { { '0', 0, 0 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto binary = string::binary((copyGuarantee), binaryLength);

        const auto prefix = binary.substr(0, 2);
        const auto binaryNumber = binary.substr(2);

        ASSERT_EQ(binaryNumber.size(), binaryLength);
        ASSERT_EQ(prefix, "0b");
        ASSERT_TRUE(faker::testing::any_of(binaryNumber, [](char binaryNumberCharacter) {
            return std::string("01").find(binaryNumberCharacter) != std::string::npos;
        }));
        auto count_0 = std::count(binaryNumber.begin(), binaryNumber.end(), '0');
        ASSERT_TRUE(count_0 == 0);
    }
}

TEST_F(StringTest, invalidGuaranteeForBinary1)
{
    const auto binaryLength = 10;

    // atleast 6 '0' and 6 '1'  // invalid // total string size will be 12 which is wrong
    // atleast 10 '0' and 10 '1'
    std::vector<string::Spec> guarantee { { '0', 6, 10 }, { '1', 6, 10 } };
    EXPECT_THROW(string::binary((guarantee), binaryLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForBinary2)
{
    const auto binaryLength = 20;

    // atleast 6 '0' and 6 '1'
    // atleast 10 '0' and 8 '1' // invalid // total string size won't exceed 18 which is wrong
    std::vector<string::Spec> guarantee { { '0', 6, 10 }, { '1', 6, 8 } };
    EXPECT_THROW(string::binary((guarantee), binaryLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForBinary3)
{
    const auto binaryLength = 10;
    //  atleast 4 '0' and 3 'a' // invalid // binary string should consist of only '0' and '1'
    std::vector<string::Spec> guarantee { { '0', 4 }, { 'a', 3 } };
    EXPECT_THROW(string::binary((guarantee), binaryLength), std::invalid_argument);
}

TEST_F(StringTest, shouldGenerateOctalWithPrefix)
{
    const auto octalLength = 8;

    const auto octal = string::octal(octalLength);

    const auto prefix = octal.substr(0, 2);
    const auto octalNumber = octal.substr(2);

    ASSERT_EQ(octal.size(), octalLength + 2);
    ASSERT_EQ(prefix, "0o");
    ASSERT_TRUE(faker::testing::any_of(octal, [](char octalNumberCharacter) {
        return std::string("01234567").find(octalNumberCharacter) != std::string::npos;
    }));
}

TEST_F(StringTest, shouldGenerateOctalWithGuarantee1)
{
    const auto octalLength = 10;
    // exactly 2 '3' - 0 '5'
    // atleast 2 '0' - 3 '6' - 1 '7'
    // atmost 10 '6' - 10 '7'
    std::vector<string::Spec> guarantee { { '0', 2 }, { '3', 2, 2 }, { '5', 0, 0 }, { '6', 3, 10 },
        { '7', 1, 10 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        auto copyGuarantee = guarantee;
        const auto octal = string::octal((copyGuarantee), octalLength);

        const auto prefix = octal.substr(0, 2);
        const auto octalNumber = octal.substr(2);

        ASSERT_EQ(octalNumber.size(), octalLength);
        ASSERT_EQ(prefix, "0o");
        ASSERT_TRUE(faker::testing::any_of(octal, [](char octalNumberCharacter) {
            return std::string("01234567").find(octalNumberCharacter) != std::string::npos;
        }));
        auto count_0 = faker::testing::count(octalNumber, '0');
        auto count_3 = faker::testing::count(octalNumber, '3');
        auto count_5 = faker::testing::count(octalNumber, '5');
        auto count_6 = faker::testing::count(octalNumber, '6');
        auto count_7 = faker::testing::count(octalNumber, '7');
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
    std::vector<string::Spec> guarantee { { '0', 18 }, { '2', 0, 0 }, { '3', 0, 0 }, { '4', 0, 0 },
        { '5', 0, 0 }, { '6', 0, 0 }, { '7', 0, 0 } };
    // it is a random function so lets test for 20 random generations
    for (int i = 0; i < runCount; ++i) {
        const auto octal = string::octal(guarantee, octalLength);

        const auto prefix = octal.substr(0, 2);
        const auto octalNumber = octal.substr(2);

        ASSERT_EQ(octalNumber.size(), octalLength);
        ASSERT_EQ(prefix, "0o");
        ASSERT_TRUE(faker::testing::any_of(octal, [](char octalNumberCharacter) {
            return std::string("01234567").find(octalNumberCharacter) != std::string::npos;
        }));
        auto count_0 = faker::testing::count(octalNumber, '0');
        auto count_1 = faker::testing::count(octalNumber, '1');
        auto count_2 = faker::testing::count(octalNumber, '2');
        auto count_3 = faker::testing::count(octalNumber, '3');
        auto count_4 = faker::testing::count(octalNumber, '4');
        auto count_5 = faker::testing::count(octalNumber, '5');
        auto count_6 = faker::testing::count(octalNumber, '6');
        auto count_7 = faker::testing::count(octalNumber, '7');

        EXPECT_GE(count_0, 18);
        EXPECT_EQ(count_1, octalLength - count_0);
        EXPECT_EQ(count_2, 0);
        EXPECT_EQ(count_3, 0);
        EXPECT_EQ(count_4, 0);
        EXPECT_EQ(count_5, 0);
        EXPECT_EQ(count_6, 0);
        EXPECT_EQ(count_7, 0);
    }
}

TEST_F(StringTest, invalidGuaranteeForOctal1)
{
    const auto octalLength = 10;
    // exactly 0 '4'
    // atleast 8 '0' - 9 '2' 9 '3'  // invalid // total string size will be atleast 26 which is
    // wrong atmost
    std::vector<string::Spec> guarantee { { '0', 8 }, { '2', 9 }, { '3', 9 }, { '4', 0, 0 } };
    ASSERT_THROW(string::octal((guarantee), octalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForOctal2)
{
    const auto octalLength = 20;
    // atmost 2 '0' '1' '2' '3' '4' '5' '6' '7' // invalid // octal string won't exceed 16 which is
    // wrong
    std::vector<string::Spec> guarantee { { '0', 0, 2 }, { '1', 0, 2 }, { '2', 0, 2 },
        { '3', 0, 2 }, { '4', 0, 2 }, { '5', 0, 2 }, { '6', 0, 2 }, { '7', 0, 2 } };
    ASSERT_THROW(string::octal((guarantee), octalLength), std::invalid_argument);
}

TEST_F(StringTest, invalidGuaranteeForOctal3)
{
    const auto octalLength = 20;

    // atleast 2 '8' // invalid // octal numbers cannot have '8'
    // atmost 3 '8'
    std::vector<string::Spec> guarantee { { '0', 0, 2 }, { '1', 0, 2 }, { '8', 2, 3 },
        { '2', 0, 2 }, { '3', 0, 2 } };
    ASSERT_THROW(string::octal((guarantee), octalLength), std::invalid_argument);
}
