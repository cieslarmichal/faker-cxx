#ifndef FAKER_IMAGE_H
#define FAKER_IMAGE_H

#include <optional>
#include <string>

namespace faker::image {
enum class ImageCategory {
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
 * image::image_url() // "https://loremflickr.com/640/480"
 * image::image_url(800, 600) // "https://loremflickr.com/800/600"
 * image::image_url(800, 600, ImageCategory::Animals) //
 * "https://loremflickr.com/800/600/animals"
 * @endcode
 */
std::string image_url(unsigned width = 640, unsigned height = 480,
    std::optional<ImageCategory> category = std::nullopt);

/**
 * @brief Generates a random avatar from GitHub.
 *
 * @returns Url to github avatar.
 *
 * @code
 * image::github_avatar_url() // "https://avatars.githubusercontent.com/u/9716558"
 * @endcode
 */
std::string github_avatar_url();

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

#endif