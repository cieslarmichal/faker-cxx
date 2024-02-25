#ifndef FAKER_HELPER_H
#define FAKER_HELPER_H

#include <algorithm>
#include <array>
#include <faker/datatype.h>
#include <faker/number.h>
#include <functional>
#include <numeric>
#include <string>
#include <unordered_set>

namespace faker {
class Helper {
public:
    template <typename T, size_t N> static T arrayElement(const std::array<T, N>& data)
    {
        if (data.empty()) {
            throw std::invalid_argument { "Data is empty." };
        }

        const auto index = number::integer(data.size() - 1);

        return data[index];
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
     * Helper::arrayElement<char>(std::string{"abcd"}) // "b"
     * Helper::arrayElement<std::string>(std::vector<std::string>{{"hello"}, {"world"}}) // "hello"
     * @endcode
     */
    template <class T> static T arrayElement(T data)
    {
        if (data.empty()) {
            throw std::invalid_argument { "Data is empty." };
        }

        const auto index = number::integer(data.size() - 1);

        return data[index];
    }

    static char arrayElement(const std::string& data)
    {
        if (data.empty()) {
            throw std::invalid_argument { "Data is empty." };
        }

        const auto index = number::integer(data.size() - 1);

        return data[index];
    }

    static char arrayElement(const std::string_view& data)
    {
        if (data.empty()) {
            throw std::invalid_argument { "Data is empty." };
        }

        const auto index = number::integer(data.size() - 1);

        return data[index];
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
     * Helper::arrayElement<std::string>(std::vector<std::string>{{"hello"}, {"world"}}) // "hello"
     * @endcode
     */
    template <class T> static T arrayElement(const std::vector<T>& data)
    {
        if (data.empty()) {
            throw std::invalid_argument { "Data is empty." };
        }

        const auto index = number::integer(data.size() - 1);

        return data[index];
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
     * Helper::setElement(chars) // 'd'
     * @endcode
     */
    template <class T> static T setElement(const std::unordered_set<T>& data)
    {
        if (data.empty()) {
            throw std::invalid_argument { "Data is empty." };
        }
        T item;
        std::sample(data.begin(), data.end(), &item, 1, pseudoRandomGenerator);
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
     * Helper::weightedArrayElement<std::string>(std::vector<Helper::WeightedElement<std::string>>{{1,
     * "value1"}, {10, "value2"}}) // "hello2"
     * @endcode
     */
    template <class T> static T weightedArrayElement(const std::vector<WeightedElement<T>>& data)
    {
        if (data.empty()) {
            throw std::invalid_argument { "Data is empty." };
        }

        const auto sumOfWeights = std::accumulate(data.begin(), data.end(), 0u,
            [](unsigned sum, const WeightedElement<T>& element) { return sum + element.weight; });

        if (sumOfWeights == 0u) {
            throw std::invalid_argument { "Sum of weights is zero." };
        }

        const auto targetWeightValue = number::integer(1U, sumOfWeights);
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
    template <class T> static std::vector<T> shuffle(std::vector<T> data)
    {
        std::shuffle(std::begin(data), std::end(data), pseudoRandomGenerator);

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
     * Helper::shuffleString("hello") // "eollh"
     * @endcode
     */
    static std::string shuffleString(std::string data);

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
     * Helper::objectKey(testMap) // "2"
     * @endcode
     */
    template <typename T> static typename T::key_type objectKey(const T& object)
    {
        if (object.empty()) {
            throw std::runtime_error("Object is empty.");
        }

        std::vector<typename T::key_type> keys;
        for (const auto& entry : object) {
            keys.push_back(entry.first);
        }

        return arrayElement<typename T::key_type>(keys);
    }

    /**
     * @brief Returns the result of the callback if the probability check was successful, otherwise
     * empty string.
     *
     *
     * @tparam TResult The type of result of the given callback.
     *
     * @param callback The callback to that will be invoked if the probability check was successful.
     * @param probability The probability (`[0.00, 1.00]`) of the callback being invoked. Defaults
     * to `0.5`.
     *
     * @return The result of the callback if the probability check was successful, otherwise empty
     * string.
     *
     * @code
     * Helper::maybe<std::string>([]() { return "Hello World!"; }) // ""
     * Helper::maybe<int>([]() { return 42; }, 0.9) // "42"
     * @endcode
     */
    template <typename TResult>
    static TResult maybe(std::function<TResult()> callback, double probability = 0.5)
    {
        if (datatype::boolean(probability)) {
            return callback();
        }
        return TResult();
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
     * Helper::replaceSymbolWithNumber() // ""
     * Helper::replaceSymbolWithNumber("#####") // "04812"
     * Helper::replaceSymbolWithNumber("!####") // "27378"
     * Helper::replaceSymbolWithNumber("Your pin is: !####") // "29841"
     * @endcode
     */
    static std::string replaceSymbolWithNumber(const std::string& str, const char& symbol = '#');
    static std::string replaceSymbolWithNumber(
        const std::string_view& str, const char& symbol = '#');

    /**
     * @brief Returns credit card schema with replaced symbols and patterns in a credit card
     * including Luhn checksum This method supports both range patterns `[4-9]` as well as the
     * patterns used by `replaceSymbolWithNumber()`. `L` will be replaced with the appropriate Luhn
     * checksum.
     *
     * @param inputString TThe credit card format pattern. Defaults to "6453-####-####-####-###L".
     * @param symbol The symbol to replace with a digit. Defaults to '#'.
     *
     * @return The string replaced symbols with digits.
     *
     * @code
     * Helper::replaceCreditCardSymbols() // "6453-4876-8626-8995-3771"
     * Helper::replaceCreditCardSymbols("1234-[4-9]-##!!-L") // "1234-9-5298-2"
     * @endcode
     */
    static std::string replaceCreditCardSymbols(
        const std::string& inputString = "6453-####-####-####-###L", char symbol = '#');

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
     * Helper::regexpStyleStringParse() // ""
     * Helper::regexpStyleStringParse("#{5}") // "#####"
     * Helper::regexpStyleStringParse("#{2,9}") // "#######"
     * Helper::regexpStyleStringParse("[500-15000]") // "8375"
     * Helper::regexpStyleStringParse("#{3}test[1-5]") // "###test3"
     * @endcode
     */
    static std::string regexpStyleStringParse(const std::string& input);

    static std::string regexpStyleStringParse(const std::string_view& input) {
        return regexpStyleStringParse(std::string(input));
    }

private:
    static std::random_device randomDevice;
    static std::mt19937 pseudoRandomGenerator;
};
}

#endif