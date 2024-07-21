#include "faker-cxx/number.h"

#include <stdexcept>

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;
using namespace faker::number;

class NumberTest : public Test
{
public:
};

TEST_F(NumberTest, integer_givenInvalidRangeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(integer<int>(10, 2), std::invalid_argument);
}

TEST_F(NumberTest, givenRangeWithSameNumbers_shouldGenerateThisNumber)
{
    const int actualRandomNumber = integer<int>(2, 2);

    ASSERT_EQ(actualRandomNumber, 2);
}

TEST_F(NumberTest, givenValidRange_shouldGenerateNumberWithinGivenRange)
{
    const int actualRandomNumber = integer<int>(2, 10);

    ASSERT_TRUE(actualRandomNumber >= 2);
    ASSERT_TRUE(actualRandomNumber <= 10);
}

TEST_F(NumberTest, givenSingleArgument_shouldCorrectlyResolveToTwoArgsOverload)
{
    const int randomNumber = integer<int>(10);

    ASSERT_TRUE(randomNumber >= 0);
    ASSERT_TRUE(randomNumber <= 10);
}

TEST_F(NumberTest, decimal_givenInvalidRangeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(decimal<float>(10.f, 2.f), std::invalid_argument);
}

TEST_F(NumberTest, givenValidRangeArguments_shouldGenerateDecimalNumberThatIsInGivenRange)
{
    const std::floating_point auto actualRandomNumber = decimal<float>(2.f, 10.f);

    ASSERT_TRUE(actualRandomNumber >= 2.f);
    ASSERT_TRUE(actualRandomNumber <= 10.f);
}

TEST_F(NumberTest, givenRangeWithSameNumberSection_shouldGenerateThisNumberForDecimal)
{
    const std::floating_point auto actualRandomNumber = decimal<float>(2.f, 2.f);

    ASSERT_EQ(actualRandomNumber, 2.f);
}
