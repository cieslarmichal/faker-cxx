#ifndef FAKER_FINANCE_H
#define FAKER_FINANCE_H

#include <faker/types/bic_country.h>
#include <faker/types/country.h>
#include <faker/types/currency.h>
#include <faker/types/iban_country.h>
#include <faker/types/precision.h>
#include <optional>
#include <string>

namespace faker::finance {
enum class CreditCardType { AmericanExpress, Discover, MasterCard, Visa };

/**
 * @brief Returns a random currency.
 *
 * @returns Currency.
 *
 * @code
 * finance::currency() // "{"US Dollar","USD","$"}"
 * @endcode
 */
Currency currency();

/**
 * @brief Returns a random currency name.
 *
 * @returns Name of the currency.
 *
 * @code
 * finance::currencyName() // "US Dollar"
 * @endcode
 */
std::string_view currencyName();

/**
 * @brief Returns a random currency code.
 *
 * @returns Code of the currency.
 *
 * @code
 * finance::currencyCode() // "USD"
 * @endcode
 */
std::string_view currencyCode();

/**
 * @brief Returns a random currency symbol.
 *
 * @returns Symbol of the currency.
 *
 * @code
 * finance::currencySymbol() // "$"
 * @endcode
 */
std::string_view currencySymbol();

/**
 * @brief Returns a random account type.
 *
 * @returns Account type.
 *
 * @code
 * finance::accountType() // "Savings"
 * @endcode
 */
std::string_view accountType();

/**
 * @brief Generates a random amount between the given bounds (inclusive).

 * @param min The lower bound for the amount. Defaults to `0`.
 * @param max The upper bound for the amount. Defaults to `1000`.
 * @param precision The number of decimal points of precision for the amount. Defaults to
 `Precision::TwoDp`.
 * @param symbol The symbol used to prefix the amount. Defaults to `""`.
 *
 * @returns Amount of money as string.
 *
 * @code
 * finance::amount() // "720.18"
 * finance::amount(5, 10) // "4.22"
 * finance::amount(5, 10, Precision::ZeroDp) // "4"
 * finance::amount(5, 10, Precision::TwoDp, "$") // "$5.85"
 * @endcode
 */
std::string amount(double min = 0, double max = 1000, Precision precision = Precision::TwoDp,
    const std::string& symbol = "");

/**
 * Generates a random iban.
 *
 * @param country The country from which you want to generate an IBAN, if none is provided a
 random country will be used.
 *
 * @returns IBAN.
 *
 * @code
 * finance::iban(IbanCountry::Poland) // "PL61109010140000071219812874"
 * @endcode
 */
std::string iban(std::optional<IbanCountry> country = std::nullopt);

/**
 * Generates a random bic.
 *
 * @param country The country from which you want to generate a BIC, if none is provided a
 random country will be used.
 *
 * @returns BIC.
 *
 * @code
 * finance::bic(BicCountry::Poland) // "BREXPLPWMUL"
 * @endcode
 */
std::string_view bic(std::optional<BicCountry> country = std::nullopt);

/**
 * Generates a random account number.
 *
 * @param length The length of the account number. Defaults to `8`.
 *
 * @returns Account number.
 *
 * @code
 * finance::accountNumber() // "92842238"
 * finance::accountNumber(26) // "55875455514825927518796290"
 * @endcode
 */
std::string accountNumber(unsigned length = 8);

/**
 * Generates a random PIN number.
 *
 * @param length The length of the PIN to generate. Defaults to `4`.
 *
 * @returns PIN number.
 *
 * @code
 * finance::pin() // "5067"
 * finance::pin(8) // "21378928"
 * @endcode
 */
std::string pin(unsigned length = 4);

/**
 * Generates a random routing number.
 *
 * @returns Routing number.
 *
 * @code
 * finance::routingNumber() // "522814402"
 * @endcode
 */
std::string routingNumber();

/**
 * Generates a random credit card number.
 *
 * @param creditCardType The type of the credit card.
 *
 * @returns Credit card number.
 *
 * @code
 * finance::creditCardNumber() // "4882664999007"
 * @endcode
 */
std::string creditCardNumber(std::optional<CreditCardType> creditCardType = std::nullopt);

/**
 * Generates a random credit card CVV.
 *
 * @returns Credit card CVV.
 *
 * @code
 * finance::creditCardCvv() // "506"
 * @endcode
 */
std::string creditCardCvv();

/**
 * Generates a random bitcoin address.
 *
 * @returns Bitcoin address.
 *
 * @code
 * finance::bitcoinAddress() // "3ySdvCkTLVy7gKD4j6JfSaf5d"
 * @endcode
 */
std::string bitcoinAddress();

/**
 * Generates a random litecoin address.
 *
 * @returns Litecoin address.
 *
 * @code
 * finance::litecoinAddress() // "LoQaSTGWBRXkWfyxKbNKuPrAWGELzcW"
 * @endcode
 */
std::string litecoinAddress();

/**
 * Generates a random ethereum address.
 *
 * @returns Ethereum address.
 *
 * @code
 * finance::ethereumAddress() // "0xf03dfeecbafc5147241cc4c4ca20b3c9dfd04c4a"
 * @endcode
 */
std::string ethereumAddress();

/**
 * Generates a random expiration date.
 *
 * @returns std::string date.
 *
 * @code
 * finance::creditCardExpirationDate() // "03/26"
 * @endcode
 */
std::string creditCardExpirationDate();
}

#endif