#pragma once

#include <string>

namespace faker
{
class Music
{
public:
    /**
     * @brief Returns a random artist.
     *
     * @returns Artist.
     *
     * @code
     * Music::artist() // "Nirvana"
     * @endcode
     */
    static std::string artist();

    /**
     * @brief Returns a random music genre.
     *
     * @returns Music genre.
     *
     * @code
     * Music::genre() // "Rock"
     * @endcode
     */
    static std::string genre();

    /**
     * @brief Returns a random song name.
     *
     * @returns Song name.
     *
     * @code
     * Music::songName() // "Light My Fire"
     * @endcode
     */
    static std::string songName();
};
}
