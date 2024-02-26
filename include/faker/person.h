#ifndef FAKER_PERSON_H
#define FAKER_PERSON_H

#include <faker/types/country.h>
#include <optional>
#include <string>

namespace faker::person {
enum class Sex {
    Male,
    Female,
};

enum class Language {
    English,
    Polish,
    French,
    German,
    Italian,
    Russian,
    Romanian,
    Hindi,
    Finnish,
    Nepali,
    Spanish,
    Turkish,
    Czech,
    Slovak,
    Ukrainian,
    Danish,
    Swedish,
    Portuguese,
    Norwegian,
    Japanese,
    Hungarian,
    Croatian,
    Greek,
    Slovene,
    Dutch,
    Mandarin,
    Korean,
    Serbian,
    Macedonian,
    Albanian,
    Latvian,
    Irish,
    Belarusian,
    Estonian
};

std::string_view to_string(Sex sex, Language language = Language::English);

enum class SsnCountry {
    Poland,
    UnitedStates,
    UnitedKingdom,
    Germany,
    France,
    Italy,
    Spain,
    India,
};

/**
 * @brief Returns a random first name.
 *
 * @param country The local country. Defaults to `Country::England`.
 * @param sex The optional sex to use.
 *
 * @returns First name starting with a capital letter.
 *
 * @code
 * person::first_name() // "Michael"
 * person::first_name(Country::England, Sex::Female) // "Emma"
 * person::first_name(Country::England, Sex::Male) // "Arthur"
 * @endcode
 */
std::string first_name(Country country = Country::England, std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random last name.
 *
 * @param country The local country. Defaults to `Country::England`.
 * @param sex The optional sex to use.
 *
 * @returns Last name starting with a capital letter.
 *
 * @code
 * person::last_name() // "Peterson"
 * @endcode
 */
std::string last_name(Country country = Country::England, std::optional<Sex> sex = std::nullopt);

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
std::string middle_name(std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random full name.
 *
 * @param country The local country. Defaults to `Country::England`.
 * @param sex The optional sex to use.
 *
 * @returns Full name starting with first name.
 *
 * @code
 * person::full_name() // "Marcia Robinson"
 * person::full_name(Country::England, Sex::Female) // "Jennifer Martin"
 * person::full_name(Country::England, Sex::Male) // "Samuel Walker"
 * @endcode
 */
std::string full_name(Country country = Country::England, std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random name prefix.
 *
 * @param sex The optional sex to use.
 *
 * @returns Name prefix.
 *
 * @code
 * person::prefix() // "Miss"
 * person::prefix(Sex::Female) // "Ms."
 * person::prefix(Sex::Male) // "Mr."
 * @endcode
 */
std::string prefix(std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random name suffix.
 *
 * @returns Name suffix.
 *
 * @code
 * person::suffix() // "Jr."
 * @endcode
 */
std::string suffix();

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
 * person::sex() // "Male"
 * @endcode
 */
std::string_view sex(Language language = Language::English);

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
 * person::language() // "Polish"
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
 * person::ssn(SsnCountry::Polish) // "95111901567"
 * @endcode
 */
std::string ssn(std::optional<SsnCountry> country);

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