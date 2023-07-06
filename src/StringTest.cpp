#include "String.h"

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

class StringTest : public Test
{
public:
};

TEST_F(StringTest, shouldGenerateUuid4)
{
    const auto uuid = String::uuid();

    ASSERT_EQ(uuid[8], '-');
    ASSERT_EQ(uuid[13], '-');
    ASSERT_EQ(uuid[14], '4');
    ASSERT_EQ(uuid[18], '-');
    ASSERT_EQ(uuid[23], '-');
}
