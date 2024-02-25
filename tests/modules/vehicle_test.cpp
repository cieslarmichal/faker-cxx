#include "../test_helpers.h"
#include <algorithm>
#include <faker/vehicle.h>
#include <modules/vehicle_data.h>
#include <regex>
#include <string>

using namespace ::testing;
using namespace faker;

class VehicleTest : public Test {
public:
};

TEST_F(VehicleTest, shouldGenerateBicycle)
{
    const auto generatedBicycle = vehicle::bicycle();

    ASSERT_TRUE(faker::testing::contains(bicycle_types, generatedBicycle));
}

TEST_F(VehicleTest, shouldGenerateColor)
{
    const auto generatedColor = vehicle::color();

    ASSERT_TRUE(faker::testing::contains(vehicle_colors, generatedColor));
}

TEST_F(VehicleTest, shouldGenerateFuel)
{
    const auto generatedFuel = vehicle::fuel();

    ASSERT_TRUE(faker::testing::contains(fuel_types, generatedFuel));
}

TEST_F(VehicleTest, shouldGenerateManufacturer)
{
    const auto generatedManufacturer = vehicle::manufacturer();

    ASSERT_TRUE(faker::testing::contains(manufacturers, generatedManufacturer));
}

TEST_F(VehicleTest, shouldGenerateModel)
{
    const auto generatedModel = vehicle::model();

    ASSERT_TRUE(faker::testing::contains(models, generatedModel));
}

TEST_F(VehicleTest, shouldGenerateType)
{
    const auto generatedType = vehicle::type();

    ASSERT_TRUE(faker::testing::contains(vehicle_types, generatedType));
}

TEST_F(VehicleTest, shouldGenerateVehicle)
{
    const auto generatedVehicle = vehicle::vehicle();

    ASSERT_TRUE(
        faker::testing::any_of(manufacturers, [generatedVehicle](const std::string& manufacturer) {
            return faker::testing::starts_with(generatedVehicle, manufacturer);
        }));

    ASSERT_TRUE(faker::testing::any_of(models, [generatedVehicle](const std::string& model) {
        return faker::testing::ends_with(generatedVehicle, model);
    }));
}

TEST_F(VehicleTest, shouldGenerateVin)
{
    const auto generatedVin = vehicle::vin();

    std::regex vinRegex("[A-HJ-NPR-Z0-9]{10}[A-HJ-NPR-Z0-9]{1}[A-HJ-NPR-Z0-9]{1}[0-9]{5}");

    std::smatch match;

    ASSERT_TRUE(std::regex_match(generatedVin, match, vinRegex));
}

TEST_F(VehicleTest, shouldGenerateVrm)
{
    const auto generatedVrm = vehicle::vrm();

    std::regex vrmRegex("[A-Z]{2}[0-9]{2}[A-Z]{3}");

    std::smatch match;

    ASSERT_TRUE(std::regex_match(generatedVrm, match, vrmRegex));
}
