/**============================================================================
Name        : Maximum_Area_Between_Boundaries.cpp
Created on  : 19.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
 * Problem
 * Given information about the height of a boundary at each position as std::vector<int64_t>,
 * determine the maximum area formed between any two boundaries.
 * The area is the minimum height of the two boundaries multiplied by the distance.
 *
 * Solution:
 * If we switch one of the boundaries, we are decreasing the distance, so the only way to improve
 * the area is to switch the lower of the two boundaries.
 * Switching the higher one decreases the distance without improving the height
 * (because the height is dictated by the lower of the two boundaries).
 * Therefore, to get the maximum, we can repeatedly apply this logic, keeping track of the maximum area as we go.
**/
namespace
{
    using namespace ArraysAlgorithms;

    size_t max_area(const std::vector<long> &height)
    {
        size_t max = 0;
        for (size_t left = 0, right = height.size() - 1, area = 0; left != right;)
        {
            area = std::min(height[left], height[right]) * (right - left);
            max = std::max(max, area);
            if (height[left] <= height[right])
                ++left;
            else
                --right;
        }
        return max;
    }

    long max_area_iter(const std::vector<long> &height)
    {
        auto left = height.begin();
        auto right = std::prev(height.end());
        long max = 0;
        while (left != right) {
            max = std::max(max, std::min(*left, *right) * (right - left));
            if (*left <= *right)
                ++left;
            else
                --right;
        }
        return max;
    }
}

void ArraysAlgorithms::Maximum_Area_Between_Boundaries()
{
    for (const auto &[heights, area_expected]: std::vector<std::pair<std::vector<long>, long>>{
            {{1, 1},                               1},
            {{1, 9, 1},                            2},
            {{1, 3, 3,  1},                        3},
            {{1, 3, 1,  3,  1},                    6},
            {{1, 3, 8,  10, 3, 1},                 9},
            {{1, 3, 8,  8,  3, 1},                 9},
            {{1, 3, 10, 10, 3, 1},                 10},
            {{1, 8, 6,  2,  5, 4,  8 ,3, 7},       49},
            {{1, 2, 5,  3,  2, 12, 1, 3, 7, 8, 2}, 35}
    }) {
        std::cout << max_area(heights) << " " << max_area_iter(heights)
                  << ", Expected: " << area_expected << std::endl;
    }
}