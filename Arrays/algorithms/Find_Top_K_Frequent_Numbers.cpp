/**============================================================================
Name        : Find_Top_K_Frequent_Numbers.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


namespace
{
    std::vector<int> _top_K_Frequent(const std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> counter;
        for (int v: nums)
            ++counter[v];

        std::map<int, std::vector<int>> freqs;
        for (const auto [val, N]: counter)
            freqs[N].emplace_back(val);

        std::vector<int> out;
        out.reserve(k);
        for (auto iter = freqs.rbegin(); freqs.rend() != iter; ++iter) {
            std::sort(iter->second.begin(), iter->second.end());
            for (auto &&s: iter->second) {
                out.push_back(s);
                if (--k == 0)
                    return out;
            }
        }
        return out;
    }

    auto comparator = [](const std::pair<int32_t, uint32_t>& a, const std::pair<int32_t, uint32_t>& b) {
        return a.second > b.second ;
    };

    std::vector<int32_t> top_K_frequent_good(const std::vector<int32_t>& nums, const int K)
    {
        std::unordered_map<int32_t, uint32_t> counter;
        for (const int v: nums)
            ++counter[v];

        std::vector<std::pair<int32_t, uint32_t>> freqNumsMinHeap(K);
        for (const auto [number, seenCount]: counter) {
            if (seenCount > freqNumsMinHeap.front().second) {
                freqNumsMinHeap.front() =  { number, seenCount };
                std::make_heap(freqNumsMinHeap.begin(), freqNumsMinHeap.end(), comparator);
            }
        }

        std::vector<int32_t> result(K);
        for (uint32_t idx = 0; idx < K; ++idx)
            result[idx] = freqNumsMinHeap[idx].first;
        return result;
    }
}

void ArraysAlgorithms::Find_Top_K_Frequent_Numbers()
{
    // TODO: Fix tests (remove std::cout && add asserts)
    for (const std::pair<std::vector<int>, int>& data: std::vector<std::pair<std::vector<int>, int>> {
            {{1,1,1,2,2,3}, 2}, // ==> { 1,2 }
            {{1,1,1,2,2,3,4,5,4,4}, 3} // ==> { 1,2, 4 }
    })
    {
        std::cout << _top_K_Frequent(data.first, data.second) << std::endl;
        std::cout << top_K_frequent_good(data.first, data.second) << std::endl;
    }
}