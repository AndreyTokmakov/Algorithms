/**============================================================================
Name        : common.h
Created on  : 11.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#ifndef GRAPHS_ALGORITHMS_COMMON_H
#define GRAPHS_ALGORITHMS_COMMON_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <deque>

namespace GraphsAlgorithms
{
    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vect) {
        for (const T& entry : vect)
            stream << entry << ' ';
        return stream;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& stream, const std::list<T>& vect) {
        for (const T& entry : vect)
            stream << entry << ' ';
        return stream;
    }
}

#endif //GRAPHS_ALGORITHMS_COMMON_H

