/**============================================================================
Name        : Simplify_Path.cpp
Created on  : 23.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

/**
 * Input: path = "/home/../etc" Output: "/etc"
 * Input: path = "/home/./me" Output: "/home/me"
 * path = "/home//me/" Output: "/home/me"
**/

namespace
{
    using namespace StringAlgorithms;


    void simplify_path(const std::string& path)
    {
        for (int32_t idx = 0, size = path.size(); idx < size; ++idx) {
            std::cout << path[idx];
        }
        std::cout << std::endl;
    }
}

void StringAlgorithms::Simplify_Path()
{
    simplify_path(R"("/home/../etc")");
}