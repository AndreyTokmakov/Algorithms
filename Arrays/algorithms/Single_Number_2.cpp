/**============================================================================
Name        : Single_Number_2.cpp
Created on  : 02.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given a non-empty array of integers, every element appears three times except for
 one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:  Input: [2,2,3,2]         Output: 3
Example 2:  Input: [0,1,0,1,0,1,99]  Output: 99
**/

namespace
{
    using namespace ArraysAlgorithms;

    int single_number(const std::vector<int>& vector)
    {
        int ones = 0, twos = 0;
        for( int i = 0, size = vector.size(); i < size; i++)
        {
            ones = (ones ^ vector[i]) & ~twos;
            twos = (twos ^ vector[i]) & ~ones;
        }
        return ones | twos;
    }
}

void ArraysAlgorithms::Single_Number_2()
{
    using TestData = std::vector< std::pair<std::vector<int>, int>>;
    for (const auto& [values, expected]:  TestData{
            { { 2,2,3,2 } , 3 },
            { { 0,1,0,1,0,1,99 } , 99 },
            { { 1,2,3,1,11, 2,3,1,2,3 } , 11 },
    })
    {
        const auto actual = single_number(values);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}