/**============================================================================
Name        : Find_Deepest_Node.cpp
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

    std::optional<const BinTree::Node*> find_deepest_node(const Node* root)
    {
        if (!root)
            return std::nullopt;

        const BinTree::Node* deepest_node { nullptr };
        int maxLevel = 0, currentLevel = 0;
        std::queue<const Node*> queue ({root});
        while (!queue.empty())
        {
            ++currentLevel;
            if (currentLevel > maxLevel) {
                maxLevel = currentLevel;
                deepest_node = queue.front();
            }

            for (size_t idx = 0, size = queue.size(); idx < size; idx++)
            {
                const Node* node = queue.front();
                queue.pop();
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
        }
        return deepest_node;
    }
}

void TreesAlgorithms::Find_Deepest_Node()
{
    using TestData = std::vector<std::pair<const Node*, std::optional<int>>>;
    for (const auto& [tree, expected]:  TestData{
            { BinTree::makeTree({3}), 3 },
            { BinTree::makeTree({33, 22,85}), 22 },
            { BinTree::makeTree({33, 22,85, 10,25,54,125}), 10 },
            { BinTree::makeTree({33, 22,85, 10,25,54,125, 5,15,30}), 5 },
            { BinTree::makeTree({33, 22,85, 10,25,54,125, 5,15,30, 1}), 1 }
    })
    {
        if (auto actual = find_deepest_node(tree ); expected != actual.value()->data) {
            std::cerr << std::boolalpha << expected.value() << " != " << expected.value_or(0) << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}
