#ifndef FAKER_RANDOM_H
#define FAKER_RANDOM_H

#include "span.h"
#include <algorithm>
#include <array>
#include <random>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

namespace faker::random {
extern std::mt19937_64 random_engine;

bool boolean(double probab);

int integer(int min, int max);
unsigned integer(unsigned min, unsigned max);
long integer(long min, long max);
unsigned long integer(unsigned long min, unsigned long max);
long long integer(long long min, long long max);
unsigned long long integer(unsigned long long min, unsigned long long max);
float decimal(float min, float max);
double decimal(double min, double max);

size_t container_index(size_t size);

size_t weighted_container_index(const std::vector<unsigned>& weights);

template <typename T> inline T element(const utils::span<T>& data)
{
    return data[container_index(data.size())];
}

template <typename T, size_t N> inline T element(const std::array<T, N>& data)
{
    return data[container_index(data.size())];
}

/**
 * @brief Get a random element from an STL container.
 *
 * @tparam T an element type of the container.
 *
 * @param data The container.
 *
 * @return T a random element from the container.
 *
 * @code
 * Helper::element<char>(std::string{"abcd"}) // "b"
 * Helper::element<std::string>(std::vector<std::string>{{"hello"}, {"world"}}) // "hello"
 * @endcode
 */
template <class T> inline T element(T data) { return data[container_index(data.size())]; }

inline char element(const std::string& data) { return data[container_index(data.size())]; }

inline char element(const std::string_view& data) { return data[container_index(data.size())]; }

/**
 * @brief Get a random element from a vector.
 *
 * @tparam T an element type of the vector.
 *
 * @param data vector of elements.
 *
 * @return T a random element from the vector.
 *
 * @code
 * Helper::element<std::string>(std::vector<std::string>{{"hello"}, {"world"}}) // "hello"
 * @endcode
 */
template <class T> inline T element(const std::vector<T>& data)
{
    return data[container_index(data.size())];
}

/**
 * @brief Get a random element from a std::set.
 *
 * @tparam T an element type of the std::set.
 *
 * @param std::set of elements.
 *
 * @return T a random element from the std::set.
 *
 * @code
 * std::unordered_set<char> chars{'a', 'b', 'c', 'd', 'e'};
 * Helper::element_from_set(chars) // 'd'
 * @endcode
 */
inline char element_from_set(const std::unordered_set<char>& data)
{
    if (data.empty()) {
        throw std::invalid_argument { "Data is empty." };
    }
    char item { 0 };
    std::sample(data.begin(), data.end(), &item, 1, random_engine);
    return item;
}

template <class T> struct WeightedElement {
    unsigned weight;
    T value;
};

/**
 * @brief Get a random element by weight from a vector.
 *
 * @tparam T an element type of the weighted element.
 *
 * @param data vector of weighted elements.
 *
 * @return T a weighted element value from the vector.
 *
 * @code
 * Helper::weighted_element<std::string>(std::vector<Helper::WeightedElement<std::string>>{{1,
 * "value1"}, {10, "value2"}}) // "hello2"
 * @endcode
 */
template <class T> inline T weighted_element(const std::vector<WeightedElement<T>>& data)
{
    if (data.empty()) {
        throw std::invalid_argument { "Data is empty." };
    }

    auto weights_sum = std::accumulate(data.begin(), data.end(), 0u,
        [](unsigned sum, const WeightedElement<T>& element) { return sum + element.weight; });

    if (weights_sum == 0u) {
        throw std::invalid_argument { "Sum of weights is zero." };
    }

    const auto targetWeightValue = integer(1U, weights_sum);
    unsigned currentSum = 0;
    size_t currentIdx = 0;

    while (currentIdx < data.size()) {
        currentSum += data[currentIdx].weight;
        if (currentSum >= targetWeightValue)
            break;
        currentIdx++;
    }

    return data.at(currentIdx).value;
}

/**
 * @brief Returns shuffled vector.
 *
 * @tparam T an element type of the vector.
 *
 * @param data The vector.
 *
 * @return Vector with shuffled elements.
 *
 * @code
 * Helper::shuffle<std::string>(std::vector<std::string>{{"hello"}, {"world"}}) // {{"world"},
 * {"hello"}}
 * @endcode
 */
template <class T> inline std::vector<T> shuffle(std::vector<T> data)
{
    std::shuffle(std::begin(data), std::end(data), random_engine);

    return data;
}

/**
 * @brief Returns shuffled std::string
 *
 * @param data String to be shuffled
 *
 * @return std::string with shuffled chars
 *
 * @code
 * Helper::shuffle_string("hello") // "eollh"
 * @endcode
 */
std::string shuffle_string(std::string data);

/**
 * @brief Returns a random key from given object.
 *
 * @tparam T The type of the object to select from.
 *
 * @param object The object to be used.
 *
 * @throws  If the given object is empty
 *
 * @return A random key from given object.
 *
 * @code
 * std::unordered_map<int, std::string> testMap = {
 * {1, "one"},
 * {2, "two"},
 * {3, "three"}
 * };
 * Helper::map_key(testMap) // "2"
 * @endcode
 */
template <typename T> inline typename T::key_type map_key(const T& object)
{
    if (object.empty()) {
        throw std::runtime_error("Object is empty.");
    }

    std::vector<typename T::key_type> keys;
    for (const auto& entry : object) {
        keys.push_back(entry.first);
    }

    return element<typename T::key_type>(keys);
}

/**
 * @brief Returns the given string parsed symbol by symbol and replaced the placeholders with
 * digits ("0" - "9").
 * "!" will be replaced by digits >=2 ("2" - "9").
 *
 * @param str The template to parse string.
 * @param symbol The symbol to replace with digits. Defaults to '#'.
 *
 * @return The string replaced symbols with digits.
 *
 * @code
 * Helper::replace_symbol_with_number() // ""
 * Helper::replace_symbol_with_number("#####") // "04812"
 * Helper::replace_symbol_with_number("!####") // "27378"
 * Helper::replace_symbol_with_number("Your pin is: !####") // "29841"
 * @endcode
 */
std::string replace_symbol_with_number(const std::string& str, const char& symbol = '#');
std::string replace_symbol_with_number(const std::string_view& str, const char& symbol = '#');

/**
 * @brief Returns credit card schema with replaced symbols and patterns in a credit card
 * including Luhn checksum This method supports both range patterns `[4-9]` as well as the
 * patterns used by `replace_symbol_with_number()`. `L` will be replaced with the appropriate Luhn
 * checksum.
 *
 * @param inputString TThe credit card format pattern. Defaults to "6453-####-####-####-###L".
 * @param symbol The symbol to replace with a digit. Defaults to '#'.
 *
 * @return The string replaced symbols with digits.
 *
 * @code
 * Helper::replace_credit_card_symbols() // "6453-4876-8626-8995-3771"
 * Helper::replace_credit_card_symbols("1234-[4-9]-##!!-L") // "1234-9-5298-2"
 * @endcode
 */
std::string replace_credit_card_symbols(
    std::string_view inputString = "6453-####-####-####-###L", char symbol = '#');

/**
 * @brief Returns the replaced regex-like expression in the string with matching values.
 *
 * Supported patterns:
 * - `.{times}` => Repeat the character exactly `times` times.
 * - `.{min,max}` => Repeat the character `min` to `max` times.
 * - `[min-max]` => Generate a number between min and max (inclusive).
 *
 * @param input The template string to to parse.
 *
 * @return The replaced regex-like expression in the string with matching values.
 *
 * @code
 * Helper::regexp_style_string_parse() // ""
 * Helper::regexp_style_string_parse("#{5}") // "#####"
 * Helper::regexp_style_string_parse("#{2,9}") // "#######"
 * Helper::regexp_style_string_parse("[500-15000]") // "8375"
 * Helper::regexp_style_string_parse("#{3}test[1-5]") // "###test3"
 * @endcode
 */
std::string regexp_style_string_parse(const std::string& input);

inline std::string regexp_style_string_parse(const std::string_view& input)
{
    return regexp_style_string_parse(std::string(input));
}
}

#endif