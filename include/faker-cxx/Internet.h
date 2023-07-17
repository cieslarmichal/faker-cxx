#pragma once

#include <optional>
#include <string>

namespace faker
{
enum class HttpResponseType
{
    Informational,
    Success,
    Redirection,
    ClientError,
    ServerError
};

class Internet
{
public:
    /**
     * @brief Generates a username using the given person's name as base.
     *
     * @param firstName The optional first name to include in username.
     * @param lastName The optional last name to include in username.
     *
     * @returns Username including neither, one or both of the provided names.
     *
     * @code
     * Internet::username() // "Richardson.Jeffrey1997"
     * Internet::username("Michael") // "Michael_Allen29"
     * Internet::username(std::nullopt, "Cieslar") // "Phillip_Cieslar20"
     * Internet::username("Andrew", "Cieslar") // "Andrew.Cieslar"
     * @endcode
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
     * @returns Email including neither, one or both of the provided names, with random/provided emailHost.
     *
     * @code
     * Internet::email() // "Jimenez.Clyde@gmail.com"
     * Internet::email("Tom") // "TomRichardson79@outlook.com"
     * Internet::email(std::nullopt, "Howard") // "FreddieHoward@hotmail.com"
     * Internet::email("Cindy", "Young") // "Young_Cindy@gmail.com"
     * Internet::email(std::nullopt, std::nullopt, "example.com") // "Wright.Edna1973@code.com"
     * @endcode
     */
    static std::string email(std::optional<std::string> firstName = std::nullopt,
                             std::optional<std::string> lastName = std::nullopt,
                             std::optional<std::string> emailHost = std::nullopt);

    /**
     * @brief Generates a random password-like string. Do not use this method for generating actual passwords for users.
     * Since the source of the randomness is not cryptographically secure, neither is this generator.
     *
     * @param length The length of the password to generate. Defaults to `15`.
     *
     * @returns Random password-like string.
     *
     * @code
     * Internet::password() // "gXGpe9pKfFcKy9R"
     * Internet::password(25) // "xv8vDu*wM!Rg0$zd0kH%8p!WY"
     * @endcode
     */
    static std::string password(int length = 15);

    /**
     * @brief Generates a real image url with `https://source.unsplash.com/`.
     *
     * @param width The width of the image. Defaults to `640`.
     * @param height The height of the image. Defaults to `480`.
     *
     * @returns Random real image url from external service.
     *
     * @code
     * Internet::imageUrl() // "https://source.unsplash.com/640x480"
     * Internet::imageUrl(800, 600) // "https://source.unsplash.com/800x600"
     * @endcode
     */
    static std::string imageUrl(unsigned width = 640, unsigned height = 480);

    /**
     * @brief Generates a random avatar from GitHub.
     *
     * @returns Url to github avatar.
     *
     * @code
     * Internet::githubAvatarUrl() // "https://avatars.githubusercontent.com/u/9716558"
     * @endcode
     */
    static std::string githubAvatarUrl();

    /**
     * @brief Returns a random web protocol. Either `http` or `https`.
     *
     * @returns Web protocol.
     *
     * @code
     * Internet::protocol() // "https"
     * @endcode
     */
    static std::string protocol();

    /**
     * @brief Generates a random http method name.
     *
     * @returns Http method name.
     *
     * @code
     * Internet::httpMethod() // "POST"
     * @endcode
     */
    static std::string httpMethod();

    /**
     * @brief Returns a random http status code.
     *
     * @param responseType The type of the http response.
     *
     * @returns Http status code.
     *
     * @code
     * Internet::httpStatusCode() // 500
     * Internet::httpStatusCode(HttpStatusCodeType::success) // 201
     * @endcode
     */
    static unsigned httpStatusCode(std::optional<HttpResponseType> responseType = std::nullopt);
};
}
