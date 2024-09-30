#include <algorithm>
#include <cctype>
#include <regex>
#include <set>
#include <span>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

#include "common/algo_helper.h"
#include "faker-cxx/helper.h"
#include "gmock/gmock.h"

using namespace ::testing;
using namespace faker;
using namespace faker::helper;

class HelperTest : public Test
{
};

TEST_F(HelperTest, ArrayElement)
{
    std::vector<std::string> data{"hello", "world", "this", "is", "faker-cxx", "library"};

    const auto result = randomElement(data);

    ASSERT_TRUE(std::ranges::any_of(data, [&result](const std::string& element) { return result == element; }));
}

TEST_F(HelperTest, ArrayElementEmptyData)
{
    std::vector<std::string> data{};

    ASSERT_THROW(randomElement(data), std::invalid_argument);
}

TEST_F(HelperTest, ArrayElementSpan)
{
    std::vector<std::string> data{"hello", "world"};

    const auto result = randomElement(std::span<const std::string>(data));

    ASSERT_TRUE(std::ranges::any_of(data, [&result](const std::string& element) { return result == element; }));
}

TEST_F(HelperTest, ArrayElementSpanEmptyData)
{
    std::vector<std::string> data{};

    ASSERT_THROW(randomElement(std::span<const std::string>(data)), std::invalid_argument);
}

TEST_F(HelperTest, WeightedArrayElement)
{
    std::vector<WeightedElement<std::string>> data{{1, "hello"}, {9, "world"}};

    const auto result = weightedRandomElement(data);

    ASSERT_TRUE(std::ranges::any_of(data, [&result](const WeightedElement<std::string>& element)
                                    { return result == element.value; }));
}

TEST_F(HelperTest, WeightedArrayElement_withZeroWeight)
{
    std::vector<WeightedElement<std::string>> data{{0, "hello"}, {1, "world"}};

    const auto result = weightedRandomElement(data);

    ASSERT_EQ(result, "world");
}

TEST_F(HelperTest, WeightedArrayZeroSum)
{
    std::vector<WeightedElement<std::string>> data{{0, "hello"}, {0, "world"}};

    ASSERT_THROW(weightedRandomElement(data), std::invalid_argument);
}

TEST_F(HelperTest, WeightedArrayEmptyData)
{
    std::vector<WeightedElement<std::string>> data{};

    ASSERT_THROW(weightedRandomElement(data), std::invalid_argument);
}

TEST_F(HelperTest, ShuffleString)
{
    std::string input = "Hello World!";

    const auto result = shuffleString(input);

    ASSERT_TRUE(
        std::ranges::all_of(input, [&result](char character) { return result.find(character) != std::string::npos; }));
}

TEST_F(HelperTest, SetElement)
{
    std::set<char> chars{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'l', 'm'};

    std::vector<char> randomChars;

    randomChars.reserve(30);

    for (int i = 0; i < 30; ++i)
    {
        randomChars.push_back(setElement(chars));
    }

    for (auto character : randomChars)
    {
        ASSERT_TRUE(chars.find(character) != chars.end());
    }
}

TEST_F(HelperTest, SetElementEmptyData)
{
    std::set<char> chars{};

    ASSERT_THROW(setElement<char>(chars), std::invalid_argument);
}

TEST_F(HelperTest, ReplaceSymbolWithNumber)
{
    std::string input = "123#456!";

    const auto result = replaceSymbolWithNumber(input);

    ASSERT_TRUE(std::ranges::all_of(result, ::isdigit));
}

TEST_F(HelperTest, ReplaceSymbolWithLetter)
{
    std::string input = "ABCD_FGH";

    const auto result = replaceSymbolWithLetter(input);

    ASSERT_TRUE(std::ranges::all_of(result, ::isalpha));
}

TEST_F(HelperTest, RegexpStyleStringParse)
{
    std::string input = "#{5}[2-4]test[1-3]";

    const auto result = regexpStyleStringParse(input);

    ASSERT_EQ(result.size(), 11);
}

TEST_F(HelperTest, RegexpStyleStringParseMaxMin)
{
    std::string input = "#{6,5}[4-2]test[1-3]";

    const auto result = regexpStyleStringParse(input);

    ASSERT_THAT(result.size(), AllOf(Ge(11), Le(12)));
}

TEST_F(HelperTest, ReplaceCreditCardSymbols)
{
    const auto result_default = replaceCreditCardSymbols();
    ASSERT_EQ(result_default.size(), 24);
    ASSERT_EQ(result_default[4], '-');
    ASSERT_EQ(result_default[9], '-');
    ASSERT_EQ(result_default[14], '-');
    ASSERT_EQ(result_default[19], '-');

    const auto format_custom = "1234-[4-9]-##!!-L";
    const auto result_custom = replaceCreditCardSymbols(format_custom);
    std::regex custom_format_regex("1234-[4-9]-\\d{2}[2-9]{2}-\\d");
    ASSERT_TRUE(std::regex_match(result_custom, custom_format_regex));

    ASSERT_EQ(result_custom.substr(0, 5), "1234-");
    ASSERT_EQ(result_custom.substr(6, 1), "-");
    ASSERT_TRUE(result_custom[5] >= '4' && result_custom[5] <= '9');
    ASSERT_TRUE(result_custom[8] >= '0' && result_custom[8] <= '9');
    ASSERT_TRUE(result_custom[9] >= '0' && result_custom[9] <= '9');
}

TEST_F(HelperTest, ObjectKeyTest)
{
    std::unordered_map<int, std::string> testMap = {{1, "one"}, {2, "two"}, {3, "three"}};

    ASSERT_NO_THROW({
        int key = objectKey(testMap);
        EXPECT_TRUE(testMap.find(key) != testMap.end());
    });

    std::unordered_map<int, std::string> emptyMap;

    ASSERT_THROW({ objectKey(emptyMap); }, std::runtime_error);
}

TEST_F(HelperTest, MaybeString)
{
    double highProbability = 1;
    auto result = maybe<std::string>([]() { return "Hello World!"; }, highProbability);
    EXPECT_EQ(result, "Hello World!");

    double lowProbability = 0;
    result = maybe<std::string>([]() { return "Hello World!"; }, lowProbability);
    EXPECT_EQ(result, "");
}

TEST_F(HelperTest, MaybeInt)
{
    double highProbability = 1;
    auto result = maybe<int>([]() { return 42; }, highProbability);
    EXPECT_EQ(result, 42);

    double lowProbability = 0;
    result = maybe<int>([]() { return 42; }, lowProbability);
    EXPECT_EQ(result, 0);
}

TEST_F(HelperTest, MaybeDouble)
{
    double highProbability = 1;
    auto result = maybe<double>([]() { return 3.14; }, highProbability);
    EXPECT_EQ(result, 3.14);

    double lowProbability = 0;
    result = maybe<double>([]() { return 3.14; }, lowProbability);
    EXPECT_EQ(result, 0.0);
}
