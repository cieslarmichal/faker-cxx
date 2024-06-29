#pragma once

#include <string_view>
#include "faker-cxx/Export.h"

namespace faker::plant
{
/**
 * @brief Returns a random species of tree.
 *
 * @returns Species of tree.
 *
 * @code
 * faker::plant::tree() // "Oak"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view tree();

/**
 * @brief Returns a random species of flower.
 *
 * @returns Species of flower.
 *
 * @code
 * faker::plant::flower() // "Rose"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view flower();

/**
 * @brief Returns a random species of shrub.
 *
 * @returns Species of shrub.
 *
 * @code
 * faker::plant::shrub() // "Azalea"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view shrub();

/**
 * @brief Returns a random species of grass.
 *
 * @returns Species of grass.
 *
 * @code
 * faker::plant::grass() // "Kentucky Bluegrass"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view grass();

/**
 * @brief Returns a random species of fern.
 *
 * @returns Species of fern.
 *
 * @code
 * faker::plant::fern() // "Maidenhair"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view fern();

/**
 * @brief Returns a random species of succulent.
 *
 * @returns Species of succulent.
 *
 * @code
 * faker::plant::succulent() // "Aloe Vera"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view succulent();

/**
 * @brief Returns a random species of vine.
 *
 * @returns Species of vine.
 *
 * @code
 * faker::plant::vine() // "Ivy"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view vine();

/**
 * @brief Returns a random type of plant.
 *
 * @returns Type of plant.
 *
 * @code
 * faker::plant::type() // "tree"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view plantType();
}
