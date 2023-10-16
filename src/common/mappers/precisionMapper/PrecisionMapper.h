#pragma once

#include "faker-cxx/types/Precision.h"

namespace faker
{
class PrecisionMapper
{
public:
    static unsigned mapToDecimalPlaces(Precision precision);

private:
    static const std::map<Precision, unsigned> precisionToDecimalPlacesMapping;
};
}
