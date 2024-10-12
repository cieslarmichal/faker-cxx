#include <algorithm>
#include <stdexcept>

#include "gtest/gtest.h"

#include "faker-cxx/number.h"
#include "number_data.h"

using namespace ::testing;
using namespace faker;
using namespace faker::number;

class NumberTest : public Test
{
public:
};

TEST_F(NumberTest, integer_givenInvalidRangeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(integer<int>(10, 2), std::invalid_argument);
}

TEST_F(NumberTest, givenRangeWithSameNumbers_shouldGenerateThisNumber)
{
    const int actualRandomNumber = integer<int>(2, 2);

    ASSERT_EQ(actualRandomNumber, 2);
}

TEST_F(NumberTest, givenValidRange_shouldGenerateNumberWithinGivenRange)
{
    const int actualRandomNumber = integer<int>(2, 10);

    ASSERT_TRUE(actualRandomNumber >= 2);
    ASSERT_TRUE(actualRandomNumber <= 10);
}

TEST_F(NumberTest, givenSingleArgument_shouldCorrectlyResolveToTwoArgsOverload)
{
    const int randomNumber = integer<int>(10);

    ASSERT_TRUE(randomNumber >= 0);
    ASSERT_TRUE(randomNumber <= 10);
}

TEST_F(NumberTest, decimal_givenInvalidRangeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(decimal<float>(10.f, 2.f), std::invalid_argument);
}

TEST_F(NumberTest, givenValidRangeArguments_shouldGenerateDecimalNumberThatIsInGivenRange)
{
    const std::floating_point auto actualRandomNumber = decimal<float>(2.f, 10.f);

    ASSERT_TRUE(actualRandomNumber >= 2.f);
    ASSERT_TRUE(actualRandomNumber <= 10.f);
}

TEST_F(NumberTest, givenRangeWithSameNumberSection_shouldGenerateThisNumberForDecimal)
{
    const std::floating_point auto actualRandomNumber = decimal<float>(2.f, 2.f);

    ASSERT_EQ(actualRandomNumber, 2.f);
}

TEST_F(NumberTest, normalDistribution_givenInvalidStandardDeviation_shouldThrowInvalidArgument)
{
    ASSERT_THROW(normalDistribution<float>(10.f, -0.01f), std::invalid_argument);
}

TEST_F(NumberTest, givenStandardDeviationOfINFINITY_shouldThrowInvalidArgument)
{
    ASSERT_THROW(normalDistribution<float>(0.f, INFINITY), std::invalid_argument);
}

TEST_F(NumberTest, givenMeanOfINFINITY_shouldThrowInvalidArgument)
{
    ASSERT_THROW(normalDistribution<float>(INFINITY, 3.f), std::invalid_argument);
}

TEST_F(NumberTest, givenStandardDeviationOf0_shouldGenerateMean)
{
    const std::floating_point auto normalDistributionNumber = normalDistribution<float>(0.f, 0.f);

    ASSERT_EQ(normalDistributionNumber, 0.f);
}

TEST_F(NumberTest, givenInvalidRangeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(normalDistribution<float>(10.f, 3.f, 11.f, 10.f), std::invalid_argument);
}

TEST_F(NumberTest, givenValidRangeArguments_shouldGenerateDecimalInGivenRange)
{
    const std::floating_point auto normalDistributionNumber = normalDistribution<float>(10.f, 1000.f, 9.9f, 11.1f);

    ASSERT_TRUE(normalDistributionNumber <= 11.1f);
    ASSERT_TRUE(normalDistributionNumber >= 9.9f);
}

TEST_F(NumberTest, givenRangeWithSameNumberSection_shouldGenerateTheExactNumber)
{
    const std::floating_point auto normalDistributionNumber = normalDistribution<float>(10.f, 1000.f, 12.f, 12.f);

    ASSERT_TRUE(normalDistributionNumber == 12.f);
}

TEST_F(NumberTest, givenHighRange_shouldGenerateMin)
{
    const std::floating_point auto normalDistributionNumber = normalDistribution<float>(-100, .0001f, 10000.f, 10001.f);

    ASSERT_TRUE(normalDistributionNumber == 10000.f);
}

TEST_F(NumberTest, givenHighRange_shouldGenerateMax)
{
    const std::floating_point auto normalDistributionNum = normalDistribution<float>(10000, .0001f, -10001.f, -10000.f);

    ASSERT_TRUE(normalDistributionNum == -10000.f);
}

