/**============================================================================
Name        : Tree_Traversal_PostOrder.cpp
Created on  : 11.03.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../TreesAlgorithms.h"

/**
Postorder traversal visits the node in the order: Left -> Right -> Root
Postorder traversal is defined as a type of tree traversal that follows the Left-Right-Root policy such that for each node:
    The left subtree is traversed first.
    Then the right subtree is traversed.
    Finally, the root node of the subtree is traversed.

Postorder traversal is a depth-first traversal (DFS) method where nodes are visited in the order:
  left subtree, right subtree, current node.

**/

namespace
{
    using namespace TreesAlgorithms;

}

namespace
{
    void post_order_walkthrough_recursive(const BinTree::Node* node)
    {
        if (nullptr == node)
            return;
        std::cout << node->getData() << " ";
        post_order_walkthrough_recursive(node->left);
        post_order_walkthrough_recursive(node->right);
    }

    void post_order_walkthrough(BinTree::Node* root)
    {
        std::vector<int> result;
        std::vector<BinTree::Node*> stack { root };
        while (!stack.empty())
        {
            const BinTree::Node* node = stack.back();
            stack.pop_back();

            result.push_back(node->getData());

            if (node->left)
                stack.push_back(node->left);
            if (node->right)
                stack.push_back(node->right);
        }

        std::reverse(result.begin(), result.end());
        std::cout << result << " ";
    }

    void post_order_walkthrough_list(BinTree::Node* root)
    {
        std::list<int> result;
        std::vector<Node*> stack { root };
        while (!stack.empty())
        {
            const BinTree::Node* node = stack.back();
            stack.pop_back();

            result.push_front(node->getData());

            if (node->left)
                stack.push_back(node->left);
            if (node->right)
                stack.push_back(node->right);
        }

        std::cout << result << " ";
    }
}

void TreesAlgorithms::Tree_Traversal_PostOrder()
{   //              33
    //        22           85
    //     10     30   54      125

    Node *tree = BinTree::makeTree({ 33, 22, 85, 10 ,30, 54, 125 });

    // post_order_walkthrough_recursive(tree);
    // std::cout << "\n" << std::string(180, '-') << std::endl;

    post_order_walkthrough(tree);
    /** 10 30 22 54 125 85 33  **/

    std::cout << "\n" << std::string(180, '-') << std::endl;

    post_order_walkthrough_list(tree);
    /** 10 30 22 54 125 85 33  **/
}
