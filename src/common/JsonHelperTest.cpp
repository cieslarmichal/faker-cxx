#include "JsonHelper.h"

#include <algorithm>

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

class JsonHelperTest : public Test
{
public:
};

TEST_F(JsonHelperTest, simpleJsonParser)
{
    const auto result = JsonHelper::simpleJsonParser("{\"Test1\":\"Hello\",\"Test2\":\"World!\"}");

    const auto key1 = result.find("Test1")->first;
    const auto key2 = result.find("Test2")->first;
    const auto value1 = result.find("Test1")->second;
    const auto value2 = result.find("Test2")->second;

    ASSERT_EQ(key1, "Test1");
    ASSERT_EQ(key2, "Test2");
    ASSERT_EQ(value1, "Hello");
    ASSERT_EQ(value2, "World!");
}