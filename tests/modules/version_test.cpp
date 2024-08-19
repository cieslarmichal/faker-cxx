#include "gtest/gtest.h"

#include "faker-cxx/version.h"

using namespace ::testing;

class VersionTest : public Test
{
public:
};

TEST_F(VersionTest, shouldGenerateVersion)
{
    ASSERT_GE(FAKER_CXX_VERSION_MAJOR, 2);
    ASSERT_GE(FAKER_CXX_VERSION_MINOR, 0);
    ASSERT_GE(FAKER_CXX_VERSION_PATCH, 0);
    ASSERT_TRUE(FAKER_CXX_VERSION);
}
