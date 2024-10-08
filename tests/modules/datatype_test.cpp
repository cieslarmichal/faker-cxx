#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

#include "faker-cxx/datatype.h"

using namespace ::testing;
using namespace faker::datatype;

class DatatypeTest : public Test
{
public:
};

TEST_F(DatatypeTest, shouldGenerateBoolean)
{
    std::vector<bool> booleanValues{false, true};

    const auto generatedBoolean = boolean();

    ASSERT_TRUE(std::ranges::any_of(booleanValues, [generatedBoolean](bool booleanValue)
                                    { return generatedBoolean == booleanValue; }));
}

TEST_F(DatatypeTest, BooleanWithProbTest)
{
    const auto result = boolean(0.3);
    EXPECT_TRUE(result || !result);

    const auto result2 = boolean(0.8);
    EXPECT_TRUE(result2 || !result2);

    const auto result3 = boolean(0.0);
    EXPECT_FALSE(result3);

    const auto result4 = boolean(1.0);
    EXPECT_TRUE(result4);
}
