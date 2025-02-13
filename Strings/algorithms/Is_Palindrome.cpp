/**============================================================================
Name        : Is_Palindrome.cpp
Created on  : 14.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

#include <iostream>
#include <cstring>

namespace
{
    using namespace StringAlgorithms;

    bool _is_palindrome_1(const std::string &str)
    {
        return std::equal(str.begin(),
                          str.begin() + std::ssize(str) / 2,
                          str.rbegin());
    }

    bool _is_palindrome_2(const std::string &string1)
    {
        return std::equal(string1.begin(), string1.end(), string1.rbegin());
    }

    bool _is_palindrome_3(const std::string &word)
    {
        for (size_t index = 0; index < word.size() / 2; index++) {
            if (tolower(word.at(index)) != tolower(word.at(word.size() - index - 1)))
                return false;
        }
        return true;
    }
}

void StringAlgorithms::Is_Palindrome()
{
    for (const auto &str: {"deleveled", "malayalam", "bab", "balam"}) {
        std::cout << str << ": " << std::boolalpha << _is_palindrome_1(str)
                  << " " << _is_palindrome_2(str)
                  << " " << _is_palindrome_3(str) << std::endl;
    }
}