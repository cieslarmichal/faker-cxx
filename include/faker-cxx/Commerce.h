#pragma once

#include <string_view>

namespace faker::commerce
{
/**
 * @brief Returns a random commerce department.
 *
 * @returns Commerce department name.
 *
 * @code
 * faker::commerce::department() // "Books"
 * @endcode
 */
std::string_view department();

/**
 * @brief Generates a random sku by default only with digits.
 *
 * @param length The length of the sku.
 *
 * @code
 * faker::commerce::sku() // "3027"
 * faker::commerce::sku(8) // "10512056"
 * @endcode
 */
std::string sku(unsigned length = 4);

/**
 * @brief Returns a random product adjective.
 *
 * @returns Product adjective.
 *
 * @code
 * faker::commerce::productAdjective() // "Handcrafted"
 * @endcode
 */
std::string_view productAdjective();

/**
 * @brief Returns a random product material.
 *
 * @returns Product material.
 *
 * @code
 * faker::commerce::productMaterial() // "Wooden"
 * @endcode
 */
std::string_view productMaterial();

/**
 * @brief Returns a random product short name.
 *
 * @returns Product short name.
 *
 * @code
 * faker::commerce::productName() // "Computer"
 * @endcode
 */
std::string_view productName();

/**
 * @brief Returns a random product full name.
 *
 * @returns Product full name.
 *
 * @code
 * faker::commerce::productFullName() // "Incredible Soft Gloves"
 * @endcode
 */
std::string productFullName();

/**
 * @brief Returns a random valid ean13 code.
 *
 * @returns Ean13 code.
 *
 * @code
 * faker::commerce::EAN13() // "1234567890128"
 * @endcode
 */
std::string EAN13();

/**
 * @brief Returns a random valid ean8 code.
 *
 * @returns Ean8 code.
 *
 * @code
 * faker::commerce::EAN8() // "90311017"
 * @endcode
 */
std::string EAN8();

/**
 * @brief Returns a random valid isbn13 code.
 *
 * @returns Isbn13 code.
 *
 * @code
 * faker::commerce::ISBN13() // "9781234567897"
 * @endcode
 */
std::string ISBN13();

/**
 * @brief Returns a random valid ISBN10 code.
 *
 * @returns Isbn10 code.
 *
 * @code
 * faker::commerce::ISBN10() // "0200716018"
 * @endcode
 */
std::string ISBN10();

/**
 * @brief Returns a random payment type.
 *
 * @returns paymentType.
 *
 * @code
 * faker::commerce::paymentType() // "Credit Card"
 * @endcode
 */
std::string_view paymentType();

/**
 * @brief Returns a random payment provider.
 *
 * @returns paymentProvider.
 *
 * @code
 * faker::commerce::paymentProvider() // "Paypal"
 * @endcode
 */
std::string_view paymentProvider();

/**
 * @brief Returns a random product description.
 *
 * @returns productDescription.
 *
 * @code
 * faker::commerce::productDescription() // "Elevate your lifestyle with premium quality product."
 * @endcode
 */
std::string_view productDescription();

/**
 * @brief Returns a random product category.
 *
 * @returns productCategory.
 *
 * @code
 * faker::commerce::productCategory() // "Electronics"
 * @endcode
 */
std::string_view productCategory();

/**
 * @brief Returns a random product review.
 *
 * @returns productReview.
 *
 * @code
 * faker::commerce::productReview() //  "Unfortunately, it broke shortly after I started using it."
 * @endcode
 */
std::string_view productReview();

/**
 * @brief Returns a random discount type.
 *
 * @returns discountType.
 *
 * @code
 * faker::commerce::discountType() // "percentage"
 * @endcode
 */
std::string_view discountType();

/**
 * @brief Returns a random order status.
 *
 * @returns orderStatus.
 *
 * @code
 * faker::commerce::orderStatus() // "shipped"
 * @endcode
 */
std::string_view orderStatus();

/**
 * @brief Returns a random shipping carrier.
 *
 * @returns shipping carrier
 *
 * @code
 * faker::commerce::shippingMethod() // "FedEx"
 * @endcode
 */
std::string_view shippingCarrier();
}
