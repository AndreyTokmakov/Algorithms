/**============================================================================
Name        : Divide_Without_Division_Operator.cpp
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

    int divide(int a, const int b)
    {
        int count = 0;
        while (a >= b) {
            a -= b;
            count++;
        }
        return count;
    }

    int divide1(const int a, const int b)
    {
        int count = 0, result = b;
        while (a > result) {
            result += b;
            count++;
        }
        return count;
    }
}

void ArraysAlgorithms::Divide_Without_Division_Operator()
{
    {
        int a = 15, b = 2;
        std::cout << a << "/" << b << " = " << divide(a, b) << std::endl;
        std::cout << a << "/" << b << " = " << divide1(a, b) << std::endl;
    }
    {
        int a = 1511, b = 22;
        std::cout << a << "/" << b << " = " << divide(a, b) << std::endl;
        std::cout << a << "/" << b << " = " << divide1(a, b) << std::endl;
    }
}
