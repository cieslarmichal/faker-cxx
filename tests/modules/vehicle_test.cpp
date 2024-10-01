#include <algorithm>
#include <regex>
#include <string>
#include <string_view>

#include "gtest/gtest.h"

#include "faker-cxx/vehicle.h"
#include "vehicle_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::vehicle;

namespace
{
const struct VehicleDefinition& getVehicleDefinition(Locale locale)
{
    return enUSVehicleDefinition ;
}
}

class VehicleTest : public TestWithParam<Locale>
{
public:
};

TEST_P(VehicleTest, shouldGenerateBicycle)
{
    const auto locale = GetParam();
    const auto& vehicleDefinition = getVehicleDefinition(locale);

    const auto generatedBicycle = bicycle(locale) ;

    ASSERT_TRUE(std::ranges::any_of(vehicleDefinition.bicycles, [generatedBicycle](const std::string_view& bicycle)
                                    { return bicycle == generatedBicycle; }));
}

TEST_P(VehicleTest, shouldGenerateColor)
{
    const auto locale = GetParam();
    const auto& vehicleDefinition = getVehicleDefinition(locale);

    const auto generatedColor = color(locale) ;

    ASSERT_TRUE(std::ranges::any_of(vehicleDefinition.colors, [generatedColor](const std::string_view& color)
                                    { return color == generatedColor; }));
}

TEST_P(VehicleTest, shouldGenerateFuel)
{
    const auto locale = GetParam();
    const auto& vehicleDefinition = getVehicleDefinition(locale);

    const auto generatedFuel = fuel(locale) ;

    ASSERT_TRUE(std::ranges::any_of(vehicleDefinition.fuelTypes,
                                    [generatedFuel](const std::string_view& fuel) { return fuel == generatedFuel; }));
}

TEST_P(VehicleTest, shouldGenerateManufacturer)
{
    const auto locale = GetParam();
    const auto& vehicleDefinition = getVehicleDefinition(locale);

    const auto generatedManufacturer = manufacturer(locale);

    ASSERT_TRUE(std::ranges::any_of(vehicleDefinition.manufacturers, [generatedManufacturer](const std::string_view& manufacturer)
                                    { return manufacturer == generatedManufacturer; }));
}

TEST_P(VehicleTest, shouldGenerateModel)
{
    const auto locale = GetParam();
    const auto& vehicleDefinition = getVehicleDefinition(locale);

    const auto generatedModel = model(locale);

    ASSERT_TRUE(std::ranges::any_of(vehicleDefinition.models, [generatedModel](const std::string_view& model)
                                    { return model == generatedModel; }));
}

TEST_P(VehicleTest, shouldGenerateType)
{
    const auto locale = GetParam();
    const auto& vehicleDefinition = getVehicleDefinition(locale);
    
    const auto generatedType = type();

    ASSERT_TRUE(std::ranges::any_of(vehicleDefinition.vehicles,
                                    [generatedType](const std::string_view& type) { return type == generatedType; }));
}

TEST_P(VehicleTest, shouldGenerateVehicle)
{
    const auto locale = GetParam();
    const auto& vehicleDefinition = getVehicleDefinition(locale);

    const auto generatedVehicle = vehicleName(locale);

    ASSERT_TRUE(std::ranges::any_of(vehicleDefinition.manufacturers, [generatedVehicle](const std::string_view& manufacturer)
                                    { return generatedVehicle.starts_with(manufacturer); }));

    ASSERT_TRUE(std::ranges::any_of(vehicleDefinition.models, [generatedVehicle](const std::string_view& model)
                                    { return generatedVehicle.ends_with(model); }));
}

TEST_P(VehicleTest, shouldGenerateVin)
{
    const auto generatedVin = vin();

    std::regex vinRegex("[A-HJ-NPR-Z0-9]{10}[A-HJ-NPR-Z0-9]{1}[A-HJ-NPR-Z0-9]{1}[0-9]{5}");

    std::smatch match;

    ASSERT_TRUE(std::regex_match(generatedVin, match, vinRegex));
}

TEST_P(VehicleTest, shouldGenerateVrm)
{
    const auto generatedVrm = vrm();

    std::regex vrmRegex("[A-Z]{2}[0-9]{2}[A-Z]{3}");

    std::smatch match;

    ASSERT_TRUE(std::regex_match(generatedVrm, match, vrmRegex));
}

INSTANTIATE_TEST_SUITE_P(TestBookByLocale, VehicleTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });