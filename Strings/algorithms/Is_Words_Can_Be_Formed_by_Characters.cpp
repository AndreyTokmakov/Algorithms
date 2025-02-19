/**============================================================================
Name        : Is_Words_Can_Be_Formed_by_Characters.cpp
Created on  : 19.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each charactercan only be used once).
Return the sum of lengths of all good strings in words.
Example 1: Input: words = ["cat","bt","hat","tree"], chars = "atach"    --> Output: 6
           Explanation:The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2: Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"  --> Output: 10
           Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
**/
namespace
{
    using namespace StringAlgorithms;

    int length_of_words_can_be_formed_from_chars(const std::vector<std::string>& words,
                                                 const std::string& chars)
    {
        const std::array<int, 256> mask = [&] {
            std::array<int, 256> tmp {};
            for (const char ch: chars)
                ++tmp[ch];
            return tmp;
        }();

        int result = 0;
        std::array<int, 256> wordChars {};
        for (const std::string& word: words)
        {
            std::fill(wordChars.begin(), wordChars.end(), 0);
            for (const char ch: word)
                ++wordChars[ch];

            bool valid { true };
            for (const char ch: word) {
                if (wordChars[ch] > mask[ch]) {
                    valid = false;
                    break;
                }
            }

            result += valid ? word.size() : 0;
        }

        return result;
    }

}

void StringAlgorithms::Is_Words_Can_Be_Formed_by_Characters()
{
    using TestData = std::vector<std::pair<std::pair<std::vector<std::string>, std::string>, int>>;
    for (const auto& [value, expected]:  TestData{
        { {{"cat","bt","hat","tree"}, "atach"} , 6 },
        { {{"hello","world","leetcode"}, "welldonehoneyr"} , 10 },
    })
    {
        const auto actual = length_of_words_can_be_formed_from_chars(value.first, value.second);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}