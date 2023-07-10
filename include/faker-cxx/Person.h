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
     * @brief Returns a random last name.
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
};
}
