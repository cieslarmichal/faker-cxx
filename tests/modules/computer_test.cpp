#include "../test_helpers.h"
#include <faker/computer.h>
#include <modules/computer_data.h>

using namespace faker;

TEST(ComputerTest, ComputerTypeGeneration)
{
    auto generatedType = computer::type();

    FAKER_EXPECT_CONTAINS(faker::data::ComputerTypes, generatedType);
}

TEST(ComputerTest, ComputerManufactureGeneration)
{
    auto generatedManufacture = computer::manufacture();

    FAKER_EXPECT_CONTAINS(faker::data::ComputerManufactures, generatedManufacture);
}

TEST(ComputerTest, ComputerModelGeneration)
{
    auto generatedModel = computer::model();

    FAKER_EXPECT_CONTAINS(faker::data::ComputerModels, generatedModel);
}

TEST(ComputerTest, ComputerCPUManufactureGeneration)
{
    auto generatedCPUManufacture = computer::cpuManufacture();

    FAKER_EXPECT_CONTAINS(faker::data::ComputerCPUManufactures, generatedCPUManufacture);
}

TEST(ComputerTest, ComputerCPUTypeGeneration)
{
    auto generatedCPUType = computer::cpuType();

    FAKER_EXPECT_CONTAINS(faker::data::ComputerCPUTypes, generatedCPUType);
}

TEST(ComputerTest, ComputerCPUModelGeneration)
{
    auto generatedCPUModel = computer::cpuModel();

    FAKER_EXPECT_CONTAINS(faker::data::ComputerCPUModels, generatedCPUModel);
}

TEST(ComputerTest, ComputerGPUManufactureGeneration)
{
    auto generatedGPUManufacture = computer::gpuManufacture();

    FAKER_EXPECT_CONTAINS(faker::data::ComputerGPUManufactures, generatedGPUManufacture);
}

TEST(ComputerTest, ComputerGPUTypeGeneration)
{
    auto generatedGPUType = computer::gpuType();

    FAKER_EXPECT_CONTAINS(faker::data::ComputerGPUTypes, generatedGPUType);
}

TEST(ComputerTest, ComputerGPUModelGeneration)
{
    auto generatedGPUModel = computer::gpuModel();

    FAKER_EXPECT_CONTAINS(faker::data::ComputerGPUModels, generatedGPUModel);
}