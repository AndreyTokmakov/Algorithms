/**============================================================================
Name        : Find_Duplicate_Symbols.cpp
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

    void find_duplicate_symbols(const std::string& text)
    {
        for (uint8_t chars[256] = {}; const auto c : text) {
            if (1 == chars[c]++) {
                std::cout << c << ' ';
            }
        }
        std::cout << std::endl;
    }
}

void StringAlgorithms::Find_Duplicate_Symbols()
{
    find_duplicate_symbols("1234567829dabcdfGGGd");
}