#pragma once

#include <optional>
#include <string>

#include "types/Language.h"
#include "types/Sex.h"

namespace faker
{
class Person
{
public:
    /**
     * @brief Returns a random first name.
     *
     * @param language The local name language. Defaults to `Language::English`.
     * @param sex The optional sex to use.
     *
     * @returns First name starting with a capital letter.
     *
     * @code
     * Person::firstName() // "Michael"
     * Person::firstName(Language::English, Sex::Female) // "Emma"
     * Person::firstName(Language::English, Sex::Male) // "Arthur"
     * @endcode
     */
    static std::string firstName(Language language = Language::English, std::optional<Sex> = std::nullopt);

    /**
     * @brief Returns a random last name.
     *
     * @param language The local name language. Defaults to `Language::English`.
     *
     * @returns Last name starting with a capital letter.
     *
     * @code
     * Person::lastName() // "Peterson"
     * @endcode
     */
    static std::string lastName(Language language = Language::English, std::optional<Sex> = std::nullopt);

    /**
     * @brief Returns a random full name.
     *
     * @param language The local name language. Defaults to `Language::English`.
     *
     * @returns Full name starting with first name.
     *
     * @code
     * Person::fullName() // "Marcia Robinson"
     * Person::fullName(Language::English, Sex::Female) // "Jennifer Martin"
     * Person::fullName(Language::English, Sex::Male) // "Samuel Walker"
     * @endcode
     */
    static std::string fullName(Language language = Language::English, std::optional<Sex> = std::nullopt);

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
    static std::string prefix(std::optional<Sex> = std::nullopt);

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
};
}
