#include "../common/format_helper.h"
#include "image_data.h"
#include <faker/helper.h>
#include <faker/image.h>
#include <faker/number.h>

namespace faker::image {

std::string imageUrl(unsigned int width, unsigned int height, std::optional<ImageCategory> category)
{
    std::string_view image_category;

    if (category.has_value()) {
        switch (*category) {
        case ImageCategory::Animals:
            image_category = "/animals";
            break;
        case ImageCategory::Business:
            image_category = "/business";
            break;
        case ImageCategory::Cats:
            image_category = "/cats";
            break;
        case faker::ImageCategory::City:
            image_category = "/city";
            break;
        case faker::ImageCategory::Food:
            image_category = "/food";
            break;
        case faker::ImageCategory::Nightlife:
            image_category = "/nightlife";
            break;
        case faker::ImageCategory::Fashion:
            image_category = "/fashion";
            break;
        case faker::ImageCategory::People:
            image_category = "/people";
            break;
        case faker::ImageCategory::Nature:
            image_category = "/nature";
            break;
        case faker::ImageCategory::Sports:
            image_category = "/sports";
            break;
        case faker::ImageCategory::Technics:
            image_category = "/technics";
            break;
        case faker::ImageCategory::Transport:
            image_category = "/transport";
            break;
        default:
            throw std::invalid_argument("Invalid image category");
        }
    }

    return FormatHelper::format("https://loremflickr.com/{}/{}{}", width, height, image_category);
}

std::string githubAvatarUrl()
{
    return FormatHelper::format(
        "https://avatars.githubusercontent.com/u/{}", number::integer(100000000));
}

std::string dimensions()
{
    return FormatHelper::format("{}x{}", number::integer(1, 32720), number::integer(1, 17280));
}

std::string_view type() { return Helper::arrayElement(imageTypes); }
}
