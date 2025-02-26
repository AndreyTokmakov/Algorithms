/**============================================================================
Name        : Find_The_Duplicate_Value.cpp
Created on  : 26.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

#include <numeric>

/// Given an array of length N + 1 that contains the integers 1..n with one duplicate, return the duplicate.
/// All values a unique with exception of the one duplicate
/// Solution should have O(n) time complexity and O(1) space complexity.
namespace
{
    using namespace ArraysAlgorithms;

    int find_duplicate_1(const std::vector<int> &values)
    {
        std::unordered_set<int> uniques;
        uniques.reserve(values.size());
        for (int v: values)
            if (!uniques.emplace(v).second)
                return v;
        return 0;
    }

    // TODO: Works only in case is only ONE duplicate
    //       We know that ARRAY contains 'SIZE - 1' sequential elements starting from number 1 --> sum of that elements
    //       can be found using (N + 1) * N / 2 (where N == SIZE - 1)
    int find_duplicate_2(const std::vector<int> &values)
    {
        const int sum = std::accumulate(values.cbegin(), values.cend(), 0);
        return sum - static_cast<int>((values.size() * (values.size() - 1)) / 2);
    }

    int find_duplicate_3(const std::vector<int> &values)
    {
        int tortoise = values[0], hare = values[0];

        // Advance until the tortoise meets the hare.
        do {
            tortoise = values[tortoise];
            hare = values[values[hare]];
        } while (tortoise != hare);

        // Reset the tortoise and move both one step at a time, until they meet.
        tortoise = values[0];
        while (tortoise != hare) {
            tortoise = values[tortoise];
            hare = values[hare];
        }

        return hare;
    }

    int find_duplicate_4(std::vector<int> &values)
    {
        while (values[0]!=values[values[0]])
            std::swap(values[0],values[values[0]]);
        return values.front();
    }
}

void ArraysAlgorithms::Find_The_Duplicate_Value()
{
    for (auto &[values, expected]: std::vector<std::pair<std::vector<int>, int>>{
            {{1, 1, 2},                      1},
            {{3, 1, 1, 2},                   1},
            {{7, 1, 6, 9, 3, 4, 9, 5, 2, 8}, 9},
            {{5, 1, 2, 3, 4, 5},             5},
            {{1,3,4,2,2},                    2},
            {{3,1,3,4,2},                    3},
    }) {
        std::cout << find_duplicate_1(values) << " | "
                  << find_duplicate_2(values) << " | "
                  << find_duplicate_3(values) << " | "
                  << find_duplicate_4(values) << " | " << expected << std::endl;
    }
}
