#include "../test_helpers.h"
#include <faker/computer.h>
#include <modules/computer_data.h>

using namespace faker;

TEST(ComputerTest, ComputerTypeGeneration)
{
    auto generatedType = computer::type();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::ComputerTypes, generatedType);
}

TEST(ComputerTest, ComputerManufactureGeneration)
{
    auto generatedManufacture = computer::manufacture();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::ComputerManufactures, generatedManufacture);
}

TEST(ComputerTest, ComputerModelGeneration)
{
    auto generatedModel = computer::model();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::ComputerModels, generatedModel);
}

TEST(ComputerTest, ComputerCPUManufactureGeneration)
{
    auto generatedCPUManufacture = computer::cpu_manufacturer();

    FAKER_EXPECT_CONTAINER_CONTAINS(
        computer::data::ComputerCPUManufactures, generatedCPUManufacture);
}

TEST(ComputerTest, ComputerCPUTypeGeneration)
{
    auto generatedCPUType = computer::cpu_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::ComputerCPUTypes, generatedCPUType);
}

TEST(ComputerTest, ComputerCPUModelGeneration)
{
    auto generatedCPUModel = computer::cpu_model();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::ComputerCPUModels, generatedCPUModel);
}

TEST(ComputerTest, ComputerGPUManufactureGeneration)
{
    auto generatedGPUManufacture = computer::gpu_manufacturer();

    FAKER_EXPECT_CONTAINER_CONTAINS(
        computer::data::ComputerGPUManufactures, generatedGPUManufacture);
}

TEST(ComputerTest, ComputerGPUTypeGeneration)
{
    auto generatedGPUType = computer::gpu_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::ComputerGPUTypes, generatedGPUType);
}

TEST(ComputerTest, ComputerGPUModelGeneration)
{
    auto generatedGPUModel = computer::gpu_model();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::ComputerGPUModels, generatedGPUModel);
}
