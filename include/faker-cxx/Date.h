#pragma once

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
     * @returns ISO formatted string
     *
     * @code
     * Date::past() // "2023-12-08T19:31:32Z"
     * Date::past(5) // "2020-06-16T15:24:09Z"
     * @endcode
     */
    static std::string pastDate(int years = 1);

    /**
     * @brief Generates a random date in the future.
     *
     * @param years The range of years the date may be in the future. Defaults to `1`.
     *
     * @returns ISO formatted string
     *
     * @code
     * Date::future() // "2023-09-27T09:47:46Z"
     * Date::future(5) // "2024-06-11T19:46:29Z"
     * @endcode
     */
    static std::string futureDate(int years = 1);

    /**
     * @brief Generates a random date in the recent past.
     *
     * @param days The range of days the date may be in the past. Defaults to `3`.
     *
     * @returns ISO formatted string
     *
     * @code
     * Date::recent() // "2023-07-05T14:12:40Z"
     * Date::recent(10) // "2023-06-29T18:24:12Z"
     * @endcode
     */
    static std::string recentDate(int days = 3);

    /**
     * @brief Generates a random date in the soon future.
     *
     * @param days The range of days the date may be in the future. Defaults to `3`.
     *
     * @returns ISO formatted string
     *
     * @code
     * Date::soon() // "2023-07-07T18:19:12Z"
     * Date::soon(10) // "2023-07-15T09:59:11Z"
     * @endcode
     */
    static std::string soonDate(int days = 3);

    /**
     * @brief Generates a random birthdate by age.
     *
     * @param minAge The minimum age to generate a birthdate. Defaults to `18`.
     * @param maxAge The maximum age to generate a birthdate. Defaults to `80`.
     *
     * @returns ISO formatted string
     *
     * @code
     * Date::birthdateByAge() // "2002-12-07T23:20:12Z"
     * Date::birthdateByAge(20, 30) // "1996-11-14T11:27:09Z"
     * @endcode
     */
    static std::string birthdateByAge(int minAge = 18, int maxAge = 80);

    /**
     * @brief Generates a random birthdate by year.
     *
     * @param minYear The minimum year to generate a birthdate. Defaults to `1920`.
     * @param maxAge The maximum year to generate a birthdate. Defaults to `2000`.
     *
     * @returns ISO formatted string
     *
     * @code
     * Date::birthdateByYear() // "1965-02-19T02:19:47Z"
     * Date::birthdateByYear(1996, 1996) // "1996-05-19T12:00:23Z"
     * @endcode
     */
    static std::string birthdateByYear(int minYear = 1920, int maxYear = 2000);

    /**
     * @brief Returns a name of random day of the week.
     *
     * @returns Name of the weekday
     *
     * @code
     * Date::weekdayName() // "Monday"
     * @endcode
     */
    static std::string weekdayName();

    /**
     * @brief Returns an abbreviated name of random day of the week.
     *
     * @returns Abbreviated name of the weekday
     *
     * @code
     * Date::weekdayAbbreviatedName() // "Mon"
     * @endcode
     */
    static std::string weekdayAbbreviatedName();

    /**
     * @brief Returns a random name of a month.
     *
     * @returns Name of the month
     *
     * @code
     * Date::monthName() // "October"
     * @endcode
     */
    static std::string monthName();

    /**
     * @brief Returns an abbreviated name of random month.
     *
     * @returns Abbreviated name of the month
     *
     * @code
     * Date::monthAbbreviatedName() // "Feb"
     * @endcode
     */
    static std::string monthAbbreviatedName();
};
}
