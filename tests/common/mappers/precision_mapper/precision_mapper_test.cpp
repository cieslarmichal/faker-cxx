#include "../../../test_helpers.h"
#include <common/mappers/precision_mapper/precision_mapper.h>

using namespace faker;

TEST(PrecisionMapperTest, mapsPrecisionToDecimalPlaces)
{
    const auto zeroDp = PrecisionMapper::mapToDecimalPlaces(Precision::ZeroDp);
    const auto oneDp = PrecisionMapper::mapToDecimalPlaces(Precision::OneDp);
    const auto twoDp = PrecisionMapper::mapToDecimalPlaces(Precision::TwoDp);
    const auto threeDp = PrecisionMapper::mapToDecimalPlaces(Precision::ThreeDp);
    const auto fourDp = PrecisionMapper::mapToDecimalPlaces(Precision::FourDp);
    const auto fiveDp = PrecisionMapper::mapToDecimalPlaces(Precision::FiveDp);
    const auto sixDp = PrecisionMapper::mapToDecimalPlaces(Precision::SixDp);
    const auto sevenDp = PrecisionMapper::mapToDecimalPlaces(Precision::SevenDp);

    ASSERT_EQ(zeroDp, 0);
    ASSERT_EQ(oneDp, 1);
    ASSERT_EQ(twoDp, 2);
    ASSERT_EQ(threeDp, 3);
    ASSERT_EQ(fourDp, 4);
    ASSERT_EQ(fiveDp, 5);
    ASSERT_EQ(sixDp, 6);
    ASSERT_EQ(sevenDp, 7);
}
