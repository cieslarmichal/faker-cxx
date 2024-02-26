#include "../test_helpers.h"
#include <faker/medicine.h>
#include <modules/medicine_data.h>

using namespace faker;

TEST(MedicineTest, shouldGenerateMedicalCondition)
{
    auto generatedMedicalCondition = medicine::condition();

    FAKER_EXPECT_CONTAINER_CONTAINS(medicine::data::medicalConditions, generatedMedicalCondition);
}

TEST(MedicineTest, shouldGenerateMedicalTest)
{
    auto generatedMedicalTest = medicine::medicalTest();

    FAKER_EXPECT_CONTAINER_CONTAINS(medicine::data::medicalTests, generatedMedicalTest);
}

TEST(MedicineTest, shouldGenerateSpecialty)
{
    auto generatedSpecialty = medicine::specialty();

    FAKER_EXPECT_CONTAINER_CONTAINS(medicine::data::specialties, generatedSpecialty);
}
