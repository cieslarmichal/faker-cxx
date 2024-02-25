#include "../common/format_helper.h"
#include "../common/mappers/precision_mapper/precision_mapper.h"
#include "finance_data.h"
#include <faker/date.h>
#include <faker/finance.h>
#include <faker/helper.h>
#include <faker/number.h>
#include <faker/string.h>

namespace faker::finance {
Currency currency() { return Helper::arrayElement(currencies); }

std::string_view currencyName() { return Helper::arrayElement(currencies).name; }

std::string_view currencyCode() { return Helper::arrayElement(currencies).code; }

std::string_view currencySymbol() { return Helper::arrayElement(currencies).symbol; }

std::string_view accountType() { return Helper::arrayElement(accountTypes); }

std::string amount(double min, double max, Precision precision, const std::string& symbol)
{
    const auto generatedNumber = number::decimal(min, max);

    std::stringstream ss;

    ss << std::fixed;

    ss.precision(PrecisionMapper::mapToDecimalPlaces(precision));

    ss << generatedNumber;

    return FormatHelper::format("{}{}", symbol, ss.str());
}

std::string iban(std::optional<IbanCountry> country)
{
    const auto ibanCountry
        = country ? *country : Helper::arrayElement<IbanCountry>(supportedIbanCountries);

    const auto& ibanFormat = ibanFormats.at(ibanCountry);

    const auto& countryCode = ibanFormat[0];

    std::string iban { countryCode };

    for (size_t i = 1; i < ibanFormat.size(); i++) {
        const auto& ibanFormatEntry = ibanFormat[i];

        const auto ibanFormatEntryDataType = ibanFormatEntry[ibanFormatEntry.size() - 1];
        const auto ibanFormatEntryDataLength
            = std::stoi(std::string(ibanFormatEntry.substr(0, ibanFormatEntry.size() - 1)));

        if (ibanFormatEntryDataType == 'a') {
            iban += string::alpha(
                static_cast<unsigned>(ibanFormatEntryDataLength), StringCasing::Upper);
        } else if (ibanFormatEntryDataType == 'c') {
            iban += string::alphanumeric(
                static_cast<unsigned>(ibanFormatEntryDataLength), StringCasing::Upper);
        } else if (ibanFormatEntryDataType == 'n') {
            iban += string::numeric(static_cast<unsigned>(ibanFormatEntryDataLength));
        }
    }

    return iban;
}

std::string_view bic(std::optional<BicCountry> country)
{
    const auto bicCountry
        = country ? *country : Helper::arrayElement<BicCountry>(supportedBicCountries);

    return Helper::arrayElement(bankIdentifiersCodesMapping.at(bicCountry));
}

std::string accountNumber(unsigned int length) { return string::numeric(length, true); }

std::string pin(unsigned int length) { return string::numeric(length, true); }

std::string routingNumber() { return string::numeric(9, true); }

std::string creditCardNumber(std::optional<CreditCardType> creditCardType)
{
    static const std::unordered_map<CreditCardType, std::vector<std::string_view>>
        creditCardTypeToNumberFormats {
            { CreditCardType::AmericanExpress,
                { americanExpressCreditCardFormats.begin(),
                    americanExpressCreditCardFormats.end() } },
            { CreditCardType::Discover,
                { discoverCreditCardFormats.begin(), discoverCreditCardFormats.end() } },
            { CreditCardType::MasterCard,
                { masterCardCreditCardFormats.begin(), masterCardCreditCardFormats.end() } },
            { CreditCardType::Visa,
                { visaCreditCardFormats.begin(), visaCreditCardFormats.end() } },
        };

    static const std::vector<CreditCardType> creditCardTypes { CreditCardType::AmericanExpress,
        CreditCardType::Discover, CreditCardType::MasterCard, CreditCardType::Visa };

    const auto creditCardTargetType
        = creditCardType ? *creditCardType : Helper::arrayElement<CreditCardType>(creditCardTypes);

    const auto& creditCardFormats = creditCardTypeToNumberFormats.at(creditCardTargetType);

    const auto creditCardFormat = Helper::arrayElement(creditCardFormats);

    return Helper::replaceCreditCardSymbols(std::string(creditCardFormat));
}

std::string creditCardCvv() { return string::numeric(3, true); }

std::string bitcoinAddress()
{
    const unsigned addressLength = number::integer(26u, 33u);

    auto address = Helper::arrayElement<std::string>(std::vector<std::string> { "1", "3" });

    address += string::alphanumeric(addressLength, StringCasing::Mixed, "0OIl");

    return address;
}

std::string litecoinAddress()
{
    const unsigned addressLength = number::integer(26u, 33u);

    auto address = Helper::arrayElement<std::string>(std::vector<std::string> { "L", "M", "3" });

    address += string::alphanumeric(addressLength, StringCasing::Mixed, "0OIl");

    return address;
}

std::string ethereumAddress() { return string::hexadecimal(40, HexCasing::Lower); }

std::string creditCardExpirationDate()
{
    const auto expirationDate = date::futureDate(3);
    return expirationDate.substr(5, 2) + "/" + expirationDate.substr(2, 2);
}
}