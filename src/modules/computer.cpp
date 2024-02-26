#include "../common/helper.h"
#include "computer_data.h"
#include <faker/computer.h>

namespace faker::computer {

std::string_view type() { return Helper::arrayElement(data::ComputerTypes); }

std::string_view manufacture() { return Helper::arrayElement(data::ComputerManufactures); }

std::string_view model() { return Helper::arrayElement(data::ComputerModels); }

std::string_view cpu_manufacturer() { return Helper::arrayElement(data::ComputerCPUManufactures); }

std::string_view cpu_type() { return Helper::arrayElement(data::ComputerCPUTypes); }

std::string_view cpu_model() { return Helper::arrayElement(data::ComputerCPUModels); }

std::string_view gpu_manufacturer() { return Helper::arrayElement(data::ComputerGPUManufactures); }

std::string_view gpu_type() { return Helper::arrayElement(data::ComputerGPUTypes); }

std::string_view gpu_model() { return Helper::arrayElement(data::ComputerGPUModels); }
}
