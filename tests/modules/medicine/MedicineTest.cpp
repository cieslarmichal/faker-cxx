
#include <algorithm>
#include <faker-cxx/Medicine.h>
#include <gtest/gtest.h>

#include "medicine/data/conditon.h"
#include "medicine/data/medicaltests.h"
#include "medicine/data/specialty.h"

using namespace ::testing;
using namespace faker;

class MedicineTest : public Test
{
public:
};

TEST_F(MedicineTest, shouldGenerateMedicalCondition)
{
    const auto generatedMedicalCondition = Medicine::condition();

    ASSERT_TRUE(std::ranges::any_of(medicalConditions, [generatedMedicalCondition](const std::string& medicalCondition)
                                    { return medicalCondition == generatedMedicalCondition; }));
}

TEST_F(MedicineTest, shouldGenerateMedicalTest)
{
    const auto generatedMedicalTest = Medicine::medicalTest();

    ASSERT_TRUE(std::ranges::any_of(medicalTests, [generatedMedicalTest](const std::string& medicalTest)
                                    { return medicalTest == generatedMedicalTest; }));
}

TEST_F(MedicineTest, shouldGenerateSpecialty)
{
    const auto generatedSpecialty = Medicine::specialty();

    ASSERT_TRUE(std::ranges::any_of(specialties, [generatedSpecialty](const std::string& specialty)
                                    { return specialty == generatedSpecialty; }));
}
