#include "../test_helpers.h"
#include <common/formatter.h>

using namespace faker;

TEST(PrecisionMapperTest, precision_format_str)
{
    EXPECT_NE(utils::precision_format_str(Precision::ZeroDp), "");
    EXPECT_NE(utils::precision_format_str(Precision::OneDp), "");
    EXPECT_NE(utils::precision_format_str(Precision::TwoDp), "");
    EXPECT_NE(utils::precision_format_str(Precision::ThreeDp), "");
    EXPECT_NE(utils::precision_format_str(Precision::FourDp), "");
    EXPECT_NE(utils::precision_format_str(Precision::FiveDp), "");
    EXPECT_NE(utils::precision_format_str(Precision::SixDp), "");
    EXPECT_NE(utils::precision_format_str(Precision::SevenDp), "");
}
