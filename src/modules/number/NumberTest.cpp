#include "faker-cxx/Number.h"

#include <algorithm>
#include <functional>

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

class NumberTest : public Test
{
public:
};

TEST_F(NumberTest, givenInvalidRangeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(Number::integer<int>(10, 2), std::invalid_argument);
}

TEST_F(NumberTest, givenRangeWithSameNumberSection_shouldGenerateThisNumber)
{
    const int actualRandomNumber = Number::integer<int>(2, 2);

    ASSERT_EQ(actualRandomNumber, 2);
}

TEST_F(NumberTest, givenValidRangeArguments_shouldGenerateNumberThatIsInGivenRange)
{
    const int actualRandomNumber = Number::integer<int>(2, 10);

    ASSERT_TRUE(actualRandomNumber >= 2);
    ASSERT_TRUE(actualRandomNumber <= 10);
}

TEST_F(NumberTest, givenSingleArgument_shouldCorrectlyResolveToTwoArgsOverload)
{
    const int randomNumber = Number::integer<int>(10);

    ASSERT_TRUE(randomNumber >= 0);
    ASSERT_TRUE(randomNumber <= 10);
}

TEST_F(NumberTest, givenValidRangeArguments_shouldGenerateDecimalNumberThatIsInGivenRange)
{
    const std::floating_point auto actualRandomNumber = Number::decimal<float>(2.f, 10.f);

    ASSERT_TRUE(actualRandomNumber >= 2.f);
    ASSERT_TRUE(actualRandomNumber <= 10.f);
}

TEST_F(NumberTest, givenRangeWithSameNumberSection_shouldGenerateThisNumberForDecimal)
{
    const std::floating_point auto actualRandomNumber = Number::decimal<float>(2.f, 2.f);

    ASSERT_EQ(actualRandomNumber, 2.f);
}

TEST_F(NumberTest, givenDiscreteDistribution_shouldGenerateNumberThatIsInGivenRange)
{
    auto dist = std::binomial_distribution<int>(10, 0.5);

    const int actualRandomNumber = Number::integer<int, std::binomial_distribution<int>>(dist, 2, 10);

    ASSERT_TRUE(actualRandomNumber >= 2);
    ASSERT_TRUE(actualRandomNumber <= 10);
}

TEST_F(NumberTest, givenRealDistribution_shouldGenerateNumberThatIsInGivenRange)
{
    auto dist = std::normal_distribution<float>(5.f, 2.f);

    const std::floating_point auto actualRandomNumber =
        Number::decimal<float, std::normal_distribution<float>>(dist, 2.f, 10.f);

    ASSERT_TRUE(actualRandomNumber >= 2.f);
    ASSERT_TRUE(actualRandomNumber <= 10.f);
}

TEST_F(NumberTest, HexMethodTest)
{

    std::string result = Number::hex();
    std::cout << result << std::endl;
    ASSERT_EQ(result.size(), 1);
    ASSERT_TRUE(std::isxdigit(result[0]));

    result = Number::hex(100, 255);
    std::cout << result << std::endl;
    ASSERT_EQ(result.size(), 2);
    ASSERT_TRUE(std::isxdigit(result[0]));
    ASSERT_TRUE(std::isxdigit(result[1]));

    result = Number::hex(10, 15);
    std::cout << result << std::endl;
    ASSERT_EQ(result.size(), 1);
    ASSERT_TRUE(std::isxdigit(result[0]));

    result = Number::hex(30, 40);
    std::cout << result << std::endl;
    ASSERT_EQ(result.size(), 2);
    ASSERT_TRUE(std::isxdigit(result[0]));
    ASSERT_TRUE(std::isxdigit(result[1]));
}

TEST_F(NumberTest, ConvertToHexMethodTest)
{
    ASSERT_EQ(Number::convertToHex(0), "0");
    ASSERT_EQ(Number::convertToHex(9), "9");
    ASSERT_EQ(Number::convertToHex(10), "a");
    ASSERT_EQ(Number::convertToHex(15), "f");
    ASSERT_EQ(Number::convertToHex(16), "10");
    ASSERT_EQ(Number::convertToHex(255), "ff");
}
