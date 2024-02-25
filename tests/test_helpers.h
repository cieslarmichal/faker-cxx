#pragma once

#include <algorithm>
#include <gtest/gtest.h>

namespace faker::testing {

template <typename RangeT, typename PredT>
inline bool any_of(const RangeT& range, const PredT& pred)
{
    return std::any_of(std::begin(range), std::end(range), pred);
}

template <typename RangeT, typename PredT>
inline bool all_of(const RangeT& range, const PredT& pred)
{
    return std::all_of(std::begin(range), std::end(range), pred);
}

template <typename RangeT, typename ElementT>
inline bool contains(const RangeT& range, const ElementT& element)
{
    return any_of(range, [&element](const auto& e) { return e == element; });
}

inline bool starts_with(const std::string& str, const std::string& prefix)
{
    return str.rfind(prefix, 0) == 0;
}

inline bool ends_with(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && str.rfind(suffix) == (str.size() - suffix.size());
}

template <typename RangeT, typename ElementT>
inline size_t count(const RangeT& range, const ElementT& elements)
{
    return std::count(std::begin(range), std::end(range), elements);
}

template <typename RangeT, typename ElementT>
inline auto find(const RangeT& range, const ElementT& element)
{
    return std::find(std::begin(range), std::end(range), element);
}

}
