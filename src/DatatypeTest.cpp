#include "include/faker-cxx/Datatype.h"

#include "gtest/gtest.h"
#include <algorithm>

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
