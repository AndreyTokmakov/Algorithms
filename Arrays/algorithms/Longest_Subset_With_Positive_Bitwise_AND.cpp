/**============================================================================
Name        : Longest_Subset_With_Positive_Bitwise_AND.cpp
Created on  : 08.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given an array arr[] consisting of N positive integers, the task is to find the largest size of the
subset of the array arr[] with positive Bitwise AND.
Note : If there exist more than one such subsets then return size of only one subset.

Input:        arr[] = [7, 13, 8, 2, 3]   Output: 3
Explanation:  The subsets having Bitwise AND positive are {7,13,3} and {7,2,3} are of length 3,
              which is of maximum length among all possible subsets.

Input:        arr[] = [1, 2, 4, 8]  Output: 1


# https://www.geeksforgeeks.org/find-the-size-of-largest-subset-with-positive-bitwise-and/?ysclid=m80alz13i0783744028
*/

namespace
{
    using namespace ArraysAlgorithms;

    int longest_subset_positive_and(const std::vector<int>& input)
    {
        std::array<int, 32> bitsCounter {0};
        for (std::vector<int> values (input); int& value: values)
        {
            for (int bit = 32 - 1; value > 0; --bit) {
                bitsCounter[bit] += (value & 1);
                value = value >> 1;
            }
        }
        return *std::max_element(bitsCounter.cbegin(), bitsCounter.cend());
    }
}

void ArraysAlgorithms::Longest_Subset_With_Positive_Bitwise_AND()
{
    using TestData = std::vector< std::pair<std::vector<int>, int>>;
    for (const auto& [values, expected]:  TestData{
            { {7, 13, 8, 2, 3} , 3 },
            { {1, 2, 4, 8} , 1},
    })
    {
        if (const auto actual = longest_subset_positive_and(values); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}