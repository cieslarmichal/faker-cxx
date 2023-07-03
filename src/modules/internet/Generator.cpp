#include "../helpers/Generator.h"

#include <format>

#include "../person/Generator.h"
#include "data/EmailHosts.h"
#include "Generator.h"

namespace faker::internet
{
std::string username(std::optional<std::string> firstNameInit, std::optional<std::string> lastNameInit)
{
    const auto firstName = firstNameInit ? *firstNameInit : person::firstName();

    const auto lastName = lastNameInit ? *lastNameInit : person::lastName();

    std::string username;

    switch (number::integer(4))
    {
    case 0:
        username = std::format("{}{}", firstName, number::integer(99999));
        break;
    case 1:
        username =
            std::format("{}{}{}", firstName, helpers::arrayElement(std::vector<std::string>{".", "_", ""}), lastName);
        break;
    case 2:
        username = std::format("{}{}{}{}", firstName, helpers::arrayElement(std::vector<std::string>{".", "_", ""}),
                               lastName, number::integer(99));
        break;
    case 3:
        username =
            std::format("{}{}{}", lastName, helpers::arrayElement(std::vector<std::string>{".", "_", ""}), firstName);
        break;
    case 4:
        username = std::format("{}{}{}{}", firstName, helpers::arrayElement(std::vector<std::string>{".", "_", ""}),
                               firstName, number::integer(2023, 1960));
    }

    return username;
}

std::string email()
{
    return std::format("{}@{}", username(), helpers::arrayElement(emailHosts));
}

}
