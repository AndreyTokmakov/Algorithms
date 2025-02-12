/**============================================================================
Name        : Find_Shortest_Path.cpp
Created on  : 11.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../GraphsAlgorithms.h"

namespace
{
    using namespace GraphsAlgorithms;

    struct  Graph
    {
        std::map<int, std::vector<int>> nodes;
        std::vector<int> path;
        std::vector<int> shortest;
        int maxId {0};

        void addEdge(const int from, const int to) {
            nodes[from].push_back(to);
            maxId = std::max(std::max(from, to), maxId) ;
        }

        void FindPaths(int v, int node_to_find)
        {
            path.clear();
            shortest.clear();
            std::vector<bool> visited(maxId + 1, false);

            findPath(v, node_to_find, visited);
        }

        void findPath(int from, int to, std::vector<bool>& visited) {
            visited[from] = true;
            path.push_back(from);

            if (from == to) {
                if (shortest.empty() || shortest.size() > path.size())
                    shortest.assign(path.begin(), path.end());
            }
            else {
                for (const auto id : nodes[from])
                    if (!visited[id])
                        findPath(id, to, visited);
            }

            path.pop_back();
            visited[from] = false;
        }

        void print_max() {
            std::cout << "shortest_path = " << shortest << std::endl;
        }
    };
}


void GraphsAlgorithms::Find_Shortest_Path()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);


    g.FindPaths(2, 3);
    g.print_max();
}