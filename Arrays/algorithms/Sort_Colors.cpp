/**============================================================================
Name        : Sort_Colors.cpp
Created on  : 13.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of
the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
*** You must solve this problem without using the library's sort function. ***

Example 1: Input: nums = [2,0,2,1,1,0] Output: [0,0,1,1,2,2]
Example 2: Input: nums = [2,0,1]       Output: [0,1,2]
*/

namespace
{
    using namespace ArraysAlgorithms;

    void sort_colors(std::vector<int>& values)
    {
        int pos = 0;
        for (int& v: values) {
            if (2 != v)
                std::swap(values[pos++], v);
        }
        for (int n = 0, pos2 = 0; n < pos; ++n) {
            if (1 != values[n])
                std::swap(values[pos2++], values[n]);
        }
    }

    void sort_colors_two_pointers(std::vector<int>& values)
    {
        for (int left = 0, right = static_cast<int>(values.size() - 1), idx = 0; idx < right; ++idx)
        {
            if (values[idx] == 0)
                std::swap(values[left++], values[idx++]);
            else if (values[idx] == 2)
                std::swap(values[right--], values[idx--]); /** Retry in this case 'idx = idx -1' **/
        }
    }
}

void ArraysAlgorithms::Sort_Colors()
{
    using TestData = std::vector<std::pair<std::vector<int>, std::vector<int>>>;
    for (const auto& [values, expected]:  TestData{
        { {2,0,2,1,1,0} , {0,0,1,1,2,2} },
        { {2,1,2,1,0,0} , {0,0,1,1,2,2} },
        { {} , {} },
    })
    {
        {
            std::vector<int> actual(values);
            sort_colors(actual);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        {
            std::vector<int> actual(values);
            sort_colors_two_pointers(actual);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
    }
    std::cout << "OK: All tests passed\n";
}