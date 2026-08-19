#include "gtest/gtest.h"

#include "faker-cxx/version.h"

using namespace ::testing;

class VersionTest : public Test
{
public:
};

TEST_F(VersionTest, shouldGenerateVersion)
{
    ASSERT_EQ(FAKER_CXX_VERSION_MAJOR, 4);
    ASSERT_EQ(FAKER_CXX_VERSION_MINOR, 4);
    ASSERT_EQ(FAKER_CXX_VERSION_PATCH, 1);
    ASSERT_STREQ(FAKER_CXX_VERSION, "4.4.1");
}
