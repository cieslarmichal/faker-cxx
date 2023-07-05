#include "Number.h"

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
    const auto actualRandomNumber = Number::integer<int>(2, 2);

    ASSERT_EQ(actualRandomNumber, 2);
}

TEST_F(NumberTest, givenValidRangeArguments_shouldGenerateNumberThatIsInGivenRange)
{
    const auto actualRandomNumber = Number::integer<int>(2, 10);

    ASSERT_TRUE(actualRandomNumber >= 2);
    ASSERT_TRUE(actualRandomNumber <= 10);
}

TEST_F(NumberTest, givenSingleArgument_shouldCorrectlyResolveToTwoArgsOverload)
{
    const auto randomNumber = Number::integer<int>(10);


    ASSERT_TRUE(randomNumber >= 0);
    ASSERT_TRUE(randomNumber <= 10);
}