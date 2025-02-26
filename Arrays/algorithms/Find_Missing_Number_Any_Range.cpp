/**============================================================================
Name        : Find_Missing_Number_Any_Range.cpp
Created on  : 26.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

#include <numeric>
#include <ranges>

namespace
{
    using namespace ArraysAlgorithms;

    int find_missing_element(const std::vector<int>& values)
    {
        int sum = 1, min = std::numeric_limits<int>::max();

        // Loop to determine min value in the given array and
        // sum will keep value of the missing element in suggestion that
        // array has elements from (1 ... till ... length)
        for (size_t index = 2; index < (values.size() + 2); index++) {
            sum += (index - values[index - 2]);
            min = std::min(min, values[index - 2]);
        }
        return (sum + (min - 1) * (values.size() + 1));
    }

    int find_missing_element_2(const std::vector<int>& values)
    {
        int sum = 0, min = std::numeric_limits<int>::max();
        for (int v: values) {
            sum += v;
            min = std::min(min, v);
        }

        const int diff = ((values.size() + 1) * (values.size() + 2)) / 2 - sum;
        return (diff + (min - 1) * (values.size() + 1));
    }

    int find_missing_element_3(const std::vector<int>& values)
    {
        auto min = *std::min_element(values.begin(), values.end());
        auto sum = std::accumulate(values.begin(), values.end(), 0);

        int diff = ((values.size() + 1) * (values.size() + 2)) / 2 - sum;
        return (diff + (min - 1) * (values.size() + 1));
    }
}

void ArraysAlgorithms::Find_Missing_Number_Any_Range()
{
    using TestData = std::vector< std::pair<std::vector<int>, int> >;
    for (const auto& [value, expected]:  TestData{
        { {1, 2, 3, 5} , 4 },
        { {4, 5, 6, 7, 8, 9, 11, 12} , 10 },
    })
    {

        if (const auto actual = find_missing_element(value); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = find_missing_element_2(value); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = find_missing_element_3(value); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}