/**============================================================================
Name        : Find_First_K_Chars_Encountered_Once.cpp
Created on  : 14.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

#include <iostream>

namespace
{
    using namespace StringAlgorithms;

    void find_first_K_chars_encountered_once(const std::string& str, int K)
    {

        int chars[256] = { 0 };
        for (const auto c : str)
            chars[c]++;
        for (const auto c : str) {
            if (1 == chars[c]) {
                std::cout << c << ::std::endl;
                if (0 == --K)
                    break;
            }
        }
    }

}

void StringAlgorithms::Find_First_K_Chars_Encountered_Once()
{
    find_first_K_chars_encountered_once("AZBCDBAGHCHFAC", 2);
}