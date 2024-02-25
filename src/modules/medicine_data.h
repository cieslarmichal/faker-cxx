#ifndef FAKER_MODULES_MEDICINE_DATA_H
#define FAKER_MODULES_MEDICINE_DATA_H

#include <array>
#include <string_view>

namespace faker {
extern const std::array<std::string_view, 59> medicalConditions;
extern const std::array<std::string_view, 35> medicalTests;
extern const std::array<std::string_view, 55> specialties;
}

#endif