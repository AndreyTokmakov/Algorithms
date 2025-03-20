/**============================================================================
Name        : Longest_Fibonacci_Sub_Sequence.cpp
Created on  : 19.03.2025
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

    void longest_fibonacci_sub_sequence(const std::vector<int>& values)
    {
        std::unordered_map<int, int> map;
        for (int value: values)
        {
            //if (map.contains())
        }
    }
}

void ArraysAlgorithms::Longest_Fibonacci_Sub_Sequence()
{
    using TestData = std::vector<std::pair<std::vector<int>, int>>;
    for (const auto& [values, expected]:  TestData {
            { {1,11,12} , 5 },
    })
    {
        /*
        const auto actual = TEST_FUNCTION(values);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        */
    }
    std::cout << "OK: All tests passed\n";
}