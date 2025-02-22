/**============================================================================
Name        : Find_SubArrays_Sum_Equal_K.cpp
Created on  : 20.01.2025
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

    std::vector<std::span<const int>>
    find_all_sub_arrays_with_given_sum(std::span<const int> values,
                                       const int K)
    {
        std::vector<std::span<const int>> result;
        std::unordered_multimap<int, int> map = {{0, -1}};
        for (int idx = 0, sum = 0, size = values.size(); idx < size; ++idx)
        {
            sum += values[idx];

            /// As soon as we meet (sum - K) in the map, it means that there is at least one subarray with
            /// the sum 0. And the beginning of this list (lists) has a second index in the map
            if (auto iter = map.find(sum - K); map.end() != iter) {
                while (iter != map.end() && iter->first == static_cast<int>(sum - K)) {
                    result.push_back(values.subspan(iter->second + 1, idx - iter->second));
                    ++iter;
                }
            }
            map.insert({sum, idx});
        }
        return result;
    }
}

void ArraysAlgorithms::Find_SubArrays_Sum_Equal_K()
{
    {
        const std::vector<int> values = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
        std::vector<std::span<const int>> result = find_all_sub_arrays_with_given_sum(values, 7);
        for (const auto &span: result)
            std::cout << span << std::endl;

        // {3 4}, { 3 1 3 }, { 3 4 -7 3 1 3 }
    }

    {
        const std::vector<int> values = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
        std::vector<std::span<const int>> result = find_all_sub_arrays_with_given_sum(values, 5);
        for (const auto &span: result)
            std::cout << span << std::endl;

        // { 1 3 1}, { 4 -7 3 1 3 1 }
    }
}
