#include "common/PrecisionMapper.h"

#include <gtest/gtest.h>

#include "faker-cxx/types/Precision.h"

using namespace ::testing;
using namespace faker;

class PrecisionMapperTest : public Test
{
public:
};

TEST_F(PrecisionMapperTest, mapsPrecisionToDecimalPlaces)
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
