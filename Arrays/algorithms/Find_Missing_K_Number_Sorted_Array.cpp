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

    int find_K_missing_number(const std::vector<int>& values,
                              int K)
    {
        const int size = values.size();
        if (0 == size)
            return K;
        for (int idx = 0, expected = values[0]; idx < size; ) {
            if (expected++ != values[idx]) {
                if (0 == --K)
                    return expected - 1;
            } else {
                ++idx;
            }
        }
        return values.front() + size - 1 + K;
    }

    int find_K_missing_number_binary_search(const std::vector<int>& values,
                                            const int K)
    {
        const int size = values.size();
        if (0 == size)
            return K;
        int offset = values.front() - 1, missingNumber = offset + size + K;

        /// Binary Search for index where arr[i] > (offset + i + k)
        for (int idxLeft = 0, idxRight = size - 1, idxMid = 0; idxLeft <= idxRight ;)
        {
            if (idxMid = (idxLeft + idxRight) / 2; values[idxMid] > (offset + idxMid + K)) {
                missingNumber = offset + idxMid + K;
                idxRight = idxMid - 1;
            }
            else {
                idxLeft = idxMid + 1;
            }
        }

        return missingNumber;
    }
}

void ArraysAlgorithms::Find_Missing_K_Number_Sorted_Array()
{
    using TestData = std::vector<std::pair<std::pair<std::vector<int>, int>, int>>;
    for (const auto& [value, expected]:  TestData{
        { {{1, 2, 4, 5, 6, 8, 10, 13, 20}, 5} , 12 },
        { {{2, 3, 4, 7, 11}, 5} , 10 },
        { {{1,2,3}, 3} , 6 },
        { {{8,9}, 2} , 11 },
        { {{}, 2} , 2 },
    })
    {
        if (const auto actual = find_K_missing_number(value.first, value.second); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = find_K_missing_number_binary_search(value.first, value.second); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}