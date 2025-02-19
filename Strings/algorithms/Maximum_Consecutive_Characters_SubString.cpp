/**============================================================================
Name        : Maximum_Consecutive_Characters_SubString.cpp
Created on  : 19.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.
Return the power of the string.
Example 1: Input: s = "leetcode"  Output: 2
           Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2: Input: s = "abbcccddddeeeeedcba" Output: 5
           Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
Example 3: Input: s = "triplepillooooow" Output: 5
Example 4: Input: s = "hooraaaaaaaaaaay" Output: 11
Example 5: Input: s = "tourist" Output: 1
**/
namespace
{
    using namespace StringAlgorithms;

    int longest_consecutive_chars_sub_string_1(const std::string &text)
    {
        char c{};
        size_t max_len = 1;
        for (size_t idx = 1, len = 1; idx < text.length(); ++idx) {
            if (text[idx - 1] != text[idx]) {
                len = 1;
            } else {
                if (++len > max_len) {
                    max_len = len;
                    c = text[idx];
                }
            }
        }
        return max_len;
    }

    int longest_consecutive_chars_sub_string_2(const std::string &text)
    {
        int max_len = 0;
        char prev = text.back();
        for (int len = 0; const char c: text) {
            len = (c == prev) ? len + 1 : 1;
            max_len = std::max(len, max_len);
            prev = c;
        }
        return max_len;
    }
}

void StringAlgorithms::Maximum_Consecutive_Characters_SubString()
{
    using TestData = std::vector< std::pair<std::string, int>>;
    for (const auto& [value, expected]:  TestData {
        { "aabbbbbcccc" , 5 },
        { "leetcode" , 2 },
        { "abbcccddddeeeeedcba" , 5 },
        { "triplepillooooow" , 5 },
        { "hooraaaaaaaaaaay" , 11 },
        { "tourist" , 1 },
    })
    {
        {
            const auto actual = longest_consecutive_chars_sub_string_1(value);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        {
            const auto actual = longest_consecutive_chars_sub_string_2(value);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
    }
    std::cout << "OK: All tests passed\n";
}
