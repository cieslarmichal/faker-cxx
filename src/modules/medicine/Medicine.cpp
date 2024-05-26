#include "faker-cxx/Medicine.h"

#include "data/conditon.h"
#include "data/medicaltests.h"
#include "data/specialty.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string_view Medicine::condition()
{
    return Helper::arrayElement(medicalConditions);
}

std::string_view Medicine::medicalTest()
{
    return Helper::arrayElement(medicalTests);
}
std::string_view Medicine::specialty()
{
    return Helper::arrayElement(specialties);
}

}
