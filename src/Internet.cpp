#include "faker-cxx/Internet.h"

#include <format>
#include <utility>

#include "data/EmailHosts.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Person.h"

namespace faker
{
std::string Internet::username(std::optional<std::string> firstNameInit, std::optional<std::string> lastNameInit)
{
    const auto firstName = firstNameInit ? *firstNameInit : Person::firstName();
    const auto lastName = lastNameInit ? *lastNameInit : Person::lastName();

    std::string username;

    switch (Number::integer<int>(2))
    {
    case 0:
        username = std::format("{}{}{}", firstName, lastName, Number::integer<int>(999));
        break;
    case 1:
        username = std::format("{}{}{}", firstName,
                               Helper::arrayElement<std::string>(std::vector<std::string>{".", "_", ""}), lastName);
        break;
    case 2:
        username = std::format("{}{}{}{}", firstName,
                               Helper::arrayElement<std::string>(std::vector<std::string>{".", "_", ""}), lastName,
                               Number::integer<int>(99));
        break;
    }

    return username;
}

std::string Internet::email(std::optional<std::string> firstName, std::optional<std::string> lastName,
                            std::optional<std::string> emailHost)
{
    return std::format("{}@{}", username(std::move(firstName), std::move(lastName)),
                       emailHost ? *emailHost : Helper::arrayElement<std::string>(emailHosts));
}

std::string Internet::password(int length)
{
    const std::string passwordCharacters = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string password;

    for (int i = 0; i < length; i++)
    {
        password += Helper::arrayElement<char>(passwordCharacters);
    }

    return password;
}

std::string Internet::imageUrl(unsigned int width, unsigned int height)
{
    return std::format("https://source.unsplash.com/{}x{}", width, height);
}

std::string Internet::githubAvatarUrl()
{
    return std::format("https://avatars.githubusercontent.com/u/{}", Number::integer<int>(100000000));
}

}
