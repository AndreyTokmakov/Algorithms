/**============================================================================
Name        : Find_Missing_Number_2.cpp
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
 *  ---- Array start from 1 ----
 *
 * Given an array nums containing n distinct numbers in the range [1, n],
 * return the only number in the range that is missing from the array.
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
        return static_cast<int>(((values.size() + 1)  * (values.size() + 2)) / 2) - sum;
    }

    int missing_number_loop(const std::vector<int>& values)
    {
        int result = 1;
        for (size_t index = 2; index <= (values.size() + 1); index++) {
            result += (index - values[index - 2]);
        }
        return result;
    }


}

void ArraysAlgorithms::Find_Missing_Number_2()
{
    using TestData = std::vector< std::pair<std::vector<int>, int> >;
    for (const auto& [value, expected]:  TestData{
        { {1,2,3,5} , 4 },
        { {5,4,3,1} , 2 },
    })
    {
        if (const auto actual = missing_number(value); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = missing_number_loop(value); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}