#pragma once

#include <map>

namespace faker
{
enum class Precision
{
    ZeroDp,
    OneDp,
    TwoDp,
    ThreeDp,
    FourDp,
    FiveDp,
    SixDp,
    SevenDp
};

inline unsigned toDecimalPlaces(Precision precision)
{
    const std::map<Precision, unsigned> precisionToDecimalPlacesMapping{
        {Precision::ZeroDp, 0}, {Precision::OneDp, 1},  {Precision::TwoDp, 2}, {Precision::ThreeDp, 3},
        {Precision::FourDp, 4}, {Precision::FiveDp, 5}, {Precision::SixDp, 6}, {Precision::SevenDp, 7}};

    return precisionToDecimalPlacesMapping.at(precision);
}
}
