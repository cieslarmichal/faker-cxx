#pragma once

#include <array>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <optional>
#include <sstream>
#include <string>

namespace faker
{
class Crypto
{
public:
    /**
     * @brief Returns a random SHA256 hash or hash of provided data.
     *
     * @returns SHA256 hash string.
     *
     * @code
     * Crypto::sha256("hello world") // "b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9"
     * Crypto::sha256()    // Random hash of random word
     * @endcode
     */
    static std::string sha256(std::optional<std::string> = std::nullopt);

    /**
     * @brief Returns a random MD5 hash or hash of provided data.
     *
     * @returns MD5 hash string.
     *
     * @code
     * Crypto::md5("hello world") // "5eb63bbbe01eeed093cb22bb8f5acdc3"
     * Crypto::md5()    // Random hash of random word
     * @endcode
     */
    static std::string md5(std::optional<std::string> = std::nullopt);
};

// info and algorithm: https://en.wikipedia.org/wiki/MD5
class md5_hash
{
public:
    /**
     * \param message message to processing
     * \return get md5-hash from message
     */
    [[nodiscard]] static std::array<uint8_t, 16> compute(const std::string& message)
    {
        // These vars will contain the hash
        uint32_t a0 = 0x67452301, b0 = 0xefcdab89, c0 = 0x98badcfe, d0 = 0x10325476;
        size_t new_len = message.size() + 1;

        // Pre-processing:
        // append "1" bit to message
        // append "0" bits until message length in bits ≡ 448 (mod 512)
        // append length mod (2^64) to message
        while (new_len % (512 / 8) != 448 / 8)
            new_len++;

        std::string msg_copy = message;
        msg_copy.resize(new_len + 8);

        // msg_copy[message.size()] = 0x80; // append the "1" bit; most significant bit is "first"
        msg_copy[message.size()] = static_cast<char>(0x80);

        // std::array<uint8_t, 4> bytes = md5_hash::uint32_to_4_bytes(message.size() * 8);
        std::array<uint8_t, 4> bytes = md5_hash::uint32_to_4_bytes(static_cast<uint32_t>(message.size() * 8));
        for (size_t i = new_len; i < new_len + 4; i++)
            // msg_copy[i] = bytes[i - new_len];
            msg_copy[i] = static_cast<char>(bytes[i - new_len]);

        // bytes = md5_hash::uint32_to_4_bytes(message.size() >> 29);
        bytes = md5_hash::uint32_to_4_bytes(static_cast<uint32_t>(message.size() >> 29));
        for (size_t i = new_len + 4; i < new_len + 8; i++)
            msg_copy[i] = static_cast<char>(bytes[i - new_len - 4]);
        // msg_copy[i] = bytes[i - new_len - 4];

        // process the message in successive 512-bit chunks
        for (size_t i = 0; i < new_len; i += (512 / 8))
        {
            uint32_t w[16];

            for (size_t j = 0; j < 16; j++)
            {
                const std::array<uint8_t, 4> array{
                    static_cast<uint8_t>(msg_copy[i + j * 4]),
                    static_cast<uint8_t>(msg_copy[i + j * 4 + 1]),
                    static_cast<uint8_t>(msg_copy[i + j * 4 + 2]),
                    static_cast<uint8_t>(msg_copy[i + j * 4 + 3]),
                };

                w[j] = md5_hash::uint32_from_4_bytes(array);
            }

            uint32_t a = a0, b = b0, c = c0, d = d0;

            for (size_t j = 0; j < 64; j++)
            {
                uint32_t f, g;

                // F(B, C, D)= (B and C) or (not B and D)
                // G(B, C, D)= (B and D) or (C and not D)
                // H(B, C, D)= B xor C xor D
                // I(B, C, D)= C xor (B or not D)
                if (j < 16)
                {
                    f = (b & c) | ((~b) & d);
                    g = static_cast<uint32_t>(j);
                }
                else if (j < 32)
                {
                    f = (d & b) | (c & (~d));
                    g = (5 * j + 1) % 16;
                }
                else if (j < 48)
                {
                    f = b ^ c ^ d;
                    g = (3 * j + 5) % 16;
                }
                else
                {
                    f = c ^ (b | (~d));
                    g = (7 * j) % 16;
                }

                const uint32_t temp = d;
                d = c;
                c = b;
                // b = b + md5_hash::rotate_left((a + f + md5_hash::k[j] + w[g]), md5_hash::r[j]);
                b = b + md5_hash::rotate_left((a + f + md5_hash::k[j] + w[g]), static_cast<int32_t>(md5_hash::r[j]));
                a = temp;
            }

            // add this chunk's hash to result so far:
            a0 += a;
            b0 += b;
            c0 += c;
            d0 += d;
        }

        const std::array<uint8_t, 4> a0_arr = md5_hash::uint32_to_4_bytes(a0);
        const std::array<uint8_t, 4> b0_arr = md5_hash::uint32_to_4_bytes(b0);
        const std::array<uint8_t, 4> c0_arr = md5_hash::uint32_to_4_bytes(c0);
        const std::array<uint8_t, 4> d0_arr = md5_hash::uint32_to_4_bytes(d0);

        // append results bytes
        const std::array<uint8_t, 16> result = {
            a0_arr[0], a0_arr[1], a0_arr[2], a0_arr[3],

            b0_arr[0], b0_arr[1], b0_arr[2], b0_arr[3],

            c0_arr[0], c0_arr[1], c0_arr[2], c0_arr[3],

            d0_arr[0], d0_arr[1], d0_arr[2], d0_arr[3],
        };

        return result;
    }

private:
    md5_hash() = default;

