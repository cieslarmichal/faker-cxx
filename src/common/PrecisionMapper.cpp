#include "PrecisionMapper.h"

namespace faker
{
const std::map<Precision, unsigned> PrecisionMapper::precisionToDecimalPlacesMapping{
    {Precision::ZeroDp, 0}, {Precision::OneDp, 1},  {Precision::TwoDp, 2}, {Precision::ThreeDp, 3},
    {Precision::FourDp, 4}, {Precision::FiveDp, 5}, {Precision::SixDp, 6}, {Precision::SevenDp, 7}};

unsigned PrecisionMapper::mapToDecimalPlaces(Precision precision)
{
    return precisionToDecimalPlacesMapping.at(precision);
}
}
