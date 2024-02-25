#pragma once

#include <string>

namespace faker::music {
/**
 * @brief Returns a random artist.
 *
 * @returns Artist.
 *
 * @code
 * music::artist() // "Nirvana"
 * @endcode
 */
std::string artist();

/**
 * @brief Returns a random music genre.
 *
 * @returns music genre.
 *
 * @code
 * music::genre() // "Rock"
 * @endcode
 */
std::string genre();

/**
 * @brief Returns a random song name.
 *
 * @returns Song name.
 *
 * @code
 * music::songName() // "Light My Fire"
 * @endcode
 */
std::string songName();
}
