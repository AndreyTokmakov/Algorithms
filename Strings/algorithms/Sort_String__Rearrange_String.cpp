/**============================================================================
Name        : Sort_String__Rearrange_String.cpp
Created on  : 05.03.2025
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

    void rearrange_string(std::string &text)
    {
        uint32_t chars[256]{0};
        for (char c: text)
            chars[(int8_t) (c)]++;

        for (size_t i = 0, pos = 0; i < 256; ++i) {
            while (chars[i]--) {
                text[pos++] = (char) i;
            }
        }
    }

    void rearrange_string_2(std::string &text)
    {
        int chars[256]{0};
        for (char c: text)
            chars[(int8_t) (c)]++;

        for (int i = 0, pos = 0; i < 256; ++i) {
            std::fill_n(text.begin() + pos, chars[i], (char) i);
            pos += chars[i];
        }
    }
}

void StringAlgorithms::Sort_String__Rearrange_String()
{
    using TestData = std::vector<std::pair<std::string, std::string>>;
    for (const auto& [str, expected]:  TestData {
            { "lgooglaabbaae" , "aaaabbegglloo" },
            { "geeksforgeeks" , "eeeefggkkorss" },
            { "cccccddddaeea" , "aacccccddddee" },
    })
    {
        {
            std::string actual {str};
            rearrange_string(actual);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        {
            std::string actual {str};
            rearrange_string_2(actual);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
    }
    std::cout << "OK: All tests passed\n";
}
