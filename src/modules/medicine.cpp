#include "faker-cxx/medicine.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "medicine_data.h"

namespace faker::medicine
{
std::string_view condition()
{
    return helper::arrayElement(medicalConditions);
}

std::string_view medicalTest()
{
    return helper::arrayElement(medicalTests);
}

std::string_view specialty()
{
    return helper::arrayElement(specialties);
}

}
