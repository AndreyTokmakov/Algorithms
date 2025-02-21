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


namespace
{
    using namespace ArraysAlgorithms;

    std::pair<bool, std::pair<size_t, size_t>>
    subarray_with_given_sum(const std::vector<int> &data, const int K)
    {
        std::unordered_map<size_t, size_t> map;
        for (int index = 0, sum = 0, size = data.size(); index < size; index++)
        {
            sum += data[index];
            if (sum == K)
                return {true, {0, index}};
            if (auto iter = map.find(sum - K); iter != map.end()) {
                return {true, {iter->second + 1, index}};
            }
            map[sum] = index;
        }
        return {false, {-1, -1}};
    }

    std::pair<bool, std::pair<size_t, size_t>>
    subarray_with_given_sum_2(const std::vector<int> &data, const int K)
    {
        std::unordered_multimap<int, size_t> map;
        for (int index = 0, sum = 0, size = data.size(); index < size; index++)
        {
            sum += data[index];
            if (sum == K)
                return {true, {0, index}};
            if (auto iter = map.find(sum - K); iter != map.end())
                return {true, {iter->second + 1, index}};

            map.insert({sum, index});
        }
        return {false, {-1, -1}};
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
            auto [success, borders] = subarray_with_given_sum(data.first, data.second);
            const std::vector<int> actual (data.first.begin() + borders.first,
                data.first.begin() + borders.second + 1);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        {
            auto [success, borders] = subarray_with_given_sum_2(data.first, data.second);
            const std::vector<int> actual (data.first.begin() + borders.first,
                data.first.begin() + borders.second + 1);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }

    }
    std::cout << "OK: All tests passed\n";

}
