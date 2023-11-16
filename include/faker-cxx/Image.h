#pragma once

#include <map>
#include <optional>
#include <string>

#include "types/ImageCategory.h"

namespace faker
{
class Image
{
public:
    /**
     * @brief Generates a real image url with `https://loremflickr.com/`.
     *
     * @param width The width of the image. Defaults to `640`.
     * @param height The height of the image. Defaults to `480`.
     * @param category The optional category of generated real image.
     *
     * @returns Random real image url from external service.
     *
     * @code
     * Internet::imageUrl() // "https://loremflickr.com/640/480"
     * Internet::imageUrl(800, 600) // "https://loremflickr.com/800/600"
     * Internet::imageUrl(800, 600, ImageCategory::animals) // "https://loremflickr.com/800/600/animals"
     * @endcode
     */
    static std::string imageUrl(unsigned width = 640, unsigned height = 480,
                                std::optional<ImageCategory> category = std::nullopt);

    /**
     * @brief Generates a random avatar from GitHub.
     *
     * @returns Url to github avatar.
     *
     * @code
     * Internet::githubAvatarUrl() // "https://avatars.githubusercontent.com/u/9716558"
     * @endcode
     */
    static std::string githubAvatarUrl();

    /**
     * @brief Generates a random image dimensions.
     *
     * @returns Random image dimensions.
     *
     * @code
     * Internet::dimensions() // "1920x1080"
     * @endcode
     */
    static std::string dimensions();
};
}
