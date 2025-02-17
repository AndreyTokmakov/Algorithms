/**============================================================================
Name        : Maximum_Sum_SubArray_Algorithms_Kadane.cpp
Created on  : 16.01.2025
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

    int max_sum_subarray(const std::vector<int>& values)
    {
        int max_before = values.front(), max = max_before;
        for (size_t index = 1; index < values.size(); index++) {
            max_before = std::max(max_before + values[index], values[index]);
            max = std::max(max, max_before);
        }
        return max;
    }
}

void ArraysAlgorithms::Maximum_Sum_SubArray_Algorithms_Kadane()
{
    using TestData = std::vector<std::pair<std::vector<int>, int>>;
    for (const auto& [values, expected]: TestData {
            { {1, -3, 2, 1, -1}, 3 },
            { {-1, 4, -2, 5, -5, 2, -20, 6}, 7 },
    }) {
        if (const auto actual = max_sum_subarray(values); expected != actual) {
            std::cerr << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
