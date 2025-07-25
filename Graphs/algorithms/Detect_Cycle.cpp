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

    /// Track visited nodes and their parent. If a visited neighbor is not the parent, a cycle exists

    struct CycleDetectedGraph: GraphBase<int>
    {
        std::map<int, bool> visited;
        std::map<int, bool> recStack;

        bool dfs(const int node)
        {
            visited[node] = true;
            recStack[node] = true;

            for (const int neighbor : nodes.at(node))
            {
                if (!visited[neighbor])
                {
                    if (dfs(neighbor)) {
                        return true;
                    }
                }
                else if (recStack[neighbor])
                {
                    return true;  // Found a back edge ---> cycle
                }
            }

            recStack[node] = false;
            return false;
        }

        bool hasCycle()
        {

            for (const auto& [node, _]: nodes) {
                if (!visited[node]) {
                    if (dfs(node))
                        return true;
                }
            }
            return false;
        }
    };



}


void GraphsAlgorithms::Detect_Cycle()
{
    CycleDetectedGraph graph;

    graph.addEdge(0,1).addEdge(1,2).addEdge(2, 3).addEdge(3, 4);
    //graph.addEdge(4,1); /** Uncomment below to introduce a cycle **/

    std::cout << (graph.hasCycle() ? "Cycle detected" : "No cycle") << std::endl;
}




