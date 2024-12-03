#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

#include "faker-cxx/science.h"
#include "science_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::science;

namespace
{
const struct ScienceDefinition& getScienceDefinition(Locale locale)
{
    switch (locale)
    {
    default:
        return enUSscienceDefinition;
    }
}
}

class ScienceTest : public TestWithParam<Locale>
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

TEST_P(ScienceTest, shouldGenerateChemElement)
{
    const auto locale = GetParam();

    const auto& scienceDefinition = getScienceDefinition(locale);

    const auto generatedChemElement = chemicalElement(locale);

    ASSERT_TRUE(std::ranges::any_of(scienceDefinition.chemicalElements, [generatedChemElement](const ChemicalElement& chemElement)
                                    { return chemicalElementsAreEqual(generatedChemElement, chemElement); }));
}

TEST_P(ScienceTest, shouldGenerateAnyUnit)
{
    const auto locale = GetParam();

    const auto& scienceDefinition = getScienceDefinition(locale);

    std::vector<Unit> units;
    units.insert(units.end(), scienceDefinition.distanceUnits.begin(), scienceDefinition.distanceUnits.end());
    units.insert(units.end(), scienceDefinition.massUnits.begin(), scienceDefinition.massUnits.end());
    units.insert(units.end(), scienceDefinition.timeUnits.begin(), scienceDefinition.timeUnits.end());
    units.insert(units.end(), scienceDefinition.currentUnits.begin(), scienceDefinition.currentUnits.end());
    units.insert(units.end(), scienceDefinition.temperatureUnits.begin(), scienceDefinition.temperatureUnits.end());

    const auto generatedAnyUnit = unit(locale);

    ASSERT_TRUE(std::ranges::any_of(units, [generatedAnyUnit](const Unit& unit)
                                    { return unitsAreEqual(generatedAnyUnit, unit); }));
}

TEST_P(ScienceTest, shouldGenerateDistanceUnit)
{
    const auto locale = GetParam();

    const auto& scienceDefinition = getScienceDefinition(locale);

    const auto generatedDistanceUnit = distanceUnit(locale);

    ASSERT_TRUE(std::ranges::any_of(scienceDefinition.distanceUnits, [generatedDistanceUnit](const Unit& distanceUnit)
                                    { return unitsAreEqual(generatedDistanceUnit, distanceUnit); }));
}

TEST_P(ScienceTest, shouldGenerateMassUnit)
{
    const auto locale = GetParam();

    const auto& scienceDefinition = getScienceDefinition(locale);

    const auto generatedMassUnit = massUnit(locale);

    ASSERT_TRUE(std::ranges::any_of(scienceDefinition.massUnits, [generatedMassUnit](const Unit& massUnit)
                                    { return unitsAreEqual(generatedMassUnit, massUnit); }));
}

TEST_P(ScienceTest, shouldGenerateTimeUnit)
{
    const auto locale = GetParam();

    const auto& scienceDefinition = getScienceDefinition(locale);

    const auto generatedTimeUnit = timeUnit(locale);

    ASSERT_TRUE(std::ranges::any_of(scienceDefinition.timeUnits, [generatedTimeUnit](const Unit& timeUnit)
                                    { return unitsAreEqual(generatedTimeUnit, timeUnit); }));
}

TEST_P(ScienceTest, shouldGenerateTempUnit)
{
    const auto locale = GetParam();

    const auto& scienceDefinition = getScienceDefinition(locale);

    const auto generatedTempUnit = tempUnit(locale);

    ASSERT_TRUE(std::ranges::any_of(scienceDefinition.temperatureUnits, [generatedTempUnit](const Unit& tempUnit)
                                    { return unitsAreEqual(generatedTempUnit, tempUnit); }));
}

TEST_P(ScienceTest, shouldGenerateCurrentUnit)
{
    const auto locale = GetParam();

    const auto& scienceDefinition = getScienceDefinition(locale);

    const auto generatedCurrentUnit = currentUnit();

    ASSERT_TRUE(std::ranges::any_of(scienceDefinition.currentUnits, [generatedCurrentUnit](const Unit& currentUnit)
                                    { return unitsAreEqual(generatedCurrentUnit, currentUnit); }));
}

INSTANTIATE_TEST_SUITE_P(TestScienceByLocale, ScienceTest, ValuesIn(locales),
                         [](const TestParamInfo<Locale>& paramInfo) { return toString(paramInfo.param); });
