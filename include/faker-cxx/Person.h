#pragma once

#include <optional>
#include <string>

#include "faker-cxx/types/Country.h"
#include "faker-cxx/types/Sex.h"

namespace faker
{
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
    static std::string firstName(Country country = Country::England, std::optional<Sex> sex = std::nullopt);

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
    static std::string lastName(Country country = Country::England, std::optional<Sex> sex = std::nullopt);

    /**
     * @brief Returns a random middle name.
     *
     * @param sex The optional sex to use.
     *
     * @returns Middle name starting with a capital letter.
     *
     * @code
     * Person::middleName() // "Васильевич"
     * @endcode
     */
    static std::string middleName(std::optional<Sex> sex = std::nullopt);

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
    static std::string fullName(Country country = Country::England, std::optional<Sex> sex = std::nullopt);

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
    static std::string prefix(std::optional<Sex> sex = std::nullopt);

    /**
     * @brief Returns a random name suffix.
     *
     * @returns Name suffix.
     *
     * @code
     * Person::suffix() // "Jr."
     * @endcode
     */
    static std::string suffix();

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
    static std::string sex();

    /**
     * @brief Returns a random gender.
     *
     * @returns Gender.
     *
     * @code
     * Person::gender() // "Transexual woman"
     * @endcode
     */
    static std::string gender();

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
    static std::string jobDescriptor();

    /**
     * @brief Returns a random job area.
     *
     * @returns Job area.
     *
     * @code
     * Person::jobArea() // "Software"
     * @endcode
     */
    static std::string jobArea();

    /**
     * @brief Returns a random job type.
     *
     * @returns Job type.
     *
     * @code
     * Person::jobType() // "Engineer"
     * @endcode
     */
    static std::string jobType();

    /**
     * @brief Returns a random hobby.
     *
     * @returns Hobby.
     *
     * @code
     * Person::hobby() // "Gaming"
     * @endcode
     */
    static std::string hobby();

    /**
     * @brief Returns a random language.
     *
     * @returns Language.
     *
     * @code
     * Person::language() // "Polish"
     * @endcode
     */
    static std::string language();

    /**
     * @brief Returns a random nationality.
     *
     * @returns Nationality.
     *
     * @code
     * Person::nationality() // "Romanian"
     * @endcode
     */
    static std::string nationality();

    /**
     * @brief Returns a random Western Zodiac
     *
     * @returns Western Zodiac
     *
     * @code
     * Person::westernZodiac() // "Virgo"
     * @endcode
     */
    static std::string westernZodiac();

    /**
     * @brief Returns a random Chinese Zodiac
     *
     * @returns Chinese Zodiac
     *
     * @code
     * Person::chineseZodiac() // "Dragon"
     * @endcode
     */
    static std::string chineseZodiac();
};
}
