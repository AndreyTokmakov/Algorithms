/**============================================================================
Name        : Is_Reversed_Equals.cpp
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
    bool _is_reversed_equals(const std::vector<int> &v1, const std::vector<int> &v2)
    {
        if (v1.size() != v2.size())
            return false;
        //std::vector<int>::const_iterator iter2 = v2.end() - 1;  // and --iter2 in FOR loop
        std::vector<int>::const_reverse_iterator iter2 = v2.rbegin();
        for (std::vector<int>::const_iterator iter1 = v1.begin(); v1.end() != iter1; ++iter1, ++iter2) {
            if (*iter1 != *iter2)
                return false;
        }
        return true;
    }

    bool _is_reversed_equals_2(const std::vector<int> &v1, const std::vector<int> &v2)
    {
        const int size = static_cast<int>(v1.size());
        if (size != static_cast<int>(v2.size()))
            return false;

        for (int left = 0, right = size - 1; left < size; ++left, --right) {
            if (v1[left] != v2[right])
                return false;
        }

        return true;
    }
}

void ArraysAlgorithms::Is_Reversed_Equals()
{
    for (const VectorPair<int> &data: std::vector<VectorPair<int>>{
            {{1, 2, 3},                   {3, 2, 1}},
            {{1, 2, 3},                   {3, 2, 2}},
            {{1, 2, 3, 4, 5, 6, 7, 8, 9}, {9, 8, 7, 6, 4, 4, 3, 2, 1}}
    }) {
        std::cout << std::boolalpha
                  << _is_reversed_equals(data.first, data.second) << ' '
                  << _is_reversed_equals_2(data.first, data.second) << ' '
                  << std::equal(data.first.begin(), data.first.end(), data.second.rbegin()) << std::endl;
    }
}