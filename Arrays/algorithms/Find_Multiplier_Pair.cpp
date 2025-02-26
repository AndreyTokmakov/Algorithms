/**============================================================================
Name        : Find_Multiplier_Pair.cpp
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

    std::optional<std::pair<int, int>>
    find_multiplier_pair(const std::vector<int>& data,
                         const int K)
    {
        std::unordered_set<int> tmp;
        tmp.reserve(data.size());
        for (const int value: data)
        {
            if (0 != K % value)
                continue;
            if (tmp.contains(K/value))
                return std::make_pair(value, K / value );
            tmp.insert(value);
        }
        return std::nullopt;
    }

}

void ArraysAlgorithms::Find_Multiplier_Pair()
{
    using TestData = std::vector< std::pair<std::pair<std::vector<int>, int>, std::optional<std::pair<int, int>>>>;
    for (int testCount = 1; const auto& [value, expected]:  TestData{
            {{{1,2,3,4,6,7,9,10}, 10} , std::pair{10, 1}},
            {{{1,2,3,4,5,6,7,9,10}, 10} , std::pair{5, 2}},
            {{{}, 10} , std::nullopt },
            {{{1,2,3,4,5}, 3} , std::pair{3, 1}},
            {{{1,2,3,4,5}, 7} , std::nullopt }
    })
    {
        if (const auto actual = find_multiplier_pair(value.first, value.second); expected != actual) {
            std::cerr << "Test failed! number: " << testCount << std::endl;
        }
        ++testCount;
    }
    std::cout << "OK: All tests passed\n";
}