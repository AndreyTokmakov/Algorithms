/**============================================================================
Name        : Switch_Case.cpp
Created on  : 26.03.2025
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

    void switch_case(std::string& input)
    {
        constexpr uint16_t diff = 'a' - 'A';
        for (char& c: input) {
            if (0 != std::isalpha(c)) {
                c = c >= 'a' ? static_cast<char>(c - diff) :static_cast<char>(c + diff);
            }
        }
    }
}

void StringAlgorithms::Switch_Case()
{
    using TestData = std::vector<std::pair<std::string, std::string>>;
    for (const auto& [str, expected]:  TestData {
        { "AbCdEfG" , "aBcDeFg"},
        { "12345" , "12345"},
        { "1a2B3c45" , "1A2b3C45"},
    })
    {
        std::string actual(str);
        switch_case(actual);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}