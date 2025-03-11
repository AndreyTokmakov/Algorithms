/**============================================================================
Name        : Tree_Traversal_PreOrder.cpp
Created on  : 11.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../TreesAlgorithms.h"

/**
In Preorder Traversal, the root node is visited first, followed by the left and right subtrees.
Inorder Traversal starts with the left subtree, visits the root, and then the right subtree, often used in binary search trees.
Postorder Traversal begins with the left subtree, moves to the right subtree, and visits the root last, useful for deleting nodes.

Preorder traversal is defined as a type of tree traversal that follows the Root-Left-Right policy where:
    The root node of the subtree is visited first.
    Then the left subtree is traversed.
    At last, the right subtree is traversed.


**/

namespace
{
    using namespace TreesAlgorithms;

}

namespace
{
    void pre_order_walkthrough_recursive(BinTree::Node* node)
    {
        if (nullptr == node)
            return;
        std::cout << node->getData() << " ";
        pre_order_walkthrough_recursive(node->left);
        pre_order_walkthrough_recursive(node->right);
    }

    void pre_order_walkthrough(BinTree::Node* root)
    {
        std::vector<BinTree::Node*> stack { root };
        while (!stack.empty())
        {
            const BinTree::Node* node = stack.back();
            stack.pop_back();
            std::cout << node->getData() << " ";

            if (node->right)
                stack.push_back(node->right);
            if (node->left)
                stack.push_back(node->left);
        }
    }
}

void TreesAlgorithms::Tree_Traversal_PreOrder()
{
    Node *tree = BinTree::makeTree({ 33, 22, 85, 10 ,30, 54, 125 });

    pre_order_walkthrough_recursive(tree);
    std::cout << "\n" << std::string(180, '-') << std::endl;
    pre_order_walkthrough(tree);
}
