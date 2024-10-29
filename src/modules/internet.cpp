#include "faker-cxx/internet.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <initializer_list>
#include <map>
#include <optional>
#include <regex>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "common/algo_helper.h"
#include "common/format_helper.h"
#include "common/string_helper.h"
#include "faker-cxx/company.h"
#include "faker-cxx/faker.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "faker-cxx/person.h"
#include "faker-cxx/types/hex.h"
#include "faker-cxx/types/locale.h"
#include "faker-cxx/word.h"
#include "internet_data.h"
#include "modules/string_data.h"

namespace
{
/**
 * @brief Encodes a given string to Base64 URL format.
 *
 * This function takes an input string and converts it into a Base64 URL encoded string.
 * Base64 URL encoding is a variant of Base64 encoding that is URL-safe.
 *
 * @param input The string to be encoded.
 *
 * @returns A Base64 URL encoded string.
 *
 * @code
 * std::string input = "Hello, World!";
 * faker::internet::toBase64UrlEncode(input); // "SGVsbG8sIFdvcmxkIQ"
 * @endcode
 */
std::string toBase64UrlEncode(const std::string& input)
{
    const std::string base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string encodedInput;

    int value = 0;
    int validBits = -6;

    for (unsigned char character : input)
    {
        value = (value << 8) + character;
        validBits += 8;
        while (validBits >= 0)
        {
            encodedInput.push_back(base64Chars[(value >> validBits) & 0x3F]);
            validBits -= 6;
        }
    }

    if (validBits > -6)
    {
        encodedInput.push_back(base64Chars[((value << 8) >> validBits) & 0x3F]);
    }

    while (encodedInput.size() % 4)
    {
        encodedInput.push_back('=');
    }

    std::replace(encodedInput.begin(), encodedInput.end(), '+', '-');
    std::replace(encodedInput.begin(), encodedInput.end(), '/', '_');
    encodedInput = std::regex_replace(encodedInput, std::regex{"=+$"}, "");

    return encodedInput;
}

/**
 * @brief Converts a map of key-value pairs to a JSON string.
 *
 * This function takes a map where both keys and values are strings and converts it into a JSON formatted string.
 *
 * @param data The map containing key-value pairs to be converted to JSON.
 *
 * @returns A JSON formatted string representing the input map.
 *
 * @code
 * std::map<std::string, std::string> data = {{"name", "John"}, {"age", "30"}};
 * faker::internet::toJSON(data);  // json is now "{\"name\":\"John\",\"age\":\"30\"}"
 * @endcode
 */
std::string toJSON(std::map<std::string, std::string>& data)
{
    std::string json = "{";
    for (auto it = data.begin(); it != data.end(); ++it)
    {
        if (it != data.begin())
        {
            json += ",";
        }
        json += "\"" + it->first + "\":\"" + it->second + "\"";
    }
    json += "}";
    return json;
}
}

