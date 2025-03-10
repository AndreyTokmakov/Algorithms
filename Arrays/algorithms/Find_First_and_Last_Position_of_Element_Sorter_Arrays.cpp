/**============================================================================
Name        : Find_First_and_Last_Position_of_Element_Sorter_Arrays.cpp
Created on  : 02.03.2025
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

    std::pair<int, int> find_indexes(const std::vector<int>& values,
                                     const int target)
    {
        const int idx = binary_search(values, target);
        if (-1 == idx)
            return {-1, -1};

        int left = idx, right = idx;
        while (left > 0 && values[left - 1] == target) { --left; }
        while (values.size() - 2 > right && values[right + 1] == target) { ++right; }

        return {left, right};
    }
}

void ArraysAlgorithms::Find_First_and_Last_Position_of_Element_Sorter_Arrays()
{
    using TestData = std::vector< std::pair< std::pair<std::vector<int>, int>, std::pair<int,int>>>;
    for (const auto& [values, expected]:  TestData {
            { {{1,1,1,1,1},2 } , {-1, -1} },
            { {{1,1,1,2,1,1},2 } , {3, 3} },
            { {{1,1,2,2,3,3},2 } , {2, 3} },
            { {{1,1,1,1,1,1,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4},2 } , {6, 9} },
    })
    {
        const auto actual = find_indexes(values.first, values.second);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}