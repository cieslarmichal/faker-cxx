#include "faker-cxx/Finance.h"

#include <algorithm>
#include <numeric>

#include "gtest/gtest.h"

#include "data/Characters.h"
#include "data/finance/AccountTypes.h"
#include "data/finance/Currencies.h"
#include "src/data/finance/BankIndentifiersCodes.h"
#include "StringHelper.h"

using namespace ::testing;
using namespace faker;

namespace
{
const std::string creditCardCharacters = "0123456789-";
}

class FinanceTest : public Test
{
public:
    static bool checkIfAllCharactersAreNumeric(const std::string& data)
    {
        return std::all_of(data.begin(), data.end(),
                           [](char dataCharacter)
                           {
                               return std::any_of(numericCharacters.begin(), numericCharacters.end(),
                                                  [dataCharacter](char numericCharacter)
                                                  { return numericCharacter == dataCharacter; });
                           });
    }

    static bool checkIfAllCharactersAreCreditCardCharacters(const std::string& data)
    {
        return std::all_of(data.begin(), data.end(),
                           [](char dataCharacter)
                           {
                               return std::any_of(creditCardCharacters.begin(), creditCardCharacters.end(),
                                                  [dataCharacter](char creditCardCharacter)
                                                  { return creditCardCharacter == dataCharacter; });
                           });
    }

    static bool checkIfAllCharactersAreAlphanumeric(const std::string& data)
    {
        return std::all_of(data.begin(), data.end(),
                           [](char dataCharacter)
                           {
                               return std::any_of(upperAlphanumericCharacters.begin(),
                                                  upperAlphanumericCharacters.end(),
                                                  [dataCharacter](char alphanumericCharacter)
                                                  { return alphanumericCharacter == dataCharacter; });
                           });
    }

    static bool checkIfAllCharactersAreAlpha(const std::string& data)
    {
        return std::all_of(data.begin(), data.end(),
                           [](char dataCharacter)
                           {
                               return std::any_of(upperCharacters.begin(), upperCharacters.end(),
                                                  [dataCharacter](char alphanumericCharacter)
                                                  { return alphanumericCharacter == dataCharacter; });
                           });
    }

    static bool checkCreditCardCheckSum(const std::string& creditCardNumber)
    {
        const auto creditCardNumberPayload = creditCardNumber.substr(0, creditCardNumber.size() - 1);

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

        return std::to_string(checkSum) == std::string{creditCardNumber[creditCardNumber.size() - 1]};
    }
};

TEST_F(FinanceTest, shouldGenerateCurrencyCode)
{
    const auto generatedCurrencyCode = Finance::currencyCode();

    ASSERT_TRUE(std::any_of(currenciesCodes.begin(), currenciesCodes.end(),
                            [generatedCurrencyCode](const std::string& currencyCode)
                            { return currencyCode == generatedCurrencyCode; }));
}

TEST_F(FinanceTest, shouldGenerateAccountType)
{
    const auto generatedAccountType = Finance::accountType();

    ASSERT_TRUE(std::any_of(accountTypes.begin(), accountTypes.end(),
                            [generatedAccountType](const std::string& accountType)
                            { return accountType == generatedAccountType; }));
}

TEST_F(FinanceTest, shouldGenerateAmount)
{
    const auto generatedAmount = Finance::amount();

    const auto amountAsFloat = std::stof(generatedAmount);

    const auto generatedAmountParts = StringHelper::split(generatedAmount, ".");

    ASSERT_EQ(generatedAmountParts.size(), 2);
    ASSERT_EQ(generatedAmountParts[1].size(), 2);
    ASSERT_GE(amountAsFloat, 0);
    ASSERT_LE(amountAsFloat, 1000);
}

TEST_F(FinanceTest, shouldGenerateAmountWithSymbol)
{
    const auto min = 150;
    const auto max = 450;
    const auto decimalPlaces = 4;
    const std::string currencySymbol = "$";

    const auto generatedAmount = Finance::amount(150, 450, decimalPlaces, currencySymbol);

    const auto amountAsFloat = std::stof(generatedAmount.substr(currencySymbol.size()));

    const auto generatedAmountParts = StringHelper::split(generatedAmount, ".");

    ASSERT_TRUE(generatedAmount.starts_with(currencySymbol));
    ASSERT_EQ(generatedAmountParts.size(), 2);
    ASSERT_EQ(generatedAmountParts[1].size(), decimalPlaces);
    ASSERT_GE(amountAsFloat, min);
    ASSERT_LE(amountAsFloat, max);
}

TEST_F(FinanceTest, shouldGenerateIban)
{
    const auto iban = Finance::iban();

    // TODO: implement more detailed checks for iban with default argument
    ASSERT_TRUE(iban.starts_with("PL") || iban.starts_with("IT") || iban.starts_with("FR") || iban.starts_with("DE"));
}

