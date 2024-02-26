#ifndef FAKER_FOOD_H
#define FAKER_FOOD_H

#include <string_view>

namespace faker::food {
/**
 * @brief Returns a random alcoholic beverage name.
 *
 * @returns Alcoholic beverage.
 *
 * @code
 * food::alcoholic_beverage() // "champain"
 * @endcode
 */
std::string_view alcoholic_beverage();

/**
 * @brief Returns a random grain measurement.
 *
 * @returns Grain.
 *
 * @code
 * food::grain() // "1 Lt"
 * @endcode
 */
std::string_view grain();

/**
 * @brief Returns a random milk product's name.
 *
 * @returns Milk product.
 *
 * @code
 * food::milk_product() // "mozzarella"
 * @endcode
 */
std::string_view milk_product();

/**
 * @brief Returns a random fruit's name.
 *
 * @returns Fruit.
 *
 * @code
 * food::fruit() // "apple"
 * @endcode
 */
std::string_view fruit();

/**
 * @brief Returns a random meat's name.
 *
 * @returns Meat.
 *
 * @code
 * food::meat() // "antrikot"
 * @endcode
 */
std::string_view meat();

/**
 * @brief Returns a random seafood's name.
 *
 * @returns Seafood.
 *
 * @code
 * food::seafood() // "lobster"
 * @endcode
 */
std::string_view seafood();

/**
 * @brief Returns a random vegetable's name.
 *
 * @returns Vegetable.
 *
 * @code
 * food::vegetable() // "watermelon"
 * @endcode
 */
std::string_view vegetable();

/**
 * @brief Returns a random oil's name.
 *
 * @returns Oil.
 *
 * @code
 * food::oil() // "olive oil"
 * @endcode
 */
std::string_view oil();

/**
 * @brief Returns a random nut's name.
 *
 * @returns Nuts.
 *
 * @code
 * food::nut() // "walnut"
 * @endcode
 */
std::string_view nut();

/**
 * @brief Returns a random seed's name.
 *
 * @returns Seed.
 *
 * @code
 * food::seed() // "mozzarella"
 * @endcode
 */
std::string_view seed();

/**
 * @brief Returns a random sugar product's name.
 *
 * @returns Sugar product.
 *
 * @code
 * food::sugar_product() // "honey harmony"
 * @endcode
 */
std::string_view sugar_product();

/**
 * @brief Returns a random non-alcoholic beverage's name.
 *
 * @returns Non-alcoholic Beverage.
 *
 * @code
 * food::non_alcoholic_beverage() // "water"
 * @endcode
 */
std::string_view non_alcoholic_beverage();

/**
 * @brief Returns a random dish's name.
 *
 * @returns Dish.
 *
 * @code
 * food::dish_name() // "beef wellington"
 * @endcode
 */
std::string_view dish_name();

/**
 * @brief Returns a random food categories' name.
 *
 * @returns food Category.
 *
 * @code
 * food::category() // "Dairy"
 * @endcode
 */
std::string_view category();
}

#endif