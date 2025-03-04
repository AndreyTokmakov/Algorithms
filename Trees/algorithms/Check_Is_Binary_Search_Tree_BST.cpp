/**============================================================================
Name        : Check_Is_Binary_Search_Tree_BST.cpp
Created on  : 04.03.2025
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

    bool is_bst(const Node* root)
    {
        int previous = std::numeric_limits<int>::min();
        std::vector<const BinTree::Node*> stack {};
        for (const BinTree::Node *node = root; node || !stack.empty(); )
        {
            while (node) {
                stack.push_back(node);
                node = node->left;
            }

            node = stack.back();
            stack.pop_back();

            if (previous >= node->data)
                return false;

            previous = node->data;
            node = node->right;
        }
        return true;
    }

    bool is_bst_recursive(const BinTree::Node* node,
                          int min = std::numeric_limits<int>::min(),
                          int max = std::numeric_limits<int>::max()) {
        if (nullptr == node)
            return true;
        if (node->data < min || node->data > max)
            return false;
        return is_bst_recursive(node->left, min, node->data - 1) &&
               is_bst_recursive(node->right, node->data + 1, max);
    }

    bool is_bst_recursive_2(const BinTree::Node* node)
    {
        if (nullptr == node)
            return true;
        else if (nullptr != node->left && node->left->data > node->data)
            return false;
        else if (!is_bst_recursive_2(node->left))
            return false;
        else if (nullptr != node->right && node->right->data < node->data)
            return false;
        else if (!is_bst_recursive_2(node->right))
            return false;
        else
            return true;
    }
}

void TreesAlgorithms::Check_Is_Binary_Search_Tree_BST()
{
    using TestData = std::vector<std::pair<const Node*, bool>>;
    for (const auto& [tree, expected]:  TestData{
            { BinTree::makeTree({33}) , true },
            { BinTree::makeTree({33, 22,85}) , true },
            { BinTree::makeTree({33, 22,85, 10}) , true },
            { BinTree::makeTree({33, 22,85, 10,30,54,125}) , true },
            { BinTree::makeTree({33, 22,85, 10,30}) , true },
            { BinTree::makeTreeNonBST(1, {33, 22,85, 10,30}) , false },
    })
    {
        if (const auto actual = is_bst(tree); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = is_bst_recursive(tree); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
        if (const auto actual = is_bst_recursive_2(tree); expected != actual) {
            std::cerr << std::boolalpha << expected << " != " << actual << std::endl;
        }
    }
    std::cout << "OK: All tests passed\n";
}