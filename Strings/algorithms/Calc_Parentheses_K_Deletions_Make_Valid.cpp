/**============================================================================
Name        : Calc_Parentheses_K_Deletions_Make_Valid.cpp
Created on  : 06.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
* Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed
* to make the string valid (i.e. each open parenthesis is eventually closed). For example,
* given the string "()())()", you should return 1.
* Given the string ")(", you should return 2, since we must remove all of them.
 */
namespace
{
    using namespace StringAlgorithms;

    int calc_parentheses_K_deletions(const std::string& str)
    {
        std::vector<char> brackets;
        brackets.reserve(str.length());
        for (const char c : str) {
            if ('(' == c) {
                brackets.push_back(c);
            }
            else if (')' == c) {
                if (brackets.empty() || ')' == brackets.back())
                    brackets.push_back(c);
                else
                    brackets.pop_back();
            }
        }
        return brackets.size();
    }
}

void StringAlgorithms::Calc_Parentheses_K_Deletions_Make_Valid()
{
    using TestData = std::vector< std::pair<std::string, int>>;
    for (const auto& [values, expected]:  TestData{
        { "()())()" , 1 },
        { ")(" , 2 },
        { ")()(" , 2 },
        { "((()))()" , 0 },
        { "" , 0 },
    })
    {
        if (const auto actual = calc_parentheses_K_deletions(values); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}