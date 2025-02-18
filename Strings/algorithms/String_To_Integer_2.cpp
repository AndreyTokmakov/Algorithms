/**============================================================================
Name        : String_To_Integer.cpp
Created on  : 18.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include <iomanip>
#include "../common.h"
#include "../StringAlgorithms.h"


/**
Read in and ignore any leading whitespace.

Check if the next character (if not already at the end of the string) is '-' or '+'.
Read this character in if it is either. This determines if the final result is negative or positive respectively.
Assume the result is positive if neither is present.777777
**/

namespace
{
    using namespace StringAlgorithms;

    int32_t _atoi_ex(std::string_view str)
    {
        int32_t number {0}, size = str.size(), idx = 0, sign = 0;
        for (idx = 0; idx < size && sign == 0; ++idx) {
            if (str[idx] == ' ') {}
            else if (str[idx] == '+') sign = 1;
            else if (str[idx] == '-') sign = -1;
            else break;
        }

        while (size > idx && str[idx] >= '0' && str[idx] <= '9')
            number = number * 10 + (str[idx++]  - '0');
        return number * (sign ? sign : 1);
    }

    constexpr int parseInt(std::string_view str)
    {
        const size_t start = str.find_first_not_of(' ');
        if (start == std::string_view::npos)
            return 0;

        int sign = 1;
        size_t index = start;

        if (str[start] == '-' || str[start] == '+') {
            sign = (str[start] == '-') ? -1 : 1;
            ++index;
        }

        int val = 0;
        for (; index < str.size(); ++index) {
            char ch = str[index];
            if (ch < '0' || ch > '9') {
                break;
            }
            val = val * 10 + (ch - '0');
        }

        return sign * val;
    }
}

void StringAlgorithms::String_To_Integer_2()
{
    for (const auto& str: {
            "123", "1203", "931aa", "00123","  -123 hh","  -+123 hh", "42", "-91283472332"
    }) {
        std::cout << std::left << std::setfill(' ') << std::setw(14) << std::quoted(str)
                  << " -> " << _atoi_ex(str) << "    " << parseInt(str) <<  std::endl;
    }
}