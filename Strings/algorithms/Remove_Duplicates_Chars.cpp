/**============================================================================
Name        : Remove_Duplicates_Chars.cpp
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

    void _removeDuplicates(std::string &text)
    {
        char tmp[256] = {0};
        size_t u_index = 0;
        for (size_t pos = 0; pos < text.length(); pos++) {
            if (1 == tmp[text[pos]]) {
                continue;
            } else if (u_index != pos) {
                text[u_index] = text[pos];
            }
            tmp[text[pos]] = 1;
            u_index++;
        }
        text.resize(u_index);
    }

    void _removeDuplicates2(std::string &text)
    {
        char tmp[256] = {0};
        size_t index = 0;
        for (char c: text) {
            if (0 == tmp[c]++)
                text[index++] = c;
        }
        text.resize(index);
    }

    void _removeDuplicates3(std::string &text)
    {
        size_t index = 0;
        for (char tmp[256]{0}; char c : text)
            if (0 == tmp[c]++)
                text[index++] = c;
        text.resize(index);
    }
}

void StringAlgorithms::Remove_Duplicates_Chars()
{
    for (const std::string &str: {"aaaaabbbbbb", "abcabcabcabcabc"}) {
        {
            std::string s{str};
            std::cout << s << " --> ";
            _removeDuplicates(s);
            std::cout << s << '\n';
        }
        {
            std::string s{str};
            std::cout << s << " --> ";
            _removeDuplicates2(s);
            std::cout << s << '\n';
        }
        {
            std::string s{str};
            std::cout << s << " --> ";
            _removeDuplicates3(s);
            std::cout << s << '\n';
        }
    }
}
