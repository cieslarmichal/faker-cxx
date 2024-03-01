#include "../test_helpers.h"
#include <common/formatter.h>

using namespace faker;

TEST(PrecisionMapperTest, precision_format_str)
{
    EXPECT_EQ(utils::precision_format(precision_t::zero_dp, 1.2345678), "1");
    EXPECT_EQ(utils::precision_format(precision_t::one_dp, 1.2345678), "1.2");
    EXPECT_EQ(utils::precision_format(precision_t::two_dp, 1.2345678), "1.23");
    EXPECT_EQ(utils::precision_format(precision_t::three_dp, 1.2345678), "1.235");
    EXPECT_EQ(utils::precision_format(precision_t::four_dp, 1.2345678), "1.2346");
    EXPECT_EQ(utils::precision_format(precision_t::five_dp, 1.2345678), "1.23457");
    EXPECT_EQ(utils::precision_format(precision_t::six_dp, 1.2345678), "1.234568");
    EXPECT_EQ(utils::precision_format(precision_t::seven_dp, 1.2345678), "1.2345678");
}
