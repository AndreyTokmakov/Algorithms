/**============================================================================
Name        : Detect_Cycle.cpp
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

    class Graph
    {
    public:
        std::map<int, bool> visited;
        std::map<int, bool> track;
        std::map<int, std::vector<int>> nodes;

        void addEdge(int v, int w) {
            nodes[v].push_back(w);
        }

        void DFS_IsCycled(int v) {
            if (visited[v] == false) {
                visited[v] = true;
                track[v] = true;

                std::cout << v << "  | " << std::boolalpha << track[v] << std::endl;

                for (const auto id : nodes[v])
                    if (visited[id] == false)
                        DFS_IsCycled(id);

                track[v] = false;
                visited[v] = false;
            }
        }

        void IsCycled() {
            for (const auto& [k, v] : nodes)
                DFS_IsCycled(k);
        }
    };
}


void GraphsAlgorithms::Detect_Cycle()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
    g.addEdge(3, 0);

    g.IsCycled();
}