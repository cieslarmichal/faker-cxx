#include "faker-cxx/Finance.h"

#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include "../../common/FormatHelper.h"
#include "faker-cxx/Date.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"
#include "faker-cxx/types/Hex.h"
#include "faker-cxx/types/Precision.h"
#include "FinanceData.h"


namespace faker::finance
{

Currency currency()
{
    return Helper::arrayElement(currencies);
}

std::string_view currencyName()
{
    return Helper::arrayElement(currencies).name;
}

std::string_view currencyCode()
{
    return Helper::arrayElement(currencies).code;
}

std::string_view currencySymbol()
{
    return Helper::arrayElement(currencies).symbol;
}

std::string_view accountType()
{
    return Helper::arrayElement(accountTypes);
}

std::string amount(double min, double max, Precision precision, const std::string& symbol)
{
    const std::floating_point auto generatedNumber = number::decimal<double>(min, max);

    std::string result{symbol};

    result += FormatHelper::precisionFormat(precision, generatedNumber);

    return result;
}

std::string iban(std::optional<IbanCountry> country)
{
    const auto ibanCountry = country ? *country : Helper::arrayElement(ibanCountries);

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
            iban += String::alpha(static_cast<unsigned>(ibanFormatEntryDataLength), StringCasing::Upper);
        }
        else if (ibanFormatEntryDataType == 'c')
        {
            iban += String::alphanumeric(static_cast<unsigned>(ibanFormatEntryDataLength), StringCasing::Upper);
        }
        else if (ibanFormatEntryDataType == 'n')
        {
            iban += String::numeric(static_cast<unsigned>(ibanFormatEntryDataLength));
        }
    }

    return iban;
}

std::string_view bic(std::optional<BicCountry> country)
{
    const auto bicCountry = country ? *country : Helper::arrayElement(bicCountries);

    return Helper::arrayElement(bicCountriesCodes.at(bicCountry));
}

std::string accountNumber(unsigned int length)
{
    return String::numeric(length, true);
}

std::string pin(unsigned int length)
{
    return String::numeric(length, true);
}

std::string routingNumber()
{
    return String::numeric(9, true);
}

std::string creditCardNumber(std::optional<CreditCardType> creditCardType)
{
    const auto creditCardTargetType = creditCardType ? *creditCardType : Helper::arrayElement(creditCardTypes);

    switch (creditCardTargetType)
    {
    case CreditCardType::AmericanExpress:
        return Helper::replaceCreditCardSymbols(
            static_cast<std::string>(Helper::arrayElement(americanExpressCreditCardFormats)));
    case CreditCardType::Discover:
        return Helper::replaceCreditCardSymbols(
            static_cast<std::string>(Helper::arrayElement(discoverCreditCardFormats)));
    case CreditCardType::MasterCard:
        return Helper::replaceCreditCardSymbols(
            static_cast<std::string>(Helper::arrayElement(masterCardCreditCardFormats)));
    case CreditCardType::Visa:
        return Helper::replaceCreditCardSymbols(static_cast<std::string>(Helper::arrayElement(visaCreditCardFormats)));
    }

    return "";
}

std::string creditCardCvv()
{
    return String::numeric(3, true);
}

std::string bitcoinAddress()
{
    const unsigned addressLength = number::integer(26u, 33u);

    auto address = Helper::arrayElement(std::vector<std::string>{"1", "3"});

    address += String::alphanumeric(addressLength, StringCasing::Mixed, "0OIl");

    return address;
}

std::string litecoinAddress()
{
    const unsigned addressLength = number::integer(26u, 33u);

    auto address = Helper::arrayElement(std::vector<std::string>{"L", "M", "3"});

    address += String::alphanumeric(addressLength, StringCasing::Mixed, "0OIl");

    return address;
}

std::string ethereumAddress()
{
    return String::hexadecimal(40, HexCasing::Lower);
}

std::string creditCardExpirationDate()
{
    const auto expirationDate = faker::date::futureDate(3);

    return expirationDate.substr(5, 2) + "/" + expirationDate.substr(2, 2);
}

std::string_view creditCardType()
{
    return Helper::arrayElement(creditCardNames);
}

}
