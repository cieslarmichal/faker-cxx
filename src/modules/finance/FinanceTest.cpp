#include "faker-cxx/Finance.h"

#include <algorithm>
#include <charconv>
#include <ranges>
#include <regex>

#include "gtest/gtest.h"

#include "../../common/LuhnCheck.h"
#include "../../common/StringHelper.h"
#include "../string/data/Characters.h"
#include "data/AccountTypes.h"
#include "data/BankIndentifiersCodes.h"
#include "data/CreditCardTypeNames.h"
#include "data/Currencies.h"
#include "gmock/gmock.h"

using namespace ::testing;
using namespace faker;

namespace
{
const std::string creditCardCharacters = "0123456789-";
const std::map<Finance::IbanCountry, std::string> expectedRegex{
    {Finance::IbanCountry::Austria, "^(AT)([0-9]{2})([0-9]{5})([0-9]{11})$"},
    {Finance::IbanCountry::Belgium, "^(BE)([0-9]{2})([0-9]{3})([0-9]{7})([0-9]{2})$"},
    {Finance::IbanCountry::Bulgaria, "^(BG)([0-9]{2})([A-Z]{4})([0-9]{4})([0-9]{2})([a-zA-Z0-9]{8})$"},
    {Finance::IbanCountry::Croatia, "^(HR)([0-9]{2})([0-9]{7})([0-9]{10})$"},
    {Finance::IbanCountry::Cyprus, "^(CY)([0-9]{2})([0-9]{3})([0-9]{5})([a-zA-Z0-9]{16})$"},
    {Finance::IbanCountry::Czechia, "^(CZ)([0-9]{2})([0-9]{4})([0-9]{6})([0-9]{10})$"},
    {Finance::IbanCountry::Denmark, "^(DK)([0-9]{2})([0-9]{4})([0-9]{9})([0-9]{1})$"},
    {Finance::IbanCountry::Estonia, "^(EE)([0-9]{2})([0-9]{2})([0-9]{2})([0-9]{11})([0-9]{1})$"},
    {Finance::IbanCountry::Finland, "^(FI)([0-9]{2})([0-9]{6})([0-9]{7})([0-9]{1})$"},
    {Finance::IbanCountry::France, "^(FR)([0-9]{2})([0-9]{5})([0-9]{5})([a-zA-Z0-9]{11})([0-9]{2})$"},
    {Finance::IbanCountry::Germany, "^(DE)([0-9]{2})([0-9]{8})([0-9]{10})$"},
    {Finance::IbanCountry::Greece, "^(GR)([0-9]{2})([0-9]{3})([0-9]{4})([a-zA-Z0-9]{16})$"},
    {Finance::IbanCountry::Hungary, "^(HU)([0-9]{2})([0-9]{3})([0-9]{4})([0-9]{1})([0-9]{15})([0-9]{1})$"},
    {Finance::IbanCountry::Ireland, "^(IE)([0-9]{2})([A-Z]{4})([0-9]{6})([0-9]{8})$"},
    {Finance::IbanCountry::Italy, "^(IT)([0-9]{2})([A-Z]{1})([0-9]{5})([0-9]{5})([a-zA-Z0-9]{12})$"},
    {Finance::IbanCountry::Latvia, "^(LV)([0-9]{2})([A-Z]{4})([a-zA-Z0-9]{13})$"},
    {Finance::IbanCountry::Lithuania, "^(LT)([0-9]{2})([0-9]{5})([0-9]{11})$"},
    {Finance::IbanCountry::Luxembourg, "^(LU)([0-9]{2})([0-9]{3})([a-zA-Z0-9]{13})$"},
    {Finance::IbanCountry::Malta, "^(MT)([0-9]{2})([A-Z]{4})([0-9]{5})([a-zA-Z0-9]{18})$"},
    {Finance::IbanCountry::Netherlands, "^(NL)([0-9]{2})([A-Z]{4})([0-9]{10})$"},
    {Finance::IbanCountry::Poland, "^(PL)([0-9]{2})([0-9]{3})([0-9]{4})([0-9]{1})([0-9]{16})$"},
    {Finance::IbanCountry::Portugal, "^(PT)([0-9]{2})([0-9]{4})([0-9]{4})([0-9]{11})([0-9]{2})$"},
    {Finance::IbanCountry::Romania, "^(RO)([0-9]{2})([A-Z]{4})([a-zA-Z0-9]{16})$"},
    {Finance::IbanCountry::Slovakia, "^(SK)([0-9]{2})([0-9]{4})([0-9]{6})([0-9]{10})$"},
    {Finance::IbanCountry::Slovenia, "^(SI)([0-9]{2})([0-9]{2})([0-9]{3})([0-9]{8})([0-9]{2})$"},
    {Finance::IbanCountry::Spain, "^(ES)([0-9]{2})([0-9]{4})([0-9]{4})([0-9]{2})([0-9]{10})$"},
    {Finance::IbanCountry::Sweden, "^(SE)([0-9]{2})([0-9]{3})([0-9]{17})$"},
};

const std::map<Finance::IbanCountry, std::string> generatedTestName{
    {Finance::IbanCountry::Austria, "shouldGenerateAustriaIban"},
    {Finance::IbanCountry::Belgium, "shouldGenerateBelgiumIban"},
    {Finance::IbanCountry::Bulgaria, "shouldGenerateBulgariaIban"},
    {Finance::IbanCountry::Croatia, "shouldGenerateCroatiaIban"},
    {Finance::IbanCountry::Cyprus, "shouldGenerateCyprusIban"},
    {Finance::IbanCountry::Czechia, "shouldGenerateCzechiaIban"},
    {Finance::IbanCountry::Denmark, "shouldGenerateDenmarkIban"},
    {Finance::IbanCountry::Estonia, "shouldGenerateEstoniaIban"},
    {Finance::IbanCountry::Finland, "shouldGenerateFinlandIban"},
    {Finance::IbanCountry::France, "shouldGenerateFranceIban"},
    {Finance::IbanCountry::Germany, "shouldGenerateGermanyIban"},
    {Finance::IbanCountry::Greece, "shouldGenerateGreeceIban"},
    {Finance::IbanCountry::Hungary, "shouldGenerateHungaryIban"},
    {Finance::IbanCountry::Ireland, "shouldGenerateIrelandIban"},
    {Finance::IbanCountry::Italy, "shouldGenerateItalyIban"},
    {Finance::IbanCountry::Latvia, "shouldGenerateLatviaIban"},
    {Finance::IbanCountry::Lithuania, "shouldGenerateLithuaniaIban"},
    {Finance::IbanCountry::Luxembourg, "shouldGenerateLuxembourgIban"},
    {Finance::IbanCountry::Malta, "shouldGenerateMaltaIban"},
    {Finance::IbanCountry::Netherlands, "shouldGenerateNetherlandsIban"},
    {Finance::IbanCountry::Poland, "shouldGeneratePolandIban"},
    {Finance::IbanCountry::Portugal, "shouldGeneratePortugalIban"},
    {Finance::IbanCountry::Romania, "shouldGenerateRomaniaIban"},
    {Finance::IbanCountry::Slovakia, "shouldGenerateSlovakiaIban"},
    {Finance::IbanCountry::Slovenia, "shouldGenerateSloveniaIban"},
    {Finance::IbanCountry::Spain, "shouldGenerateSpainIban"},
    {Finance::IbanCountry::Sweden, "shouldGenerateSwedenIban"},
};

const std::map<Finance::BicCountry, std::string> generatedBicTestName{
    {Finance::BicCountry::Poland, "shouldGeneratePolandBic"},
    {Finance::BicCountry::UnitedStates, "shouldGenerateUnitedStatesBic"},
    {Finance::BicCountry::UnitedKingdom, "shouldGenerateUnitedKingdomBic"},
    {Finance::BicCountry::Germany, "shouldGenerateGermanyBic"},
    {Finance::BicCountry::Romania, "shouldGenerateRomaniaBic"},
    {Finance::BicCountry::France, "shouldGenerateFranceBic"},
    {Finance::BicCountry::Italy, "shouldGenerateItalyBic"},
    {Finance::BicCountry::Spain, "shouldGenerateSpainBic"},
    {Finance::BicCountry::Netherlands, "shouldGenerateNetherlandsBic"},
    {Finance::BicCountry::India, "shouldGenerateIndiaBic"},
};
}

