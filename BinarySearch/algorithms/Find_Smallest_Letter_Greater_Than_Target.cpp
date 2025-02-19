/**============================================================================
Name        : Find_Smallest_Letter_Greater_Than_Target.cpp
Created on  : 19.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../BinarySearchAlgorithms.h"


/**
Given a list of sorted characters letters containing only lowercase letters, and
given a target letter target, find the smallest element in the list that is
larger than the given target.
Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
Examples:
Input: letters = ["c", "f", "j"] target = "a" Output: "c"
Input: letters = ["c", "f", "j"] target = "c" Output: "f"
Input: letters = ["c", "f", "j"] target = "d" Output: "f"
Input: letters = ["c", "f", "j"] target = "g" Output: "j"

**/

namespace
{
    using namespace BinarySearchAlgorithms;

    char nextGreatestLetter(const std::vector<char>& letters,
                            const char target)
    {
        int n = letters.size();
        int lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] <= target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return letters[lo % n];
    }
}


void BinarySearchAlgorithms::Find_Smallest_Letter_Greater_Than_Target()
{
    using TestData = std::vector<std::pair< std::pair<std::vector<char>, char>, char> >;
    for (const auto& [value, expected]:  TestData{
        { { {'c', 'f', 'j'}, 'a'} , 'c' },
        { { {'c', 'f', 'j'}, 'c'} , 'f' },
        { { {'c', 'f', 'j'}, 'd'} , 'f' },
    })
    {
        const auto actual = nextGreatestLetter(value.first, value.second);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}