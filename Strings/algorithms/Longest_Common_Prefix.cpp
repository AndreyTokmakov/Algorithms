/**============================================================================
Name        : Longest_Common_Prefix.cpp
Created on  : 10.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:  Input: ["flower","flow","flight"] Output: "fl"
Example 2:  Input: ["dog","racecar","car"] Output: ""
            Explanation: There is no common prefix among the input strings. Note:
All given inputs are in lowercase letters a-z.
**/
namespace
{
    using namespace StringAlgorithms;

    std::string longest_common_prefix(const std::vector<std::string>& strings)
    {
        int idx = 0;
        while (true) {
            for (const std::string& s : strings) {
                if (s.size() == idx || strings.front()[idx] != s[idx]) {
                    return strings.front().substr(0, idx);
                }
            }
            ++idx;
        }
        return strings.front();
    }

}

void StringAlgorithms::Longest_Common_Prefix()
{
    using TestData = std::vector<std::pair<std::vector<std::string>, std::string>>;
    for (const auto& [values, expected]:  TestData{
        { {"flower","flow","flight"} , "fl" },
        { {"dog","racecar","car"} , "" },
        { {"aaa","aaa","aaa"} , "aaa" },
        { {"1234567","12356789","12345690"} , "123" },
    })
    {
        if (const auto actual = longest_common_prefix(values); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";

}