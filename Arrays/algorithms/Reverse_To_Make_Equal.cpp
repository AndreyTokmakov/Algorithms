/**============================================================================
Name        : Reverse_To_Make_Equal.cpp
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"


namespace
{
    bool _are_reversed_equal(const std::vector<int> &v1,
                             const std::vector<int> &v2)
    {
        if (v1.size() != v2.size())
            return false;
        size_t start = 0, end = v2.size() - 1;

        /* Get first from START different element: */
        for (start = 0; start < v2.size() && v1[start] == v2[start]; start++) {}
        if ((v1.size() - 1) == start)
            return true;
        /* Get first from END different element: */
        for (end = v2.size() - 1; end >= start && v1[end] == v2[end]; end--) {}

        /* Check if */
        for (size_t pos = start, i = 0; pos <= end; pos++, i++) {
            if (v1[pos] != v2[end - i])
                return false;
        }
        return true;
    }
}

void ArraysAlgorithms::Reverse_To_Make_Equal()
{
    {
        const std::vector<int> v1 = {1, 3, 6, 2, 4};
        const std::vector<int> v2 = {1, 2, 6, 3, 4};
        std::cout << std::boolalpha << _are_reversed_equal(v1, v2) << std::endl;
    }
    {
        const std::vector<int> v1 = {1, 5, 6, 7, 4};
        const std::vector<int> v2 = {1, 7, 6, 5, 4};
        std::cout << std::boolalpha << _are_reversed_equal(v1, v2) << std::endl;
    }
}