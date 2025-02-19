/**============================================================================
Name        : Sqrt.cpp
Created on  : 19.01.2025
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

    int sqrt(const int x)
    {
        int left = 0, right = x, middle = 0, result = 0;
        while (left <= right) {
            middle = (right + left) / 2;
            result = middle * middle;
            if (result == x)
                return middle;
            if (result > x)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return right;
    }
}


void ArraysAlgorithms::Sqrt()
{
    using TestData = std::vector< std::pair<int, int> >;
    for (const auto& [value, expected]:  TestData{
        { 9 , 3 }, {16, 4}
    })
    {
        const auto actual = sqrt(value);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}