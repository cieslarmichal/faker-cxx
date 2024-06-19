#include "faker-cxx/Computer.h"

#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "computer/ComputerData.h"

using namespace ::testing;
using namespace faker::computer;

class ComputerTest : public Test
{
};

TEST_F(ComputerTest, ComputerTypeGeneration)
{
    const auto generatedType = type();
    ASSERT_TRUE(std::ranges::any_of(computerTypes.begin(), computerTypes.end(),
                                    [generatedType](const std::string_view& type) { return type == generatedType; }));
}

TEST_F(ComputerTest, ComputerManufactureGeneration)
{
    const auto generatedManufacture = manufacture();

    ASSERT_TRUE(std::ranges::any_of(computerManufacturers.begin(), computerManufacturers.end(),
                                    [generatedManufacture](const std::string_view& manufacture)
                                    { return manufacture == generatedManufacture; }));
}

TEST_F(ComputerTest, ComputerModelGeneration)
{
    const auto generatedModel = model();

    ASSERT_TRUE(std::ranges::any_of(computerModels.begin(), computerModels.end(),
                                    [generatedModel](const std::string_view& model)
                                    { return model == generatedModel; }));
}

TEST_F(ComputerTest, ComputerCPUManufactureGeneration)
{
    const auto generatedCPUManufacture = cpuManufacture();

    ASSERT_TRUE(std::ranges::any_of(cpuManufacturers.begin(), cpuManufacturers.end(),
                                    [generatedCPUManufacture](const std::string_view& cpuManufacture)
                                    { return cpuManufacture == generatedCPUManufacture; }));
}

TEST_F(ComputerTest, ComputerCPUTypeGeneration)
{
    const auto generatedCPUType = cpuType();

    ASSERT_TRUE(std::ranges::any_of(cpuTypes.begin(), cpuTypes.end(),
                                    [generatedCPUType](const std::string_view& cpuType)
                                    { return cpuType == generatedCPUType; }));
}

TEST_F(ComputerTest, ComputerCPUModelGeneration)
{
    const auto generatedCPUModel = cpuModel();

    ASSERT_TRUE(std::ranges::any_of(cpuModels.begin(), cpuModels.end(),
                                    [generatedCPUModel](const std::string_view& cpuModel)
                                    { return cpuModel == generatedCPUModel; }));
}

TEST_F(ComputerTest, ComputerGPUManufactureGeneration)
{
    const auto generatedGPUManufacture = gpuManufacture();

    ASSERT_TRUE(std::ranges::any_of(gpuManufacturers.begin(), gpuManufacturers.end(),
                                    [generatedGPUManufacture](const std::string_view& gpuManufacture)
                                    { return gpuManufacture == generatedGPUManufacture; }));
}

TEST_F(ComputerTest, ComputerGPUTypeGeneration)
{
    const auto generatedGPUType = gpuType();

    ASSERT_TRUE(std::ranges::any_of(gpuTypes.begin(), gpuTypes.end(),
                                    [generatedGPUType](const std::string_view& gpuType)
                                    { return gpuType == generatedGPUType; }));
}

TEST_F(ComputerTest, ComputerGPUModelGeneration)
{
    const auto generatedGPUModel = gpuModel();

    ASSERT_TRUE(std::ranges::any_of(gpuModels.begin(), gpuModels.end(),
                                    [generatedGPUModel](const std::string_view& gpuModel)
                                    { return gpuModel == generatedGPUModel; }));
}
