/**============================================================================
Name        : Is_String_Contains_Another_String.cpp
Created on  : 23.02.2025
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

    bool contains(const std::string& text,
                  const std::string& str)
    {
        for (int idx = 0, m = 0, n= 0; idx <= std::ssize(text) - std::ssize(str); ++idx)
        {
            for (m = 0, n = idx; m < str.size(); ++m, ++n) {
                if (str[m] != text[n])
                    break;
            }
            if (m == str.size())
                return true;
        }
        return false;
    }

    int find(const std::string& haystack,
             const std::string& needle)
    {
        const int textSize = std::ssize(haystack), searchBlockSize = std::ssize(needle);
        for (int idx = 0, m = 0, n = 0; idx <= textSize - searchBlockSize; ++idx)
        {
            for (m = 0, n = idx; m < searchBlockSize; ++m, ++n) {
                if (needle[m] != haystack[n])
                    break;
            }
            if (m == searchBlockSize)
                return idx;
        }
        return -1;
    }
}

void StringAlgorithms::Is_String_Contains_Another_String()
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
                  << contains(values.first, values.second) << " | "
                  << find(values.first, values.second) << " | expected = " << expected
                  << std::endl;
    }
}