#include "faker-cxx/Helper.h"

#include <algorithm>
#include <regex>
#include <stdexcept>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

#include "faker-cxx/String.h"

using namespace faker;
using namespace ::testing;

class HelperTest : public Test
{
};

TEST_F(HelperTest, ArrayElement)
{
    std::vector<std::string> data{"hello", "world"};

    std::string result = Helper::arrayElement(data);

    ASSERT_TRUE(std::ranges::any_of(data, [&result](const std::string& element) { return result == element; }));
}

TEST_F(HelperTest, ArrayElementEmptyData)
{
    std::vector<std::string> data{};

    ASSERT_THROW(Helper::arrayElement(data), std::invalid_argument);
}

TEST_F(HelperTest, ArrayElementSpan)
{
    std::vector<std::string> data{"hello", "world"};

    std::string result = Helper::arrayElement(std::span<const std::string>(data));

    ASSERT_TRUE(std::ranges::any_of(data, [&result](const std::string& element) { return result == element; }));
}

TEST_F(HelperTest, ArrayElementSpanEmptyData)
{
    std::vector<std::string> data{};

    ASSERT_THROW(Helper::arrayElement(std::span<const std::string>(data)), std::invalid_argument);
}

TEST_F(HelperTest, WeightedArrayElement)
{
    std::vector<Helper::WeightedElement<std::string>> data{{1, "hello"}, {9, "world"}};

    const auto result = Helper::weightedArrayElement(data);

    ASSERT_TRUE(std::ranges::any_of(data, [&result](const Helper::WeightedElement<std::string>& element)
                                    { return result == element.value; }));
}

TEST_F(HelperTest, WeightedArrayZeroSum)
{
    std::vector<Helper::WeightedElement<std::string>> data{{0, "hello"}, {0, "world"}};
    ASSERT_THROW(Helper::weightedArrayElement(data), std::invalid_argument);
}

TEST_F(HelperTest, WeightedArrayEmptyData)
{
    std::vector<Helper::WeightedElement<std::string>> data{};
    ASSERT_THROW(Helper::weightedArrayElement(data), std::invalid_argument);
}

TEST_F(HelperTest, ShuffleString)
{
    std::string input = "Hello World!";

    std::string result = Helper::shuffleString(input);

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
        randomChars.push_back(Helper::setElement(chars));
    }

    for (auto character : randomChars)
    {
        ASSERT_TRUE(chars.find(character) != chars.end());
    }
}

TEST_F(HelperTest, SetElementEmptyData)
{
    std::set<char> chars{};
    ASSERT_THROW(Helper::setElement<char>(chars), std::invalid_argument);
}

TEST_F(HelperTest, ReplaceSymbolWithNumber)
{
    std::string input = "123#456!";
    std::string result = Helper::replaceSymbolWithNumber(input);

    // The result should contain digits instead of '#' and '!'
    ASSERT_TRUE(std::ranges::all_of(result, ::isdigit));
}

TEST_F(HelperTest, RegexpStyleStringParse)
{
    std::string input = "#{5}[2-4]test[1-3]";
    std::string result = Helper::regexpStyleStringParse(input);

    ASSERT_EQ(result.size(), 11);
}

TEST_F(HelperTest, ReplaceCreditCardSymbols)
{
    // Test with the default format "6453-####-####-####-###L"
    std::string result_default = Helper::replaceCreditCardSymbols();
    ASSERT_EQ(result_default.size(), 24);
    ASSERT_EQ(result_default[4], '-');
    ASSERT_EQ(result_default[9], '-');
    ASSERT_EQ(result_default[14], '-');
    ASSERT_EQ(result_default[19], '-');

    // Test with a custom format "1234-[4-9]-##!!-L"
    std::string format_custom = "1234-[4-9]-##!!-L";
    std::string result_custom = Helper::replaceCreditCardSymbols(format_custom);
    std::regex custom_format_regex("1234-[4-9]-\\d{2}[2-9]{2}-\\d");
    ASSERT_TRUE(std::regex_match(result_custom, custom_format_regex));

    // Manually verify the custom format result, as the output is random
    // e.g., "1234-9-5298-2"
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
        int key = Helper::objectKey(testMap);
        EXPECT_TRUE(testMap.find(key) != testMap.end());
    });

    std::unordered_map<int, std::string> emptyMap;

    ASSERT_THROW({ Helper::objectKey(emptyMap); }, std::runtime_error);
}

TEST_F(HelperTest, MaybeString)
{
    double highProbability = 1;
    auto result = Helper::maybe<std::string>([]() { return "Hello World!"; }, highProbability);
    EXPECT_EQ(result, "Hello World!");

    double lowProbability = 0;
    result = Helper::maybe<std::string>([]() { return "Hello World!"; }, lowProbability);
    EXPECT_EQ(result, "");
}

TEST_F(HelperTest, MaybeInt)
{
    double highProbability = 1;
    auto result = Helper::maybe<int>([]() { return 42; }, highProbability);
    EXPECT_EQ(result, 42);

    double lowProbability = 0;
    result = Helper::maybe<int>([]() { return 42; }, lowProbability);
    EXPECT_EQ(result, 0);
}

TEST_F(HelperTest, MaybeDouble)
{
    double highProbability = 1;
    auto result = Helper::maybe<double>([]() { return 3.14; }, highProbability);
    EXPECT_EQ(result, 3.14);

    // Test with low probability to ensure callback is not invoked
    double lowProbability = 0;
    result = Helper::maybe<double>([]() { return 3.14; }, lowProbability);
    EXPECT_EQ(result, 0.0);
}
