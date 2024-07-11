#pragma once

#include <string_view>
#include "faker-cxx/export.h"

namespace faker::food
{
    /**
     * @brief Returns a random alcoholic beverage name.
     *
     * @returns Alcoholic beverage.
     *
     * @code
     * faker::food::alcoholicBeverage() // "champain"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view alcoholicBeverage();

    /**
     * @brief Returns a random grain measurement.
     *
     * @returns Grain.
     *
     * @code
     * faker::food::grain() // "1 Lt"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view grain();

    /**
     * @brief Returns a random milk product's name.
     *
     * @returns Milk product.
     *
     * @code
     * faker::food::milkProduct() // "mozzarella"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view milkProduct();

    /**
     * @brief Returns a random fruit's name.
     *
     * @returns Fruit.
     *
     * @code
     * faker::food::fruit() // "apple"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view fruit();

    /**
     * @brief Returns a random meat's name.
     *
     * @returns Meat.
     *
     * @code
     * faker::food::meat() // "antrikot"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view meat();

    /**
     * @brief Returns a random seafood's name.
     *
     * @returns Seafood.
     *
     * @code
     * faker::food::seafood() // "lobster"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view seafood();

    /**
     * @brief Returns a random vegetable's name.
     *
     * @returns Vegetable.
     *
     * @code
     * faker::food::vegetable() // "watermelon"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view vegetable();

    /**
     * @brief Returns a random oil's name.
     *
     * @returns Oil.
     *
     * @code
     * faker::food::oil() // "olive oil"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view oil();

    /**
     * @brief Returns a random nut's name.
     *
     * @returns Nuts.
     *
     * @code
     * faker::food::nut() // "walnut"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view nut();

    /**
     * @brief Returns a random seed's name.
     *
     * @returns Seed.
     *
     * @code
     * faker::food::seed() // "mozzarella"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view seed();

    /**
     * @brief Returns a random sugar product's name.
     *
     * @returns Sugar product.
     *
     * @code
     * faker::food::sugarProduct() // "honey harmony"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view sugarProduct();

    /**
     * @brief Returns a random non-alcoholic beverage's name.
     *
     * @returns Non-alcoholic Beverage.
     *
     * @code
     * faker::food::nonalcoholicBeverage() // "water"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view nonalcoholicBeverage();

    /**
     * @brief Returns a random dish's name.
     *
     * @returns Dish.
     *
     * @code
     * faker::food::dishName() // "beef wellington"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view dishName();

    /**
     * @brief Returns a random food categories' name.
     *
     * @returns Food Category.
     *
     * @code
     * faker::food::foodCategory() // "Dairy"
     * @endcode
     */
    FAKER_CXX_EXPORT std::string_view foodCategory();
}
