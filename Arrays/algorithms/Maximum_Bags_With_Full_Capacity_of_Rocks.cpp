/**============================================================================
Name        : Maximum_Bags_With_Full_Capacity_of_Rocks.cpp
Created on  : 18.06.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
 * Problem
 * You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays capacity and rocks.
 * The ith bag can hold a maximum of capacity[i] rocks and currently contains rocks[i] rocks.
 * You are also given an integer additionalRocks, the number of additional rocks you can place in any of the bags.
 * Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.
 *
 * Example 1:
 *      Input: capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
 *      Output: 3
 *      Explanation:
 *      Place 1 rock in bag 0 and 1 rock in bag 1.
 *      The number of rocks in each bag are now [2,3,4,4].
 *      Bags 0, 1, and 2 have full capacity.
 *      There are 3 bags at full capacity, so we return 3.
 *      It can be shown that it is not possible to have more than 3 bags at full capacity.
 *      Note that there may be other ways of placing the rocks that result in an answer of 3.
 *
 * Example 2:
 *      Input: capacity = [10,2,2], rocks = [2,2,0], additionalRocks = 100
 *      Output: 3
 *      Explanation:
 *      Place 8 rocks in bag 0 and 2 rocks in bag 2.
 *      The number of rocks in each bag are now [10,2,2].
 *      Bags 0, 1, and 2 have full capacity.
 *      There are 3 bags at full capacity, so we return 3.
 *      It can be shown that it is not possible to have more than 3 bags at full capacity.
 *      Note that we did not use all of the additional rocks.
**/
namespace
{
    int count_bags(const std::vector<int>& capacity,
                   const std::vector<int>& rocks,
                   int additionalRocks)
    {
        std::vector<int> bags(capacity.size());
        for (int idx = 0; idx < capacity.size(); ++idx) {
            bags[idx] = capacity[idx] - rocks[idx];
        }

        std::sort(bags.begin(), bags.end());

        int count = 0;
        for (int idx = 0, tmp = 0; idx < capacity.size() && additionalRocks > 0; ++idx) {
            tmp = std::min (bags[idx], additionalRocks);
            count+= (tmp == bags[idx]);
            additionalRocks -= tmp;
        }

        return count;
    }

    int count_bags2(const std::vector<int>& capacity,
                    const std::vector<int>& rocks,
                    int additionalRocks)
    {
        std::vector<int> bags(capacity.size());
        for (int idx = 0; idx < capacity.size(); ++idx) {
            bags[idx] = capacity[idx] - rocks[idx];
        }

        std::sort(bags.begin(), bags.end());

        int count = 0;
        for (int n: bags) {
            if (n > additionalRocks)
                break;
            additionalRocks -= n;
            ++count;
        }

        return count;
    }
}

void ArraysAlgorithms::Maximum_Bags_With_Full_Capacity_of_Rocks()
{
    using InputData = std::tuple<std::vector<int>, std::vector<int>, int>;

    for (const auto &[data, expected]: std::vector<std::pair<InputData, int>>{
            {{ {2,3,4,5}, {1,2,4,4}, 2 },3},
            {{ {10,2,2}, {2,2,0}, 100 },3},
    }) {

        const auto actual = count_bags2(std::get<0>(data), std::get<1>(data), std::get<2>(data));
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
}