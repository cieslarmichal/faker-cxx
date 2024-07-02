#include "faker-cxx/Finance.h"

#include <algorithm>
#include <ranges>
#include <regex>
#include <string>
#include <string_view>
#include <unordered_map>

#include "gtest/gtest.h"

#include "common/LuhnCheck.h"
#include "common/StringHelper.h"
#include "faker-cxx/types/Precision.h"
#include "finance/FinanceData.h"
#include "gmock/gmock.h"
#include "string/StringData.h"

using namespace ::testing;
using namespace faker;
using namespace faker::finance;

namespace
{
const std::string creditCardCharacters = "0123456789-";
const std::unordered_map<IbanCountry, std::string> expectedRegex{
    {IbanCountry::Austria, "^(AT)([0-9]{2})([0-9]{5})([0-9]{11})$"},
    {IbanCountry::Belgium, "^(BE)([0-9]{2})([0-9]{3})([0-9]{7})([0-9]{2})$"},
    {IbanCountry::Bulgaria, "^(BG)([0-9]{2})([A-Z]{4})([0-9]{4})([0-9]{2})([a-zA-Z0-9]{8})$"},
    {IbanCountry::Croatia, "^(HR)([0-9]{2})([0-9]{7})([0-9]{10})$"},
    {IbanCountry::Cyprus, "^(CY)([0-9]{2})([0-9]{3})([0-9]{5})([a-zA-Z0-9]{16})$"},
    {IbanCountry::Czechia, "^(CZ)([0-9]{2})([0-9]{4})([0-9]{6})([0-9]{10})$"},
    {IbanCountry::Denmark, "^(DK)([0-9]{2})([0-9]{4})([0-9]{9})([0-9]{1})$"},
    {IbanCountry::Estonia, "^(EE)([0-9]{2})([0-9]{2})([0-9]{2})([0-9]{11})([0-9]{1})$"},
    {IbanCountry::Finland, "^(FI)([0-9]{2})([0-9]{6})([0-9]{7})([0-9]{1})$"},
    {IbanCountry::France, "^(FR)([0-9]{2})([0-9]{5})([0-9]{5})([a-zA-Z0-9]{11})([0-9]{2})$"},
    {IbanCountry::Germany, "^(DE)([0-9]{2})([0-9]{8})([0-9]{10})$"},
    {IbanCountry::Greece, "^(GR)([0-9]{2})([0-9]{3})([0-9]{4})([a-zA-Z0-9]{16})$"},
    {IbanCountry::Hungary, "^(HU)([0-9]{2})([0-9]{3})([0-9]{4})([0-9]{1})([0-9]{15})([0-9]{1})$"},
    {IbanCountry::Ireland, "^(IE)([0-9]{2})([A-Z]{4})([0-9]{6})([0-9]{8})$"},
    {IbanCountry::Italy, "^(IT)([0-9]{2})([A-Z]{1})([0-9]{5})([0-9]{5})([a-zA-Z0-9]{12})$"},
    {IbanCountry::Latvia, "^(LV)([0-9]{2})([A-Z]{4})([a-zA-Z0-9]{13})$"},
    {IbanCountry::Lithuania, "^(LT)([0-9]{2})([0-9]{5})([0-9]{11})$"},
    {IbanCountry::Luxembourg, "^(LU)([0-9]{2})([0-9]{3})([a-zA-Z0-9]{13})$"},
    {IbanCountry::Malta, "^(MT)([0-9]{2})([A-Z]{4})([0-9]{5})([a-zA-Z0-9]{18})$"},
    {IbanCountry::Netherlands, "^(NL)([0-9]{2})([A-Z]{4})([0-9]{10})$"},
    {IbanCountry::Poland, "^(PL)([0-9]{2})([0-9]{3})([0-9]{4})([0-9]{1})([0-9]{16})$"},
    {IbanCountry::Portugal, "^(PT)([0-9]{2})([0-9]{4})([0-9]{4})([0-9]{11})([0-9]{2})$"},
    {IbanCountry::Romania, "^(RO)([0-9]{2})([A-Z]{4})([a-zA-Z0-9]{16})$"},
    {IbanCountry::Slovakia, "^(SK)([0-9]{2})([0-9]{4})([0-9]{6})([0-9]{10})$"},
    {IbanCountry::Slovenia, "^(SI)([0-9]{2})([0-9]{2})([0-9]{3})([0-9]{8})([0-9]{2})$"},
    {IbanCountry::Spain, "^(ES)([0-9]{2})([0-9]{4})([0-9]{4})([0-9]{2})([0-9]{10})$"},
    {IbanCountry::Sweden, "^(SE)([0-9]{2})([0-9]{3})([0-9]{17})$"},
};

const std::unordered_map<IbanCountry, std::string> generatedTestName{
    {IbanCountry::Austria, "shouldGenerateAustriaIban"},
    {IbanCountry::Belgium, "shouldGenerateBelgiumIban"},
    {IbanCountry::Bulgaria, "shouldGenerateBulgariaIban"},
    {IbanCountry::Croatia, "shouldGenerateCroatiaIban"},
    {IbanCountry::Cyprus, "shouldGenerateCyprusIban"},
    {IbanCountry::Czechia, "shouldGenerateCzechiaIban"},
    {IbanCountry::Denmark, "shouldGenerateDenmarkIban"},
    {IbanCountry::Estonia, "shouldGenerateEstoniaIban"},
    {IbanCountry::Finland, "shouldGenerateFinlandIban"},
    {IbanCountry::France, "shouldGenerateFranceIban"},
    {IbanCountry::Germany, "shouldGenerateGermanyIban"},
    {IbanCountry::Greece, "shouldGenerateGreeceIban"},
    {IbanCountry::Hungary, "shouldGenerateHungaryIban"},
    {IbanCountry::Ireland, "shouldGenerateIrelandIban"},
    {IbanCountry::Italy, "shouldGenerateItalyIban"},
    {IbanCountry::Latvia, "shouldGenerateLatviaIban"},
    {IbanCountry::Lithuania, "shouldGenerateLithuaniaIban"},
    {IbanCountry::Luxembourg, "shouldGenerateLuxembourgIban"},
    {IbanCountry::Malta, "shouldGenerateMaltaIban"},
    {IbanCountry::Netherlands, "shouldGenerateNetherlandsIban"},
    {IbanCountry::Poland, "shouldGeneratePolandIban"},
    {IbanCountry::Portugal, "shouldGeneratePortugalIban"},
    {IbanCountry::Romania, "shouldGenerateRomaniaIban"},
    {IbanCountry::Slovakia, "shouldGenerateSlovakiaIban"},
    {IbanCountry::Slovenia, "shouldGenerateSloveniaIban"},
    {IbanCountry::Spain, "shouldGenerateSpainIban"},
    {IbanCountry::Sweden, "shouldGenerateSwedenIban"},
};

const std::unordered_map<BicCountry, std::string> generatedBicTestName{
    {BicCountry::Poland, "shouldGeneratePolandBic"},
    {BicCountry::UnitedStates, "shouldGenerateUnitedStatesBic"},
    {BicCountry::UnitedKingdom, "shouldGenerateUnitedKingdomBic"},
    {BicCountry::Germany, "shouldGenerateGermanyBic"},
    {BicCountry::Romania, "shouldGenerateRomaniaBic"},
    {BicCountry::France, "shouldGenerateFranceBic"},
    {BicCountry::Italy, "shouldGenerateItalyBic"},
    {BicCountry::Spain, "shouldGenerateSpainBic"},
    {BicCountry::Netherlands, "shouldGenerateNetherlandsBic"},
    {BicCountry::India, "shouldGenerateIndiaBic"},
};
}

