#include "faker-cxx/Date.h"

#include <chrono>

#include "data/MonthNames.h"
#include "data/WeekdayNames.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"

namespace faker
{
namespace
{
std::string betweenDate(
    std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<int64_t, std::ratio<1, 1000000000>>> from,
    std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<int64_t, std::ratio<1, 1000000000>>> to)
{
    const auto size = std::chrono::duration_cast<std::chrono::seconds>(to - from).count();

    const auto randomDateWithinRange = from + std::chrono::seconds{1} + std::chrono::seconds{Number::integer(size - 1)};

    return std::format("{:%FT%TZ}", std::chrono::floor<std::chrono::seconds>(randomDateWithinRange));
}

const auto numberOfHoursInDay = 24;
const auto numberOfDaysInYear = 365;
}

std::string Date::futureDate(int years)
{
    const auto startDate = std::chrono::system_clock::now();

    const auto endDate =
        std::chrono::system_clock::now() + std::chrono::hours{numberOfHoursInDay * numberOfDaysInYear * years};

    return betweenDate(startDate, endDate);
}

std::string Date::pastDate(int years)
{
    const auto startDate =
        std::chrono::system_clock::now() - std::chrono::hours{numberOfHoursInDay * numberOfDaysInYear * years};

    const auto endDate = std::chrono::system_clock::now();

    return betweenDate(startDate, endDate);
}

std::string Date::soonDate(int days)
{
    const auto startDate = std::chrono::system_clock::now();

    const auto endDate = std::chrono::system_clock::now() + std::chrono::hours{numberOfHoursInDay * days};

    return betweenDate(startDate, endDate);
}

std::string Date::recentDate(int days)
{
    const auto startDate = std::chrono::system_clock::now() - std::chrono::hours{numberOfHoursInDay * days};

    const auto endDate = std::chrono::system_clock::now();

    return betweenDate(startDate, endDate);
}

std::string Date::birthdateByAge(int minAge, int maxAge)
{
    const auto startDate =
        std::chrono::system_clock::now() - std::chrono::hours{numberOfHoursInDay * numberOfDaysInYear * maxAge};

    const auto endDate =
        std::chrono::system_clock::now() - std::chrono::hours{numberOfHoursInDay * numberOfDaysInYear * minAge};

    return betweenDate(startDate, endDate);
}

std::string Date::birthdateByYear(int minYear, int maxYear)
{
    tm startDateTime{};
    startDateTime.tm_year = minYear - 1900;
    startDateTime.tm_mon = 0;
    startDateTime.tm_mday = 0;
    startDateTime.tm_hour = 0;
    startDateTime.tm_min = 0;
    startDateTime.tm_sec = 0;
    startDateTime.tm_isdst = -1;

    const auto startDate = std::chrono::system_clock::from_time_t(mktime(&startDateTime));

    tm endDateTime{};
    endDateTime.tm_year = maxYear - 1900;
    endDateTime.tm_mon = 11;
    endDateTime.tm_mday = 31;
    endDateTime.tm_hour = 23;
    endDateTime.tm_min = 59;
    endDateTime.tm_sec = 59;
    endDateTime.tm_isdst = -1;

    const auto endDate = std::chrono::system_clock::from_time_t(mktime(&endDateTime));

    return betweenDate(startDate, endDate);
}

std::string Date::weekdayName()
{
    return Helper::arrayElement<std::string>(weekdayNames);
}
std::string Date::weekdayAbbreviatedName()
{
    return Helper::arrayElement<std::string>(weekdayAbbreviatedNames);
}

std::string Date::monthName()
{
    return Helper::arrayElement<std::string>(monthNames);
}

std::string Date::monthAbbreviatedName()
{
    return Helper::arrayElement<std::string>(monthAbbreviatedNames);
}

}
