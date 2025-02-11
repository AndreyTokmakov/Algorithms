/**============================================================================
Name        : BFS.cpp
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
        using value_type = int;
        std::map<value_type, std::vector<value_type>> nodes;

    public:

        Graph& addEdge(const value_type v, const value_type w) {
            nodes[v].push_back(w);
            nodes[w].push_back(v);
            return *this;
        }

        const std::vector<value_type>& operator[](const value_type node) const {
            return this->nodes.at(node);
        }
    };

    void bfs(const Graph& graphs, int s)
    {
        std::map<int, bool> visited {{ s, true },};
        std::deque<int> queue { s }; // deque contains 1-st node

        while (!queue.empty()) {
            s = queue.front();
            queue.pop_front();
            std::cout << s << " ";

            for (const std::vector<int>& nodes = graphs[s]; int it: nodes) {
                if (visited.emplace(it, true).second) {
                    queue.push_back(it);
                }
            }
        }
    }
}

void GraphsAlgorithms::BFS()
{
    Graph graphs;
    graphs.addEdge(0, 1).addEdge(0, 9).addEdge(1, 2)
        .addEdge(2, 0).addEdge(2, 3).addEdge(9, 3);

    std::cout << "Following is Breadth First Traversal (starting from vertex 2):" << std::endl;
    bfs(graphs, 2);
    std::cout << std::endl;
}
