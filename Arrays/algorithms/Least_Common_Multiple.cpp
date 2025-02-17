/**============================================================================
Name        : Least_Common_Multiple.cpp
Created on  : 16.01.2025
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

    int greatest_common_divisor(int a, int b)
    {
        while (b != 0) {
            a = a % b;
            std::swap(a, b);
        }
        return a;
    }

    int lcm(const int a, const int b)
    {
        const int gcd = greatest_common_divisor(a, b);
        return gcd ? (a * b / gcd) : 0;
    }

}

void ArraysAlgorithms::Least_Common_Multiple()
{
    const int a = 128, b = 40;
    std::cout << lcm(a, b) << std::endl;
}