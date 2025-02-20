/**============================================================================
Name        : Check_Is_Trees_Identical.cpp
Created on  : 20.01.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../TreesAlgorithms.h"

/**
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
**/
namespace
{
    using namespace TreesAlgorithms;

    // Recursive function to check if two given binary trees are identical or not
    bool isIdentical(const BinTree::Node* x, const BinTree::Node* y)
    {
        // if both trees are empty, return true
        if (x == nullptr && y == nullptr)
            return true;

        // if both trees are non-empty and value of their root node matches, recur for their left and right sub-tree
        return (x && y) && (x->data == y->data) &&
                isIdentical(x->left, y->left) && isIdentical(x->right, y->right);
    }
}

void TreesAlgorithms::Check_Is_Trees_Identical()
{
    {
        const BinTree::Node* tree1 = BinTree::makeTree( { 33, 22, 85, 10 ,30, 54, 125  });
        const BinTree::Node* tree2 = BinTree::makeTree( { 33, 22, 85, 10 ,30, 54, 125  });
        std::cout << std::boolalpha <<  isIdentical(tree1, tree2) << std::endl; // --> True
    }

    {
        const BinTree::Node* tree1 = BinTree::makeTree( { 33, 22, 85, 10 ,30, 54, 125  });
        const BinTree::Node* tree2 = BinTree::makeTree( { 33, 22, 85, 10 ,31, 54, 125 });
        std::cout << std::boolalpha <<  isIdentical(tree1, tree2) << std::endl; // --> False
    }
}
