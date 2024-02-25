#ifndef FAKER_NUMBER_H
#define FAKER_NUMBER_H

#include <algorithm>
#include <optional>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

namespace faker::number {
/**
 * @brief Generates a random integer number in the given range, bounds included.
 *
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 *
 * @tparam I the type of the generated number, must be an integral type (int, long, long long,
 * etc.).
 *
 * @throws std::invalid_argument if min is greater than max.
 *
 * @return T a random integer number
 */
int integer(int min, int max);
unsigned integer(unsigned min, unsigned max);
long integer(long min, long max);
unsigned long integer(unsigned long min, unsigned long max);

/**
 * @brief Generates a random integer between 0 and the given maximum value, bounds included.
 *
 * @tparam I the type of the generated number, must be an integral type (int, long, long long,
 * etc.).
 * @param max the maximum value of the range.
 *
 * @throws std::invalid_argument if min is greater than max.
 *
 * @see integer<I>(I, I)
 *
 * @return T a random integer number
 */
inline int integer(int max) { return integer(0, max); }
inline unsigned integer(unsigned max) { return integer(0U, max); }
inline long integer(long max) { return integer(0L, max); }
inline unsigned long integer(unsigned long max) { return integer(0UL, max); }

/**
 * @brief Generates a random decimal number in the given range, bounds included.
 *
 * @tparam F the type of the generated number, must be a floating point type (float, double,
 * long double).
 *
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 *
 * @throws std::invalid_argument if min is greater than max.
 *
 * @return F a random decimal number.
 */
float decimal(float min, float max);
double decimal(double min, double max);

/**
 * @brief Generates a random decimal number between 0 and the given maximum value, bounds
 * included.
 *
 * @tparam F The type of the generated number, must be a floating point type (float, double,
 * long double).
 * @param max The maximum value of the range.
 *
 * @throws std::invalid_argument if max is less than 0.
 *
 * @see decimal<F>(F, F)
 *
 * @return F, a random decimal number.
 */
inline float decimal(float max) { return decimal(0.0f, max); }
inline double decimal(double max) { return decimal(0.0, max); }

/**
 * @brief Returns a lowercase hexadecimal number.
 *
 * @param min Optional parameter for lower bound of generated number.
 * @param max Optional parameter for upper bound of generated number.
 *
 * @return A lowercase hexadecimal number.
 *
 * @code
 * number::hex() // "b"
 * number::hex(0, 255) // "9d"
 * @endcode
 */
std::string hex(std::optional<int> min = std::nullopt, std::optional<int> max = std::nullopt);

}

#endif
