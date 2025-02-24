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
        std::string result(path);
        std::vector<uint32_t> delimiters;
        std::vector<char> tmp;

        if (path.front() == '/')
            delimiters.push_back(0);

        uint32_t pos = 1;
        for (int32_t idx = 1, size = path.size(); idx < size; ++idx)
        {
            if ('/' == path[idx])
            {
                if ('/' == path[idx - 1]) {
                    continue;
                }
                if (tmp.size() == 1 && tmp.front() == '.') {
                    pos = delimiters.back();
                }
                else if (tmp.size() == 2 && tmp[0] == '.' && tmp[1] == '.')
                {
                    delimiters.pop_back();
                    pos = delimiters.back();
                }
                else {
                    delimiters.push_back(idx);
                }

                tmp.clear();
            } else {
                tmp.push_back(path[idx]);
            }

            result[pos++] = path[idx];
        }

        result.resize(pos);
        std::cout << delimiters << std::endl;
        std::cout << result << std::endl;
    }
}

void StringAlgorithms::Simplify_Path()
{
    simplify_path(R"(/c/d//./)");
    // simplify_path(R"(/one//////./etc)");
    //simplify_path(R"(/one/./three//etc)");
    // simplify_path(R"(/one/../three//etc)");
    // simplify_path(R"(/one/two/three/etc)");
    // simplify_path(R"(/home//../etc)");
    //simplify_path(R"(/home//../etc//two///three)");

    // simplify_path(R"(/a//b////c/d//./)");
}