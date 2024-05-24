#include "faker-cxx/Phone.h"

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

#include "data/AreaCodes.h"
#include "data/PhoneData.h"

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

TEST_F(PhoneTest, AreaCodeGeneration)
{
    std::string areaCode = Phone::areaCode();
    ASSERT_TRUE(std::ranges::any_of(faker::data::areaCodes.begin(), faker::data::areaCodes.end(),
                                    [areaCode](const std::string& code) { return code == areaCode; }));
}
