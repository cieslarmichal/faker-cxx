#ifndef FAKER_MODULES_MEDICINE_DATA_H
#define FAKER_MODULES_MEDICINE_DATA_H

#include <array>
#include <string_view>

namespace faker::medicine::data {
extern const std::array<std::string_view, 59> medical_conditions;
extern const std::array<std::string_view, 35> medical_tests;
extern const std::array<std::string_view, 55> specialties;
}

#endif