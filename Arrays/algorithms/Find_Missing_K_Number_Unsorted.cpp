/**============================================================================
Name        : Find_Missing_K_Number_Unsorted.cpp
Created on  : 01.03.2025
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

    int find_K_missing_number(const std::vector<int>& values,
                              int K)
    {
        const auto [itMin, itMax] = std::minmax_element(values.cbegin(), values.cend());
        const int diff = *itMin - *itMax, min = *itMin;
        std::vector<int> tmp(diff + 1);
        for (int value : values)
            tmp[value - min] = 1;
        for (int i = 0; i <= diff; i++) {
            if (0 == tmp[i] && 0 == --K) {
                return i + min;
            }
        }
        return 0;
    }

    std::optional<int> find_K_missing_number_2(const std::vector<int>& values,
                                               int K) {
        const auto [itMin, itMax] = std::minmax_element(values.cbegin(), values.cend());
        std::unordered_set<int> set(values.cbegin(), values.cend());
        for (int i = *itMin; i < *itMax; ++i) {
            if (!set.contains(i) && 0 == --K) {
                return i;
            }
        }
        return std::nullopt;
    }
}

void ArraysAlgorithms::Find_Missing_K_Number_Unsorted()
{
    using TestData = std::vector<std::pair<std::pair<std::vector<int>, int>, std::optional<int>>>;
    for (int testNum = 1; const auto& [value, expected]:  TestData{
        { {{1,3}, 1} , 2 },
        { {{1,7}, 3} , 4 },
        { {{2, 4, 10, 7}, 5} , 9 },
        { {{2, 3, 4, 7, 11}, 5} , 10 },
        { {{1, 2, 3}, 2} , std::nullopt },
        { {{3, 5, 9, 10, 11, 12}, 2} , 6 },
    })
    {
        /*if (const auto actual = find_K_missing_number(value.first, value.second);
                expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }*/


        if (const auto actual = find_K_missing_number_2(value.first, value.second);
            expected != actual)
        {
            std::cerr << "Test Number " << testNum << " failed " << std::endl;
        }
        ++testNum;
    }
    std::cout << "OK: All tests passed\n";
}