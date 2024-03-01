#include "../test_helpers.h"
#include <algorithm>
#include <charconv>
#include <common/luhn_check.h>
#include <common/strings.h>
#include <faker/finance.h>
#include <gmock/gmock.h>
#include <modules/finance_data.h>
#include <modules/string_data.h>
#include <ranges>
#include <regex>
#include <unordered_set>

using namespace ::testing;
using namespace faker;

namespace {
const std::string creditCardCharacters = "0123456789-";
const std::unordered_map<finance::iban_country, std::string> expectedRegex {
    { finance::iban_country::austria, "^(AT)([0-9]{2})([0-9]{5})([0-9]{11})$" },
    { finance::iban_country::belgium, "^(BE)([0-9]{2})([0-9]{3})([0-9]{7})([0-9]{2})$" },
    { finance::iban_country::bulgaria,
        "^(BG)([0-9]{2})([A-Z]{4})([0-9]{4})([0-9]{2})([a-zA-Z0-9]{8})$" },
    { finance::iban_country::croatia, "^(HR)([0-9]{2})([0-9]{7})([0-9]{10})$" },
    { finance::iban_country::cyprus, "^(CY)([0-9]{2})([0-9]{3})([0-9]{5})([a-zA-Z0-9]{16})$" },
    { finance::iban_country::czechia, "^(CZ)([0-9]{2})([0-9]{4})([0-9]{6})([0-9]{10})$" },
    { finance::iban_country::denmark, "^(DK)([0-9]{2})([0-9]{4})([0-9]{9})([0-9]{1})$" },
    { finance::iban_country::estonia, "^(EE)([0-9]{2})([0-9]{2})([0-9]{2})([0-9]{11})([0-9]{1})$" },
    { finance::iban_country::finland, "^(FI)([0-9]{2})([0-9]{6})([0-9]{7})([0-9]{1})$" },
    { finance::iban_country::france,
        "^(FR)([0-9]{2})([0-9]{5})([0-9]{5})([a-zA-Z0-9]{11})([0-9]{2})$" },
    { finance::iban_country::germany, "^(DE)([0-9]{2})([0-9]{8})([0-9]{10})$" },
    { finance::iban_country::greece, "^(GR)([0-9]{2})([0-9]{3})([0-9]{4})([a-zA-Z0-9]{16})$" },
    { finance::iban_country::hungary,
        "^(HU)([0-9]{2})([0-9]{3})([0-9]{4})([0-9]{1})([0-9]{15})([0-9]{1})$" },
    { finance::iban_country::ireland, "^(IE)([0-9]{2})([A-Z]{4})([0-9]{6})([0-9]{8})$" },
    { finance::iban_country::italy,
        "^(IT)([0-9]{2})([A-Z]{1})([0-9]{5})([0-9]{5})([a-zA-Z0-9]{12})$" },
    { finance::iban_country::latvia, "^(LV)([0-9]{2})([A-Z]{4})([a-zA-Z0-9]{13})$" },
    { finance::iban_country::lithuania, "^(LT)([0-9]{2})([0-9]{5})([0-9]{11})$" },
    { finance::iban_country::luxembourg, "^(LU)([0-9]{2})([0-9]{3})([a-zA-Z0-9]{13})$" },
    { finance::iban_country::malta, "^(MT)([0-9]{2})([A-Z]{4})([0-9]{5})([a-zA-Z0-9]{18})$" },
    { finance::iban_country::netherlands, "^(NL)([0-9]{2})([A-Z]{4})([0-9]{10})$" },
    { finance::iban_country::poland, "^(PL)([0-9]{2})([0-9]{3})([0-9]{4})([0-9]{1})([0-9]{16})$" },
    { finance::iban_country::portugal,
        "^(PT)([0-9]{2})([0-9]{4})([0-9]{4})([0-9]{11})([0-9]{2})$" },
    { finance::iban_country::romania, "^(RO)([0-9]{2})([A-Z]{4})([a-zA-Z0-9]{16})$" },
    { finance::iban_country::slovakia, "^(SK)([0-9]{2})([0-9]{4})([0-9]{6})([0-9]{10})$" },
    { finance::iban_country::slovenia, "^(SI)([0-9]{2})([0-9]{2})([0-9]{3})([0-9]{8})([0-9]{2})$" },
    { finance::iban_country::spain, "^(ES)([0-9]{2})([0-9]{4})([0-9]{4})([0-9]{2})([0-9]{10})$" },
    { finance::iban_country::sweden, "^(SE)([0-9]{2})([0-9]{3})([0-9]{17})$" },
};

const std::unordered_map<finance::iban_country, std::string> generatedTestName {
    { finance::iban_country::austria, "shouldGenerateAustriaIban" },
    { finance::iban_country::belgium, "shouldGenerateBelgiumIban" },
    { finance::iban_country::bulgaria, "shouldGenerateBulgariaIban" },
    { finance::iban_country::croatia, "shouldGenerateCroatiaIban" },
    { finance::iban_country::cyprus, "shouldGenerateCyprusIban" },
    { finance::iban_country::czechia, "shouldGenerateCzechiaIban" },
    { finance::iban_country::denmark, "shouldGenerateDenmarkIban" },
    { finance::iban_country::estonia, "shouldGenerateEstoniaIban" },
    { finance::iban_country::finland, "shouldGenerateFinlandIban" },
    { finance::iban_country::france, "shouldGenerateFranceIban" },
    { finance::iban_country::germany, "shouldGenerateGermanyIban" },
    { finance::iban_country::greece, "shouldGenerateGreeceIban" },
    { finance::iban_country::hungary, "shouldGenerateHungaryIban" },
    { finance::iban_country::ireland, "shouldGenerateIrelandIban" },
    { finance::iban_country::italy, "shouldGenerateItalyIban" },
    { finance::iban_country::latvia, "shouldGenerateLatviaIban" },
    { finance::iban_country::lithuania, "shouldGenerateLithuaniaIban" },
    { finance::iban_country::luxembourg, "shouldGenerateLuxembourgIban" },
    { finance::iban_country::malta, "shouldGenerateMaltaIban" },
    { finance::iban_country::netherlands, "shouldGenerateNetherlandsIban" },
    { finance::iban_country::poland, "shouldGeneratePolandIban" },
    { finance::iban_country::portugal, "shouldGeneratePortugalIban" },
    { finance::iban_country::romania, "shouldGenerateRomaniaIban" },
    { finance::iban_country::slovakia, "shouldGenerateSlovakiaIban" },
    { finance::iban_country::slovenia, "shouldGenerateSloveniaIban" },
    { finance::iban_country::spain, "shouldGenerateSpainIban" },
    { finance::iban_country::sweden, "shouldGenerateSwedenIban" },
};

const std::unordered_map<finance::bic_country, std::string> generatedBicTestName {
    { finance::bic_country::poland, "shouldGeneratePolandBic" },
    { finance::bic_country::usa, "shouldGenerateUnitedStatesBic" },
    { finance::bic_country::england, "shouldGenerateUnitedKingdomBic" },
    { finance::bic_country::germany, "shouldGenerateGermanyBic" },
    { finance::bic_country::romania, "shouldGenerateRomaniaBic" },
    { finance::bic_country::france, "shouldGenerateFranceBic" },
    { finance::bic_country::italy, "shouldGenerateItalyBic" },
    { finance::bic_country::spain, "shouldGenerateSpainBic" },
    { finance::bic_country::netherlands, "shouldGenerateNetherlandsBic" },
    { finance::bic_country::india, "shouldGenerateIndiaBic" },
};
}

