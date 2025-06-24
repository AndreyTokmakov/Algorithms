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
exists a direct path going from cityAi to cityBi.
Return the destination city,that is, the city without any path outgoing to another city.
It is guaranteed that the graph of paths forms a line without any loop,
therefore, there will be exactly one destination city.

Example 1:
    Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
    Output: "Sao Paulo"
    Explanation: Starting at "London" city you will reach "Sao Paulo" city which is
    the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".

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
        std::unordered_set<std::string> destinations, origins;
        for (const auto& [from, to] : paths) {
            destinations.insert(to);
            origins.insert(from);
        }
        for (const auto& [from, to] : paths) {
            destinations.erase(from);
            origins.erase(to);
        }

        if (!origins.empty() && !destinations.empty() ) {
            return *destinations.cbegin();
        }
        return {};
    }

}

void StringAlgorithms::Destination_City()
{
    using TestData = std::vector<std::pair<std::vector<std::pair<std::string, std::string>>, std::string>>;
    for (const auto& [value, expected]:  TestData{
        { {{"London","New York"}, {"New York","Lima"},{"Lima","Sao Paulo"}} , "Sao Paulo" },
        { {{"B","C"}, {"D","B"},{"C","A"}} , "A" },
        { {{"A","Z"}} , "Z" },
    })
    {
        const auto actual = destination_city(value);
        if (expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}