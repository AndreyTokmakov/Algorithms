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
                if (it == freq.end()) {   // Ignore characters that are not in the target string.
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

void StringAlgorithms::Other()
{
    // Strings::AnalogClockAngles();
    // Strings::Atoi();
    // Strings::Atoi_Extended();
    // Strings::RotateString();
    // Strings::CheckIfStrings_RotateRotateEquals();
    Strings::Remove_Add_Chars();
    // Strings::Print_Distinct_SubStrings_Len2();
    // Strings::Print_Distinct_SubStrings();
    // Strings::RearrangeString();
    // Strings::RearrangeString_WithNumbers();
    // Strings::RearrangeString_NoAdjacent();
    // Strings::Find_K_MostFrequentCharacter();
    // Strings::Find_K_MostFrequentCharacter_2();
    // Strings::topKFrequent(); /** Find_K_Most_Frequent_Words **/
    // Strings::MaxSubstringLength_Of_K_max_Unique_Elements();
    // Strings::Longest_Palindrome_1();
    // Strings::Longest_Palindrome_2();
    // Strings::Find_If_KPalindrome();
    // Strings::ShortestPalindrome();
    // Strings::Find_All_Palindrome_In_String();
    // Strings::Find_If_String_IsSubstring_OfAnother();
    // Strings::CalcParentheses();
    // Strings::CalcParentheses_3_BRacket();
    // Strings::CalcParentheses_K_Deletions();
    // Strings::Minimum_Length_Substrings();
    // Strings::RotationalCipher();
    // Strings::Permutations();
    // Strings::Permutations2();
    // Strings::AreAnagrams();
    // Strings::MakeAnagrams_CountDeletions();
    // Strings::Minimum_Substring();
}

