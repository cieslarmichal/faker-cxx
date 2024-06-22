#pragma once

#include <string_view>

namespace faker::plant
{
/**
 * @brief Returns a random species of tree.
 *
 * @returns Species of tree.
 *
 * @code
 * Plant::tree() // "Oak"
 * @endcode
 */
std::string_view tree();

/**
 * @brief Returns a random species of flower.
 *
 * @returns Species of flower.
 *
 * @code
 * Plant::flower() // "Rose"
 * @endcode
 */
std::string_view flower();

/**
 * @brief Returns a random species of shrub.
 *
 * @returns Species of shrub.
 *
 * @code
 * Plant::shrub() // "Azalea"
 * @endcode
 */
std::string_view shrub();

/**
 * @brief Returns a random species of grass.
 *
 * @returns Species of grass.
 *
 * @code
 * Plant::grass() // "Kentucky Bluegrass"
 * @endcode
 */
std::string_view grass();

/**
 * @brief Returns a random species of fern.
 *
 * @returns Species of fern.
 *
 * @code
 * Plant::fern() // "Maidenhair"
 * @endcode
 */
std::string_view fern();

/**
 * @brief Returns a random species of succulent.
 *
 * @returns Species of succulent.
 *
 * @code
 * Plant::succulent() // "Aloe Vera"
 * @endcode
 */
std::string_view succulent();

/**
 * @brief Returns a random species of vine.
 *
 * @returns Species of vine.
 *
 * @code
 * Plant::vine() // "Ivy"
 * @endcode
 */
std::string_view vine();

/**
 * @brief Returns a random type of plant.
 *
 * @returns Type of plant.
 *
 * @code
 * Plant::type() // "tree"
 * @endcode
 */
std::string_view plantType();
}
