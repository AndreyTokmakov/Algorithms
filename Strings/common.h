/**============================================================================
Name        : StringAlgorithms.h
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : StringAlgorithms.cpp
============================================================================**/

#ifndef STRING_ALGORITHMS_COMMON_H
#define STRING_ALGORITHMS_COMMON_H

#include <string>
#include <vector>
#include <set>

namespace StringAlgorithms
{
    using StrSizeTPair = std::pair<std::string, size_t>;
    using StringPair = std::pair<std::string, std::string>;

    template<typename Ty>
    std::ostream& operator<<(std::ostream& stream, const std::vector<Ty>& vec)
    {
        for (const auto & v: vec)
            stream << v << ' ';
        return stream;
    }

    template<typename Ty>
    std::ostream& operator<<(std::ostream& stream, const std::set<Ty>& vec)
    {
        for (const auto & v: vec)
            stream << v << ' ';
        return stream;
    }
}

#endif //STRING_ALGORITHMS_COMMON_H

