#include "../common/format_helper.h"
#include "../common/helper.h"
#include "date_data.h"
#include <chrono>
#include <ctime>
#include <faker/date.h>
#include <faker/number.h>

namespace faker::date {
namespace {

    template <typename T> std::string serializeTimePoint(const T& timePoint, DateFormat dateFormat)
    {
        std::time_t timePointTimeT = std::chrono::system_clock::to_time_t(timePoint);

        if (dateFormat == DateFormat::Timestamp) {
            return std::to_string(
                std::chrono::duration_cast<std::chrono::seconds>(timePoint.time_since_epoch())
                    .count());
        }

        std::tm utcTime = *std::gmtime(&timePointTimeT);

        return FormatHelper::format("{0:%Y-%m-%d}T{0:%H:%M:%S}Z", utcTime);
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

std::string future(int years, DateFormat dateFormat)
{
    const auto startDate = std::chrono::system_clock::now() + std::chrono::hours { 1 };

    const auto endDate
        = startDate + std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * years };

    return betweenDate(startDate, endDate, dateFormat);
}

std::string past(int years, DateFormat dateFormat)
{
    const auto startDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * years };

    const auto endDate = std::chrono::system_clock::now() - std::chrono::hours { 1 };

    return betweenDate(startDate, endDate, dateFormat);
}

std::string soon(int days, DateFormat dateFormat)
{
    const auto startDate = std::chrono::system_clock::now() + std::chrono::hours { 1 };

    const auto endDate = startDate + std::chrono::hours { numberOfHoursInDay * days };

    return betweenDate(startDate, endDate, dateFormat);
}

std::string recent(int days, DateFormat dateFormat)
{
    const auto startDate
        = std::chrono::system_clock::now() - std::chrono::hours { numberOfHoursInDay * days };

    const auto endDate = std::chrono::system_clock::now() - std::chrono::hours { 1 };

    return betweenDate(startDate, endDate, dateFormat);
}

std::string birthdate_by_age(int minAge, int maxAge, DateFormat dateFormat)
{
    const auto startDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * maxAge };

    const auto endDate = std::chrono::system_clock::now()
        - std::chrono::hours { numberOfHoursInDay * numberOfDaysInYear * minAge };

    return betweenDate(startDate, endDate, dateFormat);
}

std::string birthdate_by_year(int minYear, int maxYear, DateFormat dateFormat)
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

std::string_view weekday_name() { return Helper::arrayElement(data::weekdayNames); }

std::string_view weekday_abbr_name() { return Helper::arrayElement(data::weekdayAbbreviatedNames); }

std::string_view month_name() { return Helper::arrayElement(data::monthNames); }

std::string_view month_abbr_name() { return Helper::arrayElement(data::monthAbbreviatedNames); }

}
