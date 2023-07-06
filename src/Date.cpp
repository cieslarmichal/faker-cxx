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
const auto numberOfHoursInDay = 24;
const auto numberOfDaysInYear = 365;
}

boost::posix_time::ptime Date::between(boost::posix_time::ptime from, boost::posix_time::ptime to)
{
    const auto size = (to - from).total_seconds();

    return from + boost::posix_time::seconds(Number<int>::integer(static_cast<int>(size)));
}

boost::posix_time::ptime Date::future(int years)
{
    const auto startDate = boost::posix_time::second_clock::local_time();

    const auto endDate = boost::posix_time::second_clock::local_time() +
                         boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * years);

    return between(startDate, endDate);
}

boost::posix_time::ptime Date::past(int years)
{
    const auto startDate = boost::posix_time::second_clock::local_time() -
                           boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * years);

    const auto endDate = boost::posix_time::second_clock::local_time();

    return between(startDate, endDate);
}

boost::posix_time::ptime Date::soon(int days)
{
    const auto startDate = boost::posix_time::second_clock::local_time();

    const auto endDate =
        boost::posix_time::second_clock::local_time() + boost::posix_time::hours(numberOfHoursInDay * days);

    return between(startDate, endDate);
}

boost::posix_time::ptime Date::recent(int days)
{
    const auto startDate =
        boost::posix_time::second_clock::local_time() - boost::posix_time::hours(numberOfHoursInDay * days);

    const auto endDate = boost::posix_time::second_clock::local_time();

    return between(startDate, endDate);
}

boost::posix_time::ptime Date::birthdateByAge(int minAge, int maxAge)
{
    const auto startDate = boost::posix_time::second_clock::local_time() -
                           boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * maxAge);

    const auto endDate = boost::posix_time::second_clock::local_time() -
                         boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * minAge);

    return between(startDate, endDate);
}

boost::posix_time::ptime Date::birthdateByYear(int minYear, int maxYear)
{
    boost::posix_time::ptime startDate{boost::gregorian::date(static_cast<unsigned short>(minYear), 1, 1)};
    boost::posix_time::ptime endDate{boost::gregorian::date(static_cast<unsigned short>(maxYear), 12, 31)};

    return between(startDate, endDate);
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

std::string Date::birthdateByAgeISOString(int minAge, int maxAge)
{
    return to_iso_extended_string(birthdateByAge(minAge, maxAge));
}

std::string Date::birthdateByYearISOString(int minYear, int maxYear)
{
    return to_iso_extended_string(birthdateByYear(minYear, maxYear));
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
