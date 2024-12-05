#ifndef ULID_UINT128_HH
#define ULID_UINT128_HH

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <random>
#include <vector>

#if _MSC_VER > 0
typedef uint32_t rand_t;
#else
typedef uint8_t rand_t;
#endif

namespace faker
{

/**
 * ULID is a 16 byte Universally Unique Lexicographically Sortable Identifier
 * */
typedef __uint128_t ULID;

/**
 * EncodeTime will encode the first 6 bytes of a uint8_t array to the passed
 * timestamp
 * */
inline void EncodeTime(time_t timestamp, ULID& ulid)
{
    ULID t = static_cast<uint8_t>(timestamp >> 40);

    t <<= 8;
    t |= static_cast<uint8_t>(timestamp >> 32);

    t <<= 8;
    t |= static_cast<uint8_t>(timestamp >> 24);

    t <<= 8;
    t |= static_cast<uint8_t>(timestamp >> 16);

    t <<= 8;
    t |= static_cast<uint8_t>(timestamp >> 8);

    t <<= 8;
    t |= static_cast<uint8_t>(timestamp);

    t <<= 80;

    ULID mask = 1;
    mask <<= 80;
    mask--;

    ulid = t | (ulid & mask);
}

/**
 * EncodeEntropy will encode the last 10 bytes of the passed uint8_t array with
 * the values generated using the passed random number generator.
 * */
inline void EncodeEntropy(const std::function<uint8_t()>& rng, ULID& ulid)
{
    ulid = (ulid >> 80) << 80;

    ULID e = rng();

    e <<= 8;
    e |= rng();

    e <<= 8;
    e |= rng();

    e <<= 8;
    e |= rng();

    e <<= 8;
    e |= rng();

    e <<= 8;
    e |= rng();

    e <<= 8;
    e |= rng();

    e <<= 8;
    e |= rng();

    e <<= 8;
    e |= rng();

    e <<= 8;
    e |= rng();

    ulid |= e;
}

/**
 * Encode will create an encoded ULID with a timestamp and a generator.
 * */
inline void Encode(time_t timestamp, const std::function<uint8_t()>& rng, ULID& ulid)
{
    EncodeTime(timestamp, ulid);
    EncodeEntropy(rng, ulid);
}

/**
 * Create will create a ULID with a timestamp and a generator.
 * */
inline ULID Create(time_t timestamp, const std::function<uint8_t()>& rng)
{
    ULID ulid = 0;
    Encode(timestamp, rng, ulid);
    return ulid;
}

/**
 * Crockford's Base32
 * */
static const char Encoding[33] = "0123456789ABCDEFGHJKMNPQRSTVWXYZ";

/**
 * MarshalTo will marshal a ULID to the passed character array.
 *
 * Implementation taken directly from oklog/ulid
 * (https://sourcegraph.com/github.com/oklog/ulid@0774f81f6e44af5ce5e91c8d7d76cf710e889ebb/-/blob/ulid.go#L162-190)
 *
 * timestamp:
 * dst[0]: first 3 bits of data[0]
 * dst[1]: last 5 bits of data[0]
 * dst[2]: first 5 bits of data[1]
 * dst[3]: last 3 bits of data[1] + first 2 bits of data[2]
 * dst[4]: bits 3-7 of data[2]
 * dst[5]: last bit of data[2] + first 4 bits of data[3]
 * dst[6]: last 4 bits of data[3] + first bit of data[4]
 * dst[7]: bits 2-6 of data[4]
 * dst[8]: last 2 bits of data[4] + first 3 bits of data[5]
 * dst[9]: last 5 bits of data[5]
 *
 * entropy:
 * follows similarly, except now all components are set to 5 bits.
 * */
inline void MarshalTo(const ULID& ulid, char dst[26])
{
    // 10 byte timestamp
    dst[0] = Encoding[(static_cast<uint8_t>(ulid >> 120) & 224) >> 5];
    dst[1] = Encoding[static_cast<uint8_t>(ulid >> 120) & 31];
    dst[2] = Encoding[(static_cast<uint8_t>(ulid >> 112) & 248) >> 3];
    dst[3] =
        Encoding[((static_cast<uint8_t>(ulid >> 112) & 7) << 2) | ((static_cast<uint8_t>(ulid >> 104) & 192) >> 6)];
    dst[4] = Encoding[(static_cast<uint8_t>(ulid >> 104) & 62) >> 1];
    dst[5] = Encoding[((static_cast<uint8_t>(ulid >> 104) & 1) << 4) | ((static_cast<uint8_t>(ulid >> 96) & 240) >> 4)];
    dst[6] = Encoding[((static_cast<uint8_t>(ulid >> 96) & 15) << 1) | ((static_cast<uint8_t>(ulid >> 88) & 128) >> 7)];
    dst[7] = Encoding[(static_cast<uint8_t>(ulid >> 88) & 124) >> 2];
    dst[8] = Encoding[((static_cast<uint8_t>(ulid >> 88) & 3) << 3) | ((static_cast<uint8_t>(ulid >> 80) & 224) >> 5)];
    dst[9] = Encoding[static_cast<uint8_t>(ulid >> 80) & 31];

    // 16 bytes of entropy
    dst[10] = Encoding[(static_cast<uint8_t>(ulid >> 72) & 248) >> 3];
    dst[11] = Encoding[((static_cast<uint8_t>(ulid >> 72) & 7) << 2) | ((static_cast<uint8_t>(ulid >> 64) & 192) >> 6)];
    dst[12] = Encoding[(static_cast<uint8_t>(ulid >> 64) & 62) >> 1];
    dst[13] = Encoding[((static_cast<uint8_t>(ulid >> 64) & 1) << 4) | ((static_cast<uint8_t>(ulid >> 56) & 240) >> 4)];
    dst[14] =
        Encoding[((static_cast<uint8_t>(ulid >> 56) & 15) << 1) | ((static_cast<uint8_t>(ulid >> 48) & 128) >> 7)];
    dst[15] = Encoding[(static_cast<uint8_t>(ulid >> 48) & 124) >> 2];
    dst[16] = Encoding[((static_cast<uint8_t>(ulid >> 48) & 3) << 3) | ((static_cast<uint8_t>(ulid >> 40) & 224) >> 5)];
    dst[17] = Encoding[static_cast<uint8_t>(ulid >> 40) & 31];
    dst[18] = Encoding[(static_cast<uint8_t>(ulid >> 32) & 248) >> 3];
    dst[19] = Encoding[((static_cast<uint8_t>(ulid >> 32) & 7) << 2) | ((static_cast<uint8_t>(ulid >> 24) & 192) >> 6)];
    dst[20] = Encoding[(static_cast<uint8_t>(ulid >> 24) & 62) >> 1];
    dst[21] = Encoding[((static_cast<uint8_t>(ulid >> 24) & 1) << 4) | ((static_cast<uint8_t>(ulid >> 16) & 240) >> 4)];
    dst[22] = Encoding[((static_cast<uint8_t>(ulid >> 16) & 15) << 1) | ((static_cast<uint8_t>(ulid >> 8) & 128) >> 7)];
    dst[23] = Encoding[(static_cast<uint8_t>(ulid >> 8) & 124) >> 2];
    dst[24] = Encoding[((static_cast<uint8_t>(ulid >> 8) & 3) << 3) | (((static_cast<uint8_t>(ulid)) & 224) >> 5)];
    dst[25] = Encoding[(static_cast<uint8_t>(ulid)) & 31];
}

inline std::string Marshal(const ULID& ulid)
{
    char data[27];

    data[26] = '\0';

    MarshalTo(ulid, data);

    return std::string{data};
}

}

#endif
