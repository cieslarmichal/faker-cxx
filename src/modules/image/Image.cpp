#include "faker-cxx/Image.h"

#include <map>

#include "../../common/FormatHelper.h"
#include "data/Type.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"

namespace faker
{
namespace
{
std::map<Image::ImageCategory, std::string> imageCategoryToLoremFlickrStringMapping = {
    {Image::ImageCategory::Animals, "animals"},   {Image::ImageCategory::Business, "business"},
    {Image::ImageCategory::Cats, "cats"},         {Image::ImageCategory::City, "city"},
    {Image::ImageCategory::Food, "food"},         {Image::ImageCategory::Nightlife, "nightlife"},
    {Image::ImageCategory::Fashion, "fashion"},   {Image::ImageCategory::People, "people"},
    {Image::ImageCategory::Nature, "nature"},     {Image::ImageCategory::Sports, "sports"},
    {Image::ImageCategory::Technics, "technics"}, {Image::ImageCategory::Transport, "transport"},
};
}

std::string Image::imageUrl(unsigned int width, unsigned int height, std::optional<ImageCategory> category)
{
    const std::string image_category =
        category.has_value() ?
            FormatHelper::format("/{}", imageCategoryToLoremFlickrStringMapping.at(category.value())) :
            "";

    return FormatHelper::format("https://loremflickr.com/{}/{}{}", width, height, image_category);
}

std::string Image::githubAvatarUrl()
{
    return FormatHelper::format("https://avatars.githubusercontent.com/u/{}", Number::integer<int>(100000000));
}

std::string Image::dimensions()
{
    return FormatHelper::format("{}x{}", Number::integer<int>(1, 32720), Number::integer<int>(1, 17280));
}

std::string Image::type()
{
    return Helper::arrayElement(imageTypes);
}
}
