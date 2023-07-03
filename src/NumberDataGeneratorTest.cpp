#include "NumberDataGenerator.h"

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker::number;

class NumberDataGeneratorTest : public Test
{
public:
};

TEST_F(NumberDataGeneratorTest, givenInvalidRangeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(NumberDataGenerator::integer(10, 2), std::invalid_argument);
}

TEST_F(NumberDataGeneratorTest, givenRangeWithSameNumberSection_shouldGenerateThisNumber)
{
    const auto actualRandomNumber = NumberDataGenerator::integer(2, 2);

    ASSERT_EQ(actualRandomNumber, 2);
}

TEST_F(NumberDataGeneratorTest, givenValidRangeArguments_shouldGenerateNumberThatIsInGivenRange)
{
    const auto actualRandomNumber = NumberDataGenerator::integer(2, 10);

    ASSERT_TRUE(actualRandomNumber >= 2);
    ASSERT_TRUE(actualRandomNumber <= 10);
}
