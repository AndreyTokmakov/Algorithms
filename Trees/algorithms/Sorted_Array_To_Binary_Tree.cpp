/**============================================================================
Name        : Sorted_Array_To_Binary_Tree.cpp
Created on  : 16.01.2025
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

    void level_order_traversal(const BinTree::Node* node,
                                     std::map<int, std::vector<int>>& lvls,
                                     size_t level = 0) {
        if (nullptr == node)
            return;

        lvls[level].push_back(node->data);
        level_order_traversal(node->left, lvls, level + 1);
        level_order_traversal(node->right, lvls, level + 1);
    }

    void print(const BinTree::Node* node)
    {
        std::map<int, std::vector<int>> lvls;
        level_order_traversal(node, lvls);

        for (const auto& [key, values] : lvls) {
            for (const auto& v : values)
                std::cout << v << " ";
            std::cout << std::endl;
        }
    }

    BinTree::Node* sortedArrayToBST(const std::vector<int>& data, int64_t start, int64_t end)
    {
        if (start > end)
            return nullptr;

        // Get the middle element and make it root
        const int64_t mid = (start + end) / 2;
        Node* root = new Node(data[mid]);

        root->left  = sortedArrayToBST(data, start, mid - 1);
        root->right = sortedArrayToBST(data, mid + 1, end);
        return root;
    }
}

void TreesAlgorithms::Sorted_Array_To_Binary_Tree()
{
    const std::vector<int> data { 1,2,3,4,5,6,7,8,9 };
    Node* root = sortedArrayToBST(data, 0, std::ssize(data)- 1);

    print(root);
}