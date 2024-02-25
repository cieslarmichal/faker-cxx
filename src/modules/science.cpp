#include "science_data.h"
#include <faker/helper.h>
#include <faker/science.h>
#include <vector>

namespace faker::science {

ChemicalElement chemicalElement() { return Helper::arrayElement(chemicalElements); }

Unit unit()
{
    static std::vector<Unit> units;

    if (units.empty()) {
        units.reserve(distanceUnits.size() + massUnits.size() + timeUnits.size()
            + currentUnits.size() + temperatureUnits.size());
        units.insert(units.end(), distanceUnits.begin(), distanceUnits.end());
        units.insert(units.end(), massUnits.begin(), massUnits.end());
        units.insert(units.end(), timeUnits.begin(), timeUnits.end());
        units.insert(units.end(), currentUnits.begin(), currentUnits.end());
        units.insert(units.end(), temperatureUnits.begin(), temperatureUnits.end());
    }

    return Helper::arrayElement(units);
}

Unit distanceUnit() { return Helper::arrayElement(distanceUnits); }

Unit timeUnit() { return Helper::arrayElement(timeUnits); }

Unit massUnit() { return Helper::arrayElement(massUnits); }

Unit tempUnit() { return Helper::arrayElement(temperatureUnits); }

Unit currentUnit() { return Helper::arrayElement(currentUnits); }

};
