#include "Generator.h"

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker::number;

class GeneratorTest : public Test
{
public:
};

TEST_F(GeneratorTest, givenInvalidRangeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(integer(10, 2), std::invalid_argument);
}

TEST_F(GeneratorTest, givenRangeWithSameNumberSection_shouldGenerateThisNumber)
{
    const auto actualRandomNumber = integer(2, 2);

    ASSERT_EQ(actualRandomNumber, 2);
}

TEST_F(GeneratorTest, givenValidRangeArguments_shouldGenerateNumberThatIsInGivenRange)
{
    const auto actualRandomNumber = integer(2, 10);

    ASSERT_TRUE(actualRandomNumber >= 2);
    ASSERT_TRUE(actualRandomNumber <= 10);
}
