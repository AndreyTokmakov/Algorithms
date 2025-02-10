/**============================================================================
Name        : MidPoint.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


namespace
{
    int midpoint(int a, int b) {
        return a / 2 + b / 2 + static_cast<int>((a & 1) && (b & 1));
    }
}

void ArraysAlgorithms::MidPoint()
{
    for (const auto& [values, expected]: std::vector<std::pair<std::pair<int, int>, int>>{
            {{1,1}, 1}, {{2,2}, 2},
            {{3,5}, 4},
            {{8,5}, 6},

    }) {
        if (const int actual = midpoint(values.first, values.second); expected != actual) {
            std::cerr << expected << " != " << actual << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}