#ifndef FAKER_VIDEO_GAME_H
#define FAKER_VIDEO_GAME_H

#include <string_view>

namespace faker::video_game {
/**
 * @brief Returns a random video game name.
 *
 * @returns Video game name.
 *
 * @code
 * video_game::title() // "Rayman Arena"
 * @endcode
 */
std::string_view title();

/**
 * @brief Returns a random video game genre.
 *
 * @returns Video game genre.
 *
 * @code
 * video_game::genre() // "Platformer"
 * @endcode
 */
std::string_view genre();

/**
 * @brief Returns a random video game platform.
 *
 * @returns Platform.
 *
 * @code
 * video_game::platform() // "Playstation 5"
 * @endcode
 */
std::string_view platform();

/**
 * @brief Returns a random video game studio name.
 *
 * @returns Studio name.
 *
 * @code
 * video_game::studio_name() // "Activision Blizzard"
 * @endcode
 */
std::string_view studio_name();
}

#endif