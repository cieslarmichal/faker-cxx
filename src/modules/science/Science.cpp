#include "faker-cxx/Science.h"

#include <vector>

#include "data/ChemicalElements.h"
#include "data/Units.h"
#include "faker-cxx/Helper.h"

namespace faker
{
Science::ChemicalElement Science::chemicalElement()
{
    return Helper::arrayElement<Science::ChemicalElement>(chemicalElements);
}

Science::Unit Science::unit()
{
    std::vector<faker::Science::Unit> units = distanceUnits;
    units.insert(units.end(), massUnits.begin(), massUnits.end());
    units.insert(units.end(), timeUnits.begin(), timeUnits.end());
    units.insert(units.end(), currentUnits.begin(), currentUnits.end());
    units.insert(units.end(), temperatureUnits.begin(), temperatureUnits.end());

    return Helper::arrayElement<Science::Unit>(units);
}

Science::Unit Science::distanceUnit()
{
    return Helper::arrayElement<Science::Unit>(distanceUnits);
}

Science::Unit Science::timeUnit()
{
    return Helper::arrayElement<Science::Unit>(timeUnits);
}

Science::Unit Science::massUnit()
{
    return Helper::arrayElement<Science::Unit>(massUnits);
}

Science::Unit Science::tempUnit()
{
    return Helper::arrayElement<Science::Unit>(temperatureUnits);
}

Science::Unit Science::currentUnit()
{
    return Helper::arrayElement<Science::Unit>(currentUnits);
}

}
