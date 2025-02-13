/**============================================================================
Name        : Remove_Chars_Of_One_String_FromAnother.cpp
Created on  : 14.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

#include <iostream>
#include <cstring>

namespace
{
    using namespace StringAlgorithms;

    void _removeCharsOfOneString_FromAnother(std::string &text, const std::string &mask)
    {
        char dups[256] = {0};
        for (const char c: mask)
            dups[c] = 1;

        size_t index = 0;
        for (char c: text) {
            if (0 == dups[c])
                text[index++] = c;
        }
        text.resize(index);
    }
}

void StringAlgorithms::Remove_Chars_Of_One_String_FromAnother()
{
    std::string text = "AAAAAAABBBBBCCCCCCCDDDDDDDDEEEEEEFFFFFFF";
    const std::string mask = "AF";

    std::cout << text << std::endl;
    _removeCharsOfOneString_FromAnother(text, mask);
    std::cout << text << std::endl;
}