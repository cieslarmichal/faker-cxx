#include "faker-cxx/string.h"

#include <cassert>
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

    std::random_device rd;
    std::mt19937 generator(rd());
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
    std::random_device rd;
    std::mt19937 generator(rd());
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

    std::random_device rd;
    std::mt19937 generator(rd());

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

std::string uuidV5(std::string name, std::string namespaceUuid)
{
    std::vector<uint8_t> namespaceBytes;
    for (size_t i = 0; i < namespaceUuid.size(); i += 2)
    {
        if (namespaceUuid[i] == '-')
        { // Skip dashes
            i--;
            continue;
        }
        namespaceBytes.push_back(static_cast<uint8_t>(std::stoul(namespaceUuid.substr(i, 2), nullptr, 16)));
    }
    std::string combined(reinterpret_cast<const char*>(namespaceBytes.data()), namespaceBytes.size());
    combined += name;

    std::string sha1Hex = faker::crypto::sha1(combined);
    std::array<uint8_t, 20> sha1_bytes;

    for (int i = 0; i < 20; ++i)
    {
        std::string byte_str = sha1Hex.substr(i * 2, 2);

        try
        {
            sha1_bytes[i] = std::stoi(byte_str, nullptr, 16);
        }
        catch (const std::out_of_range& e)
        {
            throw std::invalid_argument("Error converting hex string to byte: " + byte_str);
        }
    }

    std::array<uint8_t, 16> uuid;

    std::copy(sha1_bytes.begin(), sha1_bytes.begin() + 10, uuid.begin());

    uuid[6] &= 0x0F;
    uuid[6] |= 0x50;

    uuid[8] &= 0x3F;
    uuid[8] |= 0x80;

    std::copy(sha1_bytes.begin() + 10, sha1_bytes.end(), uuid.begin() + 10);

    std::ostringstream uuidV5;
    uuidV5 << std::hex << std::setfill('0');

    for (size_t i = 0; i < uuid.size(); ++i)
    {
        uuidV5 << std::setw(2) << static_cast<int>(uuid[i]);

        if (i == 3 || i == 5 || i == 7 || i == 9)
        {
            uuidV5 << '-';
        }
    }

    return uuidV5.str();
}

}
