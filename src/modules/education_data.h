#include "faker/education.h"
#include "faker/helper.h"
#include "modules/education_data.h"

namespace faker::education
{
std::string_view schoolName(Locale)
{
    return helper::pickRandomElement(schoolNames);
}

std::string_view degreeType(Locale)
{
    return helper::pickRandomElement(degreeTypes);
}

std::string_view fieldOfStudy(Locale)
{
    return helper::pickRandomElement(fieldsOfStudy);
}

std::string_view academicTerm(Locale)
{
    return helper::pickRandomElement(academicTerms);
}

std::string_view courseName(Locale)
{
    return helper::pickRandomElement(courseNames);
}
}
