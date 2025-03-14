/**============================================================================
Name        : Check_If_Strings_Rotate_Rotate_Equals_2.cpp
Created on  : 14.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 (e.g.,"waterbottle" is a rotation of"erbottlewat").
Can you use only one call to the method that checks if one word is a substring of another?

Example 1:  Input: s1 = "waterbottle", s2 = "erbottlewat" Output: True
Example 2:  Input: s1 = "aa", "aba"                       Output: False
**/

namespace
{
    using namespace StringAlgorithms;

    bool is_K_rotate_equals(const std::string &str1,
                            const std::string &str2,
                            size_t K)
    {
        for (size_t pos = 0; pos < str1.size(); pos++, K++)
            if (str2[K % str1.size()] != str1[pos])
                return false;
        return true;
    }

    bool is_rotate_equals(const std::string &str1,
                          const std::string &str2)
    {
        if (str1.size() != str2.size())
            return false;
        for (size_t pos = 0; pos < str1.size(); pos++)
            if (is_K_rotate_equals(str1, str2, pos))
                return true;
        return false;
    }

    bool is_flipped_string(const std::string& str1,
                           const std::string& str2)
    {
        return str1.size() == str2.size() && (str1 + str1).find(str2) != std::string::npos;
    }
}

void StringAlgorithms::Check_If_Strings_Rotate_Rotate_Equals_2()
{
    using TestData = std::vector<std::pair<std::pair<std::string, std::string>, bool>>;
    for (const auto& [values, expected]:  TestData {
        {{"123456789", "789123456"}, true},
        {{"00001",     "01000"}, true},
        {{"waterbottle",     "erbottlewat"}, true},
        {{"aa",     "aba"}, false},
    })
    {
        if (const auto actual = is_rotate_equals(values.first, values.second); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = is_flipped_string(values.first, values.second); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}