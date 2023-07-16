#include "include/faker-cxx/Finance.h"

#include <format>
#include <sstream>

#include "data/AccountTypes.h"
#include "data/BankIndentifiersCodes.h"
#include "data/Currencies.h"
#include "data/IbanFormats.h"
#include "include/faker-cxx/Helper.h"
#include "include/faker-cxx/Number.h"
#include "include/faker-cxx/String.h"

namespace faker
{

std::string Finance::currencyCode()
{
    return Helper::arrayElement<std::string>(currenciesCodes);
}

std::string Finance::accountType()
{
    return Helper::arrayElement<std::string>(accountTypes);
}

std::string Finance::amount(double min, double max, unsigned int decimalPlaces, const std::string& symbol)
{
    const std::floating_point auto generatedNumber = Number::decimal<double>(min, max);

    std::stringstream ss;

    ss << std::fixed;

    ss.precision(decimalPlaces);

    ss << generatedNumber;

    return std::format("{}{}", symbol, ss.str());
}

std::string Finance::iban(std::optional<Country> country)
{
    const auto ibanCountry = country ? *country : Helper::arrayElement<Country>(supportedIbanCountries);

    // TODO: error handling
    const auto& ibanFormat = ibanFormats.at(ibanCountry);

    const auto& countryCode = ibanFormat[0];

    std::string iban{countryCode};

    for (size_t i = 1; i < ibanFormat.size(); i++)
    {
        const auto& ibanFormatEntry = ibanFormat[i];

        const auto ibanFormatEntryDataType = ibanFormatEntry[ibanFormatEntry.size() - 1];
        const auto ibanFormatEntryDataLength = std::stoi(ibanFormatEntry.substr(0, ibanFormatEntry.size() - 1));

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

std::string Finance::bic(std::optional<Country> country)
{
    const auto bicCountry = country ? *country : Helper::arrayElement<Country>(supportedBankIdentifiersCodesCountries);

    // TODO: error handling
    return Helper::arrayElement<std::string>(bankIdentifiersCodesMapping.at(bicCountry));
}

std::string Finance::accountNumber(unsigned int length)
{
    return String::numeric(length, true);
}

std::string Finance::pin(unsigned int length)
{
    return String::numeric(length, true);
}
}
