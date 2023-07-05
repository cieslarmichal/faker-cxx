#include "Date.h"

#include <boost/date_time/posix_time/posix_time.hpp>

#include "data/MonthNames.h"
#include "data/WeekdayNames.h"
#include "Helper.h"
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
};

const auto futureDateSelector = [](boost::posix_time::time_duration window,
                                   boost::posix_time::ptime now = boost::posix_time::second_clock::local_time())
{
    const auto end = now + window;

    const auto size = (end - now).total_seconds();

    return now + boost::posix_time::seconds(Number::integer(static_cast<int>(size)));
};

const auto numberOfHoursInDay = 24;
const auto numberOfDaysInYear = 365;
}

boost::posix_time::ptime Date::future(int years)
{
    return futureDateSelector(boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * years));
}

boost::posix_time::ptime Date::past(int years)
{
    return pastDateSelector(boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * years));
}

boost::posix_time::ptime Date::soon(int days)
{
    return futureDateSelector(boost::posix_time::hours(numberOfHoursInDay * days));
}

boost::posix_time::ptime Date::recent(int days)
{
    return pastDateSelector(boost::posix_time::hours(numberOfHoursInDay * days));
}

boost::posix_time::ptime Date::birthDateByAge(int minAge, int maxAge)
{
    std::cout << minAge << maxAge;
    return boost::posix_time::ptime();
}

boost::posix_time::ptime Date::birthDateByYear(int minYear, int maxYear)
{
    std::cout << minYear << maxYear;

    return boost::posix_time::ptime();
}

std::string Date::futureISOString(int years)
{
    return to_iso_extended_string(future(years));
}

std::string Date::pastISOString(int years)
{
    return to_iso_extended_string(past(years));
}

std::string Date::soonISOString(int days)
{
    return to_iso_extended_string(soon(days));
}

std::string Date::recentISOString(int days)
{
    return to_iso_extended_string(recent(days));
}

std::string Date::birthDateByAgeISOString(int minAge, int maxAge)
{
    std::cout << minAge << maxAge;

    return "";
}

std::string Date::birthDateByYearISOString(int minYear, int maxYear)
{
    std::cout << minYear << maxYear;

    return "";
}

std::string Date::weekdayName()
{
    return Helper::arrayElement(weekdayNames);
}
std::string Date::weekdayAbbreviatedName()
{
    return Helper::arrayElement(weekdayAbbreviatedNames);
}

std::string Date::monthName()
{
    return Helper::arrayElement(monthNames);
}

std::string Date::monthAbbreviatedName()
{
    return Helper::arrayElement(monthAbbreviatedNames);
}

}
