#pragma once

#include <string_view>

namespace faker::animal
{
/**
 * @brief Returns a random species of bear.
 *
 * @returns Species of bear.
 *
 * @code
 * animal::bear() // "Polar bear"
 * @endcode
 */
std::string_view bear();

/**
 * @brief Returns a random species of bird.
 *
 * @returns Species of bird.
 *
 * @code
 * animal::bird() // "Black-bellied Whistling-Duck"
 * @endcode
 */
std::string_view bird();

/**
 * @brief Returns a random species of cat.
 *
 * @returns Species of cat.
 *
 * @code
 * animal::cat() // "Chartreux"
 * @endcode
 */
std::string_view cat();

/**
 * @brief Returns a random species of cetacean.
 *
 * @returns Species of cetacean.
 *
 * @code
 * animal::cetacean() // "Blue Whale"
 * @endcode
 */
std::string_view cetacean();

/**
 * @brief Returns a random species of cow.
 *
 * @returns Species of cow.
 *
 * @code
 * animal::cow() // "American Angus"
 * @endcode
 */
std::string_view cow();

/**
 * @brief Returns a random species of crocodilia.
 *
 * @returns Species of crocodilia.
 *
 * @code
 * animal::crocodile() // "Dwarf Crocodile"
 * @endcode
 */
std::string_view crocodile();

/**
 * @brief Returns a random species of dog.
 *
 * @returns Species of dog.
 *
 * @code
 * animal::dog() // "Shiba Inu"
 * @endcode
 */
std::string_view dog();

/**
 * @brief Returns a random species of fish.
 *
 * @returns Species of fish.
 *
 * @code
 * animal::fish() // "Silver carp"
 * @endcode
 */
std::string_view fish();

/**
 * @brief Returns a random species of horse.
 *
 * @returns Species of horse.
 *
 * @code
 * animal::horse() // "Fjord Horse"
 * @endcode
 */
std::string_view horse();

/**
 * @brief Returns a random species of insect.
 *
 * @returns Species of insect.
 *
 * @code
 * animal::insect() // "Bee"
 * @endcode
 */
std::string_view insect();

/**
 * @brief Returns a random species of lion.
 *
 * @returns Species of lion.
 *
 * @code
 * animal::lion() // "West African Lion"
 * @endcode
 */
std::string_view lion();

/**
 * @brief Returns a random species of rabbit.
 *
 * @returns Species of rabbit.
 *
 * @code
 * animal::rabbit() // "Californian"
 * @endcode
 */
std::string_view rabbit();

/**
 * @brief Returns a random species of rodent.
 *
 * @returns Species of rodent.
 *
 * @code
 * animal::rodent() // "Chinchilla"
 * @endcode
 */
std::string_view rodent();

/**
 * @brief Returns a random species of snake.
 *
 * @returns Species of snake.
 *
 * @code
 * animal::snake() // "Boa constrictor"
 * @endcode
 */
std::string_view snake();

/**
 * @brief Returns a random type of animal.
 *
 * @returns Type of animal.
 *
 * @code
 * animal::type() // "dog"
 * @endcode
 */
std::string_view type();
}
