#include "date_data.h"

namespace faker::date::data {
const std::array<std::string_view, 12> month_names = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December",
};

const std::array<std::string_view, 12> month_abbr_names
    = { "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" };

const std::array<std::string_view, 7> weekday_names
    = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

const std::array<std::string_view, 7> weekday_abbr_names
    = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
}
