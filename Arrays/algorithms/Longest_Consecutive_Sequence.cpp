/**============================================================================
Name        : Longest_Consecutive_Sequence.cpp
Created on  : 19.01.2025
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

    int32_t longest_consecutive_sequence(const std::vector<int> &values)
    {
        const std::unordered_set<int> tmp(values.begin(), values.end());
        size_t count = 0;
        for (size_t len = 0; int val: values) {
            len = 0;
            while (tmp.contains(val++))
                len++;
            count = std::max(count, len);
        }
        return static_cast<int32_t>(count);
    }
}

void ArraysAlgorithms::Longest_Consecutive_Sequence()
{
    using TestData = std::vector< std::pair<std::vector<int>, int> >;
    for (const auto& [value, expected]:  TestData{
        { {100,4,200,1,3,2}, 4 },
        { {0,3,7,2,5,8,4,6,0,1}, 9 },
        { {1,0,1,2}, 3 },
        { {}, 0 },
    })
    {
        const auto actual = longest_consecutive_sequence(value);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}