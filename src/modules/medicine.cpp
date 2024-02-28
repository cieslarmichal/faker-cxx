#include "../common/random.h"
#include "medicine_data.h"
#include <faker/medicine.h>

namespace faker::medicine {
std::string_view condition() { return random::element(data::medical_conditions); }

std::string_view medical_test() { return random::element(data::medical_tests); }

std::string_view specialty() { return random::element(data::specialties); }

}
