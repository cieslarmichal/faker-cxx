#include "faker-cxx/System.h"

#include <algorithm>
#include <regex>

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

class SystemTest : public Test
{
};

const std::regex validCronPattern(
    R"((\*|[0-9]+|\?|\b(JAN|FEB|MAR|APR|MAY|JUN|JUL|AUG|SEP|OCT|NOV|DEC)\b|\b(SUN|MON|TUE|WED|THU|FRI|SAT)\b)( (\*|[0-9]+|\?|\b(JAN|FEB|MAR|APR|MAY|JUN|JUL|AUG|SEP|OCT|NOV|DEC)\b|\b(SUN|MON|TUE|WED|THU|FRI|SAT)\b)){4,5})");

bool isValidCronExpression(const std::string& cronExpr)
{
    return std::regex_match(cronExpr, validCronPattern);
}

TEST_F(SystemTest, FileNameTestWithExtensionCount)
{
    FileOptions options;
    options.extensionCount = 3;

    std::string expectedFileName = System::fileName(options);

    EXPECT_FALSE(expectedFileName.empty());

    FileOptions options2;
    options2.extensionRange.min = 1;
    options2.extensionRange.max = 3;

    std::string expectedFileName2 = System::fileName(options2);

    EXPECT_FALSE(expectedFileName2.empty());
}

TEST_F(SystemTest, FileExtTestWithMimeType)
{
    std::string exampleFileExtension = System::fileExtension();

    EXPECT_FALSE(exampleFileExtension.empty());
}

TEST_F(SystemTest, FileExtTestWithMimeTypeEnum)
{
    auto image = FileType::Image;
    auto audio = FileType::Audio;
    auto video = FileType::Video;
    auto text = FileType::Text;
    auto application = FileType::Application;

    std::vector<std::string> imageExtensions;
    for (const auto& mimeType : mimeTypes)
    {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(image))
        {
            imageExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string> audioExtensions;
    for (const auto& mimeType : mimeTypes)
    {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(audio))
        {
            audioExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string> videoExtensions;
    for (const auto& mimeType : mimeTypes)
    {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(video))
        {
            videoExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string> textExtensions;
    for (const auto& mimeType : mimeTypes)
    {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(text))
        {
            textExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string> applicationExtensions;
    for (const auto& mimeType : mimeTypes)
    {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(application))
        {
            applicationExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    auto imageExt = System::fileExtension(image);
    auto audioExt = System::fileExtension(audio);
    auto videoExt = System::fileExtension(video);
    auto textExt = System::fileExtension(text);
    auto applicationExt = System::fileExtension(application);

    EXPECT_TRUE(std::ranges::find(imageExtensions, imageExt) != imageExtensions.end());
    EXPECT_TRUE(std::ranges::find(audioExtensions, audioExt) != audioExtensions.end());
    EXPECT_TRUE(std::ranges::find(videoExtensions, videoExt) != videoExtensions.end());
    EXPECT_TRUE(std::ranges::find(textExtensions, textExt) != textExtensions.end());
    EXPECT_TRUE(std::ranges::find(applicationExtensions, applicationExt) != applicationExtensions.end());
}

TEST_F(SystemTest, CommonFileNameWithEmptyExtensionTest)
{

    std::string actualFileName = System::commonFileName();

    std::string actualExtension = actualFileName.substr(actualFileName.find_last_of('.') + 1);
    EXPECT_FALSE(actualExtension.empty());

    std::string fileNameWithParam = System::commonFileName("txt");

    std::string extensionWithParam = fileNameWithParam.substr(fileNameWithParam.find_last_of('.') + 1);

    EXPECT_EQ(extensionWithParam, "txt");
}

TEST_F(SystemTest, MimeTypeTest)
{
    std::string mimeTypeResult = System::mimeType();

    bool isValidMimeType = std::ranges::find(mimeTypes, mimeTypeResult) != mimeTypes.end();
    EXPECT_TRUE(isValidMimeType);
}

TEST_F(SystemTest, CommonFileTypeTest)
{
    std::string commonFileTypeResult = System::commonFileType();

    bool isValidCommonFileType = std::ranges::find(commonFileTypes, commonFileTypeResult) != commonFileTypes.end();
    EXPECT_TRUE(isValidCommonFileType);
}

TEST_F(SystemTest, FileTypeTest)
{
    std::set<std::string> typeSet;
    for (const auto& entry : mimeTypes)
    {
        const std::string& m = entry;
        size_t pos = m.find('/');
        if (pos != std::string::npos)
        {
            std::string type = m.substr(0, pos);
            typeSet.insert(type);
        }
    }
    std::vector<std::string> expectedTypes(typeSet.begin(), typeSet.end());

    std::string fileTypeResult = System::fileType();

    bool isValidFileType = std::ranges::find(expectedTypes, fileTypeResult) != expectedTypes.end();
    EXPECT_TRUE(isValidFileType);
}

TEST_F(SystemTest, FilePathTest)
{
    std::string filePath = System::filePath();

    EXPECT_FALSE(filePath.empty());
}

TEST_F(SystemTest, SemverTest)
{
    std::string semverResult = System::semver();

    EXPECT_TRUE(std::regex_match(semverResult, std::regex("\\d+\\.\\d+\\.\\d+")));
}

TEST_F(SystemTest, NetworkInterfaceMethodTest)
{

    std::string result1 = System::networkInterface(std::nullopt);
    ASSERT_TRUE(!result1.empty());

    NetworkInterfaceOptions options2;
    options2.interfaceType = "wl";
    std::string result2 = System::networkInterface(options2);
    ASSERT_TRUE(!result2.empty());

    NetworkInterfaceOptions options3;
    options3.interfaceSchema = "mac";
    std::string result3 = System::networkInterface(options3);
    ASSERT_EQ(result3.size(), 15);

    NetworkInterfaceOptions options4;
    options4.interfaceType = "en";
    options4.interfaceSchema = "pci";
    std::string result4 = System::networkInterface(options4);
    ASSERT_TRUE(!result4.empty());
}

TEST_F(SystemTest, ValidCronExpression)
{
    std::string cronExpr = System::cron();
    EXPECT_TRUE(isValidCronExpression(cronExpr));
}

TEST_F(SystemTest, IncludeYearOption)
{
    CronOptions options;
    options.includeYear = true;
    std::string cronExpr = System::cron(options);
    EXPECT_TRUE(isValidCronExpression(cronExpr));

    int yearValue = -1;

    if (std::smatch match; std::regex_search(cronExpr, match, std::regex(R"(\b(19[7-9][0-9]|20[0-9]{2})\b)")))
    {
        yearValue = std::stoi(match.str());
    }
    EXPECT_GE(yearValue, 1970);
    EXPECT_LE(yearValue, 2099);
}

TEST_F(SystemTest, IncludeNonStandardOption)
{
    CronOptions options;
    options.includeNonStandard = true;
    std::string cronExpr = System::cron(options);

    std::vector<std::string> nonStandardExpressions = {"@annually", "@daily",  "@hourly", "@monthly",
                                                       "@reboot",   "@weekly", "@yearly"};
    bool isNonStandard = std::ranges::find(nonStandardExpressions, cronExpr) != nonStandardExpressions.end();
    EXPECT_TRUE(isNonStandard || isValidCronExpression(cronExpr));
}
