#include "../test_helpers.h"
#include <faker/medicine.h>
#include <modules/medicine_data.h>

using namespace ::testing;
using namespace faker;

class MedicineTest : public Test {
public:
};

TEST_F(MedicineTest, shouldGenerateMedicalCondition)
{
    const auto generatedMedicalCondition = medicine::condition();

    FAKER_EXPECT_CONTAINS(medicalConditions, generatedMedicalCondition);
}

TEST_F(MedicineTest, shouldGenerateMedicalTest)
{
    const auto generatedMedicalTest = medicine::medicalTest();

    FAKER_EXPECT_CONTAINS(medicalTests, generatedMedicalTest);
}

TEST_F(MedicineTest, shouldGenerateSpecialty)
{
    const auto generatedSpecialty = medicine::specialty();

    FAKER_EXPECT_CONTAINS(specialties, generatedSpecialty);
}
