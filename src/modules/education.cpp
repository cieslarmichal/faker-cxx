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
    return helper::randomElement(educationDefinition.schoolNames);
}

std::string_view degree(Locale locale)
{
    const auto& educationDefinition = getEducationDefinition(locale);
    return helper::randomElement(educationDefinition.degreeTypes);
}

std::string_view field(Locale locale)
{
    const auto& educationDefinition = getEducationDefinition(locale);
    return helper::randomElement(educationDefinition.fields);
}

std::string_view term(Locale locale)
{
    const auto& educationDefinition = getEducationDefinition(locale);
    return helper::randomElement(educationDefinition.terms);
}

std::string_view courses(Locale locale)
{
    const auto& educationDefinition = getEducationDefinition(locale);
    return helper::randomElement(educationDefinition.courseNames);
}

} // namespace faker::education
