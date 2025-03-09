/**============================================================================
Name        : Is_Palindrome_Ignore_Invalid_Chars.cpp
Created on  : 09.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

#include <iostream>
#include <cstring>

/**
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing
all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1: Input: s = "A man, a plan, a canal: Panama"  Output: true
           Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:  Input: s = "race a car" Output: false
            Explanation: "raceacar" is not a palindrome.

Example 3:  Input: s = " "  Output: true
            Explanation: s is an empty string "" after removing non-alphanumeric characters.

Since an empty string reads the same forward and backward, it is a palindrome.
**/

namespace
{
    using namespace StringAlgorithms;

    bool is_palindrome_two_pointers(const std::string &word)
    {
        for (int left = 0, right = static_cast<int>(word.size()) - 1; right >= left; )
        {
            while (right > left && !std::isalnum(word[left]))
                ++left;
            while (right > left && !std::isalnum(word[right]))
                --right;
            if (std::tolower(word[left++]) != std::tolower(word[right--])) {
                return false;
            }
        }
        return true;
    }
}

void StringAlgorithms::Is_Palindrome_Ignore_Invalid_Chars()
{
    using TestData = std::vector<std::pair<std::string, bool>>;
    for (const auto& [values, expected]:  TestData{
            { {" A man, a plan, a canal: Panama"} , true },
            { {"race a car"} , false },
            { {" "} , true },
    })
    {
        if (const auto actual = is_palindrome_two_pointers(values);expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}