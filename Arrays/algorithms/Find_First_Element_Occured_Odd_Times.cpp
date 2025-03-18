/**============================================================================
Name        : Find_First_Element_Occured_Odd_Times.cpp
Created on  : 16.03.2025
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

    std::optional<int> find_first_element_occurred_odd_times(const std::vector<int> &data)
    {
        std::unordered_map<int, size_t> map;
        for (int val: data)
            ++map[val];

        for (int val: data)
            if (0 != map[val] % 2)
                return val;

        return std::nullopt;
    }

    std::optional<int> find_first_element_occurred_odd_times_set(const std::vector<int> &data)
    {
        std::unordered_set<int> set;
        for (int val: data) {
            if (auto [iter, inserted] = set.insert(val); false == inserted)
                set.erase(iter);
        }

        for (int val: data) {
            if (set.contains(val))
                return val;
        }

        return std::nullopt;
    }

    int single_number(const std::vector<int>& nums)
    {
        int singleNum = 0;
        for (const int num : nums) {
            singleNum ^= num;
        }
        return singleNum;
    }
}

void ArraysAlgorithms::Find_First_Element_Occured_Odd_Times()
{
    using TestData = std::vector<std::pair<std::vector<int>, std::optional<int>>>;
    for (const auto& [values, expected]:  TestData {
        {{1, 2, 3, 2},                         1  },
        {{1, 1, 1, 1},                         std::nullopt },
        {{1, 2, 1, 2},                         std::nullopt },
        {{1, 2, 3, 4, 5, 1, 2, 3, 4, 5},       std::nullopt },
        {{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 4, 5}, 4  },
        {{1, 2, 3, 5, 4, 1, 2, 3, 4, 5, 4, 5}, 5  },
        {{1,7,2,3,4,7,5,1,2,3,4,9,5 }, 9  },
    })
    {
        {
            const auto actual = find_first_element_occurred_odd_times(values);
            if (actual.has_value() != expected.has_value() || expected.value_or(0) != actual.value_or(0)) {
                error();
            }
        }
        {
            const auto actual = find_first_element_occurred_odd_times_set(values);
            if (actual.has_value() != expected.has_value() || expected.value_or(0) != actual.value_or(0)) {
                error();
            }
        }
    }
    std::cout << "OK: All tests passed\n";
}