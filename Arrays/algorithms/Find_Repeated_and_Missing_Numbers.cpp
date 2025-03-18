/**============================================================================
Name        : Find_Repeated_and_Missing_Numbers.cpp
Created on  : 17.03.2025
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

    // Note: Sequence should start from 1
    std::pair<int, int> find_repeating_and_missing(const std::vector<int> &values)
    {
        std::unordered_set<int> nums;
        int dif = 0, idxDuplicate = -1;
        for (int idx = 0; idx < static_cast<int>(values.size()); ++idx) {
            dif += idx - values[idx] + 1;
            if (-1 == idxDuplicate && !nums.insert(values[idx]).second)
                idxDuplicate = idx;
        }

        const int dup = values[idxDuplicate];
        return std::make_pair(dup, dup + dif);
    }
}

void ArraysAlgorithms::Find_Repeated_and_Missing_Numbers()
{
    using TestData = std::vector<std::pair<std::vector<int>, std::pair<int, int>>>;
    for (const auto& [values, expected]:  TestData {
        { {8, 7, 7, 4, 5, 6, 2, 1} , {7,3} },
        { {1,2,3,3,5} , {3,4} },
    })
    {
        const auto actual = find_repeating_and_missing(values);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}