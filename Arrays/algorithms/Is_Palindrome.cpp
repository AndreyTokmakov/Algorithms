/**============================================================================
Name        : Is_Palindrome.cpp
Created on  : 15.01.2025
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

    bool is_palindrome(const int value)
    {
        if (0 > value)
            return false;
        long reversed = 0, number = value;
        while (0 != number) {
            reversed = reversed * 10 + number % 10;
            number = number / 10;
        }
        return reversed == value;
    }
}

void ArraysAlgorithms::Is_Palindrome()
{
    for (const int v: std::vector<int>{
            121, 234, 123454321
    }) {
        std::cout << "Is (" << v << ") palindrome: " << std::boolalpha << is_palindrome(v) << std::endl;
    }

}
