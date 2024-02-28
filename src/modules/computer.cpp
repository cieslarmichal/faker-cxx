#include "../common/random.h"
#include "computer_data.h"
#include <faker/computer.h>

namespace faker::computer {

std::string_view type() { return random::element(data::types); }

std::string_view manufacturer() { return random::element(data::manufacturers); }

std::string_view model() { return random::element(data::models); }

std::string_view cpu_manufacturer() { return random::element(data::cpu_manufacturers); }

std::string_view cpu_type() { return random::element(data::cpu_types); }

std::string_view cpu_model() { return random::element(data::cpu_models); }

std::string_view gpu_manufacturer() { return random::element(data::gpu_manufacturers); }

std::string_view gpu_type() { return random::element(data::gpu_types); }

std::string_view gpu_model() { return random::element(data::gpu_models); }
}
