/**============================================================================
Name        : Longest_Substring_With_Maximum_K_Unique_Characters.cpp
Created on  : 24.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
It is necessary to find the maximum length of a substring such that it contains no more than 'K' unique elements
**/

namespace
{
    using namespace StringAlgorithms;

    size_t findLenWithMax_K_UniqueChars(const std::string &text,
                                        const size_t K)
    {
        size_t result { 0 }, indexes[256]{};
        for (size_t right = 0, left = 0, uniqCount = 0; right < text.length(); ++right)
        {
            if (0 == indexes[text[right]]++)
                ++uniqCount;

            while (uniqCount > K) {
                if (const char ch = text[left++]; 0 == --indexes[ch])
                    --uniqCount;
            }
            result = std::max(result, right - left + 1);
        }
        return result;
    }
}

void StringAlgorithms::Longest_Substring_With_Maximum_K_Unique_Characters()
{
    for (const auto & [data, expected]: std::vector<std::pair<StrSizeTPair, size_t> >{
            {{"aba",       2}, 3},
            {{"ababaaab",  2}, 8},
            {{"ababaaacb", 2}, 7},
            {{"ababaaacb", 3}, 9},
            {{"aabbcc",    1}, 2},
            {{"aabbcc",    2}, 4},
            {{"aabbcc",    3}, 6}
    }) {
        const auto &[str, K] = data;
        if (const auto actual = findLenWithMax_K_UniqueChars(str, K); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
