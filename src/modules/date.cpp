#include "../common/format_helper.h"
#include "date_data.h"
#include <chrono>
#include <ctime>
#include <faker/date.h>
#include <faker/helper.h>
#include <faker/number.h>
#include <iomanip>

namespace faker::date {
namespace {

    template <typename T> std::string serializeTimePoint(const T& timePoint, DateFormat dateFormat)
    {
        time_t timePointTimeT = std::chrono::system_clock::to_time_t(timePoint);

        std::tm utcTime = *std::gmtime(&timePointTimeT);

        std::stringstream ss;

        if (dateFormat == DateFormat::Timestamp) {
            ss << std::chrono::duration_cast<std::chrono::seconds>(timePoint.time_since_epoch())
                      .count();
        }

        else {
            ss << std::put_time(&utcTime, "%Y-%m-%dT%H:%M:%SZ");
        }

        return ss.str();
    }

    template <typename T> std::string betweenDate(const T& from, const T& to, DateFormat dateFormat)
    {
        if (from > to) {
            throw std::runtime_error { FormatHelper::format(
                "Start date is greater than end date. {{from: {}, to: {}}}",
                serializeTimePoint(from, dateFormat), serializeTimePoint(to, dateFormat)) };
        }

        const unsigned long size
            = std::chrono::duration_cast<std::chrono::seconds>(to - from).count();

        const auto randomDateWithinRange
            = from + std::chrono::seconds { number::integer(size - 1) };

        return serializeTimePoint(randomDateWithinRange, dateFormat);
    }

    const auto numberOfHoursInDay = 24;
    const auto numberOfDaysInYear = 365;
}

std::string futureDate(int years, DateFormat dateFormat)
{
    const auto startDate = std::chrono::system_clock::now() + std::chrono::hours { 1 };

    const auto endDate
        = startDate + std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * years };

    return betweenDate(startDate, endDate, dateFormat);
}

std::string pastDate(int years, DateFormat dateFormat)
{
    const auto startDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * years };

    const auto endDate = std::chrono::system_clock::now() - std::chrono::hours { 1 };

    return betweenDate(startDate, endDate, dateFormat);
}

std::string soonDate(int days, DateFormat dateFormat)
{
    const auto startDate = std::chrono::system_clock::now() + std::chrono::hours { 1 };

    const auto endDate = startDate + std::chrono::hours { numberOfHoursInDay * days };

    return betweenDate(startDate, endDate, dateFormat);
}

std::string recentDate(int days, DateFormat dateFormat)
{
    const auto startDate
        = std::chrono::system_clock::now() - std::chrono::hours { numberOfHoursInDay * days };

    const auto endDate = std::chrono::system_clock::now() - std::chrono::hours { 1 };

    return betweenDate(startDate, endDate, dateFormat);
}

std::string birthdateByAge(int minAge, int maxAge, DateFormat dateFormat)
{
    const auto startDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * maxAge };

    const auto endDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * minAge };

    return betweenDate(startDate, endDate, dateFormat);
}

std::string birthdateByYear(int minYear, int maxYear, DateFormat dateFormat)
{
    tm startDateTime {};
    startDateTime.tm_year = minYear - 1900;
    startDateTime.tm_mon = 0;
    startDateTime.tm_mday = 1;
    startDateTime.tm_hour = 0;
    startDateTime.tm_min = 0;
    startDateTime.tm_sec = 0;
    startDateTime.tm_isdst = -1;

    const auto startDate = std::chrono::system_clock::from_time_t(mktime(&startDateTime));

    tm endDateTime {};
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

std::string_view weekdayName() { return Helper::arrayElement(weekdayNames); }

std::string_view weekdayAbbreviatedName() { return Helper::arrayElement(weekdayAbbreviatedNames); }

std::string_view monthName() { return Helper::arrayElement(monthNames); }

std::string_view monthAbbreviatedName() { return Helper::arrayElement(monthAbbreviatedNames); }

}
