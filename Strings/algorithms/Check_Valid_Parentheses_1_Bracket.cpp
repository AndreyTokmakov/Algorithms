/**============================================================================
Name        : Check_Valid_Parentheses_1_Bracket.cpp
Created on  : 06.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"
#include <stack>

namespace
{
    using namespace StringAlgorithms;

    bool is_valid_parentheses(const std::string& str)
    {
        std::stack<char> stack;
        for (const char c : str) {
            if ('(' == c)
                stack.push(c);
            else if (')' == c) {
                if (stack.empty())
                    return false;
                if ('(' == stack.top())
                    stack.pop();
            }
        }
        return stack.empty();
    }

    bool is_valid_parentheses_2(const std::string& str)
    {
        std::vector<char> brackets;
        brackets.reserve(str.length());
        for (const char c : str) {
            if ('(' == c) {
                brackets.push_back(c);
            }
            else if (')' == c) {
                if (!brackets.empty() && '(' == brackets.back())
                    brackets.pop_back();
                else return false;
            }
        }
        return brackets.empty();
    }
}

void StringAlgorithms::Check_Valid_Parentheses_1_Bracket()
{
    using TestData = std::vector< std::pair<std::string, bool>>;
    for (const auto& [values, expected]:  TestData{
        { "()" , true },
        { ")(()))" , false },
        { "(" , false },
        { "(())((()())())" , true },
        { "))" , false },
    })
    {
        if (const auto actual = is_valid_parentheses(values); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = is_valid_parentheses_2(values); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}