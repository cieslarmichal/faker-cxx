#include "precision_mapper.h"
#include <stdexcept>

namespace faker {

std::string_view PrecisionMapper::mapToFormatString(Precision precision)
{
    switch (precision) {
    case Precision::ZeroDp:
        return "{:.0f}";
    case Precision::OneDp:
        return "{:.1f}";
    case Precision::TwoDp:
        return "{:.2f}";
    case Precision::ThreeDp:
        return "{:.3f}";
    case Precision::FourDp:
        return "{:.4f}";
    case Precision::FiveDp:
        return "{:.5f}";
    case Precision::SixDp:
        return "{:.6f}";
    case Precision::SevenDp:
        return "{:.7f}";
    default:
        throw std::invalid_argument("Invalid precision");
    }
}

unsigned PrecisionMapper::mapToDecimalPlaces(Precision precision)
{
    switch (precision) {
    case Precision::ZeroDp:
        return 0;
    case Precision::OneDp:
        return 1;
    case Precision::TwoDp:
        return 2;
    case Precision::ThreeDp:
        return 3;
    case Precision::FourDp:
        return 4;
    case Precision::FiveDp:
        return 5;
    case Precision::SixDp:
        return 6;
    case Precision::SevenDp:
        return 7;
    default:
        throw std::invalid_argument("Invalid precision");
    }
}
}
