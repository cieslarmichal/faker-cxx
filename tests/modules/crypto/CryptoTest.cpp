#include "faker-cxx/Crypto.h"

#include <regex>
#include <string>

#include "gtest/gtest.h"

using namespace ::testing;
using namespace faker::crypto;

class CryptoTest : public Test
{
public:
    static bool isMD5Hash(const std::string& input)
    {
        const std::regex regexExp("^[a-f0-9]{32}$");

        return std::regex_match(input, regexExp);
    }

    static bool isSHA256Hash(const std::string& input)
    {
        const std::regex regexExp("^[a-f0-9]{64}$");

        return std::regex_match(input, regexExp);
    }
};

TEST_F(CryptoTest, ShouldGenerateSHA256Hash)
{
    const auto generatedRandomHash = sha256();

    ASSERT_EQ(generatedRandomHash.length(), 64);
}

TEST_F(CryptoTest, ChecksSHA256Hash)
{
    const auto generatedRandomHash = sha256();

    ASSERT_TRUE(isSHA256Hash(generatedRandomHash));
}

TEST_F(CryptoTest, ShouldGenerateMD5Hash)
{
    const auto generatedRandomHash = md5();

    ASSERT_EQ(generatedRandomHash.length(), 32);
}

TEST_F(CryptoTest, ChecksMD5Regex)
{
    const auto generatedRandomHash = md5();

    ASSERT_TRUE(isMD5Hash(generatedRandomHash));
}
