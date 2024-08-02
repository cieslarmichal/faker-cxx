#pragma once

#include <initializer_list>
#include <numeric>
#include <span>
#include <vector>

#include "number.h"

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
 * faker::helper::randomElement<char>(std::string{"abcd"}) // "b"
 * faker::helper::randomElement<std::string>(std::vector<std::string>{{"hello"}, {"world"}}) // "hello"
 * @endcode
 */
template <class T>
T randomElement(std::span<const T> data)
{
    if (data.empty())
    {
        throw std::invalid_argument{"Data is empty."};
    }

    const auto index = number::integer<size_t>(data.size() - 1);

    return data[index];
}

template <typename T, std::size_t N>
T randomElement(const std::array<T, N>& data)
{
    if (data.empty())
    {
        throw std::invalid_argument{"Data is empty."};
    }

    const auto index = number::integer<size_t>(data.size() - 1);

    return data[index];
}

template <std::random_access_iterator It>
auto randomElement(It start, It end)
{
    if (start == end)
    {
        throw std::invalid_argument{"Range [start, end) is empty."};
    }

    auto size = end - start;
    const auto index = number::integer(size);

    return start[index];
}


template <std::forward_iterator It>
auto& randomElement(It start, It end)
{
    if (start == end)
    {
        throw std::invalid_argument{"Range [start, end) is empty."};
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::reference_wrapper<typename std::iterator_traits<It>::value_type> result = *start;
    ++start;
    size_t count = 1;

    while (start != end) {
        std::uniform_int_distribution<size_t> distrib(0, count - 1);
        if (distrib(gen) == 0) {
            result = *start;
        }
        ++start;
        ++count;
    }

    return result.get();
}

template <std::input_iterator It>
auto randomElement(It start, It end)
{
    if (start == end)
    {
        throw std::invalid_argument{"Range [start, end) is empty."};
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    auto result = std::move(*start);
    ++start;
    size_t count = 1;

    while (start != end) {
        std::uniform_int_distribution<size_t> distrib(0, count);
        if (distrib(gen) == 0) {
            result = std::move(*start);
        }
        ++start;
        ++count;
    }

    return result;
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
 * faker::helper::randomElement<std::string>(std::vector<std::string>{{"hello"}, {"world"}}) // "hello"
 * @endcode
 */
template <class T>
T randomElement(const std::vector<T>& data)
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
 * faker::helper::randomElement<std::string>(std::initializer_list<std::string>{{"hello"}, {"world"}}) // "hello"
 * @endcode
 */
template <class T>
T randomElement(const std::initializer_list<T>& data)
{
    if (data.size() == 0)
    {
        throw std::invalid_argument{"Data is empty."};
    }

    const auto index = number::integer<size_t>(data.size() - 1);

    return *(data.begin() + index);
}

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
 * faker::helper::weightedRandomElement<std::string>(std::vector<helper::WeightedElement<std::string>>{{1, "value1"},
 * {10, "value2"}}) // "hello2"
 * @endcode
 */

template <class T>
struct WeightedElement
{
    unsigned weight;
    T value;
};

template <class T>
T weightedRandomElement(const std::vector<WeightedElement<T>>& data)
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
    for (const auto& elem : data)
    {
        currentSum += elem.weight;
        if (currentSum >= targetWeightValue)
        {
            return elem.value;
        }
    }

    return data.back().value;
}

}
