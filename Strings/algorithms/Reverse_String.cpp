/**============================================================================
Name        : Reverse_String.cpp
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

    void reverse_string(std::string &str)
    {
        for (size_t idx = 0, size = str.size(); idx < size / 2; ++idx)
            std::swap(str[idx], str[size - idx - 1]);
    }

    void reverse_string_good(std::string &str)
    {
        for (size_t front = 0, end = str.size() - 1; end >= front; ++front, --end)
            std::swap(str[front], str[end]);
    }
}

void StringAlgorithms::Reverse_String()
{
    {
        std::string text{"123456789"};
        reverse_string(text);
        std::cout << text << std::endl;
    }
    {
        std::string text{"123456789"};
        reverse_string_good(text);
        std::cout << text << std::endl;
    }
}