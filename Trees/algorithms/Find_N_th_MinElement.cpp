/**============================================================================
Name        : Find_N_th_MinElement.cpp.cpp
Created on  : 13.02.2025
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

    BinTree::Node*get_min_Nth_element_X(BinTree::Node* node, const size_t k, size_t& counter)
    {
        if (nullptr == node)
            return nullptr;
        BinTree::Node* result = get_min_Nth_element_X(node->left, k, counter);
        if (nullptr != result)
            return result;
        if (++counter == k)
            return node;
        return get_min_Nth_element_X(node->right, k, counter);
    }

    BinTree::Node* get_min_Nth_element_GOOD(BinTree::Node* node, size_t& k)
    {
        if (nullptr == node)
            return nullptr;
        BinTree::Node* result = get_min_Nth_element_GOOD(node->left, k);
        if (nullptr != result)
            return result;
        if (0 == --k)
            return node;
        return get_min_Nth_element_GOOD(node->right, k);
    }

    BinTree::Node* get_min_Nth_element(BinTree::Node* node, const size_t k)
    {
        static size_t counter = 0;
        if (nullptr == node)
            return nullptr;
        BinTree::Node* result = get_min_Nth_element(node->left, k);
        if (nullptr != result)
            return result;
        if (++counter == k)
            return node;
        return get_min_Nth_element(node->right, k);
    }

}

void TreesAlgorithms::Find_N_th_MinElement()
{
    BinTree::Node* tree = BinTree::makeTree( { 33,22,85,10,30,54,125,5,8,25,32,45,60,120,130 });

    size_t K = 4;

    std::cout << std::endl;
    std::cout << get_min_Nth_element(tree, K)->data << std::endl;

    size_t counter1 = 0;
    std::cout << get_min_Nth_element_X(tree, K, counter1)->data << std::endl;

    [[maybe_unused]]
    size_t counter2 = 0;
    std::cout << get_min_Nth_element_GOOD(tree, K)->data << std::endl;
}