class FinanceTest : public TestWithParam<Finance::IbanCountry>
{
public:
    static bool checkIfAllCharactersAreNumeric(const std::string& data)
    {
        return std::ranges::all_of(data,
                                   [](char dataCharacter)
                                   {
                                       return std::ranges::any_of(numericCharacters,
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
    const auto generatedCurrency = Finance::currency();

    ASSERT_TRUE(std::ranges::any_of(currencies, [generatedCurrency](const Currency& currency)
                                    { return checkIfCurrenciesAreEqual(currency, generatedCurrency); }));
}

TEST_F(FinanceTest, shouldGenerateCurrencyName)
{
    const auto generatedCurrencyName = Finance::currencyName();

    ASSERT_TRUE(std::ranges::any_of(currencies, [generatedCurrencyName](const Currency& currency)
                                    { return currency.name == generatedCurrencyName; }));
}

TEST_F(FinanceTest, shouldGenerateCurrencyCode)
{
    const auto generatedCurrencyCode = Finance::currencyCode();

    ASSERT_TRUE(std::ranges::any_of(currencies, [generatedCurrencyCode](const Currency& currency)
                                    { return currency.code == generatedCurrencyCode; }));
}

TEST_F(FinanceTest, shouldGenerateCurrencySymbol)
{
    const auto generatedCurrencySymbol = Finance::currencySymbol();

    ASSERT_TRUE(std::ranges::any_of(currencies, [generatedCurrencySymbol](const Currency& currency)
                                    { return currency.symbol == generatedCurrencySymbol; }));
}

TEST_F(FinanceTest, shouldGenerateAccountType)
{
    const auto generatedAccountType = Finance::accountType();

    ASSERT_TRUE(std::ranges::any_of(accountTypes, [generatedAccountType](const std::string& accountType)
                                    { return accountType == generatedAccountType; }));
}

TEST_F(FinanceTest, shouldGenerateAmount)
{
    const auto generatedAmount = Finance::amount();

    auto offset = generatedAmount.size();
    const auto amountAsFloat = std::stof(generatedAmount, &offset);

    const auto generatedAmountParts = StringHelper::split(generatedAmount, ".");

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

    ASSERT_THAT(Finance::iban(ibanCountry), MatchesRegexCpp(expectedRegex.at(ibanCountry)));
}

INSTANTIATE_TEST_SUITE_P(TestIbanGenerator, FinanceTest,
                         ValuesIn(std::views::keys(expectedRegex).begin(), std::views::keys(expectedRegex).end()),
                         [](const TestParamInfo<Finance::IbanCountry>& info)
                         { return generatedTestName.at(info.param); });

TEST_F(FinanceTest, shouldGenerateAmountWithSymbol)
{
    const auto min = 150;
    const auto max = 450;
    const auto precision = Precision::FourDp;
    const std::string currencySymbol = "$";

    const auto generatedAmount = Finance::amount(150, 450, precision, currencySymbol);

    const auto amountAsFloat = std::stof(generatedAmount.substr(currencySymbol.size()));

    const auto generatedAmountParts = StringHelper::split(generatedAmount, ".");

    ASSERT_TRUE(generatedAmount.starts_with(currencySymbol));
    ASSERT_EQ(generatedAmountParts.size(), 2);
    ASSERT_EQ(generatedAmountParts[1].size(), 4);
    ASSERT_GE(amountAsFloat, min);
    ASSERT_LE(amountAsFloat, max);
}

TEST_F(FinanceTest, shouldGenerateIban)
{
    const auto iban = Finance::iban();

    ASSERT_TRUE(iban.starts_with("AT") || iban.starts_with("BE") || iban.starts_with("BG") || iban.starts_with("HR") ||
                iban.starts_with("CY") || iban.starts_with("CZ") || iban.starts_with("DK") || iban.starts_with("EE") ||
                iban.starts_with("FI") || iban.starts_with("FR") || iban.starts_with("DE") || iban.starts_with("GR") ||
                iban.starts_with("HU") || iban.starts_with("IE") || iban.starts_with("IT") || iban.starts_with("LV") ||
                iban.starts_with("LT") || iban.starts_with("LU") || iban.starts_with("MT") || iban.starts_with("NL") ||
                iban.starts_with("PL") || iban.starts_with("PT") || iban.starts_with("RO") || iban.starts_with("SK") ||
                iban.starts_with("SI") || iban.starts_with("ES") || iban.starts_with("SE"));
}

TEST_F(FinanceTest, shouldGenerateAccountNumber)
{
    const auto accountNumber = Finance::accountNumber();

    ASSERT_EQ(accountNumber.size(), 8);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(accountNumber));
}

TEST_F(FinanceTest, shouldGenerateAccountNumberWithSpecifiedLength)
{
    const auto accountNumberLength = 26;

    const auto accountNumber = Finance::accountNumber(accountNumberLength);

    ASSERT_EQ(accountNumber.size(), accountNumberLength);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(accountNumber));
}

TEST_F(FinanceTest, shouldGeneratePinNumber)
{
    const auto pin = Finance::pin();

    ASSERT_EQ(pin.size(), 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(pin));
}

TEST_F(FinanceTest, shouldGeneratePinNumberWithSpecifiedLength)
{
    const auto pinLength = 8;

    const auto pin = Finance::pin(pinLength);

    ASSERT_EQ(pin.size(), pinLength);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(pin));
}

TEST_F(FinanceTest, shouldGenerateRoutingNumber)
{
    const auto routingNumber = Finance::routingNumber();

    ASSERT_EQ(routingNumber.size(), 9);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(routingNumber));
}

