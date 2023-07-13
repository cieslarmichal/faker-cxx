#pragma once

#include <optional>
#include <string>

#include "types/Country.h"

namespace faker
{
class Finance
{
public:
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
     * @param decimalPlaces The number of decimal places for the amount. Defaults to `2`.
     * @param symbol The symbol used to prefix the amount. Defaults to `""`.
     *
     * @returns Amount of money as string.
     *
     * @code
     * Finance::amount() // "720.18"
     * Finance::amount(5, 10) // "4.22"
     * Finance::amount(5, 10, 0) // "4"
     * Finance::amount(5, 10, 2, "$") // "$5.85"
     * @endcode
     */
    static std::string amount(double min = 0, double max = 1000, unsigned decimalPlaces = 2,
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
    static std::string iban(std::optional<Country> country = std::nullopt);

    /**
     * Generates a random bic.
     *
     * @param country The country from which you want to generate a BIC, if none is provided a random country
     will be used.
     *
     * @returns BIC.
     *
     * @code
     * Finance::bic(IbanCountry::Poland) // "BREXPLPWMUL"
     * @endcode
     */
    static std::string bic(std::optional<Country> country = std::nullopt);

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
};
}
