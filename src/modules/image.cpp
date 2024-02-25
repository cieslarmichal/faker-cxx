#include "../common/format_helper.h"
#include "image_data.h"
#include <faker/helper.h>
#include <faker/image.h>
#include <faker/number.h>
#include <unordered_map>

namespace faker::image {
namespace {
    std::unordered_map<faker::ImageCategory, std::string_view>
        imageCategoryToLoremFlickrStringMapping = {
            { faker::ImageCategory::Animals, "animals" },
            { faker::ImageCategory::Business, "business" },
            { faker::ImageCategory::Cats, "cats" },
            { faker::ImageCategory::City, "city" },
            { faker::ImageCategory::Food, "food" },
            { faker::ImageCategory::Nightlife, "nightlife" },
            { faker::ImageCategory::Fashion, "fashion" },
            { faker::ImageCategory::People, "people" },
            { faker::ImageCategory::Nature, "nature" },
            { faker::ImageCategory::Sports, "sports" },
            { faker::ImageCategory::Technics, "technics" },
            { faker::ImageCategory::Transport, "transport" },
        };
}

std::string imageUrl(unsigned int width, unsigned int height, std::optional<ImageCategory> category)
{
    const auto image_category = category.has_value()
        ? FormatHelper::format("/{}", imageCategoryToLoremFlickrStringMapping.at(category.value()))
        : "";

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
