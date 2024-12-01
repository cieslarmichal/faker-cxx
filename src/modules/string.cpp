#include "faker-cxx/string.h"

#include <cassert>
#include <map>
#include <random>
#include <set>
#include <stdexcept>
#include <string>

#include "common/algo_helper.h"
#include "faker-cxx/helper.h"
#include "faker-cxx/number.h"
#include "helpers/ulid/ulid.h"
#include "string_data.h"

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
                break;
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
        return "";

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, nanoIdAllowedCharacters.size() - 1);

    std::string id;
    for (size_t i = 0; i < length; ++i)
    {
        id += nanoIdAllowedCharacters[distribution(generator)];
    }

    return id;
}

std::string nanoId()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, nanoIdAllowedCharacters.size() - 1);

    std::string id;
    for (size_t i = 0; i < 10; ++i)
    {
        id += nanoIdAllowedCharacters[distribution(generator)];
    }

    return id;
}

std::string nanoId(int minLength, int maxLength)
{
    if (maxLength - minLength < 1)
        return "";

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> lengthDistribution(minLength, maxLength);
    int length = lengthDistribution(generator);

    std::uniform_int_distribution<int> charDistribution(0, nanoIdAllowedCharacters.size() - 1);

    std::string id;
    for (size_t i = 0; i < length; ++i)
    {
        id += nanoIdAllowedCharacters[charDistribution(generator)];
    }

    return id;
}

std::string ulid(time_t refDate)
{
    const auto uild = faker::helpers::ulid::Create(refDate, []() { return 4; });
    std::string data = faker::helpers::ulid::Marshal(uild);
    return std::string(data);
}

#pragma region UUID_IMPLEMENTATIONS

std::string uuidV1()
{
    RandomGenerator<std::mt19937> gen = RandomGenerator<std::mt19937>{};
    // Get current timestamp in 100-nanosecond intervals since UUID epoch (15 Oct 1582)
    const uint64_t UUID_EPOCH_OFFSET =
        0x01B21DD213814000ULL; // Number of 100-ns intervals between UUID epoch and Unix epoch
    auto now = std::chrono::system_clock::now();
    auto since_epoch = now.time_since_epoch();

    uint64_t timestamp =
        UUID_EPOCH_OFFSET +
        static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(since_epoch).count() * 10);

    // Generate clock sequence (14 bits)
    std::uniform_int_distribution<uint16_t> clock_seq_dist(0, 0x3FFF);
    uint16_t clock_seq = gen(clock_seq_dist);

    // Generate node identifier (48 bits)
    std::uniform_int_distribution<uint64_t> node_dist(0, 0xFFFFFFFFFFFFULL);
    uint64_t node = gen(node_dist) & 0xFFFFFFFFFFFFULL;

    uint32_t time_low = static_cast<uint32_t>(timestamp & 0xFFFFFFFFULL);
    uint16_t time_mid = static_cast<uint16_t>((timestamp >> 32) & 0xFFFFULL);
    uint16_t time_hi_and_version = static_cast<uint16_t>((timestamp >> 48) & 0x0FFFULL);
    time_hi_and_version |= (1 << 12); // Set the version number to 1

    uint8_t clock_seq_low = clock_seq & 0xFF;
    uint8_t clock_seq_hi_and_reserved = ((clock_seq >> 8) & 0x3F) | 0x80; // Set the variant to '10'

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
    // FAking MD5 hash with random data from the generator is enough for this purpose
    std::array<uint8_t, 16> hash;
    std::uniform_int_distribution<int> dist(0, 255);

    for (auto& byte : hash)
    {
        byte = gen(dist);
    }

    hash[6] = (hash[6] & 0x0F) | 0x30; // Set the version to 3
    hash[8] = (hash[8] & 0x3F) | 0x80; // Set the variant to '10'

    std::ostringstream ss;
    ss << std::hex << std::setfill('0');
    for (size_t i = 0; i < hash.size(); ++i)
    {
        ss << std::setw(2) << static_cast<int>(hash[i]);
        // Add hyphens at the appropriate positions
        if (i == 3 || i == 5 || i == 7 || i == 9)
            ss << '-';
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

std::string uuid(Uuid uuid)
{
    switch (uuid)
    {
    case Uuid::V1:
        return uuidV1();
    case Uuid::V3:
        return uuidV3();
    case Uuid::V4:
        return uuidV4();
    case Uuid::V5:
        return uuidV4();
    case Uuid::V6:
        return uuidV4();
    case Uuid::V7:
        return uuidV4();
    case Uuid::V8:
        return uuidV4();
    default:
        return uuidV4();
    }
}

#pragma endregion

}
