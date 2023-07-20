#include "faker-cxx/Helper.h"
#include "gtest/gtest.h"
#include <regex>

using namespace faker;
using namespace ::testing;

class HelperTest : public Test
{
};

namespace
{

TEST_F(HelperTest, ReplaceSymbolWithNumber)
{
    std::string input = "123#456!";
    std::string result = Helper::replaceSymbolWithNumber(input);

    // The result should contain digits instead of '#' and '!'
    ASSERT_TRUE(std::all_of(result.begin(), result.end(), ::isdigit));
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
}