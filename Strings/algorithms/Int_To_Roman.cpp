/**============================================================================
Name        : Int_To_Roman.cpp
Created on  : 20.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"


/**
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000

 For example, 2 is written as II in Roman numeral, just two one's added together.
 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
**/

namespace
{
    using namespace StringAlgorithms;
    using namespace std::string_view_literals;

    std::string int_to_roman(int value)
    {
        constexpr std::array<std::pair<std::string_view, uint16_t>, 14> numerals {{
            {"M"sv, 1000}, {"CM"sv, 900}, {"D"sv, 500}, {"CD"sv, 400},
            {"C"sv, 100}, {"XC"sv, 90}, {"LX"sv, 60}, {"L"sv, 50},
            {"XL"sv, 40}, {"X"sv, 10}, {"IX"sv, 9}, {"V"sv, 5}, {"IV"sv, 4}, {"I"sv, 1}
        }};

        std::string result;
        while (value)
        {
            for (const auto& [ch, val]: numerals)
            {
                if (value >= val)
                {
                    value -= val;
                    result.append(ch.data());
                    break;
                }
            }
        }
        return result;
    }
}

void StringAlgorithms::Int_To_Roman()
{
    for (const auto  &[roman_number, expected]: std::vector<std::pair<int, std::string>> {
            {110, "CX"},
            {1650, "MDCL"},
            {1994, "MCMXCIV"},
    })
    {
        std::string actual = int_to_roman(roman_number);
        if (expected != actual) {
            std::cerr << expected << " != " << actual << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}