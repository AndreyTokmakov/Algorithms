/**============================================================================
Name        : Find_N_Min_Elements.cpp
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

    std::vector<int> find_N_min_elements(const std::vector<int>& values,
                                         const int K)
    {
        std::vector<int> minimums(values.begin(), values.begin() + K);
        for (size_t i = K; i < std::size(values); i++) {
            std::partial_sort(minimums.begin(), minimums.begin() + 1, minimums.end(), std::greater<>());
            if (minimums.front() > values[i]) {
                minimums[0] = values[i];
            }
        }
        return minimums;
    }

    std::vector<int> find_N_min_elements_2(const std::vector<int>& values,
                                           const int K)
    {
        std::vector<int> minimums(values.begin(), values.begin() + K);
        for (size_t i = K; i < std::size(values); i++) {
            std::make_heap(minimums.begin(), minimums.end(), std::less<>{});
            if (minimums.front() > values[i]) {
                minimums[0] = values[i];
            }
        }
        return minimums;
    }

    std::vector<int> find_N_min_elements_part_sort(const std::vector<int>& values,
                                                   const int K)
    {
        std::vector<int> minimums(values.begin(), values.begin() + K);
        std::nth_element(minimums.begin(), minimums.begin() + 1, minimums.end(), std::greater<>());
        for (size_t i = K; i < std::size(values); i++) {
            if (minimums.front() > values[i]) {
                minimums.front() = values[i];
                std::nth_element(minimums.begin(), minimums.begin() + 1, minimums.end(), std::greater<>());
            }
        }
        return minimums;
    }
}

void ArraysAlgorithms::Find_N_Min_Elements()
{
    using TestData = std::vector< std::pair<std::pair<std::vector<int>, int>, std::vector<int>>>;
    for (const auto& [value, expected]:  TestData {
        {{ {4, 5, 6, 7, 8, 9, 10, 11, 0, -1}, 3}, { -1, 0, 4}},
        {{ {9,8,7,6,5,4,3,2,1}, 2}, { 1,2 }},
        {{ {9,8,7,6,5,5,5,5,4,4,4}, 4}, {5,4,4,4 }}
    })
    {
        const auto [array, K] = value;
        if (const auto actual = find_N_min_elements(array, K); !unordered_equal(expected, actual)) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = find_N_min_elements_2(array, K); !unordered_equal(expected, actual)) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = find_N_min_elements_part_sort(array, K); !unordered_equal(expected, actual)) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
