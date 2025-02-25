/**============================================================================
Name        : Container_With_Most_Water.cpp
Created on  : 25.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
You are given an integer array height of length n.
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
**/

namespace
{
    using namespace ArraysAlgorithms;

    int32_t max_area(const std::vector<int32_t>& height)
    {
        int32_t max = 0;
        for (int32_t left = 0, right = height.size() - 1, area = 0; left != right;)
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

}

void ArraysAlgorithms::Container_With_Most_Water()
{
    for (const auto & [heights, expected]: std::vector<std::pair<std::vector<int32_t>, int32_t>>{
            {{1, 1},                               1},
            {{1, 9, 1},                            2},
            {{1, 3, 3,  1},                        3},
            {{1, 3, 1,  3,  1},                    6},
            {{1, 3, 8,  10, 3, 1},                 9},
            {{1, 8, 6, 2, 5, 4, 8, 3, 7},         49},
            {{1, 3, 8,  8,  3, 1},                 9},
            {{1, 3, 10, 10, 3, 1},                 10},
            {{1, 8, 6,  2,  5, 4,  8 ,3, 7},       49},
            {{1, 2, 5,  3,  2, 12, 1, 3, 7, 8, 2}, 35}
    })
    {
        if (const auto actual = max_area(heights); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}