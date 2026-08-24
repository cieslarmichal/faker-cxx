#pragma once

#include <numeric>
#include <random>
#include <vector>

#include "generator.h"
#include "number.h"

namespace faker::helper
{
template <typename T>
concept input_range_with_faster_size_compute_than_linear_rng =
    std::ranges::input_range<T> && (std::ranges::sized_range<T> || std::ranges::forward_range<T>);

template <input_range_with_faster_size_compute_than_linear_rng Range>
decltype(auto) randomElement(Range&& range)
{
    if (std::ranges::empty(range))
    {
        throw std::invalid_argument{"Range [start, end) is empty."};
    }

    const auto size = std::ranges::distance(range);

    const auto index = number::integer(size - 1);

    return (*std::ranges::next(range.begin(), index));
}

template <std::ranges::input_range Range>
auto randomElement(Range&& range)
{
    auto const end = range.end();
    auto itr = range.begin();

    if (itr == end)
    {
        throw std::invalid_argument{"Range [start, end) is empty."};
    }

    std::mt19937_64& gen = getGenerator();

    using RangeValue = std::ranges::range_value_t<decltype(range)>;
    auto consume_itr = [&itr]() -> decltype(auto)
    {
        using reference_type = std::ranges::range_reference_t<decltype(range)>;
        if constexpr (std::is_reference_v<reference_type>)
        {
            return std::move(*itr);
        }
        else
        {
            return *itr;
        }
    };

    RangeValue result = consume_itr();

    ++itr;

    std::size_t count = 1;

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
 * @brief Get a random element from one of two ranges, without concatenating them.
 *
 * @tparam Range1 the type of the first range.
 * @tparam Range2 the type of the second range.
 *
 * @param range1 the first range.
 * @param range2 the second range.
 *
 * @throws std::invalid_argument if both ranges are empty.
 *
 * @return a random element from range1 or range2.
 *
 * @code
 * faker::helper::randomElement(malesLastNames, femalesLastNames) // "Smith"
 * @endcode
 */
template <input_range_with_faster_size_compute_than_linear_rng Range1,
          input_range_with_faster_size_compute_than_linear_rng Range2>
decltype(auto) randomElement(Range1&& range1, Range2&& range2)
{
    const auto size1 = std::ranges::distance(range1);
    const auto size2 = std::ranges::distance(range2);

    if (size1 + size2 == 0)
    {
        throw std::invalid_argument{"Ranges are empty."};
    }

    const auto index = number::integer(size1 + size2 - 1);

    if (index < size1)
    {
        return (*std::ranges::next(range1.begin(), index));
    }

    return (*std::ranges::next(range2.begin(), index - size1));
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
        throw std::invalid_argument{"Sum of weights cannot be zero."};
    }

    const auto targetWeightValue = number::integer(1u, sumOfWeights);

    auto currentSum = 0u;

    for (const auto& elem : data)
    {
        currentSum += elem.weight;

        if (currentSum > targetWeightValue)
        {
            return elem.value;
        }
    }

    return data.back().value;
}

}
