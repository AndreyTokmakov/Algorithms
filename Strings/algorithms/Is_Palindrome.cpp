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

    bool is_palindrome_1(const std::string &str)
    {
        return std::equal(str.begin(),
                          str.begin() + std::ssize(str) / 2,
                          str.rbegin());
    }

    bool is_palindrome_2(const std::string &string1)
    {
        return std::equal(string1.begin(), string1.end(), string1.rbegin());
    }

    bool is_palindrome_3(const std::string &word)
    {
        for (size_t index = 0; index < word.size() / 2; index++) {
            if (tolower(word.at(index)) != tolower(word.at(word.size() - index - 1)))
                return false;
        }
        return true;
    }

    bool is_palindrome_two_pointers(const std::string &word)
    {
        for (uint32_t left = 0, right = word.size() - 1; right >= left; ) {
            if (word[left++] != word[right--]) {
                return false;
            }
        }
        return true;
    }
}

void StringAlgorithms::Is_Palindrome()
{
    using TestData = std::vector<std::pair<std::string, bool>>;
    for (const auto& [values, expected]:  TestData{
            { {"deleveled"} , true },
            { {"malayalam"} , true },
            { {"bsab"} , false },
            { {"bab"} , true },
            { {"balam"} , false },
    })
    {
        if (const auto actual = is_palindrome_1(values);expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = is_palindrome_2(values);expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = is_palindrome_3(values);expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = is_palindrome_two_pointers(values);expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}