#include "ColumnTypeValueProvider.h"

#include "../src/common/FormatHelper.h"

#include "faker-cxx/Crypto.h"
#include "faker-cxx/Date.h"
#include "faker-cxx/Image.h"
#include "faker-cxx/Internet.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Lorem.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/Person.h"
#include "faker-cxx/Phone.h"
#include "faker-cxx/String.h"

namespace faker
{

std::string ColumnTypeValueProvider::getValue(std::string columnName, faker::Country country, faker::Sex sex)
{
    const auto iter1 = faker::columnTypeGeneratorMap.find(columnName);
    if (iter1 == faker::columnTypeGeneratorMap.end()) {
        throw;
    }
    faker::DataGeneratorType generator = iter1->second;

    switch (generator)
    {
        case faker::DataGeneratorType::AlphaNumeric:
            return getAlphaNumericValue();
        case faker::DataGeneratorType::Integer:
            return getInteger();
        case faker::DataGeneratorType::Boolean:
            return getBoolean();
        case faker::DataGeneratorType::DateTime:
            return getDateTime();
        case faker::DataGeneratorType::DateOfBirth:
            return getDateOfBirth();
        case faker::DataGeneratorType::Crypto:
            return getCryptoString();
        case faker::DataGeneratorType::Email:
            return getEmail();
        case faker::DataGeneratorType::Avatar:
            return getAvatar();
        case faker::DataGeneratorType::PersonFirstName:
            return getFirstName(country, sex);
        case faker::DataGeneratorType::PersonFullName:
            return getFullName(country, sex);
        case faker::DataGeneratorType::PersonLastName:
            return getLastName(country, sex);
        case faker::DataGeneratorType::PersonTitle:
            return getPersonTitle(sex);
        case faker::DataGeneratorType::Sentence:
            return getSentence();
        case faker::DataGeneratorType::UserName:
            return getUsername();
        case faker::DataGeneratorType::PhoneNumber:
            return getPhoneNumber();
        case faker::DataGeneratorType::Token:
        default:
            return getGenericStringValue();
    }
}

std::string ColumnTypeValueProvider::getPhoneNumber()
{
    return FormatHelper::format("'{}'", Phone::number());
}

std::string ColumnTypeValueProvider::getUsername()
{
    unsigned int length = Number::integer<unsigned int>(20);
    return FormatHelper::format("'{}'", Internet::anonymousUsername(length));
}

std::string ColumnTypeValueProvider::getSentence()
{
    return FormatHelper::format("'{}'", Lorem::sentence());
}

std::string ColumnTypeValueProvider::getPersonTitle(faker::Sex sex)
{
    return FormatHelper::format("'{}'", Person::prefix(sex));
}

std::string ColumnTypeValueProvider::getFullName(faker::Country country, faker::Sex sex)
{
    return FormatHelper::format("'{}'", Person::fullName(country, sex));
}

std::string ColumnTypeValueProvider::getLastName(faker::Country country, faker::Sex sex)
{
    return FormatHelper::format("'{}'", Person::lastName(country, sex));
}

std::string ColumnTypeValueProvider::getFirstName(faker::Country country, faker::Sex sex)
{
    return FormatHelper::format("'{}'", Person::firstName(country, sex));
}

std::string ColumnTypeValueProvider::getAvatar()
{
    return FormatHelper::format("'{}'", Image::githubAvatarUrl());
}

std::string ColumnTypeValueProvider::getCryptoString()
{
    return FormatHelper::format("'{}'", Crypto::sha256());
}

std::string ColumnTypeValueProvider::getEmail()
{
    return FormatHelper::format("'{}'", Internet::email());
}

std::string ColumnTypeValueProvider::getAlphaNumericValue()
{
    unsigned int length = static_cast<unsigned int>(Number::integer(5, 10));
    return FormatHelper::format("'{}'", String::alphanumeric(length));
}

std::string ColumnTypeValueProvider::getInteger()
{
    std::stringstream stringstream;
    stringstream << Number::integer(ColumnTypeValueProvider::MAX_INT_VALUE);
    return stringstream.str();
}

std::string ColumnTypeValueProvider::getBoolean()
{
    static std::vector<std::string> booleans = { "true", "false" };
    return Helper::arrayElement<std::string>(booleans);
}

std::string ColumnTypeValueProvider::getDateTime()
{
    int random = Number::integer(1, 4);
    std::string date;
    switch (random)
    {
        case 1:
            date = Date::futureDate();
            break;
        case 2:
            date = Date::pastDate();
            break;
        case 3:
            date = Date::recentDate();
            break;
        case 4:
        default:
            date = Date::soonDate();
            break;
    }

    return FormatHelper::format("'{}'", date);
}

std::string ColumnTypeValueProvider::getDateOfBirth()
{
    return FormatHelper::format("'{}'", Date::birthdateByAge());
}

std::string ColumnTypeValueProvider::getGenericStringValue()
{
    return FormatHelper::format("'{}'", Lorem::sentence());
}

}