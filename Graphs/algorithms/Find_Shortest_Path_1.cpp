/**============================================================================
Name        : Find_Shortest_Path_1.cpp
Created on  : 22.06.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include <queue>

#include "../common.h"
#include "../GraphsAlgorithms.h"

namespace
{
    using namespace GraphsAlgorithms;

    struct Graph: GraphBase<int>
    {
        std::map<int, bool> visited;
        int maxNode = 0;

        GraphBase& addEdge(const value_type v, const value_type w)
        {
            maxNode = std::max(maxNode, v);
            maxNode = std::max(maxNode, w);
            return GraphBase<int>::addEdge(v ,w);
        }

        std::vector<int> bfsShortestPath(int start, int end)
        {
            std::vector<int> prev(maxNode, -1);
            std::queue<int> queue;

            visited[start] = true;
            queue.push(start);

            while (!queue.empty())
            {
                const int node = queue.front();
                queue.pop();

                if (node == end)
                    break;

                for (int neighbor : nodes.at(node)) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        prev[neighbor] = node;
                        queue.push(neighbor);
                    }
                }
            }

            // Reconstruct path
            std::vector<int> path;
            for (int at = end; at != -1; at = prev[at]) {
                path.push_back(at);
            }

            reverse(path.begin(), path.end());

            if (path[0] == start)
                return path;
            return {}; // No path
        }
    };
}


void GraphsAlgorithms::Find_Shortest_Path_1()
{
    Graph graph;

    graph.addEdge(0, 1).addEdge(0, 2)
        .addEdge(1, 0).addEdge(1, 3)
        .addEdge(2, 0).addEdge(2, 4)
        .addEdge(3, 1).addEdge(3, 5)
        .addEdge(4, 2).addEdge(5, 3);


    int start = 0, end = 5;
    std::vector<int> path = graph.bfsShortestPath(start, end);

    if (!path.empty()) {
        std::cout << "Shortest path: " << path << std::endl;
    } else {
        std:: cout << "No path found\n";
    }
}