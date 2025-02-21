/**============================================================================
Name        : Intersperse_String.cpp
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

    std::string intersperse_strings(const std::string& str1,
                                    const std::string& str2)
    {
        std::string result {};
        result.reserve(str1.size() + str2.size());

        for (size_t idx1 = 0, idx2 = 0, size1 = str1.size(), size2 = str2.size(); idx1 < size1 || idx2 < size2;)
        {
            if (idx1 < size1 && idx2 < size2)
            {
                result.append(1, str1[idx1++]);
                result.append(1, str2[idx2++]);
            }
            else if (idx1 < size1)
                result.append(1, str1[idx1++]);
            else if (idx2 < size2)
                result.append(1, str2[idx2++]);
        }

        return result;
    }


}

void StringAlgorithms::Intersperse_String()
{
    for (const auto  &[values, expected]: std::vector<std::pair<StringPair, std::string>> {
            {{"12345", "abcde"}, "1a2b3c4d5e"},
            {{"12345", "a"}, "1a2345"},
            {{"", "12345"}, "12345"},
            {{"abcd", ""}, "abcd"},
            {{"123456789", "z9y08regqa57"}, "1z293y40586r7e8g9qa57"},
    })
    {
        const std::string actual = intersperse_strings(values.first, values.second);
        if (expected != actual) {
            std::cerr << expected << " != " << actual << std::endl;
            return;
        }
    }
    std::cout << "OK: All tests passed\n";
}