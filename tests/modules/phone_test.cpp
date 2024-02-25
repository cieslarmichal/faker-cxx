#include "../test_helpers.h"
#include <algorithm>
#include <faker/phone.h>
#include <modules/phone_data.h>
#include <string>
#include <vector>

using namespace ::testing;
using namespace faker;

class PhoneTest : public Test {
protected:
    static bool isStringNumericWithSpecialChars(const std::string& str)
    {
        return faker::testing::all_of(str, [](char c) {
            return std::isdigit(c) || c == '-' || c == '(' || c == ')' || c == '+' || c == ' ';
        });
    }
};

TEST_F(PhoneTest, NumberWithNoFormat)
{
    std::string phoneNumber = phone::number();

    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST_F(PhoneTest, NumberWithFormat)
{
    std::string format = "501-###-###";
    std::string phoneNumber = phone::number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));

    format = "+48 91 ### ## ##";
    phoneNumber = phone::number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));

    format = "+376 (###) ###-####";
    phoneNumber = phone::number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));

    format = "+376 (!!!) !!!-!!!!";
    phoneNumber = phone::number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST_F(PhoneTest, IMEIGeneration)
{
    std::string imei = phone::imei();

    imei.erase(std::remove(imei.begin(), imei.end(), '-'), imei.end());

    ASSERT_EQ(imei.length(), 15);
    ASSERT_TRUE(isStringNumericWithSpecialChars(imei));
}

TEST_F(PhoneTest, NumberFormatTest)
{
    std::string phoneNumber = phone::number(PhoneNumberCountryFormat::Zimbabwe);

    EXPECT_FALSE(phoneNumber.empty());
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST_F(PhoneTest, PlatformGeneration)
{
    std::string generatedPlatform = phone::platform();
    ASSERT_TRUE(faker::testing::contains(faker::data::PhonePlatforms, generatedPlatform));
}

TEST_F(PhoneTest, ModelNameGeneration)
{
    std::string generatedModelName = phone::modelName();
    ASSERT_TRUE(faker::testing::contains(faker::data::PhoneModelNames, generatedModelName));
}

TEST_F(PhoneTest, ManufacturerGeneration)
{
    std::string generatedManufacturer = phone::manufacturer();
    ASSERT_TRUE(faker::testing::contains(faker::data::PhoneManufacturers, generatedManufacturer));
}
