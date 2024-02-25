#include "../test_helpers.h"
#include <algorithm>
#include <faker/science.h>
#include <modules/science_data.h>

using namespace ::testing;
using namespace faker;

class ScienceTest : public Test {
public:
};

TEST_F(ScienceTest, shouldGenerateChemElement)
{
    const auto generatedChemElement = science::chemicalElement();
    ASSERT_TRUE(faker::testing::contains(chemicalElements, generatedChemElement));
}

TEST_F(ScienceTest, shouldGenerateAnyUnit)
{
    std::vector<faker::Unit> units;
    units.insert(units.end(), distanceUnits.begin(), distanceUnits.end());
    units.insert(units.end(), massUnits.begin(), massUnits.end());
    units.insert(units.end(), timeUnits.begin(), timeUnits.end());
    units.insert(units.end(), currentUnits.begin(), currentUnits.end());
    units.insert(units.end(), temperatureUnits.begin(), temperatureUnits.end());

    const auto generatedAnyUnit = science::unit();
    ASSERT_TRUE(faker::testing::contains(units, generatedAnyUnit));
}

TEST_F(ScienceTest, shouldGenerateDistanceUnit)
{
    const auto generatedDistanceUnit = science::distanceUnit();
    ASSERT_TRUE(faker::testing::contains(distanceUnits, generatedDistanceUnit));
}

TEST_F(ScienceTest, shouldGenerateMassUnit)
{
    const auto generatedMassUnit = science::massUnit();
    ASSERT_TRUE(faker::testing::contains(massUnits, generatedMassUnit));
}

TEST_F(ScienceTest, shouldGenerateTimeUnit)
{
    const auto generatedTimeUnit = science::timeUnit();
    ASSERT_TRUE(faker::testing::contains(timeUnits, generatedTimeUnit));
}

TEST_F(ScienceTest, shouldGenerateTempUnit)
{
    const auto generatedTempUnit = science::tempUnit();
    ASSERT_TRUE(faker::testing::contains(temperatureUnits, generatedTempUnit));
}

TEST_F(ScienceTest, shouldGenerateCurrentUnit)
{
    const auto generatedCurrentUnit = science::currentUnit();
    ASSERT_TRUE(faker::testing::contains(currentUnits, generatedCurrentUnit));
}
