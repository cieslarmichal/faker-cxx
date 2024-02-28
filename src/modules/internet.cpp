#include "../common/formatter.h"
#include "../common/random.h"
#include "../common/strings.h"
#include "internet_data.h"
#include "string_data.h"
#include <cassert>
#include <faker/internet.h>
#include <faker/number.h>
#include <faker/person.h>
#include <faker/string.h>
#include <faker/types/country.h>
#include <faker/word.h>
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
    const auto firstName = firstNameInit ? *firstNameInit : person::first_name(country);
    const auto lastName = lastNameInit ? *lastNameInit : person::last_name(country);

    std::string username;

    switch (number::integer(2)) {
    case 0:
        username = utils::format("{}{}{}", firstName, lastName, number::integer(999));
        break;
    case 1:
        username = utils::format("{}{}{}", firstName,
            random::element<std::string>(std::vector<std::string> { ".", "_", "" }), lastName);
        break;
    case 2:
        username = utils::format("{}{}{}{}", firstName,
            random::element<std::string>(std::vector<std::string> { ".", "_", "" }), lastName,
            number::integer(99));
        break;
    }

    return username;
}

std::string email(std::optional<std::string> firstName, std::optional<std::string> lastName,
    std::optional<std::string> emailHost)
{
    return utils::format("{}@{}", username(std::move(firstName), std::move(lastName)),
        emailHost ? *emailHost : random::element(data::emailHosts));
}

std::string example_email(std::optional<std::string> firstName, std::optional<std::string> lastName)
{
    return utils::format("{}@{}", username(std::move(firstName), std::move(lastName)),
        random::element(data::emailExampleHosts));
}

std::string password(int length, PasswordOptions options)
{
    std::string characters;

    if (options.upperLetters) {
        characters += string::data::upperCharacters;
    }

    if (options.lowerLetters) {
        characters += string::data::lowerCharacters;
    }

    if (options.numbers) {
        characters += string::data::numericCharacters;
    }

    if (options.symbols) {
        characters += string::data::symbolCharacters;
    }

    std::string password;

    for (int i = 0; i < length; ++i) {
        password += random::element(characters);
    }

    return password;
}

std::string_view emoji(std::optional<EmojiType> type)
{
    static std::vector<std::string_view> emojis;

    if (emojis.empty()) {
        emojis.reserve(emojis.size() + data::smileyEmojis.size() + data::bodyEmojis.size()
            + data::personEmojis.size() + data::natureEmojis.size() + data::foodEmojis.size()
            + data::travelEmojis.size() + data::activityEmojis.size() + data::objectEmojis.size()
            + data::symbolEmojis.size() + data::flagEmojis.size());
        emojis.insert(emojis.end(), data::smileyEmojis.begin(), data::smileyEmojis.end());
        emojis.insert(emojis.end(), data::bodyEmojis.begin(), data::bodyEmojis.end());
        emojis.insert(emojis.end(), data::personEmojis.begin(), data::personEmojis.end());
        emojis.insert(emojis.end(), data::natureEmojis.begin(), data::natureEmojis.end());
        emojis.insert(emojis.end(), data::foodEmojis.begin(), data::foodEmojis.end());
        emojis.insert(emojis.end(), data::travelEmojis.begin(), data::travelEmojis.end());
        emojis.insert(emojis.end(), data::activityEmojis.begin(), data::activityEmojis.end());
        emojis.insert(emojis.end(), data::objectEmojis.begin(), data::objectEmojis.end());
        emojis.insert(emojis.end(), data::symbolEmojis.begin(), data::symbolEmojis.end());
        emojis.insert(emojis.end(), data::flagEmojis.begin(), data::flagEmojis.end());
    }

    if (type) {
        switch (*type) {
        case EmojiType::Smiley:
            return random::element(data::smileyEmojis);
        case EmojiType::Body:
            return random::element(data::bodyEmojis);
        case EmojiType::Person:
            return random::element(data::personEmojis);
        case EmojiType::Nature:
            return random::element(data::natureEmojis);
        case EmojiType::Food:
            return random::element(data::foodEmojis);
        case EmojiType::Travel:
            return random::element(data::travelEmojis);
        case EmojiType::Activity:
            return random::element(data::activityEmojis);
        case EmojiType::Object:
            return random::element(data::objectEmojis);
        case EmojiType::Symbol:
            return random::element(data::symbolEmojis);
        case EmojiType::Flag:
            return random::element(data::flagEmojis);
        default:
            assert(false && "Invalid emoji type");
        }
    }

    return random::element(emojis);
}

