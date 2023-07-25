#include "faker-cxx/Datatype.h"

#include <algorithm>

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

class DatatypeTest : public Test
{
public:
};

TEST_F(DatatypeTest, shouldGenerateBoolean)
{
    std::vector<bool> booleanValues{false, true};

    const auto boolean = Datatype::boolean();

    ASSERT_TRUE(std::any_of(booleanValues.begin(), booleanValues.end(),
                            [boolean](bool booleanValue) { return boolean == booleanValue; }));
}

TEST_F(DatatypeTest, BooleanWithProbTest)
{
    bool result2 = Datatype::boolean(0.3);
    EXPECT_TRUE(result2 || !result2);

    bool result3 = Datatype::boolean(0.8);
    EXPECT_TRUE(result3 || !result3);

    bool result4 = Datatype::boolean(0.0);
    EXPECT_FALSE(result4);

    bool result5 = Datatype::boolean(1.0);
    EXPECT_TRUE(result5);
}
