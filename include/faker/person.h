#ifndef FAKER_PERSON_H
#define FAKER_PERSON_H

#include <faker/types/country.h>
#include <optional>
#include <string>

namespace faker::person {
enum class sex_t {
    male,
    female,
};

enum class language_t {
    english,
    polish,
    french,
    german,
    italian,
    russian,
    romanian,
    hindi,
    finnish,
    nepali,
    spanish,
    turkish,
    czech,
    slovak,
    ukrainian,
    danish,
    swedish,
    portuguese,
    norwegian,
    japanese,
    hungarian,
    croatian,
    greek,
    slovene,
    dutch,
    mandarin,
    korean,
    serbian,
    macedonian,
    albanian,
    latvian,
    irish,
    belarusian,
    estonian
};

std::string_view to_string(sex_t sex, language_t lang = language_t::english);

enum class ssn_country_t {
    poland,
    usa,
    england,
    germany,
    france,
    italy,
    spain,
    india,
};

/**
 * @brief Returns a random first name.
 *
 * @param country The local country. Defaults to `country_t::england`.
 * @param sex The optional sex to use.
 *
 * @returns First name starting with a capital letter.
 *
 * @code
 * person::first_name() // "Michael"
 * person::first_name(country_t::england, sex_t::female) // "Emma"
 * person::first_name(country_t::england, sex_t::male) // "Arthur"
 * @endcode
 */
std::string_view first_name(
    country_t country = country_t::england, std::optional<sex_t> sex = std::nullopt);

/**
 * @brief Returns a random last name.
 *
 * @param country The local country. Defaults to `country_t::england`.
 * @param sex The optional sex to use.
 *
 * @returns Last name starting with a capital letter.
 *
 * @code
 * person::last_name() // "Peterson"
 * @endcode
 */
std::string_view last_name(
    country_t country = country_t::england, std::optional<sex_t> sex = std::nullopt);

/**
 * @brief Returns a random middle name.
 *
 * @param sex The optional sex to use.
 *
 * @returns Middle name starting with a capital letter.
 *
 * @code
 * person::middle_name() // "Васильевич"
 * @endcode
 */
std::string_view middle_name(std::optional<sex_t> sex = std::nullopt);

/**
 * @brief Returns a random full name.
 *
 * @param country The local country. Defaults to `country_t::england`.
 * @param sex The optional sex to use.
 *
 * @returns Full name starting with first name.
 *
 * @code
 * person::full_name() // "Marcia Robinson"
 * person::full_name(country_t::england, sex_t::female) // "Jennifer Martin"
 * person::full_name(country_t::england, sex_t::male) // "Samuel Walker"
 * @endcode
 */
std::string full_name(
    country_t country = country_t::england, std::optional<sex_t> sex = std::nullopt);

/**
 * @brief Returns a random name prefix.
 *
 * @param sex The optional sex to use.
 *
 * @returns Name prefix.
 *
 * @code
 * person::prefix() // "Miss"
 * person::prefix(sex_t::female) // "Ms."
 * person::prefix(sex_t::male) // "Mr."
 * @endcode
 */
std::string_view prefix(std::optional<sex_t> sex = std::nullopt);

/**
 * @brief Returns a random name suffix.
 *
 * @returns Name suffix.
 *
 * @code
 * person::suffix() // "Jr."
 * @endcode
 */
std::string_view suffix();

/**
 * @brief Returns a random bio.
 *
 * @returns Bio.
 *
 * @code
 * person::bio() //"Developer"
 * @endcode
 */
std::string bio();

/**
 * @brief Returns a sex.
 *
 * @returns Sex.
 *
 * @code
 * person::sex() // "male"
 * @endcode
 */
std::string_view sex(language_t lang = language_t::english);

/**
 * @brief Returns a random gender.
 *
 * @returns Gender.
 *
 * @code
 * person::gender() // "Transexual woman"
 * @endcode
 */
std::string_view gender();

/**
 * @brief Returns a random job title.
 *
 * @returns Job title.
 *
 * @code
 * person::job_title() // "Global Accounts Engineer"
 * @endcode
 */
std::string job_title();

/**
 * @brief Returns a random job descriptor.
 *
 * @returns Job descriptor.
 *
 * @code
 * person::job_descriptor() // "Senior"
 * @endcode
 */
std::string_view job_descriptor();

/**
 * @brief Returns a random job area.
 *
 * @returns Job area.
 *
 * @code
 * person::job_area() // "Software"
 * @endcode
 */
std::string_view job_area();

/**
 * @brief Returns a random job type.
 *
 * @returns Job type.
 *
 * @code
 * person::job_type() // "Engineer"
 * @endcode
 */
std::string_view job_type();

/**
 * @brief Returns a random hobby.
 *
 * @returns Hobby.
 *
 * @code
 * person::hobby() // "Gaming"
 * @endcode
 */
std::string_view hobby();

/**
 * @brief Returns a random language.
 *
 * @returns Language.
 *
 * @code
 * person::lang() // "Polish"
 * @endcode
 */
std::string_view language();

/**
 * @brief Returns a random nationality.
 *
 * @returns Nationality.
 *
 * @code
 * person::nationality() // "Romanian"
 * @endcode
 */
std::string_view nationality();

/**
 * @brief Returns a random SSN.
 *
 * @param country The optional country to use.
 *
 * @returns Social Security Number.
 *
 * @code
 * person::ssn() // "437-12-6854"
 * person::ssn(ssn_country_t::polish) // "95111901567"
 * @endcode
 */
std::string ssn(std::optional<ssn_country_t> country);

/**
 * @brief Returns a random Western Zodiac
 *
 * @returns Western Zodiac
 *
 * @code
 * person::western_zodiac() // "Virgo"
 * @endcode
 */
std::string_view western_zodiac();

/**
 * @brief Returns a random Chinese Zodiac
 *
 * @returns Chinese Zodiac
 *
 * @code
 * person::chinese_zodiac() // "Dragon"
 * @endcode
 */
std::string_view chinese_zodiac();
}

#endif