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

boost::posix_time::ptime Date::fromRange(boost::posix_time::ptime startDate, boost::posix_time::ptime endDate)
{
    const auto size = (endDate - startDate).total_seconds();

    return startDate + boost::posix_time::seconds(Number::integer(static_cast<int>(size)));
}

boost::posix_time::ptime Date::future(int years)
{
    const auto startDate = boost::posix_time::second_clock::local_time();

    const auto endDate = boost::posix_time::second_clock::local_time() +
                         boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * years);

    return fromRange(startDate, endDate);
}

boost::posix_time::ptime Date::past(int years)
{
    const auto startDate = boost::posix_time::second_clock::local_time();

    const auto endDate = boost::posix_time::second_clock::local_time() -
                         boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * years);

    return fromRange(startDate, endDate);
}

boost::posix_time::ptime Date::soon(int days)
{
    const auto startDate = boost::posix_time::second_clock::local_time();

    const auto endDate =
        boost::posix_time::second_clock::local_time() + boost::posix_time::hours(numberOfHoursInDay * days);

    return fromRange(startDate, endDate);
}

boost::posix_time::ptime Date::recent(int days)
{
    const auto startDate = boost::posix_time::second_clock::local_time();

    const auto endDate =
        boost::posix_time::second_clock::local_time() - boost::posix_time::hours(numberOfHoursInDay * days);

    return fromRange(startDate, endDate);
}

boost::posix_time::ptime Date::birthDateByAge(int minAge, int maxAge)
{
    const auto startDate = boost::posix_time::second_clock::local_time() -
                           boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * maxAge);

    const auto endDate = boost::posix_time::second_clock::local_time() -
                         boost::posix_time::hours(numberOfHoursInDay * numberOfDaysInYear * minAge);

    return fromRange(startDate, endDate);
}

boost::posix_time::ptime Date::birthDateByYear(int minYear, int maxYear)
{
    boost::posix_time::ptime startDate{boost::gregorian::date(minYear, 1, 1)};
    boost::posix_time::ptime endDate{boost::gregorian::date(maxYear, 12, 31)};

    return fromRange(startDate, endDate);
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
    return to_iso_extended_string(birthDateByAge(minAge, maxAge));
}

std::string Date::birthDateByYearISOString(int minYear, int maxYear)
{
    return to_iso_extended_string(birthDateByYear(minYear, maxYear));
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
