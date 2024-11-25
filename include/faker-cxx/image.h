#pragma once

#include <optional>
#include <string>
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
 * @brief Generates a random image url with `https://loremflickr.com/` or "https://picsum.photos".
 *
 * @param width The width of the image. Defaults to `640`.
 * @param height The height of the image. Defaults to `480`.
 *
 * @returns Random real image url from external service.
 *
 * @code
 * faker::image::imageUrl() // "https://loremflickr.com/640/480" or "https://picsum.photos/640/480"
 * @endcode
 */
FAKER_CXX_EXPORT std::string imageUrl(unsigned width = 640, unsigned height = 480);

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
 * faker::image::urlLoremFlickr() // "https://loremflickr.com/640/480"
 * faker::image::urlLoremFlickr(800, 600) // "https://loremflickr.com/800/600"
 * faker::image::urlLoremFlickr(800, 600, ImageCategory::Animals) // "https://loremflickr.com/800/600/animals"
 * @endcode
 */
FAKER_CXX_EXPORT std::string urlLoremFlickr(unsigned width = 640, unsigned height = 480,
                                            std::optional<ImageCategory> category = std::nullopt);

/**
 * @brief Generates a real image url with "https://picsum.photos" .
 *
 * @param width The width of the image. Defaults to `640`.
 * @param height The height of the image. Defaults to `480`.
 * @param greyscale The optional greyscale filter. True for apply or false for disabled
 * @param blur The optional blur effect between 1 and 10
 *
 * @returns Random real image url from external service
 *
 * @code
 * faker::image::urlPicsPhotos() // "https://picsum.photos/640/480"
 * faker::image::urlPicsPhotos(800,600,true) // "https://picsum.photos/800/600?grayscale
 * faker::image::urlPicsPhotos(800,600,false,5) // "https://picsum.photos/800/600?blur=5
 * faker::image::urlPicsPhotos(800,600,true,1) // "https://picsum.photos/800/600?grayscale&blur=1
 *@endcode
 */
FAKER_CXX_EXPORT std::string urlPicsumPhotos(unsigned width = 640, unsigned height = 480,
                                             std::optional<bool> greyscale = std::nullopt,
                                             std::optional<int> blur = std::nullopt);

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
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view type();
}
