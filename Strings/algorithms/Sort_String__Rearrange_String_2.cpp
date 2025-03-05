/**============================================================================
Name        : Sort_String__Rearrange_String_2.cpp
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

    void rearrange_string_based_on_case(std::string &text)
    {
        int chars[256]{0};
        for (char c: text)
            chars[(int8_t) (c)]++;

        size_t pos = 0, caseOffset = (int) 'a' - (int) 'A';
        for (size_t i = 'A'; i <= 'z'; i++) { // 'A' (65) ...'Z' (90) .. 'a' (97) .. 'z' (122)
            while (chars[i + caseOffset]) {
                text[pos++] = (char) (i + caseOffset);
                chars[i + caseOffset]--;
            }
            while (chars[i]) {
                text[pos++] = (char) i;
                chars[i]--;
            }
        }
    }
}

void StringAlgorithms::Sort_String__Rearrange_String_2()
{
    using TestData = std::vector<std::pair<std::string, std::string>>;
    for (const auto& [str, expected]:  TestData {
            { "DaCbcdE" , "abcCdDE" },
            { "abcdDCBA" , "aAbBcCdD" },
    })
    {
        std::string actual {str};
        rearrange_string_based_on_case(actual);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
