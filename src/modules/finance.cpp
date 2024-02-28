#include "../common/formatter.h"
#include "../common/random.h"
#include "finance_data.h"
#include <faker/date.h>
#include <faker/finance.h>
#include <faker/number.h>
#include <faker/string.h>

namespace faker::finance {
Currency currency() { return random::element(data::currencies); }

std::string_view currency_name() { return random::element(data::currencies).name; }

std::string_view currency_code() { return random::element(data::currencies).code; }

std::string_view currency_symbol() { return random::element(data::currencies).symbol; }

std::string_view account_type() { return random::element(data::accountTypes); }

std::string amount(double min, double max, Precision precision, const std::string& symbol)
{
    const auto generatedNumber = number::decimal(min, max);

    std::string result { symbol };
    result += utils::format(utils::precision_format_str(precision), generatedNumber);
    return result;
}

std::string iban(std::optional<IbanCountry> country)
{
    const auto ibanCountry = country ? *country : random::element(data::supportedIbanCountries);

    const auto& ibanFormat = data::ibanFormats.at(ibanCountry);

    const auto& countryCode = ibanFormat[0];

    std::string iban { countryCode };

    for (size_t i = 1; i < ibanFormat.size(); i++) {
        const auto& ibanFormatEntry = ibanFormat[i];

        const auto ibanFormatEntryDataType = ibanFormatEntry[ibanFormatEntry.size() - 1];
        const auto ibanFormatEntryDataLength
            = std::stoi(std::string(ibanFormatEntry.substr(0, ibanFormatEntry.size() - 1)));

        if (ibanFormatEntryDataType == 'a') {
            iban += string::alpha(
                static_cast<unsigned>(ibanFormatEntryDataLength), string::StringCasing::Upper);
        } else if (ibanFormatEntryDataType == 'c') {
            iban += string::alphanumeric(
                static_cast<unsigned>(ibanFormatEntryDataLength), string::StringCasing::Upper);
        } else if (ibanFormatEntryDataType == 'n') {
            iban += string::numeric(static_cast<unsigned>(ibanFormatEntryDataLength));
        }
    }

    return iban;
}

std::string_view bic(std::optional<BicCountry> country)
{
    const auto bicCountry = country ? *country : random::element(data::supportedBicCountries);

    return random::element(data::bankIdentifiersCodesMapping.at(bicCountry));
}

std::string account_number(unsigned int length) { return string::numeric(length, true); }

std::string pin(unsigned int length) { return string::numeric(length, true); }

std::string routing_number() { return string::numeric(9, true); }

std::string credit_card_number(std::optional<CreditCardType> creditCardType)
{
    static const std::unordered_map<CreditCardType, std::vector<std::string_view>>
        creditCardTypeToNumberFormats {
            { CreditCardType::AmericanExpress,
                { data::americanExpressCreditCardFormats.begin(),
                    data::americanExpressCreditCardFormats.end() } },
            { CreditCardType::Discover,
                { data::discoverCreditCardFormats.begin(),
                    data::discoverCreditCardFormats.end() } },
            { CreditCardType::MasterCard,
                { data::masterCardCreditCardFormats.begin(),
                    data::masterCardCreditCardFormats.end() } },
            { CreditCardType::Visa,
                { data::visaCreditCardFormats.begin(), data::visaCreditCardFormats.end() } },
        };

    static const std::vector<CreditCardType> creditCardTypes { CreditCardType::AmericanExpress,
        CreditCardType::Discover, CreditCardType::MasterCard, CreditCardType::Visa };

    const auto creditCardTargetType
        = creditCardType ? *creditCardType : random::element(creditCardTypes);

    const auto& creditCardFormats = creditCardTypeToNumberFormats.at(creditCardTargetType);

    const auto creditCardFormat = random::element(creditCardFormats);

    return random::replace_credit_card_symbols(std::string(creditCardFormat));
}

std::string credit_card_cvv() { return string::numeric(3, true); }

std::string bitcoin_address()
{
    const unsigned addressLength = number::integer(26u, 33u);

    auto address = random::element(std::vector<std::string> { "1", "3" });

    address += string::alphanumeric(addressLength, string::StringCasing::Mixed, "0OIl");

    return address;
}

std::string litecoin_address()
{
    const unsigned addressLength = number::integer(26u, 33u);

    auto address = random::element(std::vector<std::string> { "L", "M", "3" });

    address += string::alphanumeric(addressLength, string::StringCasing::Mixed, "0OIl");

    return address;
}

std::string ethereum_address() { return string::hexadecimal(40, hex_case::lower); }

std::string credit_card_expiration_date()
{
    const auto expirationDate = date::future(3);
    return expirationDate.substr(5, 2) + "/" + expirationDate.substr(2, 2);
}
}