namespace faker::internet
{
namespace
{
const std::array<std::string_view, 2> webProtocols{"http", "https"};
const std::array<std::string_view, 5> httpMethodNames{"GET", "POST", "DELETE", "PATCH", "PUT"};
const std::initializer_list<unsigned> httpStatusInformationalCodes{100, 101, 102, 103};
const std::initializer_list<unsigned> httpStatusSuccessCodes{200, 201, 202, 203, 204, 205, 206, 207, 208, 226};
const std::initializer_list<unsigned> httpStatusRedirectionCodes{300, 301, 302, 303, 304, 305, 306, 307, 308};
const std::initializer_list<unsigned> httpStatusClientErrorCodes{400, 401, 402, 403, 404, 405, 406, 407, 408, 409,
                                                                 410, 411, 412, 413, 414, 415, 416, 417, 418, 421,
                                                                 422, 423, 424, 425, 426, 428, 429, 431, 451};
const std::initializer_list<unsigned> httpStatusServerErrorCodes{500, 501, 502, 503, 504, 505, 506, 507, 508, 510, 511};
const std::map<HttpResponseType, std::initializer_list<unsigned>> httpResponseTypeToCodesMapping{
    {HttpResponseType::Informational, httpStatusInformationalCodes},
    {HttpResponseType::Success, httpStatusSuccessCodes},
    {HttpResponseType::Redirection, httpStatusRedirectionCodes},
    {HttpResponseType::ClientError, httpStatusClientErrorCodes},
    {HttpResponseType::ServerError, httpStatusServerErrorCodes},
};
constexpr unsigned int ipv4AddressSectors = 4u;
constexpr unsigned int ipv4ClassCFirstSector = 192u;
constexpr unsigned int ipv4ClassCSecondSector = 168u;
constexpr unsigned int ipv4ClassAFirstSector = 10u;
constexpr unsigned int ipv4ClassBFirstSector = 172;
constexpr unsigned int ipv4ClassBSecondSectorLowerBound = 16u;
constexpr unsigned int ipv4ClassBSecondSectorUpperBound = 31u;
constexpr unsigned int ipv4SectorUpperBound = 255u;

const std::map<EmojiType, std::vector<std::string_view>> emojiTypeToEmojisMapping = {
    {EmojiType::Smiley, helper::toVector(smileyEmojis)},     {EmojiType::Body, helper::toVector(bodyEmojis)},
    {EmojiType::Person, helper::toVector(personEmojis)},     {EmojiType::Nature, helper::toVector(natureEmojis)},
    {EmojiType::Food, helper::toVector(foodEmojis)},         {EmojiType::Travel, helper::toVector(travelEmojis)},
    {EmojiType::Activity, helper::toVector(activityEmojis)}, {EmojiType::Object, helper::toVector(objectEmojis)},
    {EmojiType::Symbol, helper::toVector(symbolEmojis)},     {EmojiType::Flag, helper::toVector(flagEmojis)},
};
}

std::vector<std::string_view> getAllEmojis()
{
    std::vector<std::string_view> emojis;
    emojis.reserve(smileyEmojis.size() + bodyEmojis.size() + personEmojis.size() + natureEmojis.size() +
                   foodEmojis.size() + travelEmojis.size() + activityEmojis.size() + objectEmojis.size() +
                   symbolEmojis.size() + flagEmojis.size());

    emojis.insert(emojis.end(), smileyEmojis.begin(), smileyEmojis.end());
    emojis.insert(emojis.end(), bodyEmojis.begin(), bodyEmojis.end());
    emojis.insert(emojis.end(), personEmojis.begin(), personEmojis.end());
    emojis.insert(emojis.end(), natureEmojis.begin(), natureEmojis.end());
    emojis.insert(emojis.end(), foodEmojis.begin(), foodEmojis.end());
    emojis.insert(emojis.end(), travelEmojis.begin(), travelEmojis.end());
    emojis.insert(emojis.end(), activityEmojis.begin(), activityEmojis.end());
    emojis.insert(emojis.end(), objectEmojis.begin(), objectEmojis.end());
    emojis.insert(emojis.end(), symbolEmojis.begin(), symbolEmojis.end());
    emojis.insert(emojis.end(), flagEmojis.begin(), flagEmojis.end());

    return emojis;
}

std::string username(std::optional<std::string> firstName, std::optional<std::string> lastName, Locale locale)
{
    const auto firstNameLower = common::toLower(std::string{firstName ? *firstName : person::firstName(locale)});
    const auto lastNameLower = common::toLower(std::string{lastName ? *lastName : person::lastName(locale)});

    std::string username;

    switch (number::integer<int>(2))
    {
    case 0:
        username = common::format("{}{}{}", firstNameLower, lastNameLower, number::integer<int>(1970, 2005));
        break;
    case 1:
        username = common::format("{}{}{}", firstNameLower,
                                  helper::randomElement(std::vector<std::string>{".", "_", ""}), lastNameLower);
        break;
    case 2:
        username = common::format("{}{}{}", lastNameLower,
                                  helper::randomElement(std::vector<std::string>{".", "_", ""}), firstNameLower);
        break;
    }

    return username;
}

std::string email(std::optional<std::string> firstName, std::optional<std::string> lastName,
                  std::optional<std::string> emailHost)
{
    return common::format("{}@{}", username(std::move(firstName), std::move(lastName)),
                          emailHost ? *emailHost : helper::randomElement(emailHosts));
}

std::string exampleEmail(std::optional<std::string> firstName, std::optional<std::string> lastName)
{
    return common::format("{}@{}", username(std::move(firstName), std::move(lastName)),
                          helper::randomElement(emailExampleHosts));
}

std::string password(int length, const PasswordOptions& options)
{
    std::string characters;

    if (options.upperLetters)
    {
        characters += string::upperCharacters;
    }

    if (options.lowerLetters)
    {
        characters += string::lowerCharacters;
    }

    if (options.numbers)
    {
        characters += string::numericCharacters;
    }

    if (options.symbols)
    {
        characters += string::symbolCharacters;
    }

    std::string password;

    for (int i = 0; i < length; ++i)
    {
        password += helper::randomElement(characters);
    }

    return password;
}

std::string_view emoji(std::optional<EmojiType> type)
{
    if (type)
    {
        const auto& emojisMapped = emojiTypeToEmojisMapping.at(*type);

        return helper::randomElement(emojisMapped);
    }

    const auto emojis = getAllEmojis();

    return helper::randomElement(emojis);
}

bool checkIfEmojiIsValid(const std::string& emojiToCheck)
{
    const auto emojis = getAllEmojis();

    return std::find(emojis.begin(), emojis.end(), emojiToCheck) != emojis.end();
}

std::string_view protocol()
{
    return helper::randomElement(webProtocols);
}

std::string_view httpMethod()
{
    return helper::randomElement(httpMethodNames);
}

unsigned httpStatusCode(std::optional<HttpResponseType> responseType)
{
    if (responseType)
    {
        const auto& statusCodes = httpResponseTypeToCodesMapping.at(*responseType);

        return helper::randomElement(statusCodes);
    }

    std::vector<unsigned> statusCodes;
    statusCodes.reserve(httpStatusInformationalCodes.size() + httpStatusSuccessCodes.size() +
                        httpStatusRedirectionCodes.size() + httpStatusClientErrorCodes.size() +
                        httpStatusServerErrorCodes.size());

    statusCodes.insert(statusCodes.end(), httpStatusInformationalCodes.begin(), httpStatusInformationalCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusSuccessCodes.begin(), httpStatusSuccessCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusRedirectionCodes.begin(), httpStatusRedirectionCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusClientErrorCodes.begin(), httpStatusClientErrorCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusServerErrorCodes.begin(), httpStatusServerErrorCodes.end());

    return helper::randomElement(statusCodes);
}

std::string_view httpRequestHeader()
{
    return helper::randomElement(httpRequestHeaders);
}

std::string_view httpResponseHeader()
{
    return helper::randomElement(httpResponseHeaders);
}

std::string_view httpMediaType()
{
    return helper::randomElement(httpMediaTypes);
}

std::string ipv4(const IPv4Class& ipv4class)
{
    std::array<unsigned int, 4> sectors{};

    sectors[3] = number::integer<unsigned int>(ipv4SectorUpperBound);
    sectors[2] = number::integer<unsigned int>(ipv4SectorUpperBound);

    switch (ipv4class)
    {
    case IPv4Class::A:
    {
        sectors[1] = number::integer<unsigned int>(ipv4SectorUpperBound);
        sectors[0] = ipv4ClassAFirstSector;
        break;
    }
    case IPv4Class::B:
    {
        sectors[1] = number::integer<unsigned int>(ipv4ClassBSecondSectorLowerBound, ipv4ClassBSecondSectorUpperBound);
        sectors[0] = ipv4ClassBFirstSector;
        break;
    }
    case IPv4Class::C:
    {
        sectors[1] = ipv4ClassCSecondSector;
        sectors[0] = ipv4ClassCFirstSector;
    }
    }

    return common::format("{}.{}.{}.{}", sectors[0], sectors[1], sectors[2], sectors[3]);
}

std::string ipv4(const std::array<unsigned int, 4>& baseIpv4Address, const std::array<unsigned int, 4>& generationMask)
{
    std::array<unsigned int, 4> sectors{};

    for (std::size_t i = 0; i < ipv4AddressSectors; i++)
    {
        sectors[i] = (~generationMask[i]) & number::integer<unsigned int>(ipv4SectorUpperBound);
        sectors[i] |= (baseIpv4Address[i] & generationMask[i]);
    }

    return common::format("{}.{}.{}.{}", sectors[0], sectors[1], sectors[2], sectors[3]);
}

std::string ipv6()
{
    std::vector<std::string> ipv6Parts;

    ipv6Parts.reserve(8);

    for (int i = 0; i < 8; i++)
    {
        ipv6Parts.push_back(number::hexadecimal(4, HexCasing::Lower, HexPrefix::None));
    }

    return common::joinString(ipv6Parts, ":");
}

std::string mac(const std::string& sep)
{
    std::string mac;
    std::string currentSep = sep;
    const std::initializer_list<std::string> acceptableSeparators = {":", "-", ""};

    if (std::ranges::find(acceptableSeparators, currentSep) == acceptableSeparators.end())
    {
        currentSep = ":";
    }

    for (int i = 0; i < 12; i++)
    {
        mac += number::hexadecimal(0, 15);

        if (i % 2 == 1 && i != 11)
        {
            mac += currentSep;
        }
    }

    return mac;
}

unsigned port()
{
    return number::integer(65535u);
}

std::string url(const WebProtocol& webProtocol)
{
    const auto protocolStr = webProtocol == WebProtocol::Https ? "https" : "http";

    return common::format("{}://{}", protocolStr, domainName());
}

std::string domainName()
{
    return common::format("{}.{}", domainWord(), domainSuffix());
}

std::string domainWord()
{
    return common::toLower(common::format("{}-{}", word::adjective(), word::noun()));
}

std::string_view domainSuffix()
{
    return helper::randomElement(domainSuffixes);
}

std::string anonymousUsername(unsigned maxLength)
{
    unsigned defaultMin = 6;
    unsigned defaultMax = 20;

    if (maxLength < defaultMin)
        maxLength = defaultMin;
    else if (maxLength > defaultMax)
        maxLength = defaultMax;

    const std::integral auto adjectiveLength = number::integer<unsigned>(3, 1 + maxLength / 2);

    const auto nounLength = maxLength - adjectiveLength;

    return common::format("{}{}", word::adjective(adjectiveLength), word::noun(nounLength));
}

std::string_view getJWTAlgorithm()
{
    return helper::randomElement(jwtAlgorithms);
}

std::string getJWTToken(const std::optional<std::map<std::string, std::string>>& header,
                        const std::optional<std::map<std::string, std::string>>& payload,
                        const std::optional<std::string>& refDate)
{
    const auto refDateValue = refDate.value_or(faker::date::anytime());

    // maybe add option to set ref date to date functions then refactor this
    const auto iatDefault = faker::date::recentDate(faker::date::dayOfMonth(), faker::date::DateFormat::Timestamp);
    const auto expDefault = faker::date::soonDate(faker::date::dayOfMonth(), faker::date::DateFormat::Timestamp);
    const auto nbfDefault = faker::date::anytime(faker::date::DateFormat::Timestamp);

    std::optional<std::map<std::string, std::string>> localHeader = header;
    std::optional<std::map<std::string, std::string>> localPayload = payload;

    std::string algorithm(getJWTAlgorithm());

    if (!localHeader)
    {
        localHeader = {{"alg", algorithm}, {"typ", "JWT"}};
    }

    if (!localPayload)
    {
        localPayload = {{"iat", std::to_string(std::round(std::stoll(iatDefault)))},
                        {"exp", std::to_string(std::round(std::stoll(expDefault)))},
                        {"nbf", std::to_string(std::round(std::stoll(nbfDefault)))},
                        {"iss", faker::company::companyName()},
                        {"sub", faker::string::uuid()},
                        {"aud", faker::string::uuid()},
                        {"jti", faker::string::uuid()}};
    }

    const auto headerToJSON = toJSON(localHeader.value());
    const auto encodedHeader = toBase64UrlEncode(headerToJSON);

    const auto payloadToJSON = toJSON(localPayload.value());
    const auto encodedPayload = toBase64UrlEncode(payloadToJSON);

    const auto signature = faker::string::alphanumeric(64);

    return encodedHeader + "." + encodedPayload + "." + signature;
}

}
