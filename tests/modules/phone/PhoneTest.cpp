#include "faker-cxx/Phone.h"

#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>

#include <gtest/gtest.h>

#include "phone/PhoneData.h"

using namespace ::testing;
using namespace faker;

class PhoneTest : public Test
{
protected:
    static bool isStringNumericWithSpecialChars(const std::string& str)
    {
        return std::ranges::all_of(
            str, [](char c) { return std::isdigit(c) || c == '-' || c == '(' || c == ')' || c == '+' || c == ' '; });
    }
};

TEST_F(PhoneTest, NumberWithNoFormat)
{
    const auto phoneNumber = Phone::number();

    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST_F(PhoneTest, NumberWithFormat)
{
    auto format = "501-###-###";
    auto phoneNumber = Phone::number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));

    format = "+48 91 ### ## ##";
    phoneNumber = Phone::number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));

    format = "+376 (###) ###-####";
    phoneNumber = Phone::number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));

    format = "+376 (!!!) !!!-!!!!";
    phoneNumber = Phone::number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST_F(PhoneTest, IMEIGeneration)
{
    auto imei = Phone::imei();

    imei.erase(std::remove(imei.begin(), imei.end(), '-'), imei.end());

    ASSERT_EQ(imei.length(), 15);
    ASSERT_TRUE(isStringNumericWithSpecialChars(imei));
}

TEST_F(PhoneTest, NumberFormatTest)
{
    const auto phoneNumber = Phone::number(PhoneNumberCountryFormat::Zimbabwe);

    EXPECT_FALSE(phoneNumber.empty());
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST_F(PhoneTest, PlatformGeneration)
{
    const auto generatedPlatform = Phone::platform();
    ASSERT_TRUE(std::ranges::any_of(phone::PhonePlatforms.begin(), phone::PhonePlatforms.end(),
                                    [generatedPlatform](const std::string_view& platform)
                                    { return platform == generatedPlatform; }));
}

TEST_F(PhoneTest, ModelNameGeneration)
{
    const auto generatedModelName = Phone::modelName();
    ASSERT_TRUE(std::ranges::any_of(phone::PhoneModelNames.begin(), phone::PhoneModelNames.end(),
                                    [generatedModelName](const std::string_view& modelName)
                                    { return modelName == generatedModelName; }));
}

TEST_F(PhoneTest, ManufacturerGeneration)
{
    const auto generatedManufacturer = Phone::manufacturer();
    ASSERT_TRUE(std::ranges::any_of(phone::PhoneManufacturers.begin(), phone::PhoneManufacturers.end(),
                                    [generatedManufacturer](const std::string_view& manufacturer)
                                    { return manufacturer == generatedManufacturer; }));
}

TEST_F(PhoneTest, AreaCodeGeneration)
{
    const auto areaCode = Phone::areaCode();
    ASSERT_TRUE(std::ranges::any_of(phone::areaCodes.begin(), phone::areaCodes.end(),
                                    [areaCode](const std::string_view& code) { return code == areaCode; }));
}
