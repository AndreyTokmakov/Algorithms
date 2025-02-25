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
        std::vector<int> mins(values.begin(), values.begin() + K);
        for (size_t i = K; i < std::size(values); i++) {
            std::partial_sort(mins.begin(), mins.begin() + 1, mins.end(), std::greater<>());
            if (mins.front() > values[i]) {
                mins[0] = values[i];
            }
        }
        return mins;
    }

    std::vector<int> find_N_min_elements_2(const std::vector<int>& values,
                                           const int K)
    {
        std::vector<int> mins(values.begin(), values.begin() + K);
        for (size_t i = K; i < std::size(values); i++) {
            std::make_heap(mins.begin(), mins.end(), std::less<>{});
            if (mins.front() > values[i]) {
                mins[0] = values[i];
            }
        }
        return mins;
    }

    std::vector<int> find_N_min_elements_part_sort(const std::vector<int>& values,
                                                   const int K)
    {
        std::vector<int> mins(values.begin(), values.begin() + K);
        std::nth_element(mins.begin(), mins.begin() + 1, mins.end(), std::greater<>());
        for (size_t i = K; i < std::size(values); i++) {
            if (mins.front() > values[i]) {
                mins.front() = values[i];
                std::nth_element(mins.begin(), mins.begin() + 1, mins.end(), std::greater<>());
            }
        }
        return mins;
    }
}

void ArraysAlgorithms::Find_N_Min_Elements()
{
    using TestData = std::vector< std::pair<std::pair<std::vector<int>, int>, std::vector<int>>>;
    for (const auto& [value, expected]:  TestData {
        {{ {4, 5, 6, 7, 8, 9, 10, 11, 0, -1}, 3}, { -1, 0, 4}},
        {{ {9,8,7,6,5,4,3,2,1}, 2}, { 1,2}}
    })
    {
        const auto [array, K] = value;

        {
            const auto actual = find_N_min_elements(array, K);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        {
            const auto actual = find_N_min_elements_2(array, K);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        {
            const auto actual = find_N_min_elements_part_sort(array, K);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
    }
    std::cout << "OK: All tests passed\n";
}
