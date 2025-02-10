/**============================================================================
Name        : Show_Bits.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


/**
Reverse bits of a given 32 bits unsigned integer.
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
**/


namespace
{
    template<typename T>
    void show_bits(T x)
    {
        std::cout << x << "  ===>  ";
        for (int i = (sizeof(T) * 8) - 1; i >= 0; --i)
            std::cout << (x & (1u << i) ? '1' : '0');
        std::cout << std::endl;
    }

    uint32_t reverseBits(const uint32_t input)
    {
        uint32_t output = 0;
        for (int i = (sizeof(uint32_t) * 8) - 1, n = 0; i >= 0; --i, ++n)
        {
            if ((input & (1u << i))) {
                output |= (1 << n);
            }
        }
        return output;
    }
}


void ArraysAlgorithms::Reverse_Bits()
{
    const uint32_t val = reverseBits(5);
    show_bits(5);
    show_bits(val);
}