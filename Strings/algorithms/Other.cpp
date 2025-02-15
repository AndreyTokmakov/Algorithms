/**============================================================================
Name        : Other.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <cstring>

#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

#include <cstdint>
#include <iomanip>

#include "StringUtilities.h"



namespace Strings
{
    using namespace StringAlgorithms;


    size_t __palindrom_length(const std::string &str, size_t start, size_t end) {
        size_t length = 0;
        while (start >= 0 && end < str.size()) {
            if (str[start] == str[end]) {
                length = end - start + 1;
                start--;
                end++;
            } else
                break;
        }
        return length;
    }

    std::string longestPalindrome(const std::string &str) {
        size_t start = 0, end = 0;
        if (true == str.empty())
            return "";

        size_t len1 = 0, len2 = 0;
        for (size_t center = 0; center < str.size(); center++) {
            len1 = __palindrom_length(str, center, center);
            len2 = __palindrom_length(str, center, center + 1);
            if (len1 > end - start) {
                start = center - len1 / 2;
                end = center + len1 / 2;
            }
            if (len2 > end - start) {
                start = center + 1 - len2 / 2;
                end = center + len2 / 2;
            }
        }
        return str.substr(start, end - start + 1);
    }

    void Longest_Palindrome_1() {
        for (const StringPair &data: std::vector<StringPair>{
                {"babad",           "aba"},
                {"cbbd",            "bb"},
                {"ddddd3456654321", "34566543"}
        }) {
            std::cout << longestPalindrome(data.first) << " | " << data.second << std::endl;
        }
    }

    //--------------------------------------------------------------------------------------//

    size_t __palindrom_length_2(const std::string &str, size_t start, size_t end) {
        size_t length = 0;
        while (start >= 0 && end < str.size() &&
               str[start--] == str[end++]) {
            length = end - start - 1;
        }
        return length;
    }

    std::string longestPalindrome2(const std::string &str) {
        if (str.empty())
            return "";

        size_t start = 0, end = 0;
        size_t len1 = 0, len2 = 0;
        for (size_t center = 0; center < str.size(); center++) {
            len1 = __palindrom_length_2(str, center, center);
            len2 = __palindrom_length_2(str, center, center + 1);
            if (len1 > end - start) {
                start = center - len1 / 2;
                end = center + len1 / 2;
            }
            if (len2 > end - start) {
                start = center + 1 - len2 / 2;
                end = center + len2 / 2;
            }
            if ((end - start) > (str.size() - center - 1) * 2) {
                break;
            }
        }
        return str.substr(start, end - start + 1);
    }

    void Longest_Palindrome_2() {
        assert(longestPalindrome2("11111") == "11111");
        assert(longestPalindrome2("12345543211234") == "1234554321");
        assert(longestPalindrome2("123456789123456789aaaaa1111") == "aaaaa");
    }

    //--------------------------------------------------------------------------------------//

    bool isKPal(const std::string &str, size_t k) {
        // find longest palindromic subsequence of given string
        std::string lps = longestPalindrome2(str);

        // If the difference between the longest palindromic
        // subsequence and the original string is less
        // than equal to k, then the string is k-palindrome
        return (str.size() - lps.size() <= k);
    }

    void Find_If_KPalindrome() {
        std::string str = "abcdeca";
        size_t k = 2;

        std::cout << std::boolalpha << isKPal(str, k) << std::endl;
    }

    //-------------------------------------------------------------------------------------------------------------

    bool _is_range_palindrome(const std::string &str, int startIndex, int endIndex) {
        for (int idx = startIndex; idx <= endIndex / 2; ++idx) {
            if (str[idx] != str[endIndex - idx])
                return false;
        }
        return true;
    }

    std::string shortest_palindrome(const std::string &str) {
        const int size = str.size();
        if (1 >= size)
            return str;
        int lastIdx = size - 1;
        while (!_is_range_palindrome(str, 0, lastIdx)) {
            --lastIdx;
        }

        if (size == lastIdx + 1)
            return str;

        std::string result(2 * size - 1 - lastIdx, '0');
        for (int idx = 0; idx < size; ++idx)
            result[idx + size - 1 - lastIdx] = str[idx];
        for (int idx = 0; idx < size - 1 - lastIdx; ++idx)
            result[idx] = str[size - 1 - idx];

        return result;
    }

    /**
    You are given a string s. You can convert s to a palindrome by adding characters in front of it.
    Return the shortest palindrome you can find by performing this transformation.
    Example 1:   Input  : "aacecaaa"       Example 2:   Input  : "abcd"
                 Output : "aaacecaaa"                   Output : "dcbabcd"
    */

    void ShortestPalindrome() {
        for (const std::string &data: std::vector<std::string>{
                // "aba", "abba", "aa", "ab", "abcba", "aabbaa", "abc"
                "xyzzyxaac"
                // "aacecaa"
        }) {
            // std::cout << data << " -> " << std::boolalpha << _is_range_palindrome(data, 0, data.size() - 1) << std::endl;
            std::cout << shortest_palindrome(data) << std::endl;
        }
    }

    //-------------------------------------------------------------------------------------------------------------

    void _find_all_palindrome_substrings(const std::string &text) {
        std::set<std::string> palindromes;
        auto func = [&](const std::string &str, int start, int end) {
            while (start >= 0 && end < std::ssize(text) && str[start] == str[end]) {
                if (end > start) // ignore single char palindromes
                    palindromes.insert(str.substr(start, end - start + 1));
                start--;
                end++;
            }
        };

        for (int i = 0; i < std::ssize(text) - 1; i++) {
            func(text, i, i);
            func(text, i, i + 1);
        }

        for (const auto &s: palindromes)
            std::cout << s << std::endl;
    }

    void Find_All_Palindrome_In_String() {
        std::string str = "lgooglaabbaae";
        _find_all_palindrome_substrings(str);
    }

    //--------------------------------------------------------------------------------------//

    void _rearrange_string(std::string &text) {
        uint32_t chars[256]{0};
        for (char c: text)
            chars[(int8_t) (c)]++;

        for (size_t i = 0, pos = 0; i < 256; ++i) {
            while (chars[i]--) {
                text[pos++] = (char) i;
            }
        }
    }

    void _rearrange_string1(std::string &text) {
        int chars[256]{0};
        for (char c: text)
            chars[(int8_t) (c)]++;

        for (int i = 0, pos = 0; i < 256; ++i) {
            std::fill_n(text.begin() + pos, chars[i], (char) i);
            pos += chars[i];
        }
    }


    void _rearrange_string2(std::string &text) {
        int chars[256]{0};
        for (char c: text)
            chars[(int8_t) (c)]++;

        size_t pos = 0, diff = (int) 'a' - (int) 'A';
        for (size_t i = 'A'; i <= 'z'; i++) {
            while (chars[i + diff]) {
                text[pos++] = (char) (i + diff);
                chars[i + diff]--;
            }
            while (chars[i]) {
                text[pos++] = (char) i;
                chars[i]--;
            }
        }
    }

    void RearrangeString() {
        for (const std::string &str: {"FNYaJGNMHSWUzAGQLADQUaYMYSGQRxPCAXU"}) {
            {
                std::string s{str};
                std::cout << s << " --> ";
                _rearrange_string(s);
                std::cout << s << '\n';
            }
            {
                std::string s{str};
                std::cout << s << " --> ";
                _rearrange_string1(s);
                std::cout << s << '\n';
            }
            {
                std::string s{str};
                std::cout << s << " --> ";
                _rearrange_string2(s);
                std::cout << s << '\n';
            }
        }
    }

    //--------------------------------------------------------------------------------------//

    void __rearrange_string_with_numbers(std::string &text) {
        int chars[256] = {0}, sum = 0;
        for (char c: text) {
            if ('9' >= c && c >= '0') {
                sum += (int) (c - '0');
            } else {
                chars[c]++;
            }
        }

        for (size_t i = 0; i < 256; i++) {
            while (chars[i]--) {
                std::cout << (char) i;
            }
        }
        std::cout << sum << std::endl;
    }

    void RearrangeString_WithNumbers() {
        std::string str = "DORWBL4A1aaa6H1";


        std::cout << str << std::endl;
        __rearrange_string_with_numbers(str);
    }
    //--------------------------------------------------------------------------------------//

    // Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same.
    // If this is not possible, return None. For example, given "aaabbc", you could return "ababac". Given "aaab", return None.

    void RearrangeString_NoAdjacent() {
        std::string text = "aaabbc";
        std::cout << text << "   --->    ";

        int chars[256] = {0};
        for (char c: text)
            chars[c]++;

        size_t pos = 0;
        bool stop = false;
        while (false == stop) {
            for (size_t i = 0; i < std::size(chars); i++) {
                if (chars[i]) {
                    text[pos] = i;
                    chars[i]--;
                    pos++;
                }
            }
            stop = std::all_of(std::begin(chars), std::end(chars), [](auto v) { return v == 0; });
        }
        std::cout << text << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    using CharPair = std::pair<char, size_t>;

    struct Comparator {
        bool operator()(const CharPair &pair1, const CharPair &pair2) {
            return pair1.second > pair2.second;
        }
    };

    void Find_K_MostFrequentCharacter() {
        std::string str = "GeeksforGeeksG";
        size_t K = 3, chars[256] = {0};

        for (char c: str)
            chars[c]++;

        std::priority_queue<CharPair, std::vector<CharPair>, Comparator> queue;
        for (size_t i = 0; i < 256; i++) {
            if (chars[i]) {
                if (queue.size() != 3) {
                    queue.push(CharPair((char) i, chars[i]));
                } else if (chars[i] > queue.top().second) {
                    queue.pop();
                    queue.push(CharPair((char) i, chars[i]));
                }
            }
        }

        while (!queue.empty()) {
            std::cout << ' ' << queue.top().first << "  " << queue.top().second << std::endl;
            queue.pop();
        }
        std::cout << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    void Find_K_MostFrequentCharacter_2() {
        const std::string str = "GeeksforGeeksGzG";

        std::multimap<int, char, std::greater<>> dict;
        {
            size_t chars[256] = {0};
            for (char c: str)
                chars[c]++;

            for (int i = 0; i < std::ssize(chars); i++) {
                if (chars[i])
                    dict.emplace(chars[i], i);
            }
        }

        size_t K = 3;
        for (const auto &[k, v]: dict) {
            std::cout << k << " = " << v << std::endl;
            if (0 == (--K))
                break;
        }
    }
}

namespace Strings
{
    void _rotate_string_once(std::string &str) {
        char tmp = str.back();
        memcpy(str.data() + 1, str.data(), str.length() - 1);
        str.front() = tmp;
    }

    void _rotate_string_K(std::string &str, size_t K) {
        K = K % str.length();
        char *tmp = new char[K];
        memcpy(tmp, str.data() + K + 1, K);
        memcpy(str.data() + K, str.data(), str.length() - K);
        memcpy(str.data(), tmp, K);
        delete[] tmp;
    }

    void _rotate_string_K_2(std::string &str, size_t K) {
        std::string result(str);
        for (size_t pos = 0; pos < str.size(); pos++, K++)
            result[K % str.size()] = str[pos];
        str.swap(result);
    }

    void RotateString() {
        {
            std::string text = "567891234";
            _rotate_string_once(text);
            std::cout << text << std::endl;
        }
        {
            std::string text = "567891234";
            _rotate_string_K(text, 4 + text.length());
            std::cout << text << std::endl;
        }
        {
            std::string text = "567891234";
            _rotate_string_K_2(text, 4);
            std::cout << text << std::endl;
        }
    }
}

namespace Strings
{

    // Необходимо найти максимальную длину подстроки такой что бы в ней было не более чем 'K' уникальных элементов
    size_t findLenWithMax_K_UniqueChars(const std::string &text,
                                        const size_t K)
    {
        size_t result{0}, indexes[256]{};
        for (size_t right = 0, left = 0, uniqCount = 0; right < text.length(); ++right)
        {
            const char c = text[right];
            if (0 == indexes[c]++)
                ++uniqCount;

            while (uniqCount > K) {
                const char ch = text[left++];
                if (0 == --indexes[ch])
                    --uniqCount;
            }
            result = std::max(result, right - left + 1);
        }
        return result;
    }

    void MaxSubstringLength_Of_K_max_Unique_Elements()
    {
        for (const std::pair<StrSizeTPair, size_t> &data: std::vector<std::pair<StrSizeTPair, size_t> >{
                {{"aba",       2}, 3},
                {{"ababaaab",  2}, 8},
                {{"ababaaacb", 2}, 7},
                {{"ababaaacb", 3}, 9},
                {{"aabbcc",    1}, 2},
                {{"aabbcc",    2}, 4},
                {{"aabbcc",    3}, 6}
        }) {
            const auto &[str, K] = data.first;
            const size_t count = findLenWithMax_K_UniqueChars(str, K);
            std::cout << "Actual: " << count << "  Expected: " << data.second << "  --> "
                      << std::boolalpha << (count == data.second) << std::endl;
        }
    }

    //--------------------------------------------------------------------------------------//

    int64_t longestUniqueSubstr_0(const std::string &s) {
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

    std::string longestUniqueSubstr_1(const std::string &text) {
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

    size_t longestUniqueSubstr_2(const std::string &text) {
        size_t maxLength = 0, repeat_count = 0, indexes[256] = {0};
        for (size_t idx = 0; char c: text) {
            repeat_count = std::max(repeat_count, indexes[c] + 1);
            maxLength = std::max(maxLength, idx - repeat_count + 1);
            indexes[c] = idx++;
        }
        return maxLength;
    }

    size_t longestUniqueSubstr_3_Map(const std::string &text) {
        std::unordered_map<char, size_t> seen;
        size_t result = 0;
        for (size_t fast = 0, slow = 0; fast < text.size(); ++fast) {
            if (seen.count(text[fast]) != 0)
                slow = std::max(slow, seen[text[fast]] + 1);
            seen[text[fast]] = fast;
            result = std::max(result, fast - slow + 1);
        }
        return result;
    }

    size_t longestUniqueSubstr_4_Tbl(const std::string &text) {
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

    void LongestSubstringWithoutRepeatingCharacters() {
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

    size_t longest_substring_without_repeating_characters(const std::string &str) {
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

    void LongestSubstringWithoutRepeatingCharacters2() {
        for (const StrSizeTPair &data: std::vector<StrSizeTPair>{
                {"abcde",     5},
                {"abcbef",    4},
                {"aaaaaa",    1},
                {"aaabbbccc", 2},
                {"abcabcbb",  3}
        }) {
            const size_t count = longest_substring_without_repeating_characters(data.first);
            std::cout << "Actual: " << count << "  Expected: " << data.second << "  --> "
                      << std::boolalpha << (count == data.second) << std::endl;
        }
    }

    //--------------------------------------------------------------------------------------//

    void __longestConsecutiveCharacters(const std::string &text) {
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
        std::cout << " Max = " << max_len << " of " << c << std::endl;
    }

    void __longestConsecutiveCharacters2(const std::string &text) {
        size_t max_len = 0;
        char prev = text.back();
        for (size_t len = 0; const char c: text) {
            len = (c == prev) ? len + 1 : 1;
            max_len = std::max(len, max_len);
            prev = c;
        }
        std::cout << " Max = " << max_len << " of " << prev << std::endl;
    }

    void LongestConsecutiveCharacters() {
        const std::string &text{"aabbbbbcccc"};
        __longestConsecutiveCharacters(text);
        __longestConsecutiveCharacters2(text);
    }

    //---------------------------------------------------------------------------//

    double getAngleOnClock(std::string_view timeStr) {
        const size_t pos = timeStr.find(':');
        const double hours = atoi(timeStr.substr(0, pos).data());
        const double minutes = atoi(timeStr.substr(pos + 1, timeStr.length() - pos - 1).data());

        /*
         * The whole dial is 360 degrees and each interval is 30 degrees
         * Then there will be 150 degrees (5 intervals) between the marks corresponding to 10 and 15
         * However, the hour hand will shift from 10 to 15 minutes, which is 25% of the hour, that is 7.5 degrees from 30.
         * Then 150-7.5=142.5
         */

        auto degrees = std::abs(hours * 30 - minutes * 6 + (30 * minutes) / 60);
        degrees = std::min(degrees, 360 - degrees);

        [[maybe_unused]]
        const double radians = (degrees * std::numbers::pi) / 180;

        // std::cout << "degrees = " << degrees << std::endl;
        // std::cout << "radians = " << radians << std::endl;
        return degrees;
    }

    void AnalogClockAngles() {
        // std::string timeString = "03:00";
        std::string timeString = "09:30";

        getAngleOnClock(timeString);
    }
}

namespace Strings
{
    unsigned int _atoi(const char* str)
    {
        unsigned int result {0};
        char c = *str;
        while (c >= '0' && c <= '9') {
            result = result * 10 + (c - '0');
            c = *(++str);
        }
        return result;
    }

    unsigned int _atoi2(const char* c)
    {
        unsigned int result {0};
        while (*c >= '0' && *c <= '9')
            result = result * 10 + (*(c++) - '0');
        return result;
    }

    void Atoi()
    {
        for (const auto& str: {
                "123", "1203", "931aa", "00123", "  -123 hh", "42"
                // "-91283472332"
        }) {
            std::cout << str << " -> " << _atoi(str) <<  "    " << _atoi2(str) <<  "    " <<  std::endl;
        }
    }
}

namespace Strings
{
    int32_t _atoi_ex(std::string_view str)
    {
        int32_t number {0}, size = str.size(), idx = 0, sign = 0;
        for (idx = 0; idx < size && sign == 0; ++idx) {
            if (str[idx] == ' ') {}
            else if (str[idx] == '+') sign = 1;
            else if (str[idx] == '-') sign = -1;
            else break;
        }

        while (size > idx && str[idx] >= '0' && str[idx] <= '9')
            number = number * 10 + (str[idx++]  - '0');
        return number * (sign ? sign : 1);
    }

    constexpr int parseInt(std::string_view str)
    {
        const size_t start = str.find_first_not_of(' ');
        if (start == std::string_view::npos)
            return 0;

        int sign = 1;
        size_t index = start;

        if (str[start] == '-' || str[start] == '+') {
            sign = (str[start] == '-') ? -1 : 1;
            ++index;
        }

        int val = 0;
        for (; index < str.size(); ++index) {
            char ch = str[index];
            if (ch < '0' || ch > '9') {
                break;
            }
            val = val * 10 + (ch - '0');
        }

        return sign * val;
    }

    // Read in and ignore any leading whitespace.
    //
    // Check if the next character (if not already at the end of the string) is '-' or '+'.
    // Read this character in if it is either. This determines if the final result is negative or positive respectively.
    // Assume the result is positive if neither is present.777777

    void Atoi_Extended()
    {
        for (const auto& str: {
                "123", "1203", "931aa", "00123","  -123 hh","  -+123 hh", "42", "-91283472332"
        }) {
            std::cout << std::left << std::setfill(' ') << std::setw(14) << std::quoted(str)
                      << " -> " << _atoi_ex(str) << "    " << parseInt(str) <<  std::endl;
        }
    }
}

namespace Strings
{
    size_t _str_len(const char* str)
    {
        size_t count = 0;
        while (*str != '\0')
        {
            ++str;
            ++count;
        }
        return count;
    }

    void StrLen()
    {
        for (const auto& [str, len]: std::vector<std::pair<std::string, size_t>>{
                {"12345", 5}, {"qwerty123456", 12}
        })
        {
            std::cout << len << " = " <<  _str_len(str.data()) << std::endl;
        }
    }

    //--------------------------------------------------------------------------------------//

    void __printDistinctSubStrs__len2(const std::string& str) {
        std::unordered_map<std::string, unsigned int> pairs;
        for (size_t i = 0; i < str.size() - 1; i++)
            pairs[str.substr(i, 2)]++;

        std::cout << "Distinct sub-strings with counts:" << std::endl;
        for (const auto it : pairs)
            std::cout << it.first << "-" << it.second << std::endl;
    }

    void Print_Distinct_SubStrings_Len2()
    {
        std::string str = "abcacdcacabacaassddssklac";
        __printDistinctSubStrs__len2(str);
    }

    //--------------------------------------------------------------------------------------//

    void __printDistinctSubStrs__(const std::string& str)
    {
        for (size_t size = str.size(), i = 0; i < size; ++i) {
            for (size_t n = i + 1; n < size; ++n)
                std::cout << std::string_view(str.data() + i, n - i) << std::endl;
        }
    }

    void Print_Distinct_SubStrings()
    {
        std::string str = "abcde";
        __printDistinctSubStrs__(str);
    }

    //--------------------------------------------------------------------------------------//

    void FindDuplicateSymbols() {
        const std::string text = "1234567829dabcdfGGG";
        int chars[256] = {};

        std::cout << "Duplicate symbols: \n";
        for (const auto c : text) {
            if (1 == chars[c]++) {
                std::cout << c << ' ';
            }
        }
        std::cout << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    bool __check_parentheses(const std::string& str) {
        std::stack<char> stack;
        for (const char c : str) {
            if ('(' == c)
                stack.push(c);
            else if (')' == c) {
                if (stack.empty())
                    return false;
                if ('(' == stack.top())
                    stack.pop();
            }
        }
        return stack.empty();
    }

    bool __check_parentheses_vector(const std::string& str) {
        std::vector<char> brackets;
        brackets.reserve(str.length());
        for (const char c : str) {
            if ('(' == c) {
                brackets.push_back(c);
            }
            else if (')' == c) {
                if (!brackets.empty() && '(' == brackets.back())
                    brackets.pop_back();
                else return false;
            }
        }
        return brackets.empty();
    }

    void CalcParentheses() {

        std::vector<std::string> params = { "()", ")(()))", "(" ,"(())((()())())", "))" };
        for (const auto& str : params) {
            std::cout << std::boolalpha << __check_parentheses(str) << "   "
                      << std::boolalpha << __check_parentheses_vector(str) << std::endl;
        }
        std::cout << std::endl;
    }


    //--------------------------------------------------------------------------------------//

    int _calcParentheses_K_deletions(const std::string& str) {
        std::vector<char> brackets;
        brackets.reserve(str.length());
        for (const char c : str) {
            if ('(' == c) {
                brackets.push_back(c);
            }
            else if (')' == c) {
                if (brackets.empty() || ')' == brackets.back())
                    brackets.push_back(c);
                else
                    brackets.pop_back();
            }
        }
        return brackets.size();
    }

    // Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed to make the string valid
    // (i.e. each open parenthesis is eventually closed). For example, given the string "()())()", you should return 1.
    // Given the string ")(", you should return 2, since we must remove all of them.

    void CalcParentheses_K_Deletions()
    {
        const std::vector<std::string> testData {"()())()", ")(", ")()(", "((()))()"};
        for (const std::string& str: testData)
        {
            std::cout << str << " = " << _calcParentheses_K_deletions(str) << std::endl;
        }
    }

    //--------------------------------------------------------------------------------------//

    void Remove_Add_Chars()
    {
        std::string text = "a1b2a3b4a5b6232323";

        size_t pos = 0;
        for (size_t i = 0; i < text.length(); i++) {
            if ('a' != text[i])
                text[pos++] = text[i];
        }

        for (size_t i = 0; i < text.length(); i++) {
            if ('b' == text[i]) {
                char c = text[i + 1], c1 = text[i + 2];
                for (size_t n = i + 1; n < text.length(); n++) {
                    c1 = text[n + 1];
                    text[n + 1] = c;
                    c = c1;
                }
                text[++i] = 'b';
            }
        }

        std::cout << text << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    // ERROR: if  text = "dcbefebcfe", mask = "fd" we have resul = 'dcbefebcf' instread 'dcbef'
    std::string _minimum_length_substrings(const std::string& text,
                                           const std::string& mask)
    {
        size_t chars[256] = { 0 };
        for (size_t pos = 0; pos < text.length(); pos++)
            chars[text[pos]] = pos + 1;

        size_t start = text.length(), end = 0;
        for (const char c : mask)
        {
            if (0 == chars[c])
                return "";
            start = std::min(chars[c], start);
            end = std::max(chars[c], end);
        }
        return text.substr(start - 1, end - start + 1);
    }

    std::string _minimum_length_substrings_2(const std::string& text,
                                             const std::string& mask)
    {
        // Hask map of elements in MASK
        size_t mask_chars[256] = { 0 };
        for (char c : mask)
            mask_chars[c] = 1;

        std::map<size_t, char> map;
        // If 'Text' containt elements from MASK insert them to map as <POS, CHAR>
        for (size_t pos = 0; pos < text.length(); pos++)
            if (1 == mask_chars[text[pos]])
                map.insert({ pos, text[pos] });

        assert(false == map.empty());
        std::pair<size_t, size_t> bounds = { map.begin()->first, std::prev(map.end())->first };

        // From left -> right to determine last repeated charachter from begining, it there are any:
        for (auto it = std::next(map.begin()); map.end() != it && it->second == map.begin()->second; ++it)
            bounds.first = it->first;

        // From right --> left to determine last repeated charachter at the end, it there are any:
        for (auto it = std::next(map.rbegin()); map.rend() != it && it->second == map.rbegin()->second; ++it)
            bounds.second = it->first;

        return text.substr(bounds.first, bounds.second - bounds.first + 1);
    }


    // You are given two strings s and t. You can select any substring of string s and
    // rearrange the characters of the selected substring. Determine the minimum length
    // of the substring of s such that string t is a substring of the selected substring.
    // Example: s = "dcbefebce" and t = "fd"' -- > dcbef
    void Minimum_Length_Substrings() {
        std::string text = "dcdbefebcfe", mask = "fd";

        std::cout << text << std::endl;

        std::cout << "Test1: " << _minimum_length_substrings(text, mask) << std::endl;
        std::cout << "Test2: " << _minimum_length_substrings_2(text, mask) << std::endl;
    }

    //--------------------------------------------------------------------------------------//

    size_t count_deletions_to_make_aragrams(const std::string& str1,
                                            const std::string& str2) {

        int chars1[256]{ 0 }, chars2[256]{ 0 };
        for (char c : str1)
            chars1[c]++;
        for (char c : str2)
            chars2[c]++;
        size_t result = 0;
        for (int i = 0; i < 256; ++i) {
            if (chars1[i] && chars2[i])
                result += std::abs(chars1[i] - chars2[i]);
            else
                result += chars1[i] + chars2[i];
        }
        return result;
    }

    size_t count_deletions_to_make_aragrams2(const std::string& str1,
                                             const std::string& str2) {
        int chars[256]{ 0 };
        for (char c : str1)
            chars[c]++;
        size_t result = 0;
        for (char c : str2) {
            if (chars[c])
                chars[c]--;
            else
                result++;
        }
        return result + std::accumulate(std::begin(chars), std::end(chars), 0);
    }

    size_t count_deletions_to_make_aragrams_super(const std::string& str1, const std::string& str2) {
        int chars[256]{ 0 };
        for (char c : str1)
            chars[c]++;
        for (char c : str2)
            chars[c]--;
        return std::accumulate(std::begin(chars), std::end(chars), 0, [](int a, int b) {
            return std::abs(a) + std::abs(b);
        });
    }

    void MakeAnagrams_CountDeletions() {
        {
            std::string str1 = "mabc", str2 = "cbdka";
            std::cout << count_deletions_to_make_aragrams(str1, str2) << std::endl;
            std::cout << count_deletions_to_make_aragrams2(str1, str2) << std::endl;
            std::cout << count_deletions_to_make_aragrams_super(str1, str2) << std::endl;
        }

    }

    //--------------------------------------------------------------------------------------//

    void _rotational_cipher(std::string& text, int rotationFactor) {
        int charRange = 'Z' - 'A' + 1;
        int charFactor = (rotationFactor % 256) % charRange;
        int intFactor = (rotationFactor % 256) % 10;

        for (char& c : text) {
            if (c >= 'A' && 'Z' >= c) {
                c = (c + charFactor) > 'Z' ? c + charFactor - charRange : c + charFactor;
            }
            else if (c >= 'a' && 'z' >= c) {
                c = (c + charFactor) > 'z' ? c + charFactor - charRange : c + charFactor;
            }
            else if (c >= '0' && '9' >= c) {
                c = c + intFactor;
                if (c > '9')
                    c = c - 10;
            }
        }
    }

    void RotationalCipher() {
        {
            std::string text = "Zebra-493?";
            std::cout << text << std::endl;

            _rotational_cipher(text, 3);
            std::cout << text << std::endl;
        }
        {
            std::string text = "abcdefghijklmNOPQRSTUVWXYZ0123456789";
            std::cout << text << std::endl;

            _rotational_cipher(text, 39);
            std::cout << text << std::endl;
        }
        {
            std::string text = "abcdZXYzxy-999.@";
            std::cout << text << std::endl;

            _rotational_cipher(text, 200);
            std::cout << text << std::endl;
        }
        {
            std::string text = "Epp-gsrzsCw-3-fi:Epivx5.";
            std::cout << text << std::endl;

            _rotational_cipher(text, 200);
            std::cout << text << std::endl;
        }
    }

    //-----------------------------------------------------------------//

    void permute(const std::string& prefix, std::string s) {
        if (s.size() <= 1)
            std::cout << prefix << s << std::endl;
        else {
            for (auto iter = s.begin(); s.end() != iter; ++iter) {
                char curr = *iter;
                s.erase(iter);
                //std::cout << "---> [" << curr << ", " << s << "]" << std::endl;
                permute(prefix + curr, s);
                //std::cout << "<--- [" << curr << ", " << s << "]" << std::endl;
                s.insert(iter, curr);
            }
        }
    }

    void Permutations() {
        permute("", "1234");
    }

    //-----------------------------------------------------------------//

    // Function to print permutations of string
    // This function takes three parameters:
    // 1. String
    // 2. Starting index of the string
    // 3. Ending index of the string.
    void permute_good(std::string& str, size_t begin, size_t end){
        if (begin == end) // Base case
            std::cout << str << std::endl;
        else {   // Permutations made
            for (size_t i = begin; i <= end; ++i) {
                // std::cout << "[" << begin << ", " << i << "]\n";
                std::swap(str[begin], str[i]);      // Swapping done       (1)
                permute_good(str, begin + 1, end);  // Recursion called
                std::swap(str[begin], str[i]);      // Backtrack -- Revert (1)
            }
        }
    }

    void Permutations2() {
        std::string str {"12"};

        std::cout << "Original: " << str << std::endl;
        permute_good(str, 0, str.size() - 1);
        std::cout << "Original: " << str << std::endl;
    }
};


namespace Strings
{
    using namespace std::string_literals;
    using namespace std::string_view_literals;

    std::string_view minimum_substring(std::string_view s,
                                       std::string_view t)
    {
        // Initialize the minimum substring to empty string.
        auto min_b = s.begin(), min_e = s.begin();
        auto b = s.begin(), e = s.begin();

        // Frequency of characters in the target string.
        std::unordered_map<char,int> freq;
        for (auto c : t)
            ++freq[c];

        long matches = std::ssize(t);
        while (e != s.end()) {
            // Expand to the right until we have all characters.
            while (e != s.end() && matches > 0) {
                auto it = freq.find(*e); // Lookup current character.
                if (it == freq.end()) {                // Ignore characters that are not in the target string.
                    ++e;
                    continue;
                }

                --it->second;          // Decrease the number of instances of this character (can go negative).
                if (it->second >= 0)   // Keep track of the number of characters still missing in the window.
                    --matches;
                ++e;
            }

            // Shrink from left until we no longer have all the characters.
            while (b < e && matches == 0) {
                auto it = freq.find(*b);  // Lookup current character.
                if (it == freq.end()) {                 // Ignore characters that are not in the target string.
                    ++b;
                    continue;
                }
                // We are guaranteed to have all characters, check if this is better than the current minimum.
                if (min_e == s.begin() || (e - b < min_e - min_b)) {
                    min_b = b;
                    min_e = e;
                }

                ++it->second;         // Since we are removing a character, increase the number of instances.
                if (it->second > 0)   // Keep track of the number of characters still missing in the window.
                    ++matches;
                ++b;
            }
        }
        return {min_b,min_e};
    }

    /// Given two strings (as std::string_view), find the minimum substring of the
    /// first string that contains all letters (with duplicates) from the second string.
    void Minimum_Substring()
    {
        std::cout << ((minimum_substring("a","aa") == "") ? "OK"sv : "Failed"sv) << std::endl;
        std::cout << ((minimum_substring("aaaa","aa") == "aa") ? "OK"sv : "Failed"sv) << std::endl;
        std::cout << ((minimum_substring("abcabc","abc") == "abc") ? "OK"sv : "Failed"sv) << std::endl;
        std::cout << ((minimum_substring("abxcba","abc") == "cba") ? "OK"sv : "Failed"sv) << std::endl;
        std::cout << ((minimum_substring("bbxaxxaaxaaaxabb","ababa") == "aaxabb") ? "OK"sv : "Failed"sv) << std::endl;
        std::cout << ((minimum_substring("aaaaaaxxxaaaaaa","xxx") == "xxx") ? "OK"sv : "Failed"sv) << std::endl;
    }
}

namespace Strings
{

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


    /**
    Given a string s, find the length of the longest prefix, which is also a suffix. The prefix and suffix should not overlap.
    aabcdaabc --> 4 [The string "aabc" is the longest]
    abcab     --> 2 [The string "ab" is the longest]
    aaaa      --> 2 [The string "aa" is the longest]
    **/

    void FindCommon_PrefixAndPostfix()
    {

        for (const std::string& str: {"123X412", "aaaa", "aabaa", "aabcaa", "aacbaac", "aabcdaabc"})
        {
            std::cout << find_common_prefix_and_postfix(str) << "  "
                      << find_common_prefix_and_postfix_efficient(str) << "  "
                      << find_common_prefix_and_postfix_efficient2(str)
                      << std::endl;
        }
    }
}

namespace Strings
{
    std::string reverse_words_in_string(const std::string& str)
    {
        std::string result;
        result.reserve(str.size());

        size_t pos = 0, prev = 0;
        while ((pos = str.find(' ', prev)) != std::string::npos) {
            if (pos > prev)
                result.insert(0, str, prev, pos - prev).insert(0, " ");
            prev = pos + 1;
        }
        result.insert(0, str, prev, str.length() - prev);
        if (result.front() == ' ')
            result.erase(0,1);
        result.shrink_to_fit();
        return result;
    }

    /**
     * Given an input string s, reverse the order of the words.
     * A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
     * Return a string of the words in reverse order concatenated by a single space.
     * Note that s may contain leading or trailing spaces or multiple spaces between two words.
     * The returned string should only have a single space separating the words. Do not include any extra spaces.
     *
     * "the sky is blue"   --> "blue is sky the"
     * "  hello world  "   --> "world hello"
     * "a good   example"  -->  "example good a"
     *
    */
    void Reverse_Words_in_String()
    {
        for (const std::string& str: std::vector<std::string> {
                {"the sky is blue" }, {"a  good   example   " }, {" asdasd df f"}, {"  hello world  "}
        })
        {
            std::cout << std::quoted(str) << " --> " << std::quoted(reverse_words_in_string(str)) << std::endl;
        }
    }
}

namespace Strings
{
    bool __contains(const std::string& text,
                    const std::string& str)
    {
        for (int idx = 0, m = 0, n= 0; idx <= std::ssize(text) - std::ssize(str); ++idx)
        {
            // std::cout << idx << std::endl;
            for (m = 0, n = idx; m < str.size(); ++m, ++n) {
                // std::cout << '\t' << n << " - " << m << std::endl;
                if (str[m] != text[n])
                    break;
            }
            if (m == str.size())
                return true;
        }
        return false;
    }

    int find(const std::string& haystack, const std::string& needle)
    {
        const int textSize = std::ssize(haystack), searchBlockSize = std::ssize(needle);
        for (int idx = 0, m = 0, n = 0; idx <= textSize - searchBlockSize; ++idx)
        {
            for (m = 0, n = idx; m < searchBlockSize; ++m, ++n) {
                if (needle[m] != haystack[n])
                    break;
            }
            if (m == searchBlockSize)
                return idx;
        }
        return -1;
    }

    void Contains()
    {
        std::string text = "bcaa", to_find = "aa";

        std::cout << "Contains: " << std::boolalpha << __contains(text, to_find)
                  << ". Pos = "   << find(text, to_find) << std::endl;
    }
}


namespace Strings
{
    std::string longest_word(const std::string& input)
    {
        std::vector<std::string_view> words;
        StringUtilities::split_to(input, words, " ");

        size_t longestIdx = 0;
        for (size_t idx = 0, maxLen = 0; idx < words.size(); ++idx)
        {
            if (words[idx].size() > maxLen) {
                longestIdx = idx;
                maxLen = words[idx].size();
            }
        }

        return std::string{words[longestIdx]};
    }

    std::string longest_word_fast(const std::string& input)
    {
        uint32_t startMax {0}, endMax {0}, prev {0}, idx {};
        for (; idx < input.size(); ++idx) {
            if (' ' == input[idx]) {
                if (idx - prev > endMax - startMax) {
                    startMax = prev;
                    endMax = idx;
                }
                prev = idx + 1;
            }
        }

        if (idx - prev > endMax - startMax) {
            startMax = prev;
            endMax = idx;
        }

        return {input,startMax ,endMax - startMax};
    }

    void Longest_Word()
    {
        for (const auto  &[value, expected]: std::vector<StringPair> {
                {"11 222 33", "222"},
                {"1", "1"},
                {"", ""},
                {"Hello world aaaaaa bbbbbb", "aaaaaa"},

        })
        {
            const std::string actual1 = longest_word(value);
            if (expected != actual1) {
                std::cerr << expected << " != " << actual1 << std::endl;
                return;
            }

            const std::string actual2= longest_word_fast(value);
            if (expected != actual2) {
                std::cerr << expected << " != " << actual2 << std::endl;
                return;
            }
        }
        std::cout << "OK: All tests passed\n";
    }
}

namespace Strings
{
    std::string intersperse_strings(const std::string& str1,
                                    const std::string& str2)
    {
        std::string result {};
        result.reserve(str1.size() + str2.size());

        for (size_t idx1 = 0, idx2 = 0, size1 = str1.size(), size2 = str2.size(); idx1 < size1 || idx2 < size2;)
        {
            if (idx1 < size1 && idx2 < size2)
            {
                result.append(1, str1[idx1++]);
                result.append(1, str2[idx2++]);
            }
            else if (idx1 < size1)
                result.append(1, str1[idx1++]);
            else if (idx2 < size2)
                result.append(1, str2[idx2++]);
        }

        return result;
    }

    void Intersperse_String()
    {
        for (const auto  &[values, expected]: std::vector<std::pair<StringPair, std::string>> {
                {{"12345", "abcde"}, "1a2b3c4d5e"},
                {{"12345", "a"}, "1a2345"},
                {{"", "12345"}, "12345"},
                {{"abcd", ""}, "abcd"},
                {{"123456789", "z9y08regqa57"}, "1z293y40586r7e8g9qa57"},
        })
        {
            const std::string actual = intersperse_strings(values.first, values.second);
            if (expected != actual) {
                std::cerr << expected << " != " << actual << std::endl;
                return;
            }
        }
        std::cout << "OK: All tests passed\n";
    }
}


namespace Strings
{
    int are_anagrams(const std::string_view& str1,
                     const std::string_view& str2)
    {
        if (str1 == str2 || str1.length() != str2.length())
            return 0;

        int chars[256] = { 0 };
        for (char c : str1)
            chars[c]++;
        for (char c : str2)
            if (1 > chars[c]--)
                return 0;
        return 1;
    }

    int count_anagrams(const std::string& input)
    {
        std::vector<std::string_view> words;
        StringUtilities::split_to(input, words, " ");

        int count = 0;
        for (int i = 0; i < words.size(); ++i ){
            for (int n = 0; n < words.size(); ++n)
                count += are_anagrams(words[i], words[n]);
        }

        return count / 2;
    }

    /**
     * Have the function CountingAnagrams(str) take the str parameter and determine how many anagrams exist in the string.
     * An anagram is a new word that is produced from rearranging the characters in a different word,
     * Program should determine how many anagrams exist in a given string and return the total number.
     * For example: if str is "aa aa odg dog gdo" then your program should return 2 because "dog" and "gdo" are
     * anagrams of "odg".
     * The word "aa" occurs twice in the string but it isn't an anagram because it is the same word just repeated.
     * The string will contain only spaces and lowercase letters, no punctuation, numbers, or uppercase letters.
    */
    void Count_Anagrams()
    {
        for (const auto  &[value, expected]: std::vector<std::pair<std::string, int>> {
                {"cars are very cool so are arcs and my os", 2},
                {"a c b c run urn", 1},
                {"aa aa ab ba dog god", 2},
                {"ab ba run run run", 1},
                // {"abcd abdc bcda adbc abbc", 3},

        })
        {
            const int actual = count_anagrams(value);

            std::cout << actual << std::endl;
            if (expected != actual) {
                std::cerr << expected << " != " << actual << std::endl;
                return;
            }
        }
        std::cout << "OK: All tests passed\n";
    }
}


namespace Strings
{
    using namespace std::string_view_literals;

    int roman_to_int(const std::string& str)
    {
        int result = 0;
        for (size_t idx = 0, size = str.size(); idx < str.size(); ++idx)
        {
            const char c = str[idx];
            if ('M' == c)      result += 1000;
            else if ('D' == c) result += 500;
            else if ('C' == c) {
                if (size > idx && str[idx + 1] == 'D') {
                    result += 400;
                    ++idx;
                } else if (size > idx && str[idx + 1] == 'M') {
                    result += 900;
                    ++idx;
                } else {
                    result += 100;
                }
            }
            else if ('L' == c) result += 50;
            else if ('X' == c) {
                if (size > idx && str[idx + 1] == 'L') {
                    result += 40;
                    ++idx;
                } else if (size > idx && str[idx + 1] == 'C') {
                    result += 90;
                    ++idx;
                } else {
                    result += 10;
                }
            }
            else if ('V' == c) result += 5;
            else if ('I' == c) {
                if (size > idx && str[idx + 1] == 'V') {
                    result += 4;
                    ++idx;
                } else if (size > idx && str[idx + 1] == 'X') {
                    result += 9;
                    ++idx;
                } else {
                    result += 1;
                }
            }
        }
        return result;
    }


    void RomanToInt()
    {
        for (const auto  &[roman_num_str, expected]: std::vector<std::pair<std::string, int>> {
                { "LVIII", 58},
                { "MCMXCIV", 1994}
        })
        {
            const int actual = roman_to_int(roman_num_str);
            // std::cout << actual << std::endl;
            if (expected != actual) {
                std::cerr << expected << " != " << actual << std::endl;
                return;
            }
        }
        std::cout << "OK: All tests passed\n";
    }
}

namespace Strings
{
    using namespace std::string_view_literals;

    std::string int_to_roman(int value)
    {
        constexpr std::array<std::pair<std::string_view, u_int16_t>, 14> numerals {{
                                                                                           {"M"sv, 1000}, {"CM"sv, 900}, {"D"sv, 500}, {"CD"sv, 400},
                                                                                           {"C"sv, 100}, {"XC"sv, 90}, {"LX"sv, 60}, {"L"sv, 50},
                                                                                           {"XL"sv, 40}, {"X"sv, 10}, {"IX"sv, 9}, {"V"sv, 5}, {"IV"sv, 4}, {"I"sv, 1}
                                                                                   }};

        std::string result;
        while (value) {
            for (const auto& [ch, val]: numerals) {
                if (value >= val) {
                    value -= val;
                    result.append(ch.data());
                    break;
                }
            }
        }
        return result;
    }

    /**
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
        Symbol       Value
        I             1
        V             5
        X             10
        L             50
        C             100
        D             500
        M             1000

     For example, 2 is written as II in Roman numeral, just two one's added together.
     12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
    */
    void IntToRoman()
    {
        for (const auto  &[roman_number, expected]: std::vector<std::pair<int, std::string>> {
                {110, "CX"},
                {1650, "MDCL"},
                {1994, "MCMXCIV"},
        })
        {
            std::string actual = int_to_roman(roman_number);
            if (expected != actual) {
                std::cerr << expected << " != " << actual << std::endl;
                return;
            }
        }
        std::cout << "OK: All tests passed\n";
    }
}


void StringAlgorithms::Other()
{
    // Strings::AnalogClockAngles();
    // Strings::Atoi();
    // Strings::Atoi_Extended();
    // Strings::StrLen();

    // Strings::ReverseString();
    // Strings::RotateString();

    // Strings::Reverse_Words_in_String();

    // Strings::Contains();

    // Strings::Longest_Word();

    // Strings::Intersperse_String();

    // Strings::RomanToInt();
    // Strings::IntToRoman();

    // Strings::Count_Anagrams();

    // Strings::CheckIfStrings_RotateRotateEquals();

    // Strings::FindCommon_PrefixAndPostfix();

    // Strings::MoveCharsToEnd();
    // Strings::MoveZerosToEnd();
    Strings::Remove_Add_Chars();
    // Strings::RemoveDuplicates();
    // Strings::RemoveCharsOfOneString_FromAnother();

    // Strings::Print_Distinct_SubStrings_Len2();
    // Strings::Print_Distinct_SubStrings();
    // Strings::Print_1_0_Instead_Wildcards();
    // Strings::Print_1_0_Instead_Wildcards_2();

    // Strings::RearrangeString();
    // Strings::RearrangeString_WithNumbers();
    // Strings::RearrangeString_NoAdjacent();

    // Strings::Find_K_MostFrequentCharacter();
    // Strings::Find_K_MostFrequentCharacter_2();
    // Strings::topKFrequent(); /** Find_K_Most_Frequent_Words **/

    // Strings::Find_Last_Not_Of();

    // Strings::Find_First_Char_Occured_Once();
    // Strings::Find_First_K_Chars_Occured_Once();

    // Strings::LongestSubstringWithoutRepeatingCharacters();
    // Strings::LongestSubstringWithoutRepeatingCharacters2();
    // Strings::Find_LongestSubstring_With_K_DistinctCharacters();
    // Strings::MaxSubstringLength_Of_K_max_Unique_Elements();
    // Strings::LongestConsecutiveCharacters();


    // Strings::Palindrome_Test();
    // Strings::Longest_Palindrome_1();
    // Strings::Longest_Palindrome_2();
    // Strings::Find_If_KPalindrome();
    // Strings::ShortestPalindrome();
    // Strings::Find_All_Palindrome_In_String();



    // Strings::FindDuplicateSymbols();
    // Strings::Find_If_String_IsSubstring_OfAnother();
    // Strings::CalcParentheses();
    // Strings::CalcParentheses_3_BRacket();
    // Strings::CalcParentheses_K_Deletions();
    // Strings::Minimum_Length_Substrings();
    // Strings::RotationalCipher();

    // Strings::Permutations();
    // Strings::Permutations2();

    // Strings::CheckIfTwoStringsArePermutation();
    // Strings::AreAnagrams();
    // Strings::MakeAnagrams_CountDeletions();

    // Strings::Minimum_Substring();
}

