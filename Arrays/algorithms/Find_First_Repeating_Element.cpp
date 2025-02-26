/**============================================================================
Name        : Find_First_Repeating_Element.cpp
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

    template<typename T>
    std::optional<T> find_first_repeating_element(const std::vector<T> &data)
    {
        int minIdx = -1;
        std::unordered_set<T> set;
        for (int idx = data.size() - 1; idx >= 0; --idx) {
            if (!set.insert(data[idx]).second)
                minIdx = idx;
        }
        return -1 == minIdx ? std::nullopt : std::make_optional<int>(data[minIdx]);
    }

}

void ArraysAlgorithms::Find_First_Repeating_Element()
{
    using TestData = std::vector< std::pair<std::vector<int>, std::optional<int>> >;
    for (int testCount = 1; const auto& [value, expected]:  TestData{
        { {10, 5, 3, 4, 3, 5, 6} , 5 },
        { {1,2,3} , std::nullopt },
        { {} , std::nullopt },
        { {1,2,3,2,3,1,2,3} , 1},
    })
    {
        const std::optional<int> actual = find_first_repeating_element(value);
        if (expected != actual) {
            std::cerr << "Test failed! number: " << testCount << std::endl;
        }
        ++testCount;
    }
    std::cout << "OK: All tests passed\n";
}
