#include "../test_helpers.h"
#include <faker/vehicle.h>
#include <modules/vehicle_data.h>
#include <regex>
#include <string>

using namespace faker;

TEST(VehicleTest, shouldGenerateBicycle)
{
    auto generatedBicycle = vehicle::bicycle();

    FAKER_EXPECT_CONTAINER_CONTAINS(vehicle::data::bicycle_types, generatedBicycle);
}

TEST(VehicleTest, shouldGenerateColor)
{
    auto generatedColor = vehicle::color();

    FAKER_EXPECT_CONTAINER_CONTAINS(vehicle::data::vehicle_colors, generatedColor);
}

TEST(VehicleTest, shouldGenerateFuel)
{
    auto generatedFuel = vehicle::fuel();

    FAKER_EXPECT_CONTAINER_CONTAINS(vehicle::data::fuel_types, generatedFuel);
}

TEST(VehicleTest, shouldGenerateManufacturer)
{
    auto generatedManufacturer = vehicle::manufacturer();

    FAKER_EXPECT_CONTAINER_CONTAINS(vehicle::data::manufacturers, generatedManufacturer);
}

TEST(VehicleTest, shouldGenerateModel)
{
    auto generatedModel = vehicle::model();

    FAKER_EXPECT_CONTAINER_CONTAINS(vehicle::data::models, generatedModel);
}

TEST(VehicleTest, shouldGenerateType)
{
    auto generatedType = vehicle::type();

    FAKER_EXPECT_CONTAINER_CONTAINS(vehicle::data::vehicle_types, generatedType);
}

TEST(VehicleTest, shouldGenerateVehicle)
{
    auto generatedVehicle = vehicle::vehicle();

    ASSERT_TRUE(
        faker::testing::any_of(vehicle::data::manufacturers, [generatedVehicle](auto manufacturer) {
            return faker::testing::starts_with(generatedVehicle, manufacturer);
        }));

    ASSERT_TRUE(faker::testing::any_of(vehicle::data::models, [generatedVehicle](auto model) {
        return faker::testing::ends_with(generatedVehicle, model);
    }));
}

TEST(VehicleTest, shouldGenerateVin)
{
    auto generatedVin = vehicle::vin();

    std::regex vinRegex("[A-HJ-NPR-Z0-9]{10}[A-HJ-NPR-Z0-9]{1}[A-HJ-NPR-Z0-9]{1}[0-9]{5}");

    ASSERT_TRUE(std::regex_match(generatedVin, vinRegex));
}

TEST(VehicleTest, shouldGenerateVrm)
{
    auto generatedVrm = vehicle::vrm();

    std::regex vrmRegex("[A-Z]{2}[0-9]{2}[A-Z]{3}");

    ASSERT_TRUE(std::regex_match(generatedVrm, vrmRegex));
}
