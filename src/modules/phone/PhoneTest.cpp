#include "faker-cxx/Phone.h"

#include <algorithm>
#include "gtest/gtest.h"
#include "data/PhoneNumbers.h"

using namespace ::testing;
using namespace faker;

namespace
{

class PhoneTest : public Test
{
protected:
    static bool isStringNumericWithSpecialChars(const std::string& str)
    {
        return std::all_of(str.begin(), str.end(), [](char c) {
                               return std::isdigit(c) || c == '-' || c == '(' || c == ')' || c == '+' || c == ' ';
                           });
    }
};

TEST_F(PhoneTest, NumberWithNoFormat)
{
    Phone phone;
    std::string phoneNumber = phone.number();

    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST_F(PhoneTest, NumberWithFormat)
{
    Phone phone;
    std::string format = "501-###-###";
    std::string phoneNumber = phone.number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));

    format = "+48 91 ### ## ##";
    phoneNumber = phone.number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));

    format = "+376 (###) ###-####";
    phoneNumber = phone.number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));

    format = "+376 (!!!) !!!-!!!!";
    phoneNumber = phone.number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST_F(PhoneTest, IMEIGeneration)
{

    Phone phone;
    std::string imei = phone.imei();

    imei.erase(std::remove(imei.begin(), imei.end(), '-'), imei.end());

    ASSERT_EQ(imei.length(), 15);
    ASSERT_TRUE(isStringNumericWithSpecialChars(imei));
}
}