class FinanceTest : public TestWithParam<IbanCountry>
{
public:
    static bool checkIfAllCharactersAreNumeric(const std::string& data)
    {
        return std::ranges::all_of(data,
                                   [](char dataCharacter)
                                   {
                                       return std::ranges::any_of(string::numericCharacters,
                                                                  [dataCharacter](char numericCharacter)
                                                                  { return numericCharacter == dataCharacter; });
                                   });
    }

    static bool checkIfAllCharactersAreCreditCardCharacters(const std::string& data)
    {
        return std::ranges::all_of(data,
                                   [](char dataCharacter)
                                   {
                                       return std::ranges::any_of(creditCardCharacters,
                                                                  [dataCharacter](char creditCardCharacter)
                                                                  { return creditCardCharacter == dataCharacter; });
                                   });
    }

    static bool checkIfCurrenciesAreEqual(const Currency& currency1, const Currency& currency2)
    {
        return currency1.name == currency2.name && currency1.code == currency2.code &&
               currency1.symbol == currency2.symbol;
    }
};

TEST_F(FinanceTest, shouldGenerateCurrency)
{
    const auto generatedCurrency = currency();

    ASSERT_TRUE(std::ranges::any_of(currencies, [generatedCurrency](const Currency& currency)
                                    { return checkIfCurrenciesAreEqual(currency, generatedCurrency); }));
}

