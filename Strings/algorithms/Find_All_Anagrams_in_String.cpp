/**============================================================================
Name        : FInd_All_Anagrams_in_String.cpp
Created on  : 16.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include <iomanip>

#include "../common.h"
#include "../StringAlgorithms.h"

/**
Given two strings s and p, return an array of all the start indices of p's anagrams in s.
You may return the answer in any order.

Example 1:  Input: s = "cbaebabacd", p = "abc" Output: [0,6]
            Explanation:  The substring with start index = 0 is "cba", which is an anagram of "abc".
                          The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2: Input: s = "abab", p = "ab" Output: [0,1,2]
            Explanation:  The substring with start index = 0 is "ab", which is an anagram of "ab".
                          The substring with start index = 1 is "ba", which is an anagram of "ab".
                          The substring with start index = 2 is "ab", which is an anagram of "ab".
**/

namespace BruteForceOne
{
    using namespace StringAlgorithms;

    bool are_anagrams(const int start,
                      const int end,
                      const std::string& str,
                      std::array<int, 256> map)
    {
        for (int idx = start; idx < end; ++idx) {
            if (--map[str[idx]] < 0)
                return false;
        }
        return true;
    }


    void find_all_anagrams_in_string(const std::string& str,
                                     const std::string& mask)
    {
        std::array<int, 256> map {0};
        for (const char ch: mask)
            ++map[ch];

        for (int idx = 0, len = mask.size(), size = str.size() - len; idx <= size; ++idx) {
            if (are_anagrams(idx, idx + len, str, map))
            {
                std::cout << std::quoted(std::string_view(str.data() + idx, str.data() + idx + len)) << " ";
            }
        }
        std::cout << std::endl;
    }
}

namespace BruteForceTwo
{
    using namespace StringAlgorithms;

    void find_all_anagrams_in_string(const std::string& str,
                                     const std::string& mask)
    {
        std::array<int, 256> map { 0 }, mapCurrent { 0 };
        for (const char ch: mask)
            ++map[ch];
        for (int idx = 0; idx < mask.size(); ++idx)
            ++mapCurrent[str[idx]];

        if (map == mapCurrent) {
            std::cout << std::string_view(str.data(), str.data() +mask.size())<< std::endl;
        }
        for (size_t len = mask.size(), idx = len, size = str.size(); idx < size; ++idx)
        {
            --mapCurrent[str[idx - len]];
            ++mapCurrent[str[idx]];
            if (map == mapCurrent) {
                std::cout << std::string_view(str.data() +  idx - len  + 1, str.data() + idx + 1)<< std::endl;
            }
        }
    }
}

void StringAlgorithms::Find_All_Anagrams_in_String()
{
    using TestData = std::vector<std::pair<std::pair<std::string, std::string>, int>>;
    for (const auto& [values, expected]:  TestData {
            { {"cbaebabacd", "abc"} , 1 },
            //{ {"abcab", "abc"} , 1 },
    })
    {
        BruteForceOne::find_all_anagrams_in_string(values.first, values.second);

        std::cout << std::endl;

        BruteForceTwo::find_all_anagrams_in_string(values.first, values.second);

        /*
        const auto actual = TEST_FUNCTION(values);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        */
    }
   // std::cout << "OK: All tests passed\n";
}