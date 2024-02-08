#pragma once

#include <optional>
#include <string>

#include "types/BicCountry.h"
#include "types/Country.h"
#include "types/Currency.h"
#include "types/IbanCountry.h"
#include "types/Precision.h"

namespace faker
{
enum class CreditCardType
{
    AmericanExpress,
    Discover,
    MasterCard,
    Visa
};

class Finance
{
public:
    /**
     * @brief Returns a random currency.
     *
     * @returns Currency.
     *
     * @code
     * Finance::currency() // "{"US Dollar","USD","$"}"
     * @endcode
     */
    static Currency currency();

    /**
     * @brief Returns a random currency name.
     *
     * @returns Name of the currency.
     *
     * @code
     * Finance::currencyName() // "US Dollar"
     * @endcode
     */
    static std::string currencyName();

    /**
     * @brief Returns a random currency code.
     *
     * @returns Code of the currency.
     *
     * @code
     * Finance::currencyCode() // "USD"
     * @endcode
     */
    static std::string currencyCode();

    /**
     * @brief Returns a random currency symbol.
     *
     * @returns Symbol of the currency.
     *
     * @code
     * Finance::currencySymbol() // "$"
     * @endcode
     */
    static std::string currencySymbol();

    /**
     * @brief Returns a random account type.
     *
     * @returns Account type.
     *
     * @code
     * Finance::accountType() // "Savings"
     * @endcode
     */
    static std::string accountType();

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
     * Finance::amount() // "720.18"
     * Finance::amount(5, 10) // "4.22"
     * Finance::amount(5, 10, Precision::ZeroDp) // "4"
     * Finance::amount(5, 10, Precision::TwoDp, "$") // "$5.85"
     * @endcode
     */
    static std::string amount(double min = 0, double max = 1000, Precision precision = Precision::TwoDp,
                              const std::string& symbol = "");

    /**
     * Generates a random iban.
     *
     * @param country The country from which you want to generate an IBAN, if none is provided a random country
     will be used.
     *
     * @returns IBAN.
     *
     * @code
     * Finance::iban(IbanCountry::Poland) // "PL61109010140000071219812874"
     * @endcode
     */
    static std::string iban(std::optional<IbanCountry> country = std::nullopt);

    /**
     * Generates a random bic.
     *
     * @param country The country from which you want to generate a BIC, if none is provided a random country
     will be used.
     *
     * @returns BIC.
     *
     * @code
     * Finance::bic(BicCountry::Poland) // "BREXPLPWMUL"
     * @endcode
     */
    static std::string bic(std::optional<BicCountry> country = std::nullopt);

    /**
     * Generates a random account number.
     *
     * @param length The length of the account number. Defaults to `8`.
     *
     * @returns Account number.
     *
     * @code
     * Finance::accountNumber() // "92842238"
     * Finance::accountNumber(26) // "55875455514825927518796290"
     * @endcode
     */
    static std::string accountNumber(unsigned length = 8);

    /**
     * Generates a random PIN number.
     *
     * @param length The length of the PIN to generate. Defaults to `4`.
     *
     * @returns PIN number.
     *
     * @code
     * Finance::pin() // "5067"
     * Finance::pin(8) // "21378928"
     * @endcode
     */
    static std::string pin(unsigned length = 4);

    /**
     * Generates a random routing number.
     *
     * @returns Routing number.
     *
     * @code
     * Finance::routingNumber() // "522814402"
     * @endcode
     */
    static std::string routingNumber();

    /**
     * Generates a random credit card number.
     *
     * @param creditCardType The type of the credit card.
     *
     * @returns Credit card number.
     *
     * @code
     * Finance::creditCardNumber() // "4882664999007"
     * @endcode
     */
    static std::string creditCardNumber(std::optional<CreditCardType> creditCardType = std::nullopt);

    /**
     * Generates a random credit card CVV.
     *
     * @returns Credit card CVV.
     *
     * @code
     * Finance::creditCardCvv() // "506"
     * @endcode
     */
    static std::string creditCardCvv();

    /**
     * Generates a random bitcoin address.
     *
     * @returns Bitcoin address.
     *
     * @code
     * Finance::bitcoinAddress() // "3ySdvCkTLVy7gKD4j6JfSaf5d"
     * @endcode
     */
    static std::string bitcoinAddress();

    /**
     * Generates a random litecoin address.
     *
     * @returns Litecoin address.
     *
     * @code
     * Finance::litecoinAddress() // "LoQaSTGWBRXkWfyxKbNKuPrAWGELzcW"
     * @endcode
     */
    static std::string litecoinAddress();

    /**
     * Generates a random ethereum address.
     *
     * @returns Ethereum address.
     *
     * @code
     * Finance::ethereumAddress() // "0xf03dfeecbafc5147241cc4c4ca20b3c9dfd04c4a"
     * @endcode
     */
    static std::string ethereumAddress();

    /**
     * Generates a random expiration date.
     *
     * @returns std::string date.
     *
     * @code
     * Finance::creditCardExpirationDate() // "03/26"
     * @endcode
     */
    static std::string creditCardExpirationDate();

    /**
     * @brief Determines the type of a credit card based on its number.
     *
     * @param creditCardNumber The credit card number to check.
     * @returns The type of the credit card (e.g., "Visa", "MasterCard", "American Express", "Discover", "Unknown").
     */
    static std::string creditCardType(const std::string& creditCardNumber);
};
}
