#include "../test_helpers.h"
#include <common/string_helper.h>
#include <faker/image.h>
#include <modules/image_data.h>

using namespace faker;

TEST(ImageTest, shouldGenerateImageUrlDefault)
{
    auto imageUrl = image::image_url();

    ASSERT_EQ(imageUrl, "https://loremflickr.com/640/480");
}

TEST(ImageTest, shouldGenerateImageUrl)
{
    auto width = 800;
    auto height = 600;

    auto imageUrl = image::image_url(width, height);

    ASSERT_EQ(imageUrl, "https://loremflickr.com/800/600");
}

TEST(ImageTest, shouldGenerateImageUrlCategory)
{
    auto width = 800;
    auto height = 600;
    const image::ImageCategory category = image::ImageCategory::Fashion;

    auto imageUrl = image::image_url(width, height, category);

    ASSERT_EQ(imageUrl, "https://loremflickr.com/800/600/fashion");
}

TEST(ImageTest, shouldGenerateGithubAvatarUrl)
{
    auto githubAvatarUrl = image::github_avatar_url();

    const std::string expectedGithubAvatarPrefix = "https://avatars.githubusercontent.com/u/";

    auto userNumber = std::stoi(githubAvatarUrl.substr(expectedGithubAvatarPrefix.size()));

    FAKER_EXPECT_STRING_STARTS_WITH(githubAvatarUrl, expectedGithubAvatarPrefix);
    ASSERT_TRUE(userNumber >= 0 && userNumber <= 100000000);
}

TEST(ImageTest, shouldGenerateDimensions)
{
    auto dimensions = image::dimensions();

    std::vector<std::string_view> split_dimensions = utils::split(dimensions, "x");

    auto width_dimension = utils::to_int(split_dimensions[0]);
    ASSERT_TRUE(width_dimension >= 1 && width_dimension <= 32720);

    auto height_dimension = utils::to_int(split_dimensions[1]);
    ASSERT_TRUE(height_dimension >= 1 && height_dimension <= 17280);
}

TEST(ImageTest, shouldGenerateType)
{
    auto generatedType = image::type();

    FAKER_EXPECT_CONTAINER_CONTAINS(image::data::imageTypes, generatedType);
}