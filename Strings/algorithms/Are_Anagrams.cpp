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

    bool _are_anagrams_faster(const std::string& str1, const std::string& str2)
    {
        if (str1.length() != str2.length())
            return false;

        std::array<int, 32> chars { 0 };
        for (char c : str1)
            chars[c - 'a']++;
        for (char c : str2)
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
        std::cout << "Is '" << data.first << "' and '" << data.second << "' anagrams: "
                  << std::boolalpha << _are_anagrams(data.first, data.second) << "  "
                  << std::boolalpha << _are_anagrams_faster(data.first, data.second)
                  << ", expected = " << std::boolalpha << expected << std::endl;
    }
}
