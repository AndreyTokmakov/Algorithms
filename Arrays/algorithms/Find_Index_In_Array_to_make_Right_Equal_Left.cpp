/**============================================================================
Name        : Find_Index_In_Array_to_make_Right_Equal_Left.cpp
Created on  : 22.01.2025
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

    std::optional<int>
    find_index_to_make_right_equal_left(const std::vector<int>& values)
    {
        /// Check idxLeft && idxRight
        std::vector<int> sums(values.size(), values.front());
        for (int idx = 1, sum = values.front(); idx < values.size(); ++idx)
            sums[idx] = (sum += values[idx]);
        for (uint32_t idx = 1, leftSum = 0, rightSum = 0; idx < values.size() - 1; ++idx){
            leftSum = sums[idx] - values[idx], rightSum = sums.back() - sums[idx];
            if (leftSum == rightSum)
                return idx;
        }
        return std::nullopt;
    }
}

void ArraysAlgorithms::Find_Index_In_Array_to_make_Right_Equal_Left()
{
    using TestData = std::vector<std::pair<std::vector<int>,std::optional<int> >>;
    for (const auto& [values, expected]:  TestData{
        { {1, 1, 1, 100, 3},std::make_optional<int>(3) },
            { {7,2,1,5,4},std::make_optional<int>(2) },
            { {23,32,12,4},std::nullopt },
    })
    {
        const std::optional<int> actual = find_index_to_make_right_equal_left(values);
        if (expected.has_value() && actual.has_value() && expected.value() != actual.value()) {
            std::cerr << std::boolalpha << expected.value() << " != " << actual.value() << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}