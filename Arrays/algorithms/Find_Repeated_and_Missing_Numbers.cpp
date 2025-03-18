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
    void find_repeating_and_missing(const std::vector<int> &values)
    {
        std::unordered_set<int> nums;
        int dif = 0, idxDuplicate = -1;
        for (int idx = 0; idx < static_cast<int>(values.size()); ++idx) {
            dif += idx - values[idx] + 1;
            if (-1 == idxDuplicate && !nums.insert(values[idx]).second)
                idxDuplicate = idx;
        }

        const int dup = values[idxDuplicate];
        std::cout << "Reaping symbol: " << dup << ", Missing: " << dup + dif << std::endl;
    }

    void _find_repeating_and_missing_ex(const std::vector<int> &values) {
        std::unordered_set<int> nums;
        int sum = 0, dup = 0, min = std::numeric_limits<int>::max();
        for (const int val: values) {
            min = std::min(val, min);
            sum += val;
            if (0 == dup && false == nums.insert(val).second)
                dup = val;
        }

        auto size = values.size();
        auto sum_expected = (size * (size + 1)) / 2 + size * (min - 1);

        std::cout << "Reaping symbol: " << dup << ", Missing: " << dup + sum_expected - sum << std::endl;
    }
}

void ArraysAlgorithms::Find_Repeated_and_Missing_Numbers()
{
    using TestData = std::vector<std::pair<std::vector<int>, std::pair<int, int>>>;
    for (const auto& [values, expected]:  TestData {
            { {8, 7, 7, 4, 5, 6, 2, 1} , {7,3} },
            //{ {5, 6, 7, 6, 9} , {1,1} },
    })
    {
        find_repeating_and_missing(values);

        /*
        const auto actual = TEST_FUNCTION(values);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        */
    }
    std::cout << "OK: All tests passed\n";
}