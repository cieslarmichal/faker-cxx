#include "faker-cxx/Image.h"

#include <algorithm>
#include <string>

#include "gtest/gtest.h"

#include "../src/common/StringHelper.h"
#include "data/Type.h"

using namespace ::testing;
using namespace faker;

class ImageTest : public Test
{
public:
};

TEST_F(ImageTest, shouldGenerateImageUrlDefault)
{
    const auto imageUrl = Image::imageUrl();

    ASSERT_EQ(imageUrl, "https://loremflickr.com/640/480");
}

TEST_F(ImageTest, shouldGenerateImageUrl)
{
    const auto width = 800;
    const auto height = 600;

    const auto imageUrl = Image::imageUrl(width, height);

    ASSERT_EQ(imageUrl, "https://loremflickr.com/800/600");
}

TEST_F(ImageTest, shouldGenerateImageUrlCategory)
{
    const auto width = 800;
    const auto height = 600;
    const ImageCategory category = ImageCategory::Fashion;

    const auto imageUrl = Image::imageUrl(width, height, category);

    ASSERT_EQ(imageUrl, "https://loremflickr.com/800/600/fashion");
}

TEST_F(ImageTest, shouldGenerateGithubAvatarUrl)
{
    const auto githubAvatarUrl = Image::githubAvatarUrl();

    const std::string expectedGithubAvatarPrefix = "https://avatars.githubusercontent.com/u/";

    const auto userNumber = std::stoi(githubAvatarUrl.substr(expectedGithubAvatarPrefix.size()));

    ASSERT_TRUE(githubAvatarUrl.starts_with(expectedGithubAvatarPrefix));
    ASSERT_TRUE(userNumber >= 0 && userNumber <= 100000000);
}

TEST_F(ImageTest, shouldGenerateDimensions)
{
    const auto dimensions = Image::dimensions();

    std::vector<std::string> split_dimensions = StringHelper::split(dimensions, "x");

    auto width_dimension = std::stoi(split_dimensions[0]);
    ASSERT_TRUE(width_dimension >= 1 && width_dimension <= 32720);

    auto height_dimension = std::stoi(split_dimensions[1]);
    ASSERT_TRUE(height_dimension >= 1 && height_dimension <= 17280);
}

TEST_F(ImageTest, shouldGenerateType)
{
    const auto generatedType = Image::type();

    ASSERT_TRUE(
        std::ranges::any_of(imageTypes, [generatedType](const std::string& type) { return type == generatedType; }));
}