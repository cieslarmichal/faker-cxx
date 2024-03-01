#ifndef FAKER_FINANCE_H
#define FAKER_FINANCE_H

#include <faker/types/country.h>
#include <faker/types/precision.h>
#include <optional>
#include <string>

namespace faker::finance {
enum class iban_country {
    austria,
    belgium,
    bulgaria,
    croatia,
    cyprus,
    czechia,
    denmark,
    estonia,
    finland,
    france,
    germany,
    greece,
    hungary,
    ireland,
    italy,
    latvia,
    lithuania,
    luxembourg,
    malta,
    netherlands,
    poland,
    portugal,
    romania,
    slovakia,
    slovenia,
    spain,
    sweden
};

struct currency_info {
    std::string_view name;
    std::string_view code;
    std::string_view symbol;
};

inline bool operator==(const currency_info& lhs, const currency_info& rhs)
{
    return lhs.name == rhs.name && lhs.code == rhs.code && lhs.symbol == rhs.symbol;
}

enum class bic_country {
    poland,
    usa,
    england,
    germany,
    romania,
    france,
    india,
    italy,
    netherlands,
    spain,
};

enum class credit_card_type { american_express, discover, mastercard, visa };

/**
 * @brief Returns a random currency.
 *
 * @returns currency_info.
 *
 * @code
 * finance::currency() // "{"US Dollar","USD","$"}"
 * @endcode
 */
currency_info currency();

/**
 * @brief Returns a random currency name.
 *
 * @returns Name of the currency.
 *
 * @code
 * finance::currency_name() // "US Dollar"
 * @endcode
 */
std::string_view currency_name();

/**
 * @brief Returns a random currency code.
 *
 * @returns Code of the currency.
 *
 * @code
 * finance::currency_code() // "USD"
 * @endcode
 */
std::string_view currency_code();

/**
 * @brief Returns a random currency symbol.
 *
 * @returns Symbol of the currency.
 *
 * @code
 * finance::currency_symbol() // "$"
 * @endcode
 */
std::string_view currency_symbol();

/**
 * @brief Returns a random account type.
 *
 * @returns Account type.
 *
 * @code
 * finance::account_type() // "Savings"
 * @endcode
 */
std::string_view account_type();

/**
 * @brief Generates a random amount between the given bounds (inclusive).

 * @param min The lower bound for the amount. Defaults to `0`.
 * @param max The upper bound for the amount. Defaults to `1000`.
 * @param prec The number of decimal points of prec for the amount. Defaults to
 `precision_t::two_dp`.
 * @param symbol The symbol used to prefix the amount. Defaults to `""`.
 *
 * @returns Amount of money as string.
 *
 * @code
 * finance::amount() // "720.18"
 * finance::amount(5, 10) // "4.22"
 * finance::amount(5, 10, precision_t::zero_dp) // "4"
 * finance::amount(5, 10, precision_t::two_dp, "$") // "$5.85"
 * @endcode
 */
std::string amount(double min = 0, double max = 1000, precision_t prec = precision_t::two_dp,
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
 * finance::iban(iban_country::poland) // "PL61109010140000071219812874"
 * @endcode
 */
std::string iban(std::optional<iban_country> country = std::nullopt);

/**
 * Generates a random bic.
 *
 * @param country The country from which you want to generate a BIC, if none is provided a
 random country will be used.
 *
 * @returns BIC.
 *
 * @code
 * finance::bic(bic_country::poland) // "BREXPLPWMUL"
 * @endcode
 */
std::string_view bic(std::optional<bic_country> country = std::nullopt);

/**
 * Generates a random account number.
 *
 * @param length The length of the account number. Defaults to `8`.
 *
 * @returns Account number.
 *
 * @code
 * finance::account_number() // "92842238"
 * finance::account_number(26) // "55875455514825927518796290"
 * @endcode
 */
std::string account_number(unsigned length = 8);

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
 * finance::routing_number() // "522814402"
 * @endcode
 */
std::string routing_number();

/**
 * Generates a random credit card number.
 *
 * @param cc_type The type of the credit card.
 *
 * @returns Credit card number.
 *
 * @code
 * finance::credit_card_number() // "4882664999007"
 * @endcode
 */
std::string credit_card_number(std::optional<credit_card_type> cc_type = std::nullopt);

/**
 * Generates a random credit card CVV.
 *
 * @returns Credit card CVV.
 *
 * @code
 * finance::credit_card_cvv() // "506"
 * @endcode
 */
std::string credit_card_cvv();

/**
 * Generates a random bitcoin address.
 *
 * @returns Bitcoin address.
 *
 * @code
 * finance::bitcoin_address() // "3ySdvCkTLVy7gKD4j6JfSaf5d"
 * @endcode
 */
std::string bitcoin_address();

/**
 * Generates a random litecoin address.
 *
 * @returns Litecoin address.
 *
 * @code
 * finance::litecoin_address() // "LoQaSTGWBRXkWfyxKbNKuPrAWGELzcW"
 * @endcode
 */
std::string litecoin_address();

/**
 * Generates a random ethereum address.
 *
 * @returns Ethereum address.
 *
 * @code
 * finance::ethereum_address() // "0xf03dfeecbafc5147241cc4c4ca20b3c9dfd04c4a"
 * @endcode
 */
std::string ethereum_address();

/**
 * Generates a random expiration date.
 *
 * @returns std::string date.
 *
 * @code
 * finance::credit_card_expiration_date() // "03/26"
 * @endcode
 */
std::string credit_card_expiration_date();
}

#endif