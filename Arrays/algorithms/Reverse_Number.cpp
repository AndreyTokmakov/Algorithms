/**============================================================================
Name        : Reverse_Number.cpp
Created on  : 15.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Given a 32-bit signed integer, reverse digits of an integer.
Example 1: Input:  123  Output: 321
Example 2: Input: -123  Output: -321
Example 3: Input:  120  Output: 21
**/


namespace
{
    using namespace ArraysAlgorithms;

    int reverse_number(int number)
    {
        int reversed = 0;
        while (0 != number) {
            reversed = reversed * 10 + number % 10;
            number = number / 10;
        }
        return reversed;
    }
}

void ArraysAlgorithms::Reverse_Number()
{
    for (const auto& [value, expected]: std::vector<IntPair> {
            {123, 321}, {210, 12}, { -173, -371},
            {1234567, 7654321},
            {-4030, -304},
    }) {
        if (const auto actual = reverse_number(value); expected != actual) {
            std::cerr << expected << " != " << actual << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}