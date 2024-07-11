#include "faker-cxx/phone.h"

#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>

#include "gtest/gtest.h"

#include "phone/phone_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::phone;

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
    const auto phoneNumber = number();

    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST_F(PhoneTest, NumberWithFormat)
{
    auto format = "501-###-###";
    auto phoneNumber = number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));

    format = "+48 91 ### ## ##";
    phoneNumber = number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));

    format = "+376 (###) ###-####";
    phoneNumber = number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));

    format = "+376 (!!!) !!!-!!!!";
    phoneNumber = number(format);
    ASSERT_NE(phoneNumber, format);
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST_F(PhoneTest, IMEIGeneration)
{
    auto generatedImei = imei();

    generatedImei.erase(std::remove(generatedImei.begin(), generatedImei.end(), '-'), generatedImei.end());

    ASSERT_EQ(generatedImei.length(), 15);
    ASSERT_TRUE(isStringNumericWithSpecialChars(generatedImei));
}

TEST_F(PhoneTest, NumberFormatTest)
{
    const auto generatedPhoneNumber = number(PhoneNumberCountryFormat::Zimbabwe);

    EXPECT_FALSE(generatedPhoneNumber.empty());
    ASSERT_TRUE(isStringNumericWithSpecialChars(generatedPhoneNumber));
}

TEST_F(PhoneTest, PlatformGeneration)
{
    const auto generatedPlatform = platform();
    ASSERT_TRUE(std::ranges::any_of(PhonePlatforms.begin(), PhonePlatforms.end(),
                                    [generatedPlatform](const std::string_view& platform)
                                    { return platform == generatedPlatform; }));
}

TEST_F(PhoneTest, ModelNameGeneration)
{
    const auto generatedModelName = modelName();
    ASSERT_TRUE(std::ranges::any_of(PhoneModelNames.begin(), PhoneModelNames.end(),
                                    [generatedModelName](const std::string_view& modelName)
                                    { return modelName == generatedModelName; }));
}

TEST_F(PhoneTest, ManufacturerGeneration)
{
    const auto generatedManufacturer = manufacturer();
    ASSERT_TRUE(std::ranges::any_of(PhoneManufacturers.begin(), PhoneManufacturers.end(),
                                    [generatedManufacturer](const std::string_view& manufacturer)
                                    { return manufacturer == generatedManufacturer; }));
}

TEST_F(PhoneTest, AreaCodeGeneration)
{
    const auto generatedAreaCode = areaCode();
    ASSERT_TRUE(std::ranges::any_of(areaCodes.begin(), areaCodes.end(),
                                    [generatedAreaCode](const std::string_view& code) { return code == generatedAreaCode; }));
}
