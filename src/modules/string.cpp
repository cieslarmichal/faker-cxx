#include "faker-cxx/string.h"

#include <cassert>
#include <chrono>
#include <iomanip>
#include <map>
#include <random>
#include <set>
#include <stdexcept>
#include <string>

#include "common/algo_helper.h"
#include "faker-cxx/crypto.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "string_data.h"
#include "ulid.h"

namespace faker::string
{
namespace
{
const std::map<StringCasing, std::string> stringCasingToAlphaCharactersMapping{
    {StringCasing::Lower, lowerCharacters},
    {StringCasing::Upper, upperCharacters},
    {StringCasing::Mixed, mixedAlphaCharacters},
};
const std::map<StringCasing, std::string> stringCasingToAlphanumericCharactersMapping{
    {StringCasing::Lower, lowerAlphanumericCharacters},
    {StringCasing::Upper, upperAlphanumericCharacters},
    {StringCasing::Mixed, mixedAlphanumericCharacters},
};

const std::map<StringCasing, std::set<char>> stringCasingToAlphaCharSetMapping{
    {StringCasing::Lower, lowerCharSet},
    {StringCasing::Upper, upperCharSet},
    {StringCasing::Mixed, mixedAlphaCharSet},
};

std::string generateStringWithGuarantee(GuaranteeMap& guarantee, std::set<char>& targetCharacters, unsigned length)
{
    std::string output{};
    output += generateAtLeastString(guarantee);
    assert(output.size() <= length);
    length -= static_cast<unsigned>(output.size());
    for (unsigned i = 0; i < length; ++i)
    {
        char generatedChar;
        while (true)
        {
            generatedChar = helper::setElement(targetCharacters);

            auto it = guarantee.find(generatedChar);

            if (it == guarantee.end())
            {
                break;
            }

            auto remainingUses = it->second.atMostCount - it->second.atLeastCount;
            if (remainingUses > 0)
            {
                --it->second.atMostCount;
                break;
            }
            else
            {
                targetCharacters.erase(it->first);
            }
        }
        output += generatedChar;
    }

    output = helper::shuffleString(output);

    return output;
}
}

bool isValidGuarantee(GuaranteeMap& guarantee, std::set<char>& targetCharacters, unsigned length)
{
    unsigned atLeastCountSum{};
    unsigned atMostCountSum{};

    for (auto& it : guarantee)
    {
        if (!targetCharacters.contains(it.first))
        {
            return false;
        }

        atLeastCountSum += it.second.atLeastCount;

        atMostCountSum += it.second.atMostCount;
    }

    if (atLeastCountSum > length || (guarantee.size() == targetCharacters.size() && atMostCountSum < length))
    {
        return false;
    }

    return true;
}

std::string generateAtLeastString(const GuaranteeMap& guarantee)
{
    std::string result;

    for (auto& it : guarantee)
    {
        result += std::string(it.second.atLeastCount, it.first);
    }

    return result;
}

std::string sample(unsigned length)
{
    std::string sample;

    for (unsigned i = 0; i < length; i++)
    {
        sample += static_cast<char>(number::integer(33, 125));
    }

    return sample;
}

std::string sample(GuaranteeMap&& guarantee, unsigned length)
{
    auto targetCharacters = utf16CharSet;

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    return generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string symbol(unsigned minLength, unsigned maxLength)
{
    if (minLength > maxLength)
    {
        throw std::invalid_argument("min length cannot be greater than max length");
    }

    return fromCharacters(symbolCharacters, number::integer(minLength, maxLength));
}

std::string fromCharacters(const std::string& characters, unsigned length)
{
    std::string result;

    for (unsigned i = 0; i < length; i++)
    {
        result += helper::randomElement(characters);
    }

    return result;
}

std::string fromCharacters(GuaranteeMap&& guarantee, const std::string& characters, unsigned length)
{
    std::set<char> targetCharacters;

    for (auto character : characters)
    {
        targetCharacters.insert(character);
    }

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    return generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string alpha(unsigned length, StringCasing casing, const std::string& excludeCharacters)
{
    const auto& alphaCharacters = stringCasingToAlphaCharactersMapping.at(casing);

    std::string targetCharacters;

    for (const auto& character : alphaCharacters)
    {
        if (excludeCharacters.find(character) == std::string::npos)
        {
            targetCharacters += character;
        }
    }

    std::string alpha;

    for (unsigned i = 0; i < length; i++)
    {
        alpha += helper::randomElement(targetCharacters);
    }

    return alpha;
}

std::string alpha(GuaranteeMap&& guarantee, unsigned length, StringCasing casing)
{
    auto targetCharacters = stringCasingToAlphaCharSetMapping.at(casing);

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    return generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string alphanumeric(unsigned length, StringCasing casing, const std::string& excludeCharacters)
{
    const auto& alphanumericCharacters = stringCasingToAlphanumericCharactersMapping.at(casing);

    std::string targetCharacters;

    for (const auto& alphanumericCharacter : alphanumericCharacters)
    {
        if (excludeCharacters.find(alphanumericCharacter) == std::string::npos)
        {
            targetCharacters += alphanumericCharacter;
        }
    }

    std::string alphanumeric;

    for (unsigned i = 0; i < length; i++)
    {
        alphanumeric += helper::randomElement(targetCharacters);
    }

    return alphanumeric;
}

std::string alphanumeric(GuaranteeMap&& guarantee, unsigned length, StringCasing casing)
{
    auto targetCharacters = digitSet;

    auto charSet = stringCasingToAlphaCharSetMapping.at(casing);

    targetCharacters.merge(charSet);

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    return generateStringWithGuarantee(guarantee, targetCharacters, length);
}

std::string numeric(unsigned length, bool allowLeadingZeros)
{
    std::string alphanumericStr;
    alphanumericStr.reserve(length);

    for (unsigned i = 0; i < length; i++)
    {
        if (i == 0 && allowLeadingZeros)
        {
            alphanumericStr.push_back(helper::randomElement(numericCharacters));
        }
        else
        {
            alphanumericStr.push_back(helper::randomElement(numericCharactersWithoutZero));
        }
    }

    return alphanumericStr;
}

std::string numeric(GuaranteeMap&& guarantee, unsigned length, bool allowLeadingZeros)
{
    if (!allowLeadingZeros)
    {
        auto it = guarantee.find('0');
        if (it != guarantee.end() && it->second.atLeastCount > length - 1)
        {
            throw std::invalid_argument{"Invalid guarantee."};
        }
    }

    auto targetCharacters = digitSet;

    if (!isValidGuarantee(guarantee, targetCharacters, length))
    {
        throw std::invalid_argument{"Invalid guarantee."};
    }

    if (allowLeadingZeros)
    {
        return generateStringWithGuarantee(guarantee, targetCharacters, length);
    }
    else
    {
        auto firstChar = std::to_string(number::integer(1, 9));

        auto it = guarantee.find(firstChar[0]);

        if (it != guarantee.end())
        {
            --it->second.atMostCount;
        }

        return firstChar + generateStringWithGuarantee(guarantee, targetCharacters, length - 1);
    }
}

std::string nanoId(int length)
{
    if (length < 1)
    {
        return "";
    }

    std::mt19937_64& generator = common::GetGenerator();
    std::uniform_int_distribution<int> distribution(0, static_cast<int>(nanoIdAllowedCharacters.size() - 1));

    std::string id;

    for (auto i = 0; i < length; ++i)
    {
        id += nanoIdAllowedCharacters[static_cast<unsigned long>(distribution(generator))];
    }

    return id;
}

std::string nanoId()
{
    std::mt19937_64& generator = common::GetGenerator();
    std::uniform_int_distribution<int> distribution(0, static_cast<int>(nanoIdAllowedCharacters.size() - 1));

    std::string id;

    for (size_t i = 0; i < 10; ++i)
    {
        id += nanoIdAllowedCharacters[static_cast<unsigned long>(distribution(generator))];
    }

    return id;
}

std::string nanoId(int minLength, int maxLength)
{
    if (maxLength - minLength < 1)
    {
        return "";
    }

    std::mt19937_64& generator = common::GetGenerator();
    std::uniform_int_distribution<int> lengthDistribution(minLength, maxLength);

    const auto length = lengthDistribution(generator);

    std::uniform_int_distribution<int> charDistribution(0, static_cast<int>(nanoIdAllowedCharacters.size() - 1));

    std::string id;

    for (auto i = 0; i < length; ++i)
    {
        id += nanoIdAllowedCharacters[static_cast<unsigned long>(charDistribution(generator))];
    }

    return id;
}

std::string ulid(time_t refDate)
{
    return Marshal(Create(refDate, []() { return 4; }));
}

std::string uuidV1()
{
    RandomGenerator<std::mt19937> gen = RandomGenerator<std::mt19937>{};

    const uint64_t UUID_EPOCH_OFFSET = 0x01B21DD213814000ULL;
    auto now = std::chrono::system_clock::now();
    auto since_epoch = now.time_since_epoch();

    const auto timestamp =
        UUID_EPOCH_OFFSET +
        static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(since_epoch).count() * 10);

    std::uniform_int_distribution<uint16_t> clock_seq_dist(0, 0x3FFF);
    const auto clock_seq = static_cast<uint16_t>(gen(clock_seq_dist));

    std::uniform_int_distribution<uint64_t> node_dist(0, 0xFFFFFFFFFFFFULL);
    uint64_t node = static_cast<unsigned long long int>(gen(node_dist)) & 0xFFFFFFFFFFFFULL;

    const auto time_low = static_cast<uint32_t>(timestamp & 0xFFFFFFFFULL);
    const auto time_mid = static_cast<uint16_t>((timestamp >> 32) & 0xFFFFULL);
    auto time_hi_and_version = static_cast<uint16_t>((timestamp >> 48) & 0x0FFFULL);
    time_hi_and_version |= (1 << 12);

    uint8_t clock_seq_low = clock_seq & 0xFF;
    uint8_t clock_seq_hi_and_reserved = ((clock_seq >> 8) & 0x3F) | 0x80;

    std::ostringstream ss;
    ss << std::hex << std::setfill('0');
    ss << std::setw(8) << time_low << '-';
    ss << std::setw(4) << time_mid << '-';
    ss << std::setw(4) << time_hi_and_version << '-';
    ss << std::setw(2) << static_cast<int>(clock_seq_hi_and_reserved);
    ss << std::setw(2) << static_cast<int>(clock_seq_low) << '-';
    ss << std::setw(12) << std::setw(12) << node;

    return ss.str();
}

std::string uuidV3()
{
    RandomGenerator<std::mt19937> gen = RandomGenerator<std::mt19937>{};

    std::array<uint8_t, 16> hash{};
    std::uniform_int_distribution<int> dist(0, 255);

    for (auto& byte : hash)
    {
        byte = static_cast<unsigned char>(gen(dist));
    }

    hash[6] = (hash[6] & 0x0F) | 0x30;
    hash[8] = (hash[8] & 0x3F) | 0x80;

    std::ostringstream ss;

    ss << std::hex << std::setfill('0');

    for (size_t i = 0; i < hash.size(); ++i)
    {
        ss << std::setw(2) << static_cast<int>(hash[i]);

        if (i == 3 || i == 5 || i == 7 || i == 9)
        {
            ss << '-';
        }
    }

    return ss.str();
}

std::string uuidV4()
{
    RandomGenerator<std::mt19937> gen = RandomGenerator<std::mt19937>{};

    static std::uniform_int_distribution<> dist(0, 15);
    static std::uniform_int_distribution<> dist2(8, 11);
    static std::string_view hexCharacters{"0123456789abcdef"};

    std::string result;
    result.reserve(36);

    for (int i = 0; i < 8; i++)
    {
        result.append(1, hexCharacters[static_cast<size_t>(gen(dist))]);
    }
    result.append(1, '-');

    for (int i = 0; i < 4; i++)
    {
        result.append(1, hexCharacters[static_cast<size_t>(gen(dist))]);
    }
    result.append(1, '-');

    result.append(1, '4');
    for (int i = 0; i < 3; i++)
    {
        result.append(1, hexCharacters[static_cast<size_t>(gen(dist))]);
    }
    result.append(1, '-');

    result.append(1, hexCharacters[static_cast<size_t>(gen(dist2))]);

    for (int i = 0; i < 3; i++)
    {
        result.append(1, hexCharacters[static_cast<size_t>(gen(dist))]);
    }
    result.append(1, '-');

    for (int i = 0; i < 12; i++)
    {
        result.append(1, hexCharacters[static_cast<size_t>(gen(dist))]);
    }

    return result;
}

std::string uuidV5(const std::string& name, const std::string& namespaceUuid)
{
    if (namespaceUuid.length() != 36)
    {
        throw std::invalid_argument("Invalid namespace UUID");
    }

    std::array<unsigned char, 16> namespace_bytes{};

    int idx = 0;

    for (size_t i = 0; i < namespaceUuid.length(); i += 2)
    {
        if (namespaceUuid[i] == '-')
        {
            i--;
            continue;
        }

        std::string byte_string = namespaceUuid.substr(i, 2);

        namespace_bytes[static_cast<size_t>(idx++)] = static_cast<unsigned char>(std::stoi(byte_string, nullptr, 16));
    }

    std::string data(reinterpret_cast<const char*>(namespace_bytes.data()), namespace_bytes.size());
    data.append(name);

    std::string hash_str = crypto::sha1(data);

    std::array<unsigned char, 20> hash{};

    for (size_t i = 0; i < 20; ++i)
    {
        hash[i] = static_cast<unsigned char>(std::stoi(hash_str.substr(i * 2, 2), nullptr, 16));
    }

    hash[6] = (hash[6] & 0x0F) | 0x50; // Set version to 5
    hash[8] = (hash[8] & 0x3F) | 0x80; // Set variant to RFC 4122

    // Format the UUID as a string
    std::ostringstream ss;
    ss << std::hex << std::setfill('0');
    for (int i = 0; i < 16; ++i)
    {
        if (i == 4 || i == 6 || i == 8 || i == 10)
            ss << '-';
        ss << std::setw(2) << static_cast<int>(hash[static_cast<unsigned long>(i)]);
    }

    return ss.str();
}

std::string uuidV6()
{
    RandomGenerator<std::mt19937> gen = RandomGenerator<std::mt19937>{};

    const uint64_t UUID_EPOCH_OFFSET = 0x01B21DD213814000ULL;
    auto now = std::chrono::system_clock::now();
    auto since_epoch = now.time_since_epoch();

    const auto timestamp =
        UUID_EPOCH_OFFSET +
        static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(since_epoch).count() * 10);

    std::uniform_int_distribution<uint16_t> clock_seq_dist(0, 0x3FFF);
    const auto clock_seq = static_cast<uint16_t>(gen(clock_seq_dist));

    std::uniform_int_distribution<uint64_t> node_dist(0, 0xFFFFFFFFFFFFULL);
    uint64_t node = static_cast<unsigned long long int>(gen(node_dist)) & 0xFFFFFFFFFFFFULL;

    const auto time_high = static_cast<uint32_t>((timestamp >> 28) & 0xFFFFFFFFULL);
    const auto time_mid = static_cast<uint16_t>((timestamp >> 12) & 0xFFFFULL);
    auto time_low_and_version = static_cast<uint16_t>(timestamp & 0x0FFFULL);
    time_low_and_version |= (6 << 12); // Set version to 6

    uint8_t clock_seq_low = clock_seq & 0xFF;
    uint8_t clock_seq_hi_and_reserved = ((clock_seq >> 8) & 0x3F) | 0x80;

    std::ostringstream ss;
    ss << std::hex << std::setfill('0');
    ss << std::setw(8) << time_high << '-';
    ss << std::setw(4) << time_mid << '-';
    ss << std::setw(4) << time_low_and_version << '-';
    ss << std::setw(2) << static_cast<int>(clock_seq_hi_and_reserved);
    ss << std::setw(2) << static_cast<int>(clock_seq_low) << '-';
    ss << std::setw(12) << node;

    return ss.str();
}

std::string uuidV7()
{
    RandomGenerator<std::mt19937> gen = RandomGenerator<std::mt19937>{};
    auto now = std::chrono::system_clock::now();
    auto since_epoch = now.time_since_epoch();

    const auto timestamp =
        static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch).count());

