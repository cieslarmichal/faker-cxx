#include "faker-cxx/Medicine.h"

#include "data/conditon.h"
#include "data/medicaltests.h"
#include "data/specialty.h"
#include "faker-cxx/Helper.h"

namespace faker
{
std::string Medicine::condition()
{
    return Helper::arrayElement<std::string>(medicalConditions);
}

std::string Medicine::medicalTest()
{
    return Helper::arrayElement<std::string>(medicalTests);
}
std::string Medicine::specialty()
{
    return Helper::arrayElement<std::string>(specialties);
}

}
