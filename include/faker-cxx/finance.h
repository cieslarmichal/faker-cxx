#pragma once

#include <string>
#include <string_view>

#include "faker-cxx/export.h"
#include "faker-cxx/types/locale.h"
#include "types/precision.h"

namespace faker::finance
{
struct FAKER_CXX_EXPORT Currency
{
    std::string_view name;
    std::string_view code;
    std::string_view symbol;
};

/**
 * @brief Returns a random currency.
 *
 * @returns Currency.
 *
 * @code
 * faker::finance::currency() // "{"US Dollar","USD","$"}"
 * @endcode
 */
FAKER_CXX_EXPORT Currency currency();

/**
 * @brief Returns a random currency name.
 *
 * @returns Name of the currency.
 *
 * @code
 * faker::finance::currencyName() // "US Dollar"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view currencyName();

/**
 * @brief Returns a random currency code.
 *
 * @returns Code of the currency.
 *
 * @code
 * faker::finance::currencyCode() // "USD"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view currencyCode();

/**
 * @brief Returns a random currency symbol.
 *
 * @returns Symbol of the currency.
 *
 * @code
 * faker::finance::currencySymbol() // "$"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view currencySymbol();

/**
 * @brief Returns a random account type.
 *
 * @returns Account type.
 *
 * @code
 * faker::finance::accountType() // "Savings"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view accountType();

/**
 * @brief Generates a random amount between the given bounds (inclusive).

 * @param min The lower bound for the amount. Defaults to `0`.
 * @param max The upper bound for the amount. Defaults to `1000`.
 * @param precision The number of decimal points of precision for the amount. Defaults to `Precision::TwoDp`.
 * @param symbol The symbol used to prefix the amount. Defaults to `""`.
 *
 * @returns Amount of money as string.
 *
 * @code
 * faker::finance::amount() // "720.18"
 * faker::finance::amount(5, 10) // "4.22"
 * faker::finance::amount(5, 10, Precision::ZeroDp) // "4"
 * faker::finance::amount(5, 10, Precision::TwoDp, "$") // "$5.85"
 * @endcode
 */
FAKER_CXX_EXPORT std::string amount(double min = 0, double max = 1000, Precision precision = Precision::TwoDp,
                                    const std::string& symbol = "");

/**
 * @brief Generates a random IBAN.
 *
 * @param locale The locale. Defaults to `Locale::de_DE`.
 *
 * @returns IBAN.
 *
 * @code
 * faker::finance::iban(Locale::pl_PL) // "PL61109010140000071219812874"
 * @endcode
 */
FAKER_CXX_EXPORT std::string iban(Locale locale = Locale::de_DE);

/**
 * @brief Generates a random BIC.
 *
 * @param locale The locale. Defaults to `Locale::en_US`.
 *
 * @returns BIC.
 *
 * @code
 * faker::finance::bic(Locale::pl_PL) // "BREXPLPWMUL"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view bic(Locale locale = Locale::en_US);

/**
 * @brief Generates a random account number.
 *
 * @param length The length of the account number. Defaults to `8`.
 *
 * @returns Account number.
 *
 * @code
 * faker::finance::accountNumber() // "92842238"
 * faker::finance::accountNumber(26) // "55875455514825927518796290"
 * @endcode
 */
FAKER_CXX_EXPORT std::string accountNumber(unsigned length = 8);

/**
 * @brief Generates a random PIN number.
 *
 * @param length The length of the PIN to generate. Defaults to `4`.
 *
 * @returns PIN number.
 *
 * @code
 * faker::finance::pin() // "5067"
 * faker::finance::pin(8) // "21378928"
 * @endcode
 */
FAKER_CXX_EXPORT std::string pin(unsigned length = 4);

/**
 * @brief Generates a random routing number.
 *
 * @returns Routing number.
 *
 * @code
 * faker::finance::routingNumber() // "522814402"
 * @endcode
 */
FAKER_CXX_EXPORT std::string routingNumber();

enum class CreditCardType
{
    AmericanExpress,
    Discover,
    MasterCard,
    Visa
};

/**
 * @brief Generates a random credit card number.
 *
 * @param creditCardType The type of the credit card. Defaults to `CreditCardType::Visa`.
 *
 * @returns Credit card number.
 *
 * @code
 * faker::finance::creditCardNumber() // "4882664999007"
 * @endcode
 */
FAKER_CXX_EXPORT std::string creditCardNumber(CreditCardType creditCardType = CreditCardType::Visa);

/**
 * @brief Generates a random credit card CVV.
 *
 * @returns Credit card CVV.
 *
 * @code
 * faker::finance::creditCardCvv() // "506"
 * @endcode
 */
FAKER_CXX_EXPORT std::string creditCardCvv();

/**
 * @brief Generates a random bitcoin address.
 *
 * @returns Bitcoin address.
 *
 * @code
 * faker::finance::bitcoinAddress() // "3ySdvCkTLVy7gKD4j6JfSaf5d"
 * @endcode
 */
FAKER_CXX_EXPORT std::string bitcoinAddress();

/**
 * @brief Generates a random litecoin address.
 *
 * @returns Litecoin address.
 *
 * @code
 * faker::finance::litecoinAddress() // "LoQaSTGWBRXkWfyxKbNKuPrAWGELzcW"
 * @endcode
 */
FAKER_CXX_EXPORT std::string litecoinAddress();

/**
 * @brief Generates a random ethereum address.
 *
 * @returns Ethereum address.
 *
 * @code
 * faker::finance::ethereumAddress() // "0xf03dfeecbafc5147241cc4c4ca20b3c9dfd04c4a"
 * @endcode
 */
FAKER_CXX_EXPORT std::string ethereumAddress();

/**
 * @brief Generates a random expiration date.
 *
 * @returns std::string date.
 *
 * @code
 * faker::finance::creditCardExpirationDate() // "03/26"
 * @endcode
 */
FAKER_CXX_EXPORT std::string creditCardExpirationDate();

/**
 * @brief Generates a random credit card type.
 *
 * @returns std::string creditCardType.
 *
 * @code
 * faker::finance::creditCardType() // "Visa"
 * @endcode
 */
FAKER_CXX_EXPORT std::string_view creditCardType();

}
