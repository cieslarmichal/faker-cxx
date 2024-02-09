#include "faker-cxx/Finance.h"

#include "../../common/FormatHelper.h"
#include "../../common/mappers/precisionMapper/PrecisionMapper.h"
#include "data/AccountTypes.h"
#include "data/BankIndentifiersCodes.h"
#include "data/CreditCardsFormats.h"
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
const std::map<CreditCardType, std::vector<std::string>> creditCardTypeToNumberFormats{
    {CreditCardType::AmericanExpress, americanExpressCreditCardFormats},
    {CreditCardType::Discover, discoverCreditCardFormats},
    {CreditCardType::MasterCard, masterCardCreditCardFormats},
    {CreditCardType::Visa, visaCreditCardFormats},
};

const std::vector<CreditCardType> creditCardTypes{CreditCardType::AmericanExpress, CreditCardType::Discover,
                                                  CreditCardType::MasterCard, CreditCardType::Visa};
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

std::string Finance::iban(std::optional<IbanCountry> country)
{
    const auto ibanCountry = country ? *country : Helper::arrayElement<IbanCountry>(supportedIbanCountries);

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

std::string Finance::creditCardType(const std::string& creditCardNumber)
{
    //Visa: starts with 4
    //MasterCard: starts with 5[1-5] or 6771-89
    //Amer. Ex.: starts with 34 or 37
    //Discover: starts with 6011, 65, 64[4-9], 6011-62, 65##-62, or 64[4-9]#-62

    if ((creditCardNumber.front()) == '4' && (creditCardNumber.length() == 13 || creditCardNumber.length() == 16)){
        return "Visa";
    }
    else if (((creditCardNumber.substr(0, 2) >= "51" && creditCardNumber.substr(0, 2) <= "55") || (creditCardNumber.substr(0, 6) == "677189")) && (creditCardNumber.length() == 16)){
        return "MasterCard";
    }
    else if ((creditCardNumber.substr(0, 2) == "34" || creditCardNumber.substr(0, 2) == "37") && (creditCardNumber.length() == 15)){
        return "American Express";
    }
    else if ((creditCardNumber.substr(0, 4) == "6011" || creditCardNumber.substr(0, 2) == "65" || (creditCardNumber.substr(0, 3) >= "644" && creditCardNumber.substr(0, 3) <= "649") || creditCardNumber.substr(0, 6) >= "601162" || (creditCardNumber.substr(0, 2) == "65" && creditCardNumber.substr(5, 7) == "62") || ((creditCardNumber.substr(0, 3) == "644" || creditCardNumber.substr(0, 3) == "645" || creditCardNumber.substr(0, 3) == "646" || creditCardNumber.substr(0, 3) == "647" || creditCardNumber.substr(0, 3) == "648" || creditCardNumber.substr(0, 3) == "649") && creditCardNumber.substr(5, 7) == "62")) && (creditCardNumber.length() == 20 || creditCardNumber.length() == 16)){
        return "Discover";
    }
    else{
        return "Unknown";
    }
}
}
