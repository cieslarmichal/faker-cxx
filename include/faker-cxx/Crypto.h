#pragma once

#include <optional>
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
}
