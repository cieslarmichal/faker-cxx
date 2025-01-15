#include "faker-cxx/image.h"

#include <array>
#include <faker-cxx/datatype.h>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <sstream>
#include "common/format_helper.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "faker-cxx/base64.h"

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

int randomInt(int min, int max) {
    return number::integer(min, max);
}


std::string randomColor() {
    return "rgb(" + std::to_string(randomInt(0, 255)) + "," +
           std::to_string(randomInt(0, 255)) + "," +
           std::to_string(randomInt(0, 255)) + ")";
}

}

std::string imageUrl(unsigned width, unsigned height)
{
    if (faker::datatype::boolean(0.5))
    {
        return urlLoremFlickr(width, height);
    }

    return urlPicsumPhotos(width, height);
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
        {
            throw std::invalid_argument("Blur must be between 1 and 10");
        }

        if (!params.empty())
        {
            params += "&";
        }

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

std::string dataUri(unsigned width, unsigned height, const std::string &color, const std::string &type) {
    std::ostringstream svgStream;
    svgStream << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" baseProfile=\"full\" "
              << "width=\"" << width << "\" height=\"" << height << "\">"
              << "<rect width=\"100%\" height=\"100%\" fill=\"" << color << "\"/>"
              << "<text x=\"" << width / 2 << "\" y=\"" << height / 2 
              << "\" font-size=\"20\" alignment-baseline=\"middle\" text-anchor=\"middle\" fill=\"white\">"
              << width << "x" << height << "</text></svg>";

    std::string svgString = svgStream.str();

    if (type == "svg-uri") {
        return common::format("data:image/svg+xml;charset=UTF-8,{}", svgString);
    } else if (type == "svg-base64") {
        return "data:image/svg+xml;base64," + base64::encode(svgString); 
    } else {
        throw std::invalid_argument("Invalid type specified. Use 'svg-uri' or 'svg-base64'.");
    }
}
}
