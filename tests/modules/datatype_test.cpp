#include "../test_helpers.h"
#include <algorithm>
#include <faker/datatype.h>

using namespace ::testing;
using namespace faker;

class DatatypeTest : public Test {
public:
};

TEST_F(DatatypeTest, shouldGenerateBoolean)
{
    std::vector<bool> booleanValues { false, true };

    const auto boolean = datatype::boolean();

    ASSERT_TRUE(faker::testing::any_of(
        booleanValues, [boolean](bool booleanValue) { return boolean == booleanValue; }));
}

TEST_F(DatatypeTest, BooleanWithProbTest)
{
    bool result2 = datatype::boolean(0.3);
    EXPECT_TRUE(result2 || !result2);

    bool result3 = datatype::boolean(0.8);
    EXPECT_TRUE(result3 || !result3);

    bool result4 = datatype::boolean(0.0);
    EXPECT_FALSE(result4);

    bool result5 = datatype::boolean(1.0);
    EXPECT_TRUE(result5);
}
