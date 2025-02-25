/**============================================================================
Name        : Longest_Subarray_With_Sum_Less_Than_K.cpp
Created on  : 25.02.2025
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

    size_t longest_subarray_with_sum_less_than_K(const std::vector<int>& values,
                                                           const int K)
    {
        const int size = values.size();

        // Create a Prefix Sum array
        std::vector<int> preSum(size, values.front());
        for (int i = 1, sum = values.front(); i < size; i++)
            preSum[i] = (sum += values[i]);

        int res = std::numeric_limits<int>::min();
        for (auto iter = preSum.begin(); iter != preSum.end(); ++iter)
        {
            // Maximum value - max sum of sub-array: calculated as K  + preSum[idx]
            // -1 --> Because (it should be LESS but LESS+EQUAl)
            const int toFind = K + *iter - 1;
            std::cout << toFind << std::endl;

            // First value (sum of sub-array) greater or equal 'toFind'
            const auto bound = std::upper_bound(preSum.begin(), preSum.end(), toFind);
            if (bound == preSum.end())
                continue;

            // Iterator to prefix sum array element with Sum of subarray less than K
            const auto prev = std::prev(bound);
            if (prev == preSum.end())
                continue;

            res = std::max(res, static_cast<int>(std::distance(iter, prev)));
        }

        return res == std::numeric_limits<int>::max() ? 0 : res;
    }
}

void ArraysAlgorithms::Longest_Subarray_With_Sum_Less_Than_K()
{
    using TestData = std::vector< std::pair<std::pair<std::vector<int>, int>, int> >;
    for (const auto& [value, expected]:  TestData{
        { {{2,3,1,2,4,1,1,1,1,1,3}, 7} , 5 },
        { {{2,3,1,2,4,1,1,1,1,1,3}, 5} , 4 },
    })
    {
        const auto actual = longest_subarray_with_sum_less_than_K(value.first, value.second);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}