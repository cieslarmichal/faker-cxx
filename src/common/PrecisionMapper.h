#pragma once

#include <unordered_map>

#include "faker-cxx/types/Precision.h"

namespace faker
{
class PrecisionMapper
{
public:
    static unsigned mapToDecimalPlaces(Precision precision);

private:
    static const std::unordered_map<Precision, unsigned> precisionToDecimalPlacesMapping;
};
}
