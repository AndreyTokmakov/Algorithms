/**============================================================================
Name        : Find_K_Most_Frequent_Character.cpp
Created on  : 23.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"
#include <queue>
#include <bits/ranges_algo.h>


namespace
{
    using namespace StringAlgorithms;

    auto comparator = [](const std::pair<char, uint32_t>& a, const std::pair<char, uint32_t>& b) {
        return a.second > b.second ;
    };

    std::vector<char> find_K_most_frequent_symbols_heap(const std::string& str,
                                                        size_t K)
    {   /** Size (256) and type (uint32_t) can be reduced  **/
        uint32_t chars[256] = {0};
        for (const char c: str)
            chars[c]++;

        std::vector<std::pair<char, uint32_t>> freqSymbolsMinHeap(K);
        for (uint32_t idx = 0; idx < std::size(chars); ++idx)
        {
            if (chars[idx] && chars[idx] > freqSymbolsMinHeap.front().second) {
                freqSymbolsMinHeap.front() =  { static_cast<char>(idx), chars[idx] };
                std::make_heap(freqSymbolsMinHeap.begin(), freqSymbolsMinHeap.end(), comparator);
            }
        }

        std::vector<char> result(K);
        for (uint32_t idx = 0; idx < K; ++idx)
            result[idx] = freqSymbolsMinHeap[idx].first;
        return result;
    }

    void find_K_most_frequent_symbols_2(const std::string& str,
                                        size_t K)
    {
        std::multimap<int, char, std::greater<>> dict;
        {
            size_t chars[256] = {0};
            for (const char c: str)
                chars[c]++;
            for (int i = 0; i < std::ssize(chars); i++) {
                if (chars[i])
                    dict.emplace(chars[i], i);
            }
        }
        for (const auto &[k, v]: dict) {
            std::cout << k << " = " << v << std::endl;
            if (0 == (--K))
                break;
        }
    }

}

void StringAlgorithms::Find_K_Most_Frequent_Character()
{
    const std::string str {" abcdefge"};
    constexpr uint32_t K {2};

    std::cout << find_K_most_frequent_symbols_heap(str, K) << std::endl<< std::endl;
    find_K_most_frequent_symbols_2(str, K);
}