bool is_valid_emoji(const std::string& emojiToCheck)
{
    static std::vector<std::string_view> emojis;

    if (emojis.empty()) {
        emojis.reserve(emojis.size() + data::smileyEmojis.size() + data::bodyEmojis.size()
            + data::personEmojis.size() + data::natureEmojis.size() + data::foodEmojis.size()
            + data::travelEmojis.size() + data::activityEmojis.size() + data::objectEmojis.size()
            + data::symbolEmojis.size() + data::flagEmojis.size());
        emojis.insert(emojis.end(), data::smileyEmojis.begin(), data::smileyEmojis.end());
        emojis.insert(emojis.end(), data::bodyEmojis.begin(), data::bodyEmojis.end());
        emojis.insert(emojis.end(), data::personEmojis.begin(), data::personEmojis.end());
        emojis.insert(emojis.end(), data::natureEmojis.begin(), data::natureEmojis.end());
        emojis.insert(emojis.end(), data::foodEmojis.begin(), data::foodEmojis.end());
        emojis.insert(emojis.end(), data::travelEmojis.begin(), data::travelEmojis.end());
        emojis.insert(emojis.end(), data::activityEmojis.begin(), data::activityEmojis.end());
        emojis.insert(emojis.end(), data::objectEmojis.begin(), data::objectEmojis.end());
        emojis.insert(emojis.end(), data::symbolEmojis.begin(), data::symbolEmojis.end());
        emojis.insert(emojis.end(), data::flagEmojis.begin(), data::flagEmojis.end());
    }

    return std::find(emojis.begin(), emojis.end(), emojiToCheck) != emojis.end();
}

std::string_view protocol() { return random::element(webProtocols); }

std::string_view http_method() { return random::element(httpMethodNames); }

unsigned http_status_code(std::optional<HttpResponseType> responseType)
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
            return random::element(httpStatusInformationalCodes);
        case HttpResponseType::Success:
            return random::element(httpStatusSuccessCodes);
        case HttpResponseType::Redirection:
            return random::element(httpStatusRedirectionCodes);
        case HttpResponseType::ClientError:
            return random::element(httpStatusClientErrorCodes);
        case HttpResponseType::ServerError:
            return random::element(httpStatusServerErrorCodes);
        default:
            assert(false && "Invalid http response type");
        }
    }

    return random::element(statusCodes);
}

std::string_view http_request_header() { return random::element(data::httpRequestHeaders); }

std::string_view http_response_header() { return random::element(data::httpResponseHeaders); }

std::string_view http_media_type() { return random::element(data::httpMediaTypes); }

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

    return utils::format("{}.{}.{}.{}", sectors[0], sectors[1], sectors[2], sectors[3]);
}

std::string ipv4(const std::array<unsigned int, 4>& baseIpv4Address,
    const std::array<unsigned int, 4>& generationMask)
{
    std::array<unsigned int, 4> sectors {};

    for (std::size_t i = 0; i < ipv4AddressSectors; i++) {
        sectors[i] = (~generationMask[i]) & number::integer(ipv4SectorUpperBound);
        sectors[i] |= (baseIpv4Address[i] & generationMask[i]);
    }

    return utils::format("{}.{}.{}.{}", sectors[0], sectors[1], sectors[2], sectors[3]);
}

std::string ipv6()
{
    std::string result;
    result.reserve(39);

    result += string::hexadecimal(4, hex_case::lower, hex_prefix::none);
    for (size_t i = 0; i < 7; ++i) {
        result += ':';
        result += string::hexadecimal(4, hex_case::lower, hex_prefix::none);
    }

    return result;
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

    return utils::format("{}://{}", protocol, domain_name());
}

std::string domain_name() { return utils::format("{}.{}", domain_word(), domain_suffix()); }

std::string domain_word()
{
    return utils::to_lower(utils::format("{}-{}", word::adjective(), word::noun()));
}

std::string_view domain_suffix() { return random::element(data::domainSuffixes); }

}
