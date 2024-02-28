#include "../common/formatter.h"
#include "../common/random.h"
#include "image_data.h"
#include <faker/image.h>
#include <faker/number.h>

namespace faker::image {

std::string image_url(
    unsigned int width, unsigned int height, std::optional<image_category> category)
{
    std::string_view image_category;

    if (category.has_value()) {
        switch (*category) {
        case image_category::animals:
            image_category = "/animals";
            break;
        case image_category::business:
            image_category = "/business";
            break;
        case image_category::cats:
            image_category = "/cats";
            break;
        case image_category::city:
            image_category = "/city";
            break;
        case image_category::food:
            image_category = "/food";
            break;
        case image_category::nightlife:
            image_category = "/nightlife";
            break;
        case image_category::fashion:
            image_category = "/fashion";
            break;
        case image_category::people:
            image_category = "/people";
            break;
        case image_category::nature:
            image_category = "/nature";
            break;
        case image_category::sports:
            image_category = "/sports";
            break;
        case image_category::technics:
            image_category = "/technics";
            break;
        case image_category::transport:
            image_category = "/transport";
            break;
        default:
            throw std::invalid_argument("Invalid image category");
        }
    }

    return utils::format("https://loremflickr.com/{}/{}{}", width, height, image_category);
}

std::string github_avatar_url()
{
    return utils::format("https://avatars.githubusercontent.com/u/{}", number::integer(100000000));
}

std::string dimensions()
{
    return utils::format("{}x{}", number::integer(1, 32720), number::integer(1, 17280));
}

std::string_view type() { return random::element(data::image_types); }
}
