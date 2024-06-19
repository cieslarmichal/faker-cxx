#pragma once

#include <array>
#include <functional>
#include <string_view>

namespace faker::word
{
extern const std::array<std::string_view, 1328> adjectives;
extern const std::array<std::string_view, 325> adverbs;
extern const std::array<std::string_view, 51> conjunctions;
extern const std::array<std::string_view, 46> interjections;
extern const std::array<std::string_view, 6659> nouns;
extern const std::array<std::string_view, 109> prepositions;
extern const std::array<std::string_view, 5910> verbs;

// https://tristanbrindle.com/posts/a-more-useful-compile-time-quicksort
namespace cstd
{
template <typename RAIt>
constexpr RAIt next(RAIt it, typename std::iterator_traits<RAIt>::difference_type n = 1)
{
    return it + n;
}

template <typename RAIt>
constexpr auto distance(RAIt first, RAIt last)
{
    return last - first;
}

template <class ForwardIt1, class ForwardIt2>
constexpr void iter_swap(ForwardIt1 a, ForwardIt2 b)
{
    auto temp = std::move(*a);
    *a = std::move(*b);
    *b = std::move(temp);
}

template <class InputIt, class UnaryPredicate>
constexpr InputIt find_if_not(InputIt first, InputIt last, UnaryPredicate q)
{
    for (; first != last; ++first)
    {
        if (!q(*first))
        {
            return first;
        }
    }
    return last;
}

template <class ForwardIt, class UnaryPredicate>
constexpr ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = cstd::find_if_not(first, last, p);
    if (first == last)
        return first;

    for (ForwardIt i = cstd::next(first); i != last; ++i)
    {
        if (p(*i))
        {
            cstd::iter_swap(i, first);
            ++first;
        }
    }
    return first;
}
} // namespace cstd

template <class RAIt, class Compare = std::less<>>
constexpr void quick_sort(RAIt first, RAIt last, Compare cmp = Compare{})
{
    auto const N = cstd::distance(first, last);
    if (N <= 1)
        return;
    auto const pivot = *cstd::next(first, N / 2);
    auto const middle1 = cstd::partition(first, last, [=](auto const& elem) { return cmp(elem, pivot); });
    auto const middle2 = cstd::partition(middle1, last, [=](auto const& elem) { return !cmp(pivot, elem); });
    quick_sort(first, middle1, cmp);
    quick_sort(middle2, last, cmp);
}

const std::array<std::string_view, adjectives.size() + adverbs.size() + conjunctions.size() + interjections.size() +
                                       nouns.size() + prepositions.size() + verbs.size()>
    _allWords = []()
{
    std::array<std::string_view, adjectives.size() + adverbs.size() + conjunctions.size() + interjections.size() +
                                     nouns.size() + prepositions.size() + verbs.size()>
        table{};

    size_t idx = 0;
    for (const auto& v : adjectives)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : adverbs)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : conjunctions)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : interjections)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : nouns)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : prepositions)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : verbs)
    {
        table[idx] = v;
        idx++;
    }

    quick_sort(table.begin(), table.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return table;
}();

const auto _adjectives_sorted = []()
{
    auto sorted = adjectives;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();

const auto _adverbs_sorted = []()
{
    auto sorted = adverbs;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();

const auto _conjunctions_sorted = []()
{
    auto sorted = conjunctions;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();

const auto _interjections_sorted = []()
{
    auto sorted = interjections;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();

const auto _nouns_sorted = []()
{
    auto sorted = nouns;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();

const auto _prepositions_sorted = []()
{
    auto sorted = prepositions;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();

const auto _verbs_sorted = []()
{
    auto sorted = verbs;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();
}
