#include "../test_helpers.h"
#include <algorithm>
#include <array>
#include <charconv>
#include <common/string_helper.h>
#include <faker/internet.h>
#include <modules/internet_data.h>
#include <modules/person_data.h>
#include <modules/string_data.h>
#include <modules/word_data.h>
#include <optional>

using namespace ::testing;
using namespace faker;

namespace {
const std::string passwordCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456"
                                       "789~`!@#$%^&*()_-+={[}]|:;\"'<,>.?/";
const std::vector<std::string> webProtocols { "http", "https" };
const std::vector<std::string> httpMethodNames { "GET", "POST", "DELETE", "PATCH", "PUT" };
const std::vector<unsigned> httpStatusInformationalCodes { 100, 101, 102, 103 };
const std::vector<unsigned> httpStatusSuccessCodes { 200, 201, 202, 203, 204, 205, 206, 207, 208,
    226 };
const std::vector<unsigned> httpStatusRedirectionCodes { 300, 301, 302, 303, 304, 305, 306, 307,
    308 };
const std::vector<unsigned> httpStatusClientErrorCodes { 400, 401, 402, 403, 404, 405, 406, 407,
    408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 421, 422, 423, 424, 425, 426, 428, 429,
    431, 451 };
const std::vector<unsigned> httpStatusServerErrorCodes { 500, 501, 502, 503, 504, 505, 506, 507,
    508, 510, 511 };
constexpr unsigned int classAFirstSection = 10u;
constexpr unsigned int classBFirstSection = 172u;
constexpr unsigned int classBSecondSectionLowerBound = 16;
constexpr unsigned int classBSecondSectionUpperBound = 31;
constexpr unsigned int classCFirstSection = 192u;
constexpr unsigned int classCSecondSection = 168u;

std::array<unsigned int, 4> deconstructIpv4String(const std::string& ipv4)
{
    std::array<unsigned int, 4> result;

    std::istringstream ss(ipv4);

    constexpr char separator = '.';

    std::for_each(std::begin(result), std::end(result), [&ss](unsigned int& c) {
        std::string token;

        std::getline(ss, token, separator);

        std::from_chars(token.data(), token.data() + token.size(), c);
    });

    return result;
}
}

class InternetTest : public Test {
public:
    InternetTest()
    {
        std::sort(sortedAdjectivesDescendingBySize.begin(), sortedAdjectivesDescendingBySize.end(),
            [](const auto& first, const auto& second) { return first.size() > second.size(); });
    }

    void assertDomainWord(const std::string& domainWord)
    {
        std::optional<std::string> foundAdjective = std::nullopt;

        for (const auto& adjective : sortedAdjectivesDescendingBySize) {
            if (domainWord.find(adjective) == 0) {
                foundAdjective = adjective;
                break;
            }
        }

        ASSERT_TRUE(foundAdjective);

        ASSERT_EQ(domainWord[foundAdjective->size()], '-');

        const auto generatedNoun = domainWord.substr(foundAdjective->size() + 1);

        ASSERT_TRUE(faker::testing::any_of(
            word::data::nouns, [generatedNoun](const std::string_view& noun) {
                return StringHelper::compareNoCase(generatedNoun, noun);
            }));
    }

    std::vector<std::string_view> sortedAdjectivesDescendingBySize { word::data::adjectives.begin(),
        word::data::adjectives.end() };
};

