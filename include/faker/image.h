#pragma once

#include <faker/types/image_category.h>
#include <optional>
#include <string>

namespace faker::image {
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
 * image::imageUrl() // "https://loremflickr.com/640/480"
 * image::imageUrl(800, 600) // "https://loremflickr.com/800/600"
 * image::imageUrl(800, 600, ImageCategory::Animals) //
 * "https://loremflickr.com/800/600/animals"
 * @endcode
 */
std::string imageUrl(unsigned width = 640, unsigned height = 480,
    std::optional<ImageCategory> category = std::nullopt);

/**
 * @brief Generates a random avatar from GitHub.
 *
 * @returns Url to github avatar.
 *
 * @code
 * image::githubAvatarUrl() // "https://avatars.githubusercontent.com/u/9716558"
 * @endcode
 */
std::string githubAvatarUrl();

/**
 * @brief Generates a random image dimensions.
 *
 * @returns Random image dimensions.
 *
 * @code
 * image::dimensions() // "1920x1080"
 * @endcode
 */
std::string dimensions();

/**
 * @brief Generates a random type of image.
 *
 * @returns Type of image.
 *
 * @code
 * image::type() // "png"
 */
std::string_view type();
}
