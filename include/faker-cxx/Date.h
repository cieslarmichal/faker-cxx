#pragma once

#include <string>

namespace faker
{
class Date
{
public:
    enum class DateFormat
    {
        ISO,
        Timestamp,
    };

    /**
     * @brief Generates a random date in the past.
     *
     * @param years The range of years the date may be in the past. Defaults to `1`.
     *
     * @returns ISO formatted string.
     *
     * @code
     * Date::pastDate() // "2023-12-08T19:31:32Z"
     * Date::pastDate(5) // "2020-06-16T15:24:09Z"
     * Date::pastDate(5, Date::DateFormat::ISO) // "2020-06-16T15:24:09Z"
     * Date::pastDate(5, Date::DateFormat::Timestamp) // "1592321049"
     * @endcode
     */
    static std::string pastDate(int years = 1, DateFormat dateFormat = DateFormat::ISO);

    /**
     * @brief Generates a random date in the future.
     *
     * @param years The range of years the date may be in the future. Defaults to `1`.
     *
     * @returns ISO formatted string.
     *
     * @code
     * Date::futureDate() // "2023-09-27T09:47:46Z"
     * Date::futureDate(5) // "2024-06-11T19:46:29Z"
     * Date::futureDate(5, Date::DateFormat::ISO) // "2024-06-11T19:46:29Z"
     * Date::futureDate(5, Date::DateFormat::Timestamp) // "1718229989"
     * @endcode
     */
    static std::string futureDate(int years = 1, DateFormat dateFormat = DateFormat::ISO);

    /**
     * @brief Generates a random date in the recent past.
     *
     * @param days The range of days the date may be in the past. Defaults to `3`.
     *
     * @returns ISO formatted string.
     *
     * @code
     * Date::recentDate() // "2023-07-05T14:12:40Z"
     * Date::recentDate(10) // "2023-06-29T18:24:12Z"
     * Date::recentDate(10, Date::DateFormat::ISO) // "2023-06-29T18:24:12Z"
     * Date::recentDate(10, Date::DateFormat::Timestamp) // "1718229989"
     * @endcode
     */
    static std::string recentDate(int days = 3, DateFormat dateFormat = DateFormat::ISO);

    /**
     * @brief Generates a random date in the soon future.
     *
     * @param days The range of days the date may be in the future. Defaults to `3`.
     *
     * @returns ISO formatted string.
     *
     * @code
     * Date::soonDate() // "2023-07-07T18:19:12Z"
     * Date::soonDate(10) // "2023-07-15T09:59:11Z"
     * Date::soonDate(10, Date::DateFormat::ISO) // "2023-07-15T09:59:11Z"
     * Date::soonDate(10, Date::DateFormat::Timestamp) // "1718229989"
     * @endcode
     */
    static std::string soonDate(int days = 3, DateFormat dateFormat = DateFormat::ISO);

    /**
     * @brief Generates a random birthdate by age.
     *
     * @param minAge The minimum age to generate a birthdate. Defaults to `18`.
     * @param maxAge The maximum age to generate a birthdate. Defaults to `80`.
     *
     * @returns ISO formatted string.
     *
     * @code
     * Date::birthdateByAge() // "2002-12-07T23:20:12Z"
     * Date::birthdateByAge(20, 30) // "1996-11-14T11:27:09Z"
     * Date::birthdateByAge(20, 30, Date::DateFormat::ISO) // "1996-11-14T11:27:09Z"
     * Date::birthdateByAge(20, 30, Date::DateFormat::Timestamp) // "1718229989"
     * @endcode
     */
    static std::string birthdateByAge(int minAge = 18, int maxAge = 80, DateFormat dateFormat = DateFormat::ISO);

    /**
     * @brief Generates a random birthdate by year.
     *
     * @param minYear The minimum year to generate a birthdate. Defaults to `1920`.
     * @param maxYear The maximum year to generate a birthdate. Defaults to `2000`.
     *
     * @returns ISO formatted string.
     *
     * @code
     * Date::birthdateByYear() // "1965-02-19T02:19:47Z"
     * Date::birthdateByYear(1996, 1996) // "1996-05-19T12:00:23Z"
     * Date::birthdateByYear(1996, 1996, Date::DateFormat::ISO) // "1996-05-19T12:00:23Z"
     * Date::birthdateByYear(1996, 1996, Date::DateFormat::Timestamp) // "1718229989"
     * @endcode
     */
    static std::string birthdateByYear(int minYear = 1920, int maxYear = 2000, DateFormat dateFormat = DateFormat::ISO);

    /**
     * @brief Returns a name of random day of the week.
     *
     * @returns Name of the weekday.
     *
     * @code
     * Date::weekdayName() // "Monday"
     * @endcode
     */
    static std::string weekdayName();

    /**
     * @brief Returns an abbreviated name of random day of the week.
     *
     * @returns Abbreviated name of the weekday.
     *
     * @code
     * Date::weekdayAbbreviatedName() // "Mon"
     * @endcode
     */
    static std::string weekdayAbbreviatedName();

    /**
     * @brief Returns a random name of a month.
     *
     * @returns Name of the month.
     *
     * @code
     * Date::monthName() // "October"
     * @endcode
     */
    static std::string monthName();

    /**
     * @brief Returns an abbreviated name of random month.
     *
     * @returns Abbreviated name of the month.
     *
     * @code
     * Date::monthAbbreviatedName() // "Feb"
     * @endcode
     */
    static std::string monthAbbreviatedName();

    /**
     * @brief Returns random year.
     *
     * @returns A random year
     *
     * @code
     * Date::year() // 2000
     * @endcode
     */
    static unsigned year();

    /**
     * @brief Returns random month.
     *
     * @returns A random month
     *
     * @code
     * Date::month() // 9
     * @endcode
     */
    static unsigned month();

    /**
     * @brief Returns random hour.
     *
     * @returns A random month
     *
     * @code
     * Date::hour() // 21
     * @endcode
     */
    static unsigned hour();

    /**
     * @brief Returns random minute.
     *
     * @returns A random minute
     *
     * @code
     * Date::minute() // 40
     * @endcode
     */
    static unsigned minute();

    /**
     * @brief Returns random second.
     *
     * @returns A random second
     *
     * @code
     * Date::second() // 40
     * @endcode
     */
    static unsigned second();

    /**
     * @brief Returns random time string.
     *
     * @returns A random time string
     *
     * @code
     * Date::time() // 21:40
     * @endcode
     */
    static std::string time();

    /**
     * @brief Returns random day of month.
     *
     * @returns A random day of month
     *
     * @code
     * Date::dayOfMonth() // 15
     * @endcode
     */
    static unsigned dayOfMonth();

    /**
     * @brief Returns random day of week.
     *
     * @returns A random day of week
     *
     * @code
     * Date::dayOfWeek() // 5
     * @endcode
     */
    static unsigned dayOfWeek();

    /**
     * @brief Returns random timezone.
     *
     * @returns A random timezone
     *
     * @code
     * Date::timezone() // PT
     * @endcode
     */
    static std::string timezone();
};
}
