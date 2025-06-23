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

    struct Graph: GraphBase<int>
    {
        int maxNode = 0;
        std::vector<int> path;
        std::vector<int> shortest;

        GraphBase& addEdge(const value_type v, const value_type w)
        {
            maxNode = std::max(maxNode, v);
            maxNode = std::max(maxNode, w);
            return GraphBase<int>::addEdge(v ,w);
        }

        void findPath(int v, int node_to_find)
        {
            path.clear();
            shortest.clear();

            std::vector<bool> visited(maxNode + 1, false);
            findPath(v, node_to_find, visited);
        }

        void findPath(int from, int to, std::vector<bool>& visited)
        {
            visited[from] = true;
            path.push_back(from);

            if (from == to) {
                if (shortest.empty() || shortest.size() > path.size()) {
                    shortest.assign(path.begin(), path.end());
                    return;
                }
            }
            else {
                for (const auto id : nodes[from])
                    if (!visited[id])
                        findPath(id, to, visited);
            }

            path.pop_back();
            visited[from] = false;
        }

        void printPath() const noexcept {
            std::cout << shortest << std::endl;
        }
    };
}


void GraphsAlgorithms::Find_Shortest_Path()
{
    Graph graph;

    graph.addEdge(0, 1).addEdge(0, 2)
            .addEdge(1, 0).addEdge(1, 3)
            .addEdge(2, 0).addEdge(2, 4)
            .addEdge(3, 1).addEdge(3, 5)
            .addEdge(4, 2).addEdge(5, 3);

    graph.findPath(0, 5);
    graph.printPath();

}