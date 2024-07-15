#include <stdexcept>
#include <string>
#include <unordered_map>

#include "gtest/gtest.h"

#include "format_helper.h"

using namespace ::testing;
using namespace faker;
using namespace faker::common;

class FormatHelperTest : public Test
{
public:
};

TEST_F(FormatHelperTest, fillFormatTokensData)
{
    const auto format = "{hello} {faker}-{cxx} {library}";

    const auto dataGeneratorsMapping =
        std::unordered_map<std::string, std::function<std::string()>>{{"hello", []() { return "library"; }},
                                                                      {"faker", []() { return "cxx"; }},
                                                                      {"cxx", []() { return "faker"; }},
                                                                      {"library", []() { return "hello"; }}};

    const auto result = fillTokenValues(format, dataGeneratorsMapping);

    const auto expectedResult = "library cxx-faker hello";

    EXPECT_EQ(result, expectedResult);
}

TEST_F(FormatHelperTest, givenTokensWithNotDefinedGenerator_shouldThrow)
{
    const auto format = "{hello} {faker}-{cxx} {library}";

    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"hello", []() { return "library"; }}, {"faker", []() { return "cxx"; }}, {"cxx", []() { return "faker"; }}};

    ASSERT_THROW(fillTokenValues(format, dataGeneratorsMapping), std::runtime_error);
}

TEST_F(FormatHelperTest, shouldFormat)
{
    EXPECT_EQ(format("{}", 1), "1");
    EXPECT_EQ(format("{} {}", "Hello", "World"), "Hello World");
    EXPECT_EQ(format("{0} {1}", "Hello", "World"), "Hello World");
}
