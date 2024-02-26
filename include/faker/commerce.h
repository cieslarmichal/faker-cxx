#ifndef FAKER_COMMERCE_H
#define FAKER_COMMERCE_H

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
 * commerce::product_adjective() // "Handcrafted"
 * @endcode
 */
std::string_view product_adjective();

/**
 * @brief Returns a random product material.
 *
 * @returns Product material.
 *
 * @code
 * commerce::product_material() // "Wooden"
 * @endcode
 */
std::string_view product_material();

/**
 * @brief Returns a random product short name.
 *
 * @returns Product short name.
 *
 * @code
 * commerce::product_name() // "Computer"
 * @endcode
 */
std::string_view product_name();

/**
 * @brief Returns a random product full name.
 *
 * @returns Product full name.
 *
 * @code
 * commerce::product_full_name() // "Incredible Soft Gloves"
 * @endcode
 */
std::string product_full_name();

/**
 * @brief Returns a random valid ean13 code.
 *
 * @returns Ean13 code.
 *
 * @code
 * commerce::ean13() // "1234567890128"
 * @endcode
 */
std::string ean13();

/**
 * @brief Returns a random valid ean8 code.
 *
 * @returns Ean8 code.
 *
 * @code
 * commerce::ean8() // "90311017"
 * @endcode
 */
std::string ean8();

/**
 * @brief Returns a random valid isbn13 code.
 *
 * @returns Isbn13 code.
 *
 * @code
 * commerce::isbn13() // "9781234567897"
 * @endcode
 */
std::string isbn13();

/**
 * @brief Returns a random valid ISBN10 code.
 *
 * @returns Isbn10 code.
 *
 * @code
 * commerce::isbn10() // "0200716018"
 * @endcode
 */
std::string isbn10();

/**
 * @brief Returns a random product ID.
 *
 * @returns productId.
 *
 * @code
 * commerce::product_id() // "ABCD123456"
 * @endcode
 */
std::string product_id();

/**
 * @brief Returns a random payment type.
 *
 * @returns paymentType.
 *
 * @code
 * commerce::payment_type() // "Credit Card"
 * @endcode
 */
std::string_view payment_type();

/**
 * @brief Returns a random payment provider.
 *
 * @returns paymentProvider.
 *
 * @code
 * commerce::payment_provider() // "Paypal"
 * @endcode
 */
std::string_view payment_provider();

/**
 * @brief Returns a random product description.
 *
 * @returns productDescription.
 *
 * @code
 * commerce::product_description() // "Elevate your lifestyle with premium quality product."
 * @endcode
 */
std::string_view product_description();

/**
 * @brief Returns a random product category.
 *
 * @returns productCategory.
 *
 * @code
 * commerce::product_category() // "Electronics"
 * @endcode
 */
std::string_view product_category();

/**
 * @brief Returns a random product review.
 *
 * @returns productReview.
 *
 * @code
 * commerce::product_review() //  "Unfortunately, it broke shortly after I started using it."
 * @endcode
 */
std::string_view product_review();

/**
 * @brief Returns a random product rating (0-5).
 *
 * @returns productRating.
 *
 * @code
 * commerce::product_rating() // 4.1
 * @endcode
 */
double product_rating();

/**
 * @brief Returns a random discount type.
 *
 * @returns discountType.
 *
 * @code
 * commerce::discount_type() // "percentage"
 * @endcode
 */
std::string_view discount_type();

/**
 * @brief Returns random discount code within the specified range of 6 to 12 characters.
 *
 * @returns discount code consists of uppercase letters and numbers.
 *
 * @code
 * commerce::discount_code() // "VNM15DEC1"
 * @endcode
 */
std::string discount_code();

/**
 * @brief Returns a random discount amount within the specified range of 10 to 1000.
 *
 * @returns discountAmount.
 *
 * @code
 * commerce::discount_amount() // 57.80
 * @endcode
 */
double discount_amount();

/**
 * @brief Returns a random discount percentage within the specified range of 1. to 90.
 *
 * @returns discountPercentage.
 *
 * @code
 * commerce::discount_percentage() // 35.50
 * @endcode
 */
double discount_percentage();
}

#endif