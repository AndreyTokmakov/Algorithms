/**============================================================================
Name        : Check_Is_Tree_Symmetric.cpp
Created on  : 20.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../TreesAlgorithms.h"

#include <stack>

/**
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
**/
namespace
{
    using namespace TreesAlgorithms;

}

namespace TreesAlgorithms::Recursive
{
    // Recursive helper function to check if two subtrees are mirror images
    bool isMirror(const Node* leftSub,
                  const Node* rightSub)
    {
        // Both are null, so they are mirror images
        if (leftSub == nullptr && rightSub == nullptr)
            return true;

        // One of them is null, so they aren't mirror images
        if (leftSub == nullptr || rightSub == nullptr || leftSub->data != rightSub->data) {
            return false;
        }

        // Check if the subtrees are mirrors
        return isMirror(leftSub->left, rightSub->right) &&
               isMirror(leftSub->right, rightSub->left);
    }

    bool isSymmetric(const Node* root)
    {
        // If tree is empty, it's symmetric
        if (root == nullptr)
            return true;

        // Check if the left and right subtrees are mirrors of each other
        return isMirror(root->left, root->right);
    }
}

namespace TreesAlgorithms::NonRecursive
{
    bool isSymmetric(const Node* root)
    {
        if (root == nullptr)
            return true;
        // Initialize the stacks with the left and right subtrees
        std::stack<Node*> s1({root->left}), s2({root->right});

        while (!s1.empty() && !s2.empty())
        {
            // Get the current pair of nodes
            const Node* node1 = s1.top();
            const Node* node2 = s2.top();
            s1.pop();
            s2.pop();

            // If both nodes are null, continue to the next pair
            if (node1 == nullptr && node2 == nullptr) {
                continue;
            }

            // If one node is null and the other is not, or the nodes' data do not match then the tree is not symmetric
            if (node1 == nullptr || node2 == nullptr || node1->data != node2->data) {
                return false;
            }

            // Push children of node1 and node2 in opposite order:
            // Push left child of node1 and right child of node2 &  Push right child of node1 and left child of node2
            s1.push(node1->left);
            s1.push(node1->right);

            s2.push(node2->right);
            s2.push(node2->left);
        }

        // If both stacks are empty, the tree is symmetric
        return s1.empty() && s2.empty();
    }
}


namespace TreesAlgorithms::Tests
{
    void TestOne()
    {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->left->left = new Node(3);
        root->left->right = new Node(4);
        root->right = new Node(2);
        root->right->right = new Node(3);
        root->right->left = new Node(4);

        std::cout << std::boolalpha << Recursive::isSymmetric(root) << std::endl;  // True
        std::cout << std::boolalpha << NonRecursive::isSymmetric(root) << std::endl;  // True
    }

    void TestTwo()
    {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(2);
        root->left->right = new Node(3);
        root->right->right = new Node(3);

        std::cout << std::boolalpha << Recursive::isSymmetric(root) << std::endl;  // False
        std::cout << std::boolalpha << NonRecursive::isSymmetric(root) << std::endl; // False
    }
}

void TreesAlgorithms::Check_Is_Tree_Symmetric()
{
    Tests::TestOne();
    Tests::TestTwo();
}