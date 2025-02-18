/**============================================================================
Name        : To_Lower_Case.cpp
Created on  : 18.01.2025
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

    void to_lower_case_1(std::string& str)
    {
        for (auto& c : str) {
            c = 'A' <= c && 'Z' >= c ? c + ('a' - 'A') : c;
        }
    }

    void to_lower_case_2(std::string& str)
    {
        for (constexpr int offset = 'a' - 'A'; auto& c : str) {
            if (c >= 'A' && 'Z' >= c)
                c = c + offset;
        }
    }

}

void StringAlgorithms::To_Lower_Case()
{
    using TestData = std::vector<std::pair<std::string, std::string> >;
    for (const auto& [value, expected]:  TestData {
            { "QWERTY" , "qwerty" },
            { "ZaaA123Aaa" , "zaaa123aaa" },
    })
    {
        {
            std::string actual(value);
            to_lower_case_1(actual);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
        {
            std::string actual(value);
            to_lower_case_2(actual);
            if (expected != actual) {
                std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
            }
        }
    }
    std::cout << "OK: All tests passed\n";
}