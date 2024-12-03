
#include <algorithm>
#include <faker-cxx/medicine.h>
#include <string_view>

#include "gtest/gtest.h"

#include "medicine_data.h"
#include "locale.h"

using namespace ::testing;
using namespace faker;
using namespace faker::medicine;

namespace
{

const struct MedicineDefinition& getMedicineMapDefinition(Locale locale)
{
    if (medicineMapSpan.find(locale) == medicineMapSpan.end())
    {
        return medicineMapSpan.at(Locale::en_US);
    }
    else
    {
        return medicineMapSpan.at(locale);
    }
}
}
class MedicineTestLocale : public TestWithParam<Locale>
{
public:
};


TEST_P(MedicineTestLocale, shouldGenerateMedicalConditionLocale)
{
    auto extra = GetParam();
    auto generatedMedicalCondition = condition(extra);
    auto medicalDefinition = getMedicineMapDefinition(extra);

    ASSERT_TRUE(std::ranges::any_of(medicalDefinition.medicalConditions, [generatedMedicalCondition](const std::string_view& medicalCondition)
                                    { return medicalCondition == generatedMedicalCondition; }));
}


TEST_P(MedicineTestLocale, shouldGenerateMedicalTestLocale)
{
    auto extra = GetParam();    

    const auto generatedMedicalTest = medicalTest(extra);

    auto medicalDefinition = getMedicineMapDefinition(extra);

    ASSERT_TRUE(std::ranges::any_of(medicalDefinition.medicalTests, [generatedMedicalTest](const std::string_view& medicalTest)
                                    { return medicalTest == generatedMedicalTest; }));
}

TEST_P(MedicineTestLocale, shouldGenerateSpecialtyLocale)
{
    auto extra = GetParam();    

    const auto generatedSpecialty = specialty(extra);
    
    auto medicalDefinition = getMedicineMapDefinition(extra);

    ASSERT_TRUE(std::ranges::any_of(medicalDefinition.specialties, [generatedSpecialty](const std::string_view& specialty)
                                    { return specialty == generatedSpecialty; }));
}


INSTANTIATE_TEST_SUITE_P(testMedicineByLocale, MedicineTestLocale, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });