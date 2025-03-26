/**============================================================================
Name        : Letter_Case_Permutation.cpp
Created on  : 26.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

#include <deque>

/**

Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create. Return the output in any order.
Example 1:  Input: s = "a1b2"    Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:  Input: s = "3z4"     Output: ["3z4","3Z4"]
*/


namespace
{
    using namespace StringAlgorithms;
    constexpr uint16_t diff = 'a' - 'A';

    std::vector<std::string> letter_case_permutation_1(const std::string& str)
    {
        std::deque<std::string> strings { str };
        for (uint32_t pos = 0, target = 1, size = str.size(); size > pos;)
        {
            for (int n = 0; n < target; ++n) {
                const auto iter = std::find_if(strings.front().cbegin() + pos, strings.front().cend(), [](const char c){
                      return 0 != std::isalpha(c);
                });
                if (strings.front().end() == iter)
                    break;

                pos = std::distance(strings.front().cbegin(), iter);
                strings.push_back(std::move(strings.front()));
                strings.push_back(strings.back());
                const char c = strings.back()[pos];
                strings.back()[pos] = c >= 'a' ? c -diff : c + diff;
                strings.pop_front();
            }
            ++pos;
            target *= 2;
        }

        std::vector<std::string> result;
        result.reserve(strings.size());
        for (std::string& s : strings)
            result.push_back(std::move(s));

        return result;
    }

}

void StringAlgorithms::Letter_Case_Permutation()
{
    using TestData = std::vector<std::pair<std::string, std::vector<std::string>>>;
    for (const auto& [values, expected]:  TestData {
        { {"a1C2"} , {"a1C2","a1c2", "A1C2", "A1c2"} },
        { {"3z4"} , {"3z4","3Z4"} },
    })
    {
        const std::vector<std::string> actual = letter_case_permutation_1(values);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }

    }
    std::cout << "OK: All tests passed\n";
}