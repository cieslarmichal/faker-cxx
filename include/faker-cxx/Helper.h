#pragma once

#include <algorithm>
#include <functional>
#include <initializer_list>
#include <numeric>
#include <random>
#include <set>
#include <span>
#include <string>
#include <vector>

#include "faker-cxx/Export.h"
#include "Datatype.h"
#include "Number.h"

namespace faker::helper
{
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
 * faker::helper::arrayElement<char>(std::string{"abcd"}) // "b"
 * faker::helper::arrayElement<std::string>(std::vector<std::string>{{"hello"}, {"world"}}) // "hello"
 * @endcode
 */
template <class T>
T arrayElement(std::span<const T> data)
{
    if (data.empty())
    {
        throw std::invalid_argument{"Data is empty."};
    }

    const auto index = number::integer<size_t>(data.size() - 1);

    return data[index];
}

template <typename T, std::size_t N>
T arrayElement(const std::array<T, N>& data)
{
    if (data.empty())
    {
        throw std::invalid_argument{"Data is empty."};
    }

    const auto index = number::integer<size_t>(data.size() - 1);

    return data[index];
}

template <typename It>
auto arrayElement(It start, It end) -> decltype(*::std::declval<It>())
{
    auto size = static_cast<size_t>(end - start);

    if (size == 0)
    {
        throw std::invalid_argument{"Range [start,end) is empty."};
    }

    const std::integral auto index = number::integer<size_t>(size - 1);

    return start[index];
}

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
 * faker::helper::arrayElement<std::string>(std::vector<std::string>{{"hello"}, {"world"}}) // "hello"
 * @endcode
 */
template <class T>
T arrayElement(const std::vector<T>& data)
{
    if (data.empty())
    {
        throw std::invalid_argument{"Data is empty."};
    }

    const auto index = number::integer<size_t>(data.size() - 1);

    return data[index];
}


/**
 * @brief Get a random element from an initializer list.
 *
 * @tparam T an element type of the initializer list.
 *
 * @param data initializer list of elements.
 *
 * @return T a random element from the initializer list.
 *
 * @code
 * faker::helper::arrayElement<std::string>(std::initializer_list<std::string>{{"hello"}, {"world"}}) // "hello"
 * @endcode
 */
template <class T>
T arrayElement(const std::initializer_list<T>& data)
{
    if (data.size() == 0)
    {
        throw std::invalid_argument{"Data is empty."};
    }

    const auto index = number::integer<size_t>(data.size() - 1);

    return *(data.begin() + index);
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
 * std::set<char> chars{'a', 'b', 'c', 'd', 'e'};
 * faker::helper::setElement(chars) // 'd'
 * @endcode
 */
template <class T>
T setElement(const std::set<T>& data)
{
    if (data.empty())
    {
        throw std::invalid_argument{"Data is empty."};
    }

    T item;

    static std::mt19937 pseudoRandomGenerator(std::random_device{}());

    std::sample(data.begin(), data.end(), &item, 1, pseudoRandomGenerator);

    return item;
}

template <class T>
struct WeightedElement
{
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
 * faker::helper::weightedArrayElement<std::string>(std::vector<helper::WeightedElement<std::string>>{{1, "value1"}, {10,
 * "value2"}}) // "hello2"
 * @endcode
 */
template <class T>
T weightedArrayElement(const std::vector<WeightedElement<T>>& data)
{
    if (data.empty())
    {
        throw std::invalid_argument{"Data is empty."};
    }

    const auto sumOfWeights =
        std::accumulate(data.begin(), data.end(), 0u,
                        [](unsigned sum, const WeightedElement<T>& element) { return sum + element.weight; });

    if (sumOfWeights == 0u)
    {
        throw std::invalid_argument{"Sum of weights is zero."};
    }

    const std::integral auto targetWeightValue = number::integer<unsigned>(1, sumOfWeights);

    unsigned currentSum = 0;

    size_t currentIdx = 0;

    while (currentIdx < data.size())
    {
        currentSum += data[currentIdx].weight;

        if (currentSum >= targetWeightValue)
        {
            break;
        }

        currentIdx++;
    }

    return data.at(currentIdx).value;
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
typename T::key_type objectKey(const T& object)
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
TResult maybe(std::function<TResult()> callback, double probability = 0.5)
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
std::vector<T> toVector(const std::array<T, N>& arr)
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
FAKER_CXX_EXPORT std::string replaceCreditCardSymbols(const std::string& inputString = "6453-####-####-####-###L", char symbol = '#');

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
