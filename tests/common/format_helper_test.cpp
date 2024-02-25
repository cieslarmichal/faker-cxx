#include "../test_helpers.h"
#include <common/errors/token_generator_not_found_error.h>
#include <common/format_helper.h>

using namespace ::testing;
using namespace faker;

class FormatHelperTest : public Test {
public:
};

TEST_F(FormatHelperTest, fillFormatTokensData)
{
    const auto format = "{hello} {faker}-{cxx} {library}";

    const auto dataGeneratorsMapping
        = std::unordered_map<std::string, std::function<std::string()>> {
              { "hello", []() { return "library"; } }, { "faker", []() { return "cxx"; } },
              { "cxx", []() { return "faker"; } }, { "library", []() { return "hello"; } }
          };

    const auto result = FormatHelper::fillTokenValues(format, dataGeneratorsMapping);

    const auto expectedResult = "library cxx-faker hello";

    EXPECT_EQ(result, expectedResult);
}

TEST_F(FormatHelperTest, givenTokensWithNotDefinedGenerator_shouldThrow)
{
    const auto format = "{hello} {faker}-{cxx} {library}";

    const auto dataGeneratorsMapping
        = std::unordered_map<std::string, std::function<std::string()>> {
              { "hello", []() { return "library"; } }, { "faker", []() { return "cxx"; } },
              { "cxx", []() { return "faker"; } }
          };

    ASSERT_THROW(FormatHelper::fillTokenValues(format, dataGeneratorsMapping),
        errors::TokenGeneratorNotFoundError);
}

TEST_F(FormatHelperTest, shouldFormat)
{
    EXPECT_EQ(FormatHelper::format("{}", 1), "1");
    EXPECT_EQ(FormatHelper::format("{} {}", "Hello", "World"), "Hello World");
    EXPECT_EQ(FormatHelper::format("{0} {1}", "Hello", "World"), "Hello World");
}