#include "../test_helpers.h"
#include <algorithm>
#include <faker/system.h>
#include <modules/system_data.h>
#include <regex>
#include <unordered_set>

using namespace ::testing;
using namespace faker;
using namespace faker::system;

class SystemTest : public Test { };

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

    std::string expectedFileName = system::fileName(options);

    EXPECT_FALSE(expectedFileName.empty());

    FileOptions options2;
    options2.extensionRange.min = 1;
    options2.extensionRange.max = 3;

    std::string expectedFileName2 = system::fileName(options2);

    EXPECT_FALSE(expectedFileName2.empty());
}

TEST_F(SystemTest, FileExtTestWithMimeType)
{
    std::string exampleFileExtension = system::fileExtension();

    EXPECT_FALSE(exampleFileExtension.empty());
}

TEST_F(SystemTest, FileExtTestWithMimeTypeEnum)
{
    auto image = FileType::Image;
    auto audio = FileType::Audio;
    auto video = FileType::Video;
    auto text = FileType::Text;
    auto application = FileType::Application;

    std::vector<std::string_view> imageExtensions;
    for (const auto& mimeType : data::mimeTypes) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(image)) {
            imageExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> audioExtensions;
    for (const auto& mimeType : data::mimeTypes) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(audio)) {
            audioExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> videoExtensions;
    for (const auto& mimeType : data::mimeTypes) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(video)) {
            videoExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> textExtensions;
    for (const auto& mimeType : data::mimeTypes) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(text)) {
            textExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> applicationExtensions;
    for (const auto& mimeType : data::mimeTypes) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(application)) {
            applicationExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    auto imageExt = system::fileExtension(image);
    auto audioExt = system::fileExtension(audio);
    auto videoExt = system::fileExtension(video);
    auto textExt = system::fileExtension(text);
    auto applicationExt = system::fileExtension(application);

    EXPECT_TRUE(faker::testing::find(imageExtensions, imageExt) != imageExtensions.end());
    EXPECT_TRUE(faker::testing::find(audioExtensions, audioExt) != audioExtensions.end());
    EXPECT_TRUE(faker::testing::find(videoExtensions, videoExt) != videoExtensions.end());
    EXPECT_TRUE(faker::testing::find(textExtensions, textExt) != textExtensions.end());
    EXPECT_TRUE(
        faker::testing::find(applicationExtensions, applicationExt) != applicationExtensions.end());
}

TEST_F(SystemTest, CommonFileNameWithEmptyExtensionTest)
{
    auto actualFileName = system::commonFileName();

    auto actualExtension = actualFileName.substr(actualFileName.find_last_of('.') + 1);
    EXPECT_FALSE(actualExtension.empty());

    auto fileNameWithParam = system::commonFileName("txt");
    auto extensionWithParam = fileNameWithParam.substr(fileNameWithParam.find_last_of('.') + 1);

    EXPECT_EQ(extensionWithParam, "txt");
}

TEST_F(SystemTest, MimeTypeTest)
{
    auto mimeTypeResult = system::mimeType();

    bool isValidMimeType
        = faker::testing::find(data::mimeTypes, mimeTypeResult) != data::mimeTypes.end();
    EXPECT_TRUE(isValidMimeType);
}

TEST_F(SystemTest, CommonFileTypeTest)
{
    auto commonFileTypeResult = system::commonFileType();

    bool isValidCommonFileType = faker::testing::find(data::commonFileTypes, commonFileTypeResult)
        != data::commonFileTypes.end();
    EXPECT_TRUE(isValidCommonFileType);
}

TEST_F(SystemTest, FileTypeTest)
{
    std::unordered_set<std::string_view> typeSet;
    for (const auto& entry : data::mimeTypes) {
        const auto& m = entry;
        size_t pos = m.find('/');
        if (pos != std::string::npos) {
            auto type = m.substr(0, pos);
            typeSet.insert(type);
        }
    }
    std::vector<std::string> expectedTypes(typeSet.begin(), typeSet.end());

    auto fileTypeResult = system::fileType();

    bool isValidFileType
        = faker::testing::find(expectedTypes, fileTypeResult) != expectedTypes.end();
    EXPECT_TRUE(isValidFileType);
}

TEST_F(SystemTest, FilePathTest)
{
    auto filePath = system::filePath();

    EXPECT_FALSE(filePath.empty());
}

TEST_F(SystemTest, SemverTest)
{
    auto semverResult = system::semver();

    EXPECT_TRUE(std::regex_match(semverResult, std::regex("\\d+\\.\\d+\\.\\d+")));
}

TEST_F(SystemTest, NetworkInterfaceMethodTest)
{

    auto result1 = system::networkInterface(std::nullopt);
    ASSERT_TRUE(!result1.empty());

    NetworkInterfaceOptions options2;
    options2.interfaceType = "wl";
    auto result2 = system::networkInterface(options2);
    ASSERT_TRUE(!result2.empty());

    NetworkInterfaceOptions options3;
    options3.interfaceSchema = "mac";
    auto result3 = system::networkInterface(options3);
    ASSERT_EQ(result3.size(), 15);

    NetworkInterfaceOptions options4;
    options4.interfaceType = "en";
    options4.interfaceSchema = "pci";
    auto result4 = system::networkInterface(options4);
    ASSERT_TRUE(!result4.empty());
}

TEST_F(SystemTest, ValidCronExpression)
{
    auto cronExpr = system::cron();

    EXPECT_TRUE(isValidCronExpression(cronExpr));
}

TEST_F(SystemTest, IncludeYearOption)
{
    CronOptions options;
    options.includeYear = true;
    auto cronExpr = system::cron(options);

    EXPECT_TRUE(isValidCronExpression(cronExpr));

    int yearValue = -1;

    if (std::smatch match;
        std::regex_search(cronExpr, match, std::regex(R"(\b(19[7-9][0-9]|20[0-9]{2})\b)"))) {
        yearValue = std::stoi(match.str());
    }
    EXPECT_GE(yearValue, 1970);
    EXPECT_LE(yearValue, 2099);
}

TEST_F(SystemTest, IncludeNonStandardOption)
{
    CronOptions options;
    options.includeNonStandard = true;

    auto cronExpr = system::cron(options);

    std::vector<std::string> nonStandardExpressions
        = { "@annually", "@daily", "@hourly", "@monthly", "@reboot", "@weekly", "@yearly" };
    bool isNonStandard
        = faker::testing::find(nonStandardExpressions, cronExpr) != nonStandardExpressions.end();
    EXPECT_TRUE(isNonStandard || isValidCronExpression(cronExpr));
}
