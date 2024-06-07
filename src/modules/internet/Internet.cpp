#include "faker-cxx/Internet.h"

#include <array>
#include <vector>
#include <initializer_list>
#include <unordered_map>
#include <map>

#include "common/FormatHelper.h"
#include "common/StringHelper.h"
#include "modules/string/StringData.h"
#include "InternetData.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Person.h"
#include "faker-cxx/String.h"
#include "faker-cxx/types/Country.h"
#include "faker-cxx/Word.h"

namespace faker
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

const std::map<Internet::EmojiType, std::vector<std::string_view>> emojiTypeToEmojisMapping = {
    {Internet::EmojiType::Smiley, Helper::toVector(internet::smileyEmojis)},
    {Internet::EmojiType::Body, Helper::toVector(internet::bodyEmojis)},
    {Internet::EmojiType::Person, Helper::toVector(internet::personEmojis)},
    {Internet::EmojiType::Nature, Helper::toVector(internet::natureEmojis)},
    {Internet::EmojiType::Food, Helper::toVector(internet::foodEmojis)},
    {Internet::EmojiType::Travel, Helper::toVector(internet::travelEmojis)},
    {Internet::EmojiType::Activity, Helper::toVector(internet::activityEmojis)},
    {Internet::EmojiType::Object, Helper::toVector(internet::objectEmojis)},
    {Internet::EmojiType::Symbol, Helper::toVector(internet::symbolEmojis)},
    {Internet::EmojiType::Flag, Helper::toVector(internet::flagEmojis)},
};
}

std::vector<std::string_view> getAllEmojis()
{
    using namespace faker::internet;
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

std::string Internet::username(std::optional<std::string> firstNameInit, std::optional<std::string> lastNameInit,
                               Country country)
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
                                emailHost ? *emailHost : Helper::arrayElement(internet::emailHosts));
}

std::string Internet::exampleEmail(std::optional<std::string> firstName, std::optional<std::string> lastName)
{
    return FormatHelper::format("{}@{}", username(std::move(firstName), std::move(lastName)),
                                Helper::arrayElement(internet::emailExampleHosts));
}

std::string Internet::password(int length, const PasswordOptions& options)
{
    std::string characters;

    if (options.upperLetters)
    {
        characters += faker::string::upperCharacters;
    }

    if (options.lowerLetters)
    {
        characters += faker::string::lowerCharacters;
    }

    if (options.numbers)
    {
        characters += faker::string::numericCharacters;
    }

    if (options.symbols)
    {
        characters += faker::string::symbolCharacters;
    }

    std::string password;

    for (int i = 0; i < length; ++i)
    {
        password += Helper::arrayElement<char>(characters);
    }

    return password;
}

std::string_view Internet::emoji(std::optional<Internet::EmojiType> type)
{
    using namespace faker::internet;
    if (type)
    {
        const auto& emojisMapped = emojiTypeToEmojisMapping.at(*type);

        return Helper::arrayElement(emojisMapped);
    }

    const auto emojis = getAllEmojis();
    return Helper::arrayElement(emojis);
}

bool Internet::checkIfEmojiIsValid(const std::string& emojiToCheck)
{
    const auto emojis = getAllEmojis();
    return std::find(emojis.begin(), emojis.end(), emojiToCheck) != emojis.end();
}

std::string_view Internet::protocol()
{
    return Helper::arrayElement(webProtocols);
}

std::string_view Internet::httpMethod()
{
    return Helper::arrayElement(httpMethodNames);
}

unsigned Internet::httpStatusCode(std::optional<HttpResponseType> responseType)
{
    if (responseType)
    {
        const auto& statusCodes = httpResponseTypeToCodesMapping.at(*responseType);

        return Helper::arrayElement(statusCodes);
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

    return Helper::arrayElement(statusCodes);
}

std::string_view Internet::httpRequestHeader()
{
    return Helper::arrayElement(internet::httpRequestHeaders);
}

std::string_view Internet::httpResponseHeader()
{
    return Helper::arrayElement(internet::httpResponseHeaders);
}

std::string_view Internet::httpMediaType()
{
    return Helper::arrayElement(internet::httpMediaTypes);
}

std::string Internet::ipv4(const IPv4Class& ipv4class)
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

    return StringHelper::joinString(ipv6Parts, ":");
}

std::string Internet::mac(const std::string& sep)
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
        mac += String::hexadecimal(0, 15);

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

std::string Internet::url(const WebProtocol& webProtocol)
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

std::string_view Internet::domainSuffix()
{
    return Helper::arrayElement(internet::domainSuffixes);
}

std::string Internet::anonymousUsername(unsigned maxLength)
{
    unsigned defaultMin = 6;
    unsigned defaultMax = 20;

    if (maxLength < defaultMin)
        maxLength = defaultMin;
    else if (maxLength > defaultMax)
        maxLength = defaultMax;

    const std::integral auto adjectiveLength = Number::integer<unsigned>(3, 1 + maxLength / 2);

    const auto nounLength = maxLength - adjectiveLength;

    std::stringstream usernameBuilder;

    usernameBuilder << Word::adjective(adjectiveLength) << Word::noun(nounLength);

    return usernameBuilder.str();
}

}
