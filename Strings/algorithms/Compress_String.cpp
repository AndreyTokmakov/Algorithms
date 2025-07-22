/**============================================================================
Name        : Compress_String.cpp
Created on  : 12.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
Implement a method to perform basic string compression using the counts of repeated characters.
For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not
become smaller than the original string, your method should return the original string.
You can assume the string has only uppercase and lowercase letters (a - z).

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.

Example 1: Input: "aabcccccaaa"  Output: "a2bc5a3"
Example 2: Input: "abc"          Output: "abc"

*/

namespace
{
    using namespace StringAlgorithms;

    std::string compress_string(const std::string& input)
    {
        if (1 >= input.size())
            return input;

        size_t len = 1;
        std::string compressed(1, input.front());
        for (size_t idx = 1, size = input.size(); idx < size; ++idx)
        {
            if (compressed.back() == input[idx])
                ++len;
            else {
                if (len > 1)
                    compressed.append(std::to_string(len));
                compressed.append(1, input[idx]);
                len = 1;
            }
        }
        if (len > 1)
            compressed.append(std::to_string(len));
        return compressed;
    }

    void compress_string_inplace(std::string& input)
    {
        if (input.empty() && input.size() == 1)
            return;

        size_t lenTotal = 1, len = 1;
        for (size_t idx = 1, pos = 1, size = input.size(); idx < size; ++idx)
        {
            //std::cout << "[" << idx - 1 << "] (" << input[idx - 1] <<") = ? = "
            //    <<  "[" << idx << "] (" << input[idx ] <<") | ";
            if (input[idx - 1] == input[idx]) {
                ++len;
            }
            else {
                if (len > 1) {
                    for (const char c: std::to_string(len))
                    {
                        input[pos++] = c;
                        ++lenTotal;
                    }
                }
                input[pos++] = input[idx];
                ++lenTotal;
                len = 1;
            }
            //std::cout << "idx: " << idx << ", pos: " << pos << ", len: " << len
            //    << ", lenTotal: " << lenTotal << " | " << input<< std::endl;
        }
        input.resize(lenTotal);
        if (len > 1)
        {
            input.append(std::to_string(len));
        }
    }

}

void StringAlgorithms::Compress_String()
{
    using TestData = std::vector<std::pair<std::string, std::string>>;
    for (const auto& [input, expected]:  TestData{
        { "aabcccccaaa" , "a2bc5a3" },
        { "abc" , "abc" },
        { "aaab" , "a3b" },
        { "aaabbbbccc" , "a3b4c3" },
        { "aabbccc" , "a2b2c3" },
        { "abc" , "abc" },
        { "" , "" },
    })
    {
        if (const auto actual = compress_string(input); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }

        std::string compressed(input);
        compress_string_inplace(compressed);
        if (expected != compressed) {
            std::cerr << std::boolalpha << expected << " != " << expected << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
