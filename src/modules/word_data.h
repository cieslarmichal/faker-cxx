#pragma once
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <span>
#include <string_view>

#include "faker-cxx/types/locale.h"
#include "word_store.h"

namespace faker::word
{
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
}

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

const std::array<std::string_view, enUSAdjectives.size() + enUSAdverbs.size() + enUSConjunctions.size() +
                                       enUSInterjections.size() + enUSNouns.size() + enUSPrepositions.size() +
                                       enUSVerbs.size()>
    _allWords = []()
{
    std::array<std::string_view, enUSAdjectives.size() + enUSAdverbs.size() + enUSConjunctions.size() +
                                     enUSInterjections.size() + enUSNouns.size() + enUSPrepositions.size() +
                                     enUSVerbs.size()>
        table{};

    size_t idx = 0;
    for (const auto& v : idiomsMapSpan.at(faker::Locale::en_US).adjetives)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : idiomsMapSpan.at(faker::Locale::en_US).adverbs)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : idiomsMapSpan.at(faker::Locale::en_US).conjunctions)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : idiomsMapSpan.at(faker::Locale::en_US).interjections)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : idiomsMapSpan.at(faker::Locale::en_US).nouns)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : idiomsMapSpan.at(faker::Locale::en_US).prepositions)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : idiomsMapSpan.at(faker::Locale::en_US).verbs)
    {
        table[idx] = v;
        idx++;
    }

    quick_sort(table.begin(), table.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return table;
}();

const std::map<faker::Locale,
               std::array<std::string_view, enUSAdjectives.size() + enUSAdverbs.size() + enUSConjunctions.size() +
                                                enUSInterjections.size() + enUSNouns.size() + enUSPrepositions.size() +
                                                enUSVerbs.size()>>
    _allWords_map = []()
{
    std::map<faker::Locale,
             std::array<std::string_view, enUSAdjectives.size() + enUSAdverbs.size() + enUSConjunctions.size() +
                                              enUSInterjections.size() + enUSNouns.size() + enUSPrepositions.size() +
                                              enUSVerbs.size()>>
        output;

    for (auto mapItem : idiomsMapSpan)
    {
        std::array<std::string_view, enUSAdjectives.size() + enUSAdverbs.size() + enUSConjunctions.size() +
                                         enUSInterjections.size() + enUSNouns.size() + enUSPrepositions.size() +
                                         enUSVerbs.size()>
            table{};

        size_t idx = 0;

        for (const auto& v : idiomsMapSpan.at(mapItem.first).adjetives)
        {
            table[idx] = v;
            idx++;
        }

        for (const auto& v : idiomsMapSpan.at(mapItem.first).adverbs)
        {
            table[idx] = v;
            idx++;
        }

        for (const auto& v : idiomsMapSpan.at(mapItem.first).conjunctions)
        {
            table[idx] = v;
            idx++;
        }

        for (const auto& v : idiomsMapSpan.at(mapItem.first).interjections)
        {
            table[idx] = v;
            idx++;
        }

        for (const auto& v : idiomsMapSpan.at(mapItem.first).nouns)
        {
            table[idx] = v;
            idx++;
        }

        for (const auto& v : idiomsMapSpan.at(mapItem.first).prepositions)
        {
            table[idx] = v;
            idx++;
        }

        for (const auto& v : idiomsMapSpan.at(mapItem.first).verbs)
        {
            table[idx] = v;
            idx++;
        }

        quick_sort(table.begin(), table.end(),
                   [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });

        output.insert(std::make_pair(mapItem.first, table));
    }

    return output;
}();

const auto _adjectives_sorted = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> adjetives_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.adjetives)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        adjetives_sorted.insert(std::make_pair(i.first, list));
    }

    return adjetives_sorted.at(faker::Locale::en_US);
}();

const auto _adjetives_sorted_map = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> adjetives_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.adjetives)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        adjetives_sorted.insert(std::make_pair(i.first, list));
    }

    return adjetives_sorted;
}();

const auto _adverbs_sorted = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> adverbs_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.adverbs)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        adverbs_sorted.insert(std::make_pair(i.first, list));
    }
    return adverbs_sorted.at(faker::Locale::en_US);
}();
const auto _adverbs_sorted_map = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> adverbs_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.adverbs)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        adverbs_sorted.insert(std::make_pair(i.first, list));
    }
    return adverbs_sorted;
}();

const auto _conjunctions_sorted = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> conjunctions_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.conjunctions)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        conjunctions_sorted.insert(std::make_pair(i.first, list));
    }
    return conjunctions_sorted.at(faker::Locale::en_US);
}();

const auto _conjunctions_sorted_map = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> conjunctions_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.conjunctions)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        conjunctions_sorted.insert(std::make_pair(i.first, list));
    }

    return conjunctions_sorted;
}();

const auto _interjections_sorted = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> interjections_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.interjections)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        interjections_sorted.insert(std::make_pair(i.first, list));
    }

    return interjections_sorted.at(faker::Locale::en_US);
}();

const auto _interjections_sorted_map = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> interjections_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.interjections)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        interjections_sorted.insert(std::make_pair(i.first, list));
    }
    return interjections_sorted;
}();

const auto _nouns_sorted = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> nouns_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.nouns)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        nouns_sorted.insert(std::make_pair(i.first, list));
    }
    return nouns_sorted.at(faker::Locale::en_US);
}();

const auto _nouns_sorted_map = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> nouns_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.nouns)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        nouns_sorted.insert(std::make_pair(i.first, list));
    }
    return nouns_sorted;
}();

const auto _prepositions_sorted = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> prepositions_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.prepositions)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        prepositions_sorted.insert(std::make_pair(i.first, list));
    }
    return prepositions_sorted.at(faker::Locale::en_US);
}();

const auto _prepositions_sorted_map = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> prepositions_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.prepositions)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        prepositions_sorted.insert(std::make_pair(i.first, list));
    }
    return prepositions_sorted;
}();

const auto _verbs_sorted = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> verbs_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.verbs)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        verbs_sorted.insert(std::make_pair(i.first, list));
    }
    return verbs_sorted.at(faker::Locale::en_US);
}();

const auto _verbs_sorted_map = []()
{
    std::map<faker::Locale, std::vector<std::string_view>> verbs_sorted;
    for (auto i : idiomsMapSpan)
    {
        std::vector<std::string_view> list;
        for (auto j : i.second.verbs)
        {
            list.push_back(j);
        }

        quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
        verbs_sorted.insert(std::make_pair(i.first, list));
    }
    return verbs_sorted;
}();

}
