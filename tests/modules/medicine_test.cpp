
#include <algorithm>
#include <faker-cxx/medicine.h>
#include <string_view>

#include "gtest/gtest.h"

#include "medicine_data.h"

using namespace ::testing;
using namespace faker::medicine;

class MedicineTest : public Test
{
public:
};

TEST_F(MedicineTest, shouldGenerateMedicalCondition)
{
    const auto generatedMedicalCondition = condition();

    ASSERT_TRUE(std::ranges::any_of(medicalConditions,
                                    [generatedMedicalCondition](const std::string_view& medicalCondition)
                                    { return medicalCondition == generatedMedicalCondition; }));
}

TEST_F(MedicineTest, shouldGenerateMedicalTest)
{
    const auto generatedMedicalTest = medicalTest();

    ASSERT_TRUE(std::ranges::any_of(medicalTests, [generatedMedicalTest](const std::string_view& medicalTest)
                                    { return medicalTest == generatedMedicalTest; }));
}

TEST_F(MedicineTest, shouldGenerateSpecialty)
{
    const auto generatedSpecialty = specialty();

    ASSERT_TRUE(std::ranges::any_of(specialties, [generatedSpecialty](const std::string_view& specialty)
                                    { return specialty == generatedSpecialty; }));
}
