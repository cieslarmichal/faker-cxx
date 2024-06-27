#include "faker-cxx/Science.h"

#include "faker-cxx/Helper.h"
#include "ScienceData.h"

namespace faker::science
{
ChemicalElement chemicalElement()
{
    return helper::arrayElement(chemicalElements);
}

Unit unit()
{
    std::vector<Unit> units;

    units.insert(units.end(), distanceUnits.begin(), distanceUnits.end());
    units.insert(units.end(), massUnits.begin(), massUnits.end());
    units.insert(units.end(), timeUnits.begin(), timeUnits.end());
    units.insert(units.end(), currentUnits.begin(), currentUnits.end());
    units.insert(units.end(), temperatureUnits.begin(), temperatureUnits.end());

    return helper::arrayElement<Unit>(units);
}

Unit distanceUnit()
{
    return helper::arrayElement(distanceUnits);
}

Unit timeUnit()
{
    return helper::arrayElement(timeUnits);
}

Unit massUnit()
{
    return helper::arrayElement(massUnits);
}

Unit tempUnit()
{
    return helper::arrayElement(temperatureUnits);
}

Unit currentUnit()
{
    return helper::arrayElement(currentUnits);
}

}
