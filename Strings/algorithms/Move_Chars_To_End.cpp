/**============================================================================
Name        : Move_Chars_To_End.cpp
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

    void _moveAtEnd1(std::string str,
                     unsigned int i,
                     unsigned int l,
                     const char char_to_move = 'x') {
        if (i >= l)
            return;

        char curr = str[i];
        if (curr != char_to_move)
            std::cout << curr;
        _moveAtEnd1(str, i + 1, l, char_to_move);
        if (curr == char_to_move)
            std::cout << curr;
    }

    void _moveAtEnd2(const std::string &str, const char char_to_move = 'x') {
        int count = str.length();
        for (auto c: str) {
            if (char_to_move != c) {
                count--;
                std::cout << c;
            }
        }
        while (count--)
            std::cout << 'x';
        std::cout << std::endl;
    }

    void _moveAtEnd3_GOOD(const std::string &str, const char char_to_move = 'x') {
        std::string strLocal{str};
        for (size_t pos = 0; char &c: strLocal)
            if (char_to_move != c)
                std::swap(strLocal[pos++], c);
        std::cout << strLocal << std::endl;
    }

}

void StringAlgorithms::Move_Chars_To_End()
{
    for (const std::string &testStr: {"geekxsforgexxeksxx"}) {
        std::string text{testStr};
        _moveAtEnd1(text, 0, text.length(), 'x');
        std::cout << std::endl;
        _moveAtEnd2(text, 'x');
        _moveAtEnd3_GOOD(text, 'x');
    }
}