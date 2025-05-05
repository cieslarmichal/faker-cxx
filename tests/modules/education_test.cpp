#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "education_data.h"
#include "faker-cxx/education.h"

using namespace ::testing;
using namespace faker;
using namespace faker::education;

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

class EducationTest : public TestWithParam<Locale>
{
public:
};

TEST_P(EducationTest, shouldGenerateSchoolName)
{
    const auto locale = GetParam();

    const auto& educationDefinition = getEducationDefinition(locale);

    const auto generatedSchoolName = school(locale);

    ASSERT_TRUE(std::ranges::any_of(educationDefinition.schoolNames, 
                                    [generatedSchoolName](const std::string_view& school)
                                    { return generatedSchoolName == school; }));
}

TEST_P(EducationTest, shouldGenerateDegreeType)
{
    const auto locale = GetParam();

    const auto& educationDefinition = getEducationDefinition(locale);

    const auto generatedDegreeType = degree(locale);

    ASSERT_TRUE(std::ranges::any_of(educationDefinition.degreeTypes,
                                    [generatedDegreeType](const std::string_view& degree)
                                    { return generatedDegreeType == degree; }));
}

TEST_P(EducationTest, shouldGenerateFieldOfStudy)
{
    const auto locale = GetParam();

    const auto& educationDefinition = getEducationDefinition(locale);

    const auto generatedFieldOfStudy = field(locale);

    ASSERT_TRUE(std::ranges::any_of(educationDefinition.fields,
                                    [generatedFieldOfStudy](const std::string_view& field)
                                    { return generatedFieldOfStudy == field; }));
}

TEST_P(EducationTest, shouldGenerateAcademicTerm)
{
    const auto locale = GetParam();

    const auto& educationDefinition = getEducationDefinition(locale);

    const auto generatedAcademicTerm = term(locale);

    ASSERT_TRUE(std::ranges::any_of(educationDefinition.terms,
                                    [generatedAcademicTerm](const std::string_view& term)
                                    { return generatedAcademicTerm == term; }));
}

TEST_P(EducationTest, shouldGenerateCourseName)
{
    const auto locale = GetParam();

    const auto& educationDefinition = getEducationDefinition(locale);

    const auto generatedCourseName = courses(locale);

    ASSERT_TRUE(std::ranges::any_of(educationDefinition.courseNames,
                                    [generatedCourseName](const std::string_view& course)
                                    { return generatedCourseName == course; }));
}

INSTANTIATE_TEST_SUITE_P(TestEducationByLocale, EducationTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });
