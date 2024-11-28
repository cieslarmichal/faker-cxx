#include "faker-cxx/medicine.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "medicine_data.h"

namespace faker::medicine
{
std::string_view condition(Locale locale)
{
    auto localeLocal = locale;
    if (medicineMapSpan.find(locale) == medicineMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    return helper::randomElement((medicineMapSpan.at(localeLocal)).medicalConditions);
}

std::string_view medicalTest(Locale locale)
{
    auto localeLocal = locale;
    if (medicineMapSpan.find(locale) == medicineMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    return helper::randomElement((medicineMapSpan.at(localeLocal)).medicalTests);
}

std::string_view specialty(Locale locale)
{
    auto localeLocal = locale;
    if (medicineMapSpan.find(locale) == medicineMapSpan.end())
    {
        localeLocal = Locale::en_US;
    }
    return helper::randomElement((medicineMapSpan.at(localeLocal)).specialties);    
}

}
