#include <algorithm>
#include <string_view>

#include "gtest/gtest.h"

#include "faker-cxx/video.h"
#include "video_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::video;

class VideoTest : public Test
{
public:
};

TEST_F(VideoTest, shouldGenerateFormatName)
{
    const auto generatedFormatName = formatName();

    ASSERT_TRUE(std::ranges::any_of(formatNames, [generatedFormatName](const std::string_view& formatName)
                                    { return formatName == generatedFormatName; }));
}

TEST_F(VideoTest, shouldGenerateFileExtension)
{
    const auto generatedFileExtension = fileExtension();

    ASSERT_TRUE(std::ranges::any_of(fileExtensions, [generatedFileExtension](const std::string_view& fileExtension)
                                    { return fileExtension == generatedFileExtension; }));
}

TEST_F(VideoTest, shouldGenerateVideoCodec)
{
    const auto generatedVideoCodec = videoCodec();

    ASSERT_TRUE(std::ranges::any_of(videoCodecs, [generatedVideoCodec](const std::string_view& videoCodec)
                                    { return videoCodec == generatedVideoCodec; }));
}

TEST_F(VideoTest, shouldGeneratedAudioCodec)
{
    const auto generatedAudioCodec = audioCodec();

    ASSERT_TRUE(std::ranges::any_of(audioCodecs, [generatedAudioCodec](const std::string_view& audioCodec)
                                    { return audioCodec == generatedAudioCodec; }));
}

TEST_F(VideoTest, shouldGenerateResolution)
{
    const auto generatedResolution = resolution();

    ASSERT_TRUE(std::ranges::any_of(resolutions, [generatedResolution](const std::string_view& resolution)
                                    { return resolution == generatedResolution; }));
}

TEST_F(VideoTest, shouldGenerateAspectRatio)
{
    const auto generatedAspectRatio = aspectRatio();

    ASSERT_TRUE(std::ranges::any_of(aspectRatios, [generatedAspectRatio](const std::string_view& aspectRatio)
                                    { return aspectRatio == generatedAspectRatio; }));
}

TEST_F(VideoTest, shouldGenerateVideoUrl)
{
    const auto generatedVideoUrl = videoUrl();

    ASSERT_TRUE(std::ranges::any_of(videoUrls, [generatedVideoUrl](const std::string_view& videoUrl)
                                    { return videoUrl == generatedVideoUrl; }));
}