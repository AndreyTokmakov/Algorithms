/**============================================================================
Name        : House_Robber.cpp
Created on  : 02.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


/**
You are a professional robber planning to rob houses along a street.

Each house has a certain amount of money stashed, the only constraint stopping you from robbing each
of them is that adjacent  houses have security system connected and it will automatically contact
the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount
of money you can rob tonight without alerting the police.

Example 1: Input: [1,2,3,1]  Output: 4
           Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
           Total amount you can rob = 1 + 3 = 4.

Example 2: Input: [2,7,9,3,1]  Output: 12
           Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
           Total amount you can rob = 2 + 9 + 1 = 12.
**/

namespace
{
    using namespace ArraysAlgorithms;


    int rob(std::vector<int> values)
    {
        if (values.size() >= 2)
            values[1] = std::max(values[0], values[1]);
        for (int i = 2; i < values.size(); ++i) {
            values[i] = std::max(values[i - 1], values[i - 2] + values[i]);
        }
        return !values.empty() ? values.back() : 0;
    }

    /* int rob2(const std::vector<int>& values)
    {
        int maxValue = 0;
        if (values.size() >= 2)
            maxValue = std::max(values[0], values[1]);
        for (int i = 2, iterMax = 0; i < values.size(); ++i) {
            iterMax = std::max(values[i - 1], values[i - 2] + values[i]);
            maxValue = std::max(maxValue, iterMax);
            std::cout << i << " [" << values << "] iterMax: " << iterMax << " maxValue: " << maxValue << std::endl;
        }
        return maxValue;
    }*/
}

void ArraysAlgorithms::House_Robber()
{
    using TestData = std::vector< std::pair<std::vector<int>, int>>;
    for (const auto& [values, expected]:  TestData {
            { {1,2,3,1} , 4 },
            { {2,7,9,3,1} , 12 },
            { {7,2,9,3,1} , 17 },
            { {1,3,2,4} , 7 },
    })
    {
        if (const auto actual =  rob(values) ; expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
