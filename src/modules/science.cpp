#include "../common/random.h"
#include "science_data.h"
#include <faker/science.h>
#include <vector>

namespace faker::science {
namespace {
    std::vector<unit_info> merge_all_units()
    {
        std::vector<unit_info> result;

        result.reserve(data::distance_units.size() + data::mass_units.size()
            + data::time_units.size() + data::current_units.size()
            + data::temperature_units.size());
        result.insert(result.end(), data::distance_units.begin(), data::distance_units.end());
        result.insert(result.end(), data::mass_units.begin(), data::mass_units.end());
        result.insert(result.end(), data::time_units.begin(), data::time_units.end());
        result.insert(result.end(), data::current_units.begin(), data::current_units.end());
        result.insert(result.end(), data::temperature_units.begin(), data::temperature_units.end());

        return result;
    }

    const std::vector<unit_info> all_units = merge_all_units();
}

chemical_element_info chemical_element() { return random::element(data::chemical_elements); }

unit_info unit() { return random::element(all_units); }

unit_info distance_unit() { return random::element(data::distance_units); }

unit_info time_unit() { return random::element(data::time_units); }

unit_info mass_unit() { return random::element(data::mass_units); }

unit_info temperature_unit() { return random::element(data::temperature_units); }

unit_info current_unit() { return random::element(data::current_units); }

};
