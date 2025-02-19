/**============================================================================
Name        : Add_One_to_Integer_Array.cpp
Created on  : 19.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list,
and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:   Input: [1,2,3]   Output: [1,2,4]
Example 2:   Input: [4,3,2,1] Output: [4,3,2,2]
**/

namespace
{
    using namespace ArraysAlgorithms;

    void add_one_to_integer_array_PRINT(std::vector<int> array)
    {
        int pos = static_cast<int>(array.size());
        while (9 == array[--pos] && pos) {
            array[pos] = 0;
        }
        if (-1 == pos)
            std::cout << 1;
        else
            array[pos]++;

        for (const auto v: array)
            std::cout << v << " ";
        std::cout << std::endl;
    }

    std::deque<int> add_one_to_integer_array(const std::vector<int>& digits)
    {
        if (digits.empty())
            return {1};
        std::deque<int> result { digits.begin(), digits.end() };
        int pos = static_cast<int>(result.size());
        while (9 == digits[--pos] && pos >= 0) {
            result[pos] = 0;
        }
        if (-1 == pos)
            result.push_front(1);
        else
            result[pos]++;

        return result;
    }

    std::deque<int> plusOne(const std::vector<int>& digits)
    {
        if (digits.empty())
            return {1};

        std::deque<int> result ( digits.begin(), digits.end());
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            carry += digits[i];
            result[i] = carry % 10;
            carry /= 10;
        }
        if (carry > 0)
            result.insert(result.begin(), carry);
        return result;
    }
}

void ArraysAlgorithms::Add_One_to_Integer_Array()
{
   // add_one_to_integer_array_PRINT({1, 2, 3, 4, 5, 6, 7, 9, 9, 9});

    using TestData = std::vector<std::pair<std::vector<int>, std::deque<int>>>;
    for (const auto& [value, expected]:  TestData{
        { {1, 2, 3, 4, 5, 6, 7, 9, 9, 9} , { 1, 2, 3, 4, 5, 6, 8, 0, 0, 0} },
        { {1,2,3} , { 1,2,4} },
        { {4,3,2,1} , { 4,3,2,2} },
        { {9} , {1, 0} },
        { {} , {1} }
    })
    {
        {
            const auto actual = add_one_to_integer_array(value);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        {
            const auto actual = plusOne(value);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
    }
    std::cout << "OK: All tests passed\n";
}