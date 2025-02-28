/**============================================================================
Name        : Find_Missing_K_Number_Sorted_Array.cpp
Created on  : 28.02.2025
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

    int find_K_missing_number_sorted(const std::vector<int>& values,
                                     const size_t K)
    {
        int expected = values[0], count = 0;
        for (size_t index = 0; index < values.size(); index++) {
            if (expected++ != values[index]) {
                if (static_cast<int>(K) == ++count)
                    return expected - 1;
                index--;
            }
        }
        return 0;
    }

    int find_K_missing_number_sorted_2(const std::vector<int>& values,
                                       size_t K) {
        int expected = values[0];
        size_t index = 0;
        while (index < values.size()) {
            if (values[index] != expected) {
                if (0 == --K)
                    return expected;
            } else {
                index++;
            }
            expected++;
        }
        return 0;
    }

}

void ArraysAlgorithms::Find_Missing_K_Number_Sorted_Array()
{
    using TestData = std::vector<std::pair<std::pair<std::vector<int>, int>, int>>;
    for (const auto& [value, expected]:  TestData{
        { {{1, 2, 4, 5, 6, 8, 10, 13, 20}, 5} , 12 },
    })
    {
        if (const auto actual = find_K_missing_number_sorted(value.first, value.second); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
}