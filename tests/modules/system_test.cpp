#include "../test_helpers.h"
#include <algorithm>
#include <faker/system.h>
#include <modules/system_data.h>
#include <regex>
#include <unordered_set>

using namespace faker;

const std::regex validCronPattern(
    R"((\*|[0-9]+|\?|\b(JAN|FEB|MAR|APR|MAY|JUN|JUL|AUG|SEP|OCT|NOV|DEC)\b|\b(SUN|MON|TUE|WED|THU|FRI|SAT)\b)( (\*|[0-9]+|\?|\b(JAN|FEB|MAR|APR|MAY|JUN|JUL|AUG|SEP|OCT|NOV|DEC)\b|\b(SUN|MON|TUE|WED|THU|FRI|SAT)\b)){4,5})");

bool isValidCronExpression(const std::string& cronExpr)
{
    return std::regex_match(cronExpr, validCronPattern);
}

TEST(SystemTest, FileNameTestWithExtensionCount)
{
    system::FileOptions options;
    options.extensionCount = 3;

    std::string expectedFileName = system::fileName(options);

    EXPECT_FALSE(expectedFileName.empty());

    system::FileOptions options2;
    options2.extensionRange.min = 1;
    options2.extensionRange.max = 3;

    std::string expectedFileName2 = system::fileName(options2);

    EXPECT_FALSE(expectedFileName2.empty());
}

TEST(SystemTest, FileExtTestWithMimeType)
{
    std::string exampleFileExtension = system::fileExtension();

    EXPECT_FALSE(exampleFileExtension.empty());
}

TEST(SystemTest, FileExtTestWithMimeTypeEnum)
{
    auto image = system::FileType::Image;
    auto audio = system::FileType::Audio;
    auto video = system::FileType::Video;
    auto text = system::FileType::Text;
    auto application = system::FileType::Application;

    std::vector<std::string_view> imageExtensions;
    for (const auto& mimeType : system::data::mimeTypes) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(image)) {
            imageExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> audioExtensions;
    for (const auto& mimeType : system::data::mimeTypes) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(audio)) {
            audioExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> videoExtensions;
    for (const auto& mimeType : system::data::mimeTypes) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(video)) {
            videoExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> textExtensions;
    for (const auto& mimeType : system::data::mimeTypes) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == toString(text)) {
            textExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> applicationExtensions;
    for (const auto& mimeType : system::data::mimeTypes) {
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

    FAKER_EXPECT_CONTAINER_CONTAINS(imageExtensions, imageExt);
    FAKER_EXPECT_CONTAINER_CONTAINS(audioExtensions, audioExt);
    FAKER_EXPECT_CONTAINER_CONTAINS(videoExtensions, videoExt);
    FAKER_EXPECT_CONTAINER_CONTAINS(textExtensions, textExt);
    FAKER_EXPECT_CONTAINER_CONTAINS(applicationExtensions, applicationExt);
}

TEST(SystemTest, CommonFileNameWithEmptyExtensionTest)
{
    auto actualFileName = system::commonFileName();

    auto actualExtension = actualFileName.substr(actualFileName.find_last_of('.') + 1);
    EXPECT_FALSE(actualExtension.empty());

    auto fileNameWithParam = system::commonFileName("txt");
    auto extensionWithParam = fileNameWithParam.substr(fileNameWithParam.find_last_of('.') + 1);

    EXPECT_EQ(extensionWithParam, "txt");
}

TEST(SystemTest, MimeTypeTest)
{
    auto mimeTypeResult = system::mimeType();

    FAKER_EXPECT_CONTAINER_CONTAINS(system::data::mimeTypes, mimeTypeResult);
}

TEST(SystemTest, CommonFileTypeTest)
{
    auto commonFileTypeResult = system::commonFileType();

    FAKER_EXPECT_CONTAINER_CONTAINS(system::data::commonFileTypes, commonFileTypeResult);
}

TEST(SystemTest, FileTypeTest)
{
    std::unordered_set<std::string_view> typeSet;
    for (const auto& entry : system::data::mimeTypes) {
        const auto& m = entry;
        size_t pos = m.find('/');
        if (pos != std::string::npos) {
            auto type = m.substr(0, pos);
            typeSet.insert(type);
        }
    }
    std::vector<std::string> expectedTypes(typeSet.begin(), typeSet.end());

    auto fileTypeResult = system::fileType();

    FAKER_EXPECT_CONTAINER_CONTAINS(expectedTypes, fileTypeResult);
}

TEST(SystemTest, FilePathTest)
{
    auto filePath = system::filePath();

    EXPECT_FALSE(filePath.empty());
}

TEST(SystemTest, SemverTest)
{
    auto semverResult = system::semver();

    EXPECT_TRUE(std::regex_match(semverResult, std::regex("\\d+\\.\\d+\\.\\d+")));
}

TEST(SystemTest, NetworkInterfaceMethodTest)
{

    auto result1 = system::networkInterface(std::nullopt);
    ASSERT_TRUE(!result1.empty());

    system::NetworkInterfaceOptions options2;
    options2.interfaceType = "wl";
    auto result2 = system::networkInterface(options2);
    ASSERT_TRUE(!result2.empty());

    system::NetworkInterfaceOptions options3;
    options3.interfaceSchema = "mac";
    auto result3 = system::networkInterface(options3);
    ASSERT_EQ(result3.size(), 15);

    system::NetworkInterfaceOptions options4;
    options4.interfaceType = "en";
    options4.interfaceSchema = "pci";
    auto result4 = system::networkInterface(options4);
    ASSERT_TRUE(!result4.empty());
}

TEST(SystemTest, ValidCronExpression)
{
    auto cronExpr = system::cron();

    EXPECT_TRUE(isValidCronExpression(cronExpr));
}

TEST(SystemTest, IncludeYearOption)
{
    system::CronOptions options;
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

TEST(SystemTest, IncludeNonStandardOption)
{
    system::CronOptions options;
    options.includeNonStandard = true;

    auto cronExpr = system::cron(options);

    std::vector<std::string> nonStandardExpressions
        = { "@annually", "@daily", "@hourly", "@monthly", "@reboot", "@weekly", "@yearly" };
    bool isNonStandard
        = faker::testing::find(nonStandardExpressions, cronExpr) != nonStandardExpressions.end();
    EXPECT_TRUE(isNonStandard || isValidCronExpression(cronExpr));
}
