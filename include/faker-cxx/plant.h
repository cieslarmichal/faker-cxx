#pragma once

#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::plant
{
/**
 * @brief Returns a random species of tree.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of tree.
 *
 * @code
 * faker::plant::tree() // "Oak"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view tree(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of flower.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of flower.
 *
 * @code
 * faker::plant::flower() // "Rose"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view flower(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of shrub.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of shrub.
 *
 * @code
 * faker::plant::shrub() // "Azalea"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view shrub(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of grass.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of grass.
 *
 * @code
 * faker::plant::grass() // "Kentucky Bluegrass"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view grass(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of fern.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of fern.
 *
 * @code
 * faker::plant::fern() // "Maidenhair"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view fern(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of succulent.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of succulent.
 *
 * @code
 * faker::plant::succulent() // "Aloe Vera"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view succulent(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of vine.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of vine.
 *
 * @code
 * faker::plant::vine() // "Ivy"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view vine(Locale locale = Locale::en_US);

/**
 * @brief Returns a random type of plant.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Type of plant.
 *
 * @code
 * faker::plant::type() // "tree"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view plantType(Locale locale = Locale::en_US);
}
