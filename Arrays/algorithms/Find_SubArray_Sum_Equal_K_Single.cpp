/**============================================================================
Name        : Find_SubArray_Sum_Equal_K_Single.cpp
Created on  : 20.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

#include <optional>


namespace
{
    using namespace ArraysAlgorithms;


    std::optional<std::span<const int>>
    subarray_with_given_sum(std::span<const int> data, const int K)
    {
        std::unordered_map<size_t, size_t> map;
        for (int index = 0, sum = 0, size = data.size(); index < size; index++)
        {
            sum += data[index];
            if (sum == K)
                return data.subspan(0, index + 1);
            if (auto iter = map.find(sum - K); iter != map.end()) {
                return data.subspan(iter->second + 1, index - iter->second);
            }
            map[sum] = index;
        }
        return std::nullopt;
    }

    std::optional<std::span<const int>>
    subarray_with_given_sum_2(std::span<const int> data, const int K)
    {
        std::unordered_multimap<int, size_t> map;
        for (int index = 0, sum = 0, size = data.size(); index < size; index++)
        {
            sum += data[index];
            if (sum == K)
                return data.subspan(0, index + 1);
            if (auto iter = map.find(sum - K); iter != map.end()) {
                return data.subspan(iter->second + 1, index - iter->second);
            }
            map.insert({sum, index});
        }
        return std::nullopt;
    }
}

void ArraysAlgorithms::Find_SubArray_Sum_Equal_K_Single()
{
    using TestData = std::vector< std::pair<std::pair<std::vector<int>, int>, std::vector<int>>>;
    for (const auto& [data, expected]:  TestData{
        { {{1, 4, 20, 3, 10, 5, 11}, 33}, {20, 3 , 10 }},
        { {{9, -5, 13, 2, -7, 10, -3}, 10}, {-5, 13, 2 }}
    })
    {
        {
            const std::optional<std::span<const int>> actual = subarray_with_given_sum(data.first, data.second);
            if (actual.value() != std::span<const int>(expected)) {
                std::cerr << std::boolalpha << expected << " != " << actual.value() << std::endl;
            }
        }
        {
            const std::optional<std::span<const int>> actual = subarray_with_given_sum_2(data.first, data.second);
            if (actual.value() != std::span<const int>(expected)) {
                std::cerr << std::boolalpha << expected << " != " << actual.value() << std::endl;
            }
        }
    }
    std::cout << "OK: All tests passed\n";
}
