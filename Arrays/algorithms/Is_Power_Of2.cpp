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

    bool is_power_of_two(const int num) {
        return num && !(num & (num - 1));
    }
}

void ArraysAlgorithms::Is_Power_Of2()
{
    using TestData = std::vector< std::pair<int, bool> >;
    for (const auto& [value, expected]:  TestData{
        { 8 , true }, {64, true}, { 61, false}
    })
    {
        const auto actual = is_power_of_two(value);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
