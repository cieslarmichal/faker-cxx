#include <algorithm>
#include <array>
#include <string>
#include <string_view>

#include "gtest/gtest.h"

#include "common/string_helper.h"
#include "faker-cxx/image.h"
#include "faker-cxx/base64.h"

using namespace ::testing;
using namespace faker;
using namespace faker::image;

class ImageTest : public Test
{
public:
};

TEST_F(ImageTest, shouldGenerateRandomImageUrl)
{
    for (int i = 0; i < 10; ++i)
    {
        const auto generatedImageUrl = imageUrl();

        ASSERT_TRUE(generatedImageUrl.find("loremflickr") != std::string::npos ||
                    generatedImageUrl.find("picsum") != std::string::npos);
    }
}

TEST_F(ImageTest, shouldGenerateurlLoremFlickrDefault)
{
    const auto generatedImageUrl = urlLoremFlickr();

    ASSERT_EQ(generatedImageUrl, "https://loremflickr.com/640/480");
}

TEST_F(ImageTest, shouldGenerateImageUrl)
{
    const auto width = 800;
    const auto height = 600;

    const auto generatedImageUrl = urlLoremFlickr(width, height);

    ASSERT_EQ(generatedImageUrl, "https://loremflickr.com/800/600");
}

TEST_F(ImageTest, shouldGenerateurlLoremFlickrCategory)
{
    const auto width = 800;
    const auto height = 600;
    const auto category = ImageCategory::Fashion;

    const auto generatedImageUrl = urlLoremFlickr(width, height, category);

    ASSERT_EQ(generatedImageUrl, "https://loremflickr.com/800/600/fashion");
}

TEST_F(ImageTest, shouldGenerateImageUrlPicsumDefault)
{
    const auto generatedImageUrl = urlPicsumPhotos();

    ASSERT_EQ(generatedImageUrl, "https://picsum.photos/640/480");
}

TEST_F(ImageTest, shouldGenerateImageUrlPicsumPhotos)
{
    const auto width = 800;
    const auto height = 600;

    const auto generatedImageUrl = urlPicsumPhotos(width, height);

    ASSERT_EQ(generatedImageUrl, "https://picsum.photos/800/600");
}

TEST_F(ImageTest, shouldGenerateImageUrlPicsumPhotosGreyscale)
{
    const auto width = 800;
    const auto height = 600;
    const auto greyscale = true;

    const auto generatedImageUrl = urlPicsumPhotos(width, height, greyscale);

    ASSERT_EQ(generatedImageUrl, "https://picsum.photos/800/600?greyscale");
}

TEST_F(ImageTest, shouldGenerateImageUrlPicsumPhotosBlur)
{
    const auto width = 800;
    const auto height = 600;
    const auto greyscale = false;
    const auto blur = 5;

    const auto generatedImageUrl = urlPicsumPhotos(width, height, greyscale, blur);

    ASSERT_EQ(generatedImageUrl, "https://picsum.photos/800/600?blur=5");
}

TEST_F(ImageTest, shouldThrowErrorWhenBlurIsLessThan1)
{
    const auto width = 800;
    const auto height = 600;
    const auto greyscale = false;
    const auto blur = 0;

    ASSERT_THROW(urlPicsumPhotos(width, height, greyscale, blur), std::invalid_argument);
}

TEST_F(ImageTest, shouldThrowErrorWhenBlurIsGreaterThan10)
{
    const auto width = 800;
    const auto height = 600;
    const auto greyscale = false;
    const auto blur = 11;

    ASSERT_THROW(urlPicsumPhotos(width, height, greyscale, blur), std::invalid_argument);
}

TEST_F(ImageTest, shouldGenerateImageUrlPicsumPhotosBlurandGreyscale)
{
    const auto width = 800;
    const auto height = 600;
    const auto greyscale = true;
    const auto blur = 6;

    const auto generatedImageUrl = urlPicsumPhotos(width, height, greyscale, blur);

    ASSERT_EQ(generatedImageUrl, "https://picsum.photos/800/600?greyscale&blur=6");
}

TEST_F(ImageTest, shouldGenerateGithubAvatarUrl)
{
    const auto generatedGithubAvatarUrl = githubAvatarUrl();

    const std::string expectedGithubAvatarPrefix = "https://avatars.githubusercontent.com/u/";

    const auto userNumber = std::stoi(generatedGithubAvatarUrl.substr(expectedGithubAvatarPrefix.size()));

    ASSERT_TRUE(generatedGithubAvatarUrl.starts_with(expectedGithubAvatarPrefix));
    ASSERT_TRUE(userNumber >= 0 && userNumber <= 100000000);
}

TEST_F(ImageTest, shouldGenerateDimensions)
{
    const auto generatedDimensions = dimensions();

    const auto split_dimensions = common::split(generatedDimensions, "x");

    const auto width_dimension = std::stoi(split_dimensions[0]);

    ASSERT_TRUE(width_dimension >= 1 && width_dimension <= 32720);

    const auto height_dimension = std::stoi(split_dimensions[1]);

    ASSERT_TRUE(height_dimension >= 1 && height_dimension <= 17280);
}

TEST_F(ImageTest, shouldGenerateType)
{
    const std::array<std::string_view, 15> imageTypes = {"ai",  "bmp", "eps", "gif", "heif", "indd", "jpeg", "jpg",
                                                         "pdf", "png", "psd", "raw", "svg",  "tiff", "webp"};

    const auto generatedType = type();

    ASSERT_TRUE(std::ranges::any_of(imageTypes,
                                    [generatedType](const std::string_view& type) { return type == generatedType; }));
}

TEST_F(ImageTest, shouldGenerateDataUriSvgUri)
{
    const auto width = 100;
    const auto height = 100;
    const auto color = "red";
    const auto type = "svg-uri";

    const auto generatedDataUri = dataUri(width, height, color, type);

    ASSERT_TRUE(generatedDataUri.find("data:image/svg+xml;charset=UTF-8,") == 0);
    ASSERT_TRUE(generatedDataUri.find("<svg") != std::string::npos);
    ASSERT_TRUE(generatedDataUri.find("width=\"100\"") != std::string::npos);
    ASSERT_TRUE(generatedDataUri.find("height=\"100\"") != std::string::npos);
    ASSERT_TRUE(generatedDataUri.find("fill=\"red\"") != std::string::npos);
}

TEST_F(ImageTest, shouldGenerateDataUriSvgBase64)
{
    const auto width = 100;
    const auto height = 100;
    const auto color = "red";
    const auto type = "svg-base64";

    const auto generatedDataUri = dataUri(width, height, color, type);

    ASSERT_TRUE(generatedDataUri.find("data:image/svg+xml;base64,") == 0);

    const auto base64Data = generatedDataUri.substr(std::string("data:image/svg+xml;base64,").length());
    const auto decodedData = base64::decode(base64Data.data(), base64Data.size());

    ASSERT_TRUE(decodedData.find("<svg") != std::string::npos);
    ASSERT_TRUE(decodedData.find("width=\"100\"") != std::string::npos);
    ASSERT_TRUE(decodedData.find("height=\"100\"") != std::string::npos);
    ASSERT_TRUE(decodedData.find("fill=\"red\"") != std::string::npos);
}

TEST_F(ImageTest, shouldThrowErrorForInvalidDataUriType)
{
    const auto width = 100;
    const auto height = 100;
    const auto color = "red";
    const auto type = "invalid-type";

    ASSERT_THROW(dataUri(width, height, color, type), std::invalid_argument);
}