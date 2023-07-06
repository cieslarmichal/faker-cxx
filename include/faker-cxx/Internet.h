#pragma once

#include <optional>
#include <string>

namespace faker
{
class Internet
{
public:
    /**
     * @brief Generates a username using the given person's name as base.
     *
     * @param firstName The optional first name to include in username.
     * @param lastName The optional last name to include in username.
     *
     * @returns Username including neither, one or both of the provided names
     *
     * @example
     * Internet::username() // "Richardson.Jeffrey1997"
     * Internet::username("Michael") // "Michael_Allen29"
     * Internet::username(std::nullopt, "Cieslar") // "Phillip_Cieslar20"
     * Internet::username("Andrew", "Cieslar") // "Andrew.Cieslar"
     */
    static std::string username(std::optional<std::string> firstName = std::nullopt,
                                std::optional<std::string> lastName = std::nullopt);

    /**
     * @brief Generates an email address using the given person's name as base.
     *
     * @param firstName The optional first name to use. If not specified, a random one will be chosen.
     * @param lastName The optional last name to use. If not specified, a random one will be chosen.
     * @param emailHost The optional email host name to use. If not specified, a random one will be chosen.
     *
     * @returns Email including neither, one or both of the provided names, with random/provided emailHost
     *
     * @example
     * Internet::email() // "Jimenez.Clyde@gmail.com"
     * Internet::email("Tom") // "TomRichardson79@outlook.com"
     * Internet::email(std::nullopt, "Howard") // "FreddieHoward@hotmail.com"
     * Internet::email("Cindy", "Young") // "Young_Cindy@gmail.com"
     * Internet::email(std::nullopt, std::nullopt, "example.com") // "Wright.Edna1973@example.com"
     */
    static std::string email(std::optional<std::string> firstName = std::nullopt,
                             std::optional<std::string> lastName = std::nullopt,
                             std::optional<std::string> emailHost = std::nullopt);

    /**
     * @brief Generates a random password-like string. Do not use this method for generating actual passwords for users.
     * Since the source of the randomness is not cryptographically secure, neither is this generator
     *
     * @param length The length of the password to generate. Defaults to `15`.
     *
     * @returns Random password-like string
     *
     * @example
     * Internet::password() // "gXGpe9pKfFcKy9R"
     * Internet::password(25) // "xv8vDu*wM!Rg0$zd0kH%8p!WY"
     */
    static std::string password(int length = 15);
};
}
