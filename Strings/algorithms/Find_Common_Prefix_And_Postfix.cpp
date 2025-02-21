/**============================================================================
Name        : Find_Common_Prefix_And_Postfix.cpp
Created on  : 20.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"


/**
Given a string s, find the length of the longest prefix, which is also a suffix. The prefix and suffix should not overlap.
aabcdaabc --> 4 [The string "aabc" is the longest]
abcab     --> 2 [The string "ab" is the longest]
aaaa      --> 2 [The string "aa" is the longest]
**/


namespace
{
    using namespace StringAlgorithms;

     size_t find_common_prefix_and_postfix(const std::string& str)
    {
        size_t maxLen = 0;
        /** idx = (str.size() + 1) / 2 ---> starting from the center + 1 **/
        /** (str.size() + 1) / 2    <==>  str.size() / 2 + str.size() % 2  **/
        for (size_t idx = (str.size() + 1) / 2; idx < str.size(); ++idx)
        {
            if (size_t left = 0, right = idx, len = 1; str[left] == str[right])
            {
                while (str[++left] == str[++right]) {
                    ++len;
                }
                maxLen = std::max(maxLen, len);
            }
        }
        return maxLen;
    }

    // https://www.geeksforgeeks.org/longest-prefix-also-suffix/
    // Efficient Solution: The idea is to use the preprocessing algorithm KMP search.
    // In the preprocessing algorithm, we build lps array which stores the following values.
    size_t find_common_prefix_and_postfix_efficient(const std::string& str)
    {
        const size_t size = str.size();
        std::vector<size_t> lps(size);

        // length of the previous longest prefix suffix , the loop calculates lps[i] for i = 1 to n-1
        for (size_t idx = (size + 1) / 2, length = 0; idx < size; /** **/)
        {
            if (str[idx] == str[length])
            {
                length++;
                lps[idx] = length;
                idx++;
            }
            else // (pat[i] != pat[len])
            {
                // This is tricky. Consider the example. AAACAAAA and i = 7. The idea is similar to search step.
                if (length != 0)
                {
                    length = lps[length - 1]; // Also, note that we do not increment i here
                }
                else // if (len == 0)
                {
                    lps[idx] = 0;
                    idx++;
                }
            }
        }

        // Since we are looking for non overlapping parts.
        return lps[size - 1];
    }

    int64_t find_common_prefix_and_postfix_efficient2(const std::string& str)
    {
        const int64_t size = std::ssize(str);
        if (str.empty())
            return 0;

        int64_t endSuffix = size - 1, endPrefix = size/2 - 1;
        while (endPrefix >= 0)
        {
            if (str[endPrefix] != str[endSuffix])
            {
                if (endSuffix != size - 1) {
                    endSuffix = size - 1;
                }
                else{
                    --endPrefix;
                }
            }
            else{
                --endSuffix;
                --endPrefix;
            }
        }

        return size - endSuffix - 1;
    }

}

void StringAlgorithms::Find_Common_Prefix_And_Postfix()
{
    for (const std::string& str: {"123X412", "aaaa", "aabaa", "aabcaa", "aacbaac", "aabcdaabc"})
    {
        std::cout << find_common_prefix_and_postfix(str) << "  "
                  << find_common_prefix_and_postfix_efficient(str) << "  "
                  << find_common_prefix_and_postfix_efficient2(str)
                  << std::endl;
    }
}
