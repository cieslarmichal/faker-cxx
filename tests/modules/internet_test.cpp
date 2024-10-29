#include <algorithm>
#include <array>
#include <cctype>
#include <initializer_list>
#include <optional>
#include <regex>
#include <string>
#include <string_view>
#include <vector>

#include "gtest/gtest.h"

#include "common/string_helper.h"
#include "faker-cxx/internet.h"
#include "faker-cxx/number.h"
#include "internet_data.h"
#include "number_data.h"
#include "person_data.h"
#include "string_data.h"
#include "word_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::internet;

namespace
{
const std::string passwordCharacters =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789~`!@#$%^&*()_-+={[}]|:;\"'<,>.?/";
const std::initializer_list<std::string_view> webProtocols{"http", "https"};
const std::initializer_list<std::string_view> httpMethodNames{"GET", "POST", "DELETE", "PATCH", "PUT"};
const std::initializer_list<unsigned> httpStatusInformationalCodes{100, 101, 102, 103};
const std::initializer_list<unsigned> httpStatusSuccessCodes{200, 201, 202, 203, 204, 205, 206, 207, 208, 226};
const std::initializer_list<unsigned> httpStatusRedirectionCodes{300, 301, 302, 303, 304, 305, 306, 307, 308};
const std::initializer_list<unsigned> httpStatusClientErrorCodes{400, 401, 402, 403, 404, 405, 406, 407, 408, 409,
                                                                 410, 411, 412, 413, 414, 415, 416, 417, 418, 421,
                                                                 422, 423, 424, 425, 426, 428, 429, 431, 451};
const std::initializer_list<unsigned> httpStatusServerErrorCodes{500, 501, 502, 503, 504, 505, 506, 507, 508, 510, 511};
constexpr unsigned int classAFirstSection = 10u;
constexpr unsigned int classBFirstSection = 172u;
constexpr unsigned int classBSecondSectionLowerBound = 16;
constexpr unsigned int classBSecondSectionUpperBound = 31;
constexpr unsigned int classCFirstSection = 192u;
constexpr unsigned int classCSecondSection = 168u;

std::array<unsigned int, 4> deconstructIpv4String(const std::string& ipv4)
{
    const auto ipParts = common::split(ipv4, ".");

    std::array<unsigned int, 4> result{static_cast<unsigned>(stoi(ipParts[0])), static_cast<unsigned>(stoi(ipParts[1])),
                                       static_cast<unsigned>(stoi(ipParts[2])),
                                       static_cast<unsigned>(stoi(ipParts[3]))};
    return result;
}
}

class InternetTest : public Test
{
public:
    InternetTest()
    {
        sortedAdjectivesDescendingBySize.assign(word::adjectives.cbegin(), word::adjectives.cend());
        std::sort(sortedAdjectivesDescendingBySize.begin(), sortedAdjectivesDescendingBySize.end(),
                  [](const std::string& first, const std::string& second) { return first.size() > second.size(); });
    }

    void assertDomainWord(const std::string& domainWord)
    {
        std::optional<std::string> foundAdjective = std::nullopt;

        for (const auto& adjective : sortedAdjectivesDescendingBySize)
        {
            if (domainWord.starts_with(adjective))
            {
                foundAdjective = adjective;
                break;
            }
        }

        ASSERT_TRUE(foundAdjective);

        ASSERT_EQ(domainWord[foundAdjective->size()], '-');

        const auto generatedNoun = domainWord.substr(foundAdjective->size() + 1);

        ASSERT_TRUE(std::ranges::any_of(word::nouns,
                                        [generatedNoun](const std::string_view& noun)
                                        {
                                            if (generatedNoun.size() != noun.size())
                                                return false;
                                            for (size_t i = 0; i < noun.size(); i++)
                                                if (std::tolower(noun[i]) != std::tolower(generatedNoun[i]))
                                                    return false;
                                            return true;
                                        }));
    }

    std::vector<std::string> sortedAdjectivesDescendingBySize;
};

TEST_F(InternetTest, shouldGenerateUsername)
{
    std::vector<std::string_view> firstNames(person::englishMaleFirstNames.begin(),
                                             person::englishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::englishFemaleFirstNames.begin(), person::englishFemaleFirstNames.end());

    const auto generatedUsername = username();

    ASSERT_TRUE(
        std::ranges::any_of(firstNames, [generatedUsername](const std::string_view& firstName)
                            { return generatedUsername.find(common::toLower(firstName)) != std::string::npos; }));
    ASSERT_TRUE(
        std::ranges::any_of(person::englishLastNames, [generatedUsername](const std::string_view& lastName)
                            { return generatedUsername.find(common::toLower(lastName)) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateUsernameWithFirstNameProvided)
{
    const std::string firstName = "Michael";

    const auto generatedUsername = username(firstName);

    ASSERT_TRUE(generatedUsername.find(common::toLower(firstName)) != std::string::npos);
    ASSERT_TRUE(
        std::ranges::any_of(person::englishLastNames, [generatedUsername](const std::string_view& lastName)
                            { return generatedUsername.find(common::toLower(lastName)) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateUsernameWithLastNameProvided)
{
    std::vector<std::string_view> firstNames(person::englishMaleFirstNames.begin(),
                                             person::englishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::englishFemaleFirstNames.begin(), person::englishFemaleFirstNames.end());

    const std::string lastName = "Cieslar";

    const auto generatedUsername = username(std::nullopt, lastName);

    ASSERT_TRUE(
        std::ranges::any_of(firstNames, [generatedUsername](const std::string_view& firstName)
                            { return generatedUsername.find(common::toLower(firstName)) != std::string::npos; }));
    ASSERT_TRUE(generatedUsername.find(common::toLower(lastName)) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateUsernameWithFullNameProvided)
{
    const std::string firstName = "Andrew";

    const std::string lastName = "Cieslar";

    const auto generatedUsername = username(firstName, lastName);

    ASSERT_TRUE(generatedUsername.find(common::toLower(firstName)) != std::string::npos);
    ASSERT_TRUE(generatedUsername.find(common::toLower(lastName)) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateInternationalUsernames)
{
    std::vector<std::string_view> firstNames(person::polishMaleFirstNames.begin(), person::polishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::polishFemaleFirstNames.begin(), person::polishFemaleFirstNames.end());

    const auto generatedUsername = username(std::nullopt, std::nullopt, Locale::pl_PL);

    ASSERT_TRUE(
        std::ranges::any_of(firstNames, [generatedUsername](const std::string_view& firstName)
                            { return generatedUsername.find(common::toLower(firstName)) != std::string::npos; }));

    ASSERT_TRUE(
        std::ranges::any_of(person::polishLastNames, [generatedUsername](const std::string_view& lastName)
                            { return generatedUsername.find(common::toLower(lastName)) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateEmail)
{
    std::vector<std::string_view> firstNames(person::englishMaleFirstNames.begin(),
                                             person::englishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::englishFemaleFirstNames.begin(), person::englishFemaleFirstNames.end());

    const auto generatedEmail = email();

    const auto emailParts = common::split(generatedEmail, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_TRUE(std::ranges::any_of(emailHosts, [generatedEmailHost](const std::string_view& emailHost)
                                    { return generatedEmailHost == emailHost; }));
    ASSERT_TRUE(
        std::ranges::any_of(firstNames, [generatedUsername](const std::string_view& firstName)
                            { return generatedUsername.find(common::toLower(firstName)) != std::string::npos; }));
    ASSERT_TRUE(
        std::ranges::any_of(person::englishLastNames, [generatedUsername](const std::string_view& lastName)
                            { return generatedUsername.find(common::toLower(lastName)) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateEmailWithFirstName)
{
    const std::string firstName = "Tom";

    const auto generatedEmail = email(firstName);

    const auto emailParts = common::split(generatedEmail, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_TRUE(std::ranges::any_of(emailHosts, [generatedEmailHost](const std::string_view& emailHost)
                                    { return generatedEmailHost == emailHost; }));
    ASSERT_TRUE(generatedUsername.find(common::toLower(firstName)) != std::string::npos);
    ASSERT_TRUE(
        std::ranges::any_of(person::englishLastNames, [generatedUsername](const std::string_view& lastName)
                            { return generatedUsername.find(common::toLower(lastName)) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateEmailWithLastName)
{
    std::vector<std::string_view> firstNames(person::englishMaleFirstNames.begin(),
                                             person::englishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::englishFemaleFirstNames.begin(), person::englishFemaleFirstNames.end());

    const std::string lastName = "Howard";

    const auto generatedEmail = email(std::nullopt, lastName);

    const auto emailParts = common::split(generatedEmail, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_TRUE(std::ranges::any_of(emailHosts, [generatedEmailHost](const std::string_view& emailHost)
                                    { return generatedEmailHost == emailHost; }));
    ASSERT_TRUE(
        std::ranges::any_of(firstNames, [generatedUsername](const std::string_view& firstName)
                            { return generatedUsername.find(common::toLower(firstName)) != std::string::npos; }));
    ASSERT_TRUE(generatedUsername.find(common::toLower(lastName)) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateEmailWithFullName)
{
    const std::string firstName = "Cindy";

    const std::string lastName = "Young";

    const auto generatedEmail = email(firstName, lastName);

    const auto emailParts = common::split(generatedEmail, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_TRUE(std::ranges::any_of(emailHosts, [generatedEmailHost](const std::string_view& emailHost)
                                    { return generatedEmailHost == emailHost; }));
    ASSERT_TRUE(generatedUsername.find(common::toLower(firstName)) != std::string::npos);
    ASSERT_TRUE(generatedUsername.find(common::toLower(lastName)) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateEmailWithSpecifiedEmailHost)
{
    std::vector<std::string_view> firstNames(person::englishMaleFirstNames.begin(),
                                             person::englishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::englishFemaleFirstNames.begin(), person::englishFemaleFirstNames.end());

    const auto emailHost = "example.com";

    const auto generatedEmail = email(std::nullopt, std::nullopt, emailHost);

    const auto emailParts = common::split(generatedEmail, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_EQ(generatedEmailHost, emailHost);
    ASSERT_TRUE(
        std::ranges::any_of(firstNames, [generatedUsername](const std::string_view& firstName)
                            { return generatedUsername.find(common::toLower(firstName)) != std::string::npos; }));
    ASSERT_TRUE(
        std::ranges::any_of(person::englishLastNames, [generatedUsername](const std::string_view& lastName)
                            { return generatedUsername.find(common::toLower(lastName)) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateExampleEmail)
{
    std::vector<std::string_view> firstNames(person::englishMaleFirstNames.begin(),
                                             person::englishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::englishFemaleFirstNames.begin(), person::englishFemaleFirstNames.end());

    const auto email = exampleEmail();

    const auto emailParts = common::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_TRUE(std::ranges::any_of(emailExampleHosts, [generatedEmailHost](const std::string_view& emailHost)
                                    { return generatedEmailHost == emailHost; }));
    ASSERT_TRUE(
        std::ranges::any_of(firstNames, [generatedUsername](const std::string_view& firstName)
                            { return generatedUsername.find(common::toLower(firstName)) != std::string::npos; }));
    ASSERT_TRUE(
        std::ranges::any_of(person::englishLastNames, [generatedUsername](const std::string_view& lastName)
                            { return generatedUsername.find(common::toLower(lastName)) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateExampleEmailWithFirstName)
{
    const std::string firstName = "Barry";

    const auto email = exampleEmail(firstName);

    const auto emailParts = common::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_TRUE(std::ranges::any_of(emailExampleHosts, [generatedEmailHost](const std::string_view& emailHost)
                                    { return generatedEmailHost == emailHost; }));
    ASSERT_TRUE(generatedUsername.find(common::toLower(firstName)) != std::string::npos);
    ASSERT_TRUE(
        std::ranges::any_of(person::englishLastNames, [generatedUsername](const std::string_view& lastName)
                            { return generatedUsername.find(common::toLower(lastName)) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateExampleEmailWithLastName)
{
    std::vector<std::string_view> firstNames(person::englishMaleFirstNames.begin(),
                                             person::englishMaleFirstNames.end());
    firstNames.insert(firstNames.end(), person::englishFemaleFirstNames.begin(), person::englishFemaleFirstNames.end());

    const std::string lastName = "Wilkinson";

    const auto email = exampleEmail(std::nullopt, lastName);

    const auto emailParts = common::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_TRUE(std::ranges::any_of(emailExampleHosts, [generatedEmailHost](const std::string_view& emailHost)
                                    { return generatedEmailHost == emailHost; }));
    ASSERT_TRUE(
        std::ranges::any_of(firstNames, [generatedUsername](const std::string_view& firstName)
                            { return generatedUsername.find(common::toLower(firstName)) != std::string::npos; }));
    ASSERT_TRUE(generatedUsername.find(common::toLower(lastName)) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateExampleEmailWithFullName)
{
    const std::string firstName = "Walter";

    const std::string lastName = "Brown";

    const auto email = exampleEmail(firstName, lastName);

    const auto emailParts = common::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_TRUE(std::ranges::any_of(emailExampleHosts, [generatedEmailHost](const std::string_view& emailHost)
                                    { return generatedEmailHost == emailHost; }));
    ASSERT_TRUE(generatedUsername.find(common::toLower(firstName)) != std::string::npos);
    ASSERT_TRUE(generatedUsername.find(common::toLower(lastName)) != std::string::npos);
}

TEST_F(InternetTest, shouldGeneratePassword)
{
    const auto generatedPassword = password();

    ASSERT_EQ(generatedPassword.size(), 16);
    ASSERT_TRUE(std::ranges::all_of(generatedPassword, [&](char passwordCharacter)
                                    { return passwordCharacters.find(passwordCharacter) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGeneratePasswordWithSpecifiedLength)
{
    const auto passwordLength = 25;

    const auto generatedPassword = password(passwordLength);

    ASSERT_EQ(generatedPassword.size(), passwordLength);
    ASSERT_TRUE(std::ranges::all_of(generatedPassword, [&](char passwordCharacter)
                                    { return passwordCharacters.find(passwordCharacter) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateEmoji)
{
    const auto generatedEmoji = emoji();

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

    ASSERT_TRUE(std::ranges::any_of(emojis, [generatedEmoji](const std::string_view& emoji)
                                    { return generatedEmoji == emoji; }));
}

TEST_F(InternetTest, shouldCheckEmoji)
{
    const auto checkEmoji = "❤️";

    ASSERT_TRUE(checkIfEmojiIsValid(checkEmoji));
}

TEST_F(InternetTest, shouldGenerateSmileyEmoji)
{
    const auto generatedEmoji = emoji(EmojiType::Smiley);

    ASSERT_TRUE(std::ranges::any_of(smileyEmojis, [generatedEmoji](const std::string_view& emoji)
                                    { return generatedEmoji == emoji; }));
}

TEST_F(InternetTest, shouldGenerateBodyEmoji)
{
    const auto generatedEmoji = emoji(EmojiType::Body);

    ASSERT_TRUE(std::ranges::any_of(bodyEmojis, [generatedEmoji](const std::string_view& emoji)
                                    { return generatedEmoji == emoji; }));
}

TEST_F(InternetTest, shouldGeneratePersonEmoji)
{
    const auto generatedEmoji = emoji(EmojiType::Person);

    ASSERT_TRUE(std::ranges::any_of(personEmojis, [generatedEmoji](const std::string_view& emoji)
                                    { return generatedEmoji == emoji; }));
}

TEST_F(InternetTest, shouldGenerateNatureEmoji)
{
    const auto generatedEmoji = emoji(EmojiType::Nature);

    ASSERT_TRUE(std::ranges::any_of(natureEmojis, [generatedEmoji](const std::string_view& emoji)
                                    { return generatedEmoji == emoji; }));
}

TEST_F(InternetTest, shouldGenerateFoodEmoji)
{
    const auto generatedEmoji = emoji(EmojiType::Food);

    ASSERT_TRUE(std::ranges::any_of(foodEmojis, [generatedEmoji](const std::string_view& emoji)
                                    { return generatedEmoji == emoji; }));
}

TEST_F(InternetTest, shouldGenerateTravelEmoji)
{
    const auto generatedEmoji = emoji(EmojiType::Travel);

    ASSERT_TRUE(std::ranges::any_of(travelEmojis, [generatedEmoji](const std::string_view& emoji)
                                    { return generatedEmoji == emoji; }));
}

TEST_F(InternetTest, shouldGenerateActivityEmoji)
{
    const auto generatedEmoji = emoji(EmojiType::Activity);

    ASSERT_TRUE(std::ranges::any_of(activityEmojis, [generatedEmoji](const std::string_view& emoji)
                                    { return generatedEmoji == emoji; }));
}

TEST_F(InternetTest, shouldGenerateObjectEmoji)
{
    const auto generatedEmoji = emoji(EmojiType::Object);

    ASSERT_TRUE(std::ranges::any_of(objectEmojis, [generatedEmoji](const std::string_view& emoji)
                                    { return generatedEmoji == emoji; }));
}

TEST_F(InternetTest, shouldGenerateSymbolEmoji)
{
    const auto generatedEmoji = emoji(EmojiType::Symbol);

    ASSERT_TRUE(std::ranges::any_of(symbolEmojis, [generatedEmoji](const std::string_view& emoji)
                                    { return generatedEmoji == emoji; }));
}

TEST_F(InternetTest, shouldGenerateFlagEmoji)
{
    const auto generatedEmoji = emoji(EmojiType::Flag);

    ASSERT_TRUE(std::ranges::any_of(flagEmojis, [generatedEmoji](const std::string_view& emoji)
                                    { return generatedEmoji == emoji; }));
}

TEST_F(InternetTest, shouldGenerateProtocol)
{
    const auto webProtocol = protocol();

    ASSERT_TRUE(std::ranges::any_of(webProtocols, [webProtocol](const std::string_view& protocol)
                                    { return webProtocol == protocol; }));
}

TEST_F(InternetTest, shouldGenerateHttpMethod)
{
    const auto generatedHttpMethod = httpMethod();

    ASSERT_TRUE(std::ranges::any_of(httpMethodNames, [generatedHttpMethod](const std::string_view& httpMethod)
                                    { return generatedHttpMethod == httpMethod; }));
}

TEST_F(InternetTest, shouldGenerateHttpStatusCode)
{
    const auto generatedHttpStatusCode = httpStatusCode();

    std::vector<unsigned> statusCodes;
    statusCodes.insert(statusCodes.end(), httpStatusInformationalCodes.begin(), httpStatusInformationalCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusSuccessCodes.begin(), httpStatusSuccessCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusRedirectionCodes.begin(), httpStatusRedirectionCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusClientErrorCodes.begin(), httpStatusClientErrorCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusServerErrorCodes.begin(), httpStatusServerErrorCodes.end());

    ASSERT_TRUE(std::ranges::any_of(statusCodes, [generatedHttpStatusCode](unsigned statusCode)
                                    { return generatedHttpStatusCode == statusCode; }));
}

TEST_F(InternetTest, shouldGenerateHttpRequestHeader)
{
    const auto generatedHttpRequestHeader = httpRequestHeader();

    ASSERT_TRUE(std::ranges::any_of(httpRequestHeaders, [generatedHttpRequestHeader](const std::string_view& httpHeader)
                                    { return generatedHttpRequestHeader == httpHeader; }));
}

TEST_F(InternetTest, shouldGenerateHttpResponseHeader)
{
    const auto generatedHttpResponseHeader = httpResponseHeader();

    ASSERT_TRUE(std::ranges::any_of(httpResponseHeaders,
                                    [generatedHttpResponseHeader](const std::string_view& httpHeader)
                                    { return generatedHttpResponseHeader == httpHeader; }));
}

TEST_F(InternetTest, shouldGenerateHttpMediaType)
{
    const auto generatedHttpMediaType = httpMediaType();

    ASSERT_TRUE(std::ranges::any_of(httpMediaTypes, [generatedHttpMediaType](const std::string_view& httpMediaType)
                                    { return generatedHttpMediaType == httpMediaType; }));
}

TEST_F(InternetTest, shouldGenerateHttpInformationalSuccessCode)
{
    const auto generatedHttpStatusCode = httpStatusCode(HttpResponseType::Informational);

    ASSERT_TRUE(std::ranges::any_of(httpStatusInformationalCodes, [generatedHttpStatusCode](unsigned statusCode)
                                    { return generatedHttpStatusCode == statusCode; }));
}

TEST_F(InternetTest, shouldGenerateHttpStatusSuccessCode)
{
    const auto generatedHttpStatusCode = httpStatusCode(HttpResponseType::Success);

    ASSERT_TRUE(std::ranges::any_of(httpStatusSuccessCodes, [generatedHttpStatusCode](unsigned statusCode)
                                    { return generatedHttpStatusCode == statusCode; }));
}

TEST_F(InternetTest, shouldGenerateHttpStatusRedirectionCode)
{
    const auto generatedHttpStatusCode = httpStatusCode(HttpResponseType::Redirection);

    ASSERT_TRUE(std::ranges::any_of(httpStatusRedirectionCodes, [generatedHttpStatusCode](unsigned statusCode)
                                    { return generatedHttpStatusCode == statusCode; }));
}

TEST_F(InternetTest, shouldGenerateHttpStatusClientErrorCode)
{
    const auto generatedHttpStatusCode = httpStatusCode(HttpResponseType::ClientError);

    ASSERT_TRUE(std::ranges::any_of(httpStatusClientErrorCodes, [generatedHttpStatusCode](unsigned statusCode)
                                    { return generatedHttpStatusCode == statusCode; }));
}

TEST_F(InternetTest, shouldGenerateHttpStatusServerErrorCode)
{
    const auto generatedHttpStatusCode = httpStatusCode(HttpResponseType::ServerError);

    ASSERT_TRUE(std::ranges::any_of(httpStatusServerErrorCodes, [generatedHttpStatusCode](unsigned statusCode)
                                    { return generatedHttpStatusCode == statusCode; }));
}

TEST_F(InternetTest, shouldGenerateIpv4WithPrivateClassAAddress)
{
    const auto generatedIpv4 = ipv4(IPv4Class::A);
    const auto addressSectors = deconstructIpv4String(generatedIpv4);

    ASSERT_EQ(addressSectors[0], classAFirstSection);
}

TEST_F(InternetTest, shouldGenerateIpv4WithPrivateClassBAddress)
{
    const auto generatedIpv4 = ipv4(IPv4Class::B);

    const auto addressSectors = deconstructIpv4String(generatedIpv4);

    ASSERT_EQ(addressSectors[0], classBFirstSection);
    ASSERT_TRUE(addressSectors[1] >= classBSecondSectionLowerBound and
                addressSectors[1] <= classBSecondSectionUpperBound);
}

TEST_F(InternetTest, shouldGenerateIpv4WithPrivateClassCAddress)
{
    const auto generatedIpv4 = ipv4(IPv4Class::C);
    const auto addressSectors = deconstructIpv4String(generatedIpv4);

    ASSERT_EQ(addressSectors[0], classCFirstSection);
    ASSERT_EQ(addressSectors[1], classCSecondSection);
}

TEST_F(InternetTest, shouldGenerateIpv4KeepingTheMaskedPart)
{
    const std::array<unsigned int, 4> sampleAddress = {192, 168, 10, 12};
    const std::array<unsigned int, 4> generationMask = {255, 128, 0, 0};

    const auto generatedAddress = deconstructIpv4String(ipv4(sampleAddress, generationMask));

    constexpr unsigned int expectedSecondSectorMaskedValue = 0x00000080;

    ASSERT_EQ(sampleAddress[0], generatedAddress[0]);
    ASSERT_TRUE((generatedAddress[1] & generationMask[1]) == expectedSecondSectorMaskedValue);
}

TEST_F(InternetTest, shouldGenerateIpv6)
{
    const auto generatedIpv6 = ipv6();

    const auto generatedIpv6Parts = common::split(generatedIpv6, ":");

    ASSERT_EQ(generatedIpv6Parts.size(), 8);

    ASSERT_TRUE(std::ranges::all_of(generatedIpv6Parts, [](const std::string& generatedIpv6Part)
                                    { return generatedIpv6Part.size() == 4; }));
    ASSERT_TRUE(std::ranges::all_of(
        generatedIpv6Parts,
        [](const std::string_view& generatedIpv6Part)
        {
            return std::ranges::all_of(generatedIpv6Part, [](char hexCharacter)
                                       { return number::hexLowerCharacters.find(hexCharacter) != std::string::npos; });
        }));
}

TEST_F(InternetTest, MacDefaultSeparator)
{
    const auto generatedMac = mac();

    ASSERT_EQ(generatedMac.size(), 17);

    for (size_t i = 0; i < generatedMac.size(); i += 3)
    {
        ASSERT_TRUE(isxdigit(generatedMac[i]));
    }

    for (size_t i = 2; i < generatedMac.size(); i += 3)
    {
        ASSERT_EQ(generatedMac[i], ':');
    }
}

TEST_F(InternetTest, MacDefaultSeparatorOverwrite)
{
    const auto generatedMac = mac(";");

    ASSERT_EQ(generatedMac.size(), 17);

    for (size_t i = 0; i < generatedMac.size(); i += 3)
    {
        ASSERT_TRUE(isxdigit(generatedMac[i]));
    }

    for (size_t i = 2; i < generatedMac.size(); i += 3)
    {
        ASSERT_EQ(generatedMac[i], ':');
    }
}

TEST_F(InternetTest, shouldGenerateDomainSuffix)
{
    const auto generatedDomainSuffix = domainSuffix();

    ASSERT_TRUE(std::ranges::any_of(domainSuffixes, [generatedDomainSuffix](const std::string_view& domainSuffix)
                                    { return generatedDomainSuffix == domainSuffix; }));
}

TEST_F(InternetTest, shouldGenerateDomainWord)
{
    const auto generatedDomainWord = domainWord();

    assertDomainWord(generatedDomainWord);
}

TEST_F(InternetTest, shouldGenerateDomainName)
{
    const auto generatedDomainName = domainName();

    const auto generatedDomainNameParts = common::split(generatedDomainName, ".");

    const auto& generatedDomainWord = generatedDomainNameParts[0];
    const auto& generatedDomainSuffix = generatedDomainNameParts[1];

    assertDomainWord(generatedDomainWord);
    ASSERT_TRUE(std::ranges::any_of(domainSuffixes, [generatedDomainSuffix](const std::string_view& domainSuffix)
                                    { return generatedDomainSuffix == domainSuffix; }));
}

TEST_F(InternetTest, shouldGenerateHttpsUrl)
{
    const auto generatedUrl = url();

    const auto generatedUrlParts = common::split(generatedUrl, "://");

    const auto& generatedProtocol = generatedUrlParts[0];
    const auto& generatedDomainName = generatedUrlParts[1];

    const auto generatedDomainNameParts = common::split(generatedDomainName, ".");

    const auto& generatedDomainWord = generatedDomainNameParts[0];
    const auto& generatedDomainSuffix = generatedDomainNameParts[1];

    assertDomainWord(generatedDomainWord);
    ASSERT_TRUE(std::ranges::any_of(domainSuffixes, [generatedDomainSuffix](const std::string_view& domainSuffix)
                                    { return generatedDomainSuffix == domainSuffix; }));
    ASSERT_EQ(generatedProtocol, "https");
}

TEST_F(InternetTest, shouldGenerateHttpUrl)
{
    const auto generatedUrl = url(WebProtocol::Http);

    const auto generatedUrlParts = common::split(generatedUrl, "://");

    const auto& generatedProtocol = generatedUrlParts[0];
    const auto& generatedDomainName = generatedUrlParts[1];

    const auto generatedDomainNameParts = common::split(generatedDomainName, ".");

    const auto& generatedDomainWord = generatedDomainNameParts[0];
    const auto& generatedDomainSuffix = generatedDomainNameParts[1];

    assertDomainWord(generatedDomainWord);
    ASSERT_TRUE(std::ranges::any_of(domainSuffixes, [generatedDomainSuffix](const std::string_view& domainSuffix)
                                    { return generatedDomainSuffix == domainSuffix; }));
    ASSERT_EQ(generatedProtocol, "http");
}

TEST_F(InternetTest, shouldGeneratePort)
{
    const auto generatedPort = port();

    ASSERT_GE(generatedPort, 0);
    ASSERT_LE(generatedPort, 65535);
}

TEST_F(InternetTest, shouldGenerateAnonymousUsername)
{
    for (int i = 0; i < 100; i++)
    {
        const std::integral auto maxLength = number::integer<unsigned>(6, 20);
        const auto generatedUsername = anonymousUsername(maxLength);

        ASSERT_EQ(generatedUsername.length(), maxLength);
    }
}

TEST_F(InternetTest, shouldGenerateAnonymousUsernameWithMinLength)
{
    const auto maxLength = 5;
    const auto generatedUsername = anonymousUsername(maxLength);

    ASSERT_EQ(generatedUsername.length(), 6);
}

TEST_F(InternetTest, shouldGenerateAnonymousUsernameWithMaxLength)
{
    const auto maxLength = 21;
    const auto generatedUsername = anonymousUsername(maxLength);

    ASSERT_EQ(generatedUsername.length(), 20);
}

TEST_F(InternetTest, shouldGenerateJwtToken)
{
    std::regex pattern(R"([A-Za-z0-9-_]+\.[A-Za-z0-9-_]+\.[A-Za-z0-9-_]+)");
    const std::map<std::string, std::string> header = {{"alg", "HS256"}, {"typ", "JWT"}};
    const std::map<std::string, std::string> payload = {{"sub", "1234567890"}, {"name", "John Doe"}, {"admin", "true"}};
    const auto refDate = std::to_string(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));

    ASSERT_TRUE(std::regex_match(getJWTToken(), pattern));
    ASSERT_TRUE(std::regex_match(getJWTToken(header), pattern));
    ASSERT_TRUE(std::regex_match(getJWTToken(header, payload), pattern));
    ASSERT_TRUE(std::regex_match(getJWTToken(header, payload, refDate), pattern));
}

TEST_F(InternetTest, shouldGenerateJWTAlgorithm)
{
    const auto generatedJWTAlgorythm = getJWTAlgorithm();

    ASSERT_TRUE(std::ranges::any_of(jwtAlgorithms, [generatedJWTAlgorythm](const std::string_view& JWTAlgorythm)
                                    { return generatedJWTAlgorythm == JWTAlgorythm; }));
}
