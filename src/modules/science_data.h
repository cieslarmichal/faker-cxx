#ifndef FAKER_MODULES_SCIENCE_DATA_H
#define FAKER_MODULES_SCIENCE_DATA_H

#include <array>
#include <faker/science.h>

namespace faker::science::data {
extern const std::array<chemical_element_info, 118> chemical_elements;
extern const std::array<unit_info, 8> distance_units;
extern const std::array<unit_info, 8> mass_units;
extern const std::array<unit_info, 7> time_units;
extern const std::array<unit_info, 3> current_units;
extern const std::array<unit_info, 3> temperature_units;
};

#endif