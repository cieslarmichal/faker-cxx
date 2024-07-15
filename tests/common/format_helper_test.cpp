#include "format_helper.h"

#include <functional>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "gtest/gtest.h"

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

TEST_F(FormatHelperTest, ThrowsExceptionForMissingTokenGenerator)
{
    const auto format = "{existing} {missing}";
    const auto dataGeneratorsMapping = std::unordered_map<std::string, std::function<std::string()>>{
        {"existing", []() { return "value"; }}
    };

    try {
        fillTokenValues(format, dataGeneratorsMapping);
        FAIL() << "Expected std::runtime_error";
    }
    catch (const std::runtime_error& e) {
        EXPECT_STREQ(e.what(), "Generator not found for token missing.");
    }
}

TEST_F(FormatHelperTest, PrecisionFormat)
{
    EXPECT_EQ(precisionFormat(Precision::ZeroDp, 3.14159), "3");
    EXPECT_EQ(precisionFormat(Precision::OneDp, 3.14159), "3.1");
    EXPECT_EQ(precisionFormat(Precision::FiveDp, 3.14159), "3.14159");
    EXPECT_EQ(precisionFormat(Precision::SevenDp, 3.14159), "3.1415900");
}

TEST_F(FormatHelperTest, ThrowsForInvalidPrecision)
{
    EXPECT_THROW(precisionFormat(static_cast<Precision>(999), 3.14159), std::invalid_argument);
}