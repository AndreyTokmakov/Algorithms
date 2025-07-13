/**============================================================================
Name        : Roman_To_Int_2.cpp
Created on  : 20.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"


namespace
{
    using namespace StringAlgorithms;
    using namespace std::string_view_literals;

    constexpr std::array<std::pair<std::string_view, uint16_t>, 14> numerals {{
        {"M"sv, 1000},
        {"CM"sv, 900},
        {"D"sv, 500},
        {"CD"sv, 400},
        {"C"sv, 100},
        {"XC"sv, 90},
        {"LX"sv, 60},
        {"L"sv, 50},
        {"XL"sv, 40},
        {"X"sv, 10},
        {"IX"sv, 9},
        {"V"sv, 5},
        {"IV"sv, 4},
        {"I"sv, 1}
    }};


    int roman_to_int(const std::string_view str)
    {
        int result = 0;
        std::string_view symbol;
        for (int idx = 0, end = 0, size = str.size(), value = 0; idx < size; end = idx)
        {
            while (end <= size) {
                symbol = std::string_view(str.data() + idx, str.data() + end + 1);
                const auto iter = std::find_if(numerals.cbegin(), numerals.cend(), [&symbol] (
                    const auto& item) { return item.first == symbol;}
                );
                if (numerals.end() == iter)
                    break;
                ++end;
                value = iter->second;
            }
            idx = end;
            result += value;
        }

        return result;
    }
}

void StringAlgorithms::Roman_To_Int_2()
{
    for (const auto  &[roman_num_str, expected]: std::vector<std::pair<std::string, int>> {
            { "XXXIX", 39},
            { "XXXVIII", 38},
            { "LVIII", 58},
            { "LXVIII", 68},
            { "LXXXIII", 83},
            { "DCC", 700},
            { "DCCC", 800},
    })
    {
        int actual = roman_to_int(roman_num_str);
        if (expected != actual) {
            std::cerr << expected << " != " << actual << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}