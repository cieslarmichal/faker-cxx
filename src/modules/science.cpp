#include "faker-cxx/science.h"

#include "faker-cxx/helper.h"
#include "science_data.h"

namespace faker::science
{
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

ChemicalElement chemicalElement(Locale locale)
{
    const auto& scienceDefinition = getScienceDefinition(locale);

    return helper::randomElement(scienceDefinition.chemicalElements);
}

Unit unit(Locale locale)
{
    const auto& scienceDefinition = getScienceDefinition(locale);

    std::vector<Unit> units;

    units.insert(units.end(), scienceDefinition.distanceUnits.begin(), scienceDefinition.distanceUnits.end());
    units.insert(units.end(), scienceDefinition.massUnits.begin(), scienceDefinition.massUnits.end());
    units.insert(units.end(), scienceDefinition.timeUnits.begin(), scienceDefinition.timeUnits.end());
    units.insert(units.end(), scienceDefinition.currentUnits.begin(), scienceDefinition.currentUnits.end());
    units.insert(units.end(), scienceDefinition.temperatureUnits.begin(), scienceDefinition.temperatureUnits.end());

    return helper::randomElement(units);
}

Unit distanceUnit(Locale locale)
{
    const auto& scienceDefinition = getScienceDefinition(locale);

    return helper::randomElement(scienceDefinition.distanceUnits);
}

Unit timeUnit(Locale locale)
{
    const auto& scienceDefinition = getScienceDefinition(locale);

    return helper::randomElement(scienceDefinition.timeUnits);
}

Unit massUnit(Locale locale)
{
    const auto& scienceDefinition = getScienceDefinition(locale);

    return helper::randomElement(scienceDefinition.massUnits);
}

Unit tempUnit(Locale locale)
{
    const auto& scienceDefinition = getScienceDefinition(locale);

    return helper::randomElement(scienceDefinition.temperatureUnits);
}

Unit currentUnit(Locale locale)
{
    const auto& scienceDefinition = getScienceDefinition(locale);

    return helper::randomElement(scienceDefinition.currentUnits);
}
}
