/**============================================================================
Name        : Sum_Strings_As_Binary_Masks.cpp
Created on  : 10.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
Given two binary strings a and b, return their sum as a binary string.

Example 1: Input: a = "11",   b = "1"    Output: "100"
Example 2: Input: a = "1010", b = "1011" Output: "10101"

**/
namespace
{
    using namespace StringAlgorithms;

    void set_bit(int& num, const uint32_t bit) {
        num |= (1 << (bit - 1));
    }

    std::string sum_binary_string(const std::string& first,
                                  const std::string& second)
    {
        int32_t a = 0, b = 0;
        for (int bit = 1, idx = first.size() - 1; idx >= 0; ++bit, --idx) {
            if ('1' == first[idx])
                a |= (1 << (bit - 1));
        }
        for (int bit = 1, idx = second.size() - 1; idx >= 0; ++bit, --idx) {
            if ('1' == second[idx])
                b |= (1 << (bit - 1));
        }

        const int32_t c = a + b;
        std::string result;
        bool isSet { false };
        for (int i = 32 - 1, bits_set = 0; i >= 0; i--)
        {
            isSet = (c & (1u << i));
            bits_set += isSet;
            if (bits_set > 0) {
                result.append(1, (isSet ? '1' : '0'));
            }
        }
        return result.empty() ? "0" : result; ;
    }

}

// FIXME: No completed - Fails in case if input string. size() > 32
void StringAlgorithms::Sum_Strings_As_Binary_Masks()
{
    using TestData = std::vector< std::pair<std::pair<std::string, std::string>, std::string>>;
    for (const auto& [values, expected]:  TestData{
        { {"11", "1"} , "100" },
        { {"1010", "1011"} , "10101" },
        { {"0", "0"} , "0" },
        { {"1110001", "110100100"} , "1000010101" },
    })
    {
        if (const auto actual = sum_binary_string(values.first, values.second); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
