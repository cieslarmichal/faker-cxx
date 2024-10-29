#pragma once

#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::animal
{
/**
 * @brief Returns a random species of bear.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of bear.
 *
 * @code
 * faker::animal::bear() // "Polar bear"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view bear(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of bird.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of bird.
 *
 * @code
 * faker::animal::bird() // "Black-bellied Whistling-Duck"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view bird(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of cat.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of cat.
 *
 * @code
 * faker::animal::cat() // "Chartreux"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view cat(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of cetacean.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of cetacean.
 *
 * @code
 * faker::animal::cetacean() // "Blue Whale"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view cetacean(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of cow.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of cow.
 *
 * @code
 * faker::animal::cow() // "American Angus"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view cow(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of crocodilia.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of crocodilia.
 *
 * @code
 * faker::animal::crocodile() // "Dwarf Crocodile"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view crocodile(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of dog.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of dog.
 *
 * @code
 * faker::animal::dog() // "Shiba Inu"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view dog(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of fish.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of fish.
 *
 * @code
 * faker::animal::fish() // "Silver carp"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view fish(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of horse.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of horse.
 *
 * @code
 * faker::animal::horse() // "Fjord Horse"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view horse(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of insect.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of insect.
 *
 * @code
 * faker::animal::insect() // "Bee"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view insect(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of lion.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of lion.
 *
 * @code
 * faker::animal::lion() // "West African Lion"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view lion(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of rabbit.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of rabbit.
 *
 * @code
 * faker::animal::rabbit() // "Californian"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view rabbit(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of rodent.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of rodent.
 *
 * @code
 * faker::animal::rodent() // "Chinchilla"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view rodent(Locale locale = Locale::en_US);

/**
 * @brief Returns a random species of snake.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Species of snake.
 *
 * @code
 * faker::animal::snake() // "Boa constrictor"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view snake(Locale locale = Locale::en_US);

/**
 * @brief Returns a random type of animal.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Type of animal.
 *
 * @code
 * faker::animal::type() // "dog"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view type(Locale locale = Locale::en_US);
}
