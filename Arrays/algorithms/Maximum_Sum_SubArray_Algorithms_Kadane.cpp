/**============================================================================
Name        : Maximum_Sum_SubArray_Algorithms_Kadane.cpp
Created on  : 16.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**  Maximum Subarray -- 'Kadane' Algorithm
    https://leetcode.com/problems/maximum-subarray/description/

Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1: Input: nums = [-2,1,-3,4,-1,2,1,-5,4], Output: 6
           Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2: Input: nums = [1] Output: 1
           Explanation: The subarray [1] has the largest sum 1.

Example 3: Input: nums = [5,4,-1,7,8] Output: 23
           Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
**/

namespace
{
    using namespace ArraysAlgorithms;

    int max_sum_subarray(const std::vector<int>& values)
    {
        int max_before = values.front(), max = max_before;
        for (size_t index = 1; index < values.size(); index++) {
            max_before = std::max(max_before + values[index], values[index]);
            max = std::max(max, max_before);
        }
        return max;
    }
}

void ArraysAlgorithms::Maximum_Sum_SubArray_Algorithms_Kadane()
{
    using TestData = std::vector<std::pair<std::vector<int>, int>>;
    for (const auto& [values, expected]: TestData {
            { {1, -3, 2, 1, -1}, 3 },
            { {-1, 4, -2, 5, -5, 2, -20, 6}, 7 },
            { {-2,1,-3,4,-1,2,1,-5,4}, 6 },
            { {1}, 1 },
            { {5,4,-1,7,8}, 23 },
    }) {
        if (const auto actual = max_sum_subarray(values); expected != actual) {
            std::cerr << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
