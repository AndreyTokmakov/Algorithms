/**============================================================================
Name        : Is_Power_Of2.cpp
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

    bool is_power_of_two(int num) {
        return num && !(num & (num - 1));
    }
}

void ArraysAlgorithms::Is_Power_Of2()
{
    for (const int32_t value: {8, 64, 61}) {
        std::cout << value << " -> " << std::boolalpha << is_power_of_two(value) << std::endl;
    }
}
