#pragma once

#include <optional>
#include <string>

#include "types/Sex.h"

namespace faker
{
class Person
{
public:
    /**
     * @brief Returns a random first name.
     *
     * @param sex The optional sex to use.
     *
     * @returns First name starting with a capital letter
     *
     * @code
     * Person::firstName() // "Michael"
     * Person::firstName(Sex::Female) // "Emma"
     * Person::firstName(Sex::Male) // "Arthur"
     * @endcode
     */
    static std::string firstName(std::optional<Sex> = std::nullopt);

    /**
     * @brief Returns a random last name.
     *
     * @returns Last name starting with a capital letter
     *
     * @code
     * Person::lastName() // "Peterson"
     * @endcode
     */
    static std::string lastName();

    /**
     * @brief Returns a random full name.
     *
     * @returns Full name starting with first name
     *
     * @code
     * Person::fullName() // "Marcia Robinson"
     * Person::fullName(Sex::Female) // "Jennifer Martin"
     * Person::fullName(Sex::Male) // "Samuel Walker"
     * @endcode
     */
    static std::string fullName(std::optional<Sex> = std::nullopt);

    /**
     * @brief Returns a random name prefix.
     *
     * @param sex The optional sex to use.
     *
     * @returns Name prefix
     *
     * @code
     * Person::prefix() // 'Miss'
     * Person::prefix(Sex::Female) // 'Ms.'
     * Person::prefix(Sex::Male) // 'Mr.'
     * @endcode
     */
    static std::string prefix(std::optional<Sex> = std::nullopt);

    /**
     * @brief Returns a sex.
     *
     * @returns Sex
     *
     * @code
     * Person::sex() // "Male"
     * @endcode
     */
    static std::string sex();

    /**
     * @brief Returns a random gender.
     *
     * @returns Gender
     *
     * @code
     * Person::gender() // "Transexual woman"
     * @endcode
     */
    static std::string gender();

    /**
     * @brief Returns a random job title.
     *
     * @returns Job title
     *
     * @code
     * Person::jobTitle() // 'Global Accounts Engineer'
     * @endcode
     */
    static std::string jobTitle();

    /**
     * @brief Returns a random job descriptor.
     *
     * @returns Job descriptor
     *
     * @code
     * Person::jobDescriptor() // 'Senior'
     * @endcode
     */
    static std::string jobDescriptor();

    /**
     * @brief Returns a random job area.
     *
     * @returns Job area
     *
     * @code
     * Person::jobArea() // 'Software'
     * @endcode
     */
    static std::string jobArea();

    /**
     * @brief Returns a random job type.
     *
     * @returns Job type
     *
     * @code
     * Person::jobType() // 'Engineer'
     * @endcode
     */
    static std::string jobType();
};
}
