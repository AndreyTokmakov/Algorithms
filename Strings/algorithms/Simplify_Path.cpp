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

#include <sstream>
#include <stack>

/**
 * Input: path = "/home/../etc" Output: "/etc"
 * Input: path = "/home/./me" Output: "/home/me"
 * path = "/home//me/" Output: "/home/me"
**/

namespace
{
    using namespace StringAlgorithms;

    std::string simplify_path_fast_inplace(std::string& path)
    {
        std::vector<uint32_t> delimiters;
        std::vector<char> tmp;
        if (path.front() == '/')
            delimiters.push_back(0);

        uint32_t pos = 1;
        for (int32_t idx = 1, size = path.size(), n = 0; idx < size; ++idx)
        {
            if ('/' == path[idx])
            {
                if ('/' == path[idx - 1]) {
                    ++n;
                    continue;
                }
                if (tmp.size() == 1 && tmp.front() == '.') {
                    pos = delimiters.back();
                }
                else if (tmp.size() == 2 && tmp[0] == '.' && tmp[1] == '.')
                {
                    delimiters.pop_back();
                    pos = delimiters.back();
                    // TODO: modify n ?
                }
                else {
                    delimiters.push_back(idx - n);
                }

                tmp.clear();
            } else {
                tmp.push_back(path[idx]);
            }

            path[pos++] = path[idx];
        }
        path.resize(pos);
        return path;
    }

    std::string simplify_path_1(const std::string& path)
    {
        std::stack<std::string> st;
        std::istringstream iss(path);
        std::string s;
        while (getline(iss, s, '/')) {
            if (s == "..") {
                if (!st.empty())
                    st.pop();
            } else if (s.size() > 0 && s != ".") {st.push(s);
            }
        }
        std::string ret;
        while (!st.empty()) {
            ret = "/" + st.top() + ret;
            st.pop();
        }
        return ret.empty() ? "/" : ret;
    }
}

void StringAlgorithms::Simplify_Path()
{

    using TestData = std::vector< std::pair<std::string, std::string> >;
    for (const auto& [value, expected]:  TestData{
        { R"(/c/d//.//./)" , "" },
        { R"(/one//////./etc)" , "" },
        { R"(/one/./three//etc)" , "" },
        { R"(/one/two/three/etc)" , "" },
        { R"(/home//../etc)" , "" },
        { R"(/home//../etc//two///three)" , "" },
        { R"(/a/./b/../../c/)" , "" },
        { R"(/a//b////c/d//./)" , "" },
        { R"(/a/b/../c/../d/../e/../)" , "" },
    })
    {
        std::cout << "Input: " << value << std::endl;
        {
            std::string result(value);
            simplify_path_fast_inplace(result);
            std::cout << '\t' << result << std::endl;
        }
        {
            std::string result = simplify_path_1(value);
            std::cout << '\t' << result << std::endl;
        }
        /*if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }*/
    }
    std::cout << "OK: All tests passed\n";
}