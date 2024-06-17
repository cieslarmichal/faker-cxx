#include "faker-cxx/Science.h"

#include "faker-cxx/Helper.h"
#include "ScienceData.h"

namespace faker
{
Science::ChemicalElement Science::chemicalElement()
{
    return Helper::arrayElement(chemicalElements);
}

Science::Unit Science::unit()
{
    std::vector<faker::Science::Unit> units;
    units.insert(units.end(), distanceUnits.begin(), distanceUnits.end());
    units.insert(units.end(), massUnits.begin(), massUnits.end());
    units.insert(units.end(), timeUnits.begin(), timeUnits.end());
    units.insert(units.end(), currentUnits.begin(), currentUnits.end());
    units.insert(units.end(), temperatureUnits.begin(), temperatureUnits.end());

    return Helper::arrayElement<Science::Unit>(units);
}

Science::Unit Science::distanceUnit()
{
    return Helper::arrayElement(distanceUnits);
}

Science::Unit Science::timeUnit()
{
    return Helper::arrayElement(timeUnits);
}

Science::Unit Science::massUnit()
{
    return Helper::arrayElement(massUnits);
}

Science::Unit Science::tempUnit()
{
    return Helper::arrayElement(temperatureUnits);
}

Science::Unit Science::currentUnit()
{
    return Helper::arrayElement(currentUnits);
}

}
