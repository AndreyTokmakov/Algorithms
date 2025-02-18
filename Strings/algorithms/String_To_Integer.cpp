/**============================================================================
Name        : String_To_Integer.cpp
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

    unsigned int _atoi(const char* str)
    {
        unsigned int result {0};
        char c = *str;
        while (c >= '0' && c <= '9') {
            result = result * 10 + (c - '0');
            c = *(++str);
        }
        return result;
    }

    unsigned int _atoi2(const char* c)
    {
        unsigned int result {0};
        while (*c >= '0' && *c <= '9')
            result = result * 10 + (*(c++) - '0');
        return result;
    }
}

void StringAlgorithms::String_To_Integer()
{
    for (const auto& str: {
            "123", "1203", "931aa", "00123", "  -123 hh", "42"
            // "-91283472332"
    }) {
        std::cout << str << " -> " << _atoi(str) <<  "    " << _atoi2(str) <<  "    " <<  std::endl;
    }
}