/**============================================================================
Name        : Squares_of_a_Sorted_Array.cpp
Created on  : 25.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given an integer array nums sorted in non-decreasing order,
return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
**/

namespace
{
    using namespace ArraysAlgorithms;

    std::vector<int> sorted_squares(const std::vector<int>& values)
    {
        const int size = values.size();
        std::vector<int> res(size);
        for (int left = 0, right = size - 1, idx = size - 1; left <= right;)
        {
            if (values[left] * values[left] > values[right] * values[right]) {
                res[idx--] = values[left] * values[left];
                ++left;
            } else {
                res[idx--] = values[right] * values[right];
                --right;
            }
        }
        return res;
    }
}

void ArraysAlgorithms::Squares_of_a_Sorted_Array()
{
    using TestData = std::vector< std::pair<std::vector<int>, std::vector<int>> >;
    for (const auto& [value, expected]:  TestData{
        { {-4,-1,0,3,10} , {0,1,9,16,100} },
        { {-4, -3, -2, 0 ,1 ,5, 6, 9} , {0, 1,4,9,16,25,36,81} },
        { {-7,-3,2,3,11} , {4,9,9,49,121} },
    })
    {
        const auto actual = sorted_squares(value);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
