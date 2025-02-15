/**============================================================================
Name        : Find_First_Char_Encountered_Once.cpp
Created on  : 14.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**

**/

namespace
{
    using namespace StringAlgorithms;
    void firstNonRepeatingChar(const std::string& str)
    {
        std::pair<int, int> arr[256];
        for (int i = 0; str[i]; i++) {
            arr[str[i]].first += 1;
            arr[str[i]].second = i;
        }

        int pos = std::numeric_limits<int>::max();
        for (int i = 0; i < 256; i++) {
            if (arr[i].first == 1) {
                pos = std::min(pos, arr[i].second);
            }
        }
        std::cout << "Result = " << str[pos] << std::endl;
    }

    void firstNonRepeatingChar_GOOD(const std::string& str)
    {
        int chars[256]{ 0 };
        for (const char c : str)
            chars[c]++;

        for (const char c : str) {
            if (1 == chars[c]) {
                std::cout << "Result = " << c << std::endl;
                break;
            }
        }
    }


}

void StringAlgorithms::Find_First_Char_Encountered_Once()
{
    const std::string str { "geeksforgeeks" };
    firstNonRepeatingChar(str);
    firstNonRepeatingChar_GOOD(str);
}
