/**============================================================================
Name        : Is_String_Has_Only_Unique_Characters.cpp
Created on  : 12.03.2025
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

    bool is_unique_chars_only(const std::string& str)
    {
        for (uint32_t mask { 0 }; const char ch : str) {
            const int bit = ch - 'a';
            if (mask >> bit & 1) {
                return false;
            }
            mask |= 1 << bit;
        }
        return true;
    }
}

void StringAlgorithms::Is_String_Has_Only_Unique_Characters()
{
    using TestData = std::vector< std::pair<std::string, bool>>;
    for (const auto& [values, expected]:  TestData {
        { "leetcode" , false },
        { "abcde" , true },
        { "" , true },
        { "aba" , false },
    })
    {
        if (const auto actual = is_unique_chars_only(values); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}