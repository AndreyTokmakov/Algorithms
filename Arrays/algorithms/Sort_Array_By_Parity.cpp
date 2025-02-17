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
            if (val & 1 == false) {
                std::cout << val << std::endl;
                std::swap(values[idx++], val);
            }
        }
    }

}

void ArraysAlgorithms::Sort_Array_By_Parity()
{
    std::vector<int> nums {3,1,2,4};
    sort_array_by_parity(nums);

    std::cout << "Sorted array: " << nums << std::endl;
}
