/**============================================================================
Name        : Longest_Fibonacci_SubArray.cpp
Created on  : 19.03.2025
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

    int find_fibonacci_subset(const std::vector<int>& values)
    {
        int maxLen = 0;
        for (int pos = 2, len = 0, size = static_cast<int>(values.size()); pos < size; ++pos)
        {
            if ((values[pos - 2] + values[pos - 1]) == values[pos]) {
                len = (0 == len) ? 3 : len + 1;
                maxLen = std::max(maxLen, len);
            } else {
                len = 0;
            }
        }
        return maxLen;
    }
}

void ArraysAlgorithms::Longest_Fibonacci_SubArray()
{

    using TestData = std::vector<std::pair<std::vector<int>, int>>;
    for (const auto& [values, expected]:  TestData {
    { {0, 1, 1, 2, 3, 5, 8, 0, 1, 1, 2, 3, 5, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 8,
                           8, 8, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
                           10946} , 22 },
 { {3, 34, 0, 1, 1, 2, 3, 5, 8, 13, 3, 1343, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 3, 2, 345, 89, 144, 233,
                       377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393} , 16 },
    })
    {
        if (const auto actual = find_fibonacci_subset(values); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}