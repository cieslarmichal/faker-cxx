#include "../test_helpers.h"
#include <algorithm>
#include <faker/system.h>
#include <modules/system_data.h>
#include <regex>
#include <unordered_set>

using namespace faker;

bool is_valid_cron_expr(const std::string& value)
{
    const std::regex re_cron_expr(
        R"((\*|[0-9]+|\?|\b(JAN|FEB|MAR|APR|MAY|JUN|JUL|AUG|SEP|OCT|NOV|DEC)\b|\b(SUN|MON|TUE|WED|THU|FRI|SAT)\b)( (\*|[0-9]+|\?|\b(JAN|FEB|MAR|APR|MAY|JUN|JUL|AUG|SEP|OCT|NOV|DEC)\b|\b(SUN|MON|TUE|WED|THU|FRI|SAT)\b)){4,5})");

    return std::regex_match(value, re_cron_expr);
}

TEST(SystemTest, FileNameTestWithExtensionCount)
{
    system::file_options_t options;
    options.extension_count = 3;

    auto filename1 = system::filename(options);
    EXPECT_FALSE(filename1.empty());

    system::file_options_t options2;
    options2.extension_range.min = 1;
    options2.extension_range.max = 3;

    auto filename2 = system::filename(options2);
    EXPECT_FALSE(filename2.empty());
}

TEST(SystemTest, FileExtTestWithMimeType)
{
    auto ext = system::file_ext();

    EXPECT_FALSE(ext.empty());
}

TEST(SystemTest, FileExtTestWithMimeTypeEnum)
{
    auto image = system::file_type_t::image;
    auto audio = system::file_type_t::audio;
    auto video = system::file_type_t::video;
    auto text = system::file_type_t::text;
    auto application = system::file_type_t::application;

    std::vector<std::string_view> imageExtensions;
    for (const auto& mimeType : system::data::mime_types) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == to_string(image)) {
            imageExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> audioExtensions;
    for (const auto& mimeType : system::data::mime_types) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == to_string(audio)) {
            audioExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> videoExtensions;
    for (const auto& mimeType : system::data::mime_types) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == to_string(video)) {
            videoExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> textExtensions;
    for (const auto& mimeType : system::data::mime_types) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == to_string(text)) {
            textExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    std::vector<std::string_view> applicationExtensions;
    for (const auto& mimeType : system::data::mime_types) {
        size_t pos = mimeType.find_first_of('/');
        const auto ext = mimeType.substr(0, pos);
        if (ext == to_string(application)) {
            applicationExtensions.push_back(mimeType.substr(pos + 1));
        }
    }
    auto imageExt = system::file_ext(image);
    auto audioExt = system::file_ext(audio);
    auto videoExt = system::file_ext(video);
    auto textExt = system::file_ext(text);
    auto applicationExt = system::file_ext(application);

    FAKER_EXPECT_CONTAINER_CONTAINS(imageExtensions, imageExt);
    FAKER_EXPECT_CONTAINER_CONTAINS(audioExtensions, audioExt);
    FAKER_EXPECT_CONTAINER_CONTAINS(videoExtensions, videoExt);
    FAKER_EXPECT_CONTAINER_CONTAINS(textExtensions, textExt);
    FAKER_EXPECT_CONTAINER_CONTAINS(applicationExtensions, applicationExt);
}

TEST(SystemTest, CommonFileNameWithEmptyExtensionTest)
{
    auto actualFileName = system::common_filename();

    auto actualExtension = actualFileName.substr(actualFileName.find_last_of('.') + 1);
    EXPECT_FALSE(actualExtension.empty());

    auto fileNameWithParam = system::common_filename("txt");
    auto extensionWithParam = fileNameWithParam.substr(fileNameWithParam.find_last_of('.') + 1);

    EXPECT_EQ(extensionWithParam, "txt");
}

TEST(SystemTest, MimeTypeTest)
{
    auto mimeTypeResult = system::mime_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(system::data::mime_types, mimeTypeResult);
}

TEST(SystemTest, CommonFileTypeTest)
{
    auto commonFileTypeResult = system::common_file_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(system::data::common_file_types, commonFileTypeResult);
}

TEST(SystemTest, FileTypeTest)
{
    std::unordered_set<std::string_view> typeSet;
    for (const auto& entry : system::data::mime_types) {
        const auto& m = entry;
        size_t pos = m.find('/');
        if (pos != std::string::npos) {
            auto type = m.substr(0, pos);
            typeSet.insert(type);
        }
    }
    std::vector<std::string> expectedTypes(typeSet.begin(), typeSet.end());

    auto fileTypeResult = system::file_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(expectedTypes, fileTypeResult);
}

TEST(SystemTest, FilePathTest)
{
    auto filePath = system::file_path();

    EXPECT_FALSE(filePath.empty());
}

TEST(SystemTest, SemverTest)
{
    auto semverResult = system::semver();

    EXPECT_TRUE(std::regex_match(semverResult, std::regex("\\d+\\.\\d+\\.\\d+")));
}

TEST(SystemTest, NetworkInterfaceMethodTest)
{

    auto result1 = system::network_interface(std::nullopt);
    ASSERT_TRUE(!result1.empty());

    system::NetworkInterfaceOptions options2;
    options2.interfaceType = "wl";
    auto result2 = system::network_interface(options2);
    ASSERT_TRUE(!result2.empty());

    system::NetworkInterfaceOptions options3;
    options3.interfaceSchema = "mac";
    auto result3 = system::network_interface(options3);
    ASSERT_EQ(result3.size(), 15);

    system::NetworkInterfaceOptions options4;
    options4.interfaceType = "en";
    options4.interfaceSchema = "pci";
    auto result4 = system::network_interface(options4);
    ASSERT_TRUE(!result4.empty());
}

TEST(SystemTest, ValidCronExpression)
{
    auto expr = system::cron();

    EXPECT_TRUE(is_valid_cron_expr(expr));
}

TEST(SystemTest, IncludeYearOption)
{
    auto expr = system::cron(system::cron_options_t::include_year);

    EXPECT_TRUE(is_valid_cron_expr(expr));

    auto last_sep_pos = expr.find_last_of(' ');
    ASSERT_NE(last_sep_pos, std::string::npos);

    auto year_part_str = expr.substr(last_sep_pos + 1);

    if (year_part_str != "*") {
        auto year = std::stoi(year_part_str);
        EXPECT_GE(year, 1970);
        EXPECT_LE(year, 2099);
    }
}

TEST(SystemTest, IncludeNonStandardOption)
{
    auto expr = system::cron(system::cron_options_t::include_non_standard);

    auto is_non_standard = faker::testing::find(system::data::non_standard_cron_expressions, expr)
        != system::data::non_standard_cron_expressions.end();
    EXPECT_TRUE(is_non_standard || is_valid_cron_expr(expr));
}
