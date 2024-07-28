#include "gtest/gtest.h"
#include <algorithm>
#include <iterator>
#include <vector>

#include "word_data.h"

using namespace faker::word;
using namespace faker::word::cstd;
using namespace faker;
using namespace ::testing;

class WordDataTest : public Test
{
public:
};

TEST_F(WordDataTest, shouldIncrementDefault)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin();
    auto next_it = next(it);
    ASSERT_TRUE(*next_it == 2);
}

TEST_F(WordDataTest, shouldIncrementByN)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin();
    auto next_it = next(it, 3);
    ASSERT_TRUE(*next_it == 4);
}

TEST_F(WordDataTest, shouldCalculateDistance)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto start = vec.begin();
    auto end = vec.end();
    auto calc_distance = distance(start, end);
    ASSERT_TRUE(calc_distance == vec.size());
}

TEST_F(WordDataTest, shouldSwapAdjacentElements)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it1 = vec.begin();
    auto it2 = vec.begin() + 1;
    iter_swap(it1, it2);
    ASSERT_TRUE(*it1 == 2);
    ASSERT_TRUE(*it2 == 1);
}

TEST_F(WordDataTest, shouldSwapSameElement)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto it1 = vec.begin();
    iter_swap(it1, it1);
    ASSERT_TRUE(*it1 == 1);
}

TEST_F(WordDataTest, shouldSwapDifferentContainers)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {6, 7, 8, 9, 10};
    auto it1 = vec.begin();
    auto it2 = vec2.begin();
    iter_swap(it1, it2);
    ASSERT_TRUE(*it1 == 6);
    ASSERT_TRUE(*it2 == 1);
}

TEST_F(WordDataTest, shouldPartitionEvenOdd)
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = partition(vec.begin(), vec.end(), [](int n) { return n % 2 == 0; });
    ASSERT_TRUE(std::all_of(vec.begin(), it, [](int n) { return n % 2 == 0; }));
    ASSERT_TRUE(std::all_of(it, vec.end(), [](int n) { return n % 2 != 0; }));
}

TEST_F(WordDataTest, shouldPartitionGreaterThanFive)
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = partition(vec.begin(), vec.end(), [](int n) { return n > 5; });
    ASSERT_TRUE(std::all_of(vec.begin(), it, [](int n) { return n > 5; }));
    ASSERT_TRUE(std::all_of(it, vec.end(), [](int n) { return n <= 5; }));
}

TEST_F(WordDataTest, shouldSortAscending)
{
    std::vector<int> vec = {10, 7, 8, 9, 1, 5};
    quick_sort(vec.begin(), vec.end());
    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST_F(WordDataTest, shouldSortDescending)
{
    std::vector<int> vec = {10, 7, 8, 9, 1, 5};
    quick_sort(vec.begin(), vec.end(), std::greater<>());
    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end(), std::greater<>()));
}

TEST_F(WordDataTest, shouldSortSingleElement)
{
    std::vector<int> single_elem_vec = {1};
    quick_sort(single_elem_vec.begin(), single_elem_vec.end());
    ASSERT_TRUE(std::is_sorted(single_elem_vec.begin(), single_elem_vec.end()));
}

TEST_F(WordDataTest, shouldSortAlreadySorted)
{
    std::vector<int> sorted_vec = {1, 2, 3, 4, 5};
    quick_sort(sorted_vec.begin(), sorted_vec.end());
    ASSERT_TRUE(std::is_sorted(sorted_vec.begin(), sorted_vec.end()));
}

TEST_F(WordDataTest, shouldSortReverseSorted)
{
    std::vector<int> reverse_sorted_vec = {5, 4, 3, 2, 1};
    quick_sort(reverse_sorted_vec.begin(), reverse_sorted_vec.end());
    ASSERT_TRUE(std::is_sorted(reverse_sorted_vec.begin(), reverse_sorted_vec.end()));
}