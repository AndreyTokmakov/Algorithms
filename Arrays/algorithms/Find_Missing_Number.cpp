/**============================================================================
Name        : Find_Missing_Number.cpp
Created on  : 26.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

#include <numeric>

/**
 *  ---- Array start from 0 ----
 *
 * Given an array nums containing n distinct numbers in the range [0, n],
 * return the only number in the range that is missing from the array.
 * Example 1:
 *   nums = [3,0,1] -> 2
 *   nums = [0,1]   -> 2
 *   nums = [9,6,4,2,3,5,7,0,1]   -> 8
 *
 *   Logic:
 *   Sum [1,2,3] -> 6, Sum [1,2,3,4] --> 10 |
 *   Formula:  (len * (len + 1)) / 2  --- For sequential arrays starting from 1
*/

namespace
{
    using namespace ArraysAlgorithms;

    int missing_number(const std::vector<int>& values)
    {
        const int sum = std::accumulate(values.cbegin(), values.cend(), 0);
        return static_cast<int>((values.size()  * (values.size() + 1)) / 2) - sum;
    }

}

void ArraysAlgorithms::Find_Missing_Number()
{
    using TestData = std::vector< std::pair<std::vector<int>, int> >;
    for (const auto& [value, expected]:  TestData{
        { {3,0,1} , 2 },
        { {0,1} , 2 },
        { {9,6,4,2,3,5,7,0,1} , 8 },
    })
    {
        if (const auto actual = missing_number(value); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}