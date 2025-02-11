/**============================================================================
Name        : DFS.cpp
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
}

namespace GraphsAlgorithms::DFS_1
{
    struct Graph
    {
        using value_type = int;

        std::map<value_type, bool> visited;
        std::map<value_type, std::vector<value_type>> nodes;

        void addEdge(value_type v, value_type w) {
            nodes[v].push_back(w); // Add w to v�s list.
        }

        void DFS(value_type v)
        {
            // Mark the current node as visited and print it
            visited[v] = true;
            std::cout << v << " ";

            // Recur for all the vertices adjacent to this current node
            for (const value_type id : nodes[v])
                if (!visited[id])
                    DFS(id);
        }
    };

    void Test()
    {
        // Create a graph given in the above diagram
        Graph g;
        g.addEdge(0, 1);
        g.addEdge(0, 9);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(9, 3);

        std::cout << "Following is Depth First Traversal (starting from vertex 2) \n";
        g.DFS(2);
    }
}


namespace GraphsAlgorithms::DFS_2
{
    struct  Graph
    {
        std::map<int, std::vector<int>> nodes;

        void addEdge(const int v, const int w) {
            nodes[v].push_back(w); // Add w to v�s list.
        }

        void dfs(const int v,  std::vector<bool>& visited) {
            // Mark the current node as visited and print it
            visited[v] = true;
            std::cout << v << " ";

            for (const std::vector<int>& childs = nodes[v]; const int id: childs)
                if (!visited[id])
                    dfs(id, visited);
        }

        void DFS(const int v)
        {
            // FIXME: Size() is wrong we should use MIN and MAX node id's
            std::vector<bool> visited(nodes.size() + 1, false);
            dfs(v, visited);
        }
    };

    void Test()
    {
        // Create a graph given in the above diagram
        Graph g;
        g.addEdge(0, 1);
        g.addEdge(0, 9);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(9, 3);

        std::cout << "Following is Depth First Traversal (starting from vertex 2) \n";
        g.DFS(2);
    }
}

void GraphsAlgorithms::DFS()
{
    // DFS_1::Test();
    DFS_2::Test();
}