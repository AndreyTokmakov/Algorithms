/**============================================================================
Name        : Find_If_String_IsSubstring_OfAnother.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

#include <string>
#include <iostream>

/**

**/

namespace
{
    bool is_substring(const std::string& text, const std::string& str)
    {
        for (size_t i = 0, len = text.length() - str.length(); i <= len; ++i) {
            if (text[i] == str[0]) {
                size_t k = i, n = 0;
                while (text[k++] == str[n++]) {
                    if (n == str.length())
                        return true;
                }
            }
        }
        return false;
    }

    bool is_substring_ex(const std::string& text, const std::string& str)
    {
        const size_t textLength = text.length(), strLen = str.length();
        for (size_t idx = 0, n = 0; idx <= textLength - strLen; ++idx) {
            for (n = 0; n < strLen && text[n + idx] == str[n]; ++n) { /** **/ }
            if (strLen == n)
                return true;
        }
        return false;
    }
}

void StringAlgorithms::Find_If_String_IsSubstring_OfAnother()
{
    std::vector<std::pair<std::pair<std::string, std::string>, bool>> testData {
            { {"qw34er333345tyui34op", "345"}, true },
            { {"1234512345", "123"}, true },
            { {"1234512345", "3456"}, false },
            { {"123456789", "789"}, true },
    };

    for (const auto& [values, expected]: testData)
    {
        std::cout << "Is '" << values.first << "' is substring of '" << values.second << "' = "
                  << std::boolalpha
                  << is_substring(values.first, values.second) << " | "
                  << is_substring_ex(values.first, values.second) << " | expected = " << expected
                  << std::endl;
    }
}