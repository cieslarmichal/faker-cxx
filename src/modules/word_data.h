#pragma once
#include <iostream>
#include <array>
#include <map>
#include <functional>
#include <string_view>

#include "word_store.h"
#include "faker-cxx/types/locale.h"
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

const std::array<std::string_view, enUSAdjectives.size() + enUSAdverbs.size() + enUSConjunctions.size() + enUSInterjections.size() +
                                       enUSNouns.size() + enUSPrepositions.size() + enUSVerbs.size()>
    _allWords = []()
{
    std::array<std::string_view, enUSAdjectives.size() + enUSAdverbs.size() + enUSConjunctions.size() + enUSInterjections.size() +
                                     enUSNouns.size() + enUSPrepositions.size() + enUSVerbs.size()>
        table{};

    size_t idx = 0;
    for (const auto& v : enUSAdjectives)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : enUSAdverbs)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : enUSConjunctions)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : enUSInterjections)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : enUSNouns)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : enUSPrepositions)
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : enUSVerbs)
    {
        table[idx] = v;
        idx++;
    }

    quick_sort(table.begin(), table.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return table;
}();

const std::map<faker::Locale, std::array<std::string_view, enUSAdjectives.size() + enUSAdverbs.size() + enUSConjunctions.size() + enUSInterjections.size() +
                                       enUSNouns.size() + enUSPrepositions.size() + enUSVerbs.size()>>
    _allWords_map = []()
{
    std::map<faker::Locale, std::array<std::string_view, enUSAdjectives.size() + enUSAdverbs.size() + enUSConjunctions.size() + enUSInterjections.size() +
                                       enUSNouns.size() + enUSPrepositions.size() + enUSVerbs.size()>> output;

    for (auto mapItem: nounsMap)
    {
    std::array<std::string_view, enUSAdjectives.size() + enUSAdverbs.size() + enUSConjunctions.size() + enUSInterjections.size() +
                                       enUSNouns.size() + enUSPrepositions.size() + enUSVerbs.size()>
        table{};

    size_t idx = 0;
    
    for (const auto& v : adjetivesMap.at(mapItem.first))
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : adverbsMap.at(mapItem.first))
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : conjunctionsMap.at(mapItem.first))
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : interjectionsMap.at(mapItem.first))
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : nounsMap.at(mapItem.first))
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : prepositionsMap.at(mapItem.first))
    {
        table[idx] = v;
        idx++;
    }

    for (const auto& v : verbsMap.at(mapItem.first))
    {
        table[idx] = v;
        idx++;
    }

    quick_sort(table.begin(), table.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    
    output.insert(std::make_pair(mapItem.first,table));
    }

    return output;
}();

const auto _adjectives_sorted = []()
{
    auto sorted = enUSAdjectives;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();

const auto _adjetives_sorted_map = [](){
   std::map<faker::Locale,std::array<std::string_view,1328UL>> adjetives_sorted;    
   for (auto i : adjetivesMap){
    auto list = i.second;
    quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    adjetives_sorted.insert(std::make_pair(i.first,list));
   }
   return adjetives_sorted;
}();

const auto _adverbs_sorted = []()
{
    auto sorted = adverbs;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();
const auto _adverbs_sorted_map = [](){
   std::map<faker::Locale,std::array<std::string_view,325UL>> adverbs_sorted;    
   for (auto i : adverbsMap){
    auto list = i.second;
    quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    adverbs_sorted.insert(std::make_pair(i.first,list));
   }
   return adverbs_sorted;
}();

const auto _conjunctions_sorted = []()
{
    auto sorted = conjunctions;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();

const auto _conjunctions_sorted_map = [](){
   std::map<faker::Locale,std::array<std::string_view,51UL>> conjuntions_sorted;    
   for (auto i : conjunctionsMap){
    auto list = i.second;
    quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    conjuntions_sorted.insert(std::make_pair(i.first,list));
   }
   return conjuntions_sorted;
}();

const auto _interjections_sorted = []()
{
    auto sorted = interjections;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();

const auto _interjections_sorted_map = [](){
   std::map<faker::Locale,std::array<std::string_view,46UL>> interjection_sorted;    
   for (auto i : interjectionsMap){
    auto list = i.second;
    quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    interjection_sorted.insert(std::make_pair(i.first,list));
   }
   return interjection_sorted;
}();

const auto _nouns_sorted = []()
{
    auto sorted = nouns;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();


const auto _nouns_sorted_map = [](){
   std::map<faker::Locale,std::array<std::string_view,6659UL>>nouns_sorted;    
   for (auto i : nounsMap){
    auto list = i.second;
    quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    nouns_sorted.insert(std::make_pair(i.first,list));
   }
   return nouns_sorted;
}();

const auto _prepositions_sorted = []()
{
    auto sorted = prepositions;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();


const auto _prepositions_sorted_map = []( )
{
    std::map<faker::Locale,std::array<std::string_view,109UL>>prepositions_sorted;    
    for (auto i : prepositionsMap){
    auto list = i.second;
    quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    prepositions_sorted.insert(std::make_pair(i.first,list));
   }
    return prepositions_sorted;
}();

const auto _verbs_sorted = []()
{
    auto sorted = verbs;
    quick_sort(sorted.begin(), sorted.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    return sorted;
}();


 const auto _verbs_sorted_map = []()
{    
    std::map<faker::Locale,std::array<std::string_view,5910UL>>verbs_sorted;    
    for (auto i : verbsMap){
    auto list = i.second;
    quick_sort(list.begin(), list.end(), [](const auto& lhs, const auto& rhs) { return lhs.size() < rhs.size(); });
    verbs_sorted.insert(std::make_pair(i.first,list));
   }
    return verbs_sorted;
}();

}