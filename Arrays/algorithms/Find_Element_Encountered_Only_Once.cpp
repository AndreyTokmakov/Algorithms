/**============================================================================
Name        : Find_Element_Encountered_Only_Once.cpp
Created on  : 15.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given a non-empty array of integers, every element appears twice except for one.
Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement itwithout using extra memory?
Example 1: Input: [2,2,1]     Output: 1
Example 2: Input: [4,1,2,1,2]  Output: 4
**/

namespace
{
    using namespace ArraysAlgorithms;

    int singleNumber(const std::vector<int>& nums)
    {
        int ret = 0;
        for (int n: nums) {
            ret ^= n;
        }
        return ret;
    }

    /// Without constraint 'every element appears TWICE except for one'
    int singleNumber_GeneralCase(const std::vector<int>& nums)
    {
        std::unordered_map<int, int> counter;
        for (int val: nums)
            counter[val]++;

        for (const auto& [val, n]: counter) {
            if (n == 1)
                return val;
        }
        return 0;
    }
}

void ArraysAlgorithms::Find_Element_Encountered_Only_Once()
{
    using TestData = std::vector<std::pair<std::vector<int>, int>>;
    for (const auto& [values, expected]: TestData {
            { {2,2,1}, 1 },
            { {4,1,2,1,2}, 4 },
    }) {
        if (const auto actual = singleNumber(values); expected != actual) {
            std::cerr << expected << " != " << actual << std::endl;
            return;
        }

        if (const auto actual = singleNumber_GeneralCase(values); expected != actual) {
            std::cerr << expected << " != " << actual << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}
