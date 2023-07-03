#include "InternetDataGenerator.h"

#include "../person/PersonDataGenerator.h"
#include "data/EmailHosts.h"

namespace faker::internet
{
std::string InternetDataGenerator::username(std::optional<std::string> firstNameInit,
                                            std::optional<std::string> lastNameInit)
{
    const auto firstName = firstNameInit ? *firstNameInit : person::PersonDataGenerator::firstName();

    const auto lastName = lastNameInit ? *lastNameInit : person::PersonDataGenerator::lastName();

    return firstName + lastName;
}

std::string InternetDataGenerator::email()
{
    return username() + emailHosts[0];
}

}
