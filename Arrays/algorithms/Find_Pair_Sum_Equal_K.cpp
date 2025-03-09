/**============================================================================
Name        : Find_Pair_Sum_Equal_K.cpp
Created on  : 09.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/** Two Sum - https://leetcode.com/problems/two-sum/description/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:  Input: nums = [2,7,11,15], target = 9  Output: [0,1]
            Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:  Input: nums = [3,2,4], target = 6  Output: [1,2]
Example 3:  Input: nums = [3,3],   target = 6  Output: [0,1]
**/

namespace
{
    using namespace ArraysAlgorithms;


    std::pair<int, int> pair_sum(const std::vector<int>& values, const int target)
    {
        if (values.size() < 2)
            return {-1, -1};

        std::unordered_map<int, int> map;
        map.reserve(values.size());
        for (int idx = 0, size = values.size(); idx < size; ++idx ) {
            if (const auto it = map.find(target - values[idx]); map.cend() != it) {
                return {idx, it->second};
            } else {
                map[values[idx]] = idx;
            }
        }

        return {-1, -1};
    }

}

void ArraysAlgorithms::Find_Pair_Sum_Equal_K()
{
    using TestData = std::vector<std::pair<std::pair<std::vector<int>,int>, std::pair<int, int>>>;
    for (const auto& [values, expected]:  TestData{
            { {{2,7,11,15}, 9} , {1, 0} },
            { {{3,2,4}, 6} , {2, 1} },
            { {{3,3}, 6} , {1, 0}  },
    })
    {
        const auto actual = pair_sum(values.first, values.second);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}