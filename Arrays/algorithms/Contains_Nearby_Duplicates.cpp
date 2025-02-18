/**============================================================================
Name        : Contains_Nearby_Duplicates.cpp
Created on  : 18.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given an array in integers and integer K, find out whether there are two distinct indices I and J in the
array such that nums[I] == nums[J] and the absolute difference between I and J is at mosk K

Example 1: nums = [1,2,3,1], k = 3,     Output: true
Example 2 nums = [1,0,1,1], k = 1       Output: true
Example 3: nums = [1,2,3,1,2,3], k = 2, Output: false

**/

namespace
{
    using namespace ArraysAlgorithms;

    bool contains_nearby_duplicates_1(const std::vector<int>& values,
                                      const int K)
    {
        std::unordered_map<int, int> map;
        for (int idx = 0; const int val : values) {
            if (map.contains(val)) {
                if (K >= idx - map[val])
                    return true;
            }
            map[val] = idx;
            ++idx;
        }
        return false;
    }

    bool contains_nearby_duplicates_2(const std::vector<int>& values,
                                      const int K)
    {
        std::unordered_set<int> visited;
        for (int idx = 0; const int val : values)
        {
            if (false == visited.emplace(val).second) /// 'visited' already contains 'val'
                return true;
            if (idx - K >= 0)
                visited.erase(values[idx - K]);
            ++idx;
        }
        return false;;
    }
}

void ArraysAlgorithms::Contains_Nearby_Duplicates()
{
    using TestData = std::vector<std::pair<std::pair<std::vector<int>, int>, bool>>;
    for (const auto& [input_data, expected]:  TestData{
        { {{1,2,3,1}, 3} , true },
        { {{1,0,1,1}, 1} , true },
        { {{1,2,3,1,2,3}, 2} , false },
    })
    {
        {
            const bool actual = contains_nearby_duplicates_1(input_data.first, input_data.second);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        {
            const bool actual = contains_nearby_duplicates_2(input_data.first, input_data.second);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
    }
    std::cout << "OK: All tests passed\n";
}
