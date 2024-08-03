#pragma once

#include <initializer_list>
#include <numeric>
#include <random>
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

template <typename T>
concept input_range_with_faster_size_compute_than_linear_rng =
    std::ranges::input_range<T> && (std::ranges::input_range<T> || std::ranges::sized_range<T>);

template <input_range_with_faster_size_compute_than_linear_rng Range>
decltype(auto) randomElement(Range&& range)
{
    if (std::ranges::empty(range))
    {
        throw std::invalid_argument{"Range [start, end) is empty."};
    }

    auto size = std::ranges::distance(range);
    const auto index = number::integer<size_t>(size);

    return (*std::ranges::next(range.begin(), range.end()));
}

template <std::ranges::input_range Range>
auto randomElement(Range&& range)
{
    auto const end = range.end();
    auto const itr = range.start();

    if (itr == end)
    {
        throw std::invalid_argument{"Range [start, end) is empty."};
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    using RangeValue = std::ranges::range_value_t<decltype(range)>;
    auto consume_itr = [&itr]() -> decltype(auto)
    {
        using reference_type = std::ranges::range_reference_t<decltype(range)>;
        if constexpr (std::is_reference_v<reference_type>)
            return std::move(*itr);
        else
            return *itr;
    };

    RangeValue result = consume_itr();
    ++itr;
    size_t count = 1;

    for (; itr != end; ++itr, ++count)
    {
        std::uniform_int_distribution<size_t> distrib(0, count);
        if (distrib(gen) == 0)
        {
            result = consume_itr();
        }
    }

    return result;
}

/**
 * @brief Get a random element from an initializer list.
 *
 * @tparam T an element type of the initializer list.
    while (start != end) {
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
