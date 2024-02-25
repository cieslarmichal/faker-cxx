#ifndef FAKER_TEST_HELPERS_H
#define FAKER_TEST_HELPERS_H

#include <algorithm>
#include <gtest/gtest.h>

namespace faker::testing {

template <typename ContainerT, typename PredT>
inline bool any_of(const ContainerT& container, const PredT& pred)
{
    return std::any_of(std::begin(container), std::end(container), pred);
}

template <typename ContainerT, typename PredT>
inline bool all_of(const ContainerT& container, const PredT& pred)
{
    return std::all_of(std::begin(container), std::end(container), pred);
}

template <typename ContainerT, typename ElementT>
inline bool contains(const ContainerT& container, const ElementT& element)
{
    return any_of(container, [&element](const auto& e) { return e == element; });
}

#define FAKER_EXPECT_CONTAINS(container, element) \
    EXPECT_TRUE(faker::testing::contains((container), (element)))

inline bool starts_with(const std::string& str, const std::string& prefix)
{
    return str.rfind(prefix, 0) == 0;
}

inline bool ends_with(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && str.rfind(suffix) == (str.size() - suffix.size());
}

template <typename ContainerT, typename ElementT>
inline size_t count(const ContainerT& container, const ElementT& elements)
{
    return std::count(std::begin(container), std::end(container), elements);
}

template <typename ContainerT, typename ElementT>
inline auto find(const ContainerT& range, const ElementT& element)
{
    return std::find(std::begin(range), std::end(range), element);
}

}

#endif