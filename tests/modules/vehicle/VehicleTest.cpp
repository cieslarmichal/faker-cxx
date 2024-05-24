#include "faker-cxx/Vehicle.h"

#include <algorithm>
#include <regex>
#include <string>

#include "gtest/gtest.h"

#include "data/Bicycle.h"
#include "data/Color.h"
#include "data/Fuel.h"
#include "data/Manufacturer.h"
#include "data/Model.h"
#include "data/Type.h"

using namespace ::testing;
using namespace faker;

class VehicleTest : public Test
{
public:
};

TEST_F(VehicleTest, shouldGenerateBicycle)
{
    const auto generatedBicycle = Vehicle::bicycle();

    ASSERT_TRUE(std::ranges::any_of(bicycle_types, [generatedBicycle](const std::string& bicycle)
                                    { return bicycle == generatedBicycle; }));
}

TEST_F(VehicleTest, shouldGenerateColor)
{
    const auto generatedColor = Vehicle::color();

    ASSERT_TRUE(std::ranges::any_of(vehicle_colors,
                                    [generatedColor](const std::string& color) { return color == generatedColor; }));
}

TEST_F(VehicleTest, shouldGenerateFuel)
{
    const auto generatedFuel = Vehicle::fuel();

    ASSERT_TRUE(
        std::ranges::any_of(fuel_types, [generatedFuel](const std::string& fuel) { return fuel == generatedFuel; }));
}

TEST_F(VehicleTest, shouldGenerateManufacturer)
{
    const auto generatedManufacturer = Vehicle::manufacturer();

    ASSERT_TRUE(std::ranges::any_of(manufacturers, [generatedManufacturer](const std::string& manufacturer)
                                    { return manufacturer == generatedManufacturer; }));
}

TEST_F(VehicleTest, shouldGenerateModel)
{
    const auto generatedModel = Vehicle::model();

    ASSERT_TRUE(
        std::ranges::any_of(models, [generatedModel](const std::string& model) { return model == generatedModel; }));
}

TEST_F(VehicleTest, shouldGenerateType)
{
    const auto generatedType = Vehicle::type();

    ASSERT_TRUE(
        std::ranges::any_of(vehicle_types, [generatedType](const std::string& type) { return type == generatedType; }));
}

TEST_F(VehicleTest, shouldGenerateVehicle)
{
    const auto generatedVehicle = Vehicle::vehicle();

    ASSERT_TRUE(std::ranges::any_of(manufacturers, [generatedVehicle](const std::string& manufacturer)
                                    { return generatedVehicle.starts_with(manufacturer); }));

    ASSERT_TRUE(std::ranges::any_of(models, [generatedVehicle](const std::string& model)
                                    { return generatedVehicle.ends_with(model); }));
}

TEST_F(VehicleTest, shouldGenerateVin)
{
    const auto generatedVin = Vehicle::vin();

    std::regex vinRegex("[A-HJ-NPR-Z0-9]{10}[A-HJ-NPR-Z0-9]{1}[A-HJ-NPR-Z0-9]{1}[0-9]{5}");

    std::smatch match;

    ASSERT_TRUE(std::regex_match(generatedVin, match, vinRegex));
}

TEST_F(VehicleTest, shouldGenerateVrm)
{
    const auto generatedVrm = Vehicle::vrm();

    std::regex vrmRegex("[A-Z]{2}[0-9]{2}[A-Z]{3}");

    std::smatch match;

    ASSERT_TRUE(std::regex_match(generatedVrm, match, vrmRegex));
}
