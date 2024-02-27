#include "../test_helpers.h"
#include <common/formatter.h>
#include <stdexcept>

using namespace faker;

namespace faker::errors {
struct TokenGeneratorNotFoundError : std::runtime_error {
    using std::runtime_error::runtime_error;
};
}

TEST(FormatHelperTest, fillFormatTokensData)
{
    const auto format = "{hello} {faker}-{cxx} {library}";

    const auto result = utils::fill_token_values(format, [](std::string_view token) {
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

    ASSERT_THROW(utils::fill_token_values(format,
        [](std::string_view token) {
            if (token == "hello") {
                return "library";
            } else if (token == "faker") {
                return "cxx";
            } else if (token == "cxx") {
                return "faker";
            } else {
                throw errors::TokenGeneratorNotFoundError { utils::format(
                    "Generator not found for token {}.", token) };
            }
        });
                 , errors::TokenGeneratorNotFoundError);
}

TEST(FormatHelperTest, shouldFormat)
{
    EXPECT_EQ(utils::format("{}", 1), "1");
    EXPECT_EQ(utils::format("{} {}", "Hello", "World"), "Hello World");
    EXPECT_EQ(utils::format("{0} {1}", "Hello", "World"), "Hello World");
}