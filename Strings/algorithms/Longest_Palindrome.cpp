/**============================================================================
Name        : Longest_Palindrome.cpp
Created on  : 05.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"


namespace
{
    using namespace StringAlgorithms;

    size_t palindrome_length(const std::string &str,
                             size_t start,
                             size_t end)
    {
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

    // Same as: palindrome_length
    size_t palindrome_length_2(const std::string &str,
                               size_t start,
                               size_t end)
    {
        size_t length = 0;
        while (start >= 0 && end < str.size() &&
               str[start--] == str[end++]) {
            length = end - start - 1;
        }
        return length;
    }

    std::string longest_palindrome(const std::string &str)
    {
        size_t start = 0, end = 0;
        if (str.empty())
            return "";

        size_t len1 = 0, len2 = 0;
        for (size_t center = 0; center < str.size(); center++)
        {
            len1 = palindrome_length(str, center, center);
            len2 = palindrome_length(str, center, center + 1);
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
}

void StringAlgorithms::Longest_Palindrome()
{
    using TestData = std::vector<std::pair<std::string, std::string>>;
    for (const auto& [input_string, expected]: TestData {
            {"babad",           "aba"},
            {"cbbd",            "bb"},
            {"ddddd3456654321", "34566543"}
    })
    {
        const auto actual = longest_palindrome(input_string);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}