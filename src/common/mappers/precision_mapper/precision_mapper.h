#pragma once

#include <faker/types/precision.h>
#include <unordered_map>

namespace faker {
class PrecisionMapper {
public:
    static unsigned mapToDecimalPlaces(Precision precision);

private:
    static const std::unordered_map<Precision, unsigned> precisionToDecimalPlacesMapping;
};
}
