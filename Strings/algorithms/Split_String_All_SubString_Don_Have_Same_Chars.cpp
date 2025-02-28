/**============================================================================
Name        : Split_String_All_SubString_Don_Have_Same_Chars.cpp
Created on  : 28.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/// given a string, it needs to be split into the maximum number of substrings so that all the strings contain
/// only unique characters - there should be no substrings so that strings str1 and str2 contain the same character - for example 'a'
/// abad -> [aba, d]
/// abc -> [a, b , c]

namespace
{
    using namespace StringAlgorithms;


    std::vector<std::string> split(const std::string& str)
    {
        std::vector<std::string> result(1);

        uint16_t table[256] {};
        for (const char c: str)
            ++table[c];

        int waitCount = 0;
        uint16_t wait[256] {};
        for (char c: str)
        {
            if (!wait[c]) {
                wait[c] = table[c];
                waitCount += wait[c];
            }

            --table[c];
            if (table[c] == wait[c] - 1) {
                --waitCount;
                --wait[c];
            }

            result.back().push_back(c);
            if (!waitCount)
                result.emplace_back();
        }

        result.pop_back();
        return result;
    }
}

void StringAlgorithms::Split_String_All_SubString_Don_Have_Same_Chars()
{
    // std::vector<std::string> string = split("abcbd");
    // std::vector<std::string> string = split("abc");
    // std::vector<std::string> string = split("aba");
    // std::vector<std::string> string = split("abad");
    std::vector<std::string> string = split("abcabcddeezez");

    for (const std::string& s: string)
        std::cout << s << std::endl;
}
