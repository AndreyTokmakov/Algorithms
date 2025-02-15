/**============================================================================
Name        : Longest_Substring_Without_Repeating_Characters_2.cpp
Created on  : 15.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

#include <cstring>

namespace
{
    using namespace StringAlgorithms;


    size_t longest_substring_without_repeating_characters(const std::string &str)
    {
        uint16_t chars[256]{};
        size_t maxLen = 0;
        bool hasDuplicates = false;
        for (size_t left = 0, right = 0; right < str.size(); ++right) {
            if (++chars[str[right]] > 1)
                hasDuplicates = true;

            while (hasDuplicates) {
                if (--chars[str[left++]] == 1)
                    hasDuplicates = false;
            }
            maxLen = std::max(right - left + 1, maxLen);
        }
        return maxLen;
    }

    size_t lengthOfLongestSubstring(const std::string& s)
    {
        // int32_t seen[256] {0};
        std::unordered_map<char, int> seen;
        int ret = 0, slow = 0, n = s.size();
        for (int fast = 0; fast < n; ++fast)
        {
            // if (seen[(s[fast])] != 0)slow = std::max(slow, seen[s[fast]] + 1);
            if (seen.count(s[fast]) != 0) slow = std::max(slow, seen[s[fast]] + 1);

            seen[s[fast]] = fast;
            ret = std::max(ret, fast - slow + 1);
        }
        return ret;
    }

}

void StringAlgorithms::Longest_Substring_Without_Repeating_Characters_2()
{
    for (const StrSizeTPair &data: std::vector<StrSizeTPair>{
            {"abcde",     5},
            {"abcbef",    4},
            {"aaaaaa",    1},
            {"aaabbbccc", 2},
            {"abcabcbb",  3}
    }) {
        {
            const size_t count = longest_substring_without_repeating_characters(data.first);
            std::cout << "Actual: " << count << "  Expected: " << data.second << "  --> "
                      << std::boolalpha << (count == data.second) << std::endl;
        }

        {
            const size_t count = lengthOfLongestSubstring(data.first);
            std::cout << "Actual: " << count << "  Expected: " << data.second << "  --> "
                      << std::boolalpha << (count == data.second) << std::endl;
        }
    }
}