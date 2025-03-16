/**============================================================================
Name        : Longest_Substring_Without_Repeating_Characters.cpp
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

    std::string longestUniqueSubstr_1(const std::string &text)
    {
        char duplicates[256] = {0};
        size_t beg = 0, length = 0, maxlen = 0;
        for (size_t index = 0; index < text.length(); index++) {
            const char c = text[index];
            if (1 == duplicates[c]) {
                length = 1;
                memset(duplicates, 0, sizeof(duplicates));
            } else {
                if (++length > maxlen) {
                    maxlen = length;
                    beg = index - length + 1;
                }
            }
            duplicates[text[index]] = 1;
        }
        return text.substr(beg, maxlen);
    }

    size_t longestUniqueSubstr_2(const std::string &text)
    {
        size_t maxLength = 0, repeat_count = 0, indexes[256] = {0};
        for (size_t idx = 0; char c: text) {
            repeat_count = std::max(repeat_count, indexes[c] + 1);
            maxLength = std::max(maxLength, idx - repeat_count + 1);
            indexes[c] = idx++;
        }
        return maxLength;
    }

    size_t longestUniqueSubstr_3_Map(const std::string &text)
    {
        std::unordered_map<char, size_t> seen;
        size_t result = 0;
        for (size_t fast = 0, slow = 0; fast < text.size(); ++fast)
        {
            if (seen.count(text[fast]) != 0)
                slow = std::max(slow, seen[text[fast]] + 1);
            seen[text[fast]] = fast;
            result = std::max(result, fast - slow + 1);
        }
        return result;
    }

    size_t longestUniqueSubstr_4_Tbl(const std::string &text)
    {
        size_t result = 0, indexes[256]{0};
        for (size_t fastIdx = 0, slow = 0; const char c: text) {
            slow = std::max(slow, indexes[c] + 1);
            indexes[c] = fastIdx++;
            result = std::max(result, fastIdx - slow);
        }
        return result;
    }

    size_t longestUniqueSubstr_4_Tbl_Debug(const std::string &text) {
        size_t result = 0, indexes[256]{0};
        for (size_t fastIdx = 0, slow = 0; const char c: text) {
            slow = std::max(slow, indexes[c] + 1);
            indexes[c] = fastIdx++;
            std::cout << c << "  |  " << indexes[c] << "  |  " << fastIdx << "  |  " << slow << std::endl;
            result = std::max(result, fastIdx - slow);
        }
        return result;
    }

    // 1. Цикл в котором инкрементируем количество встреченных символов по их ISCI коду в таблице
    //    и тут рассчитываем максимальную длину как разницу между left и right + 1
    // 2. Как только количество встреч данного символа в рамках (cтрока от left до right) более чем один выполняем
    //    while цикл в котором двигаем left право пока количество встреч символа по индексу right не станет равным == 1

    size_t longestUniqueSubstr_UnFinished(const std::string &text) {
        size_t maxLen = 0, table[256]{0};
        for (size_t left = 0, right = 0, size = text.size(); right < size; ++right) {
            const size_t charIdx = static_cast<size_t>(text[right]);
            if (++table[charIdx] == 1) { // Its a first occurrence of the char == text[right]
                maxLen = std::max(maxLen, right - left + 1);
            } else {
                while (table[charIdx] > 1) {
                    --table[text[left]];
                    ++left;
                }
            }
        }
        return maxLen;
    }


    size_t lengthOfLongestSubstring(const std::string& str)
    {
        std::array<int, 128> counter {0};
        size_t maxLen = 0;
        for (size_t repeatCharsCount = 0, begin = 0, idx = 0, size = str.size(); idx < size; )
        {
            if (counter[str[idx++]]++ > 0)
                ++repeatCharsCount;
            while (repeatCharsCount > 0) {
                if (1 == --counter[str[begin++]])
                    --repeatCharsCount;
            }
            maxLen = std::max(maxLen, idx - begin);
        }
        return maxLen;
    }
}

void StringAlgorithms::Longest_Substring_Without_Repeating_Characters()
{
    using TestData = std::vector<std::pair<std::string, size_t>>;
    for (const auto& [str, lenExpected]: TestData {
            {"abcde",     5},
            {"abcbef",    4},
            {"aaaaaa",    1},
            {"aaabbbccc", 2},
            {"abcabcbb",  3}
    }) {
        /*
        if (const auto actual = longestUniqueSubstr_0(str); lenExpected != actual) {
            std::cerr << std::boolalpha << lenExpected << " != " << actual << std::endl;
        }
        if (const auto actual = longestUniqueSubstr_1(str); lenExpected != actual.size()) {
            std::cerr << std::boolalpha << lenExpected << " != " << actual << std::endl;
        }
        if (const auto actual = longestUniqueSubstr_2(str); lenExpected != actual) {
            std::cerr << std::boolalpha << lenExpected << " != " << actual << std::endl;
        }
        if (const auto actual = longestUniqueSubstr_3_Map(str); lenExpected != actual) {
            std::cerr << std::boolalpha << lenExpected << " != " << actual << std::endl;
        }
        if (const auto actual = longestUniqueSubstr_4_Tbl(str); lenExpected != actual) {
            std::cerr << std::boolalpha << lenExpected << " != " << actual << std::endl;
        }
        if (const auto actual = longestUniqueSubstr_UnFinished(str); lenExpected != actual) {
            std::cerr << std::boolalpha << lenExpected << " != " << actual << std::endl;
        }*/

        std::cout << longestUniqueSubstr_1(str) << " "
                  << longestUniqueSubstr_2(str) << " "
                  << longestUniqueSubstr_3_Map(str) << " "
                  << longestUniqueSubstr_4_Tbl(str) << " "
                  << longestUniqueSubstr_UnFinished(str) << " "
                  << lengthOfLongestSubstring(str) << " "
                  << " | " << lenExpected<< std::endl;
    }
}