#include "computer_data.h"
#include <faker/computer.h>
#include <faker/helper.h>

namespace faker::computer {

std::string_view type() { return Helper::arrayElement(data::ComputerTypes); }

std::string_view manufacture() { return Helper::arrayElement(data::ComputerManufactures); }

std::string_view model() { return Helper::arrayElement(data::ComputerModels); }

std::string_view cpuManufacture() { return Helper::arrayElement(data::ComputerCPUManufactures); }

std::string_view cpuType() { return Helper::arrayElement(data::ComputerCPUTypes); }

std::string_view cpuModel() { return Helper::arrayElement(data::ComputerCPUModels); }

std::string_view gpuManufacture() { return Helper::arrayElement(data::ComputerGPUManufactures); }

std::string_view gpuType() { return Helper::arrayElement(data::ComputerGPUTypes); }

std::string_view gpuModel() { return Helper::arrayElement(data::ComputerGPUModels); }
}
