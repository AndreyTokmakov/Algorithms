/**============================================================================
Name        : Two_Sum_Less_Than_K.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


/**
 * Given an array A of integers and integer K, return the maximum S such that there exists
 * i < j with A[i] + A[j] = S and S < K. If no i, j exist satisfying this equation, return -1.
 * Example: Input: A = [34,23,1,24,75,33,54,8], K = 60 --> Output: 58
 * Example: Input: A = [10,20,30], K = 15              --> Output: -1
 */

namespace
{
    int two_sum_less_than_k(std::vector<int> values, const int K)
    {
        std::sort(values.begin(), values.end());
        int result = -1;
        for (int left = 0, right = values.size() - 1; left < right; )
        {
            if (int sum = values[left] + values[right]; sum < K) {
                result = std::max(result, sum);
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }

}

void ArraysAlgorithms::Two_Sum_Less_Than_K()
{
    std::cout << two_sum_less_than_k({34,23,1,24,75,33,54,8}, 60) << std::endl;
    std::cout << two_sum_less_than_k({10,20,30}, 15) << std::endl;
}