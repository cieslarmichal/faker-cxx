#pragma once

#include <numeric>
#include <random>
#include <vector>

#include "number.h"

namespace faker::helper
{

template <typename T>
concept input_range_with_faster_size_compute_than_linear_rng = std::ranges::input_range<T> &&
    (std::ranges::sized_range<T> || std::ranges::forward_range<T>);

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

    std::random_device rd;
    std::mt19937 gen(rd());

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
