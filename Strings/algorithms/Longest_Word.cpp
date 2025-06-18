/**============================================================================
Name        : Find_Longest_Word.cpp
Created on  : 20.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"
#include "StringUtilities.h"

namespace
{
    using namespace StringAlgorithms;

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
}

void StringAlgorithms::Longest_Word()
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