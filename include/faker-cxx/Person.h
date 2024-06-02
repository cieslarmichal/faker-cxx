#pragma once

#include <optional>
#include <string_view>

#include "types/Country.h"

namespace faker
{
enum class PassportCountry;
enum class Sex;
enum class SsnCountry;
enum class Language;

class Person
{
public:
    /**
     * @brief Returns a random first name.
     *
     * @param country The local country. Defaults to `Country::England`.
     * @param sex The optional sex to use.
     *
     * @returns First name starting with a capital letter.
     *
     * @code
     * Person::firstName() // "Michael"
     * Person::firstName(Country::England, Sex::Female) // "Emma"
     * Person::firstName(Country::England, Sex::Male) // "Arthur"
     * @endcode
     */
    static std::string_view firstName(std::optional<Country> country = std::nullopt,
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
     * Person::lastName() // "Peterson"
     * @endcode
     */
    static std::string_view lastName(std::optional<Country> country = std::nullopt,
                                     std::optional<Sex> sex = std::nullopt);

    /**
     * @brief Returns a random middle name.
     *
     * @param country The local country. Defaults to `Country::England`.
     * @param sex The optional sex to use.
     *
     * @returns Middle name starting with a capital letter.
     *
     * @code
     * Person::middleName() // "Васильевич"
     * @endcode
     */
    static std::string_view middleName(std::optional<Country> country = std::nullopt,
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
     * Person::fullName() // "Marcia Robinson"
     * Person::fullName(Country::England, Sex::Female) // "Jennifer Martin"
     * Person::fullName(Country::England, Sex::Male) // "Samuel Walker"
     * @endcode
     */
    static std::string fullName(std::optional<Country> country = std::nullopt, std::optional<Sex> sex = std::nullopt);

    /**
     * @brief Returns a random name prefix.
     *
     * @param sex The optional sex to use.
     *
     * @returns Name prefix.
     *
     * @code
     * Person::prefix() // "Miss"
     * Person::prefix(Sex::Female) // "Ms."
     * Person::prefix(Sex::Male) // "Mr."
     * @endcode
     */
    static std::string_view prefix(std::optional<Country> countryOpt = std::nullopt,
                                   std::optional<Sex> sex = std::nullopt);

    /**
     * @brief Returns a random name suffix.
     *
     * @returns Name suffix.
     *
     * @code
     * Person::suffix() // "Jr."
     * @endcode
     */
    static std::string_view suffix(std::optional<Country> countryOpt = std::nullopt,
                                   std::optional<Sex> sex = std::nullopt);

    /**
     * @brief Returns a random bio.
     *
     * @returns Bio.
     *
     * @code
     * Person::bio() //"Developer"
     * @endcode
     */
    static std::string bio();

    /**
     * @brief Returns a sex.
     *
     * @returns Sex.
     *
     * @code
     * Person::sex() // "Male"
     * @endcode
     */
    static std::string_view sex(std::optional<Language> language = std::nullopt);

    /**
     * @brief Returns a random gender.
     *
     * @returns Gender.
     *
     * @code
     * Person::gender() // "Transexual woman"
     * @endcode
     */
    static std::string_view gender();

    /**
     * @brief Returns a random job title.
     *
     * @returns Job title.
     *
     * @code
     * Person::jobTitle() // "Global Accounts Engineer"
     * @endcode
     */
    static std::string jobTitle();

    /**
     * @brief Returns a random job descriptor.
     *
     * @returns Job descriptor.
     *
     * @code
     * Person::jobDescriptor() // "Senior"
     * @endcode
     */
    static std::string_view jobDescriptor();

    /**
     * @brief Returns a random job area.
     *
     * @returns Job area.
     *
     * @code
     * Person::jobArea() // "Software"
     * @endcode
     */
    static std::string_view jobArea();

    /**
     * @brief Returns a random job type.
     *
     * @returns Job type.
     *
     * @code
     * Person::jobType() // "Engineer"
     * @endcode
     */
    static std::string_view jobType();

    /**
     * @brief Returns a random hobby.
     *
     * @returns Hobby.
     *
     * @code
     * Person::hobby() // "Gaming"
     * @endcode
     */
    static std::string_view hobby();

    /**
     * @brief Returns a random language.
     *
     * @returns Language.
     *
     * @code
     * Person::language() // "Polish"
     * @endcode
     */
    static std::string_view language();

    /**
     * @brief Returns a random nationality.
     *
     * @returns Nationality.
     *
     * @code
     * Person::nationality() // "Romanian"
     * @endcode
     */
    static std::string_view nationality();

    /**
     * @brief Returns a random SSN.
     *
     * @param country The optional country to use.
     *
     * @returns Social Security Number.
     *
     * @code
     * Person::ssn() // "437-12-6854"
     * Person::ssn(SsnCountry::Polish) // "95111901567"
     * @endcode
     */
    static std::string ssn(std::optional<SsnCountry> country = std::nullopt);

    /**
     * @brief Returns a random Western Zodiac
     *
     * @returns Western Zodiac
     *
     * @code
     * Person::westernZodiac() // "Virgo"
     * @endcode
     */
    static std::string_view westernZodiac();

    /**
     * @brief Returns a random Chinese Zodiac
     *
     * @returns Chinese Zodiac
     *
     * @code
     * Person::chineseZodiac() // "Dragon"
     * @endcode
     */
    static std::string_view chineseZodiac();

    /**
     * @brief Returns a random passport number from a given country
     *
     * @returns Passport
     *
     * @code
     * Person::passport(PassportCountry::Romania) // "12345678"
     * @endcode
     */
    static std::string passport(std::optional<PassportCountry> country = std::nullopt);
};

enum class PassportCountry
{
    Usa,
    Poland,
    France,
    Romania,
};

enum class Sex
{
    Male,
    Female,
};

enum class SsnCountry
{
    Poland,
    Usa,
    England,
    Germany,
    France,
    Italy,
    Spain,
    India,
};

enum class Language
{
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
}
