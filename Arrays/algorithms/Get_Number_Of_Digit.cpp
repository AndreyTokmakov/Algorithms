/**============================================================================
Name        : Get_Number_Of_Digit.cpp
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

    int get_num_of_digits(const int val)
    {
        return val > 10 ? 1 + get_num_of_digits(val / 10) : 1;
    }

    int get_num_of_digits_2(int val) {
        int digits{1};
        while (val > 9) {
            val = val / 10;
            ++digits;
        }
        return digits;
    }

}

void ArraysAlgorithms::Get_Number_Of_Digit()
{
    int val = 123432323;
    std::cout << val << " = " << get_num_of_digits(val) << std::endl;
    std::cout << val << " = " << get_num_of_digits_2(val) << std::endl;
}