TEST_F(FinanceTest, shouldGenerateCurrencyName)
{
    const auto generatedCurrencyName = currencyName();

    ASSERT_TRUE(std::ranges::any_of(currencies, [generatedCurrencyName](const Currency& currency)
                                    { return currency.name == generatedCurrencyName; }));
}

TEST_F(FinanceTest, shouldGenerateCurrencyCode)
{
    const auto generatedCurrencyCode = currencyCode();

    ASSERT_TRUE(std::ranges::any_of(currencies, [generatedCurrencyCode](const Currency& currency)
                                    { return currency.code == generatedCurrencyCode; }));
}

TEST_F(FinanceTest, shouldGenerateCurrencySymbol)
{
    const auto generatedCurrencySymbol = currencySymbol();

    ASSERT_TRUE(std::ranges::any_of(currencies, [generatedCurrencySymbol](const Currency& currency)
                                    { return currency.symbol == generatedCurrencySymbol; }));
}

TEST_F(FinanceTest, shouldGenerateAccountType)
{
    const auto generatedAccountType = accountType();

    ASSERT_TRUE(std::ranges::any_of(accountTypes, [generatedAccountType](const std::string_view& accountType)
                                    { return accountType == generatedAccountType; }));
}

TEST_F(FinanceTest, shouldGenerateAmount)
{
    const auto generatedAmount = amount();

    auto offset = generatedAmount.size();
    const auto amountAsFloat = std::stof(generatedAmount, &offset);

    const auto generatedAmountParts = common::split(generatedAmount, ".");

    ASSERT_EQ(generatedAmountParts.size(), 2);
    ASSERT_EQ(generatedAmountParts[1].size(), 2);
    ASSERT_GE(amountAsFloat, 0);
    ASSERT_LE(amountAsFloat, 1000);
}

/*
 * The default GTest macro "MatchesRegex" has only minimal support on
 * windows. Hence, we define our own macro which uses the c++ default
 * implementation of the used compiler.
 */
MATCHER_P(MatchesRegexCpp, value, "")
{
    return std::regex_match(arg, std::regex(value));
}

TEST_P(FinanceTest, CheckIbanGenerator)
{
    auto ibanCountry = GetParam();

    ASSERT_THAT(iban(ibanCountry), MatchesRegexCpp(expectedRegex.at(ibanCountry)));
}

INSTANTIATE_TEST_SUITE_P(TestIbanGenerator, FinanceTest,
                         ValuesIn(std::views::keys(expectedRegex).begin(), std::views::keys(expectedRegex).end()),
                         [](const TestParamInfo<IbanCountry>& paramInfo)
                         { return generatedTestName.at(paramInfo.param); });

TEST_F(FinanceTest, shouldGenerateAmountWithSymbol)
{
    const auto min = 150;
    const auto max = 450;
    const auto precision = Precision::FourDp;
    const std::string currencySymbol = "$";

    const auto generatedAmount = amount(150, 450, precision, currencySymbol);

    const auto amountAsFloat = std::stof(generatedAmount.substr(currencySymbol.size()));

    const auto generatedAmountParts = common::split(generatedAmount, ".");

    ASSERT_TRUE(generatedAmount.starts_with(currencySymbol));
    ASSERT_EQ(generatedAmountParts.size(), 2);
    ASSERT_EQ(generatedAmountParts[1].size(), 4);
    ASSERT_GE(amountAsFloat, min);
    ASSERT_LE(amountAsFloat, max);
}

