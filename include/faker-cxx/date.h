#pragma once

#include <string>
#include <string_view>

#include "faker-cxx/export.h"

namespace faker::date
{
enum class DateFormat
{
    ISO,
    Timestamp,
};

/**
 * @brief Generates a random date between UNIX epoch and 200 years from now
 *
 * @returns ISO formatted string.
 *
 * @code
 * faker::date::anytime() // "2023-12-08T19:31:32Z"
 * faker::date::anytime(DateFormat::ISO) // "2020-06-16T15:24:09Z"
 * faker::date::anytime(DateFormat::Timestamp) // "1592321049"
 * @endcode
 */
FAKER_CXX_EXPORT std::string anytime(DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Generates a random date in the past.
 *
 * @param years The range of years the date may be in the past. Defaults to `1`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * faker::date::pastDate() // "2023-12-08T19:31:32Z"
 * faker::date::pastDate(5) // "2020-06-16T15:24:09Z"
 * faker::date::pastDate(5, DateFormat::ISO) // "2020-06-16T15:24:09Z"
 * faker::date::pastDate(5, DateFormat::Timestamp) // "1592321049"
 * @endcode
 */
FAKER_CXX_EXPORT std::string pastDate(int years = 1, DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Generates a random date in the future.
 *
 * @param years The range of years the date may be in the future. Defaults to `1`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * faker::date::futureDate() // "2023-09-27T09:47:46Z"
 * faker::date::futureDate(5) // "2024-06-11T19:46:29Z"
 * faker::date::futureDate(5, DateFormat::ISO) // "2024-06-11T19:46:29Z"
 * faker::date::futureDate(5, DateFormat::Timestamp) // "1718229989"
 * @endcode
 */
FAKER_CXX_EXPORT std::string futureDate(int years = 1, DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Generates a random date in the recent past.
 *
 * @param days The range of days the date may be in the past. Defaults to `3`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * faker::date::recentDate() // "2023-07-05T14:12:40Z"
 * faker::date::recentDate(10) // "2023-06-29T18:24:12Z"
 * faker::date::recentDate(10, DateFormat::ISO) // "2023-06-29T18:24:12Z"
 * faker::date::recentDate(10, DateFormat::Timestamp) // "1718229989"
 * @endcode
 */
FAKER_CXX_EXPORT std::string recentDate(int days = 3, DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Generates a random date in the soon future.
 *
 * @param days The range of days the date may be in the future. Defaults to `3`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * faker::date::soonDate() // "2023-07-07T18:19:12Z"
 * faker::date::soonDate(10) // "2023-07-15T09:59:11Z"
 * faker::date::soonDate(10, DateFormat::ISO) // "2023-07-15T09:59:11Z"
 * faker::date::soonDate(10, DateFormat::Timestamp) // "1718229989"
 * @endcode
 */
FAKER_CXX_EXPORT std::string soonDate(int days = 3, DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Generates a random birthdate by age.
 *
 * @param minAge The minimum age to generate a birthdate. Defaults to `18`.
 * @param maxAge The maximum age to generate a birthdate. Defaults to `80`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * faker::date::birthdateByAge() // "2002-12-07T23:20:12Z"
 * faker::date::birthdateByAge(20, 30) // "1996-11-14T11:27:09Z"
 * faker::date::birthdateByAge(20, 30, DateFormat::ISO) // "1996-11-14T11:27:09Z"
 * faker::date::birthdateByAge(20, 30, DateFormat::Timestamp) // "1718229989"
 * @endcode
 */
FAKER_CXX_EXPORT std::string birthdateByAge(int minAge = 18, int maxAge = 80, DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Generates a random birthdate by year.
 *
 * @param minYear The minimum year to generate a birthdate. Defaults to `1920`.
 * @param maxYear The maximum year to generate a birthdate. Defaults to `2000`.
 *
 * @returns ISO formatted string.
 *
 * @code
 * faker::date::birthdateByYear() // "1965-02-19T02:19:47Z"
 * faker::date::birthdateByYear(1996, 1996) // "1996-05-19T12:00:23Z"
 * faker::date::birthdateByYear(1996, 1996, DateFormat::ISO) // "1996-05-19T12:00:23Z"
 * faker::date::birthdateByYear(1996, 1996, DateFormat::Timestamp) // "1718229989"
 * @endcode
 */
FAKER_CXX_EXPORT std::string birthdateByYear(int minYear = 1920, int maxYear = 2000,
                                             DateFormat dateFormat = DateFormat::ISO);

/**
 * @brief Returns a name of random day of the week.
 *
 * @returns Name of the weekday.
 *
 * @code
 * faker::date::weekdayName() // "Monday"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view weekdayName();

/**
 * @brief Returns an abbreviated name of random day of the week.
 *
 * @returns Abbreviated name of the weekday.
 *
 * @code
 * faker::date::weekdayAbbreviatedName() // "Mon"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view weekdayAbbreviatedName();

/**
 * @brief Returns a random name of a month.
 *
 * @returns Name of the month.
 *
 * @code
 * faker::date::monthName() // "October"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view monthName();

/**
 * @brief Returns an abbreviated name of random month.
 *
 * @returns Abbreviated name of the month.
 *
 * @code
 * faker::date::monthAbbreviatedName() // "Feb"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view monthAbbreviatedName();

/**
 * @brief Returns random year.
 *
 * @returns A random year
 *
 * @code
 * faker::date::year() // 2000
 * @endcode
 */
FAKER_CXX_EXPORT unsigned year();

/**
 * @brief Returns random month.
 *
 * @returns A random month
 *
 * @code
 * faker::date::month() // 9
 * @endcode
 */
FAKER_CXX_EXPORT unsigned month();

/**
 * @brief Returns random hour.
 *
 * @returns A random month
 *
 * @code
 * faker::date::hour() // 21
 * @endcode
 */
FAKER_CXX_EXPORT unsigned hour();

/**
 * @brief Returns random minute.
 *
 * @returns A random minute
 *
 * @code
 * faker::date::minute() // 40
 * @endcode
 */
FAKER_CXX_EXPORT unsigned minute();

/**
 * @brief Returns random second.
 *
 * @returns A random second
 *
 * @code
 * faker::date::second() // 40
 * @endcode
 */
FAKER_CXX_EXPORT unsigned second();

/**
 * @brief Returns random time string.
 *
 * @returns A random time string
 *
 * @code
 * faker::date::time() // 21:40
 * @endcode
 */
FAKER_CXX_EXPORT std::string time();

/**
 * @brief Returns random day of month.
 *
 * @returns A random day of month
 *
 * @code
 * faker::date::dayOfMonth() // 15
 * @endcode
 */
FAKER_CXX_EXPORT unsigned dayOfMonth();

/**
 * @brief Returns random day of week.
 *
 * @returns A random day of week
 *
 * @code
 * faker::date::dayOfWeek() // 5
 * @endcode
 */
FAKER_CXX_EXPORT unsigned dayOfWeek();

/**
 * @brief Returns random timezone.
 *
 * @returns A random timezone
 *
 * @code
 * faker::date::timezoneRandom() // PT
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view timezoneRandom();
}
