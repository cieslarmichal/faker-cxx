#pragma once

#include <array>
#include <ctime>
#include <map>
#include <optional>
#include <string>
#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::internet
{
enum class HttpResponseType
{
    ClientError,
    Informational,
    Redirection,
    ServerError,
    Success,
};

enum class WebProtocol
{
    Http,
    Https
};

enum class IPv4Class
{
    A,
    B,
    C
};

struct FAKER_CXX_EXPORT PasswordOptions
{
    bool upperLetters = true;
    bool lowerLetters = true;
    bool numbers = true;
    bool symbols = true;
};

/**
 * @brief Generates a username using the given person's name as base.
 *
 * @param firstName The optional first name to include in username.
 * @param lastName The optional last name to include in username.
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Username including neither, one or both of the provided names.
 *
 * @code
 * faker::internet::username() // "Richardson.Jeffrey1997"
 * faker::internet::username("Michael") // "Michael_Allen29"
 * faker::internet::username(std::nullopt, "Cieslar") // "Phillip_Cieslar20"
 * faker::internet::username("Andrew", "Cieslar") // "Andrew.Cieslar"
 * @endcode
 */
FAKER_CXX_EXPORT std::string username(std::optional<std::string> firstName = std::nullopt,
                                      std::optional<std::string> lastName = std::nullopt,
                                      Locale locale = Locale::en_US);

/**
 * @brief Generates an email address using the given person's name as base.
 *
 * @param firstName The optional first name to use. If not specified, a random one will be chosen.
 * @param lastName The optional last name to use. If not specified, a random one will be chosen.
 * @param emailHost The optional email host name to use. If not specified, a random one will be chosen.
 *
 * @returns Email including neither, one or both of the provided names, with random/provided email host.
 *
 * @code
 * faker::internet::email() // "Jimenez.Clyde@gmail.com"
 * faker::internet::email("Tom") // "TomRichardson79@outlook.com"
 * faker::internet::email(std::nullopt, "Howard") // "FreddieHoward@hotmail.com"
 * faker::internet::email("Cindy", "Young") // "Young_Cindy@gmail.com"
 * faker::internet::email(std::nullopt, std::nullopt, "example.com") // "Wright.Edna1973@code.com"
 * @endcode
 */
FAKER_CXX_EXPORT std::string email(std::optional<std::string> firstName = std::nullopt,
                                   std::optional<std::string> lastName = std::nullopt,
                                   std::optional<std::string> emailHost = std::nullopt);

/**
 * @brief Generates an email address using the given person's name as base with example domain.
 *
 * @param firstName The optional first name to use. If not specified, a random one will be chosen.
 * @param lastName The optional last name to use. If not specified, a random one will be chosen.
 *
 * @returns Email including neither, one or both of the provided names, with example email host.
 *
 * @code
 * faker::internet::exampleEmail() // "Jimenez.Clyde@example.com"
 * @endcode
 */
FAKER_CXX_EXPORT std::string exampleEmail(std::optional<std::string> firstName = std::nullopt,
                                          std::optional<std::string> lastName = std::nullopt);

/**
 * @brief Generates a random password-like string. Do not use this method for generating actual passwords for users.
 * Since the source of the randomness is not cryptographically secure, neither is this generator.
 *
 * @param length The length of the password to generate. Defaults to `16`.
 * @param options The optional password options to use. Options include whether to include upperLetters, lowerLetters,
 * numbers and symbols in password generation. Defaults to include all.
 *
 * @returns Random password-like string.
 *
 * @code
 * faker::internet::password() // "gXGpe9pKfFcKy9R"
 * faker::internet::password(25) // "xv8vDu*wM!Rg0$zd0kH%8p!WY"
 * @endcode
 */
FAKER_CXX_EXPORT std::string password(int length = 16, const PasswordOptions& options = {});

enum class EmojiType
{
    Activity,
    Body,
    Flag,
    Food,
    Nature,
    Object,
    Person,
    Smiley,
    Symbol,
    Travel,
};

/**
 * @brief Returns a random emoji.
 *
 * @param type The optional type of them emoji to be generated.
 *
 * @returns Emoji.
 *
 * @code
 * faker::internet::emoji() // "👑"
 * faker::internet::emoji(EmojiType::Food) // "🍕"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view emoji(std::optional<EmojiType> type = std::nullopt);

/**
 * @brief Verify that a given emoji is valid.
 *
 * @param emojiToCheck the emoji to check.
 *
 * @returns true if emojiToCheck is found in one of the vectors, false otherwise.
 *
 * @code
 * faker::internet::checkIfEmojiIsValid("👑") // true
 * @endcode
 */
FAKER_CXX_EXPORT bool checkIfEmojiIsValid(const std::string& emojiToCheck);

/**
 * @brief Returns a random web protocol. Either `http` or `https`.
 *
 * @returns Web protocol.
 *
 * @code
 * faker::internet::protocol() // "https"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view protocol();

/**
 * @brief Generates a random http method name.
 *
 * @returns Http method name.
 *
 * @code
 * faker::internet::httpMethod() // "POST"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view httpMethod();

/**
 * @brief Returns a random http status code.
 *
 * @param responseType The type of the http response.
 *
 * @returns Http status code.
 *
 * @code
 * faker::internet::httpStatusCode() // 500
 * faker::internet::httpStatusCode(HttpStatusCodeType::success) // 201
 * @endcode
 */
FAKER_CXX_EXPORT unsigned httpStatusCode(std::optional<HttpResponseType> responseType = std::nullopt);

/**
 * @brief Generates a random http request header.
 *
 * @returns Http request header.
 *
 * @code
 * faker::internet::httpRequestHeader() // "Authorization"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view httpRequestHeader();

/**
 * @brief Generates a random http response header.
 *
 * @returns Http response header.
 *
 * @code
 * faker::internet::httpResponseHeader() // "Location"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view httpResponseHeader();

/**
 * @brief Generates a random http media type.
 *
 * @returns Http media type.
 *
 * @code
 * faker::internet::httpMediaType() // "application/json"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view httpMediaType();

/**
 * @brief Returns a string containing randomized ipv4 address of the given class.
 *
 * @param ipv4class Address class to be generated.
 *
 * @return String representation of the ipv4 address.
 *
 * @code
 * faker::internet::ipv4() // "192.168.0.1"
 * faker::internet::ipv4(IPv4Class::classA) // "10.0.0.1"
 * @endcode
 */
FAKER_CXX_EXPORT std::string ipv4(const IPv4Class& ipv4class = IPv4Class::C);

/**
 * @brief Returns a string containing randomized ipv4 address based on given base address and mask.
 *
 * Generated result is compliant with the ipv4 classes. Bits of the baseIpv4Address not covered by the
 * generationMask will be ignored and replaced during generation. Bits covered by the mask will be kept in the
 * result. Mask should be provided in the same format as regular ipv4 mask.
 *
 * @param generationMask Mask deciding which bits of the base address should be kept during randomization.
 * @param baseIpv4Address Address to randomize from.
 *
 * @return std::string representation of the ipv4 address.
 *
 * @code
 * faker::internet::ipv4({255.0.0.0}, {10.100.100.100}) // "10.128.17.1"
 * faker::internet::ipv4({255.255.128.0}, {129.168.255.0}) // "192.168.128.10"
 * @endcode
 */
FAKER_CXX_EXPORT std::string ipv4(const std::array<unsigned int, 4>& baseIpv4Address,
                                  const std::array<unsigned int, 4>& generationMask);

/**
 * @brief Returns a string containing randomized ipv6 address.
 *
 * @return String representation of the ipv6 address.
 *
 * @code
 * faker::internet::ipv6() // "269f:1230:73e3:318d:842b:daab:326d:897b"
 * @endcode
 */
FAKER_CXX_EXPORT std::string ipv6();

/**
 * @brief Returns a generated random mac address.
 *
 * @param sep Separator to use. Defaults to ":". Also can be "-" or "".
 *
 * @return A generated random mac address.
 *
 * @code
 * faker::internet::mac() // "2d:10:34:2f:ac:ac"
 * @endcode
 */
FAKER_CXX_EXPORT std::string mac(const std::string& sep = ":");

/**
 * @brief Generates a random port.
 *
 * @return Port.
 *
 * @code
 * faker::internet::port() // 5432
 * @endcode
 */
FAKER_CXX_EXPORT unsigned port();

/**
 * @brief Generates a random url.
 *
 * @param webProtocol Web protocol to generate url with. Defaults to `WebProtocol::Https`.
 *
 * @return Http(s) url.
 *
 * @code
 * faker::internet::url() // "https://slow-timer.info"
 * @endcode
 */
FAKER_CXX_EXPORT std::string url(const WebProtocol& webProtocol = WebProtocol::Https);

/**
 * @brief Generates a random domain name.
 *
 * @return Domain name.
 *
 * @code
 * faker::internet::domainName() // "slow-timer.info"
 * @endcode
 */
FAKER_CXX_EXPORT std::string domainName();

/**
 * @brief Generates a random domain word.
 *
 * @return Domain word.
 *
 * @code
 * faker::internet::domainWord() // "close-reality"
 * @endcode
 */
FAKER_CXX_EXPORT std::string domainWord();

/**
 * @brief Generates a random domain suffix.
 *
 * @return Domain suffix.
 *
 * @code
 * faker::internet::domainSuffix() // "com"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view domainSuffix();

/**
 * @brief Generates a random username.
 *
 * @param maxLength maxLength of the generated username.
 *
 * @return Username.
 *
 * @code
 * faker::internet::anonymousUsername() // "profusebrother", "richad", "powerfuldifferential"
 * @endcode
 */
FAKER_CXX_EXPORT std::string anonymousUsername(unsigned maxLength);

/**
 * @brief Generates a JSON Web Token (JWT).
 *
 * This function generates a JWT using the provided header, payload, and reference date.
 * If no header or payload is provided, default values will be used.
 * The reference date is optional and can be used to set the "iat" (issued at) claim in the payload.
 *
 * @param header The optional header map to include in the JWT. Defaults to a standard header.
 * @param payload The optional payload map to include in the JWT. Defaults to a standard payload.
 * @param refDate The optional reference date to set the "iat" claim. Defaults to the current date and time.
 *
 * @returns A string representing the generated JWT.
 *
 * @code
 * std::map<std::string, std::string> header = {{"alg", "HS256"}, {"typ", "JWT"}};
 * std::map<std::string, std::string> payload = {{"sub", "1234567890"}, {"name", "John Doe"}, {"admin", "true"}};
 * faker::internet::getJWTToken(header, payload); // "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."
 * @endcode
 */
FAKER_CXX_EXPORT std::string
getJWTToken(const std::optional<std::map<std::string, std::string>>& header = std::nullopt,
            const std::optional<std::map<std::string, std::string>>& payload = std::nullopt,
            const std::optional<std::string>& refDate = std::nullopt);

/**
 * @brief Returns the algorithm used for signing the JWT.
 *
 * This function provides the algorithm that is used to sign the JSON Web Token (JWT).
 *
 * @returns A string view representing the JWT signing algorithm.
 *
 * @code
 * faker::internet::getJWTAlgorithm(); // "HS256"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view getJWTAlgorithm();
}
