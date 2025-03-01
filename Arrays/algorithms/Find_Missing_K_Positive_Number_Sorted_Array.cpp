/**============================================================================
Name        : Find_Missing_K_Positive_Number_Sorted_Array.cpp
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

    /**
    Using Index Comparison – O(n) Time and O(1) Space
    The idea is based on the following facts
    -  The value of the result would be at least k.
       For example, for [10, 11, 12] and k = 5, the answer would be X -> 5 and for [1, 2, 3] and k = 2, the answer would be X -> 5.
    -  The maximum possible value of X would be k + n where n is size of the array.
       This happen for arrays of first n natural numbers like [1, 2, 3, 4] and [1, 2, 3]
    -  While traversing the array, if arr[i] becomes greater than (k + i), then the k-th missing element is k + i.
    */
    int find_K_missing_positive_number(const std::vector<int>& values,
                                       const int K)
    {
        const int size = values.size();
        for (int idx = 0; idx < size; idx++) {
            if (values[idx] > (K + idx))
                return (K + idx);
        }

        // If all numbers from 1 to n are present in arr[], return k + n
        return K + size;
    }

    /**
     In the previous approach, we used linear search to find the first index where arr[i] > (k + i).
     Since the input array is sorted, once we have found the index i such that arr[i] > (k + i),
     then for all indices j (j > i), arr[j] will also be greater than (k + j).
     So, we can optimize the previous approach using binary search to find the index i so that the k-th missing element is k + i.
    */
    int find_K_missing_positive_number_binary_search(const std::vector<int>& values,
                                                     const int K)
    {
        int res = values.size() + K;
        for (int idxLeft = 0, idxRight = values.size() - 1; idxLeft <= idxRight ;)  /// Binary Search for index where arr[i] > (i + k)
        {
            const int mid = (idxLeft + idxRight) / 2;
            if (values[mid] > (K + mid)) {
                res = mid + K;
                idxRight = mid - 1;
            }
            else {
                idxLeft = mid + 1;
            }
        }

        return res;
    }
}

void ArraysAlgorithms::Find_Missing_K_Positive_Number_Sorted_Array()
{
    using TestData = std::vector<std::pair<std::pair<std::vector<int>, int>, int>>;
    for (const auto& [value, expected]:  TestData{
            { {{2, 3, 4, 7, 11}, 5} , 9 },
            { {{1, 2, 3}, 2} , 5 },
            { {{3, 5, 9, 10, 11, 12}, 2} , 2 },
    })
    {
        if (const auto actual = find_K_missing_positive_number(value.first, value.second);
            expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = find_K_missing_positive_number_binary_search(value.first, value.second);
            expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}