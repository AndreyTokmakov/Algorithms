/**============================================================================
Name        : Sort_Array_By_Parity.cpp
Created on  : 16.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given an array A of non-negative integers, return an array consisting of all the
even elements of A, followed by all the odd elements of A.
You may return any answer array that satisfies this condition.
Example 1: Input: [3,1,2,4]  Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
**/
namespace
{
    using namespace ArraysAlgorithms;

    void sort_array_by_parity(std::vector<int>& values)
    {
        for (int idx = 0; int& val: values) {
            if ((val & 1) == false) {
                std::swap(values[idx++], val);
            }
        }
    }

}

void ArraysAlgorithms::Sort_Array_By_Parity()
{
    using TestData = std::vector< std::pair<std::vector<int>, std::vector<int>> >;
    for (const auto& [values, expected]:  TestData{
        { {3,1,2,4}, {2,4,3,1} },
        { {}, {} },
        { {1,2,3,4,5,6,7,8,9}, {2,4,6,8,5,3,7,1,9} },
    })
    {
        std::vector<int> actual (values);
        sort_array_by_parity(actual);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
