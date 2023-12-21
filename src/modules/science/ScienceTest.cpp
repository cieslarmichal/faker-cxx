#pragma once

#include "faker-cxx/Science.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "data/elements.h"
#include "data/units.h"

using namespace ::testing;
using namespace faker;

class ScienceTest : public Test
{
public:
};

TEST_F(ScienceTest, shouldGenerateChemElement)
{
    const auto generatedChemElement = Science::chemicalElement();
    ASSERT_TRUE(std::ranges::any_of(elements, [generatedChemElement](const ChemicalElement& chemElement)
                                    { return generatedChemElement == chemElement; }));
}

TEST_F(ScienceTest, shouldGenerateAnyUnit)
{
    const auto generatedAnyUnit = Science::unit();
    std::vector<faker::Unit> units = distanceUnits;
    units.insert(units.end(), massUnits.begin(), massUnits.end());
    units.insert(units.end(), timeUnits.begin(), timeUnits.end());
    units.insert(units.end(), currentUnits.begin(), currentUnits.end());
    units.insert(units.end(), temperatureUnits.begin(), temperatureUnits.end());

    ASSERT_TRUE(std::ranges::any_of(units, [generatedAnyUnit](const Unit& unit) { return generatedAnyUnit == unit; }));
}

TEST_F(ScienceTest, shouldGenerateDistanceUnit)
{
    const auto generatedDistanceUnit = Science::distanceUnit();
    ASSERT_TRUE(std::ranges::any_of(distanceUnits, [generatedDistanceUnit](const Unit& distanceUnit)
                                    { return generatedDistanceUnit == distanceUnit; }));
}

TEST_F(ScienceTest, shouldGenerateMassUnit)
{
    const auto generatedMassUnit = Science::massUnit();
    ASSERT_TRUE(std::ranges::any_of(massUnits, [generatedMassUnit](const Unit& massUnit)
                                    { return generatedMassUnit == massUnit; }));
}

TEST_F(ScienceTest, shouldGenerateTimeUnit)
{
    const auto generatedTimeUnit = Science::timeUnit();
    ASSERT_TRUE(std::ranges::any_of(timeUnits, [generatedTimeUnit](const Unit& timeUnit)
                                    { return generatedTimeUnit == timeUnit; }));
}

TEST_F(ScienceTest, shouldGenerateTempUnit)
{
    const auto generatedTempUnit = Science::tempUnit();
    ASSERT_TRUE(std::ranges::any_of(temperatureUnits, [generatedTempUnit](const Unit& tempUnit)
                                    { return generatedTempUnit == tempUnit; }));
}

TEST_F(ScienceTest, shouldGenerateCurrentUnit)
{
    const auto generatedCurrentUnit = Science::currentUnit();
    ASSERT_TRUE(std::ranges::any_of(currentUnits, [generatedCurrentUnit](const Unit& currentUnit)
                                    { return generatedCurrentUnit == currentUnit; }));
}