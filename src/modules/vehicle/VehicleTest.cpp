#include "faker-cxx/Vehicle.h"

#include <algorithm>
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
    std::string generatedBicycle = Vehicle::bicycle();

    ASSERT_TRUE(std::ranges::any_of(bicycle_types, [generatedBicycle](const std::string& bicycle)
                                    { return bicycle == generatedBicycle; }));
}

TEST_F(VehicleTest, shouldGenerateColor)
{
    std::string generatedColor = Vehicle::color();

    ASSERT_TRUE(std::ranges::any_of(vehicle_colors,
                                    [generatedColor](const std::string& color) { return color == generatedColor; }));
}

TEST_F(VehicleTest, shouldGenerateFuel)
{
    std::string generatedFuel = Vehicle::fuel();

    ASSERT_TRUE(
        std::ranges::any_of(fuel_types, [generatedFuel](const std::string& fuel) { return fuel == generatedFuel; }));
}

TEST_F(VehicleTest, shouldGenerateManufacturer)
{
    std::string generatedManufacturer = Vehicle::manufacturer();

    ASSERT_TRUE(std::ranges::any_of(generatedManufacturer, [generatedManufacturer](const std::string& manufacturer)
                                    { return manufacturer == generatedManufacturer; }));
}

TEST_F(VehicleTest, shouldGenerateModel)
{
    std::string generatedModel = Vehicle::model();

    ASSERT_TRUE(
        std::ranges::any_of(models, [generatedModel](const std::string& model) { return model == generatedModel; }));
}

TEST_F(VehicleTest, shouldGenerateType)
{
    std::string generatedType = Vehicle::type();

    ASSERT_TRUE(
        std::ranges::any_of(vehicle_types, [generatedType](const std::string& type) { return type == generatedType; }));
}

TEST_F(VehicleTest, shouldGenerateVehicle)
{
    std::string generatedVehicle = Vehicle::vehicle();

    int spaceIndex = generatedVehicle.find(' ');

    if (spaceIndex != -1)
    {
        std::string vehicleManufacturer = generatedVehicle.substr(0, spaceIndex);
        std::string vehicleModel = generatedVehicle.substr(spaceIndex + 1);

        // Process the two words
    }

    ASSERT_TRUE(std::ranges::any_of(manufacturers, [vehicleManufacturer](const std::string& manufacturer)
                                    { return manufacturer == vehicleManufacturer; }));

    ASSERT_TRUE(
        std::ranges::any_of(models, [vehicleModel](const std::string& model) { return model == vehicleModel; }));
}