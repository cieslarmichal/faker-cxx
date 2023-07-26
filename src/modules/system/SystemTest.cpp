#include "faker-cxx/System.h"

#include <algorithm>

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker;

class SystemTest : public Test
{
protected:
    System system;
};

TEST_F(SystemTest, FileNameTestWithExtensionCount)
{
    FileOptions options;
    options.extensionCount = 3;

    // Perform the actual function call
    std::string expectedFileName = system.fileName(options);

    // Check the result
    EXPECT_FALSE(expectedFileName.empty());

    FileOptions options2;
    options2.extensionRange.min = 1;
    options2.extensionRange.max = 3;

    std::string expectedFileName2 = system.fileName(options2);

    EXPECT_FALSE(expectedFileName.empty());
}

TEST_F(SystemTest, FileExtTestWithMimeType)
{
    std::string exampleFileExtension = system.fileExt();

    EXPECT_FALSE(exampleFileExtension.empty());

    EXPECT_EQ(system.fileExt("image/png"), "png");
    EXPECT_EQ(system.fileExt("application/pdf"), "pdf");
    EXPECT_EQ(system.fileExt("text/html"), "html");
}

TEST_F(SystemTest, CommonFileNameWithEmptyExtensionTest)
{
    std::string actualFileName = system.commonFileName("");

    std::string actualExtension = actualFileName.substr(actualFileName.find_last_of('.') + 1);
    EXPECT_FALSE(actualExtension.empty());

    std::string fileNameWithParam = system.commonFileName("txt");

    std::string extensionWithParam = fileNameWithParam.substr(fileNameWithParam.find_last_of('.') + 1);

    EXPECT_EQ(extensionWithParam, "txt");
}

TEST_F(SystemTest, MimeTypeTest)
{
    std::vector<std::string> commonMimeTypes = {"application/pdf", "audio/mpeg", "audio/wav",
                                                "image/png",       "image/jpeg", "image/gif",
                                                "video/mp4",       "video/mpeg", "text/html"};

    std::string mimeTypeResult = system.mimeType();

    std::cout << mimeTypeResult << std::endl;

    bool isValidMimeType =
        std::find(commonMimeTypes.begin(), commonMimeTypes.end(), mimeTypeResult) != commonMimeTypes.end();
    EXPECT_TRUE(isValidMimeType);
}

TEST_F(SystemTest, CommonFileTypeTest)
{
    std::vector<std::string> commonFileTypes = {"video", "audio", "image", "text", "application"};

    std::string commonFileTypeResult = system.commonFileType();

    std::cout << commonFileTypeResult << std::endl;

    bool isValidCommonFileType =
        std::find(commonFileTypes.begin(), commonFileTypes.end(), commonFileTypeResult) != commonFileTypes.end();
    EXPECT_TRUE(isValidCommonFileType);
}

TEST_F(SystemTest, FileTypeTest)
{
    std::vector<std::string> commonMimeTypes = {"application/pdf", "audio/mpeg", "audio/wav",
                                                "image/png",       "image/jpeg", "image/gif",
                                                "video/mp4",       "video/mpeg", "text/html"};

    std::set<std::string> typeSet;
    for (const auto& entry : commonMimeTypes)
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

    std::string fileTypeResult = system.fileType();

    std::cout << fileTypeResult << std::endl;

    bool isValidFileType = std::find(expectedTypes.begin(), expectedTypes.end(), fileTypeResult) != expectedTypes.end();
    EXPECT_TRUE(isValidFileType);
}

TEST_F(SystemTest, FilePathTest)
{
    std::string filePath = system.filePath();

    std::cout << filePath << std::endl;

    EXPECT_FALSE(filePath.empty());
}

TEST_F(SystemTest, SemverTest)
{
    std::string semverResult = system.semver();

    std::cout << semverResult << std::endl;

    EXPECT_TRUE(std::regex_match(semverResult, std::regex("\\d+\\.\\d+\\.\\d+")));
}

TEST_F(SystemTest, NetworkInterfaceMethodTest)
{
    System system;

    std::string result1 = system.networkInterface(std::nullopt);
    ASSERT_TRUE(!result1.empty());

    NetworkInterfaceOptions options2;
    options2.interfaceType = "wl";
    std::string result2 = system.networkInterface(options2);
    ASSERT_TRUE(!result2.empty());

    NetworkInterfaceOptions options3;
    options3.interfaceSchema = "mac";
    std::string result3 = system.networkInterface(options3);
    ASSERT_EQ(result3.size(), 15);

    NetworkInterfaceOptions options4;
    options4.interfaceType = "en";
    options4.interfaceSchema = "pci";
    std::string result4 = system.networkInterface(options4);
    ASSERT_TRUE(!result4.empty());
}
