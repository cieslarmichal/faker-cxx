#include "faker-cxx/Internet.h"

#include <array>
#include <map>
#include <utility>

#include "../../common/FormatHelper.h"
#include "../../common/StringHelper.h"
#include "../string/data/Characters.h"
#include "data/DomainSuffixes.h"
#include "data/EmailHosts.h"
#include "data/Emojis.h"
#include "data/HttpMediaType.h"
#include "data/HttpRequestHeaders.h"
#include "data/HttpResponseHeaders.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Person.h"
#include "faker-cxx/String.h"
#include "faker-cxx/Word.h"
#include "faker-cxx/types/Country.h"

namespace faker
{
namespace
{
const std::vector<std::string> webProtocols{"http", "https"};
const std::vector<std::string> httpMethodNames{"GET", "POST", "DELETE", "PATCH", "PUT"};
const std::vector<unsigned> httpStatusInformationalCodes{100, 101, 102, 103};
const std::vector<unsigned> httpStatusSuccessCodes{200, 201, 202, 203, 204, 205, 206, 207, 208, 226};
const std::vector<unsigned> httpStatusRedirectionCodes{300, 301, 302, 303, 304, 305, 306, 307, 308};
const std::vector<unsigned> httpStatusClientErrorCodes{400, 401, 402, 403, 404, 405, 406, 407, 408, 409,
                                                       410, 411, 412, 413, 414, 415, 416, 417, 418, 421,
                                                       422, 423, 424, 425, 426, 428, 429, 431, 451};
const std::vector<unsigned> httpStatusServerErrorCodes{500, 501, 502, 503, 504, 505, 506, 507, 508, 510, 511};
const std::map<HttpResponseType, std::vector<unsigned>> httpResponseTypeToCodesMapping{
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
const std::map<EmojiType, std::vector<std::string>> emojiTypeToEmojisMapping{
    {EmojiType::Smiley, smileyEmojis},     {EmojiType::Body, bodyEmojis},     {EmojiType::Person, personEmojis},
    {EmojiType::Nature, natureEmojis},     {EmojiType::Food, foodEmojis},     {EmojiType::Travel, travelEmojis},
    {EmojiType::Activity, activityEmojis}, {EmojiType::Object, objectEmojis}, {EmojiType::Symbol, symbolEmojis},
    {EmojiType::Flag, flagEmojis},
};
}

std::string Internet::username(std::optional<std::string> firstNameInit, std::optional<std::string> lastNameInit, Country country)
{
    const auto firstName = firstNameInit ? *firstNameInit : Person::firstName(country);
    const auto lastName = lastNameInit ? *lastNameInit : Person::lastName(country);

    std::string username;

    switch (Number::integer<int>(2))
    {
    case 0:
        username = FormatHelper::format("{}{}{}", firstName, lastName, Number::integer<int>(999));
        break;
    case 1:
        username = FormatHelper::format(
            "{}{}{}", firstName, Helper::arrayElement<std::string>(std::vector<std::string>{".", "_", ""}), lastName);
        break;
    case 2:
        username = FormatHelper::format("{}{}{}{}", firstName,
                                        Helper::arrayElement<std::string>(std::vector<std::string>{".", "_", ""}),
                                        lastName, Number::integer<int>(99));
        break;
    }

    return username;
}

std::string Internet::email(std::optional<std::string> firstName, std::optional<std::string> lastName,
                            std::optional<std::string> emailHost)
{
    return FormatHelper::format("{}@{}", username(std::move(firstName), std::move(lastName)),
                                emailHost ? *emailHost : Helper::arrayElement<std::string>(emailHosts));
}

std::string Internet::exampleEmail(std::optional<std::string> firstName, std::optional<std::string> lastName)
{
    return FormatHelper::format("{}@{}", username(std::move(firstName), std::move(lastName)),
                                Helper::arrayElement<std::string>(emailExampleHosts));
}

std::string Internet::password(int length, PasswordOptions options)
{
    std::string characters;

    if (options.upperLetters)
    {
        characters += faker::upperCharacters;
    }

    if (options.lowerLetters)
    {
        characters += faker::lowerCharacters;
    }

    if (options.numbers)
    {
        characters += faker::numericCharacters;
    }

    if (options.symbols)
    {
        characters += faker::symbolCharacters;
    }

    std::string password;

    for (int i = 0; i < length; ++i)
    {
        password += Helper::arrayElement<char>(characters);
    }

    return password;
}

std::string Internet::emoji(std::optional<EmojiType> type)
{
    if (type)
    {
        const auto& emojis = emojiTypeToEmojisMapping.at(*type);

        return Helper::arrayElement<std::string>(emojis);
    }

    std::vector<std::string> emojis;

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

    return Helper::arrayElement<std::string>(emojis);
}

bool Internet::checkIfEmojiIsValid(const std::string& emojiToCheck)
{
    for (const auto& vector : {smileyEmojis, bodyEmojis, personEmojis, natureEmojis, foodEmojis, travelEmojis,
                               activityEmojis, objectEmojis, symbolEmojis, flagEmojis})
    {
        if (std::find(vector.begin(), vector.end(), emojiToCheck) != vector.end())
        {
            return true;
        }
    }

    return false;
}

std::string Internet::protocol()
{
    return Helper::arrayElement<std::string>(webProtocols);
}

std::string Internet::httpMethod()
{
    return Helper::arrayElement<std::string>(httpMethodNames);
}

unsigned Internet::httpStatusCode(std::optional<HttpResponseType> responseType)
{
    if (responseType)
    {
        const auto& statusCodes = httpResponseTypeToCodesMapping.at(*responseType);

        return Helper::arrayElement<unsigned>(statusCodes);
    }

    std::vector<unsigned> statusCodes;

    statusCodes.insert(statusCodes.end(), httpStatusInformationalCodes.begin(), httpStatusInformationalCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusSuccessCodes.begin(), httpStatusSuccessCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusRedirectionCodes.begin(), httpStatusRedirectionCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusClientErrorCodes.begin(), httpStatusClientErrorCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusServerErrorCodes.begin(), httpStatusServerErrorCodes.end());

    return Helper::arrayElement<unsigned>(statusCodes);
}

std::string Internet::httpRequestHeader()
{
    return Helper::arrayElement<std::string>(httpRequestHeaders);
}

std::string Internet::httpResponseHeader()
{
    return Helper::arrayElement<std::string>(httpResponseHeaders);
}

std::string Internet::httpMediaType()
{
    return Helper::arrayElement<std::string>(httpMediaTypes);
}

std::string Internet::ipv4(IPv4Class ipv4class)
{
    std::array<unsigned int, 4> sectors{};

    sectors[3] = Number::integer<unsigned int>(ipv4SectorUpperBound);
    sectors[2] = Number::integer<unsigned int>(ipv4SectorUpperBound);

    switch (ipv4class)
    {
    case IPv4Class::A:
    {
        sectors[1] = Number::integer<unsigned int>(ipv4SectorUpperBound);
        sectors[0] = ipv4ClassAFirstSector;
        break;
    }
    case IPv4Class::B:
    {
        sectors[1] = Number::integer<unsigned int>(ipv4ClassBSecondSectorLowerBound, ipv4ClassBSecondSectorUpperBound);
        sectors[0] = ipv4ClassBFirstSector;
        break;
    }
    case IPv4Class::C:
    {
        sectors[1] = ipv4ClassCSecondSector;
        sectors[0] = ipv4ClassCFirstSector;
    }
    }

    return FormatHelper::format("{}.{}.{}.{}", sectors[0], sectors[1], sectors[2], sectors[3]);
}

std::string Internet::ipv4(const std::array<unsigned int, 4>& baseIpv4Address,
                           const std::array<unsigned int, 4>& generationMask)
{
    std::array<unsigned int, 4> sectors{};

    for (std::size_t i = 0; i < ipv4AddressSectors; i++)
    {
        sectors[i] = (~generationMask[i]) & Number::integer<unsigned int>(ipv4SectorUpperBound);
        sectors[i] |= (baseIpv4Address[i] & generationMask[i]);
    }

    return FormatHelper::format("{}.{}.{}.{}", sectors[0], sectors[1], sectors[2], sectors[3]);
}

std::string Internet::ipv6()
{
    std::vector<std::string> ipv6Parts;

    ipv6Parts.reserve(8);

    for (int i = 0; i < 8; i++)
    {
        ipv6Parts.push_back(String::hexadecimal(4, HexCasing::Lower, HexPrefix::None));
    }

    return StringHelper::join(ipv6Parts, ":");
}

std::string Internet::mac(const std::string& sep)
{
    std::string mac;
    std::string currentSep = sep;
    std::vector<std::string> acceptableSeparators = {":", "-", ""};

    if (std::ranges::find(acceptableSeparators, currentSep) == acceptableSeparators.end())
    {
        currentSep = ":";
    }

    for (int i = 0; i < 12; i++)
    {
        mac += Number::hex();
        if (i % 2 == 1 && i != 11)
        {
            mac += currentSep;
        }
    }
    return mac;
}

unsigned Internet::port()
{
    return Number::integer(65535u);
}

std::string Internet::url(WebProtocol webProtocol)
{
    const auto protocol = webProtocol == WebProtocol::Https ? "https" : "http";

    return FormatHelper::format("{}://{}", protocol, domainName());
}

std::string Internet::domainName()
{
    return FormatHelper::format("{}.{}", domainWord(), domainSuffix());
}

std::string Internet::domainWord()
{
    return StringHelper::toLower(FormatHelper::format("{}-{}", Word::adjective(), Word::noun()));
}

std::string Internet::domainSuffix()
{
    return Helper::arrayElement<std::string>(domainSuffixes);
}

std::string Internet::anonymousUsername(unsigned maxLength)
{
    unsigned defaultMin = 6;
    unsigned defaultMax = 20;

    if (maxLength < defaultMin)
        maxLength = defaultMin;
    else if (maxLength > defaultMax)
        maxLength = defaultMax;

    unsigned adjectiveLength = Number::integer<unsigned>(3, 1 + maxLength/2);
    unsigned nounLength = maxLength - adjectiveLength;
    std::stringstream usernameBuilder;

    while (true)
    {
        std::string adjective = Word::adjective(adjectiveLength);
        if (adjectiveLength == adjective.length())
        {
            usernameBuilder << adjective;
            break;
        }
    }

    while (true)
    {
        std::string noun = Word::noun(nounLength);
        if (nounLength == noun.length())
        {
            usernameBuilder << noun;
            break;
        }
    }

    return usernameBuilder.str();
}

}
