/**============================================================================
Name        : Product_of_Array_Except_Self.cpp
Created on  : 15.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include <numeric>
#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given an integer array nums, return an array answer such that answer[i] is equal to the product of
all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1: Input: nums = [1,2,3,4]      Output: [24,12,8,6]
Example 2: Input: nums = [-1,1,0,-3,3]  Output: [0,0,9,0,0]

**/
namespace
{
    using namespace ArraysAlgorithms;

    std::vector<int> product_of_array_except_self_1(const std::vector<int> &values)
    {
        std::vector<int> result(values.size(), 0);
        int allProd = 1, zeros = 0, zeroIdx = -1;
        for (int idx = 0; idx < std::ssize(values); ++idx) {
            if (0 != values[idx])
                allProd *= values[idx];
            else {
                zeroIdx = idx;
                ++zeros;
            }
        }

        if (0 == zeros) {
            for (int i = 0; i < std::ssize(values); ++i)
                result[i] = allProd / values[i];
        } else if (1 == zeros)
            result[zeroIdx] = allProd;

        return result;
    }

    std::vector<int> product_of_array_except_self_fast(const std::vector<int> &values)
    {
        if (values.empty())
            return {};

        int product = 1, product2 = 1, zerosCount = 0;
        for (int idx = 1, size = static_cast<int>(values.size()); idx < size; ++idx) {
            product *= values[idx];
            if (0 == values[idx])
                ++zerosCount;
            else
                product2 *= values[idx];
        }

        std::vector<int> result(values.size());
        result.front() = product;
        if (values.front() == 0 || zerosCount > 1) {
            return result;
        }

        for (int idx = 1, size = static_cast<int>(values.size()); idx < size; ++idx)
        {
            if (values[idx]) {
                product /= values[idx];
                product *= values[idx - 1];
                result[idx] = product;
            } else {
                result[idx] = product2 * values.front();
            }
        }

        return result;
    }
}

void ArraysAlgorithms::Product_of_Array_Except_Self()
{
    using TestData = std::vector<std::pair<std::vector<int>, std::vector<int>>>;
    for (const auto& [values, expected]:  TestData {
        { {1,2,3,4} , {} },
        { {1,2,3,4,5} , {} },
        { {-1,1,0,-3,3} , {} },
        { {1,2,0,4,5} , {} },
        { {-1,1,0,-3,3,0} , {} },
        { {-1,1,0,-3,3,1} , {} },
        { {0,0,0} , {} },
        { {0,1,2,3,4,5} , {} },
        { {0,1,2,0,4,5} , {} },
    })
    {
        {
            const auto actual = product_of_array_except_self_1(values);
            std::cout << actual << std::endl;
        }

        {
            const auto actual = product_of_array_except_self_fast(values);
            std::cout << actual << std::endl;
        }

        std::cout << std::endl;

        /*
        const auto actual = TEST_FUNCTION(values);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        */
    }
    std::cout << "OK: All tests passed\n";
}