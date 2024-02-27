#include "../test_helpers.h"
#include <algorithm>
#include <charconv>
#include <common/luhn_check.h>
#include <common/string_helper.h>
#include <faker/finance.h>
#include <gmock/gmock.h>
#include <modules/finance_data.h>
#include <modules/string_data.h>
#include <ranges>
#include <regex>

using namespace ::testing;
using namespace faker;

namespace {
const std::string creditCardCharacters = "0123456789-";
const std::unordered_map<finance::IbanCountry, std::string> expectedRegex {
    { finance::IbanCountry::Austria, "^(AT)([0-9]{2})([0-9]{5})([0-9]{11})$" },
    { finance::IbanCountry::Belgium, "^(BE)([0-9]{2})([0-9]{3})([0-9]{7})([0-9]{2})$" },
    { finance::IbanCountry::Bulgaria,
        "^(BG)([0-9]{2})([A-Z]{4})([0-9]{4})([0-9]{2})([a-zA-Z0-9]{8})$" },
    { finance::IbanCountry::Croatia, "^(HR)([0-9]{2})([0-9]{7})([0-9]{10})$" },
    { finance::IbanCountry::Cyprus, "^(CY)([0-9]{2})([0-9]{3})([0-9]{5})([a-zA-Z0-9]{16})$" },
    { finance::IbanCountry::Czechia, "^(CZ)([0-9]{2})([0-9]{4})([0-9]{6})([0-9]{10})$" },
    { finance::IbanCountry::Denmark, "^(DK)([0-9]{2})([0-9]{4})([0-9]{9})([0-9]{1})$" },
    { finance::IbanCountry::Estonia, "^(EE)([0-9]{2})([0-9]{2})([0-9]{2})([0-9]{11})([0-9]{1})$" },
    { finance::IbanCountry::Finland, "^(FI)([0-9]{2})([0-9]{6})([0-9]{7})([0-9]{1})$" },
    { finance::IbanCountry::France,
        "^(FR)([0-9]{2})([0-9]{5})([0-9]{5})([a-zA-Z0-9]{11})([0-9]{2})$" },
    { finance::IbanCountry::Germany, "^(DE)([0-9]{2})([0-9]{8})([0-9]{10})$" },
    { finance::IbanCountry::Greece, "^(GR)([0-9]{2})([0-9]{3})([0-9]{4})([a-zA-Z0-9]{16})$" },
    { finance::IbanCountry::Hungary,
        "^(HU)([0-9]{2})([0-9]{3})([0-9]{4})([0-9]{1})([0-9]{15})([0-9]{1})$" },
    { finance::IbanCountry::Ireland, "^(IE)([0-9]{2})([A-Z]{4})([0-9]{6})([0-9]{8})$" },
    { finance::IbanCountry::Italy,
        "^(IT)([0-9]{2})([A-Z]{1})([0-9]{5})([0-9]{5})([a-zA-Z0-9]{12})$" },
    { finance::IbanCountry::Latvia, "^(LV)([0-9]{2})([A-Z]{4})([a-zA-Z0-9]{13})$" },
    { finance::IbanCountry::Lithuania, "^(LT)([0-9]{2})([0-9]{5})([0-9]{11})$" },
    { finance::IbanCountry::Luxembourg, "^(LU)([0-9]{2})([0-9]{3})([a-zA-Z0-9]{13})$" },
    { finance::IbanCountry::Malta, "^(MT)([0-9]{2})([A-Z]{4})([0-9]{5})([a-zA-Z0-9]{18})$" },
    { finance::IbanCountry::Netherlands, "^(NL)([0-9]{2})([A-Z]{4})([0-9]{10})$" },
    { finance::IbanCountry::Poland, "^(PL)([0-9]{2})([0-9]{3})([0-9]{4})([0-9]{1})([0-9]{16})$" },
    { finance::IbanCountry::Portugal, "^(PT)([0-9]{2})([0-9]{4})([0-9]{4})([0-9]{11})([0-9]{2})$" },
    { finance::IbanCountry::Romania, "^(RO)([0-9]{2})([A-Z]{4})([a-zA-Z0-9]{16})$" },
    { finance::IbanCountry::Slovakia, "^(SK)([0-9]{2})([0-9]{4})([0-9]{6})([0-9]{10})$" },
    { finance::IbanCountry::Slovenia, "^(SI)([0-9]{2})([0-9]{2})([0-9]{3})([0-9]{8})([0-9]{2})$" },
    { finance::IbanCountry::Spain, "^(ES)([0-9]{2})([0-9]{4})([0-9]{4})([0-9]{2})([0-9]{10})$" },
    { finance::IbanCountry::Sweden, "^(SE)([0-9]{2})([0-9]{3})([0-9]{17})$" },
};

const std::unordered_map<finance::IbanCountry, std::string> generatedTestName {
    { finance::IbanCountry::Austria, "shouldGenerateAustriaIban" },
    { finance::IbanCountry::Belgium, "shouldGenerateBelgiumIban" },
    { finance::IbanCountry::Bulgaria, "shouldGenerateBulgariaIban" },
    { finance::IbanCountry::Croatia, "shouldGenerateCroatiaIban" },
    { finance::IbanCountry::Cyprus, "shouldGenerateCyprusIban" },
    { finance::IbanCountry::Czechia, "shouldGenerateCzechiaIban" },
    { finance::IbanCountry::Denmark, "shouldGenerateDenmarkIban" },
    { finance::IbanCountry::Estonia, "shouldGenerateEstoniaIban" },
    { finance::IbanCountry::Finland, "shouldGenerateFinlandIban" },
    { finance::IbanCountry::France, "shouldGenerateFranceIban" },
    { finance::IbanCountry::Germany, "shouldGenerateGermanyIban" },
    { finance::IbanCountry::Greece, "shouldGenerateGreeceIban" },
    { finance::IbanCountry::Hungary, "shouldGenerateHungaryIban" },
    { finance::IbanCountry::Ireland, "shouldGenerateIrelandIban" },
    { finance::IbanCountry::Italy, "shouldGenerateItalyIban" },
    { finance::IbanCountry::Latvia, "shouldGenerateLatviaIban" },
    { finance::IbanCountry::Lithuania, "shouldGenerateLithuaniaIban" },
    { finance::IbanCountry::Luxembourg, "shouldGenerateLuxembourgIban" },
    { finance::IbanCountry::Malta, "shouldGenerateMaltaIban" },
    { finance::IbanCountry::Netherlands, "shouldGenerateNetherlandsIban" },
    { finance::IbanCountry::Poland, "shouldGeneratePolandIban" },
    { finance::IbanCountry::Portugal, "shouldGeneratePortugalIban" },
    { finance::IbanCountry::Romania, "shouldGenerateRomaniaIban" },
    { finance::IbanCountry::Slovakia, "shouldGenerateSlovakiaIban" },
    { finance::IbanCountry::Slovenia, "shouldGenerateSloveniaIban" },
    { finance::IbanCountry::Spain, "shouldGenerateSpainIban" },
    { finance::IbanCountry::Sweden, "shouldGenerateSwedenIban" },
};

const std::unordered_map<finance::BicCountry, std::string> generatedBicTestName {
    { finance::BicCountry::Poland, "shouldGeneratePolandBic" },
    { finance::BicCountry::United_States, "shouldGenerateUnitedStatesBic" },
    { finance::BicCountry::United_Kingdom, "shouldGenerateUnitedKingdomBic" },
    { finance::BicCountry::Germany, "shouldGenerateGermanyBic" },
    { finance::BicCountry::Romania, "shouldGenerateRomaniaBic" },
    { finance::BicCountry::France, "shouldGenerateFranceBic" },
    { finance::BicCountry::Italy, "shouldGenerateItalyBic" },
    { finance::BicCountry::Spain, "shouldGenerateSpainBic" },
    { finance::BicCountry::Netherlands, "shouldGenerateNetherlandsBic" },
    { finance::BicCountry::India, "shouldGenerateIndiaBic" },
};
}

