/**============================================================================
Name        : Is_Prime.cpp
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

    bool check_is_prime_1(unsigned int value)
    {
        if (1 == value || 2 == value)
            return true;
        if (0 == value % 2 || 0 == value % 3)
            return false;

        for (unsigned int i = 5; i <= value / 2; i += 2) {
            if (0 == value % i)
                return false;
        }
        return true;
    }

    bool check_is_prime_2(int value)
    {
        if (1 == value || 2 == value)
            return true;
        if (0 == value % 2 || 0 == value % 3)
            return false;

        for (int i = 5; (i * i) <= value; i += 2) {
            if (0 == value % i)
                return false;
        }
        return true;
    }

}

void ArraysAlgorithms::Is_Prime()
{
    std::cout << std::boolalpha << check_is_prime_1(127) << std::endl;
    std::cout << std::boolalpha << check_is_prime_2(127) << std::endl;
}
