/**============================================================================
Name        : Detect_Cycle_2.cpp
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

        bool dfs(const int node, const int parent)
        {
            visited[node] = true;
            for (const int neighbor : nodes.at(node))
            {
                if (!visited[neighbor])
                {
                    if (dfs(neighbor, node)) {
                        return true;
                    }
                }
                else if (neighbor != parent)
                {
                    return true;  // Found a back edge ---> cycle
                }
            }
            return false;
        }

        bool hasCycle()
        {
            visited.clear();
            for (const auto& [node, _]: nodes) {
                if (!visited[node]) {
                    if (dfs(node, -1))
                        return true;
                }
            }
            return false;
        }
    };



}


void GraphsAlgorithms::Detect_Cycle_2()
{
    CycleDetectedGraph graph;

    // graph.addEdge(0,1).addEdge(1,2).addEdge(2, 3).addEdge(3, 4);
    //graph.addEdge(4,1); /** Uncomment below to introduce a cycle **/

    graph.addEdge(0,1).addEdge(1,2).addEdge(2,0);

    // 0 --> 1 --> 2 --> 0
    //    0 -> -1
    //    1 -> 0
    //    2 -> 1


    std::cout << (graph.hasCycle() ? "Cycle detected" : "No cycle") << std::endl;
}




