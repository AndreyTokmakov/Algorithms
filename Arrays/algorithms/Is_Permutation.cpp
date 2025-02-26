/**============================================================================
Name        : Is_Permutation.cpp
Created on  : 26.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


namespace
{
    using namespace ArraysAlgorithms;

    bool is_permutation_1(const std::vector<int> &v1,
                          const std::vector<int> &v2)
    {
        if (v1.size() != v2.size())
            return false;
        std::unordered_set<int> set(v1.begin(), v2.end());
        for (int val: v2)
            if (1 != set.erase(val))
                return false;
        return true;
    }

    bool is_permutation_good(const std::vector<int> &v1,
                             const std::vector<int> &v2)
    {
        if (v1.size() != v2.size())
            return false;
        std::unordered_map<int, unsigned int> temp;
        std::for_each(v1.cbegin(), v1.cend(), [&temp](auto v) { ++temp[v]; });
        return std::all_of(v2.cbegin(), v2.cend(), [&temp](auto v) { return (temp[v]--) > 0; });
    }
}

void ArraysAlgorithms::Is_Permutation()
{
    using TestData = std::vector< std::pair<std::pair<std::vector<int>, std::vector<int>>, bool> >;
    for (const auto& [values, expected]:  TestData{
        { {{1, 2, 3, 4, 5}, {3, 4, 1, 2, 5}} , true },
        { {{1, 2, 3, 4, 5}, {3, 4, 2, 2, 5}} , false },
    })
    {
        if (const auto actual = is_permutation_1(values.first, values.second); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = is_permutation_good(values.first, values.second); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}