/**============================================================================
Name        : Roman_To_Int.cpp
Created on  : 20.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"


namespace
{
    using namespace StringAlgorithms;

    using namespace std::string_view_literals;

    int roman_to_int(const std::string& str)
    {
        int result = 0;
        for (size_t idx = 0, size = str.size(); idx < str.size(); ++idx)
        {
            const char c = str[idx];
            if ('M' == c)      result += 1000;
            else if ('D' == c) result += 500;
            else if ('C' == c) {
                if (size > idx && str[idx + 1] == 'D') {
                    result += 400;
                    ++idx;
                } else if (size > idx && str[idx + 1] == 'M') {
                    result += 900;
                    ++idx;
                } else {
                    result += 100;
                }
            }
            else if ('L' == c) result += 50;
            else if ('X' == c) {
                if (size > idx && str[idx + 1] == 'L') {
                    result += 40;
                    ++idx;
                } else if (size > idx && str[idx + 1] == 'C') {
                    result += 90;
                    ++idx;
                } else {
                    result += 10;
                }
            }
            else if ('V' == c) result += 5;
            else if ('I' == c) {
                if (size > idx && str[idx + 1] == 'V') {
                    result += 4;
                    ++idx;
                } else if (size > idx && str[idx + 1] == 'X') {
                    result += 9;
                    ++idx;
                } else {
                    result += 1;
                }
            }
        }
        return result;
    }
}

void StringAlgorithms::Roman_To_Int()
{
    for (const auto  &[roman_num_str, expected]: std::vector<std::pair<std::string, int>> {
            { "LVIII", 58},
            { "MCMXCIV", 1994}
    })
    {
        const int actual = roman_to_int(roman_num_str);
        // std::cout << actual << std::endl;
        if (expected != actual) {
            std::cerr << expected << " != " << actual << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}