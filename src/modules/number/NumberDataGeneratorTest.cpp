#include "NumberDataGenerator.h"

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker::number;

namespace
{
constexpr int rangeStart{2};
constexpr int rangeEnd{10};
}

class NumberDataGeneratorTest : public Test
{
public:
};

TEST_F(NumberDataGeneratorTest, givenInvalidRangeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(NumberDataGenerator::integer(rangeEnd, rangeStart), std::invalid_argument);
}

TEST_F(NumberDataGeneratorTest, givenRangeWithSameNumberSection_shouldGenerateThisNumber)
{
    const auto actualRandomNumber = NumberDataGenerator::integer(2, 2);

    ASSERT_EQ(actualRandomNumber, 2);
}

TEST_F(NumberDataGeneratorTest, givenValidRangeArguments_shouldGenerateNumberThatIsInGivenRange)
{
    const auto actualRandomNumber = NumberDataGenerator::integer(rangeStart, rangeEnd);

    ASSERT_TRUE(actualRandomNumber >= rangeStart);
    ASSERT_TRUE(actualRandomNumber <= rangeEnd);
}
