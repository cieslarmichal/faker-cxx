#include "faker-cxx/image.h"

#include <array>
#include <faker-cxx/datatype.h>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>

#include "common/format_helper.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"

namespace faker::image
{
namespace
{
const std::array<std::string_view, 15> imageTypes = {"ai",  "bmp", "eps", "gif", "heif", "indd", "jpeg", "jpg",
                                                     "pdf", "png", "psd", "raw", "svg",  "tiff", "webp"};

std::unordered_map<ImageCategory, std::string> imageCategoryToLoremFlickrStringMapping = {
    {ImageCategory::Animals, "animals"}, {ImageCategory::Business, "business"}, {ImageCategory::Cats, "cats"},
    {ImageCategory::City, "city"},       {ImageCategory::Food, "food"},         {ImageCategory::Nightlife, "nightlife"},
    {ImageCategory::Fashion, "fashion"}, {ImageCategory::People, "people"},     {ImageCategory::Nature, "nature"},
    {ImageCategory::Sports, "sports"},   {ImageCategory::Technics, "technics"}, {ImageCategory::Transport, "transport"},
};
}

std::string imageUrl(unsigned width, unsigned height)
{
    if (faker::datatype::boolean(0.5))
    {
        return urlLoremFlickr();
    }
    else
        return urlPicsumPhotos();
}

std::string urlLoremFlickr(unsigned int width, unsigned int height, std::optional<ImageCategory> category)
{
    const std::string image_category =
        category.has_value() ? common::format("/{}", imageCategoryToLoremFlickrStringMapping.at(category.value())) : "";

    return common::format("https://loremflickr.com/{}/{}{}", width, height, image_category);
}

std::string urlPicsumPhotos(unsigned width, unsigned height, const std::optional<bool> greyscale,
                            const std::optional<int> blur)
{
    std::string url = common::format("https://picsum.photos/{}/{}", width, height);
    std::string params;

    params += (greyscale.has_value() && greyscale.value()) ? "greyscale" : "";

    if (blur.has_value())
    {
        if (blur.value() < 1 || blur.value() > 10)
            return common::format("{}", "Error: blur must be between 1 and 10.");
        if (!params.empty())
            params += "&";
        params += common::format("blur={}", blur.value());
    }
    if (!params.empty())
    {
        url = common::format("{}?{}", url, params);
    }
    return common::format("{}", url);
}

std::string githubAvatarUrl()
{
    return common::format("https://avatars.githubusercontent.com/u/{}", number::integer<int>(100000000));
}

std::string dimensions()
{
    return common::format("{}x{}", number::integer<int>(1, 32720), number::integer<int>(1, 17280));
}

std::string_view type()
{
    return helper::randomElement(imageTypes);
}
}
