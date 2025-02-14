/**============================================================================
Name        : Top_K_Frequent_Words.cpp
Created on  : 14.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
**/

namespace
{
    using namespace StringAlgorithms;

    std::vector<std::string> _top_K_Frequent(const std::vector<std::string>& words,
                                         int k)
    {
        std::unordered_map<std::string, uint32_t> wordsCount;
        for (const std::string& s: words)
            ++wordsCount[s];

        std::map<uint32_t, std::vector<std::string>> result;
        for (const auto& [str, v]: wordsCount)
            result[v].push_back(str);

        std::vector<std::string> out;
        out.reserve(k);
        for (auto iter = result.rbegin(); result.rend() != iter; ++iter) {
            std::sort(iter->second.begin(), iter->second.end());
            for (auto &&s: iter->second) {
                out.push_back(std::move(s));
                if (--k == 0)
                    return out;
            }
        }
        return out;
    }
}

void StringAlgorithms::Top_K_Frequent_Words()
{
    const std::vector<std::string> words {"i", "love", "leetcode", "i", "love", "coding"};
    std::vector<std::string> result = _top_K_Frequent(words, 3);
    std::cout << result << std::endl;
}