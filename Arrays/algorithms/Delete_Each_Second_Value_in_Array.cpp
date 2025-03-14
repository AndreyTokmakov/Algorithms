/**============================================================================
Name        : Delete_Each_Second_Value_in_Array.cpp.cpp
Created on  : 14.03.2025
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

    void delete_each_second_value_in_array(std::vector<int>& values)
    {
        int pos = 0;
        for (int idx = 0, size = values.size(); idx < size; idx += 2) {
            values[pos++] = values[idx];
        }
        values.resize(pos);
        values.shrink_to_fit();
    }
}

void ArraysAlgorithms::Delete_Each_Second_Value_in_Array()
{
    using TestData = std::vector< std::pair<std::vector<int>, std::vector<int>>>;
    for (const auto& [values, expected]:  TestData{
            { {1,2,3,4,5,6,7,8,9,10} , {1,3,5,7,9} },
    })
    {
        std::vector<int> actual(values);
        delete_each_second_value_in_array(actual);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}