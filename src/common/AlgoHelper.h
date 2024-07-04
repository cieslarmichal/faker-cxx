#pragma once

#include <algorithm>
#include <functional>
#include <random>
#include <set>
#include <stdexcept>
#include <string>

#include "faker-cxx/Datatype.h"
#include "faker-cxx/Export.h"
#include "faker-cxx/Helper.h"

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
 * std::set<char> chars{'a', 'b', 'c', 'd', 'e'};
 * faker::helper::setElement(chars) // 'd'
 * @endcode
 */
namespace faker::helper
{
template <class T>
static T setElement(const std::set<T>& data)
{
    if (data.empty())
    {
        throw std::invalid_argument{"Data is empty."};
    }

    T item;

    static std::mt19937 pseudoRandomGenerator(static_cast<unsigned long>(std::random_device{}()));

    std::sample(data.begin(), data.end(), &item, 1, pseudoRandomGenerator);

    return item;
}

/**
 * @brief Returns shuffled std::string
 *
 * @param data String to be shuffled
 *
 * @return std::string with shuffled chars
 *
 * @code
 * faker::helper::shuffleString("hello") // "eollh"
 * @endcode
 */
FAKER_CXX_EXPORT std::string shuffleString(std::string data);

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
 * faker::helper::objectKey(testMap) // "2"
 * @endcode
 */
template <typename T>
static T::key_type objectKey(const T& object)
{
    if (object.empty())
    {
        throw std::runtime_error("Object is empty.");
    }

    std::vector<typename T::key_type> keys;

    for (const auto& entry : object)
    {
        keys.push_back(entry.first);
    }

    return arrayElement<typename T::key_type>(keys);
}

/**
 * @brief Returns the result of the callback if the probability check was successful, otherwise empty string.
 *
 *
 * @tparam TResult The type of result of the given callback.
 *
 * @param callback The callback to that will be invoked if the probability check was successful.
 * @param probability The probability (`[0.00, 1.00]`) of the callback being invoked. Defaults to `0.5`.
 *
 * @return The result of the callback if the probability check was successful, otherwise empty string.
 *
 * @code
 * faker::helper::maybe<std::string>([]() { return "Hello World!"; }) // ""
 * faker::helper::maybe<int>([]() { return 42; }, 0.9) // "42"
 * @endcode
 */
template <typename TResult>
static TResult maybe(std::function<TResult()> callback, double probability = 0.5)
{
    if (datatype::boolean(probability))
    {
        return callback();
    }
    return TResult();
}

/**
 * @brief Returns a vector equivalent to the given array.
 *
 * @tparam T The type of the array.
 * @tparam N The size of the array.
 *
 * @param arr The array to convert.
 *
 * @return The same array as a vector.
 *
 * @code
 * faker::helper::toVector(std::array<int, 3>{1, 2, 3}) // {1, 2, 3}
 * @endcode
 */
template <typename T, std::size_t N>
static std::vector<T> toVector(const std::array<T, N>& arr)
{
    std::vector<T> vec;
    vec.reserve(N);
    vec.insert(vec.end(), arr.begin(), arr.end());
    return vec;
}

/**
 * @brief Returns the given string parsed symbol by symbol and replaced the placeholders with digits ("0" - "9").
 * "!" will be replaced by digits >=2 ("2" - "9").
 *
 * @param str The template to parse string.
 * @param symbol The symbol to replace with digits. Defaults to '#'.
 *
 * @return The string replaced symbols with digits.
 *
 * @code
 * faker::helper::replaceSymbolWithNumber() // ""
 * faker::helper::replaceSymbolWithNumber("#####") // "04812"
 * faker::helper::replaceSymbolWithNumber("!####") // "27378"
 * faker::helper::replaceSymbolWithNumber("Your pin is: !####") // "29841"
 * @endcode
 */
FAKER_CXX_EXPORT std::string replaceSymbolWithNumber(const std::string& str, const char& symbol = '#');

/**
 * @brief Returns credit card schema with replaced symbols and patterns in a credit card  including Luhn checksum
 * This method supports both range patterns `[4-9]` as well as the patterns used by `replaceSymbolWithNumber()`.
 * `L` will be replaced with the appropriate Luhn checksum.
 *
 * @param inputString TThe credit card format pattern. Defaults to "6453-####-####-####-###L".
 * @param symbol The symbol to replace with a digit. Defaults to '#'.
 *
 * @return The string replaced symbols with digits.
 *
 * @code
 * faker::helper::replaceCreditCardSymbols() // "6453-4876-8626-8995-3771"
 * faker::helper::replaceCreditCardSymbols("1234-[4-9]-##!!-L") // "1234-9-5298-2"
 * @endcode
 */
FAKER_CXX_EXPORT std::string replaceCreditCardSymbols(const std::string& inputString = "6453-####-####-####-###L",
                                                      char symbol = '#');

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
 * faker::helper::regexpStyleStringParse() // ""
 * faker::helper::regexpStyleStringParse("#{5}") // "#####"
 * faker::helper::regexpStyleStringParse("#{2,9}") // "#######"
 * faker::helper::regexpStyleStringParse("[500-15000]") // "8375"
 * faker::helper::regexpStyleStringParse("#{3}test[1-5]") // "###test3"
 * @endcode
 */
FAKER_CXX_EXPORT std::string regexpStyleStringParse(const std::string& input);
}
