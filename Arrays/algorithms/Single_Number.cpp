/**============================================================================
Name        : Single_Number.cpp
Created on  : 10.02.2025
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
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1: Input: [2,2,1]      Output: 1
Example 2: Input: [4,1,2,1,2]  Output: 4
*/

namespace
{
    int single_number(const std::vector<int>& nums)
    {
        int singleNum = 0;
        for (const int num : nums) {
            singleNum ^= num;
        }
        return singleNum;
    }
}

void ArraysAlgorithms::Single_Number()
{
    for (const std::pair<std::vector<int>, int>& data:  std::vector<std::pair<std::vector<int>, int>>{
            {{2, 2, 1}, 1}, {{4,1,2,1,2}, 4}, {{1}, 1}
    })
    {
        std::cout << single_number(data.first) << std::endl;
    }
}