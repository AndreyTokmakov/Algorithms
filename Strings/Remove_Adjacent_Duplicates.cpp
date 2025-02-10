/**============================================================================
Name        : Remove_Adjacent_Duplicates.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "common.h"
#include "StringAlgorithms.h"

#include <string>
#include <iostream>

/**
Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters,
and removing them.
We repeatedly make duplicate removals on S until we no longer can.
Return the final string after all such duplicate removals have been made. guaranteed the answer is unique.

Example 1:
    Input: "abbaca"
    Output: "ca"

**/

namespace StringAlgorithms
{
    void remove_adjacent_duplicates(std::string& str)
    {
        for (int idx = 0; idx < str.size();)
        {
            for (idx = 1; idx < str.size(); ++idx)
            {
                if (str[idx -1] == str[idx]) {
                    str.erase(idx - 1, 2);
                    break;
                }
            }
        }
    }

     std::string remove_adjacent_duplicates_2(const std::string& str)
    {
        std::string result;
        std::for_each(str.cbegin(), str.cend(), [&result](const char ch) {
            if (result.empty() || result.back() != ch) {
                result.push_back(ch);
            } else {
                result.pop_back();
            }
        });
        return result;
    }
}

void StringAlgorithms::Remove_Adjacent_Duplicates()
{
    std::cout << "Test first solution: " << std::endl;
    for (auto & [input, expected]: std::vector<StringPair> {
            {"abbaca", "ca"},
            {"abccccb", "a"},
    }) {
        if (remove_adjacent_duplicates(input); input != expected) {
            std::cerr << input << " != " << expected << std::endl;
            return;
        }
    }

    std::cout << "Test second solution: " << std::endl;
    for (const auto & [input, expected]: std::vector<StringPair> {
            {"abbaca", "ca"},
            {"abccccb", "a"},
    }) {
        if (std::string result = remove_adjacent_duplicates_2(input); result != expected) {
            std::cerr << result << " != " << expected << std::endl;
            return;
        }
    }
}