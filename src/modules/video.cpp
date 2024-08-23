#include "faker-cxx/video.h"

#include <string_view>

#include "faker-cxx/helper.h"
#include "video_data.h"

namespace faker::video
{
std::string_view formatName()
{
    return helper::randomElement(formatNames);
}

std::string_view fileExtension()
{
    return helper::randomElement(fileExtensions);
}

std::string_view videoCodec()
{
    return helper::randomElement(videoCodecs);
}

std::string_view audioCodec()
{
    return helper::randomElement(audioCodecs);
}

std::string_view resolution()
{
    return helper::randomElement(resolutions);
}

std::string_view aspectRatio()
{
    return helper::randomElement(aspectRatios);
}

std::string_view videoUrl()
{
    return helper::randomElement(videoUrls);
}
}