#include "../test_helpers.h"
#include <faker/science.h>
#include <modules/science_data.h>

using namespace faker;

TEST(ScienceTest, shouldGenerateChemElement)
{
    auto generatedChemElement = science::chemical_element();

    FAKER_EXPECT_CONTAINER_CONTAINS(science::data::chemical_elements, generatedChemElement);
}

TEST(ScienceTest, shouldGenerateAnyUnit)
{
    std::vector<science::unit_info> units;
    units.insert(
        units.end(), science::data::distance_units.begin(), science::data::distance_units.end());
    units.insert(units.end(), science::data::mass_units.begin(), science::data::mass_units.end());
    units.insert(units.end(), science::data::time_units.begin(), science::data::time_units.end());
    units.insert(
        units.end(), science::data::current_units.begin(), science::data::current_units.end());
    units.insert(units.end(), science::data::temperature_units.begin(),
        science::data::temperature_units.end());

    auto generatedAnyUnit = science::unit();

    FAKER_EXPECT_CONTAINER_CONTAINS(units, generatedAnyUnit);
}

TEST(ScienceTest, shouldGenerateDistanceUnit)
{
    auto generatedDistanceUnit = science::distance_unit();

    FAKER_EXPECT_CONTAINER_CONTAINS(science::data::distance_units, generatedDistanceUnit);
}

TEST(ScienceTest, shouldGenerateMassUnit)
{
    auto generatedMassUnit = science::mass_unit();

    FAKER_EXPECT_CONTAINER_CONTAINS(science::data::mass_units, generatedMassUnit);
}

TEST(ScienceTest, shouldGenerateTimeUnit)
{
    auto generatedTimeUnit = science::time_unit();

    FAKER_EXPECT_CONTAINER_CONTAINS(science::data::time_units, generatedTimeUnit);
}

TEST(ScienceTest, shouldGenerateTempUnit)
{
    auto generatedTempUnit = science::temperature_unit();

    FAKER_EXPECT_CONTAINER_CONTAINS(science::data::temperature_units, generatedTempUnit);
}

TEST(ScienceTest, shouldGenerateCurrentUnit)
{
    auto generatedCurrentUnit = science::current_unit();

    FAKER_EXPECT_CONTAINER_CONTAINS(science::data::current_units, generatedCurrentUnit);
}
