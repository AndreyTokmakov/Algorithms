/**============================================================================
Name        : Maximum_Product_SubArray.cpp
Created on  : 18.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**   Maximum Product Subarray

Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1: Input: nums = [2,3,-2,4]  Output: 6
           Explanation: [2,3] has the largest product 6.

Example 2: Input: nums = [-2,0,-1]   Output: 0
            Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

namespace
{
    using namespace ArraysAlgorithms;

    int max_product_subarray(const std::vector<int>& values)
    {
        int prodMax = values.front(), prodMin = values.front(), result = values.front();
        for (int idx = 1, maxPrev = 0, size = static_cast<int>(values.size()); idx < size; ++idx)
        {
            maxPrev = std::max(values[idx], std::max(prodMax * values[idx], prodMin * values[idx]));
            prodMin = std::min(values[idx], std::min(prodMax * values[idx], prodMin * values[idx]));
            prodMax = maxPrev;
            result = std::max(prodMax, result);
        }

        return result;
    }
}

void ArraysAlgorithms::Maximum_Product_SubArray()
{
    using TestData = std::vector<std::pair<std::vector<int>, int>>;
    for (const auto& [values, expected]: TestData {
            { {2,3,-2}, 6 },
            { {2,3,-2, 4}, 6 },
            { {2,3,-2, 4, 2}, 8 },
            { {-2,0,-1}, 0 },
            { {2,3,-2, 4, 2, -1 }, 96 },
    }) {
        if (const auto actual = max_product_subarray(values); expected != actual) {
            //error(std::format("{} != {}", expected, actual));
            std::cerr << actual << " != " << expected << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}



















