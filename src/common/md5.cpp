#include "md5.h"
#include "string_helper.h"
#include <array>
#include <cstdint>

namespace faker::utils {
namespace {
    uint32_t uint32_from_4_bytes(std::array<uint8_t, 4> bytes)
    {
        uint32_t value = 0;

        value = (value << 8) + bytes[3];
        value = (value << 8) + bytes[2];
        value = (value << 8) + bytes[1];
        value = (value << 8) + bytes[0];

        return value;
    }

    std::array<uint8_t, 4> uint32_to_4_bytes(uint32_t value)
    {
        std::array<uint8_t, 4> bytes {};

        bytes[0] = static_cast<uint8_t>(value);
        bytes[1] = static_cast<uint8_t>(value >> 8);
        bytes[2] = static_cast<uint8_t>(value >> 16);
        bytes[3] = static_cast<uint8_t>(value >> 24);

        return bytes;
    }

    uint32_t rotate_left(const uint32_t x, const int32_t n) { return (x << n) | (x >> (32 - n)); }

    constexpr static uint32_t k[64] = { 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf,
        0x4787c62a, 0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 0xf61e2562, 0xc040b340, 0x265e5a51,
        0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8, 0x21e1cde6, 0xc33707d6,
        0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a, 0xfffa3942,
        0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8,
        0xc4ac5665, 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92,
        0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82,
        0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };

    constexpr static uint32_t r[64] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11,
        16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };

    std::array<uint8_t, 16> compute(std::string_view message)
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

        std::string msg_copy { message };
        msg_copy.resize(new_len + 8);

        // msg_copy[message.size()] = 0x80; // append the "1" bit; most significant bit is "first"
        msg_copy[message.size()] = static_cast<char>(0x80);

        // std::array<uint8_t, 4> bytes = md5_hash::uint32_to_4_bytes(message.size() * 8);
        std::array<uint8_t, 4> bytes = uint32_to_4_bytes(static_cast<uint32_t>(message.size() * 8));
        for (size_t i = new_len; i < new_len + 4; i++)
            // msg_copy[i] = bytes[i - new_len];
            msg_copy[i] = static_cast<char>(bytes[i - new_len]);

        // bytes = md5_hash::uint32_to_4_bytes(message.size() >> 29);
        bytes = uint32_to_4_bytes(static_cast<uint32_t>(message.size() >> 29));
        for (size_t i = new_len + 4; i < new_len + 8; i++)
            msg_copy[i] = static_cast<char>(bytes[i - new_len - 4]);
        // msg_copy[i] = bytes[i - new_len - 4];

        // process the message in successive 512-bit chunks
        for (size_t i = 0; i < new_len; i += (512 / 8)) {
            uint32_t w[16];

            for (size_t j = 0; j < 16; j++) {
                const std::array<uint8_t, 4> array {
                    static_cast<uint8_t>(msg_copy[i + j * 4]),
                    static_cast<uint8_t>(msg_copy[i + j * 4 + 1]),
                    static_cast<uint8_t>(msg_copy[i + j * 4 + 2]),
                    static_cast<uint8_t>(msg_copy[i + j * 4 + 3]),
                };

                w[j] = uint32_from_4_bytes(array);
            }

            uint32_t a = a0, b = b0, c = c0, d = d0;

            for (size_t j = 0; j < 64; j++) {
                uint32_t f, g;

                // F(B, C, D)= (B and C) or (not B and D)
                // G(B, C, D)= (B and D) or (C and not D)
                // H(B, C, D)= B xor C xor D
                // I(B, C, D)= C xor (B or not D)
                if (j < 16) {
                    f = (b & c) | ((~b) & d);
                    g = static_cast<uint32_t>(j);
                } else if (j < 32) {
                    f = (d & b) | (c & (~d));
                    g = (5 * j + 1) % 16;
                } else if (j < 48) {
                    f = b ^ c ^ d;
                    g = (3 * j + 5) % 16;
                } else {
                    f = c ^ (b | (~d));
                    g = (7 * j) % 16;
                }

                const uint32_t temp = d;
                d = c;
                c = b;
                // b = b + md5_hash::rotate_left((a + f + md5_hash::k[j] + w[g]), md5_hash::r[j]);
                b = b + rotate_left((a + f + k[j] + w[g]), static_cast<int32_t>(r[j]));
                a = temp;
            }

            // add this chunk's hash to result so far:
            a0 += a;
            b0 += b;
            c0 += c;
            d0 += d;
        }

        const std::array<uint8_t, 4> a0_arr = uint32_to_4_bytes(a0);
        const std::array<uint8_t, 4> b0_arr = uint32_to_4_bytes(b0);
        const std::array<uint8_t, 4> c0_arr = uint32_to_4_bytes(c0);
        const std::array<uint8_t, 4> d0_arr = uint32_to_4_bytes(d0);

        // append results bytes
        const std::array<uint8_t, 16> result = {
            a0_arr[0],
            a0_arr[1],
            a0_arr[2],
            a0_arr[3],

            b0_arr[0],
            b0_arr[1],
            b0_arr[2],
            b0_arr[3],

            c0_arr[0],
            c0_arr[1],
            c0_arr[2],
            c0_arr[3],

            d0_arr[0],
            d0_arr[1],
            d0_arr[2],
            d0_arr[3],
        };

        return result;
    }

}

std::string md5(std::string_view message) { return utils::to_hex(compute(message)); }

}