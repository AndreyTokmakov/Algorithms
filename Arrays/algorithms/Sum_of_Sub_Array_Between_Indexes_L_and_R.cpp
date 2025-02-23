/**============================================================================
Name        : Sum_of_Sub_Array_Between_Indexes_L_and_R.cpp
Created on  : 23.01.2025
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


    int sum_between_indexes(const std::vector<int>& values,
                            const int idxLeft,
                            const int idxRight)
    {
        // Check idxLeft && idxRight
        std::vector<int> sums(values.size(), values.front());
        for (int i = 1, sum = values.front(); i < values.size(); i++)
            sums[i] = (sum += values[i]);

        return 0 == idxLeft ? sums[idxRight] : sums[idxRight] - sums[idxLeft - 1];
    }

}

void ArraysAlgorithms::Sum_of_Sub_Array_Between_Indexes_L_and_R()
{
    using TestData = std::vector<std::pair<std::pair<  std::vector<int>, std::pair<int, int>         >, int>>;
    for (const auto& [value, expected]:  TestData{
            { {{1,2,3,4,5}, {1,3}} , 9 },
            { {{1,2,3,4,5}, {2,3}} , 7 }
    })
    {
        const auto& [values, indexes] = value;
        const auto actual = sum_between_indexes(values, indexes.first, indexes.second);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}