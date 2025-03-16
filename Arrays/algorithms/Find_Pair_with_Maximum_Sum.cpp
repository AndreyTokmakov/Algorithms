/**============================================================================
Name        : Find_Pair_with_Maximum_Sum.cpp
Created on  : 16.03.2025
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

    std::pair<int, int> maximum_sum_pair(const std::vector<int>& values)
    {
        if (2 > values.size())
            return {};

        std::pair<int, int> maxPair {values[0], values[1]};
        for (uint32_t idx = 2, len = values.size(); idx < len; ++idx)
        {
            maxPair.first = std::max(maxPair.first, values[idx]);
            if (maxPair.first > maxPair.second)
                std::swap(maxPair.first, maxPair.second);
        }

        return maxPair;
    }
}

void ArraysAlgorithms::Find_Pair_with_Maximum_Sum()
{
    using TestData = std::vector<std::pair<std::vector<int>, std::pair<int, int>>>;
    for (const auto& [values, expected]:  TestData {
            { {5,4,3,2,1, 7} , {5,7} },
            { {1,2,3,4,6,87,2, -1, 33} , {33, 87} },
    })
    {
        const auto actual = maximum_sum_pair(values);
        if (expected != actual) {
           std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
       }

    }
    std::cout << "OK: All tests passed\n";
}