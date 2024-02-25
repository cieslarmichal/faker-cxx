#include "../common/format_helper.h"
#include "../common/string_helper.h"
#include "internet_data.h"
#include "string_data.h"
#include <cassert>
#include <faker/helper.h>
#include <faker/internet.h>
#include <faker/person.h>
#include <faker/string.h>
#include <faker/types/country.h>
#include <faker/word.h>
#include <unordered_map>
#include <utility>
#include <vector>

namespace faker::internet {
namespace {
    const std::array<std::string_view, 2> webProtocols { "http", "https" };
    const std::array<std::string_view, 5> httpMethodNames { "GET", "POST", "DELETE", "PATCH",
        "PUT" };
    const std::array<unsigned, 4> httpStatusInformationalCodes { 100, 101, 102, 103 };
    const std::array<unsigned, 10> httpStatusSuccessCodes { 200, 201, 202, 203, 204, 205, 206, 207,
        208, 226 };
    const std::array<unsigned, 9> httpStatusRedirectionCodes { 300, 301, 302, 303, 304, 305, 306,
        307, 308 };
    const std::array<unsigned, 30> httpStatusClientErrorCodes { 400, 401, 402, 403, 404, 405, 406,
        407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 421, 422, 423, 424, 425, 426,
        428, 429, 431, 451 };
    const std::array<unsigned, 11> httpStatusServerErrorCodes { 500, 501, 502, 503, 504, 505, 506,
        507, 508, 510, 511 };
    constexpr unsigned int ipv4AddressSectors = 4u;
    constexpr unsigned int ipv4ClassCFirstSector = 192u;
    constexpr unsigned int ipv4ClassCSecondSector = 168u;
    constexpr unsigned int ipv4ClassAFirstSector = 10u;
    constexpr unsigned int ipv4ClassBFirstSector = 172;
    constexpr unsigned int ipv4ClassBSecondSectorLowerBound = 16u;
    constexpr unsigned int ipv4ClassBSecondSectorUpperBound = 31u;
    constexpr unsigned int ipv4SectorUpperBound = 255u;
}

std::string username(std::optional<std::string> firstNameInit,
    std::optional<std::string> lastNameInit, Country country)
{
    const auto firstName = firstNameInit ? *firstNameInit : person::firstName(country);
    const auto lastName = lastNameInit ? *lastNameInit : person::lastName(country);

    std::string username;

    switch (number::integer(2)) {
    case 0:
        username = FormatHelper::format("{}{}{}", firstName, lastName, number::integer(999));
        break;
    case 1:
        username = FormatHelper::format("{}{}{}", firstName,
            Helper::arrayElement<std::string>(std::vector<std::string> { ".", "_", "" }), lastName);
        break;
    case 2:
        username = FormatHelper::format("{}{}{}{}", firstName,
            Helper::arrayElement<std::string>(std::vector<std::string> { ".", "_", "" }), lastName,
            number::integer(99));
        break;
    }

    return username;
}

std::string email(std::optional<std::string> firstName, std::optional<std::string> lastName,
    std::optional<std::string> emailHost)
{
    return FormatHelper::format("{}@{}", username(std::move(firstName), std::move(lastName)),
        emailHost ? *emailHost : Helper::arrayElement(emailHosts));
}

std::string exampleEmail(std::optional<std::string> firstName, std::optional<std::string> lastName)
{
    return FormatHelper::format("{}@{}", username(std::move(firstName), std::move(lastName)),
        Helper::arrayElement(emailExampleHosts));
}

std::string password(int length, PasswordOptions options)
{
    std::string characters;

    if (options.upperLetters) {
        characters += faker::upperCharacters;
    }

    if (options.lowerLetters) {
        characters += faker::lowerCharacters;
    }

    if (options.numbers) {
        characters += faker::numericCharacters;
    }

    if (options.symbols) {
        characters += faker::symbolCharacters;
    }

    std::string password;

    for (int i = 0; i < length; ++i) {
        password += Helper::arrayElement(characters);
    }

    return password;
}

std::string_view emoji(std::optional<EmojiType> type)
{
    static std::vector<std::string_view> emojis;

    if (emojis.empty()) {
        emojis.reserve(emojis.size() + smileyEmojis.size() + bodyEmojis.size() + personEmojis.size()
            + natureEmojis.size() + foodEmojis.size() + travelEmojis.size() + activityEmojis.size()
            + objectEmojis.size() + symbolEmojis.size() + flagEmojis.size());
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
    }

    if (type) {
        switch (*type) {
        case EmojiType::Smiley:
            return Helper::arrayElement(smileyEmojis);
        case EmojiType::Body:
            return Helper::arrayElement(bodyEmojis);
        case EmojiType::Person:
            return Helper::arrayElement(personEmojis);
        case EmojiType::Nature:
            return Helper::arrayElement(natureEmojis);
        case EmojiType::Food:
            return Helper::arrayElement(foodEmojis);
        case EmojiType::Travel:
            return Helper::arrayElement(travelEmojis);
        case EmojiType::Activity:
            return Helper::arrayElement(activityEmojis);
        case EmojiType::Object:
            return Helper::arrayElement(objectEmojis);
        case EmojiType::Symbol:
            return Helper::arrayElement(symbolEmojis);
        case EmojiType::Flag:
            return Helper::arrayElement(flagEmojis);
        default:
            assert(false && "Invalid emoji type");
        }
    }

    return Helper::arrayElement(emojis);
}

bool checkIfEmojiIsValid(const std::string& emojiToCheck)
{
    static std::vector<std::string_view> emojis;

    if (emojis.empty()) {
        emojis.reserve(emojis.size() + smileyEmojis.size() + bodyEmojis.size() + personEmojis.size()
            + natureEmojis.size() + foodEmojis.size() + travelEmojis.size() + activityEmojis.size()
            + objectEmojis.size() + symbolEmojis.size() + flagEmojis.size());
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
    }

    return std::find(emojis.begin(), emojis.end(), emojiToCheck) != emojis.end();
}

std::string_view protocol() { return Helper::arrayElement(webProtocols); }

std::string_view httpMethod() { return Helper::arrayElement(httpMethodNames); }

unsigned httpStatusCode(std::optional<HttpResponseType> responseType)
{
    static std::vector<unsigned> statusCodes;

    if (statusCodes.empty()) {
        statusCodes.reserve(statusCodes.size() + httpStatusInformationalCodes.size()
            + httpStatusSuccessCodes.size() + httpStatusRedirectionCodes.size()
            + httpStatusClientErrorCodes.size() + httpStatusServerErrorCodes.size());
        statusCodes.insert(statusCodes.end(), httpStatusInformationalCodes.begin(),
            httpStatusInformationalCodes.end());
        statusCodes.insert(
            statusCodes.end(), httpStatusSuccessCodes.begin(), httpStatusSuccessCodes.end());
        statusCodes.insert(statusCodes.end(), httpStatusRedirectionCodes.begin(),
            httpStatusRedirectionCodes.end());
        statusCodes.insert(statusCodes.end(), httpStatusClientErrorCodes.begin(),
            httpStatusClientErrorCodes.end());
        statusCodes.insert(statusCodes.end(), httpStatusServerErrorCodes.begin(),
            httpStatusServerErrorCodes.end());
    }

    if (responseType) {
        switch (*responseType) {
        case HttpResponseType::Informational:
            return Helper::arrayElement(httpStatusInformationalCodes);
        case HttpResponseType::Success:
            return Helper::arrayElement(httpStatusSuccessCodes);
        case HttpResponseType::Redirection:
            return Helper::arrayElement(httpStatusRedirectionCodes);
        case HttpResponseType::ClientError:
            return Helper::arrayElement(httpStatusClientErrorCodes);
        case HttpResponseType::ServerError:
            return Helper::arrayElement(httpStatusServerErrorCodes);
        default:
            assert(false && "Invalid http response type");
        }
    }

    return Helper::arrayElement(statusCodes);
}

std::string_view httpRequestHeader() { return Helper::arrayElement(httpRequestHeaders); }

std::string_view httpResponseHeader() { return Helper::arrayElement(httpResponseHeaders); }

std::string_view httpMediaType() { return Helper::arrayElement(httpMediaTypes); }

std::string ipv4(IPv4Class ipv4class)
{
    std::array<unsigned int, 4> sectors {};

    sectors[3] = number::integer(ipv4SectorUpperBound);
    sectors[2] = number::integer(ipv4SectorUpperBound);

    switch (ipv4class) {
    case IPv4Class::A: {
        sectors[1] = number::integer(ipv4SectorUpperBound);
        sectors[0] = ipv4ClassAFirstSector;
        break;
    }
    case IPv4Class::B: {
        sectors[1]
            = number::integer(ipv4ClassBSecondSectorLowerBound, ipv4ClassBSecondSectorUpperBound);
        sectors[0] = ipv4ClassBFirstSector;
        break;
    }
    case IPv4Class::C: {
        sectors[1] = ipv4ClassCSecondSector;
        sectors[0] = ipv4ClassCFirstSector;
    }
    }

    return FormatHelper::format("{}.{}.{}.{}", sectors[0], sectors[1], sectors[2], sectors[3]);
}

std::string ipv4(const std::array<unsigned int, 4>& baseIpv4Address,
    const std::array<unsigned int, 4>& generationMask)
{
    std::array<unsigned int, 4> sectors {};

    for (std::size_t i = 0; i < ipv4AddressSectors; i++) {
        sectors[i] = (~generationMask[i]) & number::integer(ipv4SectorUpperBound);
        sectors[i] |= (baseIpv4Address[i] & generationMask[i]);
    }

    return FormatHelper::format("{}.{}.{}.{}", sectors[0], sectors[1], sectors[2], sectors[3]);
}

std::string ipv6()
{
    std::vector<std::string> ipv6Parts;

    ipv6Parts.reserve(8);

    for (int i = 0; i < 8; i++) {
        ipv6Parts.push_back(String::hexadecimal(4, HexCasing::Lower, HexPrefix::None));
    }

    return StringHelper::join(ipv6Parts, ":");
}

std::string mac(const std::string& sep)
{
    std::string mac;
    std::string currentSep = sep;
    std::vector<std::string> acceptableSeparators = { ":", "-", "" };

    if (std::find(acceptableSeparators.begin(), acceptableSeparators.end(), currentSep)
        == acceptableSeparators.end()) {
        currentSep = ":";
    }

    for (int i = 0; i < 12; i++) {
        mac += number::hex();
        if (i % 2 == 1 && i != 11) {
            mac += currentSep;
        }
    }
    return mac;
}

unsigned port() { return number::integer(65535u); }

std::string url(WebProtocol webProtocol)
{
    const auto protocol = webProtocol == WebProtocol::Https ? "https" : "http";

    return FormatHelper::format("{}://{}", protocol, domainName());
}

std::string domainName() { return FormatHelper::format("{}.{}", domainWord(), domainSuffix()); }

std::string domainWord()
{
    return StringHelper::toLower(FormatHelper::format("{}-{}", word::adjective(), word::noun()));
}

std::string_view domainSuffix() { return Helper::arrayElement(domainSuffixes); }

}
