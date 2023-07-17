#include "faker-cxx/Internet.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "data/EmailHosts.h"
#include "data/FirstNamesFemales.h"
#include "data/FirstNamesMales.h"
#include "data/LastNames.h"
#include "StringHelper.h"

using namespace ::testing;
using namespace faker;

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
}

class InternetTest : public Test
{
public:
};

TEST_F(InternetTest, shouldGenerateUsername)
{
    std::vector<std::string> firstNames{firstNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    const auto username = Internet::username();

    ASSERT_TRUE(std::any_of(firstNames.begin(), firstNames.end(),
                            [username](const std::string& firstName)
                            { return username.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                            [username](const std::string& lastName)
                            { return username.find(lastName) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateUsernameWithFirstNameProvided)
{
    const auto firstName = "Michael";

    const auto username = Internet::username(firstName);

    ASSERT_TRUE(username.find(firstName) != std::string::npos);
    ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                            [username](const std::string& lastName)
                            { return username.find(lastName) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateUsernameWithLastNameProvided)
{
    std::vector<std::string> firstNames{firstNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    const auto lastName = "Cieslar";

    const auto username = Internet::username(std::nullopt, lastName);

    ASSERT_TRUE(std::any_of(firstNames.begin(), firstNames.end(),
                            [username](const std::string& firstName)
                            { return username.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(username.find(lastName) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateUsernameWithFullNameProvided)
{
    const auto firstName = "Andrew";

    const auto lastName = "Cieslar";

    const auto username = Internet::username(firstName, lastName);

    ASSERT_TRUE(username.find(firstName) != std::string::npos);
    ASSERT_TRUE(username.find(lastName) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateEmail)
{
    std::vector<std::string> firstNames{firstNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    const auto email = Internet::email();

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_TRUE(std::any_of(emailHosts.begin(), emailHosts.end(),
                            [generatedEmailHost](const std::string& emailHost)
                            { return generatedEmailHost == emailHost; }));
    ASSERT_TRUE(std::any_of(firstNames.begin(), firstNames.end(),
                            [generatedUsername](const std::string& firstName)
                            { return generatedUsername.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                            [generatedUsername](const std::string& lastName)
                            { return generatedUsername.find(lastName) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateEmailWithFirstName)
{
    const auto firstName = "Tom";

    const auto email = Internet::email(firstName);

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_TRUE(std::any_of(emailHosts.begin(), emailHosts.end(),
                            [generatedEmailHost](const std::string& emailHost)
                            { return generatedEmailHost == emailHost; }));
    ASSERT_TRUE(generatedUsername.find(firstName) != std::string::npos);
    ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                            [generatedUsername](const std::string& lastName)
                            { return generatedUsername.find(lastName) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateEmailWithLastName)
{
    std::vector<std::string> firstNames{firstNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    const auto lastName = "Howard";

    const auto email = Internet::email(std::nullopt, lastName);

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_TRUE(std::any_of(emailHosts.begin(), emailHosts.end(),
                            [generatedEmailHost](const std::string& emailHost)
                            { return generatedEmailHost == emailHost; }));
    ASSERT_TRUE(std::any_of(firstNames.begin(), firstNames.end(),
                            [generatedUsername](const std::string& firstName)
                            { return generatedUsername.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(generatedUsername.find(lastName) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateEmailWithFullName)
{
    std::vector<std::string> firstNames{firstNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    const auto firstName = "Cindy";

    const auto lastName = "Young";

    const auto email = Internet::email(firstName, lastName);

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_TRUE(std::any_of(emailHosts.begin(), emailHosts.end(),
                            [generatedEmailHost](const std::string& emailHost)
                            { return generatedEmailHost == emailHost; }));
    ASSERT_TRUE(generatedUsername.find(firstName) != std::string::npos);
    ASSERT_TRUE(generatedUsername.find(lastName) != std::string::npos);
}

TEST_F(InternetTest, shouldGenerateEmailWithSpecifiedEmailHost)
{
    std::vector<std::string> firstNames{firstNamesMales};

    firstNames.insert(firstNames.end(), firstNamesFemales.begin(), firstNamesFemales.end());

    const auto emailHost = "example.com";

    const auto email = Internet::email(std::nullopt, std::nullopt, emailHost);

    const auto emailParts = StringHelper::split(email, "@");

    ASSERT_EQ(emailParts.size(), 2);

    const auto& generatedUsername = emailParts[0];
    const auto& generatedEmailHost = emailParts[1];

    ASSERT_EQ(generatedEmailHost, emailHost);
    ASSERT_TRUE(std::any_of(firstNames.begin(), firstNames.end(),
                            [generatedUsername](const std::string& firstName)
                            { return generatedUsername.find(firstName) != std::string::npos; }));
    ASSERT_TRUE(std::any_of(lastNames.begin(), lastNames.end(),
                            [generatedUsername](const std::string& lastName)
                            { return generatedUsername.find(lastName) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGeneratePassword)
{
    const std::string passwordCharacters = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    const auto password = Internet::password();

    ASSERT_EQ(password.size(), 15);
    ASSERT_TRUE(std::all_of(password.begin(), password.end(),
                            [passwordCharacters](char passwordCharacter)
                            { return passwordCharacters.find(passwordCharacter) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGeneratePasswordWithSpecifiedLength)
{
    const auto passwordLength = 25;

    const std::string passwordCharacters = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    const auto password = Internet::password(passwordLength);

    ASSERT_EQ(password.size(), passwordLength);
    ASSERT_TRUE(std::all_of(password.begin(), password.end(),
                            [passwordCharacters](char passwordCharacter)
                            { return passwordCharacters.find(passwordCharacter) != std::string::npos; }));
}

TEST_F(InternetTest, shouldGenerateImageUrl)
{
    const auto width = 800;
    const auto height = 600;

    const auto imageUrl = Internet::imageUrl(width, height);

    ASSERT_EQ(imageUrl, "https://source.unsplash.com/800x600");
}

TEST_F(InternetTest, shouldGenerateGithubAvatarUrl)
{
    const auto githubAvatarUrl = Internet::githubAvatarUrl();

    const std::string expectedGithubAvatarPrefix = "https://avatars.githubusercontent.com/u/";

    const auto userNumber = std::stoi(githubAvatarUrl.substr(expectedGithubAvatarPrefix.size()));

    ASSERT_TRUE(githubAvatarUrl.starts_with(expectedGithubAvatarPrefix));
    ASSERT_TRUE(userNumber >= 0 && userNumber <= 100000000);
}

TEST_F(InternetTest, shouldGenerateProtocol)
{
    const auto webProtocol = Internet::protocol();

    ASSERT_TRUE(std::any_of(webProtocols.begin(), webProtocols.end(),
                            [webProtocol](const std::string& protocol) { return webProtocol == protocol; }));
}

TEST_F(InternetTest, shouldGenerateHttpMethod)
{
    const auto generatedHttpMethod = Internet::httpMethod();

    ASSERT_TRUE(std::any_of(httpMethodNames.begin(), httpMethodNames.end(),
                            [generatedHttpMethod](const std::string& httpMethod) { return generatedHttpMethod == httpMethod; }));
}

TEST_F(InternetTest, shouldGenerateHttpStatusCode)
{
    const auto generatedHttpStatusCode = Internet::httpStatusCode();

    std::vector<unsigned> statusCodes;
    statusCodes.insert(statusCodes.end(), httpStatusInformationalCodes.begin(), httpStatusInformationalCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusSuccessCodes.begin(), httpStatusSuccessCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusRedirectionCodes.begin(), httpStatusRedirectionCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusClientErrorCodes.begin(), httpStatusClientErrorCodes.end());
    statusCodes.insert(statusCodes.end(), httpStatusServerErrorCodes.begin(), httpStatusServerErrorCodes.end());

    ASSERT_TRUE(std::any_of(statusCodes.begin(), statusCodes.end(),
                            [generatedHttpStatusCode](unsigned statusCode) { return generatedHttpStatusCode == statusCode; }));
}

TEST_F(InternetTest, shouldGenerateHttpInformationalSuccessCode)
{
    const auto generatedHttpStatusCode = Internet::httpStatusCode(HttpResponseType::Informational);

    ASSERT_TRUE(std::any_of(httpStatusInformationalCodes.begin(), httpStatusInformationalCodes.end(),
                            [generatedHttpStatusCode](unsigned statusCode) { return generatedHttpStatusCode == statusCode; }));
}

TEST_F(InternetTest, shouldGenerateHttpStatusSuccessCode)
{
    const auto generatedHttpStatusCode = Internet::httpStatusCode(HttpResponseType::Success);

    ASSERT_TRUE(std::any_of(httpStatusSuccessCodes.begin(), httpStatusSuccessCodes.end(),
                            [generatedHttpStatusCode](unsigned statusCode) { return generatedHttpStatusCode == statusCode; }));
}

TEST_F(InternetTest, shouldGenerateHttpStatusRedirectionCode)
{
    const auto generatedHttpStatusCode = Internet::httpStatusCode(HttpResponseType::Redirection);

    ASSERT_TRUE(std::any_of(httpStatusRedirectionCodes.begin(), httpStatusRedirectionCodes.end(),
                            [generatedHttpStatusCode](unsigned statusCode) { return generatedHttpStatusCode == statusCode; }));
}

TEST_F(InternetTest, shouldGenerateHttpStatusClientErrorCode)
{
    const auto generatedHttpStatusCode = Internet::httpStatusCode(HttpResponseType::ClientError);

    ASSERT_TRUE(std::any_of(httpStatusClientErrorCodes.begin(), httpStatusClientErrorCodes.end(),
                            [generatedHttpStatusCode](unsigned statusCode) { return generatedHttpStatusCode == statusCode; }));
}

TEST_F(InternetTest, shouldGenerateHttpStatusServerErrorCode)
{
    const auto generatedHttpStatusCode = Internet::httpStatusCode(HttpResponseType::ServerError);

    ASSERT_TRUE(std::any_of(httpStatusServerErrorCodes.begin(), httpStatusServerErrorCodes.end(),
                            [generatedHttpStatusCode](unsigned statusCode) { return generatedHttpStatusCode == statusCode; }));
}
