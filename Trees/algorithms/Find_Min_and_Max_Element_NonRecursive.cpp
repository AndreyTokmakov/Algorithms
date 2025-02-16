/**============================================================================
Name        : Find_Min_and_Max_Element_NonRecursive.cpp
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

    int __get_min_element_non_recur(Node* node)
    {
        while (nullptr != node->left)
            node = node->left;
        return node->data;
    }

    int __get_max_element_non_recur(Node* node)
    {
        while (nullptr != node->right)
            node = node->right;
        return node->data;
    }

}

void TreesAlgorithms::Find_Min_and_Max_Element_NonRecursive()
{    /**
           33
         /    \
       22      85
      /  \    /   \
    10    30 54    125
    **/
    Node* tree = BinTree::makeTree( { 33,22,85,10,30,54,125  });
    std::cout << __get_min_element_non_recur(tree) << std::endl;
    std::cout << __get_max_element_non_recur(tree) << std::endl;
}