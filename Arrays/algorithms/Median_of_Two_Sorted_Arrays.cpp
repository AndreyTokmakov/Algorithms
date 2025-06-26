/**============================================================================
Name        : Median_of_Two_Sorted_Arrays.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:    Input: nums1 = [1,3], nums2 = [2]  --> Result: 2.00000
              Explanation: merged array = [1,2,3] and median is 2.

Example 2:    Input: nums1 = [1,2], nums2 = [3,4] --> Result: 2.50000
              Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

namespace
{
    double median_of_two_sorted_arrays(const std::vector<int>& nums1,
                                       const std::vector<int>& nums2)
    {
        const long size1 = std::ssize(nums1), size2 = std::ssize(nums2);
        const long steps = (size1 + size2) / 2 + 1;
        int m1 = 0, m2 = 0;
        for (int n = 0, idx1 = 0, idx2 = 0; n < steps; ++n)
        {
            m1 = m2;
            if (size1 > idx1 && size2 > idx2)
                m2 = nums1[idx1] > nums2[idx2] ? nums2[idx2++] : nums1[idx1++];
            else
                m2 = size1 > idx1 ? nums1[idx1++] : nums2[idx2++];
        }

        return (size1 + size2) % 2 == 1 ? static_cast<double>(m2) : static_cast<double>(m1 + m2) / 2;
    }
}

void ArraysAlgorithms::Median_of_Two_Sorted_Arrays()
{
    std::cout << median_of_two_sorted_arrays({1,3}, {2}) << std::endl;
    std::cout << median_of_two_sorted_arrays({1,2}, {3,4}) << std::endl;
    std::cout << median_of_two_sorted_arrays({1,2,3,4,5,6}, {12,13}) << std::endl;
}