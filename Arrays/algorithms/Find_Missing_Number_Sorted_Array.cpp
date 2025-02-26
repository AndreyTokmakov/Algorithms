/**============================================================================
Name        : Find_Missing_Number_Sorted_Array.cpp
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

    int find_missing_number_sorted_array(const std::vector<int> &data)
    {
        int left = 0, right = data.size() - 1;
        int mid;
        while ((right - left) > 1) {
            mid = (left + right) / 2;
            if ((data[left] - left) != (data[mid] - mid))
                right = mid;
            else if ((data[right] - right) != (data[mid] - mid))
                left = mid;
        }
        return (left + data[0] + 1);
    }

}

void ArraysAlgorithms::Find_Missing_Number_Sorted_Array()
{
    using TestData = std::vector< std::pair<std::vector<int>, int>>;
    for (const auto& [value, expected]:  TestData{
            { {1, 2, 3, 4, 5, 6, 8} , 7 },
            { {3, 4, 5, 6, 7, 8, 9, 10, 12, 13} , 11 },
    })
    {
        const auto actual = find_missing_number_sorted_array(value);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}