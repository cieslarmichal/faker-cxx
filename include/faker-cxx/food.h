#pragma once

#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"

namespace faker::food
{
/**
 * @brief Returns a random alcoholic beverage name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Alcoholic beverage.
 *
 * @code
 * faker::food::alcoholicBeverage() // "champain"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view alcoholicBeverage(Locale locale = Locale::en_US);

/**
 * @brief Returns a random grain measurement.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Grain.
 *
 * @code
 * faker::food::grain() // "1 Lt"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view grain(Locale locale = Locale::en_US);

/**
 * @brief Returns a random milk product's name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Milk product.
 *
 * @code
 * faker::food::milkProduct() // "mozzarella"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view milkProduct(Locale locale = Locale::en_US);

/**
 * @brief Returns a random fruit's name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Fruit.
 *
 * @code
 * faker::food::fruit() // "apple"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view fruit(Locale locale = Locale::en_US);

/**
 * @brief Returns a random meat's name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Meat.
 *
 * @code
 * faker::food::meat() // "antrikot"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view meat(Locale locale = Locale::en_US);

/**
 * @brief Returns a random seafood's name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Seafood.
 *
 * @code
 * faker::food::seafood() // "lobster"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view seafood(Locale locale = Locale::en_US);

/**
 * @brief Returns a random vegetable's name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Vegetable.
 *
 * @code
 * faker::food::vegetable() // "watermelon"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view vegetable(Locale locale = Locale::en_US);

/**
 * @brief Returns a random oil's name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Oil.
 *
 * @code
 * faker::food::oil() // "olive oil"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view oil(Locale locale = Locale::en_US);

/**
 * @brief Returns a random nut's name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Nuts.
 *
 * @code
 * faker::food::nut() // "walnut"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view nut(Locale locale = Locale::en_US);

/**
 * @brief Returns a random seed's name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Seed.
 *
 * @code
 * faker::food::seed() // "mozzarella"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view seed(Locale locale = Locale::en_US);

/**
 * @brief Returns a random sugar product's name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Sugar product.
 *
 * @code
 * faker::food::sugarProduct() // "honey harmony"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view sugarProduct(Locale locale = Locale::en_US);

/**
 * @brief Returns a random non-alcoholic beverage's name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Non-alcoholic Beverage.
 *
 * @code
 * faker::food::nonalcoholicBeverage() // "water"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view nonalcoholicBeverage(Locale locale = Locale::en_US);

/**
 * @brief Returns a random dish's name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Dish.
 *
 * @code
 * faker::food::dishName() // "beef wellington"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view dishName(Locale locale = Locale::en_US);

/**
 * @brief Returns a random food categories' name.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns Food Category.
 *
 * @code
 * faker::food::foodCategory() // "Dairy"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view foodCategory(Locale locale = Locale::en_US);
}
