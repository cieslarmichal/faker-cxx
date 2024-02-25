#pragma once

#include <faker/types/unit.h>
#include <array>
#include <faker/types/chemical_element.h>

namespace faker {
extern const std::array<ChemicalElement, 118> chemicalElements;
extern const std::array<Unit, 8> distanceUnits;
extern const std::array<Unit, 8> massUnits;
extern const std::array<Unit, 7> timeUnits;
extern const std::array<Unit, 3> currentUnits;
extern const std::array<Unit, 3> temperatureUnits;
};
