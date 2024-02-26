#include "science_data.h"
#include <faker/helper.h>
#include <faker/science.h>
#include <vector>

namespace faker::science {

ChemicalElement chemicalElement() { return Helper::arrayElement(data::chemicalElements); }

Unit unit()
{
    static std::vector<Unit> units;

    if (units.empty()) {
        units.reserve(data::distanceUnits.size() + data::massUnits.size() + data::timeUnits.size()
            + data::currentUnits.size() + data::temperatureUnits.size());
        units.insert(units.end(), data::distanceUnits.begin(), data::distanceUnits.end());
        units.insert(units.end(), data::massUnits.begin(), data::massUnits.end());
        units.insert(units.end(), data::timeUnits.begin(), data::timeUnits.end());
        units.insert(units.end(), data::currentUnits.begin(), data::currentUnits.end());
        units.insert(units.end(), data::temperatureUnits.begin(), data::temperatureUnits.end());
    }

    return Helper::arrayElement(units);
}

Unit distanceUnit() { return Helper::arrayElement(data::distanceUnits); }

Unit timeUnit() { return Helper::arrayElement(data::timeUnits); }

Unit massUnit() { return Helper::arrayElement(data::massUnits); }

Unit tempUnit() { return Helper::arrayElement(data::temperatureUnits); }

Unit currentUnit() { return Helper::arrayElement(data::currentUnits); }

};
