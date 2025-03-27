/**============================================================================
Name        : Longest_Substring_With_K_Distinct_Characters.cpp
Created on  : 14.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

#include <iostream>
#include <cstring>


namespace
{
    using namespace StringAlgorithms;


    int longest_substring_with_k_distinct_characters(const std::string& str, size_t K)
    {
        int chars[256] = { 0 };

        [[maybe_unused]]
        int max_len = 0;

        for (size_t i = 0; i < str.size(); i++)
        {
            size_t distinctLeft = K, n = i;
            memset(chars, 0, sizeof(chars));
            while (n < str.size()) {
                if (0 == chars[str[n]]++ && 0 == distinctLeft--) {
                    break;
                }
                std::cout << str[n];
                n++;
            }
            std::cout << std::endl;
        }

        return 0;
    }
}

void StringAlgorithms::Longest_Substring_With_K_Distinct_Characters()
{
    std::string str = "aaabaaaaadddddccccccggggg";
    longest_substring_with_k_distinct_characters(str, 2);
}