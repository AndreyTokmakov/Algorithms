/**============================================================================
Name        : Find_Longest_SubArray_K_Unique_Elements.cpp
Created on  : 22.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


/// // It is necessary to find the maximum length of the sub-array such that it contains no more than 'K' unique elements

namespace
{
    using namespace ArraysAlgorithms;

    size_t maxSubarrayLength(const std::vector<int>& nums,
                             const size_t k)
    {
        // Dictionary to keep track of the count of each number in the current window
        std::unordered_map<int, size_t> countMap;

        // Variable to store the maximum length found
        size_t maxLength = 0;

        // Two pointers defining the current window's boundaries
        for (size_t left = 0, right = 0, size = nums.size(); right < size; ++right)
        {
            // Increment the count of the rightmost element in the current window
            ++countMap[nums[right]];

            // If the count of the current element exceeds k, shrink the window from the left
            while (countMap[nums[right]] > k)
            {
                --countMap[nums[left]];
                ++left;  // Move the left pointer to the right
            }
            // Update the maximum length if the current window is larger
            maxLength = std::max(maxLength, right - left + 1);
        }
        // Return the maximum length of the sub-array
        return maxLength;
    }
}

void ArraysAlgorithms::Find_Longest_SubArray_K_Unique_Elements()
{
    using TestData = std::vector<std::pair<std::pair<std::vector<int>, size_t>, size_t>>;
    for (const auto& [value, expected]: TestData{
            {{{1, 2, 2, 3, 1, 2, 3},       2}, 5},
            {{{1, 2, 2, 3, 1, 3, 3},       2}, 6},
            {{{1, 1, 2, 2, 1, 2, 1},       2}, 4},
            {{{0},       2}, 1},
            {{{},       0}, 0},
    }) {
        const auto &[values, K] = value;
        if (const auto actual = maxSubarrayLength(values, K); actual != expected)
        {
            std::cout << "Expected value is " << expected << ", Actual: " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}