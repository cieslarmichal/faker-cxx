#pragma once

#include <string_view>
#include "faker-cxx/Export.h"


namespace faker::videogame
{
    /**
     * @brief Returns a random video game name.
     *
     * @returns Video game name.
     *
     * @code
     * faker::videogame::gameTitle() // "Rayman Arena"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view gameTitle();

    /**
     * @brief Returns a random video game genre.
     *
     * @returns Video game genre.
     *
     * @code
     * faker::videogame::genre() // "Platformer"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view genre();

    /**
     * @brief Returns a random video game platform.
     *
     * @returns Platform.
     *
     * @code
     * faker::videogame::platform() // "Playstation 5"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view platform();

    /**
     * @brief Returns a random video game studio name.
     *
     * @returns Studio name.
     *
     * @code
     * faker::videogame::studioName() // "Activision Blizzard"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view studioName();
}
