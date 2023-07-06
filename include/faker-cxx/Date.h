#pragma once

#include <boost/date_time/posix_time/ptime.hpp>
#include <string>

namespace faker
{
class Date
{
public:
    /**
     * @brief Generates a random date in the past.
     *
     * @param years The range of years the date may be in the past. Defaults to `1`.
     *
     * @returns boost posix time
     * @example
     * Date::past() // "2022-Dec-08 19:31:32"
     * Date::past(5) // "2020-Jun-16 15:24:09"
     */
    static boost::posix_time::ptime past(int years = 1);

    /**
     * @brief Generates a random date in the future.
     *
     * @param years The range of years the date may be in the future. Defaults to `1`.
     *
     * @returns boost posix time
     * @example
     * Date::future() // "2023-Sep-27 09:47:46"
     * Date::future(5) // "2024-Jun-11 19:46:29"
     */
    static boost::posix_time::ptime future(int years = 1);

    /**
     * @brief Generates a random date in the recent past.
     *
     * @param days The range of days the date may be in the past. Defaults to `3`.
     *
     * @returns boost posix time
     * @example
     * Date::recent() // "2023-Jul-05 14:12:40"
     * Date::recent(10) // "2023-Jun-29 18:24:12"
     */
    static boost::posix_time::ptime recent(int days = 3);

    /**
     * @brief Generates a random date in the soon future.
     *
     * @param days The range of days the date may be in the future. Defaults to `3`.
     *
     * @returns boost posix time
     * @example
     * Date::soon() // "2023-Jul-07 18:19:12"
     * Date::soon(10) // "2023-Jul-15 09:59:11"
     */
    static boost::posix_time::ptime soon(int days = 3);

    /**
     * @brief Generates a random birthdate by age.
     *
     * @param minAge The minimum age to generate a birthdate. Defaults to `18`.
     * @param maxAge The maximum age to generate a birthdate. Defaults to `80`.
     *
     * @returns boost posix time
     * @example
     * Date::birthdateByAge() // "2002-Dec-07 23:20:12"
     * Date::birthdateByAge(20, 30) // "1996-Nov-14 11:27:09"
     */
    static boost::posix_time::ptime birthdateByAge(int minAge = 18, int maxAge = 80);

    /**
     * @brief Generates a random birthdate by year.
     *
     * @param minYear The minimum year to generate a birthdate. Defaults to `1920`.
     * @param maxAge The maximum year to generate a birthdate. Defaults to `2000`.
     *
     * @returns boost posix time
     * @example
     * Date::birthdateByYear() // "1965-Feb-19 02:19:47"
     * Date::birthdateByYear(1996, 1996) // "1996-May-19 12:00:23"
     */
    static boost::posix_time::ptime birthdateByYear(int minYear = 1920, int maxYear = 2000);

    /**
     * @brief Generates a random date between the given boundaries.
     *
     * @param from The early date boundary.
     * @param to The late date boundary.
     *
     * @returns boost posix time
     * @example
     * Date::between(boost::posix_time::second_clock::local_time(), boost::posix_time::second_clock::local_time() +
     * boost::posix_time::hours(24)) // "2023-Jul-7 11:05:19"
     */
    static boost::posix_time::ptime between(boost::posix_time::ptime from, boost::posix_time::ptime to);

    /**
     * @brief Generates a random date in the past.
     *
     * @param years The range of years the date may be in the past. Defaults to `1`.
     *
     * @returns ISO formatted string
     * @example
     *
     * Date::past() // "2023-12-08T19:31:32"
     * Date::past(5) // "2020-06-16T15:24:09"
     */
    static std::string pastISOString(int years = 1);

    /**
     * @brief Generates a random date in the future.
     *
     * @param years The range of years the date may be in the future. Defaults to `1`.
     *
     * @returns ISO formatted string
     * @example
     * Date::future() // "2023-09-27T09:47:46"
     * Date::future(5) // "2024-06-11T19:46:29"
     */
    static std::string futureISOString(int years = 1);

    /**
     * @brief Generates a random date in the recent past.
     *
     * @param days The range of days the date may be in the past. Defaults to `3`.
     *
     * @returns ISO formatted string
     * @example
     * Date::recent() // "2023-07-05T14:12:40"
     * Date::recent(10) // "2023-06-29T18:24:12"
     */
    static std::string recentISOString(int days = 3);

    /**
     * @brief Generates a random date in the soon future.
     *
     * @param days The range of days the date may be in the future. Defaults to `3`.
     *
     * @returns ISO formatted string
     * @example
     * Date::soon() // "2023-07-07T18:19:12"
     * Date::soon(10) // "2023-07-15T09:59:11"
     */
    static std::string soonISOString(int days = 3);

    /**
     * @brief Generates a random birthdate by age.
     *
     * @param minAge The minimum age to generate a birthdate. Defaults to `18`.
     * @param maxAge The maximum age to generate a birthdate. Defaults to `80`.
     *
     * @returns ISO formatted string
     * @example
     * Date::birthdateByAge() // "2002-12-07T23:20:12"
     * Date::birthdateByAge(20, 30) // "1996-11-14T11:27:09"
     */
    static std::string birthdateByAgeISOString(int minAge = 18, int maxAge = 80);

    /**
     * @brief Generates a random birthdate by year.
     *
     * @param minYear The minimum year to generate a birthdate. Defaults to `1920`.
     * @param maxAge The maximum year to generate a birthdate. Defaults to `2000`.
     *
     * @returns ISO formatted string
     * @example
     * Date::birthdateByYear() // "1965-02-19T02:19:47"
     * Date::birthdateByYear(1996, 1996) // "1996-05-19T12:00:23"
     */
    static std::string birthdateByYearISOString(int minYear = 1920, int maxYear = 2000);

    /**
     * @brief Returns a name of random day of the week.
     *
     * @returns Name of the weekday
     * @example
     * Date::weekdayName() // "Monday"
     */
    static std::string weekdayName();

    /**
     * @brief Returns an abbreviated name of random day of the week.
     *
     * @returns Abbreviated name of the weekday
     * @example
     * Date::weekdayAbbreviatedName() // "Mon"
     */
    static std::string weekdayAbbreviatedName();

    /**
     * @brief Returns a random name of a month.
     *
     * @returns Name of the month
     * @example
     * Date::monthName() // "October"
     */
    static std::string monthName();

    /**
     * @brief Returns an abbreviated name of random month.
     *
     * @returns Abbreviated name of the month
     * @example
     * Date::monthAbbreviatedName() // "Feb"
     */
    static std::string monthAbbreviatedName();
};
}
