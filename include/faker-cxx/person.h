#pragma once

#include <optional>
#include <string>
#include <string_view>

#include "faker-cxx/export.h"
#include "types/locale.h"

namespace faker::person
{
enum class Sex;
enum class Language;

/**
 * @brief Returns a random first name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * @param sex The optional sex to use.
 *
 * @returns First name starting with a capital letter.
 *
 * @code
 * faker::person::firstName() // "Michael"
 * faker::person::firstName(Locale::en_US, Sex::Female) // "Emma"
 * faker::person::firstName(Locale::en_US, Sex::Male) // "Arthur"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view firstName(Locale locale = Locale::en_US, std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random last name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * @param sex The optional sex to use.
 *
 * @returns Last name starting with a capital letter.
 *
 * @code
 * faker::person::lastName() // "Peterson"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view lastName(Locale locale = Locale::en_US, std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random full name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * @param sex The optional sex to use.
 *
 * @returns Full name starting with first name.
 *
 * @code
 * faker::person::fullName() // "Marcia Robinson"
 * faker::person::fullName(Locale::en_US, Sex::Female) // "Jennifer Martin"
 * faker::person::fullName(Locale::en_US, Sex::Male) // "Samuel Walker"
 * @endcode
 */
FAKER_CXX_EXPORT std::string fullName(Locale locale = Locale::en_US, std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random name prefix.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * @param sex The optional sex to use.
 *
 * @returns Name prefix.
 *
 * @code
 * faker::person::prefix() // "Miss"
 * faker::person::prefix(Sex::Female) // "Ms."
 * faker::person::prefix(Sex::Male) // "Mr."
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view prefix(Locale locale = Locale::en_US, std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random name suffix.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 * @param sex The optional sex to use.
 *
 * @returns Name suffix.
 *
 * @code
 * faker::person::suffix() // "Jr."
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view suffix(Locale locale = Locale::en_US, std::optional<Sex> sex = std::nullopt);

/**
 * @brief Returns a random bio.
 *
 * @returns Bio.
 *
 * @code
 * faker::person::bio() //"Developer"
 * @endcode
 */
FAKER_CXX_EXPORT std::string bio();

/**
 * @brief Returns a sex.
 *
 * @returns Sex.
 *
 * @code
 * faker::person::sex() // "Male"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view sex(std::optional<Language> language = std::nullopt);

/**
 * @brief Returns a random gender.
 *
 * @returns Gender.
 *
 * @code
 * faker::person::gender() // "Transexual woman"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view gender();

/**
 * @brief Returns a random job title.
 *
 * @returns Job title.
 *
 * @code
 * faker::person::jobTitle() // "Global Accounts Engineer"
 * @endcode
 */
FAKER_CXX_EXPORT std::string jobTitle();

/**
 * @brief Returns a random job descriptor.
 *
 * @returns Job descriptor.
 *
 * @code
 * faker::person::jobDescriptor() // "Senior"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view jobDescriptor();

/**
 * @brief Returns a random job area.
 *
 * @returns Job area.
 *
 * @code
 * faker::person::jobArea() // "Software"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view jobArea();

/**
 * @brief Returns a random job type.
 *
 * @returns Job type.
 *
 * @code
 * faker::person::jobType() // "Engineer"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view jobType();

/**
 * @brief Returns a random hobby.
 *
 * @returns Hobby.
 *
 * @code
 * faker::person::hobby() // "Gaming"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view hobby();

/**
 * @brief Returns a random language.
 *
 * @returns Language.
 *
 * @code
 * faker::person::language() // "Polish"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view language();

/**
 * @brief Returns a random nationality.
 *
 * @returns Nationality.
 *
 * @code
 * faker::person::nationality() // "Romanian"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view nationality();

/**
 * @brief Returns a random SSN.
 *
 * @param locale The optional locale to use. Defaults to `Locale::en_US`.
 *
 * @returns Social Security Number.
 *
 * @code
 * faker::person::ssn() // "437-12-6854"
 * faker::person::ssn(Locale::pl_PL) // "95111901567"
 * @endcode
 */
FAKER_CXX_EXPORT std::string ssn(Locale locale = Locale::en_US);

/**
 * @brief Returns a random Western Zodiac
 *
 * @returns Western Zodiac
 *
 * @code
 * faker::person::westernZodiac() // "Virgo"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view westernZodiac();

/**
 * @brief Returns a random Chinese Zodiac
 *
 * @returns Chinese Zodiac
 *
 * @code
 * faker::person::chineseZodiac() // "Dragon"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view chineseZodiac();

/**
 * @brief Returns a random passport number from a given country
 *
 * @param locale The optional locale to use. Defaults to `Locale::en_US`.
 *
 * @returns Passport
 *
 * @code
 * faker::person::passport(Locale::pl_PL) // "12345678"
 * @endcode
 */
FAKER_CXX_EXPORT std::string passport(Locale locale = Locale::en_US);

enum class Sex
{
    Female,
    Male,
};

enum class Language
{
    Albanian,
    Belarusian,
    Croatian,
    Czech,
    Danish,
    Dutch,
    English,
    Estonian,
    Finnish,
    French,
    German,
    Greek,
    Hindi,
    Hungarian,
    Irish,
    Italian,
    Japanese,
    Korean,
    Latvian,
    Macedonian,
    Mandarin,
    Nepali,
    Norwegian,
    Polish,
    Portuguese,
    Romanian,
    Russian,
    Serbian,
    Slovak,
    Slovene,
    Spanish,
    Swedish,
    Turkish,
    Ukrainian,
};
}