TEST_F(FinanceTest, shouldGenerateIban)
{
    const auto generatedIban = iban();

    ASSERT_TRUE(generatedIban.starts_with("AT") || generatedIban.starts_with("BE") || generatedIban.starts_with("BG") ||
                generatedIban.starts_with("HR") || generatedIban.starts_with("CY") || generatedIban.starts_with("CZ") ||
                generatedIban.starts_with("DK") || generatedIban.starts_with("EE") || generatedIban.starts_with("FI") ||
                generatedIban.starts_with("FR") || generatedIban.starts_with("DE") || generatedIban.starts_with("GR") ||
                generatedIban.starts_with("HU") || generatedIban.starts_with("IE") || generatedIban.starts_with("IT") ||
                generatedIban.starts_with("LV") || generatedIban.starts_with("LT") || generatedIban.starts_with("LU") ||
                generatedIban.starts_with("MT") || generatedIban.starts_with("NL") || generatedIban.starts_with("PL") ||
                generatedIban.starts_with("PT") || generatedIban.starts_with("RO") || generatedIban.starts_with("SK") ||
                generatedIban.starts_with("SI") || generatedIban.starts_with("ES") || generatedIban.starts_with("SE"));
}

TEST_F(FinanceTest, shouldGenerateAccountNumber)
{
    const auto generatedAccountNumber = accountNumber();

    ASSERT_EQ(generatedAccountNumber.size(), 8);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedAccountNumber));
}

TEST_F(FinanceTest, shouldGenerateAccountNumberWithSpecifiedLength)
{
    const auto accountNumberLength = 26;

    const auto generatedAccountNumber = accountNumber(accountNumberLength);

    ASSERT_EQ(generatedAccountNumber.size(), accountNumberLength);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedAccountNumber));
}

TEST_F(FinanceTest, shouldGeneratePinNumber)
{
    const auto generatedPin = pin();

    ASSERT_EQ(generatedPin.size(), 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedPin));
}

TEST_F(FinanceTest, shouldGeneratePinNumberWithSpecifiedLength)
{
    const auto pinLength = 8;

    const auto generatedPin = pin(pinLength);

    ASSERT_EQ(generatedPin.size(), pinLength);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedPin));
}

TEST_F(FinanceTest, shouldGenerateRoutingNumber)
{
    const auto generatedRoutingNumber = routingNumber();

    ASSERT_EQ(generatedRoutingNumber.size(), 9);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedRoutingNumber));
}

