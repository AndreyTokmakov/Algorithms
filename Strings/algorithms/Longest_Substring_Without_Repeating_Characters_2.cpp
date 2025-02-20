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

#include <string>
#include <unordered_set>

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
            if (seen.count(s[fast]) != 0)
                slow = std::max(slow, seen[s[fast]] + 1);

            seen[s[fast]] = fast;
            ret = std::max(ret, fast - slow + 1);
        }
        return ret;
    }

    size_t longest_substring_without_repeating_characters_2(const std::string &text)
    {
        std::unordered_set<int> hashSet;
        int result = 0;
        for (int left = 0, right = 0, size = text.size(); right < size;)
        {
            if (hashSet.insert(text[right]).second) {
                result = std::max(result, right - left + 1);
                right++;
            } else {
                hashSet.erase(text[left]);
                left++;
            }
        }
        return result;
    }

}

void StringAlgorithms::Longest_Substring_Without_Repeating_Characters_2()
{
    for (const auto& [str, expected]: std::vector<StrSizeTPair>{
            {"abcde",     5},
            {"abcbef",    4},
            {"aaaaaa",    1},
            {"aaabbbccc", 2},
            {"abcabcbb",  3}
    })
    {
        {
            if (const size_t actual = longest_substring_without_repeating_characters(str); expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        {
            if (const size_t actual = lengthOfLongestSubstring(str); expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        {
            if (const size_t actual = longest_substring_without_repeating_characters_2(str); expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
    }
    std::cout << "OK: All tests passed\n";
}