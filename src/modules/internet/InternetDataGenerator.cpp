#include "InternetDataGenerator.h"

#include "data/EmailHosts.h"
#include "../person/PersonDataGenerator.h"

namespace faker::person
{
std::string InternetDataGenerator::username(std::optional<std::string> firstNameInit, std::optional<std::string> lastNameInit)
{
    const auto firstName = firstNameInit? *firstNameInit : PersonDataGenerator::firstName();

    const auto lastName = lastNameInit? *lastNameInit : PersonDataGenerator::lastName();

    return firstName + lastName;
}

std::string InternetDataGenerator::email()
{
    return username() + emailHosts[0];
}

}
