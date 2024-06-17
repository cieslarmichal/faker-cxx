#include "LuhnCheck.h"

#include <string>

#include "gtest/gtest.h"

using namespace faker;

TEST(LuhnCheckTest, BasicTest)
{
    std::string input = "6453-4876-8626-8995-3771";
    bool result = LuhnCheck::luhnCheck(input);
    EXPECT_TRUE(result);
}

TEST(LuhnCheckValueTest, BasicTest)
{
    std::string input = "6453-4876-8626-8995-377L";
    int result = LuhnCheck::luhnCheckValue(input);
    EXPECT_EQ(result, 1);
}