TEST_F(FinanceTest, shouldGeneratePolishIban)
{
    const auto iban = Finance::iban(IbanCountry::Poland);

    const auto countryCode = iban.substr(0, 2);
    const auto checksum = iban.substr(2, 2);
    const auto bankCode = iban.substr(4, 3);
    const auto branchCode = iban.substr(7, 4);
    const auto checkDigit = iban.substr(11, 1);
    const auto accountNumber = iban.substr(12, 16);

    ASSERT_EQ(iban.size(), 28);
    ASSERT_EQ(countryCode, "PL");
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(checksum));
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(bankCode));
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(branchCode));
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(checkDigit));
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(accountNumber));
}

TEST_F(FinanceTest, shouldGenerateFranceIban)
{
    const auto iban = Finance::iban(IbanCountry::France);

    const auto countryCode = iban.substr(0, 2);
    const auto checksum = iban.substr(2, 2);
    const auto bankCode = iban.substr(4, 5);
    const auto branchCode = iban.substr(9, 5);
    const auto accountNumber = iban.substr(14, 11);
    const auto checkDigit = iban.substr(25, 2);

    ASSERT_EQ(iban.size(), 27);
    ASSERT_EQ(countryCode, "FR");
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(checksum));
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(bankCode));
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(branchCode));
    ASSERT_TRUE(checkIfAllCharactersAreAlphanumeric(accountNumber));
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(checkDigit));
}

TEST_F(FinanceTest, shouldGenerateItalyIban)
{
    const auto iban = Finance::iban(IbanCountry::Italy);

    const auto countryCode = iban.substr(0, 2);
    const auto checksum = iban.substr(2, 2);
    const auto checkDigit = iban.substr(4, 1);
    const auto bankCode = iban.substr(5, 5);
    const auto branchCode = iban.substr(10, 5);
    const auto accountNumber = iban.substr(15, 12);

    ASSERT_EQ(iban.size(), 27);
    ASSERT_EQ(countryCode, "IT");
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(checksum));
    ASSERT_TRUE(checkIfAllCharactersAreAlpha(checkDigit));
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(bankCode));
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(branchCode));
    ASSERT_TRUE(checkIfAllCharactersAreAlphanumeric(accountNumber));
}

TEST_F(FinanceTest, shouldGenerateGermanyIban)
{
    const auto iban = Finance::iban(IbanCountry::Germany);

    const auto countryCode = iban.substr(0, 2);
    const auto checksum = iban.substr(2, 2);
    const auto blz = iban.substr(4, 8);
    const auto accountNumber = iban.substr(12, 10);

    ASSERT_EQ(iban.size(), 22);
    ASSERT_EQ(countryCode, "DE");
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(checksum));
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(blz));
    ASSERT_TRUE(checkIfAllCharactersAreNumeric(accountNumber));
}

TEST_F(FinanceTest, shouldGenerateBic)
{
    const auto bic = Finance::bic();

    const auto polandBankIdentifiersCodes = bankIdentifiersCodesMapping.at(BicCountry::Poland);

    ASSERT_TRUE(std::any_of(polandBankIdentifiersCodes.begin(), polandBankIdentifiersCodes.end(),
                            [bic](const std::string& polandBankIdentifierCode)
                            { return bic == polandBankIdentifierCode; }));
}

TEST_F(FinanceTest, shouldGeneratePolandBic)
{
    const auto bic = Finance::bic(BicCountry::Poland);

    const auto polandBankIdentifiersCodes = bankIdentifiersCodesMapping.at(BicCountry::Poland);

    ASSERT_TRUE(std::any_of(polandBankIdentifiersCodes.begin(), polandBankIdentifiersCodes.end(),
                            [bic](const std::string& polandBankIdentifierCode)
                            { return bic == polandBankIdentifierCode; }));
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
    ASSERT_TRUE(checkCreditCardCheckSum(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateAmericanExpressCreditCardNumber)
{
    const auto creditCardNumber = Finance::creditCardNumber(CreditCardType::AmericanExpress);

    ASSERT_TRUE(creditCardNumber.starts_with("34") || creditCardNumber.starts_with("37"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(checkCreditCardCheckSum(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateDiscoverCreditCardNumber)
{
    const auto creditCardNumber = Finance::creditCardNumber(CreditCardType::Discover);

    ASSERT_TRUE(creditCardNumber.starts_with("6011") || creditCardNumber.starts_with("65") ||
                creditCardNumber.starts_with("647") || creditCardNumber.starts_with("6011-62") ||
                creditCardNumber.starts_with("648"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(checkCreditCardCheckSum(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateMasterCardCreditCardNumber)
{
    const auto creditCardNumber = Finance::creditCardNumber(CreditCardType::MasterCard);

    ASSERT_TRUE(creditCardNumber.starts_with("58") || creditCardNumber.starts_with("6771-89"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(checkCreditCardCheckSum(creditCardNumber));
}

TEST_F(FinanceTest, shouldGenerateVisaCreditCardNumber)
{
    const auto creditCardNumber = Finance::creditCardNumber(CreditCardType::Visa);

    ASSERT_TRUE(creditCardNumber.starts_with("4"));
    ASSERT_TRUE(checkIfAllCharactersAreCreditCardCharacters(creditCardNumber));
    ASSERT_TRUE(checkCreditCardCheckSum(creditCardNumber));
}
