/**============================================================================
Name        : Merge_Intervals.cpp
Created on  : 05.11.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**  Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array
of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Example 3:

    Input: intervals = [[4,7],[1,4]]
    Output: [[1,7]]
    Explanation: Intervals [1,4] and [4,7] are considered overlapping.
*/

namespace
{
    std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p)
    {
        return os << '[' << p.first << ',' << p.second << ']';
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
    {
        for (const auto& e: v)
            os << e << ' ';
        return os;
    }
}

namespace
{
    using Interval = std::pair<int, int>;

    std::vector<Interval> merge(std::vector<Interval>& intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        std::vector<Interval> result;

        result.push_back(intervals.front());
        for (uint32_t idx = 1, len = intervals.size(); idx < len; ++idx) {
            Interval& curr = result.back();
            const Interval& next = intervals[idx];
            if (curr.second >= next.first) {
                curr.second = std::max(curr.second, next.second);
            } else {
                result.push_back(next);
            }
        }
        return result;
    }
}

namespace test2
{
    using Interval = std::vector<int>;

    std::ostream& operator<<(std::ostream& os, const Interval& p)
    {
        return os << '[' << p.front() << ',' << p.back() << ']';
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
    {
        for (const auto& e: v)
            os << e << ' ';
        return os;
    }

    std::vector<Interval> merge(std::vector<Interval>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.front() < b.front();
        });
        std::vector<Interval> result;

        result.push_back(intervals.front());
        for (uint32_t idx = 1, len = intervals.size(); idx < len; ++idx) {
            Interval& curr = result.back();
            const Interval& next = intervals[idx];
            if (curr.back() >= next.front()) {
                curr.back() = std::max(curr.back(), next.back());
            } else {
                result.push_back(next);
            }
        }
        return result;
    }

    void test()
    {
        std::vector<Interval> intervals {{15, 18}, {8, 10}, {1, 3}, {2, 6} };
        std::cout << merge(intervals) << std::endl;
    }
}

void ArraysAlgorithms::Merge_Intervals()
{
    {
        std::vector<Interval> intervals {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        std::cout << merge(intervals) << std::endl;
    }
    {
        std::vector<Interval> intervals {{1, 4}, {4, 5}};
        std::cout << merge(intervals) << std::endl;
    }
    {
        std::vector<Interval> intervals {{4,7}, {1,4}};
        std::cout << merge(intervals) << std::endl;
    }

    test2::test();
}