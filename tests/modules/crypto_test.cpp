#include "../test_helpers.h"
#include <faker/crypto.h>
#include <regex>

using namespace faker;

TEST(CryptoTest, ChecksSHA256Hash)
{
    static const std::regex reSha256("^[a-f0-9]{64}$");

    const auto generatedRandomHash = crypto::sha256();

    ASSERT_TRUE(std::regex_match(generatedRandomHash, reSha256));
}

TEST(CryptoTest, ChecksMD5Hash)
{
    static const std::regex reMd5("^[a-f0-9]{32}$");

    const auto generatedRandomHash = crypto::md5();

    ASSERT_TRUE(std::regex_match(generatedRandomHash, reMd5));
}
