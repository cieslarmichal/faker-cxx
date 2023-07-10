#pragma once

#include <optional>
#include <string>

#include "types/IbanCountry.h"

namespace faker
{

class Finance
{
public:
    /**
     * @brief Returns a random currency code.
     *
     * @returns Code of the currency
     *
     * @code
     * Finance::currencyCode() // "USD"
     * @endcode
     */
    static std::string currencyCode();

    /**
     * @brief Returns a random account type.
     *
     * @returns Account type
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
     * @param symbol The symbol used to prefix the amount. Defaults to `''`.
     *
     * @returns Amount of money as string
     *
     * @code
     * Finance::amount() // '720.18'
     * Finance::amount(5, 10) // '4.22'
     * Finance::amount(5, 10, 0) // '4'
     * Finance::amount(5, 10, 2, '$') // '$5.85'
     * @endcode
     */
    static std::string amount(unsigned min = 0, unsigned max = 1000, unsigned decimalPlaces = 2,
                              const std::string& symbol = "");

    /**
   * Generates a random iban.
   *
   * @param country The country from which you want to generate an IBAN, if none is provided a random country
   will be used.
   *
   * @returns Iban
   * @code
   * faker.finance.iban() // 'TR736918640040966092800056'
   * faker.finance.iban(true) // 'FR20 8008 2330 8984 74S3 Z620 224'
   * faker.finance.iban(true, 'DE') // 'DE84 1022 7075 0900 1170 01'
   * @endcode
   */
    static std::string iban(std::optional<IbanCountry> country);
};
}
