#include "faker-cxx/education.h"

#include <string_view>

#include "education_data.h"
#include "faker-cxx/helper.h"

namespace faker::education
{

namespace
{
const struct EducationDefinition& getEducationDefinition(Locale locale)
{
    switch (locale)
    {
    default:
        return enUSEducationDefinition;
    }
}
}

std::string_view school(Locale locale)
{
    const auto& educationDefinition = getEducationDefinition(locale);
    return helper::randomElement(educationDefinition.schoolNames); // FIXED
}

std::string_view degree(Locale locale)
{
    const auto& educationDefinition = getEducationDefinition(locale);
    return helper::randomElement(educationDefinition.degreeTypes); // FIXED
}

std::string_view field(Locale locale)
{
    const auto& educationDefinition = getEducationDefinition(locale);
    return helper::randomElement(educationDefinition.fields); // ✅ Only if `fields` is defined
}

std::string_view term(Locale locale)
{
    const auto& educationDefinition = getEducationDefinition(locale);
    return helper::randomElement(educationDefinition.terms); // ✅ Only if `terms` is defined
}

std::string_view courses(Locale locale)
{
    const auto& educationDefinition = getEducationDefinition(locale);
    return helper::randomElement(educationDefinition.courseNames); // FIXED
}

}
