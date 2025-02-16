/**============================================================================
Name        : Find_Min_and_Max_Element_Recursive.cpp
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

    int get_min_element(Node* node)
    {
        if (nullptr == node->left)
            return node->data;
        else return get_min_element(node->left);
    }

    int get_max_element(Node* node)
    {
        return nullptr == node->right ? node->data : get_max_element(node->right);
    }


}

void TreesAlgorithms::Find_Min_and_Max_Element_Recursive()
{    /**
           33
         /    \
       22      85
      /  \    /   \
    10    30 54    125
    **/
    Node* tree = BinTree::makeTree( { 33,22,85,10,30,54,125  });
    std::cout << "Min: " << get_min_element(tree)<< ", Max: " << get_max_element(tree) << std::endl;
}
