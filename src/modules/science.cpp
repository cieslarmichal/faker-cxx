#include "../common/helper.h"
#include "science_data.h"
#include <faker/science.h>
#include <vector>

namespace faker::science {

ChemicalElement chemical_element() { return Helper::arrayElement(data::chemicalElements); }

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

Unit distance_unit() { return Helper::arrayElement(data::distanceUnits); }

Unit time_unit() { return Helper::arrayElement(data::timeUnits); }

Unit mass_unit() { return Helper::arrayElement(data::massUnits); }

Unit temperature_unit() { return Helper::arrayElement(data::temperatureUnits); }

Unit current_unit() { return Helper::arrayElement(data::currentUnits); }

};
