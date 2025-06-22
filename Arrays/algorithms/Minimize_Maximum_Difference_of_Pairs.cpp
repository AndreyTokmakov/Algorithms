/**============================================================================
Name        : Minimize_Maximum_Difference_of_Pairs.cpp
Created on  : 20.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


/**
Given:

    An integer array nums
    An integer p (number of index pairs to form)
    Choose p disjoint pairs (no overlapping indices) such that the maximum absolute difference across all selected pairs is minimized.

Example
    nums = [10,1,2,7,1,3], p = 2
    Form pairs (1,4) and (2,5):
Example
    Differences: |1 - 1| = 0, |2 - 3| = 1 → Max = 1 (minimum possible maximum).
**/

namespace
{
    using namespace ArraysAlgorithms;

    int minimize_maximum_difference_of_Pairs(std::vector<int>& values,
                                             const int p)
    {
        std::sort(values.begin(), values.end());
        /** Min Heap to store pairwise differences  **/
        std::vector<int> minDiffs(p, values.back() - values.front());

        for (int idx = 1, diff = 0; idx < std::ssize(values); idx += 2) {
            diff = values[idx] - values[idx -1];
            minDiffs.front() = std::min(minDiffs.front(), diff);
            std::make_heap(minDiffs.begin(), minDiffs.end(), std::less<>{});
            //std::cout << minDiffs << std::endl;
        }

        for (int idx = 2, diff = 0; idx < std::ssize(values); idx += 2) {
            diff = values[idx] - values[idx -1];
            minDiffs.front() = std::min(minDiffs.front(), diff);
            std::make_heap(minDiffs.begin(), minDiffs.end(), std::less<>{});
            //std::cout << minDiffs << std::endl;
        }

        /** Return the maximum diff **/
        return minDiffs.front();
    }
}

void ArraysAlgorithms::Minimize_Maximum_Difference_of_Pairs()
{
    using InputData = std::tuple<std::vector<int>, int>;
    for ( auto& [input, expected]: std::vector<std::pair<InputData, int>> {
            {{{10,1,2,7,1,3}, 2}, 1},
            {{{4,2,1,2}, 1}, 0},
            {{{3,4,2,3,2,1,2}, 3}, 0},
    })
    {
        if (const auto actual = minimize_maximum_difference_of_Pairs(std::get<0>(input), std::get<1>(input));
            expected != actual) {
            std::cerr << actual << " != " << expected << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}