TEST_F(InternetTest, shouldGenerateUsername)
{
    std::vector<std::string> firstNames { englishMalesFirstNames };

    firstNames.insert(
        firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    const auto username = internet::username();

    ASSERT_TRUE(faker::testing::any_of(firstNames, [username](const std::string& firstName) {
        return username.find(firstName) != std::string::npos;
    }));
    ASSERT_TRUE(faker::testing::any_of(englishLastNames, [username](const std::string& lastName) {
        return username.find(lastName) != std::string::npos;
    }));
}

TEST_F(InternetTest, shouldGenerateUsernameWithFirstNameProvided)
{
    const auto firstName = "Michael";

    const auto username = internet::username(firstName);

    ASSERT_TRUE(username.find(firstName) != std::string::npos);
    ASSERT_TRUE(faker::testing::any_of(englishLastNames, [username](const std::string& lastName) {
        return username.find(lastName) != std::string::npos;
    }));
}

TEST_F(InternetTest, shouldGenerateUsernameWithLastNameProvided)
{
    std::vector<std::string> firstNames { englishMalesFirstNames };

    firstNames.insert(
        firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    const auto lastName = "Cieslar";

    const auto username = internet::username(std::nullopt, lastName);

    ASSERT_TRUE(faker::testing::any_of(firstNames, [username](const std::string& firstName) {
        return username.find(firstName) != std::string::npos;
    }));
    ASSERT_TRUE(username.find(lastName) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateUsernameWithFullNameProvided)
{
    const auto firstName = "Andrew";

    const auto lastName = "Cieslar";

    const auto username = internet::username(firstName, lastName);

    ASSERT_TRUE(username.find(firstName) != std::string::npos);
    ASSERT_TRUE(username.find(lastName) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateInternationalUsernames)
{
    std::vector<std::string> romanianFirstNames { romanianMalesFirstNames };

    romanianFirstNames.insert(romanianFirstNames.end(), romanianFemalesFirstNames.begin(),
        romanianFemalesFirstNames.end());

    const auto username = internet::username(std::nullopt, std::nullopt, Country::Romania);

    ASSERT_TRUE(faker::testing::any_of(
        romanianFirstNames, [username](const std::string& romanianFirstName) {
            return username.find(romanianFirstName) != std::string::npos;
        }));

    ASSERT_TRUE(
        faker::testing::any_of(romanianLastNames, [username](const std::string& romanianLastName) {
            return username.find(romanianLastName) != std::string::npos;
        }));
}

TEST_F(InternetTest, shouldGenerateEmail)
{
    std::vector<std::string> firstNames { englishMalesFirstNames };

    firstNames.insert(
        firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    const auto email = internet::email();

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    FAKER_EXPECT_CONTAINS(emailHosts, generatedEmailHost);
    ASSERT_TRUE(faker::testing::any_of(firstNames, [generatedUsername](const auto& firstName) {
        return generatedUsername.find(firstName) != std::string::npos;
    }));
    ASSERT_TRUE(faker::testing::any_of(englishLastNames, [generatedUsername](const auto& lastName) {
        return generatedUsername.find(lastName) != std::string::npos;
    }));
}

TEST_F(InternetTest, shouldGenerateEmailWithFirstName)
{
    const auto firstName = "Tom";

    const auto email = internet::email(firstName);

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    FAKER_EXPECT_CONTAINS(emailHosts, generatedEmailHost);
    ASSERT_TRUE(generatedUsername.find(firstName) != std::string::npos);
    ASSERT_TRUE(faker::testing::any_of(englishLastNames, [generatedUsername](const auto& lastName) {
        return generatedUsername.find(lastName) != std::string::npos;
    }));
}

TEST_F(InternetTest, shouldGenerateEmailWithLastName)
{
    std::vector<std::string> firstNames { englishMalesFirstNames };

    firstNames.insert(
        firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    const auto lastName = "Howard";

    const auto email = internet::email(std::nullopt, lastName);

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    FAKER_EXPECT_CONTAINS(emailHosts, generatedEmailHost);
    ASSERT_TRUE(
        faker::testing::any_of(firstNames, [generatedUsername](const std::string& firstName) {
            return generatedUsername.find(firstName) != std::string::npos;
        }));
    ASSERT_TRUE(generatedUsername.find(lastName) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateEmailWithFullName)
{
    std::vector<std::string> firstNames { englishMalesFirstNames };

    firstNames.insert(
        firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    const auto firstName = "Cindy";

    const auto lastName = "Young";

    const auto email = internet::email(firstName, lastName);

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    FAKER_EXPECT_CONTAINS(emailHosts, generatedEmailHost);
    ASSERT_TRUE(generatedUsername.find(firstName) != std::string::npos);
    ASSERT_TRUE(generatedUsername.find(lastName) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateEmailWithSpecifiedEmailHost)
{
    std::vector<std::string> firstNames { englishMalesFirstNames };

    firstNames.insert(
        firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    const auto emailHost = "example.com";

    const auto email = internet::email(std::nullopt, std::nullopt, emailHost);

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_EQ(generatedEmailHost, emailHost);
    ASSERT_TRUE(faker::testing::any_of(firstNames, [generatedUsername](const auto& firstName) {
        return generatedUsername.find(firstName) != std::string::npos;
    }));
    ASSERT_TRUE(
        faker::testing::any_of(englishLastNames, [generatedUsername](const std::string& lastName) {
            return generatedUsername.find(lastName) != std::string::npos;
        }));
}

TEST_F(InternetTest, shouldGenerateExampleEmail)
{
    std::vector<std::string> firstNames { englishMalesFirstNames };

    firstNames.insert(
        firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    const auto email = internet::exampleEmail();

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    FAKER_EXPECT_CONTAINS(emailExampleHosts, generatedEmailHost);
    ASSERT_TRUE(
        faker::testing::any_of(firstNames, [generatedUsername](const std::string& firstName) {
            return generatedUsername.find(firstName) != std::string::npos;
        }));
    ASSERT_TRUE(
        faker::testing::any_of(englishLastNames, [generatedUsername](const std::string& lastName) {
            return generatedUsername.find(lastName) != std::string::npos;
        }));
}

TEST_F(InternetTest, shouldGenerateExampleEmailWithFirstName)
{
    const auto firstName = "Barry";

    const auto email = internet::exampleEmail(firstName);

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    FAKER_EXPECT_CONTAINS(emailExampleHosts, generatedEmailHost);
    ASSERT_TRUE(generatedUsername.find(firstName) != std::string::npos);
    ASSERT_TRUE(
        faker::testing::any_of(englishLastNames, [generatedUsername](const std::string& lastName) {
            return generatedUsername.find(lastName) != std::string::npos;
        }));
}

TEST_F(InternetTest, shouldGenerateExampleEmailWithLastName)
{
    std::vector<std::string> firstNames { englishMalesFirstNames };

    firstNames.insert(
        firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    const auto lastName = "Wilkinson";

    const auto email = internet::exampleEmail(std::nullopt, lastName);

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    FAKER_EXPECT_CONTAINS(emailExampleHosts, generatedEmailHost);
    ASSERT_TRUE(
        faker::testing::any_of(firstNames, [generatedUsername](const std::string& firstName) {
            return generatedUsername.find(firstName) != std::string::npos;
        }));
    ASSERT_TRUE(generatedUsername.find(lastName) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateExampleEmailWithFullName)
{
    std::vector<std::string> firstNames { englishMalesFirstNames };

    firstNames.insert(
        firstNames.end(), englishFemalesFirstNames.begin(), englishFemalesFirstNames.end());

    const auto firstName = "Walter";

    const auto lastName = "Brown";

    const auto email = internet::exampleEmail(firstName, lastName);

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    FAKER_EXPECT_CONTAINS(emailExampleHosts, generatedEmailHost);
    ASSERT_TRUE(generatedUsername.find(firstName) != std::string::npos);
    ASSERT_TRUE(generatedUsername.find(lastName) != std::string::npos);
}

TEST_F(InternetTest, shouldGeneratePassword)
{
    const auto password = internet::password();

    ASSERT_EQ(password.size(), 15);
    ASSERT_TRUE(faker::testing::all_of(password, [&](char passwordCharacter) {
        return passwordCharacters.find(passwordCharacter) != std::string::npos;
    }));
}

TEST_F(InternetTest, shouldGeneratePasswordWithSpecifiedLength)
{
    const auto passwordLength = 25;

    const auto password = internet::password(passwordLength);

    ASSERT_EQ(password.size(), passwordLength);
    ASSERT_TRUE(faker::testing::all_of(password, [&](char passwordCharacter) {
        return passwordCharacters.find(passwordCharacter) != std::string::npos;
    }));
}

TEST_F(InternetTest, shouldGenerateEmoji)
{
    const auto generatedEmoji = internet::emoji();

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

    FAKER_EXPECT_CONTAINS(emojis, generatedEmoji);
}

TEST_F(InternetTest, shouldGenerateSmileyEmoji)
{
    const auto generatedEmoji = internet::emoji(EmojiType::Smiley);

    FAKER_EXPECT_CONTAINS(smileyEmojis, generatedEmoji);
}

TEST_F(InternetTest, shouldGenerateBodyEmoji)
{
    const auto generatedEmoji = internet::emoji(EmojiType::Body);

    FAKER_EXPECT_CONTAINS(bodyEmojis, generatedEmoji);
}

TEST_F(InternetTest, shouldGeneratePersonEmoji)
{
    const auto generatedEmoji = internet::emoji(EmojiType::Person);

    FAKER_EXPECT_CONTAINS(personEmojis, generatedEmoji);
}

TEST_F(InternetTest, shouldGenerateNatureEmoji)
{
    const auto generatedEmoji = internet::emoji(EmojiType::Nature);

    FAKER_EXPECT_CONTAINS(natureEmojis, generatedEmoji);
}

TEST_F(InternetTest, shouldGenerateFoodEmoji)
{
    const auto generatedEmoji = internet::emoji(EmojiType::Food);

    FAKER_EXPECT_CONTAINS(foodEmojis, generatedEmoji);
}

TEST_F(InternetTest, shouldGenerateTravelEmoji)
{
    const auto generatedEmoji = internet::emoji(EmojiType::Travel);

    FAKER_EXPECT_CONTAINS(travelEmojis, generatedEmoji);
}

TEST_F(InternetTest, shouldGenerateActivityEmoji)
{
    const auto generatedEmoji = internet::emoji(EmojiType::Activity);

    FAKER_EXPECT_CONTAINS(activityEmojis, generatedEmoji);
}

TEST_F(InternetTest, shouldGenerateObjectEmoji)
{
    const auto generatedEmoji = internet::emoji(EmojiType::Object);

    FAKER_EXPECT_CONTAINS(objectEmojis, generatedEmoji);
}

TEST_F(InternetTest, shouldGenerateSymbolEmoji)
{
    const auto generatedEmoji = internet::emoji(EmojiType::Symbol);

    FAKER_EXPECT_CONTAINS(symbolEmojis, generatedEmoji);
}

TEST_F(InternetTest, shouldGenerateFlagEmoji)
{
    const auto generatedEmoji = internet::emoji(EmojiType::Flag);

    FAKER_EXPECT_CONTAINS(flagEmojis, generatedEmoji);
}

TEST_F(InternetTest, shouldGenerateProtocol)
{
    const auto webProtocol = internet::protocol();

    FAKER_EXPECT_CONTAINS(webProtocols, webProtocol);
}

TEST_F(InternetTest, shouldGenerateHttpMethod)
{
    const auto generatedHttpMethod = internet::httpMethod();

    FAKER_EXPECT_CONTAINS(httpMethodNames, generatedHttpMethod);
}

TEST_F(InternetTest, shouldGenerateHttpStatusCode)
{
    const auto generatedHttpStatusCode = internet::httpStatusCode();

    std::vector<unsigned> statusCodes;
    statusCodes.insert(statusCodes.end(), httpStatusInformationalCodes.begin(),
        httpStatusInformationalCodes.end());
    statusCodes.insert(
        statusCodes.end(), httpStatusSuccessCodes.begin(), httpStatusSuccessCodes.end());
    statusCodes.insert(
        statusCodes.end(), httpStatusRedirectionCodes.begin(), httpStatusRedirectionCodes.end());
    statusCodes.insert(
        statusCodes.end(), httpStatusClientErrorCodes.begin(), httpStatusClientErrorCodes.end());
    statusCodes.insert(
        statusCodes.end(), httpStatusServerErrorCodes.begin(), httpStatusServerErrorCodes.end());

    FAKER_EXPECT_CONTAINS(statusCodes, generatedHttpStatusCode);
}

TEST_F(InternetTest, shouldGenerateHttpRequestHeader)
{
    const auto generatedHttpRequestHeader = internet::httpRequestHeader();

    FAKER_EXPECT_CONTAINS(httpRequestHeaders, generatedHttpRequestHeader);
}

TEST_F(InternetTest, shouldGenerateHttpResponseHeader)
{
    const auto generatedHttpResponseHeader = internet::httpResponseHeader();

    FAKER_EXPECT_CONTAINS(httpResponseHeaders, generatedHttpResponseHeader);
}

TEST_F(InternetTest, shouldGenerateHttpMediaType)
{
    const auto generatedHttpMediaType = internet::httpMediaType();

    FAKER_EXPECT_CONTAINS(httpMediaTypes, generatedHttpMediaType);
}

TEST_F(InternetTest, shouldGenerateHttpInformationalSuccessCode)
{
    const auto generatedHttpStatusCode
        = internet::httpStatusCode(internet::HttpResponseType::Informational);

    FAKER_EXPECT_CONTAINS(httpStatusInformationalCodes, generatedHttpStatusCode);
}

TEST_F(InternetTest, shouldGenerateHttpStatusSuccessCode)
{
    const auto generatedHttpStatusCode
        = internet::httpStatusCode(internet::HttpResponseType::Success);

    FAKER_EXPECT_CONTAINS(httpStatusSuccessCodes, generatedHttpStatusCode);
}

TEST_F(InternetTest, shouldGenerateHttpStatusRedirectionCode)
{
    const auto generatedHttpStatusCode
        = internet::httpStatusCode(internet::HttpResponseType::Redirection);

    FAKER_EXPECT_CONTAINS(httpStatusRedirectionCodes, generatedHttpStatusCode);
}

TEST_F(InternetTest, shouldGenerateHttpStatusClientErrorCode)
{
    const auto generatedHttpStatusCode
        = internet::httpStatusCode(internet::HttpResponseType::ClientError);

    FAKER_EXPECT_CONTAINS(httpStatusClientErrorCodes, generatedHttpStatusCode);
}

TEST_F(InternetTest, shouldGenerateHttpStatusServerErrorCode)
{
    const auto generatedHttpStatusCode
        = internet::httpStatusCode(internet::HttpResponseType::ServerError);

    FAKER_EXPECT_CONTAINS(httpStatusServerErrorCodes, generatedHttpStatusCode);
}

TEST_F(InternetTest, shouldGenerateIpv4WithPrivateClassAAddress)
{
    const auto generatedIpv4 = internet::ipv4(internet::IPv4Class::A);
    const auto addressSectors = deconstructIpv4String(generatedIpv4);

    ASSERT_EQ(addressSectors[0], classAFirstSection);
}

TEST_F(InternetTest, shouldGenerateIpv4WithPrivateClassBAddress)
{
    const auto generatedIpv4 = internet::ipv4(internet::IPv4Class::B);
    const auto addressSectors = deconstructIpv4String(generatedIpv4);

    ASSERT_EQ(addressSectors[0], classBFirstSection);
    ASSERT_TRUE(addressSectors[1] >= classBSecondSectionLowerBound
        and addressSectors[1] <= classBSecondSectionUpperBound);
}

TEST_F(InternetTest, shouldGenerateIpv4WithPrivateClassCAddress)
{
    const auto generatedIpv4 = internet::ipv4(internet::IPv4Class::C);
    const auto addressSectors = deconstructIpv4String(generatedIpv4);

    ASSERT_EQ(addressSectors[0], classCFirstSection);
    ASSERT_EQ(addressSectors[1], classCSecondSection);
}

TEST_F(InternetTest, shouldGenerateIpv4KeepingTheMaskedPart)
{
    const std::array<unsigned int, 4> sampleAddress = { 192, 168, 10, 12 };
    const std::array<unsigned int, 4> generationMask = { 255, 128, 0, 0 };

    const auto generatedAddress
        = deconstructIpv4String(internet::ipv4(sampleAddress, generationMask));

    constexpr unsigned int expectedSecondSectorMaskedValue = 0x00000080;

    ASSERT_EQ(sampleAddress[0], generatedAddress[0]);
    ASSERT_TRUE((generatedAddress[1] & generationMask[1]) == expectedSecondSectorMaskedValue);
}

TEST_F(InternetTest, shouldGenerateIpv6)
{
    const auto generatedIpv6 = internet::ipv6();

    const auto generatedIpv6Parts = StringHelper::split(generatedIpv6, ":");

    ASSERT_EQ(generatedIpv6Parts.size(), 8);

    ASSERT_TRUE(faker::testing::all_of(generatedIpv6Parts,
        [](const std::string& generatedIpv6Part) { return generatedIpv6Part.size() == 4; }));
    ASSERT_TRUE(
        faker::testing::all_of(generatedIpv6Parts, [](const std::string& generatedIpv6Part) {
            return faker::testing::all_of(generatedIpv6Part, [](char hexCharacter) {
                return hexLowerCharacters.find(hexCharacter) != std::string::npos;
            });
        }));
}

TEST_F(InternetTest, MacDefaultSeparator)
{
    const auto mac = internet::mac();

    ASSERT_EQ(mac.size(), 17);

    for (size_t i = 0; i < mac.size(); i += 3) {
        ASSERT_TRUE(isxdigit(mac[i]));
    }

    for (size_t i = 2; i < mac.size(); i += 3) {
        ASSERT_EQ(mac[i], ':');
    }
}

TEST_F(InternetTest, shouldGenerateDomainSuffix)
{
    const auto generatedDomainSuffix = internet::domainSuffix();

    FAKER_EXPECT_CONTAINS(domainSuffixes, generatedDomainSuffix);
}

TEST_F(InternetTest, shouldGenerateDomainWord)
{
    const auto generatedDomainWord = internet::domainWord();

    assertDomainWord(generatedDomainWord);
}

TEST_F(InternetTest, shouldGenerateDomainName)
{
    const auto generatedDomainName = internet::domainName();

    const auto generatedDomainNameParts = StringHelper::split(generatedDomainName, ".");

    const auto& generatedDomainWord = generatedDomainNameParts[0];
    const auto& generatedDomainSuffix = generatedDomainNameParts[1];

    assertDomainWord(generatedDomainWord);
    FAKER_EXPECT_CONTAINS(domainSuffixes, generatedDomainSuffix);
}

TEST_F(InternetTest, shouldGenerateHttpsUrl)
{
    const auto generatedUrl = internet::url();

    const auto generatedUrlParts = StringHelper::split(generatedUrl, "://");

    const auto& generatedProtocol = generatedUrlParts[0];
    const auto& generatedDomainName = generatedUrlParts[1];

    const auto generatedDomainNameParts = StringHelper::split(generatedDomainName, ".");

    const auto& generatedDomainWord = generatedDomainNameParts[0];
    const auto& generatedDomainSuffix = generatedDomainNameParts[1];

    assertDomainWord(generatedDomainWord);
    FAKER_EXPECT_CONTAINS(domainSuffixes, generatedDomainSuffix);
    ASSERT_EQ(generatedProtocol, "https");
}

TEST_F(InternetTest, shouldGenerateHttpUrl)
{
    const auto generatedUrl = internet::url(internet::WebProtocol::Http);

    const auto generatedUrlParts = StringHelper::split(generatedUrl, "://");

    const auto& generatedProtocol = generatedUrlParts[0];
    const auto& generatedDomainName = generatedUrlParts[1];

    const auto generatedDomainNameParts = StringHelper::split(generatedDomainName, ".");

    const auto& generatedDomainWord = generatedDomainNameParts[0];
    const auto& generatedDomainSuffix = generatedDomainNameParts[1];

    assertDomainWord(generatedDomainWord);
    FAKER_EXPECT_CONTAINS(domainSuffixes, generatedDomainSuffix);
    ASSERT_EQ(generatedProtocol, "http");
}

TEST_F(InternetTest, shouldGeneratePort)
{
    const auto generatedPort = internet::port();

    ASSERT_GE(generatedPort, 0);
    ASSERT_LE(generatedPort, 65535);
}
