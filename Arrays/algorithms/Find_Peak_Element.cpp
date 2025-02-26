/**============================================================================
Name        : Find_Peak_Element.cpp
Created on  : 26.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞.
In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.




**/
namespace
{
    using namespace ArraysAlgorithms;

    std::optional<int> find_first_peak_element(const std::vector<int>& values)
    {
        if (3 > values.size() )
            return std::nullopt;
        for (int idx = 1, size = values.size() - 1; idx < size; ++idx)
        {
            if (values[idx - 1] < values[idx] && values[idx] > values[idx + 1])
                return values[idx];
        }
        return std::nullopt;
    }

    std::optional<int> find_higher_peak_element(const std::vector<int>& values)
    {
        if (3 > values.size() )
            return std::nullopt;

        std::optional<int> peak;
        for (int idx = 1, size = values.size() - 1; idx < size; ++idx) {
            if (values[idx - 1] < values[idx] && values[idx] > values[idx + 1]) {
                peak = std::max(peak.value_or(std::numeric_limits<int>::min()), values[idx]);
            }
        }
        return peak;
    }
}

void ArraysAlgorithms::Find_Peak_Element()
{
    using TestData = std::vector< std::pair<std::vector<int>, std::optional<std::pair<int, int>>>>;
    for (const auto& [value, expected]:  TestData{
        { {1,2} , std::nullopt },
        { {1,2,3} , std::nullopt },
        { {1,2,3,1} , std::make_pair(3, 3) },
        { {1,2,3,4} , std::nullopt },
        { {1,2,1,3,5,6,4} , std::make_pair(2, 6)  },
    })
    {
        const std::optional<int> firstPeak = find_first_peak_element(value);
        const std::optional<int> higher_peak = find_higher_peak_element(value);

        if (expected.has_value() != firstPeak.has_value() || expected.has_value() != higher_peak.has_value()) {
            std::cerr << "Error: Actual result is NullOpt - Expected:" << expected.value() << std::endl;
        }
        if (expected.has_value() && firstPeak.value() != expected->first) {
            std::cerr << "Error: Actual result is " << firstPeak.value() << ", Expected: " << expected->first << std::endl;
        }
        if (expected.has_value() &&  higher_peak.value() != expected->second) {
            std::cerr << "Error: Actual result is " << higher_peak.value() << ", Expected: " << expected->second << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}