    const auto time_high = static_cast<uint32_t>((timestamp >> 16) & 0xFFFFFFFFULL);
    const auto time_low = static_cast<uint32_t>(timestamp & 0xFFFFULL);

    std::uniform_int_distribution<uint16_t> rand_a_seq_dis(0, 0xFFF);
    uint16_t rand_a_seq = (gen(rand_a_seq_dis) & 0xFFF);
    rand_a_seq |= 0x7000;

    std::uniform_int_distribution<uint32_t> rand_b_seq_dis(0, 0xFFFFFFFFULL);
    uint64_t rand_b_seq = static_cast<uint32_t>(gen(rand_b_seq_dis));
    rand_b_seq = rand_b_seq << 32;
    rand_b_seq |= static_cast<uint32_t>(gen(rand_b_seq_dis));

    uint16_t rand_b_high = ((rand_b_seq >> 32) & 0x3FFFULL) | 0x8000;
    uint64_t rand_b_low = (rand_b_seq & 0xFFFFFFFFFFFFULL);

    std::ostringstream ss;
    ss << std::hex << std::setfill('0');
    ss << std::setw(8) << time_high << '-';
    ss << std::setw(4) << time_low << '-';
    ss << std::setw(4) << rand_a_seq << '-';
    ss << std::setw(4) << rand_b_high << '-';
    ss << std::setw(12) << rand_b_low;

    return ss.str();
}

}
