#include "faker-cxx/System.h"

#include <algorithm>
#include <optional>
#include <regex>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

#include "system/SystemData.h"

using namespace ::testing;
using namespace faker::system;

const std::unordered_map<FileType, std::string_view> fileTypeToStringMapping{
    {FileType::Video, "video"},
    {FileType::Audio, "audio"},
    {FileType::Image, "image"},
    {FileType::Text, "text"},
    {FileType::Application, "application"},
};

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

    const auto expectedFileName = fileName(options);

    EXPECT_FALSE(expectedFileName.empty());

    FileOptions options2;
    options2.extensionRange.min = 1;
    options2.extensionRange.max = 3;

    const auto expectedFileName2 = fileName(options2);

    EXPECT_FALSE(expectedFileName2.empty());
}

TEST_F(SystemTest, FileExtTestWithMimeType)
{
    const auto exampleFileExtension = fileExtension();

    EXPECT_FALSE(exampleFileExtension.empty());
}

TEST_F(SystemTest, FileExtTestWithMimeTypeEnum)
{
    const auto image = FileType::Image;
    const auto audio = FileType::Audio;
    const auto video = FileType::Video;
    const auto text = FileType::Text;
    const auto application = FileType::Application;

    std::vector<std::string_view> imageExtensions;

    for (const auto& mimeType : mimeTypes)
    {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == fileTypeToStringMapping.at(image))
        {
            imageExtensions.push_back(mimeType.substr(pos + 1));
        }
    }

    std::vector<std::string_view> audioExtensions;

    for (const auto& mimeType : mimeTypes)
    {
        size_t pos = mimeType.find_first_of('/');

        const auto ext = mimeType.substr(0, pos);

        if (ext == fileTypeToStringMapping.at(audio))
        {
            audioExtensions.push_back(mimeType.substr(pos + 1));
        }
    }

    std::vector<std::string_view> videoExtensions;

    for (const auto& mimeType : mimeTypes)
    {
        size_t pos = mimeType.find_first_of('/');

        const auto ext = mimeType.substr(0, pos);

        if (ext == fileTypeToStringMapping.at(video))
        {
            videoExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> textExtensions;

    for (const auto& mimeType : mimeTypes)
    {
        size_t pos = mimeType.find_first_of('/');

        const auto ext = mimeType.substr(0, pos);

        if (ext == fileTypeToStringMapping.at(text))
        {
            textExtensions.push_back(mimeType.substr(pos + 1));
        }
    }

    std::vector<std::string_view> applicationExtensions;

    for (const auto& mimeType : mimeTypes)
    {
        size_t pos = mimeType.find_first_of('/');

        const auto ext = mimeType.substr(0, pos);

        if (ext == fileTypeToStringMapping.at(application))
        {
            applicationExtensions.push_back(mimeType.substr(pos + 1));
        }
    }

    const auto imageExt = fileExtension(image);
    const auto audioExt = fileExtension(audio);
    const auto videoExt = fileExtension(video);
    const auto textExt = fileExtension(text);
    const auto applicationExt = fileExtension(application);

    EXPECT_TRUE(std::ranges::find(imageExtensions, imageExt) != imageExtensions.end());
    EXPECT_TRUE(std::ranges::find(audioExtensions, audioExt) != audioExtensions.end());
    EXPECT_TRUE(std::ranges::find(videoExtensions, videoExt) != videoExtensions.end());
    EXPECT_TRUE(std::ranges::find(textExtensions, textExt) != textExtensions.end());
    EXPECT_TRUE(std::ranges::find(applicationExtensions, applicationExt) != applicationExtensions.end());
}

TEST_F(SystemTest, CommonFileNameWithEmptyExtensionTest)
{
    const auto actualFileName = commonFileName();

    const auto actualExtension = actualFileName.substr(actualFileName.find_last_of('.') + 1);
    EXPECT_FALSE(actualExtension.empty());

    const auto fileNameWithParam = commonFileName("txt");

    const auto extensionWithParam = fileNameWithParam.substr(fileNameWithParam.find_last_of('.') + 1);

    EXPECT_EQ(extensionWithParam, "txt");
}

TEST_F(SystemTest, MimeTypeTest)
{
    const auto mimeTypeResult = mimeType();

    bool isValidMimeType = std::ranges::find(mimeTypes, mimeTypeResult) != mimeTypes.end();

    EXPECT_TRUE(isValidMimeType);
}

TEST_F(SystemTest, FileTypeTest)
{
    std::set<std::string_view> typeSet;

    for (const auto& entry : mimeTypes)
    {
        size_t pos = entry.find('/');

        if (pos != std::string::npos)
        {
            auto type = entry.substr(0, pos);

            typeSet.insert(type);
        }
    }

    std::vector<std::string> expectedTypes(typeSet.begin(), typeSet.end());

    const auto fileTypeResult = fileType();

    std::cout << fileTypeResult << std::endl;

    bool isValidFileType = std::ranges::find(expectedTypes, fileTypeResult) != expectedTypes.end();

    EXPECT_TRUE(isValidFileType);
}

TEST_F(SystemTest, FilePathTest)
{
    const auto generatedFilePath = filePath();

    EXPECT_FALSE(generatedFilePath.empty());
}

TEST_F(SystemTest, SemverTest)
{
    const auto semverResult = semver();

    EXPECT_TRUE(std::regex_match(semverResult, std::regex("\\d+\\.\\d+\\.\\d+")));
}

TEST_F(SystemTest, NetworkInterfaceMethodTest)
{
    const auto result1 = networkInterface(std::nullopt);

    ASSERT_TRUE(!result1.empty());

    NetworkInterfaceOptions options2;
    options2.interfaceType = "wl";

    const auto result2 = networkInterface(options2);

    ASSERT_TRUE(!result2.empty());

    NetworkInterfaceOptions options3;
    options3.interfaceSchema = "mac";

    const auto result3 = networkInterface(options3);

    ASSERT_EQ(result3.size(), 15);

    NetworkInterfaceOptions options4;
    options4.interfaceType = "en";
    options4.interfaceSchema = "pci";

    const auto result4 = networkInterface(options4);

    ASSERT_TRUE(!result4.empty());
}

TEST_F(SystemTest, ValidCronExpression)
{
    std::string cronExpr = cron();
    EXPECT_TRUE(isValidCronExpression(cronExpr));
}

TEST_F(SystemTest, IncludeYearOption)
{
    CronOptions options;
    options.includeYear = true;

    const auto cronExpr = cron(options);

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

    const auto cronExpr = cron(options);

    std::vector<std::string> nonStandardExpressions = {"@annually", "@daily",  "@hourly", "@monthly",
                                                       "@reboot",   "@weekly", "@yearly"};
    bool isNonStandard = std::ranges::find(nonStandardExpressions, cronExpr) != nonStandardExpressions.end();
    EXPECT_TRUE(isNonStandard || isValidCronExpression(cronExpr));
}
