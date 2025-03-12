/**============================================================================
Name        : Remove_Duplicates_From_Sorted_Array.cpp
Created on  : 15.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
Example 1:   Given nums = [1,1,2],
             Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
             It doesn't matter what you leave beyond the returned length.

Example 2:   Given nums = [0,0,1,1,1,2,2,3,3,4],
             Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
**/

namespace

{
    using namespace ArraysAlgorithms;

    size_t remove_duplicates_sorted(std::vector<int> &nums)
    {
        size_t pos = 0;
        if (nums.empty())
            return pos;
        for (size_t idx = 1; idx < nums.size(); ++idx) {
            if (nums[pos] != nums[idx]) {
                nums[++pos] = nums[idx];
            }
        }
        nums.resize(++pos);
        nums.shrink_to_fit();
        return pos;
    }
}

void ArraysAlgorithms::Remove_Duplicates_From_Sorted_Array()
{
    for (auto& [values, expected]: std::vector<VectorPair<int>> {
            {{}, {}},
            {{0, 1, 2}, {0, 1, 2}},
            {{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {0, 1, 2, 3, 4}} ,
            {{0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5}, {0, 1, 2, 3, 4, 5}}
    })
    {
        remove_duplicates_sorted(values);
        if (values != expected) {
            std::cerr << values << " != " << expected << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}