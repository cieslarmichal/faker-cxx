#ifndef FAKER_COMMON_MAPPERS_PRECISION_MAPPER_PRECISION_MAPPER_H
#define FAKER_COMMON_MAPPERS_PRECISION_MAPPER_PRECISION_MAPPER_H

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

#endif