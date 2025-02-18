/**============================================================================
Name        : Remove_Element.cpp
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
    void remove_element(std::vector<T> &nums,
                        const T value)
    {
        size_t pos = 0;
        for (T &entry: nums)
            if (value != entry)
                std::swap(nums[pos++], entry);

        nums.resize(pos);
        nums.shrink_to_fit();
    }
}

void ArraysAlgorithms::Remove_Element()
{
    /// Format: [ { Input_Values_Vector , Element_to_Delete }, { Result_Values_Vector } ]
    using TestData = std::vector<std::pair<std::pair<std::vector<int>, int>,std::vector<int>>>;
    for (const auto& [input, expected]: TestData {
            {{{ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 }, 2}, { 0, 0, 1, 1, 1, 3, 3, 4}},
            {{{  }, 7}, { }},
            {{{1,1,1  }, 1}, { }},
    })
    {
        std::vector<int> values(input.first);
        const int elementsToRemove = input.second;

        remove_element(values, elementsToRemove);
        if (values != expected) {
            std::cerr << values << " != " << expected << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}