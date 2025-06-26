/**============================================================================
Name        : Calculate_Max_Hotel_Visitors.cpp
Created on  : 19.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
Visitors check into a hotel, stay there for a while, and check out
The entry for this looks like [check-in day, check-out day]
We need to calculate the maximum number of visitors staying at the hotel at the same time
**/

namespace
{
    using namespace ArraysAlgorithms;

    int calc_max_hotel_visitors(const std::vector<std::pair<int, int>>& intervals)
    {
        int maxVisitors = 0;
        std::unordered_map<int, int> dailyVisitors {};
        for (auto [checkIn, checkOut]: intervals) {
            for (/** **/; checkIn <= checkOut; ++checkIn) {
                maxVisitors = std::max(maxVisitors, ++dailyVisitors[checkIn]);
            }
        }
        return maxVisitors;
    }
}

void ArraysAlgorithms::Calculate_Max_Hotel_Visitors()
{
    using TestData = std::vector< std::pair<std::vector<std::pair<int, int>>, int>>;
    for (const auto& [value, expected]:  TestData{
            { {{1, 2},{1, 2}} , 2 },
            { {{1, 2},{3, 4}, {2,3}} , 2 },
            { {{1, 3},{6, 8}, {3,6}} , 2 },
            { {{1, 3},{6, 8}, {3,6}, {4,7}} , 3 },
    })
    {
        const auto actual = calc_max_hotel_visitors(value);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
