/**============================================================================
Name        : Move_Zeros_To_End.cpp
Created on  : 14.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**

**/

namespace
{
    using namespace StringAlgorithms;

    void _move_zeros_to_end(std::string &str)
    {
        size_t pos = 0;
        for (size_t i = 0; i < str.length(); i++)
            if ('0' != str[i])
                str[pos++] = str[i];
        for (size_t i = pos; i < str.length(); i++)
            str[i] = '0';
    }

    void _move_zeros_to_end_EX(std::string &str)
    {
        for (size_t pos = 0; char &c: str)
            if ('0' != c)
                std::swap(str[pos++], c);
    }
}

void StringAlgorithms::Move_Zeros_To_End()
{
    for (const std::string &testStr: {"1001"}) {
        {
            auto s{testStr};
            _move_zeros_to_end(s);
            std::cout << testStr << " --> " << s << '\n';
        }
        {
            auto s{testStr};
            _move_zeros_to_end_EX(s);
            std::cout << testStr << " --> " << s << '\n';
        }
    }
}