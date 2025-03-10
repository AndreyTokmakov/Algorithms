/**============================================================================
Name        : First_Bad_Version.cpp
Created on  : 10.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../ArraysAlgorithms.h"

/**
You are a product manager and currently leading a team to develop a new product.
Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad.
Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example 1:  Input: n = 5, bad = 4  Output: 4
            Explanation:
            call isBadVersion(3) -> false
            call isBadVersion(5) -> true
            call isBadVersion(4) -> true
            Then 4 is the first bad version.

Example 2:   Input: n = 1, bad = 1 Output: 1

**/

namespace
{
    using namespace ArraysAlgorithms;

    int firstBadVersion { 0 };

    [[nodiscard]]
    bool isBadVersion(const int version)
    {
        return version >= firstBadVersion;
    }

    int find_first_bad_version(const std::vector<int>& values)
    {
        for (int left = 0, right = values.size() - 1, idxMid = 0; right >= left; )
        {
            idxMid = (left + right) >> 1 ;
            if (isBadVersion(values[idxMid]))
            {
                if (isBadVersion(values[idxMid - 1])) {
                    right = idxMid - 1;
                } else {
                    return values[idxMid];
                }
            }
            else {
                left = idxMid + 1;
            }
        }
        return -1;
    }

    // [1,2,3.... N]
    int find_first_bad_version_seq(const int N)
    {
        for (int left = 1, right = N, idxMid = 0; right >= left; )
        {
            idxMid = ((right - left ) >> 1) + left;
            if (isBadVersion(idxMid))
            {
                if (isBadVersion(idxMid - 1)) {
                    right = idxMid - 1;
                } else {
                    return idxMid;
                }
            }
            else {
                left = idxMid + 1;
            }
        }
        return -1;
    }
}

void ArraysAlgorithms::First_Bad_Version()
{

    using TestData1 = std::vector<std::pair<std::pair<std::vector<int>, int>, int>>;
    for (const auto& [values, expected]:  TestData1 {
            { {{1,2,3,4,5,6,7,8,9}, 7} , 7 },
            { {{1,3,5,7,9,11,13,15,17,19}, 11} , 11 },
    })
    {
        firstBadVersion = values.second;
        if (const int actual = find_first_bad_version(values.first); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }

    using TestData2 = std::vector<std::pair<std::pair<int, int>, int>>;
    for (const auto& [values, expected]:  TestData2 {
            { {20, 7} , 7 },
            { {45, 13} , 13 },
    })
    {
        firstBadVersion = values.second;
        if (const int actual = find_first_bad_version_seq(values.first); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }

    std::cout << "OK: All tests passed\n";
}
