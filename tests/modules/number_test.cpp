#include "../test_helpers.h"
#include <algorithm>
#include <faker/number.h>

using namespace faker;

TEST(NumberTest, integer_givenInvalidRangeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(number::integer(10, 2), std::invalid_argument);
}

TEST(NumberTest, givenRangeWithSameNumbers_shouldGenerateThisNumber)
{
    const int actualRandomNumber = number::integer(2, 2);

    ASSERT_EQ(actualRandomNumber, 2);
}

TEST(NumberTest, givenValidRange_shouldGenerateNumberWithinGivenRange)
{
    const int actualRandomNumber = number::integer(2, 10);

    ASSERT_TRUE(actualRandomNumber >= 2);
    ASSERT_TRUE(actualRandomNumber <= 10);
}

TEST(NumberTest, givenSingleArgument_shouldCorrectlyResolveToTwoArgsOverload)
{
    const int randomNumber = number::integer(10);

    ASSERT_TRUE(randomNumber >= 0);
    ASSERT_TRUE(randomNumber <= 10);
}

TEST(NumberTest, decimal_givenInvalidRangeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(number::decimal(10.f, 2.f), std::invalid_argument);
}

TEST(NumberTest, givenValidRangeArguments_shouldGenerateDecimalNumberThatIsInGivenRange)
{
    const auto actualRandomNumber = number::decimal(2.f, 10.f);

    ASSERT_TRUE(actualRandomNumber >= 2.f);
    ASSERT_TRUE(actualRandomNumber <= 10.f);
}

TEST(NumberTest, givenRangeWithSameNumberSection_shouldGenerateThisNumberForDecimal)
{
    const auto actualRandomNumber = number::decimal(2.f, 2.f);

    ASSERT_EQ(actualRandomNumber, 2.f);
}

TEST(NumberTest, shouldGenerateHexNumber)
{
    auto result = number::hex();
    ASSERT_EQ(result.size(), 1);
    ASSERT_TRUE(std::isxdigit(result[0]));

    result = number::hex(100, 255);
    ASSERT_EQ(result.size(), 2);
    ASSERT_TRUE(std::isxdigit(result[0]));
    ASSERT_TRUE(std::isxdigit(result[1]));

    result = number::hex(10, 15);
    ASSERT_EQ(result.size(), 1);
    ASSERT_TRUE(std::isxdigit(result[0]));

    result = number::hex(30, 40);
    ASSERT_EQ(result.size(), 2);
    ASSERT_TRUE(std::isxdigit(result[0]));
    ASSERT_TRUE(std::isxdigit(result[1]));
}
