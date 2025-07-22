/**============================================================================
Name        : Minimum_Size_Subarray_Sum.cpp
Created on  : 22.07.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


/**
Given an array of positive integers nums and a positive integer target, return the minimal
 length of a subarray whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

**/

namespace
{
    using namespace ArraysAlgorithms;

    int minimum_size_subarray_sum(const std::vector<int>& values, int target)
    {
        int left(0), right(0), sum(0), minLength(std::numeric_limits<int>::max());
        while (right < values.size()){
            sum += values[right];
            while(sum >= target){
                minLength = std::min(minLength, right - left + 1);
                sum -= values[left++];
            }
            right++;
        }
        return (minLength == std::numeric_limits<int>::max() ? 0 : minLength);
    }
}

void ArraysAlgorithms::Minimum_Size_Subarray_Sum()
{
    using InputData = std::tuple<std::vector<int>, int>;
    for ( auto& [input, expected]: std::vector<std::pair<InputData, int>> {
            {{{2,3,1,2,4,3}, 7}, 2},
            {{{1,4,4}, 4}, 1},
            {{{1,1,1,1,1,1,1,1}, 11}, 0}
    })
    {
        if (const auto actual = minimum_size_subarray_sum(std::get<0>(input), std::get<1>(input));
                expected != actual) {
            std::cerr << actual << " != " << expected << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
