/**============================================================================
Name        : Can_Jump.cpp
Created on  : 16.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
    Given an array of non-negative integers, you are initially positioned at the first index of the array.
    Each element in the array represents your maximum jump length at that position.
    Determine if you are able to reach the last index.
    Input: [2,3,1,1,4] --> True,
           [3,2,1,0,4] --> False
**/

namespace
{
    using namespace ArraysAlgorithms;

    bool canJump(const std::vector<int>& nums)
    {
        size_t step = 0;
        for (size_t idx = 0; idx < nums.size(); ++idx)
        {
            if (step >= idx) {
                step = std::max(idx + nums[idx], step);
            } else
                break;
        }
        return step > nums.size();
    };
}

void ArraysAlgorithms::Can_Jump()
{
    using TestData = std::vector<std::pair<std::vector<int>, bool>>;
    for (const auto& [input, expected]: TestData {
            {{2,3,1,1,4}, true},
            {{3,2,1,0,4}, false},
            {{3,3,1,0,4}, true},
    })
    {
        if (const bool actual = canJump(input); actual != expected) {
            std::cerr << actual << " != " << expected << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}