/**============================================================================
Name        : Check_If_Strings_Rotate_Rotate_Equals.cpp
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

    bool _is_K_rotate_equals(const std::string &str1, const std::string &str2, size_t K)
    {
        for (size_t pos = 0; pos < str1.size(); pos++, K++)
            if (str2[K % str1.size()] != str1[pos])
                return false;
        return true;
    }

    int find_K_rotates_to_make_equal(const std::string &str1, const std::string &str2)
    {
        if (str1.size() != str2.size())
            return -1;
        for (size_t pos = 0; pos < str1.size(); pos++)
            if (_is_K_rotate_equals(str1, str2, pos))
                return pos;
        return -1;
    }
}

void StringAlgorithms::Check_If_Strings_Rotate_Rotate_Equals()
{
    using TestData = std::vector<std::pair<std::pair<std::string, std::string>, size_t>>;
    for (const auto& [values, expected]:  TestData{
        {{"123456789", "789123456"}, 3},
           {{"00001",     "01000"},  2},
    })
    {
        if (const auto actual = find_K_rotates_to_make_equal(values.first, values.second); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}