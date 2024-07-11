#include "faker-cxx/vehicle.h"

#include <algorithm>
#include <regex>
#include <string>
#include <string_view>

#include "gtest/gtest.h"

#include "vehicle/vehicle_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::vehicle;

class VehicleTest : public Test
{
public:
};

TEST_F(VehicleTest, shouldGenerateBicycle)
{
    const auto generatedBicycle = bicycle();

    ASSERT_TRUE(std::ranges::any_of(bicycle_types, [generatedBicycle](const std::string_view& bicycle)
                                    { return bicycle == generatedBicycle; }));
}

TEST_F(VehicleTest, shouldGenerateColor)
{
    const auto generatedColor = color();

    ASSERT_TRUE(std::ranges::any_of(vehicle_colors, [generatedColor](const std::string_view& color)
                                    { return color == generatedColor; }));
}

TEST_F(VehicleTest, shouldGenerateFuel)
{
    const auto generatedFuel = fuel();

    ASSERT_TRUE(std::ranges::any_of(fuel_types,
                                    [generatedFuel](const std::string_view& fuel) { return fuel == generatedFuel; }));
}

TEST_F(VehicleTest, shouldGenerateManufacturer)
{
    const auto generatedManufacturer = manufacturer();

    ASSERT_TRUE(std::ranges::any_of(manufacturers,
                                    [generatedManufacturer](const std::string_view& manufacturer)
                                    { return manufacturer == generatedManufacturer; }));
}

TEST_F(VehicleTest, shouldGenerateModel)
{
    const auto generatedModel = model();

    ASSERT_TRUE(std::ranges::any_of(models, [generatedModel](const std::string_view& model)
                                    { return model == generatedModel; }));
}

TEST_F(VehicleTest, shouldGenerateType)
{
    const auto generatedType = type();

    ASSERT_TRUE(std::ranges::any_of(vehicle_types,
                                    [generatedType](const std::string_view& type) { return type == generatedType; }));
}

TEST_F(VehicleTest, shouldGenerateVehicle)
{
    const auto generatedVehicle = vehicleName();

    ASSERT_TRUE(std::ranges::any_of(manufacturers, [generatedVehicle](const std::string_view& manufacturer)
                                    { return generatedVehicle.starts_with(manufacturer); }));

    ASSERT_TRUE(std::ranges::any_of(models, [generatedVehicle](const std::string_view& model)
                                    { return generatedVehicle.ends_with(model); }));
}

TEST_F(VehicleTest, shouldGenerateVin)
{
    const auto generatedVin = vin();

    std::regex vinRegex("[A-HJ-NPR-Z0-9]{10}[A-HJ-NPR-Z0-9]{1}[A-HJ-NPR-Z0-9]{1}[0-9]{5}");

    std::smatch match;

    ASSERT_TRUE(std::regex_match(generatedVin, match, vinRegex));
}

TEST_F(VehicleTest, shouldGenerateVrm)
{
    const auto generatedVrm = vrm();

    std::regex vrmRegex("[A-Z]{2}[0-9]{2}[A-Z]{3}");

    std::smatch match;

    ASSERT_TRUE(std::regex_match(generatedVrm, match, vrmRegex));
}
