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

        void addEdge(value_type v, value_type w) {
            nodes[v].push_back(w);
            nodes[w].push_back(v);
        }

        [[nodiscard]]
        inline size_t size() const noexcept {
            return this->nodes.size();
        }

        const std::vector<value_type>& operator[](size_t index) const {
            return this->nodes.at(index);
        }
    };

    void bfs(const Graph& graphs, int s)
    {
        std::vector<bool> visited(graphs.size(), false);

        visited[s] = true;
        std::deque<int> queue { s }; // deque contains 1-st node

        while (!queue.empty()) {
            s = queue.front();
            queue.pop_front();
            std::cout << s << " ";

            for (const auto& nodes = graphs[s]; int it: nodes) {
                if (!visited[it]) {
                    visited[it] = true;
                    queue.push_back(it);
                }
            }
        }
    }

}

void GraphsAlgorithms::BFS()
{
    // Create a graph given in the above diagram
    Graph graphs;

    graphs.addEdge(0, 1);
    graphs.addEdge(0, 9);
    graphs.addEdge(1, 2);
    graphs.addEdge(2, 0);
    graphs.addEdge(2, 3);
    graphs.addEdge(9, 3);

    std::cout << "Following is Breadth First Traversal (starting from vertex 2):" << std::endl;
    bfs(graphs, 2);
    std::cout << std::endl;
}
