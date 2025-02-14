/**============================================================================
Name        : Print_1_0_Instead_Wildcards.cpp
Created on  : 14.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

#include <deque>

/**

**/

namespace
{
    using namespace StringAlgorithms;

    void print(std::string str, const size_t pos)
    {
        if (str.length() == pos) {
            std::cout << str << std::endl;
            return;
        }
        if ('?' == str[pos]) {
            str[pos] = '0';
            print(str, pos + 1);
            str[pos] = '1';
            print(str, pos + 1);
        }
        else {
            print(str, pos + 1);
        }
    }

    void print_2(const std::string& str)
    {
        std::deque<std::string> strings{ str };
        size_t wildPos = std::string::npos;
        while (std::string::npos != (wildPos = strings.front().find('?'))) {
            strings.emplace_back(strings.front())[wildPos] = '0';
            strings.emplace_back(strings.front())[wildPos] = '1';
            strings.pop_front();
        }
        std::for_each(strings.begin(), strings.end(), [](const auto& s) {
            std::cout << s << std::endl;
        });
    }
}

void StringAlgorithms::Print_1_0_Instead_Wildcards()
{
    const std::string text = "1??0?101";
    print(text, 0);
    std::cout << std::string(180, '=') << std::endl;
    print_2(text);
}