#include "date_data.h"

namespace faker {
const std::array<std::string_view, 12> monthNames = {

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

const std::array<std::string_view, 12> monthAbbreviatedNames
    = { "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" };

const std::array<std::string_view, 7> weekdayNames
    = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

const std::array<std::string_view, 7> weekdayAbbreviatedNames
    = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
}
