
/**============================================================================
Name        : Find_Smallest_Without_Compare.cpp
Created on  : 23.02.2025
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

    template<typename T>
    T find_smallest(T x, T y, T z)
    {
        T smallest = 0;
        while (x && y && z) {
            x--;
            y--;
            z--;
            smallest++;
        }
        return smallest;
    }
}

void ArraysAlgorithms::Find_Smallest_Without_Compare()
{
    int smallest = find_smallest(7, 9, 12);
    std::cout << "Smallest = " << smallest << std::endl;
}
