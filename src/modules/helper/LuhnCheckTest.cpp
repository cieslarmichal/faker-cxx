#include <gtest/gtest.h>
#include <string>
#include "faker-cxx/LuhnCheck.h"

using namespace faker;

TEST(LuhnCheckTest, BasicTest) {
    std::string input = "6453-4876-8626-8995-3771";
    bool result = LuhnCheck::luhnCheck(input);
    EXPECT_TRUE(result); // Replace true with the expected result for the given input.
}

TEST(LuhnCheckValueTest, BasicTest) {
    std::string input = "6453-4876-8626-8995-377L";
    int result = LuhnCheck::luhnCheckValue(input);
    EXPECT_EQ(result, 1); // Replace 1 with the expected result for the given input.
}
