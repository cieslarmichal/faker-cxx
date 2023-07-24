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



