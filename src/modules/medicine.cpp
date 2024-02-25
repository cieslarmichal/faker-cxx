#include "medicine_data.h"
#include <faker/helper.h>
#include <faker/medicine.h>

namespace faker::medicine {
std::string_view condition() { return Helper::arrayElement(medicalConditions); }

std::string_view medicalTest() { return Helper::arrayElement(medicalTests); }
std::string_view specialty() { return Helper::arrayElement(specialties); }

}
