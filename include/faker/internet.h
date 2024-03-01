#ifndef FAKER_INTERNET_H
#define FAKER_INTERNET_H

#include <array>
#include <faker/types/country.h>
#include <optional>
#include <string>

namespace faker::internet {
enum class emoji_type {
    smiley,
    body,
    person,
    nature,
    food,
    travel,
    activity,
    object,
    symbol,
    flag
};

enum class http_response_type { informational, success, redirection, client_error, server_error };

enum class web_protocol { http, https };

enum class ipv4_class { a, b, c };

/**
 * @brief Generates a username using the given person's name as base.
 *
 * @param first_name The optional first name to include in username.
 * @param last_name The optional last name to include in username.
 *
 * @returns Username including neither, one or both of the provided names.
 *
 * @code
 * internet::username() // "Richardson.Jeffrey1997"
 * internet::username("Michael") // "Michael_Allen29"
 * internet::username(std::nullopt, "Cieslar") // "Phillip_Cieslar20"
 * internet::username("Andrew", "Cieslar") // "Andrew.Cieslar"
 * @endcode
 */
std::string username(std::optional<std::string> first_name = std::nullopt,
    std::optional<std::string> last_name = std::nullopt, country_t country = country_t::usa);

/**
 * @brief Generates an email address using the given person's name as base.
 *
 * @param first_name The optional first name to use. If not specified, a random one will be
 * chosen.
 * @param last_name The optional last name to use. If not specified, a random one will be chosen.
 * @param email_host The optional email host name to use. If not specified, a random one will be
 * chosen.
 *
 * @returns Email including neither, one or both of the provided names, with random/provided
 * email host.
 *
 * @code
 * internet::email() // "Jimenez.Clyde@gmail.com"
 * internet::email("Tom") // "TomRichardson79@outlook.com"
 * internet::email(std::nullopt, "Howard") // "FreddieHoward@hotmail.com"
 * internet::email("Cindy", "Young") // "Young_Cindy@gmail.com"
 * internet::email(std::nullopt, std::nullopt, "example.com") // "Wright.Edna1973@code.com"
 * @endcode
 */
std::string email(std::optional<std::string> first_name = std::nullopt,
    std::optional<std::string> last_name = std::nullopt,
    std::optional<std::string> email_host = std::nullopt);

/**
 * @brief Generates an email address using the given person's name as base with example domain.
 *
 * @param first_name The optional first name to use. If not specified, a random one will be
 * chosen.
 * @param last_name The optional last name to use. If not specified, a random one will be chosen.
 *
 * @returns Email including neither, one or both of the provided names, with example email host.
 *
 * @code
 * internet::example_email() // "Jimenez.Clyde@example.com"
 * @endcode
 */
std::string example_email(std::optional<std::string> first_name = std::nullopt,
    std::optional<std::string> last_name = std::nullopt);

enum password_options : unsigned {
    upper_letters = 0x01,
    lower_letters = 0x02,
    numbers = 0x04,
    symbols = 0x08,
    all = upper_letters | lower_letters | numbers | symbols,
};

/**
 * @brief Generates a random password-like string. Do not use this method for generating actual
 * passwords for users. Since the source of the randomness is not cryptographically secure,
 * neither is this generator.
 *
 * @param length The length of the password to generate. Defaults to `15`.
 * @param options
 *
 * @returns Random password-like string.
 *
 * @code
 * internet::password() // "gXGpe9pKfFcKy9R"
 * internet::password(25) // "xv8vDu*wM!Rg0$zd0kH%8p!WY"
 * @endcode
 */
std::string password(unsigned length = 15, password_options options = password_options::all);

/**
 * @brief Returns a random emoji.
 *
 * @param type The optional type of them emoji to be generated.
 *
 * @returns Emoji.
 *
 * @code
 * internet::emoji() // "👑"
 * internet::emoji(emoji_type::food) // "🍕"
 * @endcode
 */
std::string_view emoji(std::optional<emoji_type> type = std::nullopt);

/**
 * @brief Verify that a given emoji is valid.
 *
 * @param emoji_to_check the emoji to check.
 *
 * @returns true if emoji_to_check is found in one of the vectors, false otherwise.
 *
 * @code
 * internet::is_valid_emoji("👑") // true
 * @endcode
 */
bool is_valid_emoji(const std::string& emoji_to_check);

/**
 * @brief Returns a random web protocol. Either `http` or `https`.
 *
 * @returns Web protocol.
 *
 * @code
 * internet::protocol() // "https"
 * @endcode
 */
std::string_view protocol();

/**
 * @brief Generates a random http method name.
 *
 * @returns Http method name.
 *
 * @code
 * internet::http_method() // "POST"
 * @endcode
 */
std::string_view http_method();

/**
 * @brief Returns a random http status code.
 *
 * @param response_type The type of the http response.
 *
 * @returns Http status code.
 *
 * @code
 * internet::http_status_code() // 500
 * internet::http_status_code(HttpStatusCodeType::success) // 201
 * @endcode
 */
unsigned http_status_code(std::optional<http_response_type> response_type = std::nullopt);

/**
 * @brief Generates a random http request header.
 *
 * @returns Http request header.
 *
 * @code
 * internet::http_request_header() // "Authorization"
 * @endcode
 */
std::string_view http_request_header();

/**
 * @brief Generates a random http response header.
 *
 * @returns Http response header.
 *
 * @code
 * internet::http_response_header() // "Location"
 * @endcode
 */
std::string_view http_response_header();

/**
 * @brief Generates a random http media type.
 *
 * @returns Http media type.
 *
 * @code
 * internet::http_media_type() // "application/json"
 * @endcode
 */
std::string_view http_media_type();

/**
 * @brief Returns a string containing randomized ipv4 address of the given class.
 *
 * @param ipv4class Address class to be generated.
 *
 * @return String representation of the ipv4 address.
 *
 * @code
 * internet::ipv4() // "192.168.0.1"
 * internet::ipv4(ipv4_class::classA) // "10.0.0.1"
 * @endcode
 */
std::string ipv4(ipv4_class ipv4class = ipv4_class::c);

/**
 * @brief Returns a string containing randomized ipv4 address based on given base address and
 * mask.
 *
 * Generated result is compliant with the ipv4 classes. Bits of the base_ipv4_addr not covered
 * by the generation_mask will be ignored and replaced during generation. Bits covered by the
 * mask will be kept in the result. Mask should be provided in the same format as regular ipv4
 * mask.
 *
 * @param generation_mask Mask deciding which bits of the base address should be kept during
 * randomization.
 * @param base_ipv4_addr Address to randomize from.
 *
 * @return std::string representation of the ipv4 address.
 *
 * @code
 * internet::ipv4({255.0.0.0}, {10.100.100.100}) // "10.128.17.1"
 * internet::ipv4({255.255.128.0}, {129.168.255.0}) // "192.168.128.10"
 * @endcode
 */
std::string ipv4(const std::array<unsigned int, 4>& base_ipv4_addr,
    const std::array<unsigned int, 4>& generation_mask);

/**
 * @brief Returns a string containing randomized ipv6 address.
 *
 * @return String representation of the ipv6 address.
 *
 * @code
 * internet::ipv6() // "269f:1230:73e3:318d:842b:daab:326d:897b"
 * @endcode
 */
std::string ipv6();

/**
 * @brief Returns a generated random mac address.
 *
 * @param sep Separator to use. Defaults to ":". Also can be "-" or "".
 *
 * @return A generated random mac address.
 *
 * @code
 * internet::mac() // "2d:10:34:2f:ac:ac"
 * @endcode
 */
std::string mac(const std::string& sep = ":");

/**
 * @brief Generates a random port.
 *
 * @return Port.
 *
 * @code
 * internet::port() // 5432
 * @endcode
 */
unsigned port();

/**
 * @brief Generates a random url.
 *
 * @param protocol Web protocol to generate url with. Defaults to `web_protocol::https`.
 *
 * @return Http(s) url.
 *
 * @code
 * internet::url() // "https://slow-timer.info"
 * @endcode
 */
std::string url(web_protocol protocol = web_protocol::https);

/**
 * @brief Generates a random domain name.
 *
 * @return Domain name.
 *
 * @code
 * internet::domain_name() // "slow-timer.info"
 * @endcode
 */
std::string domain_name();

/**
 * @brief Generates a random domain word.
 *
 * @return Domain word.
 *
 * @code
 * internet::domain_word() // "close-reality"
 * @endcode
 */
std::string domain_word();

/**
 * @brief Generates a random domain suffix.
 *
 * @return Domain suffix.
 *
 * @code
 * internet::domain_suffix() // "com"
 * @endcode
 */
std::string_view domain_suffix();
}

#endif