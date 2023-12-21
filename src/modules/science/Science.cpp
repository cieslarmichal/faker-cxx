#include "faker-cxx/Science.h"

#include "data/elements.h"
#include "data/units.h"
#include "faker-cxx/Helper.h"

#include <vector>

namespace faker
{

ChemicalElement Science::chemicalElement()
{
    return Helper::arrayElement<ChemicalElement>(elements);
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