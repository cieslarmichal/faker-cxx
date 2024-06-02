#include "faker-cxx/Science.h"

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

#include "science/ScienceData.h"

using namespace ::testing;
using namespace faker;

class ScienceTest : public Test
{
public:
    static bool chemicalElementsAreEqual(const Science::ChemicalElement& chemElement1,
                                         const Science::ChemicalElement& chemElement2)
    {
        return chemElement1.name == chemElement2.name && chemElement1.symbol == chemElement2.symbol &&
               chemElement1.atomicNumber == chemElement2.atomicNumber;
    }

    static bool unitsAreEqual(const Science::Unit& unit1, const Science::Unit& unit2)
    {
        return unit1.name == unit2.name && unit1.symbol == unit2.symbol && unit1.usedToMeasure == unit2.usedToMeasure;
    }
};

TEST_F(ScienceTest, shouldGenerateChemElement)
{
    const auto generatedChemElement = Science::chemicalElement();
    ASSERT_TRUE(std::ranges::any_of(chemicalElements,
                                    [generatedChemElement](const Science::ChemicalElement& chemElement)
                                    { return chemicalElementsAreEqual(generatedChemElement, chemElement); }));
}

TEST_F(ScienceTest, shouldGenerateAnyUnit)
{
    const auto generatedAnyUnit = Science::unit();
    std::vector<faker::Science::Unit> units;
    units.insert(units.end(), distanceUnits.begin(), distanceUnits.end());
    units.insert(units.end(), massUnits.begin(), massUnits.end());
    units.insert(units.end(), timeUnits.begin(), timeUnits.end());
    units.insert(units.end(), currentUnits.begin(), currentUnits.end());
    units.insert(units.end(), temperatureUnits.begin(), temperatureUnits.end());

    ASSERT_TRUE(std::ranges::any_of(units, [generatedAnyUnit](const Science::Unit& unit)
                                    { return unitsAreEqual(generatedAnyUnit, unit); }));
}

TEST_F(ScienceTest, shouldGenerateDistanceUnit)
{
    const auto generatedDistanceUnit = Science::distanceUnit();
    ASSERT_TRUE(std::ranges::any_of(distanceUnits, [generatedDistanceUnit](const Science::Unit& distanceUnit)
                                    { return unitsAreEqual(generatedDistanceUnit, distanceUnit); }));
}

TEST_F(ScienceTest, shouldGenerateMassUnit)
{
    const auto generatedMassUnit = Science::massUnit();
    ASSERT_TRUE(std::ranges::any_of(massUnits, [generatedMassUnit](const Science::Unit& massUnit)
                                    { return unitsAreEqual(generatedMassUnit, massUnit); }));
}

TEST_F(ScienceTest, shouldGenerateTimeUnit)
{
    const auto generatedTimeUnit = Science::timeUnit();
    ASSERT_TRUE(std::ranges::any_of(timeUnits, [generatedTimeUnit](const Science::Unit& timeUnit)
                                    { return unitsAreEqual(generatedTimeUnit, timeUnit); }));
}

TEST_F(ScienceTest, shouldGenerateTempUnit)
{
    const auto generatedTempUnit = Science::tempUnit();
    ASSERT_TRUE(std::ranges::any_of(temperatureUnits, [generatedTempUnit](const Science::Unit& tempUnit)
                                    { return unitsAreEqual(generatedTempUnit, tempUnit); }));
}

TEST_F(ScienceTest, shouldGenerateCurrentUnit)
{
    const auto generatedCurrentUnit = Science::currentUnit();
    ASSERT_TRUE(std::ranges::any_of(currentUnits, [generatedCurrentUnit](const Science::Unit& currentUnit)
                                    { return unitsAreEqual(generatedCurrentUnit, currentUnit); }));
}
