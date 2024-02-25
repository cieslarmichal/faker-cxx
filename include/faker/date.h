#pragma once

#include <string>

namespace faker::date {
enum class DateFormat {
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
 * date::pastDate() // "2023-12-08T19:31:32Z"
 * date::pastDate(5) // "2020-06-16T15:24:09Z"
 * date::pastDate(5, date::DateFormat::ISO) // "2020-06-16T15:24:09Z"
 * date::pastDate(5, date::DateFormat::Timestamp) // "1592321049"
 * @endcode
 */
std::string pastDate(int years = 1, DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Generates a random date in the future.
 *
 * @param years The range of years the date may be in the future. Defaults to `1`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * date::futureDate() // "2023-09-27T09:47:46Z"
 * date::futureDate(5) // "2024-06-11T19:46:29Z"
 * date::futureDate(5, date::DateFormat::ISO) // "2024-06-11T19:46:29Z"
 * date::futureDate(5, date::DateFormat::Timestamp) // "1718229989"
 * @endcode
 */
std::string futureDate(int years = 1, DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Generates a random date in the recent past.
 *
 * @param days The range of days the date may be in the past. Defaults to `3`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * date::recentDate() // "2023-07-05T14:12:40Z"
 * date::recentDate(10) // "2023-06-29T18:24:12Z"
 * date::recentDate(10, date::DateFormat::ISO) // "2023-06-29T18:24:12Z"
 * date::recentDate(10, date::DateFormat::Timestamp) // "1718229989"
 * @endcode
 */
std::string recentDate(int days = 3, DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Generates a random date in the soon future.
 *
 * @param days The range of days the date may be in the future. Defaults to `3`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * date::soonDate() // "2023-07-07T18:19:12Z"
 * date::soonDate(10) // "2023-07-15T09:59:11Z"
 * date::soonDate(10, date::DateFormat::ISO) // "2023-07-15T09:59:11Z"
 * date::soonDate(10, date::DateFormat::Timestamp) // "1718229989"
 * @endcode
 */
std::string soonDate(int days = 3, DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Generates a random birthdate by age.
 *
 * @param minAge The minimum age to generate a birthdate. Defaults to `18`.
 * @param maxAge The maximum age to generate a birthdate. Defaults to `80`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * date::birthdateByAge() // "2002-12-07T23:20:12Z"
 * date::birthdateByAge(20, 30) // "1996-11-14T11:27:09Z"
 * date::birthdateByAge(20, 30, date::DateFormat::ISO) // "1996-11-14T11:27:09Z"
 * date::birthdateByAge(20, 30, date::DateFormat::Timestamp) // "1718229989"
 * @endcode
 */
std::string birthdateByAge(
    int minAge = 18, int maxAge = 80, DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Generates a random birthdate by year.
 *
 * @param minYear The minimum year to generate a birthdate. Defaults to `1920`.
 * @param maxYear The maximum year to generate a birthdate. Defaults to `2000`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * date::birthdateByYear() // "1965-02-19T02:19:47Z"
 * date::birthdateByYear(1996, 1996) // "1996-05-19T12:00:23Z"
 * date::birthdateByYear(1996, 1996, date::DateFormat::ISO) // "1996-05-19T12:00:23Z"
 * date::birthdateByYear(1996, 1996, date::DateFormat::Timestamp) // "1718229989"
 * @endcode
 */
std::string birthdateByYear(
    int minYear = 1920, int maxYear = 2000, DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Returns a name of random day of the week.
 *
 * @returns Name of the weekday.
 *
 * @code
 * date::weekdayName() // "Monday"
 * @endcode
 */
std::string_view weekdayName();

/**
 * @brief Returns an abbreviated name of random day of the week.
 *
 * @returns Abbreviated name of the weekday.
 *
 * @code
 * date::weekdayAbbreviatedName() // "Mon"
 * @endcode
 */
std::string_view weekdayAbbreviatedName();

/**
 * @brief Returns a random name of a month.
 *
 * @returns Name of the month.
 *
 * @code
 * date::monthName() // "October"
 * @endcode
 */
std::string_view monthName();

/**
 * @brief Returns an abbreviated name of random month.
 *
 * @returns Abbreviated name of the month.
 *
 * @code
 * date::monthAbbreviatedName() // "Feb"
 * @endcode
 */
std::string_view monthAbbreviatedName();
}
