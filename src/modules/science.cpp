#include "faker-cxx/science.h"

#include <array>

#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "science_data.h"

namespace faker::science
{
namespace
{
const struct ScienceDefinition& getScienceDefinition(Locale locale)
{
    switch (locale)
    {
    case Locale::en_US:
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

    const std::array<std::span<const Unit>, 5> unitRanges{scienceDefinition.distanceUnits, scienceDefinition.massUnits,
                                                          scienceDefinition.timeUnits, scienceDefinition.currentUnits,
                                                          scienceDefinition.temperatureUnits};

    std::size_t totalSize = 0;

    for (const auto& range : unitRanges)
    {
        totalSize += range.size();
    }

    auto index = number::integer(totalSize - 1);

    std::size_t rangeIndex = 0;

    while (index >= unitRanges[rangeIndex].size())
    {
        index -= unitRanges[rangeIndex].size();
        ++rangeIndex;
    }

    return unitRanges[rangeIndex][index];
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
