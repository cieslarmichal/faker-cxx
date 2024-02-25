#pragma once

#include <string_view>

namespace faker::food {
/**
 * @brief Returns a random alcoholic beverage name.
 *
 * @returns Alcoholic beverage.
 *
 * @code
 * food::alcoholicBeverage() // "champain"
 * @endcode
 */
std::string_view alcoholicBeverage();

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
 * food::milkProduct() // "mozzarella"
 * @endcode
 */
std::string_view milkProduct();

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
 * food::sugarProduct() // "honey harmony"
 * @endcode
 */
std::string_view sugarProduct();

/**
 * @brief Returns a random non-alcoholic beverage's name.
 *
 * @returns Non-alcoholic Beverage.
 *
 * @code
 * food::nonalcoholicBeverage() // "water"
 * @endcode
 */
std::string_view nonalcoholicBeverage();

/**
 * @brief Returns a random dish's name.
 *
 * @returns Dish.
 *
 * @code
 * food::dishName() // "beef wellington"
 * @endcode
 */
std::string_view dishName();

/**
 * @brief Returns a random food categories' name.
 *
 * @returns food Category.
 *
 * @code
 * food::foodCategory() // "Dairy"
 * @endcode
 */
std::string_view foodCategory();
}
