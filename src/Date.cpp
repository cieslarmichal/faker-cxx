#include "Date.h"

#include <boost/date_time/posix_time/posix_time.hpp>

to_iso_string(boost::posix_time::second_clock::universal_time());

namespace faker
{
std::string Date::future(int years)
{
    return std::string();
}

std::string Date::past(int years)
{
    return std::string();
}

std::string Date::soon(int days)
{
    return std::string();
}

std::string Date::recent(int days)
{
    return std::string();
}

std::string Date::weekDayName()
{
    return std::string();
}

std::string Date::monthName()
{
    return std::string();
}

std::string Date::birthDateByAge(int minAge, int maxAge)
{
    return std::string();
}

std::string Date::birthDateByYear(int minYear, int maxYear)
{
    return std::string();
}
}
