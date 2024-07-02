#include "faker-cxx/Date.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>

#include "../../common/FormatHelper.h"
#include "DateData.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"

namespace faker::date
{
std::string serializeTimePoint(const auto& timePoint, DateFormat dateFormat)
{
    time_t timePointTimeT = std::chrono::system_clock::to_time_t(timePoint);

    std::tm utcTime = *std::gmtime(&timePointTimeT);

    std::stringstream ss;

    if (dateFormat == DateFormat::Timestamp)
    {
        ss << std::chrono::duration_cast<std::chrono::seconds>(timePoint.time_since_epoch()).count();
    }

    else
    {
        ss << std::put_time(&utcTime, "%Y-%m-%dT%H:%M:%SZ");
    }

    return ss.str();
}

std::string betweenDate(const auto& from, const auto& to, DateFormat dateFormat)
{
    if (from > to)
    {
        throw std::runtime_error{common::format("Start date is greater than end date. {{from: {}, to: {}}}",
                                                      serializeTimePoint(from, dateFormat),
                                                      serializeTimePoint(to, dateFormat))};
    }

    const auto size = std::chrono::duration_cast<std::chrono::seconds>(to - from).count();

    const auto randomDateWithinRange = from + std::chrono::seconds{number::integer(size - 1)};

    return serializeTimePoint(randomDateWithinRange, dateFormat);
}

const auto numberOfHoursInDay = 24;
const auto numberOfDaysInYear = 365;

std::string futureDate(int years, DateFormat dateFormat)
{
    const auto startDate = std::chrono::system_clock::now() + std::chrono::hours{1};

    const auto endDate = startDate + std::chrono::hours{numberOfHoursInDay * numberOfDaysInYear * years};

    return betweenDate(startDate, endDate, dateFormat);
}

std::string pastDate(int years, DateFormat dateFormat)
{
    const auto startDate =
        std::chrono::system_clock::now() - std::chrono::hours{numberOfHoursInDay * numberOfDaysInYear * years};

    const auto endDate = std::chrono::system_clock::now() - std::chrono::hours{1};

    return betweenDate(startDate, endDate, dateFormat);
}

std::string soonDate(int days, DateFormat dateFormat)
{
    const auto startDate = std::chrono::system_clock::now() + std::chrono::hours{1};

    const auto endDate = startDate + std::chrono::hours{numberOfHoursInDay * days};

    return betweenDate(startDate, endDate, dateFormat);
}

std::string recentDate(int days, DateFormat dateFormat)
{
    const auto startDate = std::chrono::system_clock::now() - std::chrono::hours{numberOfHoursInDay * days};

    const auto endDate = std::chrono::system_clock::now() - std::chrono::hours{1};

    return betweenDate(startDate, endDate, dateFormat);
}

std::string birthdateByAge(int minAge, int maxAge, DateFormat dateFormat)
{
    const auto startDate =
        std::chrono::system_clock::now() - std::chrono::hours{numberOfHoursInDay * numberOfDaysInYear * maxAge};

    const auto endDate =
        std::chrono::system_clock::now() - std::chrono::hours{numberOfHoursInDay * numberOfDaysInYear * minAge};

    return betweenDate(startDate, endDate, dateFormat);
}

std::string birthdateByYear(int minYear, int maxYear, DateFormat dateFormat)
{
    tm startDateTime{};
    startDateTime.tm_year = minYear - 1900;
    startDateTime.tm_mon = 0;
    startDateTime.tm_mday = 1;
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

    return betweenDate(startDate, endDate, dateFormat);
}

std::string_view weekdayName()
{
    return helper::arrayElement(weekdayNames);
}

std::string_view weekdayAbbreviatedName()
{
    return helper::arrayElement(weekdayAbbreviatedNames);
}

std::string_view monthName()
{
    return helper::arrayElement(monthNames);
}

std::string_view monthAbbreviatedName()
{
    return helper::arrayElement(monthAbbreviatedNames);
}

unsigned int year()
{
    unsigned minYear = 1950;
    unsigned maxYear = 2050;

    return number::integer<unsigned>(minYear, maxYear);
}

unsigned int month()
{
    return number::integer<unsigned>(1, 12);
}

unsigned int hour()
{
    return number::integer<unsigned>(0, 23);
}

unsigned int minute()
{
    return number::integer<unsigned>(0, 59);
}

unsigned int second()
{
    return number::integer<unsigned>(0, 59);
}

std::string time()
{
    return common::format("{:02}:{:02}", hour(), minute());
}

unsigned int dayOfMonth()
{
    return number::integer<unsigned>(1, 31);
}

unsigned dayOfWeek()
{
    return number::integer<unsigned>(1, 7);
}

std::string_view timezoneRandom()
{
    return helper::arrayElement(timezonesAbbreviatedNames);
}

}
