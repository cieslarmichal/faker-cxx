#pragma once

#include <array>

#include "faker-cxx/Science.h"

namespace faker
{
extern const std::array<Science::ChemicalElement, 118> chemicalElements;
extern const std::array<Science::Unit, 8> distanceUnits;
extern const std::array<Science::Unit, 8> massUnits;
extern const std::array<Science::Unit, 7> timeUnits;
extern const std::array<Science::Unit, 3> currentUnits;
extern const std::array<Science::Unit, 3> temperatureUnits;
}
