#include "Internet.h"

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

#include "gtest/gtest.h"

#include "data/EmailHosts.h"
#include "data/FirstNamesFemales.h"
#include "data/FirstNamesMales.h"
#include "data/LastNames.h"

using namespace ::testing;
using namespace faker;

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
    const auto firstName = "Michal";

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
    const auto firstName = "Michal";

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

    std::vector<std::string> emailParts;

    boost::split(emailParts, email, boost::is_any_of("@"));

    ASSERT_EQ(emailParts.size(), 2);

    const auto generatedUsername = emailParts[0];
    const auto generatedEmailHost = emailParts[1];

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

TEST_F(InternetTest, shouldGeneratePassword)
{
    const auto passwordLength = 18;

    const std::string passwordCharacters = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    const auto password = Internet::password(passwordLength);

    ASSERT_EQ(password.size(), passwordLength);
    ASSERT_TRUE(std::all_of(password.begin(), password.end(),
                            [passwordCharacters](char passwordCharacter)
                            { return passwordCharacters.find(passwordCharacter) != std::string::npos; }));
}
