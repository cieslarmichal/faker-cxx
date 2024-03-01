#include "../test_helpers.h"
#include <common/formatter.h>

using namespace faker;

TEST(PrecisionMapperTest, precision_format_str)
{
    EXPECT_NE(utils::precision_format_str(precision_t::zero_dp), "");
    EXPECT_NE(utils::precision_format_str(precision_t::one_dp), "");
    EXPECT_NE(utils::precision_format_str(precision_t::two_dp), "");
    EXPECT_NE(utils::precision_format_str(precision_t::three_dp), "");
    EXPECT_NE(utils::precision_format_str(precision_t::four_dp), "");
    EXPECT_NE(utils::precision_format_str(precision_t::five_dp), "");
    EXPECT_NE(utils::precision_format_str(precision_t::six_dp), "");
    EXPECT_NE(utils::precision_format_str(precision_t::seven_dp), "");
}
