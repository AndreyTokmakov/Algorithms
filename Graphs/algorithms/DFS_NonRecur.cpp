/**============================================================================
Name        : DFS_NonRecur.cpp
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

    struct Graph
    {
        using value_type = int;
        std::map<value_type, std::vector<value_type>> graph;

        Graph& add(value_type v, value_type w) {
            graph[v].push_back(w);
            graph[w].push_back(v);
            return *this;
        }

        void dfs(value_type s)
        {
            std::map<value_type, bool> visited { {s, true } };
            std::vector<value_type> vec { s }; // deque contains 1-st node

            while (!vec.empty()) {
                s = vec.back();
                vec.pop_back();

                std::cout << s << " ";

                for (const auto& nodes = graph[s]; value_type it: nodes) {
                    if (!visited[it]) {
                        visited[it] = true;
                        vec.push_back(it);
                    }
                }
            }
        }
    };

}

void GraphsAlgorithms::DFS_NonRecur()
{

    Graph graph;
    graph.add(0, 1).add(0, 9).add(1, 2).add(2, 0).add(2, 3).add(9, 3);
    graph.dfs(2);

    /*
    {
        Graph g;
        g.add(0, 1).add(0, 9).add(1, 2).add(2, 0).add(2, 3).add(9, 3);

        g.dfs(0);
    }

    std::cout << std::endl;
    */

    /*
    {
        Graph g;
        // g.add(0, 1).add(0, 9).add(1, 2).add(2, 0).add(2, 3).add(9, 3);
        g.add(0, 1).add(1, 2).add(2, 3)
                .add(0, 4).add(4,5).add(5,6)
                .add(0, 7).add(7,8).add(8, 9);


        g.dfs(0);
    }*/

    /*
    std::cout << std::endl;

    {
        Graph g;
        g.add(0, 1).add(0, 9).add(1, 2).add(2, 0).add(2, 3).add(9, 3);

        g.bfs(2);
    }
     */
}