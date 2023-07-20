#include "faker-cxx/Finance.h"

#include <format>
#include <numeric>

#include "data/AccountTypes.h"
#include "data/BankIndentifiersCodes.h"
#include "data/CreditCardsFormats.h"
#include "data/Currencies.h"
#include "data/IbanFormats.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"

namespace faker
{
namespace
{
const std::map<CreditCardType, std::vector<std::string>> creditCardTypeToNumberFormats{
    {CreditCardType::AmericanExpress, americanExpressCreditCardFormats},
    {CreditCardType::Discover, discoverCreditCardFormats},
    {CreditCardType::MasterCard, masterCardCreditCardFormats},
    {CreditCardType::Visa, visaCreditCardFormats},
};

const std::vector<CreditCardType> creditCardTypes{CreditCardType::AmericanExpress, CreditCardType::Discover,
                                                  CreditCardType::MasterCard, CreditCardType::Visa};
}

std::string Finance::currencyCode()
{
    return Helper::arrayElement<std::string>(currenciesCodes);
}

std::string Finance::accountType()
{
    return Helper::arrayElement<std::string>(accountTypes);
}

std::string Finance::amount(double min, double max, Precision precision, const std::string& symbol)
{
    const std::floating_point auto generatedNumber = Number::decimal<double>(min, max);

    std::stringstream ss;

    ss << std::fixed;

    ss.precision(toDecimalPlaces(precision));

    ss << generatedNumber;

    return std::format("{}{}", symbol, ss.str());
}

std::string Finance::iban(std::optional<IbanCountry> country)
{
    const auto ibanCountry = country ? *country : Helper::arrayElement<IbanCountry>(supportedIbanCountries);

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

std::string Finance::bic(std::optional<BicCountry> country)
{
    const auto bicCountry = country ? *country : Helper::arrayElement<BicCountry>(supportedBicCountries);

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

std::string Finance::routingNumber()
{
    return String::numeric(9, true);
}

std::string Finance::creditCardNumber(std::optional<CreditCardType> creditCardType)
{
    const auto creditCardTargetType =
        creditCardType ? *creditCardType : Helper::arrayElement<CreditCardType>(creditCardTypes);

    const auto& creditCardFormats = creditCardTypeToNumberFormats.at(creditCardTargetType);

    const auto creditCardFormat = Helper::arrayElement<std::string>(creditCardFormats);

    std::string creditCardNumberPayload;

    for (const auto& creditCardFormatCharacter : creditCardFormat)
    {
        if (creditCardFormatCharacter == '#')
        {
            creditCardNumberPayload += String::numeric(1);
        }
        else
        {
            creditCardNumberPayload += creditCardFormatCharacter;
        }
    }

    std::vector<int> creditCardNumberPayloadAsDigits;

    for (const auto& creditCardNumberPayloadEntry : creditCardNumberPayload)
    {
        if (creditCardNumberPayloadEntry != '-')
        {
            creditCardNumberPayloadAsDigits.push_back(std::stoi(std::string{creditCardNumberPayloadEntry}));
        }
    }

    // Luhn algorithm: https://en.wikipedia.org/wiki/Luhn_algorithm

    for (int i = static_cast<int>(creditCardNumberPayloadAsDigits.size()) - 1; i >= 0; i = i - 2)
    {
        creditCardNumberPayloadAsDigits[static_cast<unsigned>(i)] =
            2 * creditCardNumberPayloadAsDigits[static_cast<unsigned>(i)];
    }

    for (auto& creditCardNumberPayloadAsDigitsEntry : creditCardNumberPayloadAsDigits)
    {
        if (creditCardNumberPayloadAsDigitsEntry >= 10)
        {
            const auto tensDigit = creditCardNumberPayloadAsDigitsEntry / 10;
            const auto onesDigit = creditCardNumberPayloadAsDigitsEntry % 10;

            creditCardNumberPayloadAsDigitsEntry = tensDigit + onesDigit;
        }
    }

    const auto digitsSum =
        std::accumulate(creditCardNumberPayloadAsDigits.begin(), creditCardNumberPayloadAsDigits.end(), 0);

    auto checkSum = 10 - (digitsSum % 10);

    if (checkSum == 10)
    {
        checkSum = 0;
    }

    return std::format("{}{}", creditCardNumberPayload, checkSum);
}
}
