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
        for (int left = 0, right = values.size() - 1, idxMid = 0; right >= left; )
        {
            idxMid = (left + right) >> 1 ;
            if (values[idxMid] > target)
                right = idxMid - 1; /** we have checked 'idxMid' above (and its greater than 'target') **/
            else if (values[idxMid] < target)
                left = idxMid + 1;
            else
                return idxMid;
        }
        return -1;
    }
}

void BinarySearchAlgorithms::Binary_Search()
{
    using TestData = std::vector<std::pair<std::pair<std::vector<int>, int>, int>>;
    for (const auto& [input_data, expected]:  TestData{
            {{{-1,0,3,5,9,12}, 9} , 4 },
            {{{-1,0,3,5,9,12}, 2} , -1 },
            {{{2,5}, 2} , 0 },
            {{{2}, 2} , 0 },
    })
    {
        {
            if (const auto actual = binary_search(input_data.first, input_data.second); expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        /*
        {
            const auto actual = binary_search_recursive(input_data.first, 0, input_data.first.size() - 1,
                z                                       input_data.second);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        */
    }
    std::cout << "OK: All tests passed\n";
}