TEST_F(FinanceTest, shouldGenerateCreditCardNumber)
{
    const auto generatedCreditCardNumber = creditCardNumber();

    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(generatedCreditCardNumber));
    ASSERT_TRUE(common::luhnCheck(generatedCreditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateAmericanExpressCreditCardNumber)
{
    const auto generatedCreditCardNumber = creditCardNumber(CreditCardType::AmericanExpress);

    ASSERT_TRUE(generatedCreditCardNumber.starts_with("34") || generatedCreditCardNumber.starts_with("37"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(generatedCreditCardNumber));
    ASSERT_TRUE(common::luhnCheck(generatedCreditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateDiscoverCreditCardNumber)
{
    const auto generatedCreditCardNumber = creditCardNumber(CreditCardType::Discover);

    ASSERT_TRUE(generatedCreditCardNumber.starts_with("6011") || generatedCreditCardNumber.starts_with("65") ||
                generatedCreditCardNumber.starts_with("644") || generatedCreditCardNumber.starts_with("645") ||
                generatedCreditCardNumber.starts_with("646") || generatedCreditCardNumber.starts_with("647") ||
                generatedCreditCardNumber.starts_with("648") || generatedCreditCardNumber.starts_with("649") ||
                generatedCreditCardNumber.starts_with("6011-62"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(generatedCreditCardNumber));
    ASSERT_TRUE(common::luhnCheck(generatedCreditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateMasterCardCreditCardNumber)
{
    const auto generatedCreditCardNumber = creditCardNumber(CreditCardType::MasterCard);

    ASSERT_TRUE(generatedCreditCardNumber.starts_with("51") || generatedCreditCardNumber.starts_with("52") ||
                generatedCreditCardNumber.starts_with("53") || generatedCreditCardNumber.starts_with("54") ||
                generatedCreditCardNumber.starts_with("55") || generatedCreditCardNumber.starts_with("6771-89"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(generatedCreditCardNumber));
    ASSERT_TRUE(common::luhnCheck(generatedCreditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateVisaCreditCardNumber)
{
    const auto generatedCreditCardNumber = creditCardNumber(CreditCardType::Visa);

    ASSERT_TRUE(generatedCreditCardNumber.starts_with("4"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(generatedCreditCardNumber));
    ASSERT_TRUE(common::luhnCheck(generatedCreditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateCreditCardCvv)
{
    const auto generatedCreditCardCvv = creditCardCvv();

    ASSERT_EQ(generatedCreditCardCvv.size(), 3);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(generatedCreditCardCvv));
}

TEST_F(FinanceTest, shouldGenerateBitcoinAddress)
{
    const auto generatedBitcoinAddress = bitcoinAddress();

    ASSERT_GE(generatedBitcoinAddress.size(), 27);
    ASSERT_LE(generatedBitcoinAddress.size(), 34);

    const std::string supportedBitcoinAddressCharacters = "ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz123456789";

    ASSERT_TRUE(generatedBitcoinAddress.starts_with("1") || generatedBitcoinAddress.starts_with("3"));
    ASSERT_TRUE(std::ranges::all_of(generatedBitcoinAddress,
                                    [&supportedBitcoinAddressCharacters](char dataCharacter)
                                    {
                                        return std::ranges::any_of(
                                            supportedBitcoinAddressCharacters,
                                            [dataCharacter](char supportedBitcoinAddressCharacter)
                                            { return supportedBitcoinAddressCharacter == dataCharacter; });
                                    }));
}

TEST_F(FinanceTest, shouldGenerateLitecoinAddress)
{
    const auto generatedLitecoinAddress = litecoinAddress();

    ASSERT_GE(generatedLitecoinAddress.size(), 27);
    ASSERT_LE(generatedLitecoinAddress.size(), 34);

    const std::string supportedLitecoinAddressCharacters = "ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz123456789";

    ASSERT_TRUE(generatedLitecoinAddress.starts_with("L") || generatedLitecoinAddress.starts_with("M") ||
                generatedLitecoinAddress.starts_with("3"));
    ASSERT_TRUE(std::ranges::all_of(generatedLitecoinAddress,
                                    [&supportedLitecoinAddressCharacters](char dataCharacter)
                                    {
                                        return std::ranges::any_of(
                                            supportedLitecoinAddressCharacters,
                                            [dataCharacter](char supportedLitecoinAddressCharacter)
                                            { return supportedLitecoinAddressCharacter == dataCharacter; });
                                    }));
}

TEST_F(FinanceTest, shouldGenerateEthereumAddress)
{
    const auto generatedEthereumAddress = ethereumAddress();

    const auto prefix = generatedEthereumAddress.substr(0, 2);
    const auto hexNumber = generatedEthereumAddress.substr(2);

    ASSERT_EQ(generatedEthereumAddress.size(), 42);
    ASSERT_EQ(prefix, "0x");
    ASSERT_TRUE(
        std::ranges::any_of(hexNumber, [hexNumber](char hexNumberCharacter)
                            { return string::hexLowerCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(FinanceTest, shouldGenerateExpirationDate)
{
    const auto expirationDate = creditCardExpirationDate();

    const int tenthPlaceYear = std::stoi(expirationDate.substr(3, 2));

    ASSERT_TRUE(tenthPlaceYear >= 24);
}

TEST_F(FinanceTest, shouldGenerateRandomCreditCardTypeName)
{
    const auto creditCardTypeName = creditCardType();

    ASSERT_TRUE(std::find(creditCardNames.begin(), creditCardNames.end(), creditCardTypeName) != creditCardNames.end());
}

class FinanceBicTest : public TestWithParam<BicCountry>
{
};

TEST_P(FinanceBicTest, CheckBicGenerator)
{
    const auto country = GetParam();

    const auto generatedBic = bic(country);

    const auto& bankIdentifiersCodes = bicCountriesCodes.at(country);

    ASSERT_TRUE(std::ranges::any_of(bankIdentifiersCodes, [generatedBic](const std::string_view& bankIdentifierCode)
                                    { return generatedBic == bankIdentifierCode; }));
}

INSTANTIATE_TEST_SUITE_P(TestBicGenerator, FinanceBicTest,
                         Values(BicCountry::Poland, BicCountry::UnitedStates, BicCountry::UnitedKingdom,
                                BicCountry::Germany, BicCountry::Romania, BicCountry::France, BicCountry::Italy,
                                BicCountry::Spain, BicCountry::Netherlands, BicCountry::India),
                         [](const TestParamInfo<BicCountry>& paramInfo)
                         { return generatedBicTestName.at(paramInfo.param); });
