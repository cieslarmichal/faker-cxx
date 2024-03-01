#include "../common/formatter.h"
#include "../common/random.h"
#include "../common/strings.h"
#include "finance_data.h"
#include <faker/date.h>
#include <faker/finance.h>
#include <faker/number.h>
#include <faker/string.h>

namespace faker::finance {
currency_info currency() { return random::element(data::currencies); }

std::string_view currency_name() { return random::element(data::currencies).name; }

std::string_view currency_code() { return random::element(data::currencies).code; }

std::string_view currency_symbol() { return random::element(data::currencies).symbol; }

std::string_view account_type() { return random::element(data::account_types); }

std::string amount(double min, double max, precision_t prec, const std::string& symbol)
{
    std::string result { symbol };
    result += utils::precision_format(prec, number::decimal(min, max));
    return result;
}

std::string iban(std::optional<iban_country> country)
{
    auto iban_format
        = data::iban_formats.at(country ? *country : random::element(data::iban_countries));

    std::string result { iban_format[0] };

    for (size_t i = 1; i < iban_format.size(); i++) {
        auto iban_format_entry = iban_format[i];
        auto entry_data_type = iban_format_entry.back();
        auto entry_data_length
            = utils::to_uint(iban_format_entry.substr(0, iban_format_entry.size() - 1));
        if (entry_data_type == 'a') {
            result += string::alpha(entry_data_length, string::string_case::upper);
        } else if (entry_data_type == 'c') {
            result += string::alphanumeric(entry_data_length, string::string_case::upper);
        } else if (entry_data_type == 'n') {
            result += string::numeric(entry_data_length);
        }
    }

    return result;
}

std::string_view bic(std::optional<bic_country> country)
{
    return random::element(
        data::bic_countries_codes.at(country ? *country : random::element(data::bic_countries)));
}

std::string account_number(unsigned length) { return string::numeric(length, true); }

std::string pin(unsigned length) { return string::numeric(length, true); }

std::string routing_number() { return string::numeric(9, true); }

std::string credit_card_number(std::optional<credit_card_type> cc_type)
{
    std::string_view cc_format {};

    switch (cc_type ? *cc_type : random::element(data::credit_card_types)) {
    case credit_card_type::american_express:
        cc_format = random::element(data::american_express_cc_formats);
        break;
    case credit_card_type::discover:
        cc_format = random::element(data::discover_cc_formats);
        break;
    case credit_card_type::mastercard:
        cc_format = random::element(data::mastercard_cc_formats);
        break;
    case credit_card_type::visa:
        cc_format = random::element(data::visa_cc_formats);
        break;
    }

    return random::replace_credit_card_symbols(cc_format);
}

std::string credit_card_cvv() { return string::numeric(3, true); }

std::string bitcoin_address()
{
    static std::array<std::string_view, 2> first_digits { "1", "3" };

    std::string result { random::element(first_digits) };
    result += string::alphanumeric(number::integer(26, 33), string::string_case::mixed, "0OIl");
    return result;
}

std::string litecoin_address()
{
    static std::array<std::string_view, 3> first_digits { "L", "M", "3" };

    std::string result { random::element(first_digits) };
    result += string::alphanumeric(number::integer(26, 33), string::string_case::mixed, "0OIl");
    return result;
}

std::string ethereum_address() { return string::hexadecimal(40, hex_case_t::lower); }

std::string credit_card_expiration_date()
{
    auto result = date::future(3);
    return result.substr(5, 2) + "/" + result.substr(2, 2);
}
}
