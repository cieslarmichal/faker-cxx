#include "faker-cxx/Phone.h"

#include <algorithm>
#include <string>
#include <vector>

#include "gtest/gtest.h"

#include "data/PhoneNumbers.h"
#include "faker-cxx/data/PhoneData.h"
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
    std::vector<std::string> platforms = {
        "Android OS", "iOS", "Windows Phone", "Symbian", "Palm OS", "Tizen",
    };
    ASSERT_TRUE(std::ranges::any_of(platforms.begin(), platforms.end(),
                                    [generatedPlatform](const std::string& platform)
                                    { return platform == generatedPlatform; }));
}

TEST_F(PhoneTest, ModelNameGeneration)
{
    std::string generatedModelName = Phone::modelName();
    std::vector<std::string> modelNames = {
       "Samsung Galaxy S9", "iPhone X",   "Google Pixel 4", "Samsung Galaxy S22", "iPhone 13",
        "iPhone 13",         "iPhone 14",  "iPhone 15",      "Google Pixel 6",     "OnePlus 9",
        "Xiaomi Mi 11",      "Huawei P50", "Oppo Find X3",   "Sony Xperia 1 III",  "Motorola Edge 20"};
    ASSERT_TRUE(std::ranges::any_of(modelNames.begin(), modelNames.end(),
                                    [generatedModelName](const std::string& modelName)
                                    { return modelName == generatedModelName; }));
}

TEST_F(PhoneTest, ManufacturerGeneration)
{
    std::string generatedManufacturer = Phone::manufacturer();
    std::vector<std::string> manufacturers = {"Samsung", "Apple", "Google", "OnePlus", "Xiaomi",
                                              "Huawei",  "Oppo",  "Sony",   "Motorola"};
    ASSERT_TRUE(std::ranges::any_of(manufacturers.begin(), manufacturers.end(),
                                    [generatedManufacturer](const std::string& manufacturer)
                                    { return manufacturer == generatedManufacturer; }));
}
