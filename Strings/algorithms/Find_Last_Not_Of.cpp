/**============================================================================
Name        : Find_Last_Not_Of.cpp
Created on  : 14.01.2025
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

    int64_t find_last_not_of(const std::string& str,
                             const std::string& txt)
    {
        bool chars[256] {};
        for (char c: txt)
            chars[static_cast<uint8_t>(c)] = true;

        for (int64_t i = std::ssize(str) - 1; i >= 0; --i) {
            if (!chars[str[i]])
                return i;
        }
        return -1;
    }

    int find_last_not_of_less_mem(const std::string& str, const std::string& txt)
    {
        uint8_t chars[32] {};
        for (const uint8_t charNum: txt)
            chars[charNum / 8] |= (1 << charNum % 8);

        for (int i = static_cast<int>(str.size() - 1); i >= 0; --i) {
            if (false == (chars[str[i] / 8] & (1u << (str[i] % 8))))
                return i;
        }
        return -1;
    }

}

void StringAlgorithms::Find_Last_Not_Of()
{
    for (const StringPair& data: std::vector<StringPair>{
            {"01234b567a89Zc", "abc"}
    })
    {
        int pos1 = find_last_not_of(data.first, data.second);
        int pos2 = find_last_not_of_less_mem(data.first, data.second);
        auto pos3 = std::string(data.first).find_last_not_of(data.second);

        std::cout << data.first[pos1] << " " << data.first[pos2] << " " << data.first[pos3] << std::endl;
    }
}