#include "faker-cxx/Science.h"

#include "faker-cxx/Helper.h"
#include "ScienceData.h"

namespace faker
{
Science::ChemicalElement Science::chemicalElement()
{
    return helper::arrayElement(chemicalElements);
}

Science::Unit Science::unit()
{
    std::vector<faker::Science::Unit> units;
    units.insert(units.end(), distanceUnits.begin(), distanceUnits.end());
    units.insert(units.end(), massUnits.begin(), massUnits.end());
    units.insert(units.end(), timeUnits.begin(), timeUnits.end());
    units.insert(units.end(), currentUnits.begin(), currentUnits.end());
    units.insert(units.end(), temperatureUnits.begin(), temperatureUnits.end());

    return helper::arrayElement<Science::Unit>(units);
}

Science::Unit Science::distanceUnit()
{
    return helper::arrayElement(distanceUnits);
}

Science::Unit Science::timeUnit()
{
    return helper::arrayElement(timeUnits);
}

Science::Unit Science::massUnit()
{
    return helper::arrayElement(massUnits);
}

Science::Unit Science::tempUnit()
{
    return helper::arrayElement(temperatureUnits);
}

Science::Unit Science::currentUnit()
{
    return helper::arrayElement(currentUnits);
}

}
