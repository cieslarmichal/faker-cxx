#include "../test_helpers.h"
#include <faker/science.h>
#include <modules/science_data.h>

using namespace faker;

TEST(ScienceTest, shouldGenerateChemElement)
{
    auto generatedChemElement = science::chemicalElement();

    FAKER_EXPECT_CONTAINS(chemicalElements, generatedChemElement);
}

TEST(ScienceTest, shouldGenerateAnyUnit)
{
    std::vector<faker::Unit> units;
    units.insert(units.end(), distanceUnits.begin(), distanceUnits.end());
    units.insert(units.end(), massUnits.begin(), massUnits.end());
    units.insert(units.end(), timeUnits.begin(), timeUnits.end());
    units.insert(units.end(), currentUnits.begin(), currentUnits.end());
    units.insert(units.end(), temperatureUnits.begin(), temperatureUnits.end());

    auto generatedAnyUnit = science::unit();

    FAKER_EXPECT_CONTAINS(units, generatedAnyUnit);
}

TEST(ScienceTest, shouldGenerateDistanceUnit)
{
    auto generatedDistanceUnit = science::distanceUnit();

    FAKER_EXPECT_CONTAINS(distanceUnits, generatedDistanceUnit);
}

TEST(ScienceTest, shouldGenerateMassUnit)
{
    auto generatedMassUnit = science::massUnit();

    FAKER_EXPECT_CONTAINS(massUnits, generatedMassUnit);
}

TEST(ScienceTest, shouldGenerateTimeUnit)
{
    auto generatedTimeUnit = science::timeUnit();

    FAKER_EXPECT_CONTAINS(timeUnits, generatedTimeUnit);
}

TEST(ScienceTest, shouldGenerateTempUnit)
{
    auto generatedTempUnit = science::tempUnit();

    FAKER_EXPECT_CONTAINS(temperatureUnits, generatedTempUnit);
}

TEST(ScienceTest, shouldGenerateCurrentUnit)
{
    auto generatedCurrentUnit = science::currentUnit();

    FAKER_EXPECT_CONTAINS(currentUnits, generatedCurrentUnit);
}
