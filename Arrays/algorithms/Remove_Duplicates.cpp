/**============================================================================
Name        : Remove_Duplicates.cpp
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

    template<typename T>
    void removeDuplicates(std::vector<T> &nums)
    {
        std::unordered_set<T> duplicates{};
        size_t pos = 0;
        for (size_t idx = 0; idx < nums.size(); ++idx)
            if (true == duplicates.insert(nums[idx]).second)
                std::swap(nums[pos++], nums[idx]);

        nums.resize(pos);
        nums.shrink_to_fit();
    }
}

void ArraysAlgorithms::Remove_Duplicates()
{
    for (auto& [values, expected]: std::vector<VectorPair<int>> {
            {{}, {}},
            {{3,2,2,3}, {3, 2}},
            {{0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5}, {0, 1, 2, 3, 4, 5}},

    })
    {
        removeDuplicates(values);
        if (values != expected) {
            std::cerr << values << " != " << expected << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}