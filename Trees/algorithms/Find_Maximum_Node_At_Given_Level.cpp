/**============================================================================
Name        : Find_Maximum_Node_At_Given_Level.cpp
Created on  : 03.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../TreesAlgorithms.h"

namespace
{
    using namespace TreesAlgorithms;

    std::optional<int> maximum_node_at_level(const Node* root,
                                             int level)
    {
        if (!root)
            return 0;

        std::queue<const Node*> queue ({root});
        while (!queue.empty())
        {
            int maxValue = queue.front()->data;
            for (size_t idx = 0, size = queue.size(); idx < size; idx++)
            {
                const Node* node = queue.front();
                queue.pop();
                maxValue = std::max(node->data, maxValue);

                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            if (0 == --level)
                return maxValue;
        }
        return std::nullopt;
    }
}

void TreesAlgorithms::Find_Maximum_Node_At_Given_Level()
{
    using TestData = std::vector<std::pair<std::pair<const Node*, int>, std::optional<int>>>;
    for (const auto& [data, expected]:  TestData{
            { {BinTree::makeTree({3}), 1}, 3 },
            { {BinTree::makeTree({33,22,85 }), 2}, 85 },
            { {BinTree::makeTree({33,22,85,10,25,54,125,5,15,30}), 3}, 125 },
    })
    {
        auto actual = maximum_node_at_level(data.first, data.second );
        if (expected != actual) {
            std::cerr << std::boolalpha << expected.value() << " != " << expected.value_or(0) << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}