TEST_F(NumberTest, shouldGenerateHexadecimal)
{
    const auto hexadecimalLength = 8;

    const auto generatedHexadecimal = hexadecimal(hexadecimalLength);

    const auto prefix = generatedHexadecimal.substr(0, 2);
    const auto hexNumber = generatedHexadecimal.substr(2);

    ASSERT_EQ(generatedHexadecimal.size(), hexadecimalLength + 2);
    ASSERT_EQ(prefix, "0x");
    ASSERT_TRUE(std::ranges::any_of(hexNumber, [hexNumber](char hexNumberCharacter)
                                    { return hexLowerCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(NumberTest, shouldGenerateHexadecimalWithHashPrefix)
{
    const auto hexadecimalLength = 8;

    const auto generatedHexadecimal = hexadecimal(hexadecimalLength, HexCasing::Upper, HexPrefix::Hash);

    const auto prefix = generatedHexadecimal.substr(0, 1);
    const auto hexNumber = generatedHexadecimal.substr(1);

    ASSERT_EQ(generatedHexadecimal.size(), hexadecimalLength + 1);
    ASSERT_EQ(prefix, "#");
    ASSERT_TRUE(std::ranges::any_of(hexNumber, [](char hexNumberCharacter)
                                    { return hexUpperCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(NumberTest, shouldGenerateHexadecimalWithoutPrefix)
{
    const auto hexadecimalLength = 8;

    const auto generatedHexadecimal = hexadecimal(hexadecimalLength, HexCasing::Upper, HexPrefix::None);

    ASSERT_EQ(generatedHexadecimal.size(), hexadecimalLength);
    ASSERT_TRUE(std::ranges::any_of(generatedHexadecimal, [](char hexNumberCharacter)
                                    { return hexUpperCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(NumberTest, shouldGenerateHexNumber)
{
    auto result = hexadecimal(100, 255);
    ASSERT_EQ(result.size(), 2);
    ASSERT_TRUE(std::isxdigit(result[0]));
    ASSERT_TRUE(std::isxdigit(result[1]));

    result = hexadecimal(10, 15);
    ASSERT_EQ(result.size(), 1);
    ASSERT_TRUE(std::isxdigit(result[0]));

    result = hexadecimal(30, 40);
    ASSERT_EQ(result.size(), 2);
    ASSERT_TRUE(std::isxdigit(result[0]));
    ASSERT_TRUE(std::isxdigit(result[1]));
}

TEST_F(NumberTest, shouldGenerateOctalWithPrefix)
{
    const auto octalLength = 8;

    const auto generatedOctal = octal(octalLength);

    const auto prefix = generatedOctal.substr(0, 2);
    const auto octalNumber = generatedOctal.substr(2);

    ASSERT_EQ(generatedOctal.size(), octalLength + 2);
    ASSERT_EQ(prefix, "0o");
    ASSERT_TRUE(
        std::ranges::any_of(generatedOctal, [](char octalNumberCharacter)
                            { return std::string("01234567").find(octalNumberCharacter) != std::string::npos; }));
}

TEST_F(NumberTest, shouldGenerateBinary)
{
    const auto binaryLength = 8;

    const auto generatedBinary = binary(binaryLength);

    const auto prefix = generatedBinary.substr(0, 2);
    const auto binaryNumber = generatedBinary.substr(2);

    ASSERT_EQ(generatedBinary.size(), binaryLength + 2);
    ASSERT_EQ(prefix, "0b");
    ASSERT_TRUE(std::ranges::any_of(generatedBinary, [](char binaryNumberCharacter)
                                    { return std::string("01").find(binaryNumberCharacter) != std::string::npos; }));
}

TEST_F(NumberTest, shouldThrowInvalidArgumentForNegativeLength)
{
    ASSERT_THROW(binary(-1), std::invalid_argument);
}

TEST_F(NumberTest, givenValidArguments_shouldGenerateBinaryNumberInRange)
{
    const std::string generatedBinary = binary(1234, 1236);
    int n = 1;
    int decimalEquivalent = 0;

    for (int i = static_cast<int>(generatedBinary.size() - 1); i >= 0; i--)
    {
        if (generatedBinary[static_cast<size_t>(i)] == '1')
        {
            decimalEquivalent += n;
        }

        n *= 2;
    }

    ASSERT_EQ(generatedBinary[0], '0');
    ASSERT_EQ(generatedBinary[1], 'b');

    ASSERT_TRUE(decimalEquivalent >= 1234);
    ASSERT_TRUE(decimalEquivalent <= 1236);
}

TEST_F(NumberTest, shouldGenerateBinaryFor0)
{
    const auto generatedBinary = binary(0, 0);

    ASSERT_EQ(generatedBinary, "0b0");
}

TEST_F(NumberTest, shouldGenerateBinaryFor7)
{
    const auto generatedBinary = binary(7, 7);

    ASSERT_EQ(generatedBinary, "0b111");
}

TEST_F(NumberTest, givenNegativeArguments_shouldThrowInvalidArgument)
{
    ASSERT_THROW(binary(INT_MIN, -1), std::invalid_argument);
}

TEST_F(NumberTest, givenMinBiggerThanMax_shouldThrowInvalidArgument)
{
    ASSERT_THROW(binary(10, 1), std::invalid_argument);
}
