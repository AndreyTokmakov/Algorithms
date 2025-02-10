/**============================================================================
Name        : common.h
Created on  : 10.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#ifndef ARRAYS_ALGORITHMS_COMMON_H
#define ARRAYS_ALGORITHMS_COMMON_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

namespace ArraysAlgorithms
{
    using StrSizeTPair = std::pair<std::string, size_t>;
    using StringPair = std::pair<std::string, std::string>;

    template<typename T>
    using VectorPair = std::pair<std::vector<T>, std::vector<T>>;

    template<typename T1, typename T2>
    using VectorOfPairs = std::vector< std::pair<T1, T2> >;

    using IntPair = std::pair<int, int>;


    template<typename T>
    std::ostream &operator<<(std::ostream &stream, const std::vector<T> &list)
    {
        for (const auto &i: list)
            stream << " " << i;
        return stream;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &stream, const std::list<T> &list)
    {
        for (const auto &i: list)
            stream << " " << i;
        return stream;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &stream, const std::set<T> &set)
    {
        for (const auto &i: set)
            stream << " " << i;
        return stream;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &stream, const std::unordered_set<T> &set)
    {
        for (const auto &i: set)
            stream << " " << i;
        return stream;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &stream, const std::deque<T> &list)
    {
        for (const auto &i: list)
            stream << " " << i;
        return stream;
    }

    template<typename T>
    void print_vector(const std::vector<T> &vector, size_t start, size_t end)
    {
        for (size_t i = start; i <= end; i++)
            std::cout << vector[i] << " ";
        std::cout << std::endl;
    }
}

#endif //ARRAYS_ALGORITHMS_COMMON_H

