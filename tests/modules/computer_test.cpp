#include "../test_helpers.h"
#include <algorithm>
#include <faker/computer.h>
#include <modules/computer_data.h>

using namespace ::testing;
using namespace faker;

class ComputerTest : public Test { };

TEST_F(ComputerTest, ComputerTypeGeneration)
{
    auto generatedType = computer::type();
    ASSERT_TRUE(faker::testing::contains(faker::data::ComputerTypes, generatedType));
}

TEST_F(ComputerTest, ComputerManufactureGeneration)
{
    auto generatedManufacture = computer::manufacture();
    ASSERT_TRUE(faker::testing::contains(faker::data::ComputerManufactures, generatedManufacture));
}

TEST_F(ComputerTest, ComputerModelGeneration)
{
    auto generatedModel = computer::model();
    ASSERT_TRUE(faker::testing::contains(faker::data::ComputerModels, generatedModel));
}

TEST_F(ComputerTest, ComputerCPUManufactureGeneration)
{
    auto generatedCPUManufacture = computer::cpuManufacture();
    ASSERT_TRUE(
        faker::testing::contains(faker::data::ComputerCPUManufactures, generatedCPUManufacture));
}

TEST_F(ComputerTest, ComputerCPUTypeGeneration)
{
    auto generatedCPUType = computer::cpuType();
    ASSERT_TRUE(faker::testing::contains(faker::data::ComputerCPUTypes, generatedCPUType));
}

TEST_F(ComputerTest, ComputerCPUModelGeneration)
{
    auto generatedCPUModel = computer::cpuModel();
    ASSERT_TRUE(faker::testing::contains(faker::data::ComputerCPUModels, generatedCPUModel));
}

TEST_F(ComputerTest, ComputerGPUManufactureGeneration)
{
    auto generatedGPUManufacture = computer::gpuManufacture();
    ASSERT_TRUE(
        faker::testing::contains(faker::data::ComputerGPUManufactures, generatedGPUManufacture));
}

TEST_F(ComputerTest, ComputerGPUTypeGeneration)
{
    auto generatedGPUType = computer::gpuType();
    ASSERT_TRUE(faker::testing::contains(faker::data::ComputerGPUTypes, generatedGPUType));
}

TEST_F(ComputerTest, ComputerGPUModelGeneration)
{
    auto generatedGPUModel = computer::gpuModel();
    ASSERT_TRUE(faker::testing::contains(faker::data::ComputerGPUModels, generatedGPUModel));
}
