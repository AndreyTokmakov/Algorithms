/**============================================================================
Name        : Backwards_Tree_Traversal.cpp
Created on  : 26.02.2025
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

    void backwards_walkthrough_recursive(BinTree::Node* node)
    {
        if (nullptr == node)
            return;

        backwards_walkthrough_recursive(node->right);
        std::cout << node->getData() << std::endl;
        backwards_walkthrough_recursive(node->left);
    }

    void backwards_walkthrough(BinTree::Node* node)
    {
        std::vector<BinTree::Node*> stack {};
        BinTree::Node *curr = node;

        while (curr || !stack.empty())
        {   /* Reach the left most Node of the curr Node */
            while (curr)
            { /* place pointer to a tree node on the stack before traversing the node's left subtree */
                stack.push_back(curr);
                curr = curr->right;
            }

            curr = stack.back(); // Current must be NULL at this point
            stack.pop_back();

            std::cout << curr->data << " ";
            /* we have visited the node and its left subtree.  Now, it's right subtree's turn */
            curr = curr->left;
        }
    }
}

void TreesAlgorithms::Backwards_Tree_Traversal()
{
    Node *tree = BinTree::makeTree({ 33, 22, 85, 10 ,30, 54, 125 });

    backwards_walkthrough(tree);
    std::cout << "\n" << std::string(180, '-') << std::endl;
    backwards_walkthrough_recursive(tree);
}