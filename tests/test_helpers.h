#ifndef FAKER_TEST_HELPERS_H
#define FAKER_TEST_HELPERS_H

#include <algorithm>
#include <cctype>
#include <common/span.h>
#include <gtest/gtest.h>
#include <string>

namespace faker::testing {

// strings

inline bool compare_no_case(std::string_view str1, std::string_view str2)
{
    if (str1.length() != str2.length()) {
        return false;
    }

    return std::equal(str1.begin(), str1.end(), str2.begin(),
        [](char a, char b) { return std::tolower(a) == std::tolower(b); });
}

// containers

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

template <size_t N1, size_t N2>
inline std::vector<std::string_view> make_vector(
    const std::array<std::string_view, N1>& a, const std::array<std::string_view, N2>& b)
{
    std::vector<std::string_view> result;
    result.reserve(a.size() + b.size());
    result.insert(result.end(), a.begin(), a.end());
    result.insert(result.end(), b.begin(), b.end());
    return result;
}

inline std::vector<std::string_view> make_vector(
    const utils::span<const std::string_view>& a, const utils::span<const std::string_view>& b)
{
    std::vector<std::string_view> result;
    result.reserve(a.size() + b.size());
    result.insert(result.end(), a.begin(), a.end());
    result.insert(result.end(), b.begin(), b.end());
    return result;
}

// strings

inline bool starts_with(const std::string& str, const std::string& prefix)
{
    return str.rfind(prefix, 0) == 0;
}

inline bool starts_with(const std::string& str, const std::string_view& prefix)
{
    return str.rfind(prefix, 0) == 0;
}

inline bool starts_with(const std::string& str, const char* prefix)
{
    return starts_with(str, std::string_view(prefix));
}

inline bool ends_with(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && str.rfind(suffix) == (str.size() - suffix.size());
}

inline bool ends_with(const std::string& str, const std::string_view& suffix)
{
    return str.size() >= suffix.size() && str.rfind(suffix) == (str.size() - suffix.size());
}

inline bool ends_with(const std::string& str, const char* suffix)
{
    return ends_with(str, std::string_view(suffix));
}

template <typename ContainerT> inline bool contains(const std::string& str, const ContainerT& part)
{
    return any_of(part, [&str](const auto& p) { return str.find(p) != std::string::npos; });
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

// macros

#define FAKER_EXPECT_CONTAINER_CONTAINS(container, element)                                        \
    EXPECT_TRUE(faker::testing::contains((container), (element)))

#define FAKER_EXPECT_STRING_STARTS_WITH(str, prefix)                                               \
    EXPECT_TRUE(faker::testing::starts_with((str), (prefix)))

#define FAKER_EXPECT_STRING_ENDS_WITH(str, suffix)                                                 \
    EXPECT_TRUE(faker::testing::ends_with((str), (suffix)))

#define FAKER_EXPECT_STRING_CONTAINS(str, part) EXPECT_TRUE(faker::testing::contains((str), (part)))

}

#endif