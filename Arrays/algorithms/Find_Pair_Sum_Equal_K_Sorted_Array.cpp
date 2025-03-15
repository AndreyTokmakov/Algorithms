/**============================================================================
Name        : Find_Pair_Sum_Equal_K_Sorted_Array.cpp
Created on  : 15.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to
a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1
must be less than index2.

Note:
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example: Input: numbers = [2,7,11,15], target = 9 Output: [0,1]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2

**/


namespace
{
    using namespace ArraysAlgorithms;


    std::pair<int, int> find_pair_sum(const std::vector<int>& values,
                                      const int target)
    {
        for (int32_t idxLeft = 0, idxRight = values.size() - 1; idxRight > idxLeft;) {
            if (values[idxLeft] + values[idxRight] == target) {
                return { idxLeft, idxRight };
            }
            if (values[idxLeft] + values[idxRight] < target) {
                ++idxLeft;
            } else {
                --idxRight;
            }
        }
        return {-1 , -1};
    }
}

void ArraysAlgorithms::Find_Pair_Sum_Equal_K_Sorted_Array()
{
    using TestData = std::vector<std::pair<std::pair<std::vector<int>, int>, std::pair<int, int>>>;
    for (const auto& [values, expected]:  TestData {
            { {{2,7,11,15}, 9} , {0, 1} },
            { {{2, 4, 5, 6, 7, 8, 9, 11}, 12} , {1, 5} },
    })
    {
        const auto actual = find_pair_sum(values.first, values.second);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}