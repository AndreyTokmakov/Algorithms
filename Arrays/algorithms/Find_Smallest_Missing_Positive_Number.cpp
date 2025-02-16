/**============================================================================
Name        : Find_Smallest_Missing_Positive_Number.cpp
Created on  : 15.01.2025
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
    int smallest_missingPositive_number(const std::vector<int> &A)
    {
        const auto minmax = std::minmax_element(A.begin(), A.end());
        int min = *minmax.first, max = *minmax.second;
        if (1 > max || min > 1)
            return 1;

        std::unordered_set<int> set(A.begin(), A.end());
        for (int i = std::max(1, min); i < max; i++)
            if (set.end() == set.find(i))
                return i;

        return max + 1;
    }

    int smallest_missingPositive_number_2(const std::vector<int> &A)
    {
        std::unordered_set<int> set;
        int min = std::numeric_limits<int>::max(), max = std::numeric_limits<int>::min();
        for (int i: A) {
            if (i > max)
                max = i;
            if (min > i)
                min = i;
            if (i > 0)
                set.insert(i);
        }
        if (1 > max || min > 1)
            return 1;

        for (int i = std::max(1, min); i < max; i++)
            if (set.end() == set.find(i))
                return i;

        return max + 1;
    }

    int smallest_missingPositive_number_3(std::vector<int> nums)
    {
        const int size = static_cast<int>(nums.size());
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        for (int i = 0; i < size; ++i)
            while (nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1])
                std::swap(nums[i], nums[nums[i] - 1]);

        for (int i = 0; i < size; ++i)
            if (nums[i] != i + 1)
                return i + 1;

        return size + 1;
    }
}

void ArraysAlgorithms::Find_Smallest_Missing_Positive_Number()
{
    for (const std::vector<int> &numbers: std::vector<std::vector<int>>{
            {-1,      0, 1},
            {1,       3, 6,       4, 1, 2},
            {3,       4, 5,       6},
            {-999999, 4, 9999999, 6}
    }) {
        std::cout << smallest_missingPositive_number(numbers) << " "
                  << smallest_missingPositive_number_2(numbers) << " "
                  << smallest_missingPositive_number_3(numbers)
                  << std::endl;
    }
}
