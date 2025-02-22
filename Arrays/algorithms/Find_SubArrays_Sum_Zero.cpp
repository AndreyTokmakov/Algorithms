/**============================================================================
Name        : Find_SubArrays_SumZero.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

namespace
{
    std::optional<std::span<const int>>
    find_sub_arrays_sum_zero_SLOW(std::span<const int> values)
    {
        for (size_t i = 0; i < values.size(); i++) {
            for (size_t n = i, sum = 0; n < values.size(); n++) {
                sum += values[n];
                if (0 == sum) {
                    return values.subspan(i, n - i + 1);
                }
            }
        }
        return std::nullopt;
    }

    std::vector<std::span<const int>>
    find_subArrays_sum_zero(std::span<const int> values)
    {
        std::vector<std::span<const int>> result;
        std::unordered_multimap<int, int> map = {{0, -1}};
        for (int idx = 0, sum = 0, size = values.size(); idx < size; ++idx)
        {
            sum += values[idx];

            // As soon as we meet sum in the map, it means that there is at least one subarray with
            // the sum 0. And the beginning of this list (lists) has a second index in the map
            if (auto iter = map.find(sum); map.end() != iter) {
                while (iter != map.end() && iter->first == static_cast<int>(sum)) {
                    result.push_back(values.subspan(iter->second + 1, idx - iter->second));
                    ++iter;
                }
            }
            map.insert({sum, idx});
        }
        return result;
    }
}

void ArraysAlgorithms::Find_SubArrays_Sum_Zero()
{
    using TestData = std::vector< std::pair<std::vector<int>, std::vector<int>>>;
    for (const auto& [data, expected]:  TestData{
            { {1, 3, 2, -5, 3}, {3, 2, -5}},
    })
    {
        const std::optional<std::span<const int>> actual = find_sub_arrays_sum_zero_SLOW(data);
        if (actual.value() != std::span<const int>(expected)) {
            std::cerr << std::boolalpha << expected << " != " << actual.value() << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";

    const std::vector<int> values = { 3,4,-7,3,1,3,1,-4,-2,-2};
    std::vector<std::span<const int>> result = find_subArrays_sum_zero(values);
    for (const auto& span: result)
        std::cout << span << std::endl;
}
