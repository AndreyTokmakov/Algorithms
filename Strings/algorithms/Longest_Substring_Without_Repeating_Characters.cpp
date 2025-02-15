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


    int64_t longestUniqueSubstr_0(const std::string &s)
    {
        int64_t max_len = 0, left = -1;
        // initial left border, before the start of the string
        // storage for last instance of each character
        std::vector<int64_t> arr(256, -1);
        for (int64_t right = 0; right < std::ssize(s); ++right) {
            // last seen is in between left and right
            // this is a duplicate, move left to the duplicate
            if (arr[unsigned(s[right])] > left)
                left = arr[unsigned(s[right])];
            // remember the new last seen
            arr[unsigned(s[right])] = right;
            // left to right, but not including the character at left
            max_len = std::max(max_len, right - left);
        }
        return max_len;
    }

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
}

void StringAlgorithms::Longest_Substring_Without_Repeating_Characters()
{
    for (const StrSizeTPair &data: std::vector<StrSizeTPair>{
            {"abcde",     5},
            {"abcbef",    4},
            {"aaaaaa",    1},
            {"aaabbbccc", 2},
            {"abcabcbb",  3}
    }) {
        std::cout << longestUniqueSubstr_0(data.first) << " "
                  << longestUniqueSubstr_1(data.first) << " "
                  << longestUniqueSubstr_2(data.first) << " "
                  << longestUniqueSubstr_3_Map(data.first) << " "
                  << longestUniqueSubstr_4_Tbl(data.first) << " "
                  << longestUniqueSubstr_UnFinished(data.first)
                  << " | " << data.second << std::endl;
    }
}