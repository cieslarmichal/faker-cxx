#include "../common/formatter.h"
#include "../common/random.h"
#include "date_data.h"
#include <chrono>
#include <ctime>
#include <faker/date.h>
#include <faker/number.h>

namespace faker::date {
namespace {
    constexpr unsigned hours_per_day = 24;
    constexpr unsigned days_per_year = 365;

    template <typename T> std::string serialize_time_point(const T& time_point, date_format format)
    {
        auto timestamp = std::chrono::system_clock::to_time_t(time_point);

        if (format == date_format::timestamp) {
            return std::to_string(
                std::chrono::duration_cast<std::chrono::seconds>(time_point.time_since_epoch())
                    .count());
        }

        auto utc_time = *std::gmtime(&timestamp);

        return utils::format("{0:%Y-%m-%d}T{0:%H:%M:%S}Z", utc_time);
    }

    template <typename T> std::string date_between(const T& from, const T& to, date_format format)
    {
        if (from > to) {
            throw std::runtime_error { utils::format(
                "Start date is greater than end date. {{from: {}, to: {}}}",
                serialize_time_point(from, format), serialize_time_point(to, format)) };
        }

        std::chrono::seconds::rep ticks
            = std::chrono::duration_cast<std::chrono::seconds>(to - from).count();
        auto date = from + std::chrono::seconds { number::integer(ticks - 1) };

        return serialize_time_point(date, format);
    }
}

std::string future(int years, date_format format)
{
    auto start = std::chrono::system_clock::now() + std::chrono::hours { 1 };
    auto end = start + std::chrono::hours { hours_per_day * days_per_year * years };
    return date_between(start, end, format);
}

std::string past(int years, date_format format)
{
    auto start = std::chrono::system_clock::now()
        - std::chrono::hours { hours_per_day * days_per_year * years };
    auto end = std::chrono::system_clock::now() - std::chrono::hours { 1 };
    return date_between(start, end, format);
}

std::string soon(int days, date_format format)
{
    auto start = std::chrono::system_clock::now() + std::chrono::hours { 1 };
    auto end = start + std::chrono::hours { hours_per_day * days };
    return date_between(start, end, format);
}

std::string recent(int days, date_format format)
{
    auto start = std::chrono::system_clock::now() - std::chrono::hours { hours_per_day * days };
    auto end = std::chrono::system_clock::now() - std::chrono::hours { 1 };
    return date_between(start, end, format);
}

std::string birthdate_by_age(unsigned min_age, unsigned max_age, date_format format)
{
    auto start = std::chrono::system_clock::now()
        - std::chrono::hours { hours_per_day * days_per_year * max_age };
    auto end = std::chrono::system_clock::now()
        - std::chrono::hours { hours_per_day * days_per_year * min_age };
    return date_between(start, end, format);
}

std::string birthdate_by_year(unsigned min_year, unsigned max_year, date_format format)
{
    tm tm_start {};
    tm_start.tm_year = min_year - 1900;
    tm_start.tm_mon = 0;
    tm_start.tm_mday = 1;
    tm_start.tm_hour = 0;
    tm_start.tm_min = 0;
    tm_start.tm_sec = 0;
    tm_start.tm_isdst = -1;

    const auto start = std::chrono::system_clock::from_time_t(mktime(&tm_start));

    tm tm_end {};
    tm_end.tm_year = max_year - 1900;
    tm_end.tm_mon = 11;
    tm_end.tm_mday = 31;
    tm_end.tm_hour = 23;
    tm_end.tm_min = 59;
    tm_end.tm_sec = 59;
    tm_end.tm_isdst = -1;

    const auto end = std::chrono::system_clock::from_time_t(mktime(&tm_end));

    return date_between(start, end, format);
}

std::string_view weekday_name() { return random::element(data::weekday_names); }

std::string_view weekday_abbr_name() { return random::element(data::weekday_abbr_names); }

std::string_view month_name() { return random::element(data::month_names); }

std::string_view month_abbr_name() { return random::element(data::month_abbr_names); }

}
