#pragma once

#include <optional>
#include <string_view>

#include "faker-cxx/export.h"

namespace faker::image
{
enum class ImageCategory
{
    Animals,
    Business,
    Cats,
    City,
    Food,
    Nightlife,
    Fashion,
    People,
    Nature,
    Sports,
    Technics,
    Transport
};

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
 * faker::image::imageUrl() // "https://loremflickr.com/640/480"
 * faker::image::imageUrl(800, 600) // "https://loremflickr.com/800/600"
 * faker::image::imageUrl(800, 600, ImageCategory::Animals) // "https://loremflickr.com/800/600/animals"
 * @endcode
 */
FAKER_CXX_EXPORT std::string imageUrl(unsigned width = 640, unsigned height = 480,
                                      std::optional<ImageCategory> category = std::nullopt);

/**
 * @brief Generates a random avatar from GitHub.
 *
 * @returns Url to github avatar.
 *
 * @code
 * faker::image::githubAvatarUrl() // "https://avatars.githubusercontent.com/u/9716558"
 * @endcode
 */
FAKER_CXX_EXPORT std::string githubAvatarUrl();

/**
 * @brief Generates a random image dimensions.
 *
 * @returns Random image dimensions.
 *
 * @code
 * faker::image::dimensions() // "1920x1080"
 * @endcode
 */
FAKER_CXX_EXPORT std::string dimensions();

/**
 * @brief Generates a random type of image.
 *
 * @returns Type of image.
 *
 * @code
 * faker::image::type() // "png"
 */
FAKER_CXX_EXPORT std::string_view type();
}
