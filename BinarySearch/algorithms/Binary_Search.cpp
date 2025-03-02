/**============================================================================
Name        : Binary_Search.cpp
Created on  : 20.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../BinarySearchAlgorithms.h"


namespace
{
    using namespace BinarySearchAlgorithms;

    int binary_search_recursive(const std::vector<int> &numbers,
                                const int left,
                                const int right,
                                const int x) {
        if (right < left)
            return -1;
        // const int mid = left + (right - left) / 2;
        const int mid = left + ((right - left) >> 1);

        if (numbers[mid] == x)
            return mid;
        if (numbers[mid] > x)
            return binary_search_recursive(numbers, left, mid - 1, x);

        return binary_search_recursive(numbers, mid + 1, right, x);
    }

    template<typename T>
    int binary_search(const std::vector<T>& values,
                      const T target)
    {
        size_t left = 0, right = values.size() - 1, idxMid = 0;
        while (right > (left + 1))
        {
            // idxMid = (left + right) / 2;
            idxMid = (left + right) >> 1;
            if (target == values[idxMid])
                return values[idxMid];
            if (values[idxMid] > target)
                right = idxMid;
            else
                left = idxMid;
        }
        return -1;
    }
}

void BinarySearchAlgorithms::Binary_Search()
{
    using TestData = std::vector<std::pair<std::pair<std::vector<int>, int>, int>>;
    for (const auto& [input_data, expected]:  TestData{
            {{{-1,0,3,5,9,12}, 9} , 9 },
            {{{-1,0,3,5,9,12}, 2} , -1 },
    })
    {
        {
            const auto actual = binary_search(input_data.first, input_data.second);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        /*
        {
            const auto actual = binary_search_recursive(input_data.first, 0, input_data.first.size() - 1,
                                                        input_data.second);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        */
    }
    std::cout << "OK: All tests passed\n";
}