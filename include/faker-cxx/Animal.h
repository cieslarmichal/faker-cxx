#pragma once

#include <string_view>

namespace faker
{
class Animal
{
public:
    /**
     * @brief Returns a random species of bear.
     *
     * @returns Species of bear.
     *
     * @code
     * Animal::bear() // "Polar bear"
     * @endcode
     */
    static std::string_view bear();

    /**
     * @brief Returns a random species of bird.
     *
     * @returns Species of bird.
     *
     * @code
     * Animal::bird() // "Black-bellied Whistling-Duck"
     * @endcode
     */
    static std::string_view bird();

    /**
     * @brief Returns a random species of cat.
     *
     * @returns Species of cat.
     *
     * @code
     * Animal::cat() // "Chartreux"
     * @endcode
     */
    static std::string_view cat();

    /**
     * @brief Returns a random species of cetacean.
     *
     * @returns Species of cetacean.
     *
     * @code
     * Animal::cetacean() // "Blue Whale"
     * @endcode
     */
    static std::string_view cetacean();

    /**
     * @brief Returns a random species of cow.
     *
     * @returns Species of cow.
     *
     * @code
     * Animal::cow() // "American Angus"
     * @endcode
     */
    static std::string_view cow();

    /**
     * @brief Returns a random species of crocodilia.
     *
     * @returns Species of crocodilia.
     *
     * @code
     * Animal::crocodile() // "Dwarf Crocodile"
     * @endcode
     */
    static std::string_view crocodile();

    /**
     * @brief Returns a random species of dog.
     *
     * @returns Species of dog.
     *
     * @code
     * Animal::dog() // "Shiba Inu"
     * @endcode
     */
    static std::string_view dog();

    /**
     * @brief Returns a random species of fish.
     *
     * @returns Species of fish.
     *
     * @code
     * Animal::fish() // "Silver carp"
     * @endcode
     */
    static std::string_view fish();

    /**
     * @brief Returns a random species of horse.
     *
     * @returns Species of horse.
     *
     * @code
     * Animal::horse() // "Fjord Horse"
     * @endcode
     */
    static std::string_view horse();

    /**
     * @brief Returns a random species of insect.
     *
     * @returns Species of insect.
     *
     * @code
     * Animal::insect() // "Bee"
     * @endcode
     */
    static std::string_view insect();

    /**
     * @brief Returns a random species of lion.
     *
     * @returns Species of lion.
     *
     * @code
     * Animal::lion() // "West African Lion"
     * @endcode
     */
    static std::string_view lion();

    /**
     * @brief Returns a random species of rabbit.
     *
     * @returns Species of rabbit.
     *
     * @code
     * Animal::rabbit() // "Californian"
     * @endcode
     */
    static std::string_view rabbit();

    /**
     * @brief Returns a random species of rodent.
     *
     * @returns Species of rodent.
     *
     * @code
     * Animal::rodent() // "Chinchilla"
     * @endcode
     */
    static std::string_view rodent();

    /**
     * @brief Returns a random species of snake.
     *
     * @returns Species of snake.
     *
     * @code
     * Animal::snake() // "Boa constrictor"
     * @endcode
     */
    static std::string_view snake();

    /**
     * @brief Returns a random type of animal.
     *
     * @returns Type of animal.
     *
     * @code
     * Animal::type() // "dog"
     * @endcode
     */
    static std::string_view type();
};
}
