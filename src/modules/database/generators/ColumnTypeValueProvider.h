#pragma once

#include "faker-cxx/Database.h"
#include "faker-cxx/types/Country.h"
#include "faker-cxx/types/Sex.h"
#include "../data/ColumnData.h"

#include <string>
#include <map>
#include <memory>

namespace faker
{
class ColumnTypeValueProvider
{
private:
    static const int MAX_INT_VALUE = 999999999;
private:
    static std::string getAlphaNumericValue();
    static std::string getGenericStringValue();
    static std::string getInteger();
    static std::string getBoolean();
    static std::string getDateTime();
    static std::string getDateOfBirth();
    static std::string getCryptoString();
    static std::string getEmail();
    static std::string getAvatar();
    static std::string getFirstName(faker::Country country, faker::Sex sex);
    static std::string getLastName(faker::Country country, faker::Sex sex);
    static std::string getFullName(faker::Country country, faker::Sex sex);
    static std::string getPersonTitle(faker::Sex sex);
    static std::string getSentence();
    static std::string getToken();
    static std::string getUsername();
    static std::string getPhoneNumber();

public:
    static std::string getValue(std::string columnName, faker::Country country, faker::Sex sex);
};
}