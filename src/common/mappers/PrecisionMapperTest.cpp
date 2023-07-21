#include "PrecisionMapper.h"

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

class PrecisionMapperTest : public Test
{
public:
};

TEST_F(PrecisionMapperTest, mapsPrecisionToDecimalPlaces)
{
    const auto zeroDp = PrecisionMapper::toDecimalPlaces(Precision::ZeroDp);
    const auto oneDp = PrecisionMapper::toDecimalPlaces(Precision::OneDp);
    const auto twoDp = PrecisionMapper::toDecimalPlaces(Precision::TwoDp);
    const auto threeDp = PrecisionMapper::toDecimalPlaces(Precision::ThreeDp);
    const auto fourDp = PrecisionMapper::toDecimalPlaces(Precision::FourDp);
    const auto fiveDp = PrecisionMapper::toDecimalPlaces(Precision::FiveDp);
    const auto sixDp = PrecisionMapper::toDecimalPlaces(Precision::SixDp);
    const auto sevenDp = PrecisionMapper::toDecimalPlaces(Precision::SevenDp);

    ASSERT_EQ(zeroDp, 0);
    ASSERT_EQ(oneDp, 1);
    ASSERT_EQ(twoDp, 2);
    ASSERT_EQ(threeDp, 3);
    ASSERT_EQ(fourDp, 4);
    ASSERT_EQ(fiveDp, 5);
    ASSERT_EQ(sixDp, 6);
    ASSERT_EQ(sevenDp, 7);
}
