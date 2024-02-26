#include "../common/helper.h"
#include "medicine_data.h"
#include <faker/medicine.h>

namespace faker::medicine {
std::string_view condition() { return Helper::arrayElement(data::medicalConditions); }

std::string_view medical_test() { return Helper::arrayElement(data::medicalTests); }
std::string_view specialty() { return Helper::arrayElement(data::specialties); }

}
