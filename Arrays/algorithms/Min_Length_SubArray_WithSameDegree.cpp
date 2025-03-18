/**============================================================================
Name        : Min_Length_SubArray_WithSameDegree.cpp
Created on  : 19.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**  Degree of an Array
 *
 * Given a non-empty array of non-negative integers nums, the degree of this array is defined
 * as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
 *
 * Explanation:
 *   The input array has a degree of 2 because both elements 1 and 2 appear twice.
 *   Of the subarrays that have the same degree:  [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 *   The shortest length is 2. So return 2.
 *
 *  Explanation:
 *    The degree is 3 because the element 2 is repeated 3 times.
 *    So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
*/

namespace
{
    using namespace ArraysAlgorithms;

    struct Stats final
    {
        int count{0};
        int start{0};
        int end{0};

        explicit Stats(int start = 0) : start{start} {}
    };

    int degreeOfArray(const std::vector<int>& values)
    {
        int maxOccurred = 0;
        std::unordered_map<int, Stats> counter{};
        for (int idx = 0; idx < static_cast<int>(values.size()); ++idx) {
            const auto [iter, ok] = counter.emplace(values[idx], idx);
            ++(iter->second.count);
            iter->second.end = idx;
            maxOccurred = std::max(maxOccurred, iter->second.count);
        }

        int minLength = values.size();
        for (const auto &[key, stats]: counter) {
            if (stats.count == maxOccurred)
                minLength = std::min(minLength, stats.end - stats.start + 1);
        }

        return minLength;
    }

}

void ArraysAlgorithms::Min_Length_SubArray_WithSameDegree()
{
    for (const std::vector<int> &input: std::vector<std::vector<int>>{
            {1, 2, 2, 3, 1}, // -> 2
            {2, 2, 3, 1, 4, 2}, // -> 6
            {2, 1, 1, 2, 1, 3, 3, 3, 1, 3, 1, 3, 2} // -> 7
    }) {
        const auto result = degreeOfArray(input);
        std::cout << "Result = " << result << std::endl;
    }
}