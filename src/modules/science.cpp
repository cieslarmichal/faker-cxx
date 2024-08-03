#include "faker-cxx/science.h"

#include "faker-cxx/helper.h"
#include "science_data.h"

namespace faker::science
{
ChemicalElement chemicalElement()
{
    return helper::randomElement(chemicalElements);
}

Unit unit()
{
    std::vector<Unit> units;

    units.insert(units.end(), distanceUnits.begin(), distanceUnits.end());
    units.insert(units.end(), massUnits.begin(), massUnits.end());
    units.insert(units.end(), timeUnits.begin(), timeUnits.end());
    units.insert(units.end(), currentUnits.begin(), currentUnits.end());
    units.insert(units.end(), temperatureUnits.begin(), temperatureUnits.end());

    return helper::randomElement(units);
}

Unit distanceUnit()
{
    return helper::randomElement(distanceUnits);
}

Unit timeUnit()
{
    return helper::randomElement(timeUnits);
}

Unit massUnit()
{
    return helper::randomElement(massUnits);
}

Unit tempUnit()
{
    return helper::randomElement(temperatureUnits);
}

Unit currentUnit()
{
    return helper::randomElement(currentUnits);
}

}
