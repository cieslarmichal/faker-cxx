#pragma once

#include <optional>
#include <string_view>

namespace faker
{
class Image
{
public:
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
     * Image::imageUrl() // "https://loremflickr.com/640/480"
     * Image::imageUrl(800, 600) // "https://loremflickr.com/800/600"
     * Image::imageUrl(800, 600, ImageCategory::Animals) // "https://loremflickr.com/800/600/animals"
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
     * Image::githubAvatarUrl() // "https://avatars.githubusercontent.com/u/9716558"
     * @endcode
     */
    static std::string githubAvatarUrl();

    /**
     * @brief Generates a random image dimensions.
     *
     * @returns Random image dimensions.
     *
     * @code
     * Image::dimensions() // "1920x1080"
     * @endcode
     */
    static std::string dimensions();

    /**
     * @brief Generates a random type of image.
     *
     * @returns Type of image.
     *
     * @code
     * Image::type() // "png"
     */
    static std::string_view type();
};
}
