#include "faker-cxx/Computer.h"

#include <algorithm>
#include <string>
#include <vector>

#include "gtest/gtest.h"

#include "computer/data/ComputerData.h"

using namespace ::testing;
using namespace faker;
class ComputerTest : public Test
{
};

TEST_F(ComputerTest, ComputerTypeGeneration)
{
    std::string generatedType = Computer::type();
    ASSERT_TRUE(std::ranges::any_of(faker::data::ComputerTypes.begin(), faker::data::ComputerTypes.end(),
                                    [generatedType](const std::string& type) { return type == generatedType; }));
}

TEST_F(ComputerTest, ComputerManufactureGeneration)
{
    std::string generatedManufacture = Computer::manufacture();
    ASSERT_TRUE(std::ranges::any_of(faker::data::ComputerManufactures.begin(), faker::data::ComputerManufactures.end(),
                                    [generatedManufacture](const std::string& manufacture)
                                    { return manufacture == generatedManufacture; }));
}

TEST_F(ComputerTest, ComputerModelGeneration)
{
    std::string generatedModel = Computer::model();
    ASSERT_TRUE(std::ranges::any_of(faker::data::ComputerModels.begin(), faker::data::ComputerModels.end(),
                                    [generatedModel](const std::string& model) { return model == generatedModel; }));
}

TEST_F(ComputerTest, ComputerCPUManufactureGeneration)
{
    std::string generatedCPUManufacture = Computer::cpuManufacture();
    ASSERT_TRUE(std::ranges::any_of(faker::data::ComputerCPUManufactures.begin(),
                                    faker::data::ComputerCPUManufactures.end(),
                                    [generatedCPUManufacture](const std::string& cpuManufacture)
                                    { return cpuManufacture == generatedCPUManufacture; }));
}

TEST_F(ComputerTest, ComputerCPUTypeGeneration)
{
    std::string generatedCPUType = Computer::cpuType();
    ASSERT_TRUE(std::ranges::any_of(faker::data::ComputerCPUTypes.begin(), faker::data::ComputerCPUTypes.end(),
                                    [generatedCPUType](const std::string& cpuType)
                                    { return cpuType == generatedCPUType; }));
}

TEST_F(ComputerTest, ComputerCPUModelGeneration)
{
    std::string generatedCPUModel = Computer::cpuModel();
    ASSERT_TRUE(std::ranges::any_of(faker::data::ComputerCPUModels.begin(), faker::data::ComputerCPUModels.end(),
                                    [generatedCPUModel](const std::string& cpuModel)
                                    { return cpuModel == generatedCPUModel; }));
}

TEST_F(ComputerTest, ComputerGPUManufactureGeneration)
{
    std::string generatedGPUManufacture = Computer::gpuManufacture();
    ASSERT_TRUE(std::ranges::any_of(faker::data::ComputerGPUManufactures.begin(),
                                    faker::data::ComputerGPUManufactures.end(),
                                    [generatedGPUManufacture](const std::string& gpuManufacture)
                                    { return gpuManufacture == generatedGPUManufacture; }));
}

TEST_F(ComputerTest, ComputerGPUTypeGeneration)
{
    std::string generatedGPUType = Computer::gpuType();
    ASSERT_TRUE(std::ranges::any_of(faker::data::ComputerGPUTypes.begin(), faker::data::ComputerGPUTypes.end(),
                                    [generatedGPUType](const std::string& gpuType)
                                    { return gpuType == generatedGPUType; }));
}

TEST_F(ComputerTest, ComputerGPUModelGeneration)
{
    std::string generatedGPUModel = Computer::gpuModel();
    ASSERT_TRUE(std::ranges::any_of(faker::data::ComputerGPUModels.begin(), faker::data::ComputerGPUModels.end(),
                                    [generatedGPUModel](const std::string& gpuModel)
                                    { return gpuModel == generatedGPUModel; }));
}
