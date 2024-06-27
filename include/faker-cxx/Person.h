#pragma once

#include <optional>
#include <string_view>

#include "types/Country.h"

namespace faker::person
{
enum class PassportCountry;
enum class Sex;
enum class SsnCountry;
enum class Language;

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
    std::string_view firstName(std::optional<Country> country = std::nullopt,
                                      std::optional<Sex> sex = std::nullopt);

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
    std::string_view lastName(std::optional<Country> country = std::nullopt,
                                     std::optional<Sex> sex = std::nullopt);

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
    std::string fullName(std::optional<Country> country = std::nullopt, std::optional<Sex> sex = std::nullopt);

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
    std::string_view prefix(std::optional<Country> countryOpt = std::nullopt,
                                   std::optional<Sex> sex = std::nullopt);

    /**
     * @brief Returns a random name suffix.
     *
     * @returns Name suffix.
     *
     * @code
     * person::suffix() // "Jr."
     * @endcode
     */
    std::string_view suffix(std::optional<Country> countryOpt = std::nullopt,
                                   std::optional<Sex> sex = std::nullopt);

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
    std::string_view sex(std::optional<Language> language = std::nullopt);

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
    std::string ssn(std::optional<SsnCountry> country = std::nullopt);

    /**
     * @brief Returns a random Western Zodiac
     *
     * @returns Western Zodiac
     *
     * @code
     * person::westernZodiac() // "Virgo"
     * @endcode
     */
    std::string_view westernZodiac();

    /**
     * @brief Returns a random Chinese Zodiac
     *
     * @returns Chinese Zodiac
     *
     * @code
     * person::chineseZodiac() // "Dragon"
     * @endcode
     */
    std::string_view chineseZodiac();

    /**
     * @brief Returns a random passport number from a given country
     *
     * @returns Passport
     *
     * @code
     * person::passport(PassportCountry::Romania) // "12345678"
     * @endcode
     */
    std::string passport(std::optional<PassportCountry> country = std::nullopt);

enum class PassportCountry
{
    France,
    Poland,
    Romania,
    Usa,
};

enum class Sex
{
    Female,
    Male,
};

enum class SsnCountry
{
    England,
    France,
    Germany,
    India,
    Italy,
    Poland,
    Spain,
    Usa,
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
