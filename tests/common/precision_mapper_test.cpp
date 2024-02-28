#include "../test_helpers.h"
#include <common/formatter.h>

using namespace faker;

TEST(PrecisionMapperTest, precision_format_str)
{
    EXPECT_NE(utils::precision_format_str(precision::zero_dp), "");
    EXPECT_NE(utils::precision_format_str(precision::one_dp), "");
    EXPECT_NE(utils::precision_format_str(precision::two_dp), "");
    EXPECT_NE(utils::precision_format_str(precision::three_dp), "");
    EXPECT_NE(utils::precision_format_str(precision::four_dp), "");
    EXPECT_NE(utils::precision_format_str(precision::five_dp), "");
    EXPECT_NE(utils::precision_format_str(precision::six_dp), "");
    EXPECT_NE(utils::precision_format_str(precision::seven_dp), "");
}
