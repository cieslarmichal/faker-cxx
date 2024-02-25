#include "../test_helpers.h"
#include <common/errors/token_generator_not_found_error.h>
#include <common/format_helper.h>

using namespace faker;

TEST(FormatHelperTest, fillFormatTokensData)
{
    const auto format = "{hello} {faker}-{cxx} {library}";

    const auto result = FormatHelper::fillTokenValues(format, [](std::string_view token) {
        if (token == "hello") {
            return "library";
        } else if (token == "faker") {
            return "cxx";
        } else if (token == "cxx") {
            return "faker";
        } else if (token == "library") {
            return "hello";
        } else {
            return "";
        }
    });

    const auto expectedResult = "library cxx-faker hello";

    EXPECT_EQ(result, expectedResult);
}

TEST(FormatHelperTest, givenTokensWithNotDefinedGenerator_shouldThrow)
{
    const auto format = "{hello} {faker}-{cxx} {library}";

    ASSERT_THROW(FormatHelper::fillTokenValues(format,
        [](std::string_view token) {
            if (token == "hello") {
                return "library";
            } else if (token == "faker") {
                return "cxx";
            } else if (token == "cxx") {
                return "faker";
            } else {
                throw errors::TokenGeneratorNotFoundError { FormatHelper::format(
                    "Generator not found for token {}.", token) };
            }
        });
                 , errors::TokenGeneratorNotFoundError);
}

TEST(FormatHelperTest, shouldFormat)
{
    EXPECT_EQ(FormatHelper::format("{}", 1), "1");
    EXPECT_EQ(FormatHelper::format("{} {}", "Hello", "World"), "Hello World");
    EXPECT_EQ(FormatHelper::format("{0} {1}", "Hello", "World"), "Hello World");
}