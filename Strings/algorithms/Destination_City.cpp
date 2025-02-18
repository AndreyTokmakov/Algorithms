/**============================================================================
Name        : Destination_City.cpp
Created on  : 18.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include <unordered_set>

#include "../common.h"
#include "../StringAlgorithms.h"

/**
You are given the array paths, where paths[i] = [cityAi, cityBi] means there
exists a direct path going from cityAi to cityBi. Return the destination city,
that is, the city without any path outgoing to another city.
It is guaranteed that the graph of paths forms a line without any loop,
therefore, there will be exactly one destination city.
Example 1:
Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo"
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is
the destination city. Your trip consist of: "London" -> "New York" -> "Lima" ->
"Sao Paulo".
Example 2:
Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are:
"D" -> "B" -> "C" -> "A".
"B" -> "C" -> "A".
"C" -> "A".
"A".
Clearly the destination city is "A".
Example 3:
Input: paths = [["A","Z"]]
Output: "Z"
Constraints:
1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space
character.
**/

namespace
{
    using namespace StringAlgorithms;

    std::string destination_city(const std::vector<std::pair<std::string, std::string>>& paths)
    {
        std::unordered_set<std::string> dests, origins;
        for (const auto& [from, to] : paths) {
            dests.insert(to);
            origins.insert(from);
        }
        for (const auto& [from, to] : paths) {
            dests.erase(from);
            origins.erase(to);
        }

        return *dests.cbegin();
    }

}

void StringAlgorithms::Destination_City()
{
    {
        std::vector<std::pair<std::string, std::string>> paths {
            {"London","New York"}, {"New York","Lima"},{"Lima","Sao Paulo"},
        };
        std::cout << destination_city(paths) << std::endl;
    }
    {
        std::vector<std::pair<std::string, std::string>> paths {
            {"B","C"}, {"D","B"},{"C","A"},
        };
        std::cout << destination_city(paths) << std::endl;
    }
    {
        std::vector<std::pair<std::string, std::string>> paths {
            {"A","Z"},
        };
        std::cout << destination_city(paths) << std::endl;
    }
}