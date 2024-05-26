
#pragma once

#include <array>
#include <string_view>

namespace faker::phone
{
extern const std::array<std::string_view, 217> areaCodes;
extern const std::array<std::string_view, 6> PhonePlatforms;
extern const std::array<std::string_view, 15> PhoneModelNames;
extern const std::array<std::string_view, 9> PhoneManufacturers;
extern const std::array<std::string_view, 230> phoneNumbers;
}