class FinanceTest : public TestWithParam<finance::IbanCountry> {
public:
    static bool checkIfAllCharactersAreNumeric(const std::string& data)
    {
        return faker::testing::all_of(data, [](char dataCharacter) {
            return faker::testing::any_of(
                string::data::numericCharacters, [dataCharacter](char numericCharacter) {
                    return numericCharacter == dataCharacter;
                });
        });
    }

    static bool checkIfAllCharactersAreCreditCardCharacters(const std::string& data)
    {
        return faker::testing::all_of(data, [](char dataCharacter) {
            return faker::testing::any_of(
                creditCardCharacters, [dataCharacter](char creditCardCharacter) {
                    return creditCardCharacter == dataCharacter;
                });
        });
    }
};

TEST_F(FinanceTest, shouldGenerateCurrency)
{
    const auto generatedCurrency = finance::currency();

    FAKER_EXPECT_CONTAINER_CONTAINS(finance::data::currencies, generatedCurrency);
}

TEST_F(FinanceTest, shouldGenerateCurrencyName)
{
    const auto generatedCurrencyName = finance::currency_name();

    ASSERT_TRUE(faker::testing::any_of(
        finance::data::currencies, [generatedCurrencyName](const finance::Currency& currency) {
            return currency.name == generatedCurrencyName;
        }));
}

