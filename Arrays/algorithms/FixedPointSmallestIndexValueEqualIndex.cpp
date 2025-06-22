/**============================================================================
Name        : FixedPointSmallestIndexValueEqualIndex.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"



/**
 * Given an array A of distinct integers sorted in ascending order, return the smallest index i that
 * satisfies A[i] == i. Return -1 if no such i exists.
 * Example: [-10,-5,0,3,7]     -> 3
 * Example: [0,2,5,8,17]       -> 0
 * Example: [-10,-5,3,4,7,9]   -> -1
**/

namespace
{
    int fixed_point(const std::vector<int>& values)
    {
        int leftIdx = 0, rightIdx = values.size() - 1;
        while (leftIdx < rightIdx)
        {
            int midIdx = (leftIdx + rightIdx) >> 1;
            if (values[midIdx] < midIdx) {
                leftIdx = midIdx + 1;
            } else {
                rightIdx = midIdx;
            }
        }
        return values[leftIdx] == leftIdx ? leftIdx : -1;
    }

}

void ArraysAlgorithms::Fixed_Point_SmallestIndex_ValueEqualIndex()
{
    std::cout << fixed_point({-10,-5,0,3,7}) << std::endl;
    std::cout << fixed_point({0,2,5,8,17}) << std::endl;
    std::cout << fixed_point({-10,-5,3,4,7,9}) << std::endl;
}