class FinanceTest : public TestWithParam<finance::iban_country> {
public:
    static bool checkIfAllCharactersAreNumeric(const std::string& data)
    {
        return faker::testing::all_of(data, [](char dataCharacter) {
            return faker::testing::any_of(
                string::data::digits, [dataCharacter](char numericCharacter) {
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
        finance::data::currencies, [generatedCurrencyName](const finance::currency_info& currency) {
            return currency.name == generatedCurrencyName;
        }));
}

TEST_F(FinanceTest, shouldGenerateCurrencyCode)
{
    const auto generatedCurrencyCode = finance::currency_code();

    ASSERT_TRUE(faker::testing::any_of(
        finance::data::currencies, [generatedCurrencyCode](const finance::currency_info& currency) {
            return currency.code == generatedCurrencyCode;
        }));
}

TEST_F(FinanceTest, shouldGenerateCurrencySymbol)
{
    const auto generatedCurrencySymbol = finance::currency_symbol();

    ASSERT_TRUE(faker::testing::any_of(finance::data::currencies,
        [generatedCurrencySymbol](const finance::currency_info& currency) {
            return currency.symbol == generatedCurrencySymbol;
        }));
}

TEST_F(FinanceTest, shouldGenerateAccountType)
{
    const auto generatedAccountType = finance::account_type();

    FAKER_EXPECT_CONTAINER_CONTAINS(finance::data::account_types, generatedAccountType);
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

std::unordered_set<finance::iban_country> getIbanCountryKeys()
{
    std::unordered_set<finance::iban_country> ibanCountries;
    for (const auto& [ibanCountry, _] : expectedRegex) {
        ibanCountries.insert(ibanCountry);
    }
    return ibanCountries;
}

std::unordered_set<finance::iban_country> ibanCountryKeys = getIbanCountryKeys();

INSTANTIATE_TEST_SUITE_P(TestIbanGenerator, FinanceTest,
    ValuesIn(ibanCountryKeys.begin(), ibanCountryKeys.end()),
    [](const TestParamInfo<finance::iban_country>& info) {
        return generatedTestName.at(info.param);
    });

TEST_F(FinanceTest, shouldGenerateAmountWithSymbol)
{
    const auto min = 150;
    const auto max = 450;
    const auto precision = precision_t::four_dp;
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
    ASSERT_TRUE(utils::luhn_check(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateAmericanExpressCreditCardNumber)
{
    const auto creditCardNumber
        = finance::credit_card_number(finance::credit_card_type::american_express);

    ASSERT_TRUE(faker::testing::starts_with(creditCardNumber, "34")
        || faker::testing::starts_with(creditCardNumber, "37"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(utils::luhn_check(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateDiscoverCreditCardNumber)
{
    const auto creditCardNumber = finance::credit_card_number(finance::credit_card_type::discover);

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
    ASSERT_TRUE(utils::luhn_check(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateMasterCardCreditCardNumber)
{
    const auto creditCardNumber
        = finance::credit_card_number(finance::credit_card_type::mastercard);

    ASSERT_TRUE(faker::testing::starts_with(creditCardNumber, "51")
        || faker::testing::starts_with(creditCardNumber, "52")
        || faker::testing::starts_with(creditCardNumber, "53")
        || faker::testing::starts_with(creditCardNumber, "54")
        || faker::testing::starts_with(creditCardNumber, "55")
        || faker::testing::starts_with(creditCardNumber, "6771-89"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(utils::luhn_check(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateVisaCreditCardNumber)
{
    const auto creditCardNumber = finance::credit_card_number(finance::credit_card_type::visa);

    FAKER_EXPECT_STRING_STARTS_WITH(creditCardNumber, "4");
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(utils::luhn_check(creditCardNumber));
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
        return string::data::hex_lower_digits.find(hexNumberCharacter) != std::string::npos;
    }));
}

TEST_F(FinanceTest, shouldGenerateExpirationDate)
{
    const auto expirationDate = finance::credit_card_expiration_date();
    int tenthPlaceYear = std::stoi(expirationDate.substr(3, 2));
    std::cout << expirationDate << " " << tenthPlaceYear << "\n";
    ASSERT_TRUE(tenthPlaceYear >= 24);
}

class FinanceBicTest : public TestWithParam<finance::bic_country> { };

TEST_P(FinanceBicTest, CheckBicGenerator)
{
    const auto country = GetParam();

    const auto bic = finance::bic(country);

    FAKER_EXPECT_CONTAINER_CONTAINS(finance::data::bic_countries_codes.at(country), bic);
}

INSTANTIATE_TEST_SUITE_P(TestBicGenerator, FinanceBicTest,
    Values(finance::bic_country::poland, finance::bic_country::usa, finance::bic_country::england,
        finance::bic_country::germany, finance::bic_country::romania, finance::bic_country::france,
        finance::bic_country::italy, finance::bic_country::spain, finance::bic_country::netherlands,
        finance::bic_country::india),
    [](const TestParamInfo<finance::bic_country>& info) {
        return generatedBicTestName.at(info.param);
    });
