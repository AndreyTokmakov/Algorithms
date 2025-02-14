/**============================================================================
Name        : Check_If_Two_Strings_Are_Permutation.cpp
Created on  : 14.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
// Write a function to check whether two given strings are Permutation of each other or not.
// A Permutation of a string is another string that contains same characters, only the order
// of characters can be different. For example, �abcd� and �dabc� are Permutation of each other.
**/

namespace
{
    using namespace StringAlgorithms;

    bool _are_permutation(const std::string& str1, const std::string& str2)
    {
        if (str1.length() != str2.length())
            return false;

        int32_t chars[256] = { 0 };
        for (const char c : str1)
            chars[c]++;
        for (const char c : str2)
            if (0 > --chars[c])
                return false;
        return true;
    }
}

void StringAlgorithms::Check_If_Two_Strings_Are_Permutation()
{
    std::vector<std::pair<std::pair<std::string, std::string> , bool>> testData {
                    {{"test", "estt"}, true},
                    {{"ABBAACCDDD", "BACDBACDAD"}, true},
                    {{"ABCDDDDBA", "ABCCDDDBA"}, false},
                    {{"abcd", "bbbb"}, false},
            };

    for (const auto& [data, expected]: testData)
    {
        std::cout << std::boolalpha << _are_permutation(data.first, data.second)
                  << ", expected = " << std::boolalpha << expected << std::endl;
    }
}
