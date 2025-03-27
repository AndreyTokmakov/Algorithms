/**============================================================================
Name        : Minimum_Substring_of_Other_String_Chars.cpp
Created on  : 27.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such
that every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".

Example 1:  Input: s = "ADOBECODEBANC", t = "ABC"  Output: "BANC"
            Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:  Input: s = "a", t = "a", Output: "a"
            Explanation: The entire string s is the minimum window.

Example 3:  Input: s = "a", t = "aa", Output: ""
            Explanation: Both 'a's from t must be included in the window.

Since the largest window of s only has one 'a', return empty string.
*/

namespace
{
    using namespace StringAlgorithms;

    void minimum_substring_of_other_string_chars(const std::string& str,
                                                 const std::string& mask)
    {
        const int size = static_cast<int>(str.size()), maskSize = static_cast<int>(mask.size());
        int need[256] {};
        for (const char c : mask)
            ++need[static_cast<uint32_t>(c)];

        int right = 0;

        /** Skip leading chars from 'str' which are not part of 'mask' **/
        while (0 == need[static_cast<int32_t>(str[right])  ]) {
            ++right;
        }

        int window[256] {}, minLen = std::numeric_limits<int>::max();
        for (int left = right, needCount = 0, errors = 0; right < size; ++right)
        {
            ++window[str[right]];
            char ch = str[right];
            if (need[ch] &&  window[ch] == need[ch]) {
                ++needCount;
            }
            else if (need[ch] && window[ch] > need[ch]) {
                ++errors;
            }

            while (errors)
            {
                ch = str[left];
                if (need[ch] && window[ch] == need[ch]) {
                    --needCount;
                }
                else if (need[ch] && window[ch] > need[ch]) {
                    --errors;
                }
                --window[ch];
                ++left;
            }


            std::cout << " left : " << left  << " | " << str[left]
                      << " right : " << right << " | " << str[right] << std::endl;

            /*
            fromMask = need[str[left]];
            while (window[str[left]] > need[str[left]])
            {
                std::cout << "\t\twindow[" << str[left] << "](" << left << " = " <<  (char)str[left]
                    << ") > need[" << str[right] << "](" << right << " = " << str[right] << ")" << std::endl;
                --window[str[++left]];
                --len;
            }
            std::cout
                << " left : " << left  << " | " << str[left]
                << " right: " << right << " | " << str[right];

            fromMask = need[str[right]];
            // window[str[left]] == need[str[right]]
            if (fromMask)
            {
                ++needCount;
                if (needCount == maskSize)
                {
                    std::cout << " | Store length: " << len << "  ";
                }
            }
            */
        }
    }
}

void StringAlgorithms::Minimum_Substring_of_Other_String_Chars()
{
    using TestData = std::vector<std::pair<std::pair<std::string, std::string>, int>>;
    for (const auto& [values, expected]:  TestData {
        { {"gggAfffBCgggABCgg", "ABC"} , 1 },
        // { {"ADOBECODEBANC", "ABC"} , 1 },
    })
    {
        minimum_substring_of_other_string_chars(values.first, values.second);


        /*
        const auto actual = TEST_FUNCTION(values);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        */
    }
    std::cout << "OK: All tests passed\n";
}