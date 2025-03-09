/**============================================================================
Name        : Kadane_Algorithm.cpp
Created on  : 09.03.2025
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

    void kadane_demo(const std::vector<int>& values)
    {
        std::vector<int> sums(values);
        for (size_t idx = 1; idx < sums.size(); ++idx)
            sums[idx] = std::max(sums[idx - 1] + values[idx], values[idx]);
        std::cout << sums << std::endl;
    }

    void kadane_demo_2(const std::vector<int>& values)
    {
        int maxSum = values.front();
        for (int index = 1, max_before = maxSum, size = static_cast<int>(values.size()); index < size; index++) {
            max_before = std::max(max_before + values[index], values[index]);
            maxSum = std::max(maxSum, max_before);
        }
        std::cout << "max = " << maxSum << std::endl;
    }
}

void ArraysAlgorithms::Kadane_Algorithm()
{
    const std::vector<int> value {1, -3, 2, 1, -1, 2};
    kadane_demo(value);
    kadane_demo_2(value);
}
