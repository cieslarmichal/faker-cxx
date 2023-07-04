#include "Internet.h"

#include <format>

#include "data/EmailHosts.h"
#include "Helper.h"
#include "Person.h"

namespace faker
{
std::string Internet::username(std::optional<std::string> firstNameInit, std::optional<std::string> lastNameInit)
{
    const auto firstName = firstNameInit ? *firstNameInit : Person::firstName();

    const auto lastName = lastNameInit ? *lastNameInit : Person::lastName();

    std::string username;

    switch (Number::integer(4))
    {
    case 0:
        username = std::format("{}{}{}", firstName, lastName, Number::integer(99999));
        break;
    case 1:
        username =
            std::format("{}{}{}", firstName, Helper::arrayElement(std::vector<std::string>{".", "_", ""}), lastName);
        break;
    case 2:
        username = std::format("{}{}{}{}", firstName, Helper::arrayElement(std::vector<std::string>{".", "_", ""}),
                               lastName, Number::integer(99));
        break;
    case 3:
        username =
            std::format("{}{}{}", lastName, Helper::arrayElement(std::vector<std::string>{".", "_", ""}), firstName);
        break;
    case 4:
        username = std::format("{}{}{}{}", lastName, Helper::arrayElement(std::vector<std::string>{".", "_", ""}),
                               firstName, Number::integer(2023, 1960));
    }

    return username;
}

std::string Internet::email()
{
    return std::format("{}@{}", username(), Helper::arrayElement(emailHosts));
}

std::string Internet::password(int length)
{
    const std::string passwordCharacters = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string password;

    for (int i = 0; i < length; i++)
    {
        password += Helper::arrayElement(passwordCharacters);
    }

    return password;
}

}
