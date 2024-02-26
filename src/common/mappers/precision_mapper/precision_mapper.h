#ifndef FAKER_COMMON_MAPPERS_PRECISION_MAPPER_PRECISION_MAPPER_H
#define FAKER_COMMON_MAPPERS_PRECISION_MAPPER_PRECISION_MAPPER_H

#include <faker/types/precision.h>
#include <string_view>

namespace faker {
class PrecisionMapper {
public:
    static std::string_view mapToFormatString(Precision precision);
    static unsigned mapToDecimalPlaces(Precision precision);
};
}

#endif