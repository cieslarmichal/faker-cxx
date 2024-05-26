#include "faker-cxx/Medicine.h"

#include "MedicineData.h"
#include "faker-cxx/Helper.h"

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
