/**============================================================================
Name        : Unique_Permutations.cpp
Created on  : 28.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


/** Given a collection of numbers that might contain duplicates, return all possible unique permutations.
    Input: [1,1,2]  Output: [1,1,2], [1,2,1], [2,1,1]
**/

namespace
{
    using namespace ArraysAlgorithms;

    std::vector<std::vector<int>> permuteUnique(std::vector<int>& input)
    {
        int n = input.size();
        if (n <= 1)
            return { input };
        std::set<std::vector<int>> permuted, sret;
        for (int i = 0; i < n; ++i)
        {
            int cur = input[i];
            std::swap(input[i], input[n - 1]);
            input.pop_back();
            if (permuted.count(input) > 0) {
                input.push_back(cur);
                std::swap(input[i], input[n - 1]);
                continue;
            }
            permuted.insert(input);
            std::vector<std::vector<int>> sub = permuteUnique(input);
            for (auto& s : sub) {
                s.push_back(cur);
                sret.insert(s);
            }
            input.push_back(cur);
            std::swap(input[i], input[n - 1]);
        }
        std::vector<std::vector<int>> ret(sret.begin(), sret.end());
        return ret;
    }
}

void ArraysAlgorithms::Unique_Permutations()
{
    std::vector<int> input {1, 1 ,2};
    const std::vector<std::vector<int>> result = permuteUnique(input);


    for (const auto& sub_set: result) {
        std::cout << "[" << sub_set << " ]\n";
    }
}