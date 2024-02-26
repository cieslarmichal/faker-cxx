#include "../test_helpers.h"
#include <faker/science.h>
#include <modules/science_data.h>

using namespace faker;

TEST(ScienceTest, shouldGenerateChemElement)
{
    auto generatedChemElement = science::chemicalElement();

    FAKER_EXPECT_CONTAINS(science::data::chemicalElements, generatedChemElement);
}

TEST(ScienceTest, shouldGenerateAnyUnit)
{
    std::vector<science::Unit> units;
    units.insert(
        units.end(), science::data::distanceUnits.begin(), science::data::distanceUnits.end());
    units.insert(units.end(), science::data::massUnits.begin(), science::data::massUnits.end());
    units.insert(units.end(), science::data::timeUnits.begin(), science::data::timeUnits.end());
    units.insert(
        units.end(), science::data::currentUnits.begin(), science::data::currentUnits.end());
    units.insert(units.end(), science::data::temperatureUnits.begin(),
        science::data::temperatureUnits.end());

    auto generatedAnyUnit = science::unit();

    FAKER_EXPECT_CONTAINS(units, generatedAnyUnit);
}

TEST(ScienceTest, shouldGenerateDistanceUnit)
{
    auto generatedDistanceUnit = science::distanceUnit();

    FAKER_EXPECT_CONTAINS(science::data::distanceUnits, generatedDistanceUnit);
}

TEST(ScienceTest, shouldGenerateMassUnit)
{
    auto generatedMassUnit = science::massUnit();

    FAKER_EXPECT_CONTAINS(science::data::massUnits, generatedMassUnit);
}

TEST(ScienceTest, shouldGenerateTimeUnit)
{
    auto generatedTimeUnit = science::timeUnit();

    FAKER_EXPECT_CONTAINS(science::data::timeUnits, generatedTimeUnit);
}

TEST(ScienceTest, shouldGenerateTempUnit)
{
    auto generatedTempUnit = science::tempUnit();

    FAKER_EXPECT_CONTAINS(science::data::temperatureUnits, generatedTempUnit);
}

TEST(ScienceTest, shouldGenerateCurrentUnit)
{
    auto generatedCurrentUnit = science::currentUnit();

    FAKER_EXPECT_CONTAINS(science::data::currentUnits, generatedCurrentUnit);
}
