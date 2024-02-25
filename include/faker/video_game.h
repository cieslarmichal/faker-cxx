#ifndef FAKER_VIDEO_GAME_H
#define FAKER_VIDEO_GAME_H

#include <string>

namespace faker::video_game {
/**
 * @brief Returns a random video game name.
 *
 * @returns Video game name.
 *
 * @code
 * video_game::gameTitle() // "Rayman Arena"
 * @endcode
 */
std::string gameTitle();

/**
 * @brief Returns a random video game genre.
 *
 * @returns Video game genre.
 *
 * @code
 * video_game::genre() // "Platformer"
 * @endcode
 */
std::string genre();

/**
 * @brief Returns a random video game platform.
 *
 * @returns Platform.
 *
 * @code
 * video_game::platform() // "Playstation 5"
 * @endcode
 */
std::string platform();

/**
 * @brief Returns a random video game studio name.
 *
 * @returns Studio name.
 *
 * @code
 * video_game::studioName() // "Activision Blizzard"
 * @endcode
 */
std::string studioName();
}

#endif