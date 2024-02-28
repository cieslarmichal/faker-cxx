#include "../test_helpers.h"
#include <faker/computer.h>
#include <modules/computer_data.h>

using namespace faker;

TEST(ComputerTest, ComputerTypeGeneration)
{
    auto generatedType = computer::type();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::types, generatedType);
}

TEST(ComputerTest, ComputerManufactureGeneration)
{
    auto generatedManufacture = computer::manufacturer();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::manufacturers, generatedManufacture);
}

TEST(ComputerTest, ComputerModelGeneration)
{
    auto generatedModel = computer::model();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::models, generatedModel);
}

TEST(ComputerTest, ComputerCPUManufactureGeneration)
{
    auto generatedCPUManufacture = computer::cpu_manufacturer();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::cpu_manufacturers, generatedCPUManufacture);
}

TEST(ComputerTest, ComputerCPUTypeGeneration)
{
    auto generatedCPUType = computer::cpu_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::cpu_types, generatedCPUType);
}

TEST(ComputerTest, ComputerCPUModelGeneration)
{
    auto generatedCPUModel = computer::cpu_model();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::cpu_models, generatedCPUModel);
}

TEST(ComputerTest, ComputerGPUManufactureGeneration)
{
    auto generatedGPUManufacture = computer::gpu_manufacturer();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::gpu_manufacturers, generatedGPUManufacture);
}

TEST(ComputerTest, ComputerGPUTypeGeneration)
{
    auto generatedGPUType = computer::gpu_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::gpu_types, generatedGPUType);
}

TEST(ComputerTest, ComputerGPUModelGeneration)
{
    auto generatedGPUModel = computer::gpu_model();

    FAKER_EXPECT_CONTAINER_CONTAINS(computer::data::gpu_models, generatedGPUModel);
}