TEST_F(FinanceTest, shouldGenerateCreditCardNumber)
{
    const auto creditCardNumber = Finance::creditCardNumber();

    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(LuhnCheck::luhnCheck(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateAmericanExpressCreditCardNumber)
{
    const auto creditCardNumber = Finance::creditCardNumber(Finance::CreditCardType::AmericanExpress);

    ASSERT_TRUE(creditCardNumber.starts_with("34") || creditCardNumber.starts_with("37"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(LuhnCheck::luhnCheck(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateDiscoverCreditCardNumber)
{
    const auto creditCardNumber = Finance::creditCardNumber(Finance::CreditCardType::Discover);

    ASSERT_TRUE(creditCardNumber.starts_with("6011") || creditCardNumber.starts_with("65") ||
                creditCardNumber.starts_with("644") || creditCardNumber.starts_with("645") ||
                creditCardNumber.starts_with("646") || creditCardNumber.starts_with("647") ||
                creditCardNumber.starts_with("648") || creditCardNumber.starts_with("649") ||
                creditCardNumber.starts_with("6011-62"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(LuhnCheck::luhnCheck(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateMasterCardCreditCardNumber)
{
    const auto creditCardNumber = Finance::creditCardNumber(Finance::CreditCardType::MasterCard);

    ASSERT_TRUE(creditCardNumber.starts_with("51") || creditCardNumber.starts_with("52") ||
                creditCardNumber.starts_with("53") || creditCardNumber.starts_with("54") ||
                creditCardNumber.starts_with("55") || creditCardNumber.starts_with("6771-89"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(LuhnCheck::luhnCheck(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateVisaCreditCardNumber)
{
    const auto creditCardNumber = Finance::creditCardNumber(Finance::CreditCardType::Visa);

    ASSERT_TRUE(creditCardNumber.starts_with("4"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(LuhnCheck::luhnCheck(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateCreditCardCvv)
{
    const auto creditCardCvv = Finance::creditCardCvv();

    ASSERT_EQ(creditCardCvv.size(), 3);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(creditCardCvv));
}

TEST_F(FinanceTest, shouldGenerateBitcoinAddress)
{
    const auto bitcoinAddress = Finance::bitcoinAddress();

    ASSERT_GE(bitcoinAddress.size(), 27);
    ASSERT_LE(bitcoinAddress.size(), 34);

    const std::string supportedBitcoinAddressCharacters = "ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz123456789";

    ASSERT_TRUE(bitcoinAddress.starts_with("1") || bitcoinAddress.starts_with("3"));
    ASSERT_TRUE(std::ranges::all_of(bitcoinAddress,
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
    const auto litecoinAddress = Finance::litecoinAddress();

    ASSERT_GE(litecoinAddress.size(), 27);
    ASSERT_LE(litecoinAddress.size(), 34);

    const std::string supportedLitecoinAddressCharacters = "ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz123456789";

    ASSERT_TRUE(litecoinAddress.starts_with("L") || litecoinAddress.starts_with("M") ||
                litecoinAddress.starts_with("3"));
    ASSERT_TRUE(std::ranges::all_of(litecoinAddress,
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
    const auto ethereumAddress = Finance::ethereumAddress();

    const auto prefix = ethereumAddress.substr(0, 2);
    const auto hexNumber = ethereumAddress.substr(2);

    ASSERT_EQ(ethereumAddress.size(), 42);
    ASSERT_EQ(prefix, "0x");
    ASSERT_TRUE(std::ranges::any_of(hexNumber, [hexNumber](char hexNumberCharacter)
                                    { return hexLowerCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(FinanceTest, shouldGenerateExpirationDate)
{
    const auto expirationDate = Finance::creditCardExpirationDate();
    int tenthPlaceYear = std::stoi(expirationDate.substr(3, 2));
    ASSERT_TRUE(tenthPlaceYear >= 24);
}

TEST_F(FinanceTest, shouldGenerateRandomCreditCardTypeName)
{
    const auto creditCardTypeName = Finance::creditCardType();
    ASSERT_TRUE(std::find(faker::creditCardTypeNames.begin(), faker::creditCardTypeNames.end(), creditCardTypeName) !=
                faker::creditCardTypeNames.end());
}

class FinanceBicTest : public TestWithParam<Finance::BicCountry>
{
};

TEST_P(FinanceBicTest, CheckBicGenerator)
{
    const auto country = GetParam();

    const auto bic = Finance::bic(country);

    const auto& bankIdentifiersCodes = bankIdentifiersCodesMapping.at(country);

    ASSERT_TRUE(std::ranges::any_of(bankIdentifiersCodes, [bic](const std::string& bankIdentifierCode)
                                    { return bic == bankIdentifierCode; }));
}

INSTANTIATE_TEST_SUITE_P(TestBicGenerator, FinanceBicTest,
                         Values(Finance::BicCountry::Poland, Finance::BicCountry::UnitedStates,
                                Finance::BicCountry::UnitedKingdom, Finance::BicCountry::Germany,
                                Finance::BicCountry::Romania, Finance::BicCountry::France, Finance::BicCountry::Italy,
                                Finance::BicCountry::Spain, Finance::BicCountry::Netherlands,
                                Finance::BicCountry::India),
                         [](const TestParamInfo<Finance::BicCountry>& info)
                         { return generatedBicTestName.at(info.param); });
