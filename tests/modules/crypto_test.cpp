#include <regex>
#include <string>

#include "gtest/gtest.h"

#include "faker-cxx/crypto.h"

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

    static bool isSHA1Hash(const std::string& input)
    {
        if (input.length() != 40)
        {
            return false;
        }
        return std::all_of(input.begin(), input.end(),
                           [](char c) { return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'); });
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

TEST_F(CryptoTest, ShouldGenerateSHA256HashWithData)
{
    const auto generatedRandomHash = sha256("SHA256 TEST");

    ASSERT_EQ(generatedRandomHash.length(), 64);
}

TEST_F(CryptoTest, ChecksSHA256HashWithData)
{
    const auto generatedRandomHash = sha256("SHA256 TEST");

    ASSERT_TRUE(isSHA256Hash(generatedRandomHash));
}

TEST_F(CryptoTest, ShouldGenerateSHA256HashWithLongData)
{
    const auto generatedRandomHash = sha256("b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde978");

    ASSERT_EQ(generatedRandomHash.length(), 64);
}

TEST_F(CryptoTest, ChecksSHA256HashWithLongData)
{
    const auto generatedRandomHash = sha256("b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde978");

    ASSERT_TRUE(isSHA256Hash(generatedRandomHash));
}

TEST_F(CryptoTest, ShouldGenerateSHA256HashWithDataCodecov)
{
    const auto generatedRandomHash = sha256("b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde");

    ASSERT_EQ(generatedRandomHash.length(), 64);
}

TEST_F(CryptoTest, ChecksSHA256HashWithDataCodecov)
{
    const auto generatedRandomHash = sha256("b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde");

    ASSERT_TRUE(isSHA256Hash(generatedRandomHash));
}

TEST_F(CryptoTest, ChecksSHA1Hash)
{
    const auto generatedRandomHash = sha1();
    ASSERT_TRUE(isSHA1Hash(generatedRandomHash));
}

TEST_F(CryptoTest, ChecksSHA1HashWithData)
{
    const auto generatedRandomHash = sha1("SHA1 TEST");
    ASSERT_TRUE(isSHA1Hash(generatedRandomHash));
}

TEST_F(CryptoTest, ChecksSHA1HashWithLongData)
{
    const auto generatedRandomHash = sha1("b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde978");
    ASSERT_TRUE(isSHA1Hash(generatedRandomHash));
}

TEST_F(CryptoTest, ChecksSHA1HashWithDataCodecov)
{
    const auto generatedRandomHash = sha1("b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde");
    ASSERT_TRUE(isSHA1Hash(generatedRandomHash));
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

TEST_F(CryptoTest, ShouldGenerateMD5HashWithData)
{
    const auto generatedRandomHash = md5("MD5 TEST");

    ASSERT_EQ(generatedRandomHash.length(), 32);
}

TEST_F(CryptoTest, ChecksMD5RegexWithData)
{
    const auto generatedRandomHash = md5("MD5 TEST");

    ASSERT_TRUE(isMD5Hash(generatedRandomHash));
}
