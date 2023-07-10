#include "Finance.h"

#include "gtest/gtest.h"

#include "data/AccountTypes.h"
#include "data/Currencies.h"
#include "StringHelper.h"

using namespace ::testing;
using namespace faker;

class FinanceTest : public Test
{
public:
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
