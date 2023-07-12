#pragma once

#include <string>

namespace faker
{
class Commerce
{
public:
    /**
     * @brief Returns a random commerce department.
     *
     * @returns Commerce department name
     *
     * @code
     * Commerce::department() // "Books"
     * @endcode
     */
    static std::string department();

    /**
     * @brief Generates a random price between the given bounds (inclusive).

     * @param min The lower bound for the price. Defaults to `0`.
     * @param max The upper bound for the price. Defaults to `1000`.
     *
     * @code
     * Commerce::price() // "88.62"
     * @endcode
     */
    static std::string price(double min = 0, double max = 1000);

    /**
     * @brief Generates a random sku by default only with digits.
     *
     * @param length The length of the sku.
     *
     * @code
     * Commerce::sku() // "3027"
     * Commerce::sku(8) // "10512056"
     * @endcode
     */
    static std::string sku(unsigned length = 4);

    /**
     * @brief Returns a random product adjective.
     *
     * @returns Product adjective
     *
     * @code
     * Commerce::productAdjective() // "Handcrafted"
     * @endcode
     */
    static std::string productAdjective();

    /**
     * @brief Returns a random product material.
     *
     * @returns Product material
     *
     * @code
     * Commerce::productMaterial() // "Wooden"
     * @endcode
     */
    static std::string productMaterial();

    /**
     * @brief Returns a random product short name.
     *
     * @returns Product short name
     *
     * @code
     * Commerce::productName() // "Computer"
     * @endcode
     */
    static std::string productName();

    /**
     * @brief Returns a random product full name.
     *
     * @returns Product full name
     *
     * @code
     * Commerce::productFullName() // "Incredible Soft Gloves"
     * @endcode
     */
    static std::string productFullName();
};
}
