#include "faker-cxx/Medicine.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "MedicineData.h"

namespace faker::medicine
{
std::string_view condition()
{
    return Helper::arrayElement(medicalConditions);
}

std::string_view medicalTest()
{
    return Helper::arrayElement(medicalTests);
}

std::string_view specialty()
{
    return Helper::arrayElement(specialties);
}

}
