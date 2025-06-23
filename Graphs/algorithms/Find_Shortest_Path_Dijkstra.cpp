/**============================================================================
Name        : Find_Shortest_Path_Dijkstra.cpp
Created on  : 23.06.2025
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

    struct Graph
    {
        using value_type = int;

        struct WNode
        {
            value_type destNode { 0 };
            value_type weight { 0 };

            friend auto operator<=>(const WNode&, const WNode&) = default;
        };

        std::map<value_type, std::vector<WNode>> nodes;
        value_type maxNode = 0;

        Graph& addEdge(const value_type v, const value_type w, const value_type weight)
        {
            nodes[v].emplace_back(w, weight);
            nodes[w].emplace_back(v, weight);
            maxNode = std::max(maxNode, v);
            maxNode = std::max(maxNode, w);

            return *this;
        }

        std::vector<value_type> dijkstra(value_type start,
                                         value_type end)
        {
            std::vector<value_type> dist(maxNode, std::numeric_limits<value_type>::max()),
                                    prev(maxNode, -1);
            std::priority_queue<WNode, std::vector<WNode>, std::greater<>> pQueue;

            dist[start] = 0;
            pQueue.emplace(0, start);

            while (!pQueue.empty())
            {
                const auto& [destNode, weight] = pQueue.top();
                pQueue.pop();
                if (destNode > dist[weight])
                    continue;

                for (const auto [v, w] : nodes.at(weight)) {
                    if (dist[weight] + w < dist[v]) {
                        dist[v] = dist[weight] + w;
                        prev[v] = weight;
                        pQueue.emplace(dist[v], v);
                    }
                }
            }

            // Reconstruct path
            std::vector<value_type> path;
            for (value_type n = end; n != -1; n = prev[n])
                path.push_back(n);

            reverse(path.begin(), path.end());
            if (path[0] != start)
                path.clear();

            return path;
        }
    };
}


void GraphsAlgorithms::Find_Shortest_Path_Dijkstra()
{
    Graph graph;
    graph.addEdge(0, 1, 10).addEdge(0, 2, 3)
         .addEdge(1, 2, 1).addEdge(1, 3, 2)
         .addEdge(2, 1, 4).addEdge(2, 3, 8)
         .addEdge(2, 1, 4).addEdge(2, 3, 8)
         .addEdge(2, 4, 2).addEdge(3, 4, 7)
         .addEdge(4, 3, 9);

    const int start = 0, end = 4;
    std::vector<int> path = graph.dijkstra(start, end);

    if (!path.empty()) {
        std::cout << "Shortest path: " << path << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }
}