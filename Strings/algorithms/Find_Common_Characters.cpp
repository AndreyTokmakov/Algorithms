/**============================================================================
Name        : Find_Common_Characters.cpp
Created on  : 26.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
Given an array A of strings made only from lowercase letters, return a list of all characters that show up
 in all strings within the list (including duplicates).
For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character
three times in the final answer.
 You may return the answer in any order.
**/

namespace
{
    using namespace StringAlgorithms;

    std::vector<char> find_common_characters_without_duplicates(const std::vector<std::string>& strings)
    {
        std::vector<char> result;
        std::array<int32_t, 'z' - 'a'> chars {};
        for (int n = 0, size = strings.size(); const std::string& str: strings) {
            for (char c: str)
            {
                const char ch = c - 'a';
                if (n == chars[ch]) {
                    ++chars[ch];
                    if (size == chars[ch])
                        result.push_back(ch + 'a');
                }
            }
            ++n;
        }
        return result;
    }

    void find_common_characters(const std::vector<std::string>& strings)
    {
        const size_t size = strings.size();
        std::array<int32_t, 'z' - 'a'> chars {};
        std::vector<std::array<int32_t, 'z' - 'a'>> counters(size);

        for (int n = 0; const std::string& str: strings) {
            for (char c: str) {
                const char ch = c - 'a';
                if (n == chars[ch]) {
                    ++chars[ch];
                }
                ++counters[n][ch];
            }
            ++n;
        }

        // for ()
    }

    std::vector<std::string> commonChars(const std::vector<std::string>& strings)
    {
        const int size = strings.size();
        std::vector<std::vector<int>> cnt(size, std::vector<int>(26, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < (int)strings[i].size(); ++j) {
                ++cnt[i][strings[i][j] - 'a'];
            }
        }
        std::vector<std::string> ret;
        for (int i = 0; i < 26; ++i) {
            int m = std::numeric_limits<int>::max();
            for (int j = 0; j < size; ++j) {
                m = std::min(m, cnt[j][i]);
            }
            for (; m > 0; --m) {
                ret.push_back(std::string(1, 'a' + i));
            }
        }
        return ret;
    }
}

void StringAlgorithms::Find_Common_Characters()
{

    using TestData = std::vector<std::pair<std::vector<std::string>, std::vector<char>>>;
    for (const auto& [values, expected]:  TestData {
            {{"bella","label","roller"},{'e','l','l'}},
    })
    {
        //std::cout << find_common_characters_without_duplicates(values) << std::endl;
        find_common_characters(values);
    }
    std::cout << "OK: All tests passed\n";

}

