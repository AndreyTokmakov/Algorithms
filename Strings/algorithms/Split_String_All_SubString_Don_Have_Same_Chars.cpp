/**============================================================================
Name        : Split_String_All_SubString_Don_Have_Same_Chars.cpp
Created on  : 28.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/// given a string, it needs to be split into the maximum number of substrings so that all the strings contain
/// only unique characters - there should be no substrings so that strings str1 and str2 contain the same character - for example 'a'
/// abad -> [aba, d]
/// abc -> [a, b , c]

namespace
{
    using namespace StringAlgorithms;

    /**
     * Нужно отделять стороку исходя из того что в текущей подстроке более нет элементов которые встретятся далее в
     * основной строке для этого создаётся таблица 'tblWait' с количеством символов для данной подстроки а счётчик
     * waitCount служит для учёта количества элементов в этой подстроки которое еще есть в оставшейся части основной подстроки
     */

    std::vector<std::string> split(const std::string& str)
    {
        uint16_t table[256] {};
        std::for_each(str.cbegin(), str.cend(), [&table](char c) { ++table[c]; });

        std::vector<std::string> result(1);
        uint16_t waitCount = 0, tblWait[256] {};
        for (char c: str)
        {
            if (!tblWait[c]) {
                tblWait[c] = table[c];
                waitCount += tblWait[c];
            }

            --table[c];
            --tblWait[c];
            --waitCount;

            result.back().push_back(c);
            if (!waitCount)
                result.emplace_back();
        }

        result.pop_back();
        return result;
    }
}


void StringAlgorithms::Split_String_All_SubString_Don_Have_Same_Chars()
{
    using TestData = std::vector< std::pair<std::string, std::vector<std::string>>>;
    for (const auto& [value, expected]:  TestData{
            { "abcbd" , {"a", "bcb", "d"} },
            { "abc" , {"a", "b", "c"} },
            { "aba" , {"aba"} },
            { "abad" , {"aba", "d"} },
            { "abcabcddeezez" , {"abcabc", "dd", "eezez"} },
            { "aabbabcde" , {"aabbab", "c", "d", "e"} },
    })
    {
        const auto actual = split(value);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
