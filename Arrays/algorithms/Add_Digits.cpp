/**============================================================================
Name        : Add_Digits.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


/**
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
Example 1:  Input: num = 38     Explanation: The process is
            Output: 2           38 --> 3 + 8 --> 11
                                11 --> 1 + 1 --> 2
                                Since 2 has only one digit, return it.
*/
namespace
{
    int add_digits(int value)
    {
        int tmp = 0;
        while (value > 9) {
            tmp = value; value = 0;
            while (tmp > 9) {
                value += tmp % 10;
                tmp = tmp / 10;
            }
            value += tmp;
        }
        return value;
    }
}

void ArraysAlgorithms::Add_Digits()
{
    for (const auto& [value, expected]: std::vector<std::pair<int, int>>{
        {10, 1}, {38, 2}, {123, 6}, {1234, 1},
        {8888, 5}, {99992, 2}
    }) {
        if (const auto actual = add_digits(value); expected != actual) {
            std::cerr << expected << " != " << actual << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}