    // rol command: https://www.aldeid.com/wiki/X86-assembly/Instructions/rol
    static uint32_t rotate_left(const uint32_t x, const int32_t n)
    {
        return (x << n) | (x >> (32 - n));
    }

    // cast unsigned integer to to a four-element array
    static std::array<uint8_t, 4> uint32_to_4_bytes(uint32_t value)
    {
        std::array<uint8_t, 4> bytes{};

        bytes[0] = static_cast<uint8_t>(value);
        bytes[1] = static_cast<uint8_t>(value >> 8);
        bytes[2] = static_cast<uint8_t>(value >> 16);
        bytes[3] = static_cast<uint8_t>(value >> 24);

        return bytes;
    }

    // cast a four-element array to unsigned integer
    static uint32_t uint32_from_4_bytes(std::array<uint8_t, 4> bytes)
    {
        uint32_t value = 0;

        value = (value << 8) + bytes[3];
        value = (value << 8) + bytes[2];
        value = (value << 8) + bytes[1];
        value = (value << 8) + bytes[0];

        return value;
    }

    // table, computed by this code:
    /*
        for i from 0 to 63
            K[i] : = floor(232 × abs(sin(i + 1)))
    */
    constexpr static uint32_t k[64] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

    // specifies the per-round shift amounts
    constexpr static uint32_t r[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                                       5, 9,  14, 20, 5, 9,  14, 20, 5, 9,  14, 20, 5, 9,  14, 20,
                                       4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                                       6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
};

class SHA256
{

public:
    SHA256();
    void update(const uint8_t* data, size_t length);
    void update(const std::string& data);
    std::array<uint8_t, 32> digest();

    static std::string toString(const std::array<uint8_t, 32>& digest);

private:
    uint8_t m_data[64];
    uint32_t m_blocklen;
    uint64_t m_bitlen;
    uint32_t m_state[8]; // A, B, C, D, E, F, G, H

    static constexpr std::array<uint32_t, 64> K = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

    static uint32_t rotr(uint32_t x, uint32_t n);
    static uint32_t choose(uint32_t e, uint32_t f, uint32_t g);
    static uint32_t majority(uint32_t a, uint32_t b, uint32_t c);
    static uint32_t sig0(uint32_t x);
    static uint32_t sig1(uint32_t x);
    void transform();
    void pad();
    void revert(std::array<uint8_t, 32>& hash);
};
}
