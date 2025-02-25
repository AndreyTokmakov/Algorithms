/**============================================================================
Name        : Jewels_and_Stones.cpp
Created on  : 25.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.
Each character in S is a type of stone you have.
You want to know how many of the stones you have are also jewels.
The letters in J are guaranteed distinct, and all characters in J and S are letters.
Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1: Input: J = "aA", S = "aAAbbbb" Output: 3
Example 2: Input: J = "z", S = "ZZ"       Output: 0

Note:
S and J will consist of letters and have length at most 50. The characters in J are distinct.
**/
namespace
{
    using namespace StringAlgorithms;

    int count_jewels(const std::string& jewels,
                     const std::string& stones) {
        int ret = 0, chars[128] = {0};
        for (const char& jch : jewels) {
            ++chars[jch];
        }
        for (const char& stone :  stones) {
            ret += chars[stone];
        }
        return ret;
    }

}

void StringAlgorithms::Jewels_and_Stones()
{

    using TestData = std::vector<std::pair<std::pair<std::string, std::string>, int32_t> >;
    for (const auto& [value, expected]:  TestData{
        { {"aA", "aAAbbbb"} , 3 },
        { {"z", "ZZ"} , 0 },
    })
    {
        const auto actual = count_jewels(value.first, value.second);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}