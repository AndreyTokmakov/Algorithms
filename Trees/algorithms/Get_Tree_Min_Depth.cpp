/**============================================================================
Name        : Get_Tree_Min_Depth.cpp
Created on  : 07.03.2025
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

    int get_min_depth(const BinTree::Node* node)
    {
        if (nullptr == node)
            return 0;
        else if (node->left == nullptr && node->right == nullptr)
            return 1;
        else if (nullptr == node->right)
            return get_min_depth(node->left) + 1;
        else if (nullptr == node->left)
            return get_min_depth(node->right) + 1;
        else
            return 1 + std::min(get_min_depth(node->left), get_min_depth(node->right));
    }

    struct Item
    {
        const Node* node;
        int depth;
    };

    int get_min_depth_iter(const BinTree::Node* root)
    {
        if (!root )
            return 0;

        std::queue<Item> queue;
        Item item = queue.emplace(root, 1);
        while (!queue.empty())
        {
            item = queue.front();
            queue.pop();

            // If this  is the first leaf node seen so far - then return its depth as answer
            if (item.node->left == nullptr && item.node->right == nullptr)
                return item.depth;

            if (item.node->left) { /** If LEFT subtree is not NULL, add it to queue **/
                queue.emplace(item.node->left, item.depth + 1);
            }
            if (item.node->right) { /** If RIGHT subtree is not NULL, add it to queue **/
                queue.emplace(item.node->right, item.depth + 1);
            }
        }
        return 0;
    }
}

void TreesAlgorithms::Get_Tree_Min_Depth()
{
    using TestData = std::vector<std::pair< const Node*, int>>;
    for (const auto& [tree, expected]:  TestData {
            { BinTree::makeTree({33, 10, 85, 125, 159}) , 2 },
            { BinTree::makeTree({33,22,85,10,25,54,125,5,15,30}) , 3 },
    })
    {
        if (const auto actual = get_min_depth(tree); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = get_min_depth_iter(tree); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}