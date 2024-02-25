#pragma once

#include <faker/types/country.h>
#include <faker/types/sex.h>
#include <faker/types/ssn_country.h>
#include <optional>
#include <string>

namespace faker::person {
/**
 * @brief Returns a random first name.
 *
 * @param country The local country. Defaults to `Country::England`.
 * @param sex The optional sex to use.
 *
 * @returns First name starting with a capital letter.
 *
 * @code
 * person::firstName() // "Michael"
 * person::firstName(Country::England, Sex::Female) // "Emma"
 * person::firstName(Country::England, Sex::Male) // "Arthur"
 * @endcode
 */
std::string firstName(Country country = Country::England, std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random last name.
 *
 * @param country The local country. Defaults to `Country::England`.
 * @param sex The optional sex to use.
 *
 * @returns Last name starting with a capital letter.
 *
 * @code
 * person::lastName() // "Peterson"
 * @endcode
 */
std::string lastName(Country country = Country::England, std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random middle name.
 *
 * @param sex The optional sex to use.
 *
 * @returns Middle name starting with a capital letter.
 *
 * @code
 * person::middleName() // "Васильевич"
 * @endcode
 */
std::string middleName(std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random full name.
 *
 * @param country The local country. Defaults to `Country::England`.
 * @param sex The optional sex to use.
 *
 * @returns Full name starting with first name.
 *
 * @code
 * person::fullName() // "Marcia Robinson"
 * person::fullName(Country::England, Sex::Female) // "Jennifer Martin"
 * person::fullName(Country::England, Sex::Male) // "Samuel Walker"
 * @endcode
 */
std::string fullName(Country country = Country::England, std::optional<Sex> sex = std::nullopt);

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
 * person::jobTitle() // "Global Accounts Engineer"
 * @endcode
 */
std::string jobTitle();

/**
 * @brief Returns a random job descriptor.
 *
 * @returns Job descriptor.
 *
 * @code
 * person::jobDescriptor() // "Senior"
 * @endcode
 */
std::string_view jobDescriptor();

/**
 * @brief Returns a random job area.
 *
 * @returns Job area.
 *
 * @code
 * person::jobArea() // "Software"
 * @endcode
 */
std::string_view jobArea();

/**
 * @brief Returns a random job type.
 *
 * @returns Job type.
 *
 * @code
 * person::jobType() // "Engineer"
 * @endcode
 */
std::string_view jobType();

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
 * person::westernZodiac() // "Virgo"
 * @endcode
 */
std::string westernZodiac();

/**
 * @brief Returns a random Chinese Zodiac
 *
 * @returns Chinese Zodiac
 *
 * @code
 * person::chineseZodiac() // "Dragon"
 * @endcode
 */
std::string chineseZodiac();
}
