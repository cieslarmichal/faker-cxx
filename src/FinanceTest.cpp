#include "Finance.h"

#include "gtest/gtest.h"

#include "data/AccountTypes.h"
#include "data/AlphanumericCharacters.h"
#include "data/Currencies.h"
#include "StringHelper.h"

using namespace ::testing;
using namespace faker;

class FinanceTest : public Test
{
public:
    bool checkIfAllCharactersAreNumeric(const std::string& data)
    {
        return std::all_of(data.begin(), data.end(),
                           [](char dataCharacter)
                           {
                               return std::any_of(numericCharacters.begin(), numericCharacters.end(),
                                                  [dataCharacter](char numericCharacter)
                                                  { return numericCharacter == dataCharacter; });
                           });
    }

    bool checkIfAllCharactersAreAlphanumeric(const std::string& data)
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

    bool checkIfAllCharactersAreAlpha(const std::string& data)
    {
        return std::all_of(data.begin(), data.end(),
                           [](char dataCharacter)
                           {
                               return std::any_of(upperCharacters.begin(), upperCharacters.end(),
                                                  [dataCharacter](char alphanumericCharacter)
                                                  { return alphanumericCharacter == dataCharacter; });
                           });
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
