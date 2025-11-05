 /**============================================================================
Name        : Count_Distinct_Pairs_With_Difference_K.cpp
Created on  : 13.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.


Example 1: Input: nums = [3,1,4,1,5], k = 2 Output: 2
            Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
            Although we have two 1s in the input, we should only return the number of unique pairs.

Example 2: Input: nums = [1,2,3,4,5], k = 1 Output: 4
           Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

Example 3: Input: nums = [1,3,1,5,4], k = 0   Output: 1
           Explanation: There is one 0-diff pair in the array, (1, 1).
*/

namespace
{
    template <typename T = int>
    struct Pair: std::pair<T, T> {
        constexpr Pair(const T& a, const T& b) : std::pair<T, T>{ a, b } {}
    };

    template <typename T>
    constexpr bool operator==(const Pair<T>& left, const Pair<T>& right) noexcept
    {
        return (left.first == right.first && left.second == right.second) ||
               (left.second == right.first && left.first == right.second);
    }

    template<typename T>
    struct PairHash
    {
        constexpr std::size_t operator()(const Pair<T>& pair) const noexcept {
            const std::size_t h1 = std::hash<T>{}(std::min(pair.first, pair.second));
            const std::size_t h2 = std::hash<T>{}(std::max(pair.first, pair.second));
            return h1 ^ (h2 << 1);
        }
    };

}


namespace
{
    using namespace ArraysAlgorithms;

    int count_distinct_pair_diff_K(const std::vector<int> &values,
                                   const int K)
    {
        int count = 0;
        std::unordered_map<int, bool> map;
        std::unordered_map<int, bool>::iterator iter;
        for (int i: values)
        {
            if (iter = map.find(i - K); map.end() != iter) {
                if (!iter->second) {
                    iter->second = true;
                    ++count;
                }
            }
            else if (iter = map.find(K - i); map.end() != iter) {
                if (!iter->second) {
                    iter->second = true;
                    ++count;
                }
            }
            else {
                map.emplace(i, false);
            }
        }
        return count;
    }

    int count_distinct_pair_diff_K_2(const std::vector<int> &values,
                                     const int K)
    {
        std::unordered_set<int> set;
        std::unordered_set<Pair<int>, PairHash<int>> result;
        for (int value: values)
        {
            if (set.contains(value - K)) {
                result.insert({value, value - K});
            }
            else if (set.contains(K + value)) {
                result.insert({value, K + value});
            }
            set.insert(value);
        }
        return result.size();
    }
}

void ArraysAlgorithms::Count_Distinct_Pairs_With_Difference_K()
{
    using TestData = std::vector<std::pair<std::pair<std::vector<int>, int>, int>>;
    for (const auto& [values, expected]:  TestData{
        { {{8, 12, 16, 4, 0, 20, 8, 8, 8, 8, 4, 4, 8, 4},4} , 5 },
        { {{3,1,4,1,5},2} , 2 },
        { {{1,2,4,4,3,3,0,9,2,3},3} , 2},
        { {{1, 5, 3, 4, 2},3} , 2 },
        { {{8, 12, 16, 4, 0, 20},4} , 5 },
        { {{5, 2, 4, 8, 3},3} , 2 },
        { {{3, 9, 8, 2, 5},6} , 2 },
        { {{1, 4, 1, 4, 5},3} , 1 },
        { {{1, 0, 2, 4, 5},4} , 2 },
        { {{-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8},6} , 5 },
        { {{1, 2, 3, 4},3} , 1 },
    })
    {
        /*{
            const auto actual = count_distinct_pair_diff_K(values.first, values.second);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }*/
        {
            const auto actual = count_distinct_pair_diff_K_2(values.first, values.second);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
    }
    std::cout << "OK: All tests passed\n";
}