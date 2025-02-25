/**============================================================================
Name        : Find_Longest_Increasing_Subsequence.cpp
Created on  : 25.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


namespace
{
    using namespace ArraysAlgorithms;

    size_t longest_increasing_subsequence_1(const std::vector<int>& values)
    {
        std::set<int> tmp;
        for (const int val: values)
        {   // 1. If element IS NOT inserted at the END, then delete next greater element from set
            // 2. Ignore the current element if already present in the set
            if (auto [iter, ok] = tmp.insert(val); ok && tmp.end() != std::next(iter))
                tmp.erase(std::next(iter));
        }
        return tmp.size();
    }

    /** Solution:
    The O(nlogn) solution is less obvious.

    If we consider building a subsequence iteratively, we have two situations.
    Either the next element is strictly higher, in which case we can simply append it.

    If it is not, we still want to remember it and we can do that by replacing the next higher value in the subsequence.

    This works because we only ever decrease values this way:
    - we won't break previous subsequences this way
    - we won't accidentally skip over potential subsequences
    **/

    size_t longest_increasing_subsequence_2(const std::vector<int> &numbers)
    {
        std::vector<int> path {numbers.front()};
        for (int i = 1, curr = 0; i < std::ssize(numbers); ++i)
        {
            curr = numbers[i];
            if (path.back() < curr) {
                // Current element is higher than the tail of the path.
                path.push_back(curr);
                continue;
            }

            // Find the element to overwrite
            auto it = std::upper_bound(path.begin(), path.end(), curr, [](int l, int r) {
                return l <= r;
            });

            // it != path.end() because path.back() >= nums[i];
            *it = curr;
        }
        return path.size();
    }
}

void ArraysAlgorithms::Find_Longest_Increasing_Subsequence()
{
    std::vector<std::pair<std::vector<int>, size_t>> testData{
                    {{1,  2,  3},                         3},
                    {{3,  2,  1},                         1},
                    {{2,  8,  4, 1,  9,  3,  5},          3},
                    {{2,  1,  4, 3,  6,  5,  8,  7,  9},  5},
                    {{1,  1,  1, 1},                      1},
                    {{10, 22, 9, 33, 21, 50, 41, 60, 80}, 6},
                    {{1,  2,  2, 3,  4,  4},              4}
    };
    for (const auto &[data, expected]: testData)
    {
        const auto actual1 = longest_increasing_subsequence_1(data);
        const auto actual2 = longest_increasing_subsequence_2(data);

        std::cout << actual1 << " | " << actual2 << " | " << expected << std::endl;
        if (actual1 != expected) {
            std::cerr << actual1 << " != " << expected << std::endl;
        }
        if (actual2 != expected) {
            std::cerr << actual2 << " != " << expected << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}