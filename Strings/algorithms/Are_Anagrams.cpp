/**============================================================================
Name        : Are_Anagrams.cpp
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

    // Same as isPermutation
    bool _are_anagrams(const std::string& str1, const std::string& str2)
    {
        if (str1.length() != str2.length())
            return false;

        int chars[256] = { 0 };
        for (const char c : str1)
            chars[c]++;
        for (const char c : str2)
            if (1 > chars[c]--)
                return false;
        return true;
    }

    bool are_anagrams_contains_only_lowercase(const std::string& str1, const std::string& str2)
    {
        if (str1.length() != str2.length())
            return false;

        std::array<int, 32> chars { 0 };
        for (const char c : str1)
            chars[c - 'a']++;
        for (const char c : str2)
            if (1 > chars[c - 'a']--)
                return false;
        return true;
    }
}

void StringAlgorithms::Are_Anagrams()
{
    std::vector<std::pair<std::pair<std::string, std::string> , bool>> testData {
                    {{"triangle", "integral"}, true},
                    {{"listen", "silent"}, true},
                    {{"acbdd", "aabc"}, false},
            };

    for (const auto& [data, expected]: testData)
    {
        const bool actual1 = _are_anagrams(data.first, data.second);
        const bool actual2 = are_anagrams_contains_only_lowercase(data.first, data.second);

        std::cout << "Is '" << data.first << "' and '" << data.second << "' anagrams: "
                  << std::boolalpha << actual1 << " ,  " << actual2
                  << ". expected = " << std::boolalpha << expected << std::endl;

        if (actual1 != expected || actual2 != expected) {
            std::cerr << actual1 << " != " << expected << " or " << actual2 << " != " << expected << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}