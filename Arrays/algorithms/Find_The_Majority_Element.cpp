/**============================================================================
Name        : Find_The_Majority_Element.cpp
Created on  : 16.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


/** Problem:
Given an array of integers as std::vector<int>, return the majority element (guaranteed to be present).
A majority element has more than size/2 number of instances in the array.
There is a solution that runs in O(n) time and O(1) space.

Example 1: Input: [3,2,3] Output: 3
Example 2: Input: [2,2,1,1,1,2,2] Output: 2
**/

namespace
{
    using namespace ArraysAlgorithms;

    int majority_element(const std::vector<int>& nums)
    {
        int major = 0;
        for (size_t count = 0; auto v : nums) {
            if (0 == count) {
                major = v;
                count = 1;
            } else if (v == major) {
                ++count;
            } else {
                --count;
            }
        }
        return major;
    }
}

void ArraysAlgorithms::Find_The_Majority_Element()
{
    for (const std::vector<int>& v: std::vector<std::vector<int>> {
            // {0},
            {3,2,3},
            {2,2,1,1,1},     // --> 1
            {2,2,1,1,1,2,2}, // --> 2
            // {1,2,3,4,5,6,6,6,6,6,6,6},
    })
    {
        const int major = majority_element(v);
        std::cout << "[ " << v << "] ==> " << major << std::endl;
    }
}