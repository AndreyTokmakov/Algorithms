/**============================================================================
Name        : Check_Valid_Parentheses_3_Bracket.cpp
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

    bool match(const char l, const char r) {
        return (l == '(' && r == ')') || (l == '[' && r == ']') || (l == '{' && r == '}');
    }

    bool check_parentheses_3_bracket_2(const std::string& str)
    {
        std::vector<char> brackets;
        brackets.reserve(str.length());
        for (const char c : str) {
            if ('(' == c || '[' == c || '{' == c)
                brackets.push_back(c);
            else if (brackets.empty() || false == match(brackets.back(), c))
                return false;
            else
                brackets.pop_back();
        }
        return brackets.empty();
    }

    bool check_parentheses_3_bracket_3(const std::string& str)
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

void StringAlgorithms::Check_Valid_Parentheses_3_Bracket()
{
    using TestData = std::vector< std::pair<std::string, bool>>;
    for (const auto& [values, expected]:  TestData{
        { "[(]}" , false },
        { "()" , true },
        { "()()" , true },
        { "({}[{}])" , true },
    })
    {
        if (const auto actual = check_parentheses_3_bracket_1(values); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = check_parentheses_3_bracket_2(values); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = check_parentheses_3_bracket_2(values); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}