/**============================================================================
Name        : Find_N_Max_Elements.cpp
Created on  : 26.02.2025
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

    std::vector<int> find_N_max_elements(const std::vector<int>& values,
                                         const int K)
    {
        std::vector<int> maximums(values.begin(), values.begin() + K);
        for (size_t i = K; i < std::size(values); i++) {
            std::partial_sort(maximums.begin(), maximums.begin() + 1, maximums.end(), std::less<>());
            if (values[i] > maximums.front()) {
                maximums.front() = values[i];
            }
        }
        return maximums;
    }

    std::vector<int> find_N_max_elements_2(const std::vector<int>& values,
                                           const int K)
    {
        std::vector<int> maximums(values.begin(), values.begin() + K);
        for (size_t i = K; i < std::size(values); i++) {
            std::make_heap(maximums.begin(), maximums.end(), std::greater<>{});
            if (values[i] > maximums.front()) {
                maximums.front() = values[i];
            }
        }
        return maximums;
    }

    std::vector<int> find_N_max_elements_part_sort(const std::vector<int>& values,
                                                   const int K)
    {
        std::vector<int> maximums(values.begin(), values.begin() + K);
        std::nth_element(maximums.begin(), maximums.begin() + 1, maximums.end(), std::less<>());
        for (size_t i = K; i < std::size(values); i++) {
            if (values[i] > maximums.front()) {
                maximums.front() = values[i];
                std::nth_element(maximums.begin(), maximums.begin() + 1, maximums.end(), std::less<>());
            }
        }
        return maximums;
    }
}

void ArraysAlgorithms::Find_N_Max_Elements()
{
    using TestData = std::vector< std::pair<std::pair<std::vector<int>, int>, std::vector<int>>>;
    for (const auto& [value, expected]:  TestData {
        {{ {4, 5, 6, 7, 8, 9, 10, 11, 0, -1}, 3}, { 9, 10, 11}},
        {{ {1,2,3,4,5,6,7,8,9}, 2}, { 8,9}},
        {{ {1,2,3,4,5,5,6,6,6}, 4}, {5,6,6,6}}
    })
    {
        const auto [array, K] = value;
        if (const auto actual = find_N_max_elements(array, K); !unordered_equal(expected, actual)) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = find_N_max_elements_2(array, K); !unordered_equal(expected, actual)) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = find_N_max_elements_part_sort(array, K); !unordered_equal(expected, actual)) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
