/**============================================================================
Name        : Find_Lowest_Common_Ancestor.cpp
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
    BinTree::Node* find_lowest_common_ancestor(Node* node,
                                               int value1,
                                               int value2)
    {
        while (nullptr != node) {
            if (node->data > value1 && node->data > value2)
                node = node->left;
            else if (node->data < value1 && node->data < value2)
                node = node->right;
            else
                return node;
        }
        return node;
    }

    BinTree::Node* find_lowest_common_ancestor_recur(Node* node,
                                                     int value1,
                                                     int value2)
    {
        if (nullptr == node)
            return nullptr;
        if (value1 < node->data && value2 < node->data)
            return find_lowest_common_ancestor_recur(node->left, value1, value2);
        else if (value1 > node->data && value2 > node->data)
            return find_lowest_common_ancestor_recur(node->right, value1, value2);
        else
            return node;
    }
}

void TreesAlgorithms::Find_Lowest_Common_Ancestor()
{
    Node* tree = BinTree::makeTree( {  33,22,85,10,25,54,125,5,15,30 });

    {
        BinTree::Node* lcaNode = find_lowest_common_ancestor(tree, 5, 30);
        std::cout << "LCA: " << lcaNode->getData() << std::endl;
    }
    {
        BinTree::Node* lcaNode = find_lowest_common_ancestor_recur(tree, 5, 30);
        std::cout << "LCA: " << lcaNode->getData() << std::endl;
    }
}
