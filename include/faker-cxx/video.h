#pragma once

#include <string_view>

#include "faker-cxx/export.h"

namespace faker::video
{
/**
 * @brief Returns a random format name .
 *
 * @returns Format name.
 *
 * @code
 * faker::video::formatName() // "Ogg Video"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view formatName();

/**
 * @brief Returns a random file extension.
 *
 * @returns File extension.
 *
 * @code
 * faker::video::fileExtension() // ".webm"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view fileExtension();

/**
 * @brief Returns a random video codec.
 *
 * @returns Video codec.
 *
 * @code
 * faker::video::videoCodec() // "VP8"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view videoCodec();

/**
 * @brief Returns a random audio codec.
 *
 * @returns Audio Codec.
 *
 * @code
 * faker::video::audioCodec() // "Vorbis"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view audioCodec();

/**
 * @brief Returns a random resolution.
 *
 * @returns Resolution.
 *
 * @code
 * faker::video::resolution() // "240p"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view resolution();

/**
 * @brief Returns a random aspect ratio.
 *
 * @returns Aspect Ratio.
 *
 * @code
 * faker::video::aspectRatio() // "16:9"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view aspectRatio();

/**
 * @brief Returns a random video Url.
 *
 * @returns Video Url.
 *
 * @code
 * faker::video::videoUrl() // "https://youtu.be/_7ONEaabK90"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view videoUrl();
}