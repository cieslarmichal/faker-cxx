#include "faker-cxx/Finance.h"

#include "../../common/FormatHelper.h"
#include "../../common/PrecisionMapper.h"
#include "data/AccountTypes.h"
#include "data/BankIndentifiersCodes.h"
#include "data/CreditCardsFormats.h"
#include "data/CreditCardTypeNames.h"
#include "data/Currencies.h"
#include "data/IbanFormats.h"
#include "faker-cxx/Date.h"
#include "faker-cxx/Helper.h"
#include "faker-cxx/Number.h"
#include "faker-cxx/String.h"

namespace faker
{
namespace
{
const std::vector<Finance::BicCountry> supportedBicCountries{
    Finance::BicCountry::Poland,  Finance::BicCountry::UnitedStates, Finance::BicCountry::UnitedKingdom,
    Finance::BicCountry::Germany, Finance::BicCountry::Romania,      Finance::BicCountry::France,
    Finance::BicCountry::Italy,   Finance::BicCountry::Spain,        Finance::BicCountry::Netherlands,
    Finance::BicCountry::India};

const std::vector<Finance::IbanCountry> supportedIbanCountries{
    Finance::IbanCountry::Austria,  Finance::IbanCountry::Belgium,     Finance::IbanCountry::Bulgaria,
    Finance::IbanCountry::Croatia,  Finance::IbanCountry::Cyprus,      Finance::IbanCountry::Czechia,
    Finance::IbanCountry::Denmark,  Finance::IbanCountry::Estonia,     Finance::IbanCountry::Finland,
    Finance::IbanCountry::France,   Finance::IbanCountry::Germany,     Finance::IbanCountry::Greece,
    Finance::IbanCountry::Hungary,  Finance::IbanCountry::Ireland,     Finance::IbanCountry::Italy,
    Finance::IbanCountry::Latvia,   Finance::IbanCountry::Lithuania,   Finance::IbanCountry::Luxembourg,
    Finance::IbanCountry::Malta,    Finance::IbanCountry::Netherlands, Finance::IbanCountry::Poland,
    Finance::IbanCountry::Portugal, Finance::IbanCountry::Romania,     Finance::IbanCountry::Slovakia,
    Finance::IbanCountry::Slovenia, Finance::IbanCountry::Spain,       Finance::IbanCountry::Sweden,
};

const std::unordered_map<Finance::CreditCardType, std::vector<std::string>> creditCardTypeToNumberFormats{
    {Finance::CreditCardType::AmericanExpress, americanExpressCreditCardFormats},
    {Finance::CreditCardType::Discover, discoverCreditCardFormats},
    {Finance::CreditCardType::MasterCard, masterCardCreditCardFormats},
    {Finance::CreditCardType::Visa, visaCreditCardFormats},
};

const std::vector<Finance::CreditCardType> creditCardTypes{
    Finance::CreditCardType::AmericanExpress, Finance::CreditCardType::Discover, Finance::CreditCardType::MasterCard,
    Finance::CreditCardType::Visa};
}

Currency Finance::currency()
{
    return Helper::arrayElement<Currency>(currencies);
}

std::string Finance::currencyName()
{
    return Helper::arrayElement<Currency>(currencies).name;
}

std::string Finance::currencyCode()
{
    return Helper::arrayElement<Currency>(currencies).code;
}

std::string Finance::currencySymbol()
{
    return Helper::arrayElement<Currency>(currencies).symbol;
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

    ss.precision(PrecisionMapper::mapToDecimalPlaces(precision));

    ss << generatedNumber;

    return FormatHelper::format("{}{}", symbol, ss.str());
}

std::string Finance::iban(std::optional<Finance::IbanCountry> country)
{
    const auto ibanCountry = country ? *country : Helper::arrayElement<Finance::IbanCountry>(supportedIbanCountries);

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

std::string Finance::bic(std::optional<Finance::BicCountry> country)
{
    const auto bicCountry = country ? *country : Helper::arrayElement<Finance::BicCountry>(supportedBicCountries);

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

std::string Finance::creditCardNumber(std::optional<Finance::CreditCardType> creditCardType)
{
    const auto creditCardTargetType =
        creditCardType ? *creditCardType : Helper::arrayElement<Finance::CreditCardType>(creditCardTypes);

    const auto& creditCardFormats = creditCardTypeToNumberFormats.at(creditCardTargetType);

    const auto creditCardFormat = Helper::arrayElement<std::string>(creditCardFormats);

    return Helper::replaceCreditCardSymbols(creditCardFormat);
}

std::string Finance::creditCardCvv()
{
    return String::numeric(3, true);
}

std::string Finance::bitcoinAddress()
{
    const unsigned addressLength = Number::integer(26u, 33u);

    auto address = Helper::arrayElement<std::string>(std::vector<std::string>{"1", "3"});

    address += String::alphanumeric(addressLength, StringCasing::Mixed, "0OIl");

    return address;
}

std::string Finance::litecoinAddress()
{
    const unsigned addressLength = Number::integer(26u, 33u);

    auto address = Helper::arrayElement<std::string>(std::vector<std::string>{"L", "M", "3"});

    address += String::alphanumeric(addressLength, StringCasing::Mixed, "0OIl");

    return address;
}

std::string Finance::ethereumAddress()
{
    return String::hexadecimal(40, HexCasing::Lower);
}

std::string Finance::creditCardExpirationDate()
{
    const auto expirationDate = Date::futureDate(3);
    return expirationDate.substr(5, 2) + "/" + expirationDate.substr(2, 2);
}

std::string Finance::creditCardType()
{
    return Helper::arrayElement<std::string>(creditCardTypeNames);
}

}
