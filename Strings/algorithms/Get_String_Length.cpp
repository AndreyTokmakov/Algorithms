/**============================================================================
Name        : Get_String_Length.cpp
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

    size_t str_len(const char* str)
    {
        size_t count = 0;
        while (*str != '\0')
        {
            ++str;
            ++count;
        }
        return count;
    }
}

void StringAlgorithms::Get_String_Length()
{
    using TestData = std::vector< std::pair<std::string, size_t> >;
    for (const auto& [str, expected]:  TestData{
        { "12345" , 5 },
        { "qwerty123456" , 12 },
    })
    {
        const auto actual = str_len(str.data());
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}