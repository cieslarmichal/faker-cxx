#include "../common/format_helper.h"
#include "vehicle_data.h"
#include <faker/helper.h>
#include <faker/number.h>
#include <faker/string.h>
#include <faker/vehicle.h>

namespace faker::vehicle {

std::string_view bicycle() { return Helper::arrayElement(data::bicycle_types); }

std::string_view color() { return Helper::arrayElement(data::vehicle_colors); }

std::string_view fuel() { return Helper::arrayElement(data::fuel_types); }

std::string_view manufacturer() { return Helper::arrayElement(data::manufacturers); }

std::string_view model() { return Helper::arrayElement(data::models); }

std::string_view type() { return Helper::arrayElement(data::vehicle_types); }

std::string vehicle() { return FormatHelper::format("{} {}", manufacturer(), model()); }

std::string vin()
{
    std::string exclude_characters { "oiqOIQ" };

    return FormatHelper::format("{}{}{}{}",
        String::alphanumeric(10, StringCasing::Upper, exclude_characters),
        String::alpha(1, StringCasing::Upper, exclude_characters),
        String::alphanumeric(1, StringCasing::Upper, exclude_characters),
        number::integer(10000, 99999));
}

std::string vrm()
{
    return FormatHelper::format("{}{}{}", String::alpha(2, StringCasing::Upper),
        String::numeric(2, true), String::alpha(3, StringCasing::Upper));
}

}
