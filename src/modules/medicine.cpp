#include "medicine_data.h"
#include <faker/helper.h>
#include <faker/medicine.h>

namespace faker::medicine {
std::string_view condition() { return Helper::arrayElement(data::medicalConditions); }

std::string_view medicalTest() { return Helper::arrayElement(data::medicalTests); }
std::string_view specialty() { return Helper::arrayElement(data::specialties); }

}
