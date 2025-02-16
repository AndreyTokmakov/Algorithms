/**============================================================================
Name        : Contains_Duplicate.cpp
Created on  : 15.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


namespace
{
    using namespace ArraysAlgorithms;

    bool contains_duplicate(const std::vector<int> &nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
        return nums.size() != set.size();
    }
}

void ArraysAlgorithms::Contains_Duplicate()
{
    for (const std::vector<int> &values: std::vector<std::vector<int>>{
            {1, 2, 3, 4, 5},
            {1, 2, 3, 4, 5, 3}
    }) {
        std::cout << std::boolalpha << contains_duplicate(values) << std::endl;
    }
}