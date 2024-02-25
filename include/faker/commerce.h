#pragma once

#include <string>

namespace faker::commerce {
/**
 * @brief Returns a random commerce department.
 *
 * @returns commerce department name.
 *
 * @code
 * commerce::department() // "Books"
 * @endcode
 */
std::string_view department();

/**
 * @brief Generates a random price between the given bounds (inclusive).
 *
 * @param min The lower bound for the price. Defaults to `0`.
 * @param max The upper bound for the price. Defaults to `1000`.
 *
 * @code
 * commerce::price() // "88.62"
 * @endcode
 */
std::string price(double min = 0, double max = 1000);

/**
 * @brief Generates a random sku by default only with digits.
 *
 * @param length The length of the sku.
 *
 * @code
 * commerce::sku() // "3027"
 * commerce::sku(8) // "10512056"
 * @endcode
 */
std::string sku(unsigned length = 4);

/**
 * @brief Returns a random product adjective.
 *
 * @returns Product adjective.
 *
 * @code
 * commerce::productAdjective() // "Handcrafted"
 * @endcode
 */
std::string_view productAdjective();

/**
 * @brief Returns a random product material.
 *
 * @returns Product material.
 *
 * @code
 * commerce::productMaterial() // "Wooden"
 * @endcode
 */
std::string_view productMaterial();

/**
 * @brief Returns a random product short name.
 *
 * @returns Product short name.
 *
 * @code
 * commerce::productName() // "Computer"
 * @endcode
 */
std::string_view productName();

/**
 * @brief Returns a random product full name.
 *
 * @returns Product full name.
 *
 * @code
 * commerce::productFullName() // "Incredible Soft Gloves"
 * @endcode
 */
std::string productFullName();

/**
 * @brief Returns a random valid ean13 code.
 *
 * @returns Ean13 code.
 *
 * @code
 * commerce::EAN13() // "1234567890128"
 * @endcode
 */
std::string EAN13();

/**
 * @brief Returns a random valid ean8 code.
 *
 * @returns Ean8 code.
 *
 * @code
 * commerce::EAN8() // "90311017"
 * @endcode
 */
std::string EAN8();

/**
 * @brief Returns a random valid isbn13 code.
 *
 * @returns Isbn13 code.
 *
 * @code
 * commerce::ISBN13() // "9781234567897"
 * @endcode
 */
std::string ISBN13();

/**
 * @brief Returns a random valid ISBN10 code.
 *
 * @returns Isbn10 code.
 *
 * @code
 * commerce::ISBN10() // "0200716018"
 * @endcode
 */
std::string ISBN10();

/**
 * @brief Returns a random product ID.
 *
 * @returns productId.
 *
 * @code
 * commerce::productId() // "ABCD123456"
 * @endcode
 */
std::string productId();

/**
 * @brief Returns a random payment type.
 *
 * @returns paymentType.
 *
 * @code
 * commerce::paymentType() // "Credit Card"
 * @endcode
 */
std::string_view paymentType();

/**
 * @brief Returns a random payment provider.
 *
 * @returns paymentProvider.
 *
 * @code
 * commerce::paymentProvider() // "Paypal"
 * @endcode
 */
std::string_view paymentProvider();

/**
 * @brief Returns a random product description.
 *
 * @returns productDescription.
 *
 * @code
 * commerce::productDescription() // "Elevate your lifestyle with premium quality product."
 * @endcode
 */
std::string_view productDescription();

/**
 * @brief Returns a random product category.
 *
 * @returns productCategory.
 *
 * @code
 * commerce::productCategory() // "Electronics"
 * @endcode
 */
std::string_view productCategory();

/**
 * @brief Returns a random product review.
 *
 * @returns productReview.
 *
 * @code
 * commerce::productReview() //  "Unfortunately, it broke shortly after I started using it."
 * @endcode
 */
std::string_view productReview();

/**
 * @brief Returns a random product rating (0-5).
 *
 * @returns productRating.
 *
 * @code
 * commerce::productRating() // 4.1
 * @endcode
 */
double productRating();

/**
 * @brief Returns a random discount type.
 *
 * @returns discountType.
 *
 * @code
 * commerce::discountType() // "percentage"
 * @endcode
 */
std::string_view discountType();

/**
 * @brief Returns random discount code within the specified range of 6 to 12 characters.
 *
 * @returns discount code consists of uppercase letters and numbers.
 *
 * @code
 * commerce::discountCode() // "VNM15DEC1"
 * @endcode
 */
std::string discountCode();

/**
 * @brief Returns a random discount amount within the specified range of 10 to 1000.
 *
 * @returns discountAmount.
 *
 * @code
 * commerce::discountAmount() // 57.80
 * @endcode
 */
double discountAmount();

/**
 * @brief Returns a random discount percentage within the specified range of 1. to 90.
 *
 * @returns discountPercentage.
 *
 * @code
 * commerce::discountPercentage() // 35.50
 * @endcode
 */
double discountPercentage();
}
