/**============================================================================
Name        : Longest_Harmonious_Subsequence.cpp
Created on  : 16.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
We define a harmounious array as an array where the difference between its maximum value and its minimum value is exactly 1.
Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.
Example 1:
Input: [1,3,2,2,5,2,3,7]  Output: 5
       Explanation: The longest harmonious subsequence is [3,2,2,2,3].
**/

namespace
{
    using namespace ArraysAlgorithms;

    int32_t findLHS(const std::vector<int>& values)
    {
        if (values.empty())
            return 0;
        std::unordered_map<int, int> counter;
        for (int val : values)
            ++counter[val];
        int result = 0;
        for (auto& [value, currValCount] : counter)
        {
            const auto itMinusOne = counter.find(value - 1);
            if (counter.end() == itMinusOne)
                continue;

            const int minusOneCount = itMinusOne->second;
            result = std::max(result, minusOneCount + currValCount);
        }
        return result;
    }

}

void ArraysAlgorithms::Longest_Harmonious_Subsequence()
{
    std::cout << findLHS({1,3,2,2,5,2,3,7}) << std::endl;
}