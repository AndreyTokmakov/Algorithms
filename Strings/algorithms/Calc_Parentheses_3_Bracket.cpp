/**============================================================================
Name        : Calc_Parentheses_3_Bracket.cpp
Created on  : 15.01.2025
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


    bool check_parentheses_3_bracket_1(const std::string& str)
    {
        std::vector<char> brackets;
        brackets.reserve(str.length());
        for (const char c : str) {
            if ('(' == c || '[' == c || '{' == c) {
                brackets.push_back(c);
            }
            else if (')' == c || ']' == c || '}' == c) {
                if (brackets.empty()) {
                    return false;
                }
                else if (')' == c) {
                    if ('(' == brackets.back())
                        brackets.pop_back();
                    else
                        return false;
                }
                else if ('}' == c) {
                    if ('{' == brackets.back())
                        brackets.pop_back();
                    else
                        return false;
                }
                else {
                    if ('[' == brackets.back())
                        brackets.pop_back();
                    else
                        return false;
                }
            }
        }
        return brackets.empty();
    }

    bool check_parentheses_3_bracket_2(const std::string& str)
    {
        constexpr std::array<std::pair<char, char>, 3> symbols {{
            {'[', ']'}, {'{', '}'}, {'(', ')'}
        }};
        std::vector<char> brackets;
        for (const char c : str) {
            for (const auto& [open, close]: symbols) {
                if (c == open)
                    brackets.push_back(c);
                else if (c == close) {
                    if (brackets.empty() || open != brackets.back())
                        return false;
                    else
                        brackets.pop_back();
                }
            }
        }
        return brackets.empty();
    }
}

void StringAlgorithms::Calc_Parentheses_3_Bracket()
{
    for (const auto& str: {"{[(]}", "()", "()()", "({}[{}])"})
    {
        std::cout << str << " = " << std::boolalpha << check_parentheses_3_bracket_1(str) << std::endl;
        std::cout << str << " = " << std::boolalpha << check_parentheses_3_bracket_2(str) << std::endl;
    }
}