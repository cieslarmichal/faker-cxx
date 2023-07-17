#include "faker-cxx/Internet.h"

#include <format>
#include <map>
#include <utility>

#include "data/EmailHosts.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Person.h"

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
}
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

}
