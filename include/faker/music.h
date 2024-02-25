#ifndef FAKER_MUSIC_H
#define FAKER_MUSIC_H

#include <string_view>

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
std::string_view artist();

/**
 * @brief Returns a random music genre.
 *
 * @returns music genre.
 *
 * @code
 * music::genre() // "Rock"
 * @endcode
 */
std::string_view genre();

/**
 * @brief Returns a random song name.
 *
 * @returns Song name.
 *
 * @code
 * music::songName() // "Light My Fire"
 * @endcode
 */
std::string_view songName();
}

#endif