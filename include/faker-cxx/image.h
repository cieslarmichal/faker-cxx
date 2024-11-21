#pragma once

#include <optional>
#include <string>
#include <string_view>

#include "faker-cxx/export.h"

/**
 * @brief Namespace for image-related functionalities.
 */
namespace faker::image {

/**
 * @brief Categories for image generation.
 */
enum class ImageCategory {
    Animals,    ///< Images related to animals.
    Business,   ///< Images related to business.
    Cats,       ///< Images of cats.
    City,       ///< Images of cityscapes.
    Food,       ///< Images of food items.
    Nightlife,  ///< Images of nightlife scenes.
    Fashion,    ///< Images related to fashion.
    People,     ///< Images of people.
    Nature,     ///< Images of nature.
    Sports,     ///< Images related to sports.
    Technics,   ///< Images of technical items.
    Transport   ///< Images of transport and vehicles.
};

/**
 * @brief Generates a random image URL.
 * 
 * This function generates a random image URL using `loremflickr.com` with
 * the given width, height, and optional category.
 * 
 * @param width The width of the image. Default is 640.
 * @param height The height of the image. Default is 480.
 * @param category The optional category of the image.
 * @return std::string The generated image URL.
 */
FAKER_CXX_EXPORT std::string imageUrl(unsigned width = 640, unsigned height = 480,
                                      std::optional<ImageCategory> category = std::nullopt);

/**
 * @brief Generates a random GitHub avatar URL.
 * 
 * @return std::string A URL to a random GitHub avatar.
 */
FAKER_CXX_EXPORT std::string githubAvatarUrl();

/**
 * @brief Generates random image dimensions.
 * 
 * @return std::string A string representing the dimensions (e.g., "1920x1080").
 */
FAKER_CXX_EXPORT std::string dimensions();

/**
 * @brief Generates a random image type.
 * 
 * @return std::string_view The type of the image (e.g., "png", "jpg").
 */
FAKER_CXX_EXPORT std::string_view type();

} // namespace faker::image