TEST_F(FinanceTest, shouldGenerateCurrencyCode)
{
    const auto generatedCurrencyCode = finance::currency_code();

    ASSERT_TRUE(faker::testing::any_of(
        finance::data::currencies, [generatedCurrencyCode](const finance::Currency& currency) {
            return currency.code == generatedCurrencyCode;
        }));
}

TEST_F(FinanceTest, shouldGenerateCurrencySymbol)
{
    const auto generatedCurrencySymbol = finance::currency_symbol();

    ASSERT_TRUE(faker::testing::any_of(
        finance::data::currencies, [generatedCurrencySymbol](const finance::Currency& currency) {
            return currency.symbol == generatedCurrencySymbol;
        }));
}

TEST_F(FinanceTest, shouldGenerateAccountType)
{
    const auto generatedAccountType = finance::account_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(finance::data::accountTypes, generatedAccountType);
}

TEST_F(FinanceTest, shouldGenerateAmount)
{
    const auto generatedAmount = finance::amount();

    auto offset = generatedAmount.size();
    const auto amountAsFloat = std::stof(generatedAmount.data(), &offset);

    const auto generatedAmountParts = utils::split(generatedAmount, ".");

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
MATCHER_P(MatchesRegexCpp, value, "") { return std::regex_match(arg, std::regex(value)); }

TEST_P(FinanceTest, CheckIbanGenerator)
{
    auto ibanCountry = GetParam();

    ASSERT_THAT(finance::iban(ibanCountry), MatchesRegexCpp(expectedRegex.at(ibanCountry)));
}

std::unordered_set<finance::IbanCountry> getIbanCountryKeys()
{
    std::unordered_set<finance::IbanCountry> ibanCountries;
    for (const auto& [ibanCountry, _] : expectedRegex) {
        ibanCountries.insert(ibanCountry);
    }
    return ibanCountries;
}

std::unordered_set<finance::IbanCountry> ibanCountryKeys = getIbanCountryKeys();

INSTANTIATE_TEST_SUITE_P(TestIbanGenerator, FinanceTest,
    ValuesIn(ibanCountryKeys.begin(), ibanCountryKeys.end()),
    [](const TestParamInfo<finance::IbanCountry>& info) {
        return generatedTestName.at(info.param);
    });

TEST_F(FinanceTest, shouldGenerateAmountWithSymbol)
{
    const auto min = 150;
    const auto max = 450;
    const auto precision = Precision::FourDp;
    const std::string currencySymbol = "$";

    const auto generatedAmount = finance::amount(150, 450, precision, currencySymbol);

    const auto amountAsFloat = std::stof(generatedAmount.substr(currencySymbol.size()));

    const auto generatedAmountParts = utils::split(generatedAmount, ".");

    FAKER_EXPECT_STRING_STARTS_WITH(generatedAmount, currencySymbol);
    ASSERT_EQ(generatedAmountParts.size(), 2);
    ASSERT_EQ(generatedAmountParts[1].size(), 4);
    ASSERT_GE(amountAsFloat, min);
    ASSERT_LE(amountAsFloat, max);
}

TEST_F(FinanceTest, shouldGenerateIban)
{
    const auto iban = finance::iban();

    ASSERT_TRUE(faker::testing::starts_with(iban, "AT") || faker::testing::starts_with(iban, "BE")
        || faker::testing::starts_with(iban, "BG") || faker::testing::starts_with(iban, "HR")
        || faker::testing::starts_with(iban, "CY") || faker::testing::starts_with(iban, "CZ")
        || faker::testing::starts_with(iban, "DK") || faker::testing::starts_with(iban, "EE")
        || faker::testing::starts_with(iban, "FI") || faker::testing::starts_with(iban, "FR")
        || faker::testing::starts_with(iban, "DE") || faker::testing::starts_with(iban, "GR")
        || faker::testing::starts_with(iban, "HU") || faker::testing::starts_with(iban, "IE")
        || faker::testing::starts_with(iban, "IT") || faker::testing::starts_with(iban, "LV")
        || faker::testing::starts_with(iban, "LT") || faker::testing::starts_with(iban, "LU")
        || faker::testing::starts_with(iban, "MT") || faker::testing::starts_with(iban, "NL")
        || faker::testing::starts_with(iban, "PL") || faker::testing::starts_with(iban, "PT")
        || faker::testing::starts_with(iban, "RO") || faker::testing::starts_with(iban, "SK")
        || faker::testing::starts_with(iban, "SI") || faker::testing::starts_with(iban, "ES")
        || faker::testing::starts_with(iban, "SE"));
}

TEST_F(FinanceTest, shouldGenerateAccountNumber)
{
    const auto accountNumber = finance::account_number();

    ASSERT_EQ(accountNumber.size(), 8);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(accountNumber));
}

