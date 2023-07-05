#include "Date.h"

#include <boost/date_time/posix_time/posix_time.hpp>

#include "Number.h"

namespace faker
{
namespace
{
const auto pastDateSelector = [](boost::posix_time::time_duration window,
                                 boost::posix_time::ptime now = boost::posix_time::second_clock::local_time())
{
    const auto start = now - window;

    const auto size = (now - start).total_seconds();

    return start + boost::posix_time::seconds(Number::integer(static_cast<int>(size)));
    return pastDateSelector(hours(24 * days));
};
}

boost::posix_time::ptime Date::future(int years)
{
    return boost::posix_time::ptime();
}

boost::posix_time::ptime Date::past(int years)
{
    return boost::posix_time::ptime();
}

boost::posix_time::ptime Date::soon(int days)
{
    return boost::posix_time::ptime();
}

boost::posix_time::ptime Date::recent(int days)
{
    return boost::posix_time::ptime();
}

boost::posix_time::ptime Date::birthDateByAge(int minAge, int maxAge)
{
    return boost::posix_time::ptime();
}

boost::posix_time::ptime Date::birthDateByYear(int minYear, int maxYear)
{
    return boost::posix_time::ptime();
}

std::string Date::futureISOString(int years)
{
    return std::string();
}

std::string Date::pastISOString(int years)
{
    return std::string();
}

std::string Date::soonISOString(int days)
{
    return std::string();
}

std::string Date::recentISOString(int days)
{
    return std::string();
}

std::string Date::birthDateByAgeISOString(int minAge, int maxAge)
{
    return std::string();
}

std::string Date::birthDateByYearISOString(int minYear, int maxYear)
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
}
