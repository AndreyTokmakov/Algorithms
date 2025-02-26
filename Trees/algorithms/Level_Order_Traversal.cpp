/**============================================================================
Name        : Level_Order_Traversal.cpp
Created on  : 26.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../TreesAlgorithms.h"


namespace {
    using namespace TreesAlgorithms;
}

namespace TreesAlgorithms::Map_Recursive
{
    void level_order_traversal(const BinTree::Node* node,
                               std::multimap<size_t, int>& lvlMap,
                               size_t level) {
        if (nullptr == node)
            return;
        lvlMap.emplace(level, node->getData() );
        level_order_traversal(node->left, lvlMap, level + 1);
        level_order_traversal(node->right, lvlMap, level + 1);
    }

    void level_order_traversal(const BinTree::Node* node)
    {
        std::multimap<size_t, int> lvlMap;
        level_order_traversal(node, lvlMap, 1);

        for (size_t level = 1; const auto& [k, v] : lvlMap) {
            if (k > level) {
                std::cout << std::endl;
                level = k;
            }
            std::cout << v << " ";
        }
    }
}

namespace TreesAlgorithms::Map_Recursive_2
{
    void level_order_traversal(const BinTree::Node* node,
                               std::map<size_t, std::vector<int>>& lvlMap,
                               size_t level) {
        if (nullptr == node)
            return;
        lvlMap[level].emplace_back(node->getData() );
        level_order_traversal(node->left, lvlMap, level + 1);
        level_order_traversal(node->right, lvlMap, level + 1);
    }

    void level_order_traversal(const BinTree::Node* node)
    {
        std::map<size_t, std::vector<int>> lvlMap;
        level_order_traversal(node, lvlMap, 1);

        for (const auto& [key, values] : lvlMap) {
            for (const auto& v : values)
                std::cout << v << " ";
            std::cout << std::endl;
        }
    }
}


namespace TreesAlgorithms::Print_Recursive
{

    bool print_level(BinTree::Node* node, int level)
    {
        if (node == nullptr)
            return false;
        else if (level == 1) {
            std::cout << node->data << " ";
            return true;
        }

        bool left = print_level(node->left, level - 1);
        bool right = print_level(node->right, level - 1);
        return left || right;
    }

    void level_order_traversal(BinTree::Node* root)
    {
        int level = 1;
        while (print_level(root, level)) {
            level++;
        }
    }
}

namespace TreesAlgorithms::NonRecursive
{
    void level_order_traversal_1(BinTree::Node* root)
    {
        if (nullptr == root)
            return;

        std::queue<const Node*> queue ({root});
        while (!queue.empty())
        {
            const BinTree::Node* node = queue.front();
            std::cout << node->getData() << " ";
            queue.pop();

            if (nullptr != node->left) /* Enqueue left child: */
                queue.push(node->left);
            if (nullptr != node->right) /* Enqueue right child: */
                queue.push(node->right);
        }
    }

    void level_order_traversal_2(BinTree::Node* root)
    {
        if (nullptr == root)
            return;

        std::queue<const Node*> queue ({root});
        while (!queue.empty())
        {
            for (size_t idx = 0, size = queue.size(); idx < size; idx++)
            {
                const Node* node = queue.front();
                queue.pop();
                std::cout << node->getData() << " ";

                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            std::cout << std::endl;
        }
    }
}

void TreesAlgorithms::Level_Order_Traversal()
{
    Node *tree = BinTree::makeTree({40,22,85 ,10,30,54,125 ,5,12 ,25,32 ,45,60,
                                    120,130,4,7,11,15,24,28,31,35,42,50,55,65,100,122,127 });

    Map_Recursive::level_order_traversal(tree);

    std::cout << std::string(180, '-') << std::endl;
    Map_Recursive_2::level_order_traversal(tree);

    std::cout << std::string(180, '-') << std::endl;
    Print_Recursive::level_order_traversal(tree);

    std::cout << std::string(180, '-') << std::endl;
    NonRecursive::level_order_traversal_1(tree);

    std::cout << std::string(180, '-') << std::endl;
    NonRecursive::level_order_traversal_2(tree);
}