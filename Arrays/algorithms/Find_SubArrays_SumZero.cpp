/**============================================================================
Name        : Find_SubArrays_SumZero.cpp
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
    void _find_subArrays_sum_zero_SLOW(const std::vector<int> &Numeric)
    {
        for (size_t i = 0; i < Numeric.size(); i++) {
            for (size_t n = i, sum = 0; n < Numeric.size(); n++) {
                sum += Numeric[n];
                if (0 == sum) {
                    std::cout << "Subarray [" << i << ".." << n << "]" << std::endl;
                }
            }
        }
    }

    void _find_subArrays_sum_zero(const std::vector<int>& values)
    {
        std::unordered_multimap<int, int> map = {{0, -1}};
        for (int idx = 0, sum = 0, size = values.size(); idx < size; ++idx)
        {
            sum += values[idx];

            // As soon as we meet sum in the map, it means that there is at least one subarray with
            // the sum 0. And the beginning of this list (lists) has a second index in the map
            if (auto iter = map.find(sum); map.end() != iter) {
                while (iter != map.end() && iter->first == static_cast<int>(sum)) {
                    std::cout << "Subarray [" << iter->second + 1 << ".." << idx << "]" << std::endl;
                    ++iter;
                }
            }
            map.insert({sum, idx});
        }
    }
}

void ArraysAlgorithms::Find_SubArrays_SumZero()
{
    // const std::vector<int> Numeric = { 3,4,-7,3,1,3,1,-4,-2,-2};
    const std::vector<int> Numeric = {1, 3, 2, -5, 3};
    _find_subArrays_sum_zero(Numeric);
    std::cout << std::endl;
    _find_subArrays_sum_zero_SLOW(Numeric);
}
