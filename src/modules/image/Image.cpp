#include "faker-cxx/Image.h"

#include "faker-cxx/Number.h"
#include "../../common/Format.h"
namespace faker
{
namespace
{
std::map<faker::ImageCategory, std::string> imageCategoryToLoremFlickrStringMapping = {
    {faker::ImageCategory::Animals, "animals"},   {faker::ImageCategory::Business, "business"},
    {faker::ImageCategory::Cats, "cats"},         {faker::ImageCategory::City, "city"},
    {faker::ImageCategory::Food, "food"},         {faker::ImageCategory::Nightlife, "nightlife"},
    {faker::ImageCategory::Fashion, "fashion"},   {faker::ImageCategory::People, "people"},
    {faker::ImageCategory::Nature, "nature"},     {faker::ImageCategory::Sports, "sports"},
    {faker::ImageCategory::Technics, "technics"}, {faker::ImageCategory::Transport, "transport"},
};
}

std::string Image::imageUrl(unsigned int width, unsigned int height, std::optional<ImageCategory> category)
{
    const std::string image_category =
        category.has_value() ? Format::format("/{}", imageCategoryToLoremFlickrStringMapping.at(category.value())) : "";
    return Format::format("https://loremflickr.com/{}/{}{}", width, height, image_category);
}

std::string Image::githubAvatarUrl()
{
    return Format::format("https://avatars.githubusercontent.com/u/{}", Number::integer<int>(100000000));
}

std::string Image::dimensions()
{
    return Format::format("{}x{}", Number::integer<int>(1, 32720), Number::integer<int>(1, 17280));
}

}
