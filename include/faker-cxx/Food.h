#pragma once

#include <string_view>

namespace faker
{
class Food
{
public:
    /**
     * @brief Returns a random alcoholic beverage name.
     *
     * @returns Alcoholic beverage.
     *
     * @code
     * Food::alcoholicBeverage() // "champain"
     * @endcode
     */
    static std::string_view alcoholicBeverage();

    /**
     * @brief Returns a random grain measurement.
     *
     * @returns Grain.
     *
     * @code
     * Food::grain() // "1 Lt"
     * @endcode
     */
    static std::string_view grain();

    /**
     * @brief Returns a random milk product's name.
     *
     * @returns Milk product.
     *
     * @code
     * Food::milkProduct() // "mozzarella"
     * @endcode
     */
    static std::string_view milkProduct();

    /**
     * @brief Returns a random fruit's name.
     *
     * @returns Fruit.
     *
     * @code
     * Food::fruit() // "apple"
     * @endcode
     */
    static std::string_view fruit();

    /**
     * @brief Returns a random meat's name.
     *
     * @returns Meat.
     *
     * @code
     * Food::meat() // "antrikot"
     * @endcode
     */
    static std::string_view meat();

    /**
     * @brief Returns a random seafood's name.
     *
     * @returns Seafood.
     *
     * @code
     * Food::seafood() // "lobster"
     * @endcode
     */
    static std::string_view seafood();

    /**
     * @brief Returns a random vegetable's name.
     *
     * @returns Vegetable.
     *
     * @code
     * Food::vegetable() // "watermelon"
     * @endcode
     */
    static std::string_view vegetable();

    /**
     * @brief Returns a random oil's name.
     *
     * @returns Oil.
     *
     * @code
     * Food::oil() // "olive oil"
     * @endcode
     */
    static std::string_view oil();

    /**
     * @brief Returns a random nut's name.
     *
     * @returns Nuts.
     *
     * @code
     * Food::nut() // "walnut"
     * @endcode
     */
    static std::string_view nut();

    /**
     * @brief Returns a random seed's name.
     *
     * @returns Seed.
     *
     * @code
     * Food::seed() // "mozzarella"
     * @endcode
     */
    static std::string_view seed();

    /**
     * @brief Returns a random sugar product's name.
     *
     * @returns Sugar product.
     *
     * @code
     * Food::sugarProduct() // "honey harmony"
     * @endcode
     */
    static std::string_view sugarProduct();

    /**
     * @brief Returns a random non-alcoholic beverage's name.
     *
     * @returns Non-alcoholic Beverage.
     *
     * @code
     * Food::nonalcoholicBeverage() // "water"
     * @endcode
     */
    static std::string_view nonalcoholicBeverage();

    /**
     * @brief Returns a random dish's name.
     *
     * @returns Dish.
     *
     * @code
     * Food::dishName() // "beef wellington"
     * @endcode
     */
    static std::string_view dishName();

    /**
     * @brief Returns a random food categories' name.
     *
     * @returns Food Category.
     *
     * @code
     * Food::foodCategory() // "Dairy"
     * @endcode
     */
    static std::string_view foodCategory();
};
}
