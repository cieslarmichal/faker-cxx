#include "../test_helpers.h"
#include <algorithm>
#include <faker/phone.h>
#include <modules/phone_data.h>
#include <string>
#include <vector>

using namespace faker;

bool isStringNumericWithSpecialChars(const std::string& str)
{
    return faker::testing::all_of(str, [](char c) {
        return std::isdigit(c) || c == '-' || c == '(' || c == ')' || c == '+' || c == ' ';
    });
}

TEST(PhoneTest, NumberWithNoFormat)
{
    auto phoneNumber = phone::number();

    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST(PhoneTest, NumberWithFormat)
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

TEST(PhoneTest, IMEIGeneration)
{
    auto imei = phone::imei();

    imei.erase(std::remove(imei.begin(), imei.end(), '-'), imei.end());

    ASSERT_EQ(imei.length(), 15);
    ASSERT_TRUE(isStringNumericWithSpecialChars(imei));
}

TEST(PhoneTest, NumberFormatTest)
{
    auto phoneNumber = phone::number(phone::phone_number_format_t::zimbabwe);

    EXPECT_FALSE(phoneNumber.empty());
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST(PhoneTest, PlatformGeneration)
{
    auto generatedPlatform = phone::platform();

    FAKER_EXPECT_CONTAINER_CONTAINS(phone::data::platforms, generatedPlatform);
}

TEST(PhoneTest, ModelNameGeneration)
{
    auto generatedModelName = phone::model_name();

    FAKER_EXPECT_CONTAINER_CONTAINS(phone::data::model_names, generatedModelName);
}

TEST(PhoneTest, ManufacturerGeneration)
{
    auto generatedManufacturer = phone::manufacturer();

    FAKER_EXPECT_CONTAINER_CONTAINS(phone::data::manufacturers, generatedManufacturer);
}
