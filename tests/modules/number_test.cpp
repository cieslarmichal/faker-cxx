#include <stdexcept>

#include "gtest/gtest.h"

#include "faker-cxx/number.h"

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

//NormalDistribution(F, F) function tests

TEST_F(NumberTest, normalDistribution_givenInvalidStandardDeviation_shouldThrowInvalidArgument)
{
    ASSERT_THROW(normalDistribution<float>(10.f, -0.01f), std::invalid_argument);
}

TEST_F(NumberTest, givenStandardDeviationOfINFINITY_shouldThrowInvalidArgument)
{
    ASSERT_THROW(normalDistribution<float>(0.f, INFINITY), std::invalid_argument);
}

TEST_F(NumberTest, givenMeanOfINFINITY_shouldThrowInvalidArgument)
{
    ASSERT_THROW(normalDistribution<float>(INFINITY, 3.f), std::invalid_argument);
}

TEST_F(NumberTest, givenStandardDeviationOf0_shouldGenerateMean)
{
    const std::floating_point auto normalDistributionNumber = normalDistribution<float>(0.f, 0.f);

    ASSERT_EQ(normalDistributionNumber, 0.f);
}

//NormalDistribution(F, F, F, F) tests

TEST_F(NumberTest, givenInvalidRangeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(normalDistribution<float>(10.f, 3.f, 11.f, 10.f), std::invalid_argument);
}

TEST_F(NumberTest, givenValidRangeArguments_shouldGenerateDecimalInGivenRange)
{
    const std::floating_point auto normalDistributionNumber = normalDistribution<float>(10.f, 1000.f, 9.9f, 11.1f);

    ASSERT_TRUE(normalDistributionNumber <= 11.1f);
    ASSERT_TRUE(normalDistributionNumber >= 9.9f);
}

TEST_F(NumberTest, givenRangeWithSameNumberSection_shouldGenerateTheExactNumber)
{
    const std::floating_point auto normalDistributionNumber = normalDistribution<float>(10.f, 1000.f, 12.f, 12.f);

    ASSERT_TRUE(normalDistributionNumber == 12.f);
}

TEST_F(NumberTest, givenHighRange_shouldGenerateMin)
{
    const std::floating_point auto normalDistributionNumber = normalDistribution<float>(-100, .0001f, 10000.f, 10001.f);

    ASSERT_TRUE(normalDistributionNumber == 10000.f);
}

TEST_F(NumberTest, givenHighRange_shouldGenerateMax)
{
    const std::floating_point auto normalDistributionNum = normalDistribution<float>(10000, .0001f, -10001.f, -10000.f);

    ASSERT_TRUE(normalDistributionNum == -10000.f);
}