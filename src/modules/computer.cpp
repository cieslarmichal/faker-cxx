#include "../common/random.h"
#include "computer_data.h"
#include <faker/computer.h>

namespace faker::computer {

std::string_view type() { return random::element(data::ComputerTypes); }

std::string_view manufacture() { return random::element(data::ComputerManufactures); }

std::string_view model() { return random::element(data::ComputerModels); }

std::string_view cpu_manufacturer() { return random::element(data::ComputerCPUManufactures); }

std::string_view cpu_type() { return random::element(data::ComputerCPUTypes); }

std::string_view cpu_model() { return random::element(data::ComputerCPUModels); }

std::string_view gpu_manufacturer() { return random::element(data::ComputerGPUManufactures); }

std::string_view gpu_type() { return random::element(data::ComputerGPUTypes); }

std::string_view gpu_model() { return random::element(data::ComputerGPUModels); }
}
