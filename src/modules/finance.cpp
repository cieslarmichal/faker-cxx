#include "faker-cxx/finance.h"

#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "common/algo_helper.h"
#include "common/format_helper.h"
#include "faker-cxx/date.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "faker-cxx/string.h"
#include "faker-cxx/types/hex.h"
#include "faker-cxx/types/precision.h"
#include "finance_data.h"

namespace faker::finance
{

Currency currency()
{
    return helper::randomElement(currencies);
}

std::string_view currencyName()
{
    return helper::randomElement(currencies).name;
}

std::string_view currencyCode()
{
    return helper::randomElement(currencies).code;
}

std::string_view currencySymbol()
{
    return helper::randomElement(currencies).symbol;
}

std::string_view accountType()
{
    return helper::randomElement(accountTypes);
}

std::string amount(double min, double max, Precision precision, const std::string& symbol)
{
    const std::floating_point auto generatedNumber = number::decimal<double>(min, max);

    std::string result{symbol};

    result += common::precisionFormat(precision, generatedNumber);

    return result;
}

std::string iban(std::optional<IbanCountry> country)
{
    const auto ibanCountry = country ? *country : helper::randomElement(ibanCountries);

    const auto& ibanFormat = ibanFormats.at(ibanCountry);

    const auto& countryCode = ibanFormat[0];

    std::string iban{countryCode};

    for (size_t i = 1; i < ibanFormat.size(); i++)
    {
        const auto& ibanFormatEntry = ibanFormat[i];

        const auto ibanFormatEntryDataType = ibanFormatEntry[ibanFormatEntry.size() - 1];
        const auto ibanFormatEntryDataLength =
            std::stoi(static_cast<const std::string>(ibanFormatEntry.substr(0, ibanFormatEntry.size() - 1)));

        if (ibanFormatEntryDataType == 'a')
        {
            iban += string::alpha(static_cast<unsigned>(ibanFormatEntryDataLength), string::StringCasing::Upper);
        }
        else if (ibanFormatEntryDataType == 'c')
        {
            iban += string::alphanumeric(static_cast<unsigned>(ibanFormatEntryDataLength), string::StringCasing::Upper);
        }
        else if (ibanFormatEntryDataType == 'n')
        {
            iban += string::numeric(static_cast<unsigned>(ibanFormatEntryDataLength));
        }
    }

    return iban;
}

std::string_view bic(std::optional<BicCountry> country)
{
    const auto bicCountry = country ? *country : helper::randomElement(bicCountries);

    return helper::randomElement(bicCountriesCodes.at(bicCountry));
}

std::string accountNumber(unsigned int length)
{
    return string::numeric(length, true);
}

std::string pin(unsigned int length)
{
    return string::numeric(length, true);
}

std::string routingNumber()
{
    return string::numeric(9, true);
}

std::string creditCardNumber(std::optional<CreditCardType> creditCardType)
{
    const auto creditCardTargetType = creditCardType ? *creditCardType : helper::randomElement(creditCardTypes);

    switch (creditCardTargetType)
    {
    case CreditCardType::AmericanExpress:
        return helper::replaceCreditCardSymbols(
            static_cast<std::string>(helper::randomElement(americanExpressCreditCardFormats)));
    case CreditCardType::Discover:
        return helper::replaceCreditCardSymbols(
            static_cast<std::string>(helper::randomElement(discoverCreditCardFormats)));
    case CreditCardType::MasterCard:
        return helper::replaceCreditCardSymbols(
            static_cast<std::string>(helper::randomElement(masterCardCreditCardFormats)));
    case CreditCardType::Visa:
        return helper::replaceCreditCardSymbols(static_cast<std::string>(helper::randomElement(visaCreditCardFormats)));
    default:;
    }

    return "";
}

std::string creditCardCvv()
{
    return string::numeric(3, true);
}

std::string bitcoinAddress()
{
    const unsigned addressLength = number::integer(26u, 33u);

    auto address = helper::randomElement(std::vector<std::string>{"1", "3"});

    address += string::alphanumeric(addressLength, string::StringCasing::Mixed, "0OIl");

    return address;
}

std::string litecoinAddress()
{
    const unsigned addressLength = number::integer(26u, 33u);

    auto address = helper::randomElement(std::vector<std::string>{"L", "M", "3"});

    address += string::alphanumeric(addressLength, string::StringCasing::Mixed, "0OIl");

    return address;
}

std::string ethereumAddress()
{
    return string::hexadecimal(40, HexCasing::Lower);
}

std::string creditCardExpirationDate()
{
    const auto expirationDate = faker::date::futureDate(3);

    return expirationDate.substr(5, 2) + "/" + expirationDate.substr(2, 2);
}

std::string_view creditCardType()
{
    return helper::randomElement(creditCardNames);
}

}
