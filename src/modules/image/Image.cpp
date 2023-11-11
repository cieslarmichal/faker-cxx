#include "faker-cxx/Image.h"

#include "faker-cxx/Number.h"
#include "fmt/format.h"

namespace faker
{

std::string Image::imageUrl(unsigned int width, unsigned int height, std::optional<ImageCategory> category)
{
    const std::string image_category =
        category.has_value() ? fmt::format("/{}", imageCategoryString.at(category.value())) : "";
    return fmt::format("https://loremflickr.com/{}/{}{}", width, height, image_category);
}

std::string Image::githubAvatarUrl()
{
    return fmt::format("https://avatars.githubusercontent.com/u/{}", Number::integer<int>(100000000));
}

std::string Image::dimensions()
{
    return fmt::format("{}x{}", Number::integer<int>(1, 32720), Number::integer<int>(1, 17280));
}

}
