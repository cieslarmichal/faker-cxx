
#include <algorithm>
#include <string_view>
#include <faker-cxx/Medicine.h>
#include "gtest/gtest.h"

#include "medicine/MedicineData.h"

using namespace ::testing;
using namespace faker;

class MedicineTest : public Test
{
public:
};

TEST_F(MedicineTest, shouldGenerateMedicalCondition)
{
    const auto generatedMedicalCondition = Medicine::condition();

    ASSERT_TRUE(std::ranges::any_of(medicine::medicalConditions, [generatedMedicalCondition](const std::string_view& medicalCondition)
                                    { return medicalCondition == generatedMedicalCondition; }));
}

TEST_F(MedicineTest, shouldGenerateMedicalTest)
{
    const auto generatedMedicalTest = Medicine::medicalTest();

    ASSERT_TRUE(std::ranges::any_of(medicine::medicalTests, [generatedMedicalTest](const std::string_view& medicalTest)
                                    { return medicalTest == generatedMedicalTest; }));
}

TEST_F(MedicineTest, shouldGenerateSpecialty)
{
    const auto generatedSpecialty = Medicine::specialty();

    ASSERT_TRUE(std::ranges::any_of(medicine::specialties, [generatedSpecialty](const std::string_view& specialty)
                                    { return specialty == generatedSpecialty; }));
}
