#include "../test_helpers.h"
#include <algorithm>
#include <common/random.h>
#include <faker/string.h>
#include <regex>
#include <stdexcept>
#include <unordered_map>
#include <vector>

using namespace faker;

TEST(HelperTest, ArrayElement)
{
    std::vector<std::string> data { "hello", "world" };

    std::string result = random::element(data);

    ASSERT_TRUE(faker::testing::any_of(
        data, [&result](const std::string& element) { return result == element; }));
}

TEST(HelperTest, ArrayElementEmptyData)
{
    std::vector<std::string> data {};

    ASSERT_THROW(random::element(data), std::invalid_argument);
}

TEST(HelperTest, ArrayElementSpan)
{
    std::vector<std::string> data { "hello", "world" };

    std::string result = random::element(data);

    ASSERT_TRUE(faker::testing::any_of(
        data, [&result](const std::string& element) { return result == element; }));
}

TEST(HelperTest, ArrayElementSpanEmptyData)
{
    std::vector<std::string> data {};

    ASSERT_THROW(random::element(data), std::invalid_argument);
}

TEST(HelperTest, WeightedArrayElement)
{
    std::vector<random::WeightedElement<std::string>> data { { 1, "hello" }, { 9, "world" } };

    const auto result = random::weighted_element(data);

    ASSERT_TRUE(faker::testing::any_of(
        data, [&result](const random::WeightedElement<std::string>& element) {
            return result == element.value;
        }));
}

TEST(HelperTest, WeightedArrayZeroSum)
{
    std::vector<random::WeightedElement<std::string>> data { { 0, "hello" }, { 0, "world" } };
    ASSERT_THROW(random::weighted_element(data), std::invalid_argument);
}

TEST(HelperTest, WeightedArrayEmptyData)
{
    std::vector<random::WeightedElement<std::string>> data {};
    ASSERT_THROW(random::weighted_element(data), std::invalid_argument);
}

TEST(HelperTest, ShuffleString)
{
    std::string input = "Hello World!";

    std::string result = random::shuffle_string(input);

    ASSERT_TRUE(faker::testing::all_of(
        input, [&result](char character) { return result.find(character) != std::string::npos; }));
}

TEST(HelperTest, SetElement)
{
    std::unordered_set<char> chars { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'l', 'm' };

    std::vector<char> randomChars;

    randomChars.reserve(30);

    for (int i = 0; i < 30; ++i) {
        randomChars.push_back(random::element_from_set(chars));
    }

    for (auto character : randomChars) {
        ASSERT_TRUE(chars.find(character) != chars.end());
    }
}

TEST(HelperTest, SetElementEmptyData)
{
    std::unordered_set<char> chars {};
    ASSERT_THROW(random::element_from_set(chars), std::invalid_argument);
}

TEST(HelperTest, ReplaceSymbolWithNumber)
{
    std::string input = "123#456!";
    std::string result = random::replace_symbol_with_number(input);

    // The result should contain digits instead of '#' and '!'
    ASSERT_TRUE(faker::testing::all_of(result, ::isdigit));
}

TEST(HelperTest, RegexpStyleStringParse)
{
    std::string input = "#{5}[2-4]test[1-3]";
    std::string result = random::regexp_style_string_parse(input);

    ASSERT_EQ(result.size(), 11);
}

TEST(HelperTest, ReplaceCreditCardSymbols)
{
    // Test with the default format "6453-####-####-####-###L"
    std::string result_default = random::replace_credit_card_symbols();
    ASSERT_EQ(result_default.size(), 24);
    ASSERT_EQ(result_default[4], '-');
    ASSERT_EQ(result_default[9], '-');
    ASSERT_EQ(result_default[14], '-');
    ASSERT_EQ(result_default[19], '-');

    // Test with a custom format "1234-[4-9]-##!!-L"
    std::string format_custom = "1234-[4-9]-##!!-L";
    std::string result_custom = random::replace_credit_card_symbols(format_custom);
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

TEST(HelperTest, ObjectKeyTest)
{
    std::unordered_map<int, std::string> testMap = { { 1, "one" }, { 2, "two" }, { 3, "three" } };

    ASSERT_NO_THROW({
        int key = random::map_key(testMap);
        EXPECT_TRUE(testMap.find(key) != testMap.end());
    });

    std::unordered_map<int, std::string> emptyMap;

    ASSERT_THROW({ random::map_key(emptyMap); }, std::runtime_error);
}
