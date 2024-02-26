#ifndef FAKER_MODULES_COMPUTER_DATA_H
#define FAKER_MODULES_COMPUTER_DATA_H

#include <array>
#include <string_view>

namespace faker::computer::data {
extern const std::array<std::string_view, 4> ComputerTypes;
extern const std::array<std::string_view, 20> ComputerManufactures;
extern const std::array<std::string_view, 45> ComputerModels;
extern const std::array<std::string_view, 5> ComputerCPUManufactures;
extern const std::array<std::string_view, 12> ComputerCPUTypes;
extern const std::array<std::string_view, 26> ComputerCPUModels;
extern const std::array<std::string_view, 5> ComputerGPUManufactures;
extern const std::array<std::string_view, 2> ComputerGPUTypes;
extern const std::array<std::string_view, 23> ComputerGPUModels;
}

#endif