TEST_F(FinanceTest, shouldGenerateAccountNumberWithSpecifiedLength)
{
    const auto accountNumberLength = 26;

    const auto accountNumber = finance::account_number(accountNumberLength);

    ASSERT_EQ(accountNumber.size(), accountNumberLength);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(accountNumber));
}

TEST_F(FinanceTest, shouldGeneratePinNumber)
{
    const auto pin = finance::pin();

    ASSERT_EQ(pin.size(), 4);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(pin));
}

TEST_F(FinanceTest, shouldGeneratePinNumberWithSpecifiedLength)
{
    const auto pinLength = 8;

    const auto pin = finance::pin(pinLength);

    ASSERT_EQ(pin.size(), pinLength);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(pin));
}

TEST_F(FinanceTest, shouldGenerateRoutingNumber)
{
    const auto routingNumber = finance::routing_number();

    ASSERT_EQ(routingNumber.size(), 9);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(routingNumber));
}

TEST_F(FinanceTest, shouldGenerateCreditCardNumber)
{
    const auto creditCardNumber = finance::credit_card_number();

    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(LuhnCheck::luhnCheck(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateAmericanExpressCreditCardNumber)
{
    const auto creditCardNumber
        = finance::credit_card_number(finance::CreditCardType::AmericanExpress);

    ASSERT_TRUE(faker::testing::starts_with(creditCardNumber, "34")
        || faker::testing::starts_with(creditCardNumber, "37"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(LuhnCheck::luhnCheck(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateDiscoverCreditCardNumber)
{
    const auto creditCardNumber = finance::credit_card_number(finance::CreditCardType::Discover);

    ASSERT_TRUE(faker::testing::starts_with(creditCardNumber, "6011")
        || faker::testing::starts_with(creditCardNumber, "65")
        || faker::testing::starts_with(creditCardNumber, "644")
        || faker::testing::starts_with(creditCardNumber, "645")
        || faker::testing::starts_with(creditCardNumber, "646")
        || faker::testing::starts_with(creditCardNumber, "647")
        || faker::testing::starts_with(creditCardNumber, "648")
        || faker::testing::starts_with(creditCardNumber, "649")
        || faker::testing::starts_with(creditCardNumber, "6011-62"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(LuhnCheck::luhnCheck(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateMasterCardCreditCardNumber)
{
    const auto creditCardNumber = finance::credit_card_number(finance::CreditCardType::MasterCard);

    ASSERT_TRUE(faker::testing::starts_with(creditCardNumber, "51")
        || faker::testing::starts_with(creditCardNumber, "52")
        || faker::testing::starts_with(creditCardNumber, "53")
        || faker::testing::starts_with(creditCardNumber, "54")
        || faker::testing::starts_with(creditCardNumber, "55")
        || faker::testing::starts_with(creditCardNumber, "6771-89"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(LuhnCheck::luhnCheck(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateVisaCreditCardNumber)
{
    const auto creditCardNumber = finance::credit_card_number(finance::CreditCardType::Visa);

    FAKER_EXPECT_STRING_STARTS_WITH(creditCardNumber, "4");
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(LuhnCheck::luhnCheck(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateCreditCardCvv)
{
    const auto creditCardCvv = finance::credit_card_cvv();

    ASSERT_EQ(creditCardCvv.size(), 3);
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(creditCardCvv));
}

TEST_F(FinanceTest, shouldGenerateBitcoinAddress)
{
    const auto bitcoinAddress = finance::bitcoin_address();

    ASSERT_GE(bitcoinAddress.size(), 27);
    ASSERT_LE(bitcoinAddress.size(), 34);

    const std::string supportedBitcoinAddressCharacters
        = "ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz123456789";

    ASSERT_TRUE(faker::testing::starts_with(bitcoinAddress, "1")
        || faker::testing::starts_with(bitcoinAddress, "3"));
    ASSERT_TRUE(faker::testing::all_of(
        bitcoinAddress, [&supportedBitcoinAddressCharacters](char dataCharacter) {
            return faker::testing::any_of(supportedBitcoinAddressCharacters,
                [dataCharacter](char supportedBitcoinAddressCharacter) {
                    return supportedBitcoinAddressCharacter == dataCharacter;
                });
        }));
}

TEST_F(FinanceTest, shouldGenerateLitecoinAddress)
{
    const auto litecoinAddress = finance::litecoin_address();

    ASSERT_GE(litecoinAddress.size(), 27);
    ASSERT_LE(litecoinAddress.size(), 34);

    const std::string supportedLitecoinAddressCharacters
        = "ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz123456789";

    ASSERT_TRUE(faker::testing::starts_with(litecoinAddress, "L")
        || faker::testing::starts_with(litecoinAddress, "M")
        || faker::testing::starts_with(litecoinAddress, "3"));
    ASSERT_TRUE(faker::testing::all_of(
        litecoinAddress, [&supportedLitecoinAddressCharacters](char dataCharacter) {
            return faker::testing::any_of(supportedLitecoinAddressCharacters,
                [dataCharacter](char supportedLitecoinAddressCharacter) {
                    return supportedLitecoinAddressCharacter == dataCharacter;
                });
        }));
}

TEST_F(FinanceTest, shouldGenerateEthereumAddress)
{
    const auto ethereumAddress = finance::ethereum_address();

    const auto prefix = ethereumAddress.substr(0, 2);
    const auto hexNumber = ethereumAddress.substr(2);

    ASSERT_EQ(ethereumAddress.size(), 42);
    ASSERT_EQ(prefix, "0x");
    ASSERT_TRUE(faker::testing::any_of(hexNumber, [hexNumber](char hexNumberCharacter) {
        return string::data::hexLowerCharacters.find(hexNumberCharacter) != std::string::npos;
    }));
}

TEST_F(FinanceTest, shouldGenerateExpirationDate)
{
    const auto expirationDate = finance::credit_card_expiration_date();
    int tenthPlaceYear = std::stoi(expirationDate.substr(3, 2));
    std::cout << expirationDate << " " << tenthPlaceYear << "\n";
    ASSERT_TRUE(tenthPlaceYear >= 24);
}

class FinanceBicTest : public TestWithParam<finance::BicCountry> { };

TEST_P(FinanceBicTest, CheckBicGenerator)
{
    const auto country = GetParam();

    const auto bic = finance::bic(country);

    FAKER_EXPECT_CONTAINER_CONTAINS(finance::data::bankIdentifiersCodesMapping.at(country), bic);
}

INSTANTIATE_TEST_SUITE_P(TestBicGenerator, FinanceBicTest,
    Values(finance::BicCountry::Poland, finance::BicCountry::United_States,
        finance::BicCountry::United_Kingdom, finance::BicCountry::Germany,
        finance::BicCountry::Romania, finance::BicCountry::France, finance::BicCountry::Italy,
        finance::BicCountry::Spain, finance::BicCountry::Netherlands, finance::BicCountry::India),
    [](const TestParamInfo<finance::BicCountry>& info) {
        return generatedBicTestName.at(info.param);
    });
