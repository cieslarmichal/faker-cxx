#ifndef FAKER_CRYPTO_H
#define FAKER_CRYPTO_H

#include <optional>
#include <string>

namespace faker::crypto {
/**
 * @brief Returns a random SHA256 hash or hash of provided data.
 *
 * @param data Data to hash. If not provided, random data will be used.
 *
 * @returns SHA256 hash string.
 *
 * @code
 * crypto::sha256("hello world") //
 * "b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9" crypto::sha256()    //
 * Random hash of random word
 * @endcode
 */
std::string sha256(std::optional<std::string> data = std::nullopt);

/**
 * @brief Returns a random MD5 hash or hash of provided data.
 *
 * @param data Data to hash. If not provided, random data will be used.
 *
 * @returns MD5 hash string.
 *
 * @code
 * crypto::md5("hello world") // "5eb63bbbe01eeed093cb22bb8f5acdc3"
 * crypto::md5()    // Random hash of random word
 * @endcode
 */
std::string md5(std::optional<std::string> data = std::nullopt);
}

#endif