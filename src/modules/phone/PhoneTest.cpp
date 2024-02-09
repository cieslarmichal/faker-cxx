#include "faker-cxx/Phone.h"

#include <algorithm>
#include <string>
#include <vector>

#include "gtest/gtest.h"

#include "data/PhoneData.h"
#include "data/PhoneNumbers.h"
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
    std::string phoneNumber = Phone::number();

    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST_F(PhoneTest, NumberWithFormat)
{
    std::string format = "501-###-###";
    std::string phoneNumber = Phone::number(format);
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
    std::string imei = Phone::imei();

    imei.erase(std::remove(imei.begin(), imei.end(), '-'), imei.end());

    ASSERT_EQ(imei.length(), 15);
    ASSERT_TRUE(isStringNumericWithSpecialChars(imei));
}

TEST_F(PhoneTest, NumberFormatTest)
{
    std::string phoneNumber = Phone::number(PhoneNumberCountryFormat::Zimbabwe);

    EXPECT_FALSE(phoneNumber.empty());
    ASSERT_TRUE(isStringNumericWithSpecialChars(phoneNumber));
}

TEST_F(PhoneTest, PlatformGeneration)
{
    std::string generatedPlatform = Phone::platform();
    ASSERT_TRUE(std::ranges::any_of(faker::data::PhonePlatforms.begin(), faker::data::PhonePlatforms.end(),
                                    [generatedPlatform](const std::string& platform)
                                    { return platform == generatedPlatform; }));
}

TEST_F(PhoneTest, ModelNameGeneration)
{
    std::string generatedModelName = Phone::modelName();
    ASSERT_TRUE(std::ranges::any_of(faker::data::PhoneModelNames.begin(), faker::data::PhoneModelNames.end(),
                                    [generatedModelName](const std::string& modelName)
                                    { return modelName == generatedModelName; }));
}

TEST_F(PhoneTest, ManufacturerGeneration)
{
    std::string generatedManufacturer = Phone::manufacturer();
    ASSERT_TRUE(std::ranges::any_of(faker::data::PhoneManufacturers.begin(), faker::data::PhoneManufacturers.end(),
                                    [generatedManufacturer](const std::string& manufacturer)
                                    { return manufacturer == generatedManufacturer; }));
}

TEST_F(PhoneTest, AreaCodeExtraction)
{
    // Test with a valid phone number including country code
    std::string phoneNumberWithCountryCode = "+1234567890";
    std::string expectedCountryCode = "+1";
    std::string actualCountryCode = Phone::areaCode(phoneNumberWithCountryCode);
    ASSERT_EQ(expectedCountryCode, actualCountryCode);

    // Test with a phone number without country code
    std::string phoneNumberWithoutCountryCode = "1234567890";
    std::string expectedNoCountryCode = "";
    actualCountryCode = Phone::areaCode(phoneNumberWithoutCountryCode);
    ASSERT_EQ(expectedNoCountryCode, actualCountryCode);

    // Test with a phone number that includes non-digit characters immediately after "+"
    std::string phoneNumberWithNonDigitAfterPlus = "+1-234567890";
    expectedCountryCode = "+1";
    actualCountryCode = Phone::areaCode(phoneNumberWithNonDigitAfterPlus);
    ASSERT_EQ(expectedCountryCode, actualCountryCode);

    // Test with an empty string
    std::string emptyPhoneNumber = "";
    expectedNoCountryCode = "";
    actualCountryCode = Phone::areaCode(emptyPhoneNumber);
    ASSERT_EQ(expectedNoCountryCode, actualCountryCode);

    // Test with a phone number that starts with "+" but followed by non-digits
    std::string phoneNumberWithPlusAndNonDigits = "+abcdefg";
    expectedNoCountryCode = "";
    actualCountryCode = Phone::areaCode(phoneNumberWithPlusAndNonDigits);
    ASSERT_EQ(expectedNoCountryCode, actualCountryCode);

    // Test with a phone number that has "+" not at the beginning
    std::string phoneNumberWithPlusNotAtStart = "123+4567890";
    expectedNoCountryCode = "";
    actualCountryCode = Phone::areaCode(phoneNumberWithPlusNotAtStart);
    ASSERT_EQ(expectedNoCountryCode, actualCountryCode);
}
