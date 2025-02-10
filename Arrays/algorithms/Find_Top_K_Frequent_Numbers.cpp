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
}

void ArraysAlgorithms::Find_Top_K_Frequent_Numbers()
{
    for (const std::pair<std::vector<int>, int>& data: std::vector<std::pair<std::vector<int>, int>> {
            {{1,1,1,2,2,3}, 2} // ==> { 1,2 }
    })
    {
        std::cout << _top_K_Frequent(data.first, data.second) << std::endl;
    }
}