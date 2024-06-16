#pragma once

#include <string_view>

namespace faker
{
class Commerce
{
public:
    /**
     * @brief Returns a random commerce department.
     *
     * @returns Commerce department name.
     *
     * @code
     * Commerce::department() // "Books"
     * @endcode
     */
    static std::string_view department();

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
     * @returns Product adjective.
     *
     * @code
     * Commerce::productAdjective() // "Handcrafted"
     * @endcode
     */
    static std::string_view productAdjective();

    /**
     * @brief Returns a random product material.
     *
     * @returns Product material.
     *
     * @code
     * Commerce::productMaterial() // "Wooden"
     * @endcode
     */
    static std::string_view productMaterial();

    /**
     * @brief Returns a random product short name.
     *
     * @returns Product short name.
     *
     * @code
     * Commerce::productName() // "Computer"
     * @endcode
     */
    static std::string_view productName();

    /**
     * @brief Returns a random product full name.
     *
     * @returns Product full name.
     *
     * @code
     * Commerce::productFullName() // "Incredible Soft Gloves"
     * @endcode
     */
    static std::string productFullName();

    /**
     * @brief Returns a random valid ean13 code.
     *
     * @returns Ean13 code.
     *
     * @code
     * Commerce::EAN13() // "1234567890128"
     * @endcode
     */
    static std::string EAN13();

    /**
     * @brief Returns a random valid ean8 code.
     *
     * @returns Ean8 code.
     *
     * @code
     * Commerce::EAN8() // "90311017"
     * @endcode
     */
    static std::string EAN8();

    /**
     * @brief Returns a random valid isbn13 code.
     *
     * @returns Isbn13 code.
     *
     * @code
     * Commerce::ISBN13() // "9781234567897"
     * @endcode
     */
    static std::string ISBN13();

    /**
     * @brief Returns a random valid ISBN10 code.
     *
     * @returns Isbn10 code.
     *
     * @code
     * Commerce::ISBN10() // "0200716018"
     * @endcode
     */
    static std::string ISBN10();

    /**
     * @brief Returns a random payment type.
     *
     * @returns paymentType.
     *
     * @code
     * Commerce::paymentType() // "Credit Card"
     * @endcode
     */
    static std::string_view paymentType();

    /**
     * @brief Returns a random payment provider.
     *
     * @returns paymentProvider.
     *
     * @code
     * Commerce::paymentProvider() // "Paypal"
     * @endcode
     */
    static std::string_view paymentProvider();

    /**
     * @brief Returns a random product description.
     *
     * @returns productDescription.
     *
     * @code
     * Commerce::productDescription() // "Elevate your lifestyle with premium quality product."
     * @endcode
     */
    static std::string_view productDescription();

    /**
     * @brief Returns a random product category.
     *
     * @returns productCategory.
     *
     * @code
     * Commerce::productCategory() // "Electronics"
     * @endcode
     */
    static std::string_view productCategory();

    /**
     * @brief Returns a random product review.
     *
     * @returns productReview.
     *
     * @code
     * Commerce::productReview() //  "Unfortunately, it broke shortly after I started using it."
     * @endcode
     */
    static std::string_view productReview();

    /**
     * @brief Returns a random discount type.
     *
     * @returns discountType.
     *
     * @code
     * Commerce::discountType() // "percentage"
     * @endcode
     */
    static std::string_view discountType();

    /**
     * @brief Returns a random order status.
     *
     * @returns orderStatus.
     *
     * @code
     * Commerce::orderStatus() // "shipped"
     * @endcode
     */
    static std::string_view orderStatus();

    /**
     * @brief Returns a random shipping carrier.
     *
     * @returns shipping carrier
     *
     * @code
     * Commerce::shippingMethod() // "FedEx"
     * @endcode
     */
    static std::string_view shippingCarrier();
};
}
