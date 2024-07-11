#include "faker-cxx/science.h"

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

#include "science/science_data.h"

using namespace ::testing;
using namespace faker;
using namespace science;

class ScienceTest : public Test
{
public:
    static bool chemicalElementsAreEqual(const ChemicalElement& chemElement1, const ChemicalElement& chemElement2)
    {
        return chemElement1.name == chemElement2.name && chemElement1.symbol == chemElement2.symbol &&
               chemElement1.atomicNumber == chemElement2.atomicNumber;
    }

    static bool unitsAreEqual(const Unit& unit1, const Unit& unit2)
    {
        return unit1.name == unit2.name && unit1.symbol == unit2.symbol && unit1.usedToMeasure == unit2.usedToMeasure;
    }
};

TEST_F(ScienceTest, shouldGenerateChemElement)
{
    const auto generatedChemElement = chemicalElement();

    ASSERT_TRUE(std::ranges::any_of(chemicalElements, [generatedChemElement](const ChemicalElement& chemElement)
                                    { return chemicalElementsAreEqual(generatedChemElement, chemElement); }));
}

TEST_F(ScienceTest, shouldGenerateAnyUnit)
{
    std::vector<Unit> units;
    units.insert(units.end(), distanceUnits.begin(), distanceUnits.end());
    units.insert(units.end(), massUnits.begin(), massUnits.end());
    units.insert(units.end(), timeUnits.begin(), timeUnits.end());
    units.insert(units.end(), currentUnits.begin(), currentUnits.end());
    units.insert(units.end(), temperatureUnits.begin(), temperatureUnits.end());

    const auto generatedAnyUnit = unit();

    ASSERT_TRUE(std::ranges::any_of(units, [generatedAnyUnit](const Unit& unit)
                                    { return unitsAreEqual(generatedAnyUnit, unit); }));
}

TEST_F(ScienceTest, shouldGenerateDistanceUnit)
{
    const auto generatedDistanceUnit = distanceUnit();

    ASSERT_TRUE(std::ranges::any_of(distanceUnits, [generatedDistanceUnit](const Unit& distanceUnit)
                                    { return unitsAreEqual(generatedDistanceUnit, distanceUnit); }));
}

TEST_F(ScienceTest, shouldGenerateMassUnit)
{
    const auto generatedMassUnit = massUnit();

    ASSERT_TRUE(std::ranges::any_of(massUnits, [generatedMassUnit](const Unit& massUnit)
                                    { return unitsAreEqual(generatedMassUnit, massUnit); }));
}

TEST_F(ScienceTest, shouldGenerateTimeUnit)
{
    const auto generatedTimeUnit = timeUnit();

    ASSERT_TRUE(std::ranges::any_of(timeUnits, [generatedTimeUnit](const Unit& timeUnit)
                                    { return unitsAreEqual(generatedTimeUnit, timeUnit); }));
}

TEST_F(ScienceTest, shouldGenerateTempUnit)
{
    const auto generatedTempUnit = tempUnit();

    ASSERT_TRUE(std::ranges::any_of(temperatureUnits, [generatedTempUnit](const Unit& tempUnit)
                                    { return unitsAreEqual(generatedTempUnit, tempUnit); }));
}

TEST_F(ScienceTest, shouldGenerateCurrentUnit)
{
    const auto generatedCurrentUnit = currentUnit();

    ASSERT_TRUE(std::ranges::any_of(currentUnits, [generatedCurrentUnit](const Unit& currentUnit)
                                    { return unitsAreEqual(generatedCurrentUnit, currentUnit); }));
}
