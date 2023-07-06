#pragma once

#include <optional>
#include <string>

namespace faker
{
enum class Sex
{
    Male,
    Female,
};

class Person
{
public:
    /**
     * @brief Returns a random first name.
     *
     * @param sex The optional sex to use.
     *
     * @returns First name starting with a capital letter
     * @example
     * Person::firstName() // "Michael"
     * Person::firstName(Sex::Female) // "Emma"
     * Person::firstName(Sex::Male) // "Arthur"
     */
    static std::string firstName(std::optional<Sex> = std::nullopt);

    /**
     * @brief Returns a random last name.
     *
     * @returns Last name starting with a capital letter
     * @example
     * Person::lastName() // "Peterson"
     */
    static std::string lastName();

    /**
     * @brief Returns a random last name.
     *
     * @returns Full name starting with first name
     * @example
     * Person::fullName() // "Marcia Robinson"
     * Person::fullName(Sex::Female) // "Jennifer Martin"
     * Person::firstName(Sex::Male) // "Samuel Walker"
     */
    static std::string fullName(std::optional<Sex> = std::nullopt);
};
}
