#include "faker-cxx/Medicine.h"

#include <string_view>

#include "faker-cxx/Helper.h"
#include "MedicineData.h"

namespace faker
{
std::string_view Medicine::condition()
{
    return Helper::arrayElement(medicine::medicalConditions);
}

std::string_view Medicine::medicalTest()
{
    return Helper::arrayElement(medicine::medicalTests);
}

std::string_view Medicine::specialty()
{
    return Helper::arrayElement(medicine::specialties);
}

}
