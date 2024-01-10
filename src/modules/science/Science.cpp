#include "faker-cxx/Science.h"

#include <vector>

#include "data/ChemicalElements.h"
#include "data/Units.h"
#include "faker-cxx/Helper.h"

namespace faker
{

ChemicalElement Science::chemicalElement()
{
    return Helper::arrayElement<ChemicalElement>(chemicalElements);
}

Unit Science::unit()
{
    std::vector<faker::Unit> units = distanceUnits;
    units.insert(units.end(), massUnits.begin(), massUnits.end());
    units.insert(units.end(), timeUnits.begin(), timeUnits.end());
    units.insert(units.end(), currentUnits.begin(), currentUnits.end());
    units.insert(units.end(), temperatureUnits.begin(), temperatureUnits.end());

    return Helper::arrayElement<Unit>(units);
}

Unit Science::distanceUnit()
{
    return Helper::arrayElement<Unit>(distanceUnits);
}

Unit Science::timeUnit()
{
    return Helper::arrayElement<Unit>(timeUnits);
}

Unit Science::massUnit()
{
    return Helper::arrayElement<Unit>(massUnits);
}

Unit Science::tempUnit()
{
    return Helper::arrayElement<Unit>(temperatureUnits);
}

Unit Science::currentUnit()
{
    return Helper::arrayElement<Unit>(currentUnits);
}

};
