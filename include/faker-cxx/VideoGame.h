#pragma once

#include <string_view>

namespace faker::videogame
{
    /**
     * @brief Returns a random video game name.
     *
     * @returns Video game name.
     *
     * @code
     * VideoGame::gameTitle() // "Rayman Arena"
     * @endcode
     */
    std::string_view gameTitle();

    /**
     * @brief Returns a random video game genre.
     *
     * @returns Video game genre.
     *
     * @code
     * VideoGame::genre() // "Platformer"
     * @endcode
     */
    std::string_view genre();

    /**
     * @brief Returns a random video game platform.
     *
     * @returns Platform.
     *
     * @code
     * VideoGame::platform() // "Playstation 5"
     * @endcode
     */
    std::string_view platform();

    /**
     * @brief Returns a random video game studio name.
     *
     * @returns Studio name.
     *
     * @code
     * VideoGame::studioName() // "Activision Blizzard"
     * @endcode
     */
    std